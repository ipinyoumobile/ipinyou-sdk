//
//  PYAdRequest.h
//  AdLib
//
//  Created by lide on 14-3-21.
//  Copyright (c) 2014年 lide. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef void (^PYAdRequestSuccessBlock)(id responseObject);
typedef void (^PYAdRequestFailureBlock)(NSError *error);

@interface PYAdRequest : NSObject

+ (PYAdRequest *)request;
+ (void)initSDKWithVersion:(NSString *)version;
+ (PYAdRequest *)requestWithAdUnitId:(NSString *)adUnitId;

- (void)loadRequestSuccess:(PYAdRequestSuccessBlock)successBlock
                   failure:(PYAdRequestFailureBlock)failureBlock;

@end

