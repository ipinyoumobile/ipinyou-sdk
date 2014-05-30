//
//  PYMraidView.h
//  AdLib
//
//  Created by lide on 14-4-2.
//  Copyright (c) 2014年 lide. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "PYWebViewController.h"
#import <EventKit/EventKit.h>

@class PYJavascriptBridge;
@class PYAVPlayer;

@protocol PYMraidDelegate;
@protocol PYJavascriptBridgeDelegate;

typedef enum PYMraidViewStateEnum
{
	PYMraidViewStateHidden = -1,
	PYMraidViewStateDefault = 0,
	PYMraidViewStateExpanded
} PYMraidViewState;

@interface PYMraidView : UIView <PYWebViewControllerDelegate>
{
    UIDevice        *_currentDevice;
    UIWebView       *_webView;
    NSError         *_lastError;
    
    PYJavascriptBridge  *_javascriptBridge;
    id<PYMraidDelegate> _delegate;
    
    PYMraidViewState    _currentState;
    CGSize              _maxSize;
    
    BOOL                _applicationReady;
    NSURL               *_creativeURL;
    NSString            *_creativeId;
    
    BOOL                _isMraidAd;
    BOOL                _loadingAd;
    NSInteger           _modalityCounter;
    
    BOOL                _bIsDisplayed;
    BOOL                _allowLocationServices;
    
    NSMutableArray      *_externalProtocols;
    BOOL                _allowAdOrientation;
    CGRect              _defaultFrame;
    CGRect              _expandedFrame;
    
    UIView              *_blockingView;
    
    CGRect              _originalFrame;
    CGAffineTransform   _originalTransform;
    
    CGRect              _translatedFrame;
    NSInteger           _originalTag;
	NSInteger           _parentTag;
    
    PYWebViewController *_webBrowser;
    PYAVPlayer          *_moviePlayer;
    
    EKEventStore        *_eventStore;
	EKEvent             *_event;
}

@property (assign, nonatomic) id<PYMraidDelegate> delegate;
@property (assign, nonatomic) PYMraidViewState currentState;
@property (assign, nonatomic) CGSize maxSize;
@property (assign, nonatomic) NSError *lastError;

@property (assign, nonatomic) UIWebView *webView;

@property (copy, nonatomic) NSURL *creativeURL;

@property (assign, nonatomic, readwrite) BOOL isMraidAd;
@property (nonatomic, assign) BOOL allowLocationServices;

- (void)loadCreative:(NSURL *)url;

- (void)loadHTMLCreative:(NSString *)htmlFragment
			 creativeURL:(NSURL *)url;

@end

@protocol PYMraidDelegate <NSObject>

@required

- (UIViewController *)mraidViewController;

@optional

// called to allow the application to inject javascript into the creative
- (NSString *)javascriptForInjection;

// notifies the consumer that it should handle the specified request
// NOTE: REQUIRED IF A PROTOCOL IS REGISTERED
- (void)handleRequest:(NSURLRequest *)request
				forAd:(PYMraidView *)adView;

// called to allow the application to execute javascript on the creative at the
// time the creative is loaded
- (NSString *)onLoadJavaScriptForAd:(PYMraidView *)adView;

// called when an ad fails to load
- (void)failureLoadingAd:(PYMraidView *)adView;

// Called just before to an ad is displayed
- (void)adWillShow:(PYMraidView *)adView;

// Called just after to an ad is displayed
- (void)adDidShow:(PYMraidView *)adView;

// Called just before to an ad is Hidden
- (void)adWillHide:(PYMraidView *)adView;

// Called just after to an ad is Hidden
- (void)adDidHide:(PYMraidView *)adView;

// Called just before an ad expands
- (void)willExpandAd:(PYMraidView *)adView
			 toFrame:(CGRect)frame;

// Called just after an ad expands
- (void)didExpandAd:(PYMraidView *)adView
			toFrame:(CGRect)frame;

// Called just before an ad closes
- (void)adWillClose:(PYMraidView *)adView;

// Called just after an ad closes
- (void)adDidClose:(PYMraidView *)adView;

// called when the ad will begin heavy content (usually when the ad goes full screen)
- (void)appShouldSuspendForAd:(PYMraidView *)adView;

// called when the ad is finished with it's heavy content (usually when the ad returns from full screen)
- (void)appShouldResumeFromAd:(PYMraidView *)adView;

// allows the application to override the phone call process to, for example
// display an alert to the user before hand
- (void)placePhoneCall:(NSString *)number;

//// allows the application to override the click to app store, for example
//// display an alert to the user before hand
//- (void)placeCallToAppStore:(NSString *)urlString;

// allows the application to override the create calendar event process to, for
// example display an alert to the user before hand
- (void)createCalendarEntryForDate:(NSDate *)date
							 title:(NSString *)title
							  body:(NSString *)body;

// allows the application to inject itself into the full screen browser menu
// to handle the "go" method (for example, send to safari, facebook, etc)
- (void)showURLFullScreen:(NSURL *)url
			   sourceView:(UIView *)view;

- (void)emailNotSetupForAd:(PYMraidView *)adView;

@end
