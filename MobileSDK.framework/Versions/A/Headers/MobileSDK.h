//
//  MobileSDK.h
//  MobileSDK
//
//  Created by An Dai on 3/14/14.
//  Copyright (c) 2014 analysis. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface MobileSDK : NSObject
+(void)start:(NSString *)appKey withHost:(NSString *)appHost andAppStoreID:(NSString *)appstore_id;

+(void)appControlAction:(BOOL) value;

+ (void)trackDeviceToken:(NSString *)token pushBadge:(NSString *)badge pushAlert:(NSString *)alert pushSound:(NSString *)sound;

+ (void)trackEvent:(NSString *)key count:(int)count;

+ (void)trackEvent:(NSString *)key count:(int)count sum:(double)sum;

+ (void)trackEvent:(NSString *)key segmentation:(NSDictionary *)segmentation count:(int)count;

+ (void)trackEvent:(NSString *)key segmentation:(NSDictionary *)segmentation count:(int)count sum:(double)sum;
@end
