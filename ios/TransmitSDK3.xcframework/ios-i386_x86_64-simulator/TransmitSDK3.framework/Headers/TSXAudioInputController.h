//
//  TSXAudioInputController.h
//  TransmitSDK
//
//  Created by Eldan Ben Haim on 07/11/2017.
//  Copyright © 2017 TransmitSecurity. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "TransmitSDKXm.h"

@class TSXAudioInputController;

@protocol TSXAudioInputControllerDelegate
-(void)audioInputControllerStartedSampling:(TSXAudioInputController*)ctler;
-(void)audioInputController:(TSXAudioInputController*)ctler responseCollected:(TSXAudioInputResponse*)response;
-(void)audioInputController:(TSXAudioInputController*)view responseCollectionError:(NSError*)error;
@end

@interface TSXAudioInputController : NSObject

-(void)startSampling;
-(void)endSampling;

@property NSArray<NSDictionary*> *acquisitionChallenges;
@property TSXAudioInputResponse *lastResponse;

@property NSObject<TSXAudioInputControllerDelegate> *delegate;
@end
