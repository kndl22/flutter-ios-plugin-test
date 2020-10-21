//
//  TSAuthenticatorType.h
//  TransmitSDK
//
//  Created by Eldan Ben Haim on 08/11/2017.
//  Copyright © 2017 TransmitSecurity. All rights reserved.
//

#ifndef TSAuthenticatorType_h
#define TSAuthenticatorType_h

/**
 * \enum TSAuthenticatorType Authenticator types
 * @file TSAuthenticatorType.h
 */
typedef enum : NSUInteger {
    TS_AUTHENTICATOR_PASSWORD = 0,  /**< Password Authenticator */
    TS_AUTHENTICATOR_FINGERPRINT,   /**< Fingerprint Authenticator */
    TS_AUTHENTICATOR_PINCODE,       /**< PIN code Authenticator */
    TS_AUTHENTICATOR_PATTERN,       /**< Pattern Authenticator */
    TS_AUTHENTICATOR_OTP,           /**< One Time Password (OTP) Authenticator */
    TS_AUTHENTICATOR_FACE,          /**< Face recognition Authenticator */
    TS_AUTHENTICATOR_VOICE,         /**< Voice passphrase Authenticator */
    TS_AUTHENTICATOR_EYE,           /**< Eye identification Authenticator */
    TS_AUTHENTICATOR_EMOJI,         /**< Emoji password Authenticator */
    TS_AUTHENTICATOR_QUESTIONS,     /**< User Knowledge Questions Authenticator */
    TS_AUTHENTICATOR_FACE_ID,     /**< iPhoneX auth */
} TSAuthenticatorType;

extern NSString * _Nonnull const tsAuthenticatorIdFingerNative; /**< Native Fingerprint Authenticator implementation Id */
extern NSString * _Nonnull const tsAuthenticatorIdPINNative; /**< Native PIN code Authenticator implementation Id */
extern NSString * _Nonnull const tsAuthenticatorIdPatternNative; /**< Native Pattern Authenticator implementation Id */
extern NSString * _Nonnull const tsAuthenticatorIdPasswordNative; /**< Native Password Authenticator implementation Id */
extern NSString * _Nonnull const tsAuthenticatorIdPINCentralizedNative; /**< Native PIN code Authenticator on server implementation Id */
extern NSString * _Nonnull const tsAuthenticatorIdPatternCentralizedNative; /**< Native Pattern Authenticator on server implementation Id */
extern NSString * _Nonnull const tsAuthenticatorIdOTPNative; /**< Native OTP Authenticator implementation Id */
extern NSString * _Nonnull const tsAuthenticatorIdFaceNative; /**< Native Face recognition Authenticator implementation Id */
extern NSString * _Nonnull const tsAuthenticatorIdFaceCentralizedNative; /**< Native Face recognition Authenticator using server registration implementation Id */
extern NSString * _Nonnull const tsAuthenticatorIdVoiceServerNative; /**< Native Voice passphrase Authenticator using Nuance Voice Server implementation Id */
extern NSString * _Nonnull const tsAuthenticatorIdEyeNative; /**< Native Eye identification Authenticator implementation Id */
extern NSString * _Nonnull const tsAuthenticatorIdEmojiNative; /**< Native Emoji Authenticator implementation Id */
extern NSString * _Nonnull const tsAuthenticatorIdQuestionsNative; /**< Native Questions Authenticator implementation Id */
extern NSString * _Nonnull const tsAuthenticatorIdFaceIDNative; /**< iPhoneX auth */


#endif /* TSAuthenticatorType_h */
