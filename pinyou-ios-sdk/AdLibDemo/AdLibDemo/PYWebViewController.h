//
//  PYWebViewController.h
//  AdLib
//
//  Created by lide on 14-3-3.
//  Copyright (c) 2014年 lide. All rights reserved.
//

#import <UIKit/UIKit.h>

@protocol PYWebViewControllerDelegate;

@interface PYWebViewController : UIViewController
{
    id<PYWebViewControllerDelegate> _delegate;
    
    NSURL       *_url;
    UIWebView   *_webView;
    UIView      *_browserNavigationBar;
//    UIImageView *_addressBarBackground;
    
    UIButton    *_backButton;
    UIButton    *_forwardButton;
    UIButton    *_refreshButton;
    UIButton    *_safariButton;
    
//    UIActivityIndicatorView *_pageLoadingIndicator;
    UIButton    *_closeButton;
}

@property (retain, nonatomic) UIWebView *webView;
@property (retain, nonatomic) UIView *browserNavigationBar;
//@property (retain, nonatomic) UIImageView *addressBarBackground;
@property (retain, nonatomic) UIButton *backButton;
@property (retain, nonatomic) UIButton *forwardButton;
@property (retain, nonatomic) UIButton *refreshButton;
@property (retain, nonatomic) UIButton *safariButton;
//@property (retain, nonatomic) UIActivityIndicatorView *pagaLoadingIndicator;
@property (retain, nonatomic) UIButton *closeButton;

@property (assign, nonatomic) id<PYWebViewControllerDelegate> delegate;

@property (copy, nonatomic) NSURL *URL;

@property (assign, nonatomic) BOOL backButtonEnabled;
@property (assign, nonatomic) BOOL forwardButtonEnabled;
@property (assign, nonatomic) BOOL refreshButtonEnabled;
@property (assign, nonatomic) BOOL safariButtonEnabled;
@property (assign, nonatomic) BOOL closeButtonEnabled;

@end

@protocol PYWebViewControllerDelegate <NSObject>

@required
- (void)doneWithBrowser;

@optional
// allows the consumer to veto loading a given request
- (BOOL)shouldLoadRequest:(NSURLRequest *)request
			   forBrowser:(PYWebViewController *)browserController;

// called when the user presses the "safari" button (i.e. wants to do something
// "special" with the url such as book mark it)
- (void)showURLFullScreen:(NSURL *)url
			   sourceView:(UIView *)view;

@end
