//
//  TSXPresentersProtocol.h
//  TransmitSDKUILayer
//
//  Created by Transmit Security on 12/02/2019.
//  Copyright © 2019 Transmit Security LTD. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "SDK3.h"

NS_ASSUME_NONNULL_BEGIN

typedef void (^Completion) (NSDictionary* _Nullable data, TSXAuthenticationError* _Nullable error);
@protocol TSXGeneralPresenterProtocol;

#pragma mark - UI Presenter (Application)
/*! \protocol TSXIParentPresenterProtocol TSXPresentersProtocol.h
 *  \brief Parent presenter protocol
 *
 * Inform the hosting view controlles to keep the current presenter in the navigation stack.
 *
 * @implementation should be provided by application developer
 */
@protocol TSXIParentPresenterProtocol<NSObject>
@end

/*! \protocol TSXUIContextProtocol TSXPresentersProtocol.h
 *  \
 *
 * Base UI Context protocol that provides UI context object.
 *
 *
 * @implementation provided by SDK
 */
@protocol TSXUIContextProtocol

/**
 UIContext provides UI utils.
 */
@property (nonatomic, readonly, nullable) TSXUIContext *uiContext;
@end

/*! \protocol TSXGeneralSessionProtocol TSXPresentersProtocol.h
 *  \brief Base UI session protocol
 *
 * Base UI session protocol that provides policy action context and client context
 * objects to presenters.
 *
 * @implementation provided by SDK
 */
#pragma mark - Session Protocols
#pragma mark General Session (SDK)
@protocol TSXGeneralSessionProtocol<TSXUIContextProtocol>

/**
 * Provides information on the currently executed action in a policy. This class is provided by the SDK to the client
 * on callback invocations to allow the client to access information about the action during its execution.
 */
@property (nonatomic, readonly, nullable) TSXPolicyAction *actionContext;

/**
 The clientContext for the SDK operation invocation for which this callback is invoked.
 */
@property (nonatomic, readonly, nullable) NSDictionary *clientContext;
@end

#pragma mark Authenticator Session (SDK)

/*! \protocol TSXGeneralAuthenticatorSessionProtocol TSXPresentersProtocol.h
 *  \brief Base authentication UI session protocol
 *
 * Base authentication UI session protocol that provides authenticator description object
 * and authenticator session mode.
 *
 * @implementation provided by SDK
 */
@protocol TSXGeneralAuthenticatorSessionProtocol <TSXGeneralSessionProtocol>

/**
 * Describes an authenticator. This includes general description
 * of the authenticator and its status.
 */
@property (nonatomic, readonly) TSXAuthenticatorDescription *authDescription;

/**
 *
 * Authenticator UI session modes.
 */
@property (nonatomic, readonly) TSXAuthenticatorSessionMode currentMode;
@end

#pragma mark - Abstract Base Protocols
#pragma mark Base Presenter (Application)

/*! \protocol TSXBasePresenterProtocol TSXPresentersProtocol.h
 *  \brief Base presenter protocol.
 *
 * Base for all presenter protocols.
 */
@protocol TSXBasePresenterProtocol <NSObject>
/**
 * Provides the UI context of the Session/Action for the presenter.
 *
 */
-(void)startUIContext:(id<TSXUIContextProtocol>)uiContext;
@end

#pragma mark General Session Presenter Delegate (SDK)

/*! \protocol TSXGeneralPresenterDelegate TSXPresentersProtocol.h
 *  \brief General presenter delegate protocol
 *
 * General presenter delegate protocol that provides common
 * properties and methods for non-authentication sessions and control flow actions.
 *
 * @implementation provided by SDK
 */
@protocol TSXGeneralPresenterDelegate <NSObject>

/**
 Cancel the current non-authentication session or control flow action.
 */
-(void)provideCancel;

/**
 * Request an escape from the current control flow action.
 */
-(void)requestEscape:(TSXActionEscapeOption*)escapeOption;
@end

#pragma mark - General Session Presenter (Application)
/*! \protocol TSXGeneralPresenterProtocol TSXPresentersProtocol.h
 *  \brief General UI session presenter protocol
 *
 * General UI session presenter protocol for non-authentication sessions and control flow actions.
 *
 * @implementation should be provided by application developer
 */
@protocol TSXGeneralPresenterProtocol<NSObject>

/**
 Informs the presenter that the session has started.
 
 @param session General session object.
 */
-(void)startSession:(id<TSXGeneralSessionProtocol>)session;

/**
 Informs the presenter that the session has ended.
 */
-(void)endSession;

@end


#pragma mark - Authentication General Session Presenter Delegate (SDK)

/*! \protocol TSXGeneralAuthenticationPresenterDelegate TSXPresentersProtocol.h
 *  \brief Authentication UI session presenter delegate protocol
 *
 * Authentication UI session presenter delegate protocol that provides common
 * properties and methods for authentication UI sessions.
 *
 * @implementation provided by SDK
 */
@protocol TSXGeneralAuthenticationPresenterDelegate <TSXGeneralPresenterDelegate>

/**
 Handle authentication input or control response.
 
 @param input Authentication input or control response object.
 */
-(void)provideInput:(TSXInputOrControlResponse *)input;

/**
 Handle error with set of valid recovery options, return response asynchronously to the
 provided handler.
 Use to call customized implementation of TSXErrorRecoveryPresenterProtocol through SDK
 rather than directly from the current customized Presenter.
 
 @param error Error object contains the error code, error message and additional data.
 @param validRecoveries The Recoveries options that allow to invoke them.
 @param handler The handler of the select option.
 */
-(void)showDefaultUIRecoveryForError:(nonnull TSXAuthenticationError *)error validRecoveries:(TSXAuthenticationErrorRecoverySet)validRecoveries asynchronouslyWithHandler:(nonnull void (^)(TSXAuthenticationErrorRecovery))handler;
@end

#pragma mark - Authentication General Session Presenter (Application)

/*! \protocol TSXAuthenticationPresenterProtocol TSXPresentersProtocol.h
 *  \brief General authentication UI session presenter protocol
 *
 * General authentication UI session presenter protocol for handling single Authenticator.
 *
 * @implementation should be provided by application developer
 */
@protocol TSXAuthenticationPresenterProtocol<TSXBasePresenterProtocol>


/**
 Informs the presenter that the authentication session has started.
 
 @param session General authentication UI session object
 */
-(void)startSession:(id<TSXGeneralAuthenticatorSessionProtocol>)session;

/**
 Informs the presenter that the authentication session has ended.
 */
-(void)endSession;

/**
 Informs the presenter that the session mode has changed to registration after expiration.
 */
-(void)changeSessionModeToRegistrationAfterExpiration;



/**
 Informs the presenter that the authentication session is ready for input.
 */
-(void)promiseInputRetry;

/**
 Handle error with set of valid recovery options, return response asynchronously to the
 provided handler.
 
 @param error Error object contains the error code, error message and additional data.
 @param validRecoveries The Recoveries options that allow to invoke them.
 @param handler The handler of the select option.
 */
-(void)handleRecoveryOptionsForError:(TSXAuthenticationError *)error validRecoveries:(TSXAuthenticationErrorRecoverySet)validRecoveries asynchronouslyWithHandler:(void (^)(TSXAuthenticationErrorRecovery))handler;

/**
 Handle authentication error.
 
 @param error Error object.
 */
-(void)retryAuthenticationAfterInputError:(TSXAuthenticationError * _Nullable)error;

/**
 General authentication UI session delegate object.
 */
@property (weak, nonatomic) id<TSXGeneralAuthenticationPresenterDelegate> authenticatorDelegate;
@end

#pragma mark - MultiStepAuthentication General Session Presenter (Application)

/*! \protocol TSXMultiStepAuthenticationPresenterProtocol TSXPresentersProtocol.h
 *  \brief Multistep authentication UI session protocol
 *
 * Multistep authentication UI session protocols for handling single multistep authenticators.
 *
 * @implementation should be provided by application developer
 */
@protocol TSXMultiStepAuthenticationPresenterProtocol<TSXAuthenticationPresenterProtocol>

/**
 * Set the current input step. This is called before the session is ready for authentication input.
 *
 * @param stepNumber The current, 0-based step number. This is incremented to reflect progress in the session.
 * @param maxStepNumber The number of steps in the session, if known in advance. If this is not known this is -1.
 * @param stepDescription An object describing the step, and possibly the input required for this step.
 */
-(void)setInputStepWithStepNumber:(long)stepNumber maxStepNumber:(long)maxStepNumber stepDescription:(nullable id)stepDescription;
@end

#pragma mark - Pin Authenticator Extension (Application)
/*! \protocol TSXPinPresenterProtocol TSXPresentersProtocol.h
 *  \brief PIN authentication presenter protocol
 *
 * Provides additional details about PIN Authenticator.
 *
 * @implementation should be provided by application developer
 */
@protocol TSXPinPresenterProtocol <TSXAuthenticationPresenterProtocol>

/**
 Provide the PIN length
 
 @param length The pin length
 */
-(void)pinLength:(long)length;
@end


#pragma mark - Pattern Authenticator Extension (Application)

/*! \protocol TSXPatternPresenterProtocol TSXPresentersProtocol.h
 *  \brief Pattern authentication presenter protocol
 *
 * Provides additional details about pattern authenticator.
 *
 * @implementation should be provided by application developer
 */
@protocol TSXPatternPresenterProtocol <TSXAuthenticationPresenterProtocol>

/**
 Provides the pattern matrix width and height.
 
 @param width The pattern matrix number of columns.
 @param height The pattern matrix number of rows.
 */
-(void)patternWidth:(long)width height:(long)height;
@end

#pragma mark - OTP Authenticator Delegate Extension (SDK)

/*! \protocol TSXOTPAuthenticatorDelegate TSXPresentersProtocol.h
 *  \brief OTP authentication session delegate protocol
 *
 * Additional delegate for OTP operations other than those provided
 * by the authenticator delegate.
 *
 * @implementation provided by SDK
 */
@protocol TSXOTPAuthenticatorDelegate<TSXGeneralAuthenticationPresenterDelegate>

/**
 Handle the selected OTP target, such as phone number or email.
 
 @param target The selected target.
 */
-(void)provideOtpTarget:(TSXOtpTarget*)target;

/**
 Request a new OTP code.
 */
-(void)resendOtpCode;
@end

#pragma mark - OTP Authenticator Presenter Extension (Application)

/*! \protocol TSXOtpPresenterProtocol TSXPresentersProtocol.h
 *  \brief OTP authentication presenter protocol
 *
 * Provides OTP available targets as well as input format type and
 * additional details about OTP authenticator.
 *
 * @implementation should be provided by application developer
 */
@protocol TSXOtpPresenterProtocol <TSXAuthenticationPresenterProtocol>

/**
 Provides the OTP targets
 
 @param targets The available OTP targets
 */
-(void)setOTPTargets:(NSArray<TSXOtpTarget*>*)targets;

/**
 Provides the OTP format and selected target.
 
 @param format The OTP format type (Numeric, QR).
 @param target The selected target.
 */
-(void)setOTPInputFormat:(TSXOtpFormat *)format target:(TSXOtpTarget *)target;

/**
 Delegate object for OTP specific operations.
 */
@property (weak, nonatomic) id<TSXOTPAuthenticatorDelegate> otpDelegate;
@end

#pragma mark - Mobile Approve Authenticator Presenter Delegate Extension (SDK)

/*! \protocol TSXMobileApproveAuthenticatorDelegate TSXPresentersProtocol.h
 *  \brief Mobile approval authentication session delegate protocol
 *
 * Additional delegate for approval operations other than those provided
 * by the authenticator delegate.
 *
 * @implementation provided by SDK
 */
@protocol TSXMobileApproveAuthenticatorDelegate<TSXGeneralAuthenticationPresenterDelegate>

/**
 Handle the selected target for mobile approval.
 
 @param targets The selected target.
 */
-(void)provideMobileTargets:(NSArray<TSXMobileApproveTarget*>*)targets;

-(void)pollForApprovals;

@end

/*! \protocol TSXTotpAuthenticatorPresenterProtocol TSXPresentersProtocol.h
 *  \brief TOTP authentication presenter protocol
 *
 * Provides TOTP available targets as well as input format type and
 * additional details about TOTP authenticator.
 *
 * @implementation should be provided by application developer
 */
@protocol TSXMobileApproveAuthenticatorPresenterProtocol<TSXAuthenticationPresenterProtocol>

/**
 Provides the available targets that can be used to generate TOTP codes.
 
 @param targets The available targets.
 */
-(void)setAvailableTargets:(NSArray<TSXMobileApproveTarget *> *)targets;

/**
informs that presenter should start polling for approvals

@param otp the OTP challenge if available
*/
-(void)startPollingWithOTP:(TSXMobileApproveOtp *)otp instructions:(NSString*)instructions;

/**
 Delegate object for TOTP specific operations.
 */
@property (weak, nonatomic) id<TSXMobileApproveAuthenticatorDelegate> approveAuthenticatorDelegate;
@end

#pragma mark - TOTP Authenticator Presenter Delegate Extension (SDK)

/*! \protocol TSXTotpAuthenticatorDelegate TSXPresentersProtocol.h
 *  \brief TOTP authentication session delegate protocol
 *
 * Additional delegate for TOTP operations other than those provided
 * by the authenticator delegate.
 *
 * @implementation provided by SDK
 */
@protocol TSXTotpAuthenticatorDelegate<TSXGeneralAuthenticationPresenterDelegate>

/**
 Handle the selected TOTP target, such as mobile device.
 
 @param target The selected target.
 */
-(void)provideTotpTarget:(TSXTotpTarget*)target;
@end

#pragma mark - TOTP Authenticator Presenter Extension (Application)

/*! \protocol TSXTotpAuthenticatorPresenterProtocol TSXPresentersProtocol.h
 *  \brief TOTP authentication presenter protocol
 *
 * Provides TOTP available targets as well as input format type and
 * additional details about TOTP authenticator.
 *
 * @implementation should be provided by application developer
 */
@protocol TSXTotpAuthenticatorPresenterProtocol<TSXAuthenticationPresenterProtocol>

/**
 Provides the available targets that can be used to generate TOTP codes.
 
 @param targets The available targets.
 */
-(void)setAvailableTargets:(NSArray<TSXTotpTarget *> *)targets;

/**
 Provide the external challenge input type for which a challenge input
 should be collected, such as QR or numeric input.
 
 @param challenge The TOTP challenge.
 */
-(void)setChallenge:(TSXTotpChallenge *)challenge;

/**
 Delegate object for TOTP specific operations.
 */
@property (weak, nonatomic) id<TSXTotpAuthenticatorDelegate> totpAuthenticatorDelegate;
@end

#pragma mark - Available Control Options Base Class (SDK)

/**
 Base available options class for listing common control options
 *
 * @implementation provided by SDK
 */
@interface TSXAvailableOptions : NSObject

/**
 Retry current operation option available
 */
@property (nonatomic, readonly) BOOL retry;

/**
 Abort control flow option available
 */
@property (nonatomic, readonly) BOOL abort;
@end

#pragma mark - Authenticators Available Control Options (SDK)

/**
 Extended available options class for multiple authenticators control.
 *
 * @implementation provided by SDK
 */
@interface TSXAuthenticatorAvailableOptions : TSXAvailableOptions

/**
 Change to any other enabled authenticator option available
 */
@property (nonatomic, readonly) BOOL change;

/**
 List all provided authenticators option available
 */
@property (nonatomic, readonly) BOOL select;
@end

#pragma mark - Fallback Available Control Options (SDK)

/**
 Extended available options class for authentication fallback control.
 *
 * @implementation provided by SDK
 */
@interface TSXFallbackAvailableOptions : TSXAvailableOptions

/**
 Choose fallback to another authenticator option available
 */
@property (nonatomic, readonly) BOOL fallback;

/**
 Choose fallback from Authenticators menu option available
 */
@property (nonatomic, readonly) BOOL authMenu;
@end

#pragma mark - Control Options Delegate (SDK)

/*! \protocol TSXBaseControlOptionDelegate TSXPresentersProtocol.h
 *  \brief Base control options delegate protocol
 *
 * Delegate protocol to handle the available control options.
 *
 * @implementation provided by SDK
 */
@protocol TSXBaseControlOptionDelegate<TSXGeneralPresenterDelegate>

/**
 Retry current operation.
 */
-(void)provideControlRetry;

/**
 Abort control flow.
 */
-(void)provideControlAbort;
@end

#pragma mark - Authenticator Control Options Delegate (SDK)

/*! \protocol TSXControlOptionDelegate TSXPresentersProtocol.h
 *  \brief Extended authentication control options delegate protocol
 *
 * Delegate protocol to handle the available control options during authentication.
 *
 * @implementation provided by SDK
 */
@protocol TSXAuthenticatorControlOptionDelegate<TSXBaseControlOptionDelegate>

/**
 Select from Authenticators list
 */
-(void)provideControlSelect;

/**
 Change to another enabled Authenticator
 */
-(void)provideControlChange;
@end

#pragma mark - Authenticator Fallback Control Options Delegate (SDK)
/*! \protocol TSXAuthenticatorFallbackDelegate TSXPresentersProtocol.h
 *  \brief Fallback from current authentication option list presenter delegate protocol
 *
 * Provides the fallback from current authentication control options.
 *
 * @implementation provided by SDK
 */
@protocol TSXAuthenticatorFallbackDelegate<TSXBaseControlOptionDelegate>

/**
 Switch to predefined fallback Authenticator.
 */
-(void)provideFallback;

/**
 Present list of other enabled Authenticators
 */
-(void)provideAuthMenu;
@end

#pragma mark - Cancellation Dialog Presenter Protocol (Application)
/*! \protocol TSXAuthenticationCancellationPresenterProtocol TSXPresentersProtocol.h
 *  \brief Authentication cancelation option list presenter protocol
 *
 * Provides the available actions option when authentication cancelation is invoked.
 *
 * @implementation should be provided by application developer
 */
@protocol TSXAuthenticationCancellationPresenterProtocol<TSXBasePresenterProtocol>

/**
 Provide the authentication cancellation title, message and the available control option.
 
 @param title Title.
 @param message Body text.
 @param availableOptions available control options list.
 */
-(void)setTitle:(nullable NSString*)title message:(nullable NSString*)message availableOptions:(TSXAuthenticatorAvailableOptions*)availableOptions;

/**
 Authentication cancelation option list delegate object.
 */
@property (weak, nonatomic) id<TSXAuthenticatorControlOptionDelegate> controlOptionDelegate;
@end

#pragma mark - Error Dialog Presenter Protocol (Application)
/*! \protocol TSXErrorRecoveryPresenterProtocol TSXPresentersProtocol.h
 *  \brief Error recovery option list presenter protocol
 *
 * Provides the error recovery control options.
 *
 * @implementation should be provided by application developer
 */
@protocol TSXErrorRecoveryPresenterProtocol<TSXBasePresenterProtocol>

/**
 Provide the error title, message and the available control options.
 
 @param title Title.
 @param message Body text.
 @param availableOptions The error available control options.
 */
-(void)setTitle:(nullable NSString*)title message:(nullable NSString*)message availableOptions:(TSXAuthenticatorAvailableOptions*)availableOptions;

/**
 Error recovery option list delegate object.
 */
@property (weak, nonatomic) id<TSXAuthenticatorControlOptionDelegate> controlOptionDelegate;
@end

#pragma mark - Fallback Dialog Presenter Protocol (Application)

/*! \protocol TSXAuthenticatorFallbackPresenterProtocol TSXPresentersProtocol.h
 *  \brief Authenticatior fallback option list presenter protocol
 *
 * Provides the fallback control options for current authenticator session.
 *
 * @implementation should be provided by application developer
 */
@protocol TSXAuthenticatorFallbackPresenterProtocol<TSXBasePresenterProtocol>

/**
  Provide the authenticator fallback title, message and the available control option.

 @param title Title.
 @param message Body text.
 @param sessionName The failed Authenticator session name.
 @param availableOptions The authenticator fallback contorl options.
 */
-(void)setTitle:(nullable NSString*)title message:(nullable NSString*)message failedSessionName:(NSString *)sessionName availableOptions:(TSXFallbackAvailableOptions*)availableOptions;

/**
 Authenticator fallback option list delegate object.
 */
@property (weak, nonatomic) id<TSXAuthenticatorFallbackDelegate> fallbackDelegate;
@end

#pragma mark - Info Action Delegate (SDK)

/*! \protocol TSXInfoActionDelegate TSXPresentersProtocol.h
 *  \brief Information action presenter delegate protocol
 *
 * Delegate protocol for control flow information action UI session presenter.
 *
 * @implementation provided by SDK
 */
@protocol TSXInfoActionDelegate<TSXGeneralPresenterDelegate>

/**
 Handle positive response.
 */
-(void)provideContinue;
@end

#pragma mark - Info Action Presenter (SDK)

/*! \protocol TSXInfoActionPresenterProtocol TSXPresentersProtocol.h
 *  \brief Control flow action UI session presenter protocol
 *
 * Provides details for Information, Confirmation and Rejection control flow actions.
 *
 * @implementation should be provided by application developer
 */
@protocol TSXInfoActionPresenterProtocol<TSXBasePresenterProtocol>

/**
 Handle action presentation details.
 
 @param title Title.
 @param text Body text.
 @param continueButtonText Continue button text.
 @param cancelButtonText Cancel button text.
 */
-(void)setTitle:(NSString *)title text:(NSString *)text continueButtonText:(NSString *)continueButtonText cancelButtonText:(NSString* _Nullable)cancelButtonText actionContext:(TSXPolicyAction*)actionContext;

/**
 Delegate object for control flow action control options.
 */
@property (weak, nonatomic) id<TSXInfoActionDelegate> actionDelegate;

@end

#pragma mark - TOTP (Soft Token) Generation Session Delegate (SDK)
/*! \protocol TSXTotpDelegate TSXPresentersProtocol.h
 *  \brief TOTP code generation presenter delegate protocol
 *
 * Protocol for client side initiated TOTP code generation presenter delegate
 *
 * @implementation provided by SDK
 */
@protocol TSXTotpDelegate <TSXGeneralAuthenticationPresenterDelegate>
/**
 Called to provide the challenge input.
 
 @param challengeInput The challenge input.
 */
-(void)provideChallengeInput:(NSString*)challengeInput;
@end

#pragma mark - TOTP (Soft Token) Generation Session Presenter (Application)
/*! \protocol TSXTotpPresenterProtocol TSXPresentersProtocol.h
 *  \brief TOTP code generation presenter protocol
 *
 * Provides TOTP available challenges, optionally a predefined message and generated code details.
 *
 * @implementation should be provided by application developer
 */
@protocol TSXTotpPresenterProtocol <TSXGeneralPresenterProtocol>
/**
 Code presentation details. When time based includes time to live and remaining seconds.
 When canonical generation is used, a message is provided.
 
 @param code TOTP code.
 @param ttlSeconds Total seconds.
 @param remainingSeconds Remaining seconds until new code is generated.
 */
-(void)setTotpCode:(NSString*)code ttlSeconds:(long)ttlSeconds remainingSeconds:(long)remainingSeconds;

/**
 Provide constant message in canonical TOTP generation mode.
 
 @param message Code generation message.
 */
-(void)setMessage:(NSString*)message;


/**
 Provide array of optional TOTP challenges (Numeric,QR)

 @param challenges TOTP challenges
 */
-(void)setTotpChallenges:(NSArray<TSXTotpChallengeFormat*>*)challenges;

/**
 Delegate object to call the TOTP actions.
 */
@property (weak, nonatomic) id<TSXTotpDelegate> totpDelegate;
@end


#pragma mark - Promotion Session Delegate (SDK)
/*! \protocol TSXPromotionDelegate TSXPresentersProtocol.h
 *  \brief Authenticators promotion presenter delegate protocol
 *
 * Provides control options for promotion presenter and consumes choice of Authenticator
 * to register.
 *
 * @implementation provided by SDK
 */
@protocol TSXPromotionDelegate

/**
 Skip the promotion session.
 */
-(void)providePromotionSkip;

/**
 Cancel promotion and abort control flow.
 */
-(void)providePromotionAbort;

/**
 Continue from promotional introduction presentation step to Authenticators list.
 */
-(void)providePromotionContinue;

/**
 Provide Authenticator to register.
 
 @param authenticator Selected authenticator.
 */
-(void)provideInputAuthenticator:(TSXAuthenticatorDescription*)authenticator;

/**
* Request an escape from the current control flow action.
*/
-(void)requestEscape:(TSXActionEscapeOption*)option;
@end

#pragma mark - Promotion Session Presenter (Application)
/*! \protocol TSXPromotionPresenterProtocol TSXPresentersProtocol.h
 *  \brief Authenticator promotion introduction and regitration presenter protocol
 *
 * Provides introductory information about the promotion options, suggests list of
 * Authenticators to promote and allows Authenticator registration.
 *
 * @implementation should be provided by application developer
 */
@protocol TSXPromotionPresenterProtocol <TSXGeneralPresenterProtocol>
/**
 Provide promotion introduction details.
 
 @param title Title.
 @param text Body text.
 @param continueText Continue button text.
 @param cancelText Cancel button text.
 */
-(void)setIntroduction:(NSString *)title text:(NSString *)text continueText:(NSString *)continueText cancelText:(NSString *)cancelText;

/**
 Provide the promotion authenticators list and continue button text.
 
 @param authenticators Available Authenticators list.
 @param continueText Continue button text.
 */
-(void)setAuthenticatorsList:(NSArray<TSXAuthenticatorDescription*>*)authenticators continueText:(NSString*)continueText;

/**
 Delegate object for promotion control options in Authenticator choice input.
 */
@property (weak, nonatomic) id<TSXPromotionDelegate> promotionDelegate;
@end


#pragma mark - Configuration Session Delegate (SDK)
/*! \protocol TSXConfigurationDelegate TSXPresentersProtocol.h
 *  \brief Authenticators configuration presenter delegate protocol
 *
 * Provides actions on Authenticators available throughout the application flows.
 *
 * @implementation provided by SDK
 */

@protocol TSXConfigurationDelegate <TSXGeneralPresenterDelegate>
/**
 Register an unregistered Authenticator.
 Completion block returns no data on success. Returns error on failure.

 @param authenticator Selected Authenticator.
 @param completion Optional completion block.
 */
-(void)registerAuthenticator:(TSXConfigurableAuthenticator *)authenticator completion:(Completion _Nullable)completion;

/**
 Unregister a registered authenticator.
 Completion block returns no data on success. Returns error on failure.

 @param authenticator Selected Authenticator.
 @param completion Optional completion block.
 */
-(void)unregisterAuthenticator:(TSXConfigurableAuthenticator *)authenticator completion:(Completion _Nullable)completion;

/**
 Register a registered Authenticator.
 Completion block returns no data on success. Returns error on failure.

 @param authenticator Selected Authenticator.
 @param completion Optional completion block.
 */
-(void)reregisterAuthenticator:(TSXConfigurableAuthenticator *)authenticator completion:(Completion _Nullable)completion;

/**
 Set Authenticator as default for authentication.
 Completion block returns no data on success. Returns error on failure.

 @param authenticator Selected Authenticator.
 @param completion Optional completion block.
 */
-(void)setDefaultAuthenticator:(TSXConfigurableAuthenticator *)authenticator completion:(Completion _Nullable)completion;
@end

#pragma mark - Configuration Session Presenter (Application)
/*! \protocol TSXConfigurationPresenterProtocol TSXPresentersProtocol.h
 *  \brief Authenticators configuration presenter protocol
 *
 * Provides list of Authenticators available throughout the application flows.
 *
 * @implementation should be provided by application developer
 */
@protocol TSXConfigurationPresenterProtocol <TSXGeneralPresenterProtocol, TSXIParentPresenterProtocol>

/**
 Provide list of the available authenticators
 
 @param authenticators Available authenticators.
 */
-(void)setAuthenticatorsList:(NSArray<TSXConfigurableAuthenticator *> *)authenticators;

/**
 Delegate object for Authenticator actions.
 */
@property (weak, nonatomic) id<TSXConfigurationDelegate> configurationDelegate;
@end


#pragma mark - Authenticators List Delegate (SDK)
/*! \protocol TSXAuthenticatorsListDelegate TSXPresentersProtocol.h
 *  \brief Authenticators list presenter delgate protocol
 *
 * Provides Authenticator option selection action.
 *
 * @implementation provided by SDK
 */
@protocol TSXAuthenticatorsListDelegate <TSXGeneralPresenterDelegate>
/**
 Select Authenticator to use.
 
 @param authenticator Selected Authenticator.
 */
-(void)provideInputAuthenticator:(TSXAuthenticationOption *)authenticator;
@end

#pragma mark - Authenticators List Presenter (Application)
/*! \protocol TSXAuthenticatorsListPresenterProtocol TSXPresentersProtocol.h
 *  \brief Authenticators list presenter protocol
 *
 * Provides list of optional Authenticators for current use (see actionContext).
 *
 * @implementation should be provided by application developer
 */
@protocol TSXAuthenticatorsListPresenterProtocol <TSXBasePresenterProtocol>

/**
 Provides list of optional Authenticators for current use as referenced by actionContext.
 The action context includes one of the following strings:
 1. "registration" - List of Authenticators available for registration.
 2. "authentication" - List of enabled Authenticators to authenticate with.
    This list may include unregistered or locked Authenticators.
    See -[TSXUIHandler shouldIncludeDisabledAuthenticatorsInMenuWithActionContext:clientContext:] for more details.
 3. "provision_totp" - List of Authenticators that may be used to protect a TOTP code generator.
 
 
 @param options List of Authenticators wrapped in options objects.
 @param actionContext Context of the Authenticators list (registration, authentication, provision_totp).
 @param clientContext Client context.
 */
-(void)setAuthenticatorsOptions:(NSArray<TSXAuthenticationOption *> *)options actionContext:(TSXPolicyAction *)actionContext clientContext:(NSDictionary *)clientContext;

/**
 Delegate object for selecting Authenticators.
 */
@property (weak, nonatomic) id<TSXAuthenticatorsListDelegate> authenticatorsListDelegate;
@end

#pragma mark - Scan QR Session Delegate (SDK)
/*! \protocol TSXScanQRDelegate TSXPresentersProtocol.h
 *  \brief QR scan presenter delegate protocol
 *
 * Provides input action for QR scan presenter
 *
 * @implementation provided by SDK
 */
@protocol TSXScanQRDelegate<TSXGeneralPresenterDelegate>
/**
 Provides camera QR acquisition response. See "TSXCameraInputView.h" in TransmitSDK3.framework
 for "TSXCameraInputResponse" generation.
 
 @param response TSXCameraInputResponse object with QR data aqcuired by camera.
 */
-(void)provideCameraInputResponse:(TSXCameraInputResponse*)response;
@end

#pragma mark - Scan QR Session Presenter (Application)
/*! \protocol TSXScanQRPresenterProtocol TSXPresentersProtocol.h
 *  \brief QR scan presenter protocol
 *
 * Provides context for QR acquisition with TSXCameraInputView.
 * See "TSXCameraInputView.h" in TransmitSDK3.framework for "TSXCameraInputResponse" generation.
 *
 * @implementation should be provided by application developer
 */
@protocol TSXScanQRPresenterProtocol<TSXGeneralPresenterProtocol>

/**
 Provide instructions text and QR code format type.
 
 @param instructionsText Instructions text.
 @param qrCodeFormat QR code format type.
 */
-(void)startQrInputWithInstructions:(NSString*)instructionsText qrCodeFormat:(TSXQrCodeFormat)qrCodeFormat;

/**
 Delegate object for QR scan input handling.
 */
@property (weak, nonatomic) id<TSXScanQRDelegate> scanQRDelegate;
@end

#pragma mark - Local Authenticator Invalidated Delegate (SDK)
/*! \protocol TSXLocalAuthenticatorInvalidateDelegate TSXPresentersProtocol.h
 *  \brief Local Authenticator invalidation notice presenter delegate protocol
 *
 * Provides notice about local Authenticator which got unregistered by the hosting platform.
   E.g. Transmit biometric Authenticator invalidated after editing device biometrics settings.
 *
 * @implementation provided by SDK
 */
@protocol TSXLocalAuthenticatorInvalidatedDelegate
/**
 Dismiss and acknowledge notice.
 */
-(void)provideComplete;
@end

#pragma mark - Local Authenticator Invalidated Presenter (Application)
/*! \protocol TSXLocalAuthenticatorInvalidatedPresenterProtocol TSXPresentersProtocol.h
 *  \brief Local Authenticator invalidation notice presenter protocol
 *
 * Provide local Authenticator invalidation notice details.
 *
 * @implementation should be provided by application developer
 */
@protocol TSXLocalAuthenticatorInvalidatedPresenterProtocol<TSXBasePresenterProtocol>

/**
 Provide description object of the invalidated Authenticator.
 
 @param description Authenticator description object.
 */
-(void)localAuthenticatorInvalidatedWithDescription:(TSXAuthenticatorDescription* _Nonnull)description;

/**
 Delegate object for completion of notice presentation.
 */
@property (weak, nonatomic) id<TSXLocalAuthenticatorInvalidatedDelegate> localAuthenticatorInvalidateDelegate;
@end


#pragma mark - CSM Ticket Wait Delegate (SDK)
/*! \protocol TSXCSMTicketWaitDelegate TSXPresentersProtocol.h
 *  \brief Cross Session Message presenter delegate protocol
 *
 * Provides input action for Cross Session Message presenter
 *
 * @implementation provided by SDK
 */
@protocol TSXCSMTicketWaitDelegate<TSXGeneralPresenterDelegate>
/**
Detect if the Cross Session Message ticket had consumed.
 */
-(void)pollForCSMTicketWait;
@end

#pragma mark - Cross Session Message Presenter (Application)
/*! \protocol TSXScanQRPresenterProtocol TSXPresentersProtocol.h
 *  \brief Cross Session Message presenter  protocol
 *
 * Provides ticket information.
 *
 * @implementation should be provided by application developer
 */
@protocol TSXCSMTicketWaitPresenterProtocol<TSXGeneralPresenterProtocol>

/**
 Provide ticket information such as title, message and ticket format (QR/Alphanumeric).
 */
-(void)startCSMWithTicketWaitInfo:(TSXTicketWaitingInformation*)ticketWaitInfo;

/**
 Delegate object for Cross Session Message input handling.
 */
@property (weak, nonatomic) id<TSXCSMTicketWaitDelegate> ticketWaitDelegate;
@end

#pragma mark - Public Approvals Session Presenter (Application)
/*! \protocol TSXApprovalsPublicPresenterProtocol TSXPresentersProtocol.h
 *  \brief Approvals public presenter protocol
 *
 * Protocol for presenting current approval or no pending approvals status.
 *
 * @implementation should be provided by application developer
 */
@protocol TSXApprovalsPublicPresenterProtocol <TSXGeneralPresenterProtocol>
/**
 Refresh pending approvals list.
 Completion block returns no data on success. Returns error on failure.
 
 @param completion Optional completion block.
 */
-(void)refreshApprovalsWithCompletion:(Completion _Nullable)completion;
@end

NS_ASSUME_NONNULL_END

