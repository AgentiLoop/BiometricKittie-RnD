#import "BiometricKitHandler.h"
#import "BiometricKitXPCExportedObject.h"

static BiometricKitXPCExportedObject *_supporter = nil;
static BiometricKitHandler *_handler = nil;

@implementation BiometricKitHandler

+ (BiometricKitHandler*) manager {
    NSBundle *biome = [NSBundle bundleWithPath:@"/System/Library/PrivateFrameworks/BiometricSupport.framework"];
    [biome load];
    _supporter = [NSClassFromString(@"BiometricKitXPCServer") valueForKey:@"initialize"];
    _handler = [[BiometricKitHandler alloc] init];
    return _handler;
}

//- (NSString *)deviceName
//{
//    return [_supporter deviceName];
//}
//
//- (NSString *)productName
//{
//    return [_supporter productName];
//}
//

- (void)match;
{
    [_supporter match:nil options:nil client:nil replyBlock:nil];
}
//
//
//- (BOOL)isFingerOn;
//{
//    return [_supporter isFingerOn];
//}
//
//
//- (BOOL)isTouchIDCapable;
//{
//    return [_supporter isTouchIDCapable];
//}
//
//
//- (id)runinit;
//{
//    return [_supporter init];
//}
//
//- (long long)getBioLockoutState;
//{
//    return [_supporter getBioLockoutState];
//}
//
//
//- (in)getMatchPolicyInfo;
//{
//    return [_supporter getMatchPolicyInfo];
//}
//
//
//- (int)enableBackgroundFdet:(BOOL)arg1;
//{
//    return [_supporter enableBackgroundFdet: 1];
//}







//
//- (NSString *)deviceRegionInfo
//{
//    return [_supporter deviceRegionInfo];
//}

@end
