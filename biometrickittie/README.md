## BiometricKittie

Research app for interacting with Apple's private `BiometricKit.framework` on macOS to observe Touch ID match events.

This project dynamically loads the private framework at runtime, calls into a minimal, reverse-engineered interface, and monitors the system log for match results produced by `biometrickitd` when you touch the Touch ID sensor.

### Warning and scope

- **Private frameworks and entitlements**: This uses `BiometricKit.framework` and a private entitlement `com.apple.private.bmk.allow`. This is for research/education only. It will not be accepted on the App Store and may violate Apple agreements.
- **System integrity**: Running this as-is typically requires relaxing SIP/AMFI for testing. Proceed only on non-production machines you control. Restore protections when finished.

---

### How it works (reverse-engineering overview)

- **Minimal header stub**: `biometrickittie/biometrickittie/BiometricKit.h` defines only what we need:
  - `+ (id)manager;`
  - `- (int)match:(id)arg1;`
  - A global `int _matchingMode = 1;` to satisfy internal checks in the private framework.

- **Dynamic loading at runtime**: `BiometricKitHandler` loads the private framework from `/System/Library/PrivateFrameworks/BiometricKit.framework` and resolves the `BiometricKit` class using `NSClassFromString`.

```objc:startLine:endLine:biometrickittie/biometrickittie/BiometricKitHandler.m
// ...
NSBundle *privateFramework = [NSBundle bundleWithPath:@"/System/Library/PrivateFrameworks/BiometricKit.framework"];
[privateFramework load];
_biokit = [NSClassFromString(@"BiometricKit") valueForKey:@"manager"]; // calls +manager
// ...
```

- **Trigger matching mode**: On launch, `AppDelegate` acquires the handler and calls `match(nil)`. This puts the Touch ID subsystem into a "match mode" where the system daemon `biometrickitd` processes sensor touches and emits match results to the unified log.

```swift:startLine:endLine:biometrickittie/biometrickittie/AppDelegate.swift
let BiometricKitHandler = BiometricKitHandler.manager()
print("match:", BiometricKitHandler.match() as Any)
// 0 means success; Touch the sensor and watch logs from biometrickitd
```

- **Observe results**: This limited version does not receive match events directly. Observe match/no‑match by tailing the system log for `biometrickitd`. Raw biometric data is never exposed.

---

### Requirements

- macOS device with a Touch ID sensor (e.g., MacBook with Touch ID or Apple Silicon Mac with Touch ID keyboard)
- Xcode 13+ (tested with later versions as well)
- Administrative access to reboot into Recovery for SIP/AMFI changes if you plan to run with private entitlements

---

### Setup (research build)

1. Clone and open the project:
   - Open `biometrickittie/biometrickittie.xcodeproj` in Xcode.

2. Code signing:
   - Set signing to "Sign to Run Locally" or use an ad-hoc/team profile that allows local run. App Store signing is not applicable.

3. Entitlements:
   - The project includes `biometrickittie/biometrickittie/biometrickittie.entitlements` with `com.apple.private.bmk.allow = true`.
   - On stock systems, private entitlements are rejected by AMFI; see the test-only steps below.

4. Test-only system configuration (optional but usually required):
   - Reboot to Recovery, open Terminal, run:

```sh
csrutil enable --without kext --without nvram
reboot
```

   - After reboot, open Terminal and run:

```sh
sudo nvram boot-args="amfi_get_out_of_my_way=0x1"
sudo reboot
```

   - This reduces protections so the app can load private frameworks/entitlements for research. Reverse when finished (see below).

5. Build and run:
   - Select the `biometrickittie` scheme and Run.
   - The app is an agent (`LSUIElement = true`) and shows no dock icon or window. Check the Xcode console for the startup prints.

---

### Using BiometricKittie

1. Launch from Xcode. On startup you should see console output indicating `match()` was called successfully.
2. In a separate Terminal, stream logs from `biometrickitd` and then touch the Touch ID sensor:

```sh
log stream --style syslog --predicate 'process == "biometrickitd"' | grep -i match
# or
log stream -d | grep biometrickitd
```

3. Look for entries like `matchResult: timestamp: MATCH <uid>: <fingerprint uuid>`. If no match is found and `NO-MATCH` is not logged, your fingerprint may be deactivated.
4. To re-activate a fingerprint after deactivation, lock the screen and log back in with your password.

---

### Project layout

- `AppDelegate.swift`: Starts matching and prints guidance to the console.
- `BiometricKit.h`: Minimal reverse-engineered header and `_matchingMode` flag.
- `BiometricKitHandler.[hm]`: Loads the private framework and forwards `match` calls.
- `biometrickittie.entitlements`: Private entitlement enabling BiometricKit access.
- `Base.lproj/MainMenu.xib`: Minimal app menu; app runs as an agent (`LSUIElement`).

---

### Limitations and notes

- Private APIs change without notice; symbols, behaviors, or paths may differ across macOS versions.
- You do not receive raw biometric templates or images. Matching happens in secure components, and only match results are observable via logs.
- This is not production-ready and should not be distributed.

---

### Restoring system protections

1. Remove AMFI bypass flag and reboot:

```sh
sudo nvram -d boot-args
sudo reboot
```

2. Re-enable full SIP from Recovery:

```sh
csrutil enable
reboot
```

---

### Legal

This code is for educational and research purposes only. Use at your own risk. Interacting with private Apple frameworks and altering system security settings may violate agreements and can render devices insecure. You are responsible for complying with all applicable laws and policies.


