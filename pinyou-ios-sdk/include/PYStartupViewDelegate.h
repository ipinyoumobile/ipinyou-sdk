//
//  PYStartupViewDelegate.h
//  AdLib
//
//  Created by darren on 14-5-29.
//  Copyright (c) 2014年 lide. All rights reserved.
//

#import <Foundation/Foundation.h>

@class PYStartupView;

@protocol PYStartupViewDelegate <NSObject>

- (void)startupViewDidLoadImageData:(PYStartupView *)startupView;

- (void)startupViewDidLoadDataError:(PYStartupView *)startupView error:(NSError *)error;

- (void)startupViewCacheFaild:(PYStartupView *)startupView error:(NSError *)error;

@end
