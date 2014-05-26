//
//  PYBannerView.h
//  AdLib
//
//  Created by lide on 14-2-19.
//  Copyright (c) 2014年 lide. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "PYBannerViewDelegate.h"

#define kPYBannnerViewNormalSize    CGSizeMake(320, 50)

/*
 PYBannerView sample code
 
 PYBannerView *bannerView = [[[PYBannerView alloc] initWithFrame:rect] autorelease];
 bannerView.delegate = self;
 [bannerView setAdUnitId:adUnitId];
 [layerView addSubview:bannerView];
 
 [bannerView loadAdInfo];
 
 Caution:
 
 PYBannerView Defualt hidden is YES, do not set hidden to NO,
 when the ad content is ready to show, banner view will show automatically.
 
 */

@interface PYBannerView : UIView <UIWebViewDelegate>

- (id)initWithSize:(CGSize)size;

@property (assign, nonatomic) id<PYBannerViewDelegate> delegate;
//banner view adUnitId
@property (copy, nonatomic) NSString *adUnitId;
//whether auto dismiss when banner view is shown, default is NO, when set to YES, banner view auto dismiss in 10s
@property (assign, nonatomic) BOOL autoDismiss;
//banner view auto refresh time, default is 0, banner view not auto refresh
@property (assign, nonatomic) NSUInteger autoRefreshTime;
//show close button on banner view or not
@property (assign, nonatomic) BOOL showCloseButton;

/*
 获取广告信息，自动展示
 */
- (void)loadAdInfo;

@end
