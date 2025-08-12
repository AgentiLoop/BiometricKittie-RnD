#import <Foundation/Foundation.h>
#import <CoreFoundation/CoreFoundation.h>

@interface BiometricKitHandler : NSObject

+ (BiometricKitHandler*) manager;


- (id)match;

//- (BOOL)isTouchIDCapable;
//- (BOOL)isFingerOn;
//- (id)runinit;
//- (long long)getBioLockoutState;
//- (in)getMatchPolicyInfo;
//- (int)enableBackgroundFdet:(BOOL)arg1;

//- (NSString *)deviceRegionInfo;

@end
