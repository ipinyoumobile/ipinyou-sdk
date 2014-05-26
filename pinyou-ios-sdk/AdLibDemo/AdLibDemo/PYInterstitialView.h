//
//  PYInterstitialView.h
//  AdLib
//
//  Created by lide on 14-5-4.
//  Copyright (c) 2014年 lide. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "PYInterstitialViewDelegate.h"

/*
 
 PYInterstitialView sample code
 
 PYInterstitialView *interstitialView = [[[PYInterstitialView alloc] initWithFrame:CGRectMake(0, 0, size.width, size.height)] autorelease];
 interstitialView.delegate = self;
 [interstitialView setAdUnitId:adUnitId];
 [interstitialView loadAdInfo];
 
 Caution:
 
 PYInterstitialView Defualt hidden is YES, do not set hidden to NO,
 when the ad content is ready to show, banner view will show automatically.
 
 Do not add PYInterstitialView object to any view, when load ad info successed,
 it will be added to the current window.
 */

@interface PYInterstitialView : UIView

- (id)initWithSize:(CGSize)size;

@property (assign, nonatomic) id<PYInterstitialViewDelegate> delegate;
//banner view adUnitId
@property (retain, nonatomic) NSString *adUnitId;
//whether auto dismiss when interstitial view is shown, default is NO, when set to YES, banner view auto dismiss in 10s
@property (assign, nonatomic) BOOL autoDismiss;
//interstitial view auto refresh time, default is 0, interstitial view not auto refresh
@property (assign, nonatomic) NSUInteger autoRefreshTime;

/*
 获取广告信息，自动展示
 */
- (void)loadAdInfo;

@end
