//
//  HomeViewController.m
//  AdLibDemo
//
//  Created by lide on 14-3-4.
//  Copyright (c) 2014年 lide. All rights reserved.
//

#import "HomeViewController.h"
#import "Pinyou.h"
//#import "MobiSageSDK.h"
#import <QuartzCore/QuartzCore.h>
#import "DownloadViewController.h"
#import "PYBannerView.h"
#import "PYInterstitialView.h"
#import "PYInterstitialViewDelegate.h"
#import <MessageUI/MessageUI.h>

@interface HomeViewController () <PYBannerViewDelegate>

@end

@implementation HomeViewController

- (void)clickBannerButton:(id)sender
{

    PYBannerView *bannerView = [[[PYBannerView alloc] initWithFrame:CGRectMake(0, 20, 320, 50)] autorelease];
    [bannerView setShowCloseButton:NO];
    bannerView.delegate = self;
    [bannerView setAdUnitId:@"gi.BY"];
    [self.view addSubview:bannerView];
    
    [bannerView loadAdInfo];

}

- (void)clickInterstitialButton:(id)sender
{
    [Pinyou showInterstitialViewWithSize:CGSizeMake(320, 240) adUnitId:@"Xi.VU"];

}

#pragma mark - super

- (id)init
{
    self = [super init];
    if(self != nil)
    {
        
    }
    
    return self;
}

- (void)loadView
{
    [super loadView];
    
    UIButton *bannerButton = [[UIButton buttonWithType:UIButtonTypeCustom] retain];
    bannerButton.frame = CGRectMake(100, 120, 120, 40);
    [bannerButton setTitle:@"Banner" forState:UIControlStateNormal];
    [bannerButton setTitleColor:[UIColor blackColor] forState:UIControlStateNormal];
    bannerButton.layer.borderColor = [[UIColor blackColor] CGColor];
    bannerButton.layer.borderWidth = 1.0;
    [bannerButton addTarget:self action:@selector(clickBannerButton:) forControlEvents:UIControlEventTouchUpInside];
    [self.view addSubview:bannerButton];
    
    UIButton *interstitialButton = [[UIButton buttonWithType:UIButtonTypeCustom] retain];
    interstitialButton.frame = CGRectMake(100, 165, 120, 40);
    [interstitialButton setTitle:@"Interstitial" forState:UIControlStateNormal];
    [interstitialButton setTitleColor:[UIColor blackColor] forState:UIControlStateNormal];
    interstitialButton.layer.borderColor = [[UIColor blackColor] CGColor];
    interstitialButton.layer.borderWidth = 1.0;
    [interstitialButton addTarget:self action:@selector(clickInterstitialButton:) forControlEvents:UIControlEventTouchUpInside];
    [self.view addSubview:interstitialButton];
}

- (void)viewDidLoad
{
    [super viewDidLoad];
	// Do any additional setup after loading the view.
}

- (void)didReceiveMemoryWarning
{
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

#pragma mark - PYMraidDelegate

- (UIViewController *)mraidViewController
{
    return self;
}
#pragma mark - PYPYBannerViewDelegate
- (void)customOpenClickUrl:(PYBannerView *)bannerView withClickUrl:(NSString *)clickUrl {
    NSLog(@"%@",clickUrl);
}


@end
