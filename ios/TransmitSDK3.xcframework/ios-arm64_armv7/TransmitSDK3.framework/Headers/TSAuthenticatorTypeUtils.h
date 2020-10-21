//
//  TSAuthenticatorTypeUtils.h
//  TransmitSDK
//
//  Created by Eldan Ben Haim on 08/11/2017.
//  Copyright © 2017 TransmitSecurity. All rights reserved.
//

#import "TSAuthenticatorType.h"

@interface TSAuthenticatorTypeUtils : NSObject {}
+(NSString*)authenticatorTypeStringFromEnum:(TSAuthenticatorType)type;
+(NSNumber*)authenticatorTypeStringToEnum:(NSString*)type;
+(NSString*)typeNameFromId:(NSString*)authenticatorId;
+(NSString*)authenticatorTypeStringToAuthenticatorIdIfPossible:(NSString*)typeStr;
@end


extern NSString * const tsAuthenticatorFinger;
extern NSString * const tsAuthenticatorPinCode;
extern NSString * const tsAuthenticatorPassword;
extern NSString * const tsAuthenticatorPattern;
extern NSString * const tsAuthenticatorOTP;
extern NSString * const tsAuthenticatorFace;
extern NSString * const tsAuthenticatorVoice;
extern NSString * const tsAuthenticatorEye;
extern NSString * const tsAuthenticatorEmoji;
extern NSString * const tsAuthenticatorQuestions;
extern NSString * const tsAuthenticatorFaceID;
