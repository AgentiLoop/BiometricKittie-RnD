//
//  AppDelegate.swift
//  biometrickittie
//
//  Created by Todd Bruss on 7/31/22.
//

import Cocoa

@main
class AppDelegate: NSObject, NSApplicationDelegate {

    @IBOutlet var window: NSWindow!


    func applicationDidFinishLaunching(_ aNotification: Notification) {
        // Insert code here to initialize your application
        
        let BiometricKitHandler = BiometricKitHandler.manager()
       print("match:", BiometricKitHandler!.match()as Any)

//        print("Is finger on:", BiometricKitHandler!.isFingerOn()as Any)
//        print("run init:", BiometricKitHandler!.runinit() as Any)
//        print("getBioLockoutState:", BiometricKitHandler!.getBioLockoutState() as Any)
//        print("run getMatchPolicyInfo:", BiometricKitHandler!.getMatchPolicyInfo() as Any)
//        print("Is touchid capable:", BiometricKitHandler!.isTouchIDCapable() as Any)
//        print("enableBackgroundFdet", BiometricKitHandler!.enableBackgroundFdet(true) as Any)


    }

    func applicationWillTerminate(_ aNotification: Notification) {
        // Insert code here to tear down your application
    }

    func applicationSupportsSecureRestorableState(_ app: NSApplication) -> Bool {
        return true
    }


}

