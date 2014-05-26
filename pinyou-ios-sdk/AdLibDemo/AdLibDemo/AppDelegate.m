//
//  AppDelegate.m
//  AdLibDemo
//
//  Created by lide on 14-2-18.
//  Copyright (c) 2014年 lide. All rights reserved.
//

#import "AppDelegate.h"
#import "HomeViewController.h"
#import "PYAdRequest.h"
#import <SystemConfiguration/SystemConfiguration.h>

#include <sys/types.h>
#include <sys/sysctl.h>

@implementation AppDelegate

#pragma mark - private

#pragma mark - super

- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions
{
    self.window = [[[UIWindow alloc] initWithFrame:[[UIScreen mainScreen] bounds]] autorelease];
    // Override point for customization after application launch.
    self.window.backgroundColor = [UIColor whiteColor];
    [self.window makeKeyAndVisible];
        
    HomeViewController *homeVc = [[[HomeViewController alloc] init] autorelease];
    HomeViewController *homeVc1 = [[[HomeViewController alloc] init] autorelease];
//    UINavigationController *navigationController = [[[UINavigationController alloc] initWithRootViewController:homeVc] autorelease];
//    navigationController.navigationBarHidden = YES;
    UITabBarController *tabBarVC = [[UITabBarController alloc] init];
    tabBarVC.viewControllers = [NSArray arrayWithObjects:homeVc, homeVc1, nil];
    self.window.rootViewController = tabBarVC;
    [PYAdRequest initSDKWithVersion:@"V1.0"];
    
    return YES;
}

- (void)applicationWillResignActive:(UIApplication *)application
{
    // Sent when the application is about to move from active to inactive state. This can occur for certain types of temporary interruptions (such as an incoming phone call or SMS message) or when the user quits the application and it begins the transition to the background state.
    // Use this method to pause ongoing tasks, disable timers, and throttle down OpenGL ES frame rates. Games should use this method to pause the game.
}

- (void)applicationDidEnterBackground:(UIApplication *)application
{
    // Use this method to release shared resources, save user data, invalidate timers, and store enough application state information to restore your application to its current state in case it is terminated later. 
    // If your application supports background execution, this method is called instead of applicationWillTerminate: when the user quits.
}

- (void)applicationWillEnterForeground:(UIApplication *)application
{
    // Called as part of the transition from the background to the inactive state; here you can undo many of the changes made on entering the background.
}

- (void)applicationDidBecomeActive:(UIApplication *)application
{
    // Restart any tasks that were paused (or not yet started) while the application was inactive. If the application was previously in the background, optionally refresh the user interface.
}

- (void)applicationWillTerminate:(UIApplication *)application
{
    // Called when the application is about to terminate. Save data if appropriate. See also applicationDidEnterBackground:.
}

@end
