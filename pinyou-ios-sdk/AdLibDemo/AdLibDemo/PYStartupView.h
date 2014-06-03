//
//  PYStartupView.h
//  AdLib
//
//  Created by darren on 14-5-29.
//  Copyright (c) 2014年 lide. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "PYStartupViewDelegate.h"

@interface PYStartupView : UIView

- (id)initWithSize:(CGSize)size;
@property (assign,nonatomic) id<PYStartupViewDelegate> delegate;
@property (retain,nonatomic) NSString *adUnitId;
@property (retain,nonatomic) UIImageView *imageView;

- (void)loadAdInfo;

@end
