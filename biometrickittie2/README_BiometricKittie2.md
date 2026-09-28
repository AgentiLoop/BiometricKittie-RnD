## BiometricKittie2

BiometricKittie2 is a macOS sample that experiments with Apple's private Biometric Support interfaces from a simple Cocoa app. It dynamically loads `BiometricSupport.framework` and sends a minimal `match` request via internal XPC types.

This target is for local, educational exploration only. It uses private APIs and private entitlements and is not suitable for App Store distribution.

### What’s inside
- **Swift app shell**: `AppDelegate.swift` launches and calls into an Objective‑C bridge.
- **Objective‑C bridge**: `BiometricKitHandler` loads `/System/Library/PrivateFrameworks/BiometricSupport.framework`, acquires `BiometricKitXPCServer`, and calls `match`.
- **Header stubs (class-dump)**: `BiometricKitXPCExportedObject.h`, `BiometricKitXpcProtocol-Protocol.h`, `CDStructures.h`, `NSObject-Protocol.h` to describe private symbols.
- **Entitlements**: `biometrickittie.entitlements` enables `com.apple.private.bmk.allow` for local testing.
- **Xcode project**: Configured Swift/Obj‑C bridging header and adds the Obj‑C sources to the target.

### Requirements
- macOS 12.3+ with Touch ID hardware (T1/T2 or Apple Silicon with Touch ID keyboard) for any meaningful response
- Xcode 13.4.1+ (project settings were created with 13.4.1)
- An Apple development certificate to code sign for local run

### Setup
1. Open `biometrickittie2/biometrickittie.xcodeproj` in Xcode.
2. Select the `biometrickittie` target.
3. In Signing & Capabilities:
   - Set your Team.
   - Change the Bundle Identifier if needed.
   - Hardened Runtime is disabled in this sample; keep as is for local testing.
4. Ensure the bridging header is set to `biometrickittie/biometrickittie-Bridging-Header.h` (already configured in project settings).

### Running
1. Build and Run on your Mac (My Mac). No simulator support.
2. On launch, `AppDelegate` creates the `BiometricKitHandler` singleton and invokes `match`.
3. Watch the Xcode console for logs. Actual matching requires appropriate hardware, OS support, and permissions; without them, calls may no-op or fail silently.

### Notes and Caveats
- Private APIs: Uses internal classes such as `BiometricKitXPCServer` and XPC protocols. Behavior can break on any macOS update.
- Private entitlements: `com.apple.private.bmk.allow` is a private entitlement. Standard developer provisioning profiles will not grant it; functionality may be restricted or denied at runtime.
- Not for distribution: Do not ship or submit to the App Store. Intended only for research on your own machine.
- Type signatures: Some method signatures come from class-dump headers and may be inaccurate; adjust if you observe mismatches.

### Commented-out features (optional)
The bridge and `AppDelegate.swift` include several commented items you can experiment with. These map loosely to private XPC calls and may require signature tweaks:

- **`isFingerOn` (BOOL)**: Presence detection. XPC: `isFingerOn:replyBlock:`. May always return false without proper entitlements/sensor state.
- **`isTouchIDCapable` (BOOL)**: Hardware capability check. Modern flows often use biometry availability instead (see XPC `getBiometryAvailabilityForUser:...`).
- **`runinit` (id)**: Calls `init` on the internal server; typically unnecessary and potentially unsafe.
- **`getBioLockoutState` (long long)**: Lockout status. XPC requires a user parameter: `getBioLockoutStateForUser:client:replyBlock:`. The stub without a user id will need updating.
- **`getMatchPolicyInfo`**: Policy info. Prefer `pullMatchPolicyInfoData:replyBlock:`.
- **`enableBackgroundFdet:(BOOL)`**: Background finger detect. XPC: `enableBackgroundFdet:client:replyBlock:`; behavior is device/OS dependent.
- **`deviceRegionInfo` (NSString*)**: Region string. This selector may not exist on current OS builds; keep commented unless verified.

To try them:
1. Uncomment the method declarations in `biometrickittie/BiometricKitHandler.h` and implementations in `BiometricKitHandler.m`.
2. Align signatures with the XPC forms above. For reply blocks, you can wrap them into synchronous returns (e.g., via a semaphore) for simple demos.
3. Uncomment the related print lines in `biometrickittie/AppDelegate.swift`.

### Quick reference (commented-out Swift calls)
```swift
//        print("Is finger on:", BiometricKitHandler!.isFingerOn()as Any)
//        print("run init:", BiometricKitHandler!.runinit() as Any)
//        print("getBioLockoutState:", BiometricKitHandler!.getBioLockoutState() as Any)
//        print("run getMatchPolicyInfo:", BiometricKitHandler!.getMatchPolicyInfo() as Any)
//        print("Is touchid capable:", BiometricKitHandler!.isTouchIDCapable() as Any)
//        print("enableBackgroundFdet", BiometricKitHandler!.enableBackgroundFdet(true) as Any)
```

- **Is finger on**: Presence detect; often returns false without full permissions/hardware readiness.
- **run init**: Calls internal server `init`; generally not necessary and may be unstable.
- **getBioLockoutState**: Lockout state; XPC requires user context (`getBioLockoutStateForUser:...`).
- **run getMatchPolicyInfo**: Policy data; modern call is `pullMatchPolicyInfoData:replyBlock:`.
- **Is touchid capable**: Capability check; prefer biometry availability APIs.
- **enableBackgroundFdet(true)**: Attempts to enable background finger detection; behavior varies by OS/device.

### Key Files
- `biometrickittie/AppDelegate.swift` — entry point calling the bridge.
- `biometrickittie/BiometricKitHandler.h/.m` — Objective‑C bridge to private framework and XPC server.
- `biometrickittie/biometrickittie-Bridging-Header.h` — exposes the bridge to Swift.
- `biometrickittie/biometrickittie.entitlements` — private entitlement used for local testing.

### License
Provided as-is for educational purposes. Use at your own risk.


---

**AgentiLoop:** [agentiloop.ai](https://agentiloop.ai/)

Copyright © 2026 AgentiLoop.ai, a Logos InkPen LLC company. All rights reserved.
