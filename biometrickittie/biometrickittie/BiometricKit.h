#import <Foundation/NSObject.h>

int _matchingMode=1;

@interface BiometricKit : NSObject 
{
   
}
+ (id)manager;
- (int)match:(id)arg1;
@end
