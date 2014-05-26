//
//  AdLib.h
//  AdLib
//
//  Created by lide on 14-2-18.
//  Copyright (c) 2014年 lide. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface Pinyou : NSObject

//固定位广告
+ (void)showAdViewWithFrame:(CGRect)rect
                  layerView:(UIView *)layerView
                   adUnitId:(NSString *)adUnitId;

//Banner
+ (void)showBannerViewFormTopWithSize:(CGSize)size
                             adUnitId:(NSString *)adUnitId;

+ (void)showBannerViewFormBottomWithSize:(CGSize)size
                                adUnitId:(NSString *)adUnitId;

//Interstitial
+ (void)showInterstitialViewWithSize:(CGSize)size
                            adUnitId:(NSString *)adUnitId;

//Default

+ (void)showDefaultTopBannerView;
+ (void)showDefaultBottomBannerView;
+ (void)showDefaultMiddleBannerView;

+ (NSString *)getPinyouSDKVersion;
+ (NSString *)getPinyouId;

//Preload
+ (void)preloadAdInfo;

@end
