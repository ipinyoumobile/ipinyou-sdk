//
//  DownloadViewController.m
//  AdLibDemo
//
//  Created by lide on 14-3-4.
//  Copyright (c) 2014年 lide. All rights reserved.
//

#import "DownloadViewController.h"
#import "Pinyou.h"
@interface DownloadViewController ()

@end

@implementation DownloadViewController

- (void)clickCloseButton:(id)sender
{
//    [self dismissViewControllerAnimated:YES completion:^{
//        
//    }];
    [self dismissModalViewControllerAnimated:YES];
//    [self.navigationController popViewControllerAnimated:YES];
}

- (void)clickAddButton:(id)sender
{
    [self.navigationController pushViewController:[[[DownloadViewController alloc] init] autorelease] animated:YES];
}

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
    
    self.view.backgroundColor = [UIColor whiteColor];
    
    UIButton *closeButton = [UIButton buttonWithType:UIButtonTypeContactAdd];
    closeButton.frame = CGRectMake(2, 2, 40, 40);
    closeButton.backgroundColor = [UIColor blackColor];
    [closeButton addTarget:self action:@selector(clickCloseButton:) forControlEvents:UIControlEventTouchUpInside];
    [self.view addSubview:closeButton];
    
    UIButton *addButton = [UIButton buttonWithType:UIButtonTypeContactAdd];
    addButton.frame = CGRectMake(278, 2, 40, 40);
    addButton.backgroundColor = [UIColor blackColor];
    [addButton addTarget:self action:@selector(clickAddButton:) forControlEvents:UIControlEventTouchUpInside];
    [self.view addSubview:addButton];
}

- (void)loadProductWithParameters:(NSDictionary *)parameters completionBlock:(void(^)(BOOL result, NSError *error))block
{
    [super loadProductWithParameters:parameters completionBlock:block];
}

//- (id)initWithNibName:(NSString *)nibNameOrNil bundle:(NSBundle *)nibBundleOrNil
//{
//    self = [super initWithNibName:nibNameOrNil bundle:nibBundleOrNil];
//    if (self) {
//        // Custom initialization
//    }
//    return self;
//}

- (void)viewDidLoad
{
    [super viewDidLoad];
	// Do any additional setup after loading the view.
}

- (void)viewDidAppear:(BOOL)animated
{
    [super viewDidAppear:animated];
    
    [Pinyou showDefaultBottomBannerView];
}

- (void)didReceiveMemoryWarning
{
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

@end
