//
//  TSXCameraInputView.h
//  TransmitSDK
//
//  Created by Eldan Ben Haim on 06/11/2017.
//  Copyright © 2017 TransmitSecurity. All rights reserved.
//

#import <UIKit/UIKit.h>

@class TSXCameraInputView;
@class TSXCameraInputResponse;

@protocol TSXCameraInputViewDelegate
-(void)cameraInputView:(TSXCameraInputView*)view responseCollected:(TSXCameraInputResponse*)response;
-(void)cameraInputView:(TSXCameraInputView*)view responseCollectionError:(NSError*)error;
-(void)cameraInputView:(TSXCameraInputView*)view hintsChanged:(NSArray<NSString*> *)hints;
@end

@protocol TSXCameraInputViewBleBeaconWhitelistSource
-(NSDictionary *)readCameraInputViewWhiteList:(TSXCameraInputView*)view;
-(void)cameraInputView:(TSXCameraInputView*)view updateWhitelist:(NSDictionary*)whitelist;
@end

@interface TSXCameraInputView : UIView

// Sampling control
-(void)startSampling;
-(void)cancelSampling;
@property BOOL acquisitionEnabled;

// Acquisition configuration
@property NSArray<NSDictionary*> *acquisitionChallenges;
@property BOOL waitForCameraAdjusted;
@property BOOL useBackCamera;
@property NSTimeInterval detectionTimeout;

// Visual
@property BOOL showIndicators;
@property CGRect liveRect;

@property UIImage *blurMask;
@property UIColor *indicatorColorValidInput;
@property UIColor *indicatorColorInvalidInput;
@property UIColor *indicatorProgressTintColor;
@property UIColor *indicatorProgressBackgroundTintColor;

@property NSInteger detectionBarHeight;
@property NSInteger detectionBarMargin;
@property NSInteger detectionButtonInterButtonSpacing;

@property BOOL showHourGlass;
@property BOOL staticIndicators;

// Delegate
@property(weak) IBOutlet NSObject<TSXCameraInputViewDelegate> *delegate;

@property TSXCameraInputResponse *lastResponse;

+(void)initQrBeaconSupportWithDefaultWhitelistSource:(id<TSXCameraInputViewBleBeaconWhitelistSource>)defaultWhitelistSource;

@end
