//
//  PYConversion.h
//  AdLib
//
//  Created by darren on 14-4-16.
//  Copyright (c) 2014年 lide. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <AdSupport/AdSupport.h>


typedef enum : NSInteger {
	PY_FirstRun = 0,
	PY_DownLoad,
	PY_Pay,
    PY_Register
} ConversionType;

@interface PYConversion : NSObject
+ (PYConversion *)defaultManager;

//根据转化目标传递相应的转化类型ConversionType
- (void)noticeConversionWithParamA:(NSString *)a conversionType:(ConversionType )type;


@end

