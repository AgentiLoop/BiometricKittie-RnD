#import "BiometricKitHandler.h"
#import "BiometricKit.h"

static BiometricKit *_biokit = nil;
static BiometricKitHandler *_biohandler = nil;

@implementation BiometricKitHandler

+ (BiometricKitHandler*) manager {
    NSBundle *privateFramework = [NSBundle bundleWithPath:@"/System/Library/PrivateFrameworks/BiometricKit.framework"];
    [privateFramework load];
    _biokit = [NSClassFromString(@"BiometricKit") valueForKey:@"manager"];
    _biohandler = [[BiometricKitHandler alloc] init];
    
    return _biohandler;
}

- (int)match;
{
    return [_biokit match:nil];
}
@end
