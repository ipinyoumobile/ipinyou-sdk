//
//  PYBannerViewDelegate.h
//  AdLib
//
//  Created by lide on 14-2-19.
//  Copyright (c) 2014年 lide. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef void (^PYBannerCloseBlock)(void);
typedef void (^PYBannerLoadSuccessBlock)(void);

@class PYBannerView;

@protocol PYBannerViewDelegate <NSObject>

- (void)bannerViewDidLoadImageData:(PYBannerView *)bannerView success:(PYBannerLoadSuccessBlock)successBlock;
- (void)bannerViewDidLoadHTMLData:(PYBannerView *)bannerView success:(PYBannerLoadSuccessBlock)successBlock;
- (void)bannerViewDidClickCloseButton:(PYBannerView *)bannerView finished:(PYBannerCloseBlock)closeBlock;
- (void)bannerViewDidLoadDataError:(PYBannerView *)bannerView error:(NSError *)error;

@end
