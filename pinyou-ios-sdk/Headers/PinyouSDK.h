//
//  PinyouSDK.h
//  PinyouSDK
//
//  Created by darren on 14-2-19.
//  Copyright (c) 2014年 ipinyou. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef enum : NSInteger {
	PY_FirstRun = 0,
	PY_DownLoad,
	PY_Pay,
    PY_Register
} ConversionType;


@interface PinyouSDK : NSObject

+ (PinyouSDK *)defaultManager;

//根据转化目标传递相应的转化类型ConversionType
- (void)noticeConversionWithParamA:(NSString *)a conversionType:(ConversionType )type;

@end

