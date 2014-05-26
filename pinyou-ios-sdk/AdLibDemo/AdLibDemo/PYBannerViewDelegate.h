//
//  PYBannerViewDelegate.h
//  AdLib
//
//  Created by lide on 14-2-19.
//  Copyright (c) 2014年 lide. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef void (^PYBannerTapBlock)(void);
typedef void (^PYBannerCloseBlock)(void);

@class PYBannerView;

@protocol PYBannerViewDelegate <NSObject>

//默认情况是数据加载成功后自动展示bannerView
- (void)bannerViewDidLoadImageData:(PYBannerView *)bannerView;
//默认情况是数据加载成功后自动展示bannerView
- (void)bannerViewDidLoadHTMLData:(PYBannerView *)bannerView;
//目前点击bannerView会直接在safari打开广告链接，并关闭bannerView，如果开发者想自定义一些动画效果，请在最后调用tapBlock来关闭bannerView
- (BOOL)bannerViewDidTapBanner:(PYBannerView *)bannerView finished:(PYBannerTapBlock)tapBlock;
//默认情况是点击关闭按钮后自动关闭bannerView，如果开发者想自定义一些动画效果，请在最后调用closeBlock来关闭bannerView
- (void)bannerViewDidClickCloseButton:(PYBannerView *)bannerView finished:(PYBannerCloseBlock)closeBlock;
//点击打开url时自定义打开方式,默认通过safari打开点击地址
- (void)customOpenClickUrl:(PYBannerView *)bannerView withClickUrl:(NSString *)clickUrl;
- (void)bannerViewDidLoadDataError:(PYBannerView *)bannerView error:(NSError *)error;

@end
