//
//  TSXHTTPTransportProvider.h
//  TransmitSDK
//
//  Created by Eldan Ben Haim on 28/09/2017.
//  Copyright © 2017 TransmitSecurity. All rights reserved.
//

#import "TransmitSDKXm.h"
#import "TSConnectionAuthenticationChallengeDelegate.h"

@class TSXSSLDomainConfiguration;

#define TSXConnectionAuthenticationChallengeDelegate TSConnectionAuthenticationChallengeDelegate

@interface TSXHTTPTransportProvider : TSXTransportProvider

@property NSTimeInterval timeoutInterval;

@property NSHTTPCookieStorage *cookieStorage;

@property NSDictionary<NSString*,TSXSSLDomainConfiguration*>* publicKeyPinningconfig;

+(void)setAuthChallengeDelegate:(id<TSXConnectionAuthenticationChallengeDelegate>)delegate;

@end
