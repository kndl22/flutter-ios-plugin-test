//
//  TransmitSDKXm+ios.h
//  TransmitSDK
//
//  Created by Eldan Ben Haim on 09/11/2017.
//  Copyright © 2017 TransmitSecurity. All rights reserved.
//

#ifndef TransmitSDKXm_IOS_h
#define TransmitSDKXm_IOS_h

#import "TransmitSDKXm.h"

@interface TSXTransmitSDKXm (ios) 

/**
 * Configure the SDK instance in this session to use a specific app group and keychain
 * group for storage.
 *
 * This must be invoked before the first access to the SDK sharedInstance.
 *
 * @param appGroupName       Name of appgroup to use for persistent storage.
 * @param keychainGroupName  Name of keychain group to use for key storage.
 */
+(void)shareDataWithAppGroup:(NSString*_Nonnull)appGroupName keychainGroup:(NSString*_Nonnull)keychainGroupName;

/**
 * Return the single shared instance of the TransmitSDKXm object -- the entry point
 * to Transmit SDK services.
 */
+(TSXTransmitSDKXm * _Nonnull)sharedInstance;

/**
 Timestamp since epoch for last wake up of application from background state.

 @return epoch based timestamp
 */
-(NSTimeInterval)lastWakeUpFromBackgroundSince1970;


/**
 Set alternate bundle for TransmitSDK3 resources. Not related to default UI in TransmitSDKUILayer.
 Set the alternate bundle before creating the TSXTransmitSDKXm instance to take effect.
 i.e. before calling +[TSXTransmitSDKXm sharedInstance].

 @param bundle NSBundle object
 */
+(void)setTsResourceBundle:(nonnull NSBundle*)bundle;

@end

#endif
