//
//  PYInterstitialViewDelegate.h
//  AdLib
//
//  Created by lide on 14-5-4.
//  Copyright (c) 2014年 lide. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef void (^PYInterstitialTapBlock)(void);
typedef void (^PYInterstitialCloseBlock)(void);

@class PYInterstitialView;

@protocol PYInterstitialViewDelegate <NSObject>

//默认情况是数据加载成功后自动展示InterstitialView
- (void)interstitialViewDidLoadImageData:(PYInterstitialView *)interstitialView;
//默认情况是数据加载成功后自动展示InterstitialView
- (void)interstitialViewDidLoadHTMLData:(PYInterstitialView *)interstitialView;
//目前点击InterstitialView会直接在safari打开广告链接，并关闭InterstitialView，如果开发者想自定义一些动画效果，请在最后调用tapBlock来关闭InterstitialView
- (void)interstitialViewDidTapInterstitial:(PYInterstitialView *)interstitialView finished:(PYInterstitialTapBlock)tapBlock;
//默认情况是点击关闭按钮后自动关闭InterstitialView，如果开发者想自定义一些动画效果，请在最后调用closeBlock来关闭InterstitialView
- (void)interstitialViewDidClickCloseButton:(PYInterstitialView *)interstitialView finished:(PYInterstitialCloseBlock)closeBlock;
//点击打开url时自定义打开方式,默认通过safari打开点击地址
- (void)customOpenClickUrl:(PYInterstitialView *)interstitialView withClickUrl:(NSString *)clickUrl;
- (void)interstitialViewDidLoadDataError:(PYInterstitialView *)interstitialView error:(NSError *)error;

@end
