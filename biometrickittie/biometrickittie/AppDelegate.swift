//
//  AppDelegate.swift
//  biometrickittie
//
//  Created by Todd Bruss on 7/31/22.
//

import Cocoa

@main
class AppDelegate: NSObject, NSApplicationDelegate {
        
    func applicationDidFinishLaunching(_ aNotification: Notification) {
        
        guard let BiometricKitHandler = BiometricKitHandler.manager() else { return }
       
        
///        For Testing purposes only:
///        To turn on entitlements
///        Enter Recovery Mode
///        Open Terminal
///        Enter
//        csrutil enable --without kext --without nvram
//        reboot
///        Login
///        Open Terminal
///        Enter
//        nvram boot-args="amfi_get_out_of_my_way=0x1"
//        sudo reboot


        print("match:", BiometricKitHandler.match() as Any)
        print("^ 0 means no error was returned, and matchMode is now on")

        print("Open terminal and enter: log str -d | grep biometrickitd")
        print("Then Touch the TouchID sensor, look for MATCH")
        print("look for 'matchResult:timestamp: MATCH' <uid>: <fingerprint uuid>")
        print("If no match is found and NO-MATCH is not logged, then fingerprint is deactivated")
        print("To reactivate a fingerprint, go to the lock screen and enter your password")

        func applicationSupportsSecureRestorableState(_ app: NSApplication) -> Bool {
            return true
        }
    }
}
