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

@interface PYBannerView : UIView <UIWebViewDelegate>

- (id)initWithSize:(CGSize)size;

@property (assign, nonatomic) id<PYBannerViewDelegate> delegate;
@property (assign, nonatomic) UIViewController *rootViewController;
@property (copy, nonatomic) NSString *adUnitId;
@property (assign, nonatomic) BOOL autoDismiss;
@property (assign, nonatomic) NSUInteger autoRefreshTime;
@property (assign, nonatomic) BOOL showCloseButton;

/*
 获取广告信息，自动展示
 */
- (void)loadAdInfo;

@end
