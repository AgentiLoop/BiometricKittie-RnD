#import <Foundation/Foundation.h>
#import <CoreFoundation/CoreFoundation.h>

@interface BiometricKitHandler : NSObject

+ (BiometricKitHandler*) manager;

- (int)match;

@end
