/**
 * \file 
 * Copyright (C) Transmit Security, LTD - All Rights Reserved
 * Unauthorized copying of this file, via any medium is strictly prohibited
 * Proprietary and confidential
 * Generated using tsidlc.
 * 
 * Package com.ts.mobile.sdk
 */

#import <Foundation/Foundation.h>
#import <CoreLocation/CoreLocation.h>



/**
 * Describes the versions of the elements which comprise the Transmit SDK APIs.
 *
 * \ingroup sdkProvided
 */
@interface TSXVersionInfo : NSObject { }

/**
 * The version of the *native* services SDK, e.g. "major.minor.patch.patch2-preRelease (buildNumber)" Where:
 *  - major AND minor are mandatory numeric values
 *  - patch AND patch2 are optional numeric values
 *  - preRelease is an optional string containing alphanumeric characters and hyphens and preceded by a hyphen
 *  - buildNumber is an optional numeric value wrapped with parentheses and possibly preceded by any number of spaces
 *
 * An example for a concrete full-form version string: "5.1.0.0-RC2-SNAPSHOT  (1080)"
 */
@property (readonly) NSString* _Null_unspecified sdkVersion;

/**
 * The name of the native platform, e.g. "android".
 */
@property (readonly) NSString* _Null_unspecified platformName;

/**
 * The "version" of the APIs which this package provides.
 */
@property (readonly) long apiLevel;

/**
 * The version of the *core* services SDK. Has the same structure as described for sdkVersion above.
 */
@property (readonly) NSString* _Null_unspecified tarsusVersion;
@end

/**
 * Final result of a successful authentication request. This object is returned from the SDK following a successful
 * completion of policy evaluation, and contains information about the evaluation as well as an optional authentication
 * token.
 *
 * \ingroup sdkProvided
 */
@interface TSXAuthenticationResult : NSObject { }

/**
 * Authentication token, if one was generated as part of this policy evaluation.
 */
@property (readonly) NSString* _Null_unspecified token;

/**
 * Device ID
 */
@property (readonly) NSString* _Null_unspecified deviceId;

/**
 * Additional data attached by the policy at completion.
 */
@property (readonly) NSDictionary * _Null_unspecified data;
@end

/** \enum TSXAuthenticationErrorCode
*
 * Possible reasons for authentication errors.
 *
 * \ingroup sdkProvided
 */
typedef NS_OPTIONS(NSUInteger, TSXAuthenticationErrorCode) {
   AuthenticationErrorCodeInternal = 1 << 0    /**< General internal SDK error. */,
   AuthenticationErrorCodeInvalidInput = 1 << 1    /**< Invalid input received from authenticator. */,
   AuthenticationErrorCodeAuthenticatorLocked = 1 << 2    /**< Authenticator locked. Typically passed to an authenticator context when it is locked and other authenticators areavailable.*/,
   AuthenticationErrorCodeAllAuthenticatorsLocked = 1 << 3    /**< All authenticators are locked. Typically passed to an authenticator context when it is locked and no other authenticator is available. */,
   AuthenticationErrorCodeNoRegisteredAuthenticator = 1 << 4    /**< No registered authenticator exists, and one is required. */,
   AuthenticationErrorCodeRegisteredSecretAlreadyInHistory = 1 << 5    /**< Attempt to register an authenticator with input that was used in the past. */,
   AuthenticationErrorCodeCommunication = 1 << 6    /**< Error communicating with the server. */,
   AuthenticationErrorCodeUserCanceled = 1 << 7    /**< Request not completed due to user cancellation request. */,
   AuthenticationErrorCodeAppImplementation = 1 << 8    /**< Callback implementation behaved unexpectedly */,
   AuthenticationErrorCodePolicyRejection = 1 << 9    /**< Policy requested to reject the evaluation */,
   AuthenticationErrorCodeAuthenticatorInvalidated = 1 << 10    /**< Authenticator was invalidated from some reason. User is expected to re-register the authenticator. */,
   AuthenticationErrorCodeControlFlowExpired = 1 << 11    /**< Control flow execution session expired our not found. */,
   AuthenticationErrorCodeSessionRequired = 1 << 12    /**< SDK operation requires an active session, and one doesn't exist (or expired) */,
   AuthenticationErrorCodeAuthenticatorError = 1 << 13    /**< The authenticator cannot authenticate the user due to an authenticator-originating error -- as opposed to bad credentials. */,
   AuthenticationErrorCodeApprovalWrongState = 1 << 14    /**< An approval is in the wrong state for performing an operation on it. */,
   AuthenticationErrorCodeTotpNotProvisioned = 1 << 15    /**< TOTP generation session is requested for user when TOTP wasn't provisioned for user. */,
   AuthenticationErrorCodeAuthenticatorExternalConfigError = 1 << 16    /**< The authenticator cannot authenticate the user because of a user-servicable configuration issue outside the scope of the SDK */,
   AuthenticationErrorCodeInvalidDeviceBinding = 1 << 17    /**< The device binding is invalid; typically indicated by the server. Application should attempt to re-bind the device. */,
   AuthenticationErrorCodeInvalidIdToken = 1 << 18    /**< The id token in use is invalid; typically indicated by the server. Application should attempt to re-bind the device using a userId. */,
   AuthenticationErrorCodeDeviceNotFound = 1 << 19    /**< Requested device was not found in the list of users devices. */,
   AuthenticationErrorCodeApprovalDenied = 1 << 20    /**< Approval was denied on mobile app. */,
   AuthenticationErrorCodeApprovalExpired = 1 << 21    /**< Approval has expired. */,
   AuthenticationErrorCodeApplicationGeneratedRecoverableError = 1 << 22    /**< An error generated by the application; the SDK doesn't attribute any semantics to these errors */,
   AuthenticationErrorCodeUserNotFound = 1 << 23    /**< The user handle provided to the operation does not map to any user record in the local state */
} ;
typedef TSXAuthenticationErrorCode TSXAuthenticationErrorCodeSet;

/** \enum TSXAuthenticationErrorProperty
*
 * Keys for retreiving additional information describing the related error codes.
 *
 * \ingroup sdkProvided
 */
typedef NS_OPTIONS(NSUInteger, TSXAuthenticationErrorProperty) {
   AuthenticationErrorPropertyAuthenticatorExternalConfigErrorReason = 1 << 0    /**< A property the value of which describes the reason which caused an {@link AuthenticationErrorCode#AuthenticatorExternalConfigError} report. */,
   AuthenticationErrorPropertyAuthenticatorInvalidInputErrorDescription = 1 << 1    /**< A property the value of which describes the reason which caused an {@link AuthenticationErrorCode#InvalidInput} report. */,
   AuthenticationErrorPropertyInvalidIdTokenErrorReason = 1 << 2    /**< A property the value of which describes the reason which caused an {@link AuthenticationErrorCode#InvalidIdToken} report. */,
   AuthenticationErrorPropertyUserRecordDeleted = 1 << 3    /**< A property that indicates whether the user's record (and device binding) was deleted as a result of the error. This will be present if the SDK is configured for auto recovery from errors that indicate such deletion is required.  */,
   AuthenticationErrorPropertyAuthenticationErrorFailingActionType = 1 << 4    /**< An optional string property which value represents the policy action type during which execution the error occurred. */
} ;
typedef TSXAuthenticationErrorProperty TSXAuthenticationErrorPropertySet;

/** \enum TSXAuthenticationErrorPropertySymbol
*
 * AuthenticationError specific roperty values.
 *
 * \ingroup sdkProvided
 */
typedef NS_OPTIONS(NSUInteger, TSXAuthenticationErrorPropertySymbol) {
   AuthenticationErrorPropertySymbolAuthenticatorExternalConfigErrorReasonBiometricsNotEnrolled = 1 << 0    /**< Property value for {@link AuthenticationErrorProperty#AuthenticatorExternalConfigErrorReason} indicating no fingerprints enrolled on the device */,
   AuthenticationErrorPropertySymbolAuthenticatorExternalConfigErrorReasonBiometricsOsLockTemporary = 1 << 1    /**< Property value for {@link AuthenticationErrorProperty#AuthenticatorExternalConfigErrorReason} indicating fingerprint authentication on the device is temporarily locked due to too many failed attempts. */,
   AuthenticationErrorPropertySymbolAuthenticatorExternalConfigErrorReasonBiometricsOsLockPermanent = 1 << 2    /**< Property value for {@link AuthenticationErrorProperty#AuthenticatorExternalConfigErrorReason} indicating fingerprint authentication on the device is locked until the user uses the psscode to unlock it. */,
   AuthenticationErrorPropertySymbolAuthenticatorInvalidInputErrorDescriptionTotpIncorrectCheckDigit = 1 << 3    /**< Property value for {@link AuthenticationErrorProperty#AuthenticatorInvalidInputErrorDescription} indicating TOTP authentication failed due to incorrect check digit. */,
   AuthenticationErrorPropertySymbolInvalidIdTokenErrorReasonExpiredToken = 1 << 4    /**< Property value for {@link AuthenticationErrorProperty#InvalidIdTokenErrorReason} indicating the id token in use has expired */,
   AuthenticationErrorPropertySymbolInvalidIdTokenErrorReasonBadToken = 1 << 5    /**< Property value for {@link AuthenticationErrorProperty#InvalidIdTokenErrorReason} indicating the id token in use does not match the one expected by the server */
} ;
typedef TSXAuthenticationErrorPropertySymbol TSXAuthenticationErrorPropertySymbolSet;

/** \enum TSXUIAssetsDownloadMode
*
 * UI Assets download mode.
 *
 * \ingroup sdkProvided
 */
typedef NS_OPTIONS(NSUInteger, TSXUIAssetsDownloadMode) {
   UIAssetsDownloadModeDisable = 1 << 0    /**< Disable download assets from the server and use the local assets. */,
   UIAssetsDownloadModeDownloadOnInit = 1 << 1    /**< Download the assets from the server once the SDK has been initialized. */
} ;
typedef TSXUIAssetsDownloadMode TSXUIAssetsDownloadModeSet;

/** \enum TSXInvalidUserRecordRecoveryMode
*
 * Invalid user record error recovery mode.
 *
 * \ingroup sdkProvided
 */
typedef NS_OPTIONS(NSUInteger, TSXInvalidUserRecordRecoveryMode) {
   InvalidUserRecordRecoveryModeDisable = 1 << 0    /**< Disable atomatic recovery of user record errors. It is the application's respobsibility to respond to these errors by clearing the user record as needed. */,
   InvalidUserRecordRecoveryModeRecoverDeviceAndBindingOnAuthenticate = 1 << 1    /**< Delete user record when encountering DeviceNotFound or InvalidDeviceBinding errors during an authentication call. This only affects calls to {@link TransmitSdkXm#authenticate}. */
} ;
typedef TSXInvalidUserRecordRecoveryMode TSXInvalidUserRecordRecoveryModeSet;

/**
 * Provides information on an error ocurring as part of invocation of an SDK API.
 *
 * \ingroup sdkProvided
 */
@interface TSXAuthenticationError : NSObject { }

/**
 * Error code
 */
@property (readonly) TSXAuthenticationErrorCode errorCode;

/**
 * Error message
 */
@property (readonly) NSString* _Null_unspecified message;

/**
 * Additional error-specific data
 */
@property (readonly) NSDictionary * _Null_unspecified data;

/**
 * Create an authentication error object with  code ApplicationGeneratedRecoverableError.
 */
+(TSXAuthenticationError* _Nonnull) createApplicationGeneratedGeneralErrorWithMessage:(NSString* _Nonnull)message data:(NSDictionary * _Nonnull)data;

/**
 * Create an authentication error object with code Communication.
 */
+(TSXAuthenticationError* _Nonnull) createApplicationGeneratedCommunicationErrorWithMessage:(NSString* _Nonnull)message data:(NSDictionary * _Nonnull)data;

/** Retrieves a specific **string** property attached to this error object where relevant (e.g. when {@link errorCode} equals {@link AuthenticationErrorCode#AuthenticatorExternalConfigError}).
 *
 * @param property The key for the property to retrieve.
 *
 * @return The property value matching the requested type or *null* if not present.
 * @throws AuthenticationError in case the property being retrieved is not of string type..
 */
-(NSString* _Null_unspecified)getPublicStringPropertyWithProperty:(TSXAuthenticationErrorProperty)property;

/**
 * Retrieves a specific **number** property attached to this error object where relevant (e.g. when {@link errorCode} equals {@link AuthenticationErrorCode#AuthenticatorExternalConfigError}).
 *
 * @param property The key for the property to retrieve.
 *
 * @return The property value matching the requested type or *null* if not present.
 * @throws AuthenticationError in case the property being retrieved is not of number type.
 */
-(long)getPublicNumberPropertyWithProperty:(TSXAuthenticationErrorProperty)property;

/**
 * Retrieves a specific **boolean** property attached to this error object where relevant (e.g. when {@link errorCode} equals {@link AuthenticationErrorCode#AuthenticatorExternalConfigError}).
 *
 * @param property The key for the property to retrieve.
 *
 * @return The property value matching the requested type or *null* if not present.
 * @throws AuthenticationError in case the property being retrieved is not of boolean type.
 */
-(BOOL)getPublicBooleanPropertyWithProperty:(TSXAuthenticationErrorProperty)property;

/**
 * Retrieves a specific **{@link AuthenticationErrorPropertySymbol}** property attached to this error object where relevant (e.g. when {@link errorCode} equals {@link AuthenticationErrorCode#AuthenticatorExternalConfigError}).
 *
 * @param property The key for the property to retrieve.
 *
 * @return The property value matching the requested type or *null* if not present.
 * @throws AuthenticationError in case the property being retrieved is not of type AuthenticationErrorPropertySymbol.
 */
-(TSXAuthenticationErrorPropertySymbol)getPublicSymbolicPropertyWithProperty:(TSXAuthenticationErrorProperty)property;
@end

@interface TSXTSColor : NSObject { }

/**
 * hex representation of the color in the following available formats.
 * #AARRGGBB , #ARGB, #RGB, #RRGGBB
 */
@property (readonly) NSString* _Null_unspecified hexValue;
@end

@interface TSXUIStyle : NSObject { }

/**
 * Background color of element
 */
@property (readonly) TSXTSColor* _Nullable backgroundColor;

/**
 * Tint color of element
 */
@property (readonly) TSXTSColor* _Nullable tintColor;

/**
 * Line color of element
 */
@property (readonly) TSXTSColor* _Nullable lineColor;

/**
 * Icon color of element
 */
@property (readonly) TSXTSColor* _Nullable iconColor;

/**
 * Image URL of element
 */
@property (readonly) NSString* _Nullable imageUrl;

/**
 * Font name for element
 */
@property (readonly) NSString* _Nullable fontName;

/**
 * Font size for element
 */
@property (readonly) long fontSize;

/**
 * Should font be bold?
 */
@property (readonly) BOOL fontBold;

/**
 * Should input be masked?
 */
@property (readonly) BOOL maskInput;
@end

@interface TSXUIContext : NSObject { }

/**
 * API to get the localized string by the key from the server strings table, if the string doesn't exist
 * it will search for the string in the local localization strings table else will return the key.
 *
 * @param key a string to retrive the localized string from strings table.
 *
 * @return a localized string
 */
-(NSString* _Null_unspecified)getStringWithKey:(NSString* _Nonnull)key;

/**
 * API to get a localized string by the key from the server strings table with the ability to define arguments for interpolation,
 * if the string doesn't exist, it will search for the string in the local localization strings table else will return the key.
 * if the interpolation args are less, it will return the partial result with the interpolation tags for missing args.
 * if the interpolation args are more, it will ignore the additional tags.
 *
 * @param key a string to retrieve the localized string from strings table.
 * @param args a list of strings for interpolation.
 *
 * @return a localized string after interpolation.
 */
-(NSString* _Null_unspecified)formatStringWithKey:(NSString* _Nonnull)key args:(NSArray<NSString*> * _Nullable)args;

/**
 * API to get UI style
 *
 * @param tags list of
 *
 * @return the style object matching the tags or null
 */
-(TSXUIStyle* _Null_unspecified)getStyleWithTags:(NSArray<NSString*> * _Nonnull)tags;
@end

/** \enum TSXActionEscapeOptionPresentation
*
 * A hint to the UI layer regarding how an escape option should be rendered
 * on screen.
 */
typedef NS_OPTIONS(NSUInteger, TSXActionEscapeOptionPresentation) {
   ActionEscapeOptionPresentationHide = 1 << 0    /**< Do not render this escape option */,
   ActionEscapeOptionPresentationAction = 1 << 1    /**< This escape option is an auxiliary action that the user should be offered a chance to invoke */,
   ActionEscapeOptionPresentationCancel = 1 << 2    /**< This escape option should be invoked when the user clicks on a button that suggests cancellation of the action */,
   ActionEscapeOptionPresentationCustom = 1 << 3    /**< Reserved for custom Transmit Security Implementations */
} ;
typedef TSXActionEscapeOptionPresentation TSXActionEscapeOptionPresentationSet;

/**
 * Represents a UI escpae option defined for an action. UI escape options allow user-actions
 * to abort their intended operation and signal to the Transmit Server that journey execution
 * should resume in an alternate path. Journeys may attach escape options to actions, and these escape
 * options define alternate execution paths.
 * UI handlers receive information on the escape options attached to an action via instances of this
 * interface. They also identify escape options to invoke by providing back these instances to
 * relevant SDK API calls.
 * UI handlers may choose to render UI to allow the user to invoke escape options, or otherwise decide
 * to invoke them.
 */
@interface TSXActionEscapeOption : NSObject { }

/**
 * An ID assigned to the escape option.
 */
@property (readonly) NSString* _Null_unspecified id;

/**
 * A value hinting the UI layer how the escape option should be presented to the user.
 */
@property (readonly) TSXActionEscapeOptionPresentation presentation;

/**
 * A string label decribing the escape option to the user. How this value is rendered in the UI,
 * if at all, is up to the UI layer implementation which should also take into account the #presentation
 * attribute of the escape option.
 */
@property (readonly) NSString* _Nullable displayName;
@end

/**
 * Represents a request from the UI layer to the SDK to invoke an escape option. Objects of these types
 * are passed in return from various UI sessions to signal to the SDK that an escape option should be
 * invoked. They identify the escape option to invoke as well as additional optional parameters to pass to it.
 */
@interface TSXActionEscapeRequest : NSObject { }

/**
 * The object identifying the escape option to invoke.
 */
@property () TSXActionEscapeOption* _Null_unspecified escapeOption;

/**
 * An additional JSON object to include with the escape option invocation request.
 * This data will be made available to the journey when the escape option is invoked.
 */
@property () NSDictionary * _Nullable escapeParameters;
@end

/**
 * Provides information on the currently executed action in a policy. This class is provided by the SDK to the client
 * on callback invocations to allow the client to access information about the action during its execution.
 *
 * \ingroup sdkProvided
 */
@interface TSXPolicyAction : NSObject { }

/**
 * Used to distinguish between a journey-originated action and an action that was initiated on the client.
 * If this property is true – then the action did not originate from the server for example, for authentication as part of local TOTP generation.
 * Otherwise this will be false.
 */
@property (readonly) BOOL isPseudoAction;

/**
 * Type of this action.
 */
@property (readonly) NSString* _Null_unspecified actionType;

/**
 * Action alternative label
 */
@property (readonly) NSString* _Null_unspecified altLabel;

/**
 * UIContext contains ui utils.
 */
@property (readonly) TSXUIContext* _Null_unspecified uiContext;

/**
 * Available escape options from action. Depending on the executing action,
 * one of these options can be provided to abort action completion and
 * take a different path in the control flow.
 */
@property (readonly) NSArray<TSXActionEscapeOption*> * _Null_unspecified escapeOptions;

/**
 * Find an escape option based on ID sent from the server.
 */
-(TSXActionEscapeOption* _Null_unspecified)escapeOptionByIdWithEscapeOptionName:(NSString* _Nonnull)escapeOptionName;
@end

/** \enum TSXControlRequestType
*
 * Type of authentication UI session control request. Defines how the authentication flow should be changed in response
 * to the control request from an authentication UI session.
 *
 * \ingroup sdkProvided
 */
typedef NS_OPTIONS(NSUInteger, TSXControlRequestType) {
   ControlRequestTypeCancelAuthenticator = 1 << 0    /**< Cancel the authenticator. This will trigger invoking the UIHandler#controlOptionForCancellationRequestInSession callback to obtain an alternative control request */,
   ControlRequestTypeRetryAuthenticator = 1 << 1    /**< Retry authenticating using the current authenticator. */,
   ControlRequestTypeChangeMethod = 1 << 2    /**< Allow the user to change the authentication method (not the current one) */,
   ControlRequestTypeSelectMethod = 1 << 3    /**< Allow the user to select an authentication method (the current one or another one) */,
   ControlRequestTypeAbortAuthentication = 1 << 4    /**< Abort the authentication process altogether, returning an error from the SDK invocation */
} ;
typedef TSXControlRequestType TSXControlRequestTypeSet;

/**
 * Represents a control request from a UI authenticator session, asking to change or terminate the authentication
 * flow.
 *
 * \ingroup sdkProvided
 */
@interface TSXControlRequest : NSObject { }

/**
 * Type of contorl request.
 */
@property () TSXControlRequestType requestType;

/**
 * Create a control request with the specified request type.
 *
 * @param requestType Type of control request to create.
 */
+(TSXControlRequest* _Nonnull) createWithRequestType:(TSXControlRequestType)requestType;
@end

/**
 * Supertype for all authenticator input resposne types.
 */
@interface TSXInputResponseType : NSObject { }
@end

/**
 * Communicates either an input response, a control response or an escape request from a UI
 * session (e.g an authenticator UI session or a QR scan UI session) to the SDK.
 * This is a container that can contain either an InputResponseType object, an ActionEscapeOption object,
 * **or** a ControlRequest object.
 *
 * \ingroup sdkProvided
 */
@interface TSXInputOrControlResponse<ResponseType> : NSObject { }

/**
 * Is this a control request?
 *
 * @return true if this object contains a control request (obtained through the controlRequest property), false if it contains an input response (obtained through the response property)
 */
-(BOOL)isControlRequest;

/**
 * The input response, if this object represents an input response.
 */
@property () ResponseType _Null_unspecified response;

/**
 * The control request, if this object represents a control request.
 */
@property () TSXControlRequest* _Null_unspecified controlRequest;

/**
 * An escape option, if this object represents an escape request.
 */
@property () TSXActionEscapeRequest* _Null_unspecified actionEscapeRequest;

/**
 * Create an InputOrControlResponse object representing a control request.
 *
 * @param controlRequest the ControlRequest to represent in the created object.
 */
+(TSXInputOrControlResponse* _Nonnull) createControlResponseWithControlRequest:(TSXControlRequest* _Nonnull)controlRequest;

/**
 * Create an InputOrControlResponse object representing an escape request --
 * branching through an escape not in the action.
 *
 * @param escapeOption the ActionEscapeOption to represent in the created object.
 * @param escapeParameters Parameters to pass to the journey when taking the escape branch.
 */
+(TSXInputOrControlResponse* _Nonnull) createEscapeResponseWithEscapeOption:(TSXActionEscapeOption* _Nonnull)escapeOption escapeParameters:(NSDictionary * _Nullable)escapeParameters;

/**
 * Create an InputOrControlResponse object representing an authenticator input response.
 *
 * @param inputResponse the input response to represent in the created object.
 */
+(TSXInputOrControlResponse* _Nonnull) createInputResponseWithInputResponse:(ResponseType _Nonnull)inputResponse;
@end

/** \enum TSXAuthenticationErrorRecovery
*
 * Type of error recovery actions available to authentication sessions.
 *
 * \ingroup sdkProvided
 */
typedef NS_OPTIONS(NSUInteger, TSXAuthenticationErrorRecovery) {
   AuthenticationErrorRecoveryRetryAuthenticator = 1 << 0    /**< Retry authentication using the current authenticator (and within the current session). */,
   AuthenticationErrorRecoveryChangeAuthenticator = 1 << 1    /**< End the UI session and switch to a different authenticator. This is only valid if there is an authenticator available other than the present one.*/,
   AuthenticationErrorRecoverySelectAuthenticator = 1 << 2    /**< End the UI session and go to the auhtneticator selection menu. */,
   AuthenticationErrorRecoveryFail = 1 << 3    /**< Abort policy execution and fail the authentication process. */
} ;
typedef TSXAuthenticationErrorRecovery TSXAuthenticationErrorRecoverySet;

/** \enum TSXAuthenticatorSessionMode
*
 * Authenticator UI session modes.
 *
 * \ingroup sdkProvided
 */
typedef NS_OPTIONS(NSUInteger, TSXAuthenticatorSessionMode) {
   AuthenticatorSessionModeAuthentication = 1 << 0    /**< Session used for authenticating using an authenticator */,
   AuthenticatorSessionModeRegistration = 1 << 1    /**< Session used for enrolling / registering an authenticator. */
} ;
typedef TSXAuthenticatorSessionMode TSXAuthenticatorSessionModeSet;

/** \enum TSXAuthenticatorType
*
 * Authenticator types / modalities.
 *
 * \ingroup sdkProvided
 */
typedef NS_OPTIONS(NSUInteger, TSXAuthenticatorType) {
   AuthenticatorTypePassword = 1 << 0,
   AuthenticatorTypeFingerprint = 1 << 1,
   AuthenticatorTypePincode = 1 << 2,
   AuthenticatorTypePattern = 1 << 3,
   AuthenticatorTypeOtp = 1 << 4,
   AuthenticatorTypeFace = 1 << 5,
   AuthenticatorTypeVoice = 1 << 6,
   AuthenticatorTypeEye = 1 << 7,
   AuthenticatorTypeEmoji = 1 << 8,
   AuthenticatorTypeQuestions = 1 << 9,
   AuthenticatorTypeFaceID = 1 << 10,
   AuthenticatorTypeGeneric = 1 << 11,
   AuthenticatorTypeMobileApprove = 1 << 12,
   AuthenticatorTypeTotp = 1 << 13,
   AuthenticatorTypeDeviceBiometrics = 1 << 14
} ;
typedef TSXAuthenticatorType TSXAuthenticatorTypeSet;

/** \enum TSXAuthenticatorRegistrationStatus
*
 * Authenticator registration status
 *
 * \ingroup sdkProvided
 */
typedef NS_OPTIONS(NSUInteger, TSXAuthenticatorRegistrationStatus) {
   AuthenticatorRegistrationStatusRegistered = 1 << 0    /**< Authenticator is registered for this device (or centrally) */,
   AuthenticatorRegistrationStatusUnregistered = 1 << 1    /**< Authenticator is not registered for this device (or centrally) due to registration not occurring or unregistration ocurring */,
   AuthenticatorRegistrationStatusLocallyInvalid = 1 << 2    /**< Authenticator is not registered for this device (or centrally) due to invalidation of registration on device */
} ;
typedef TSXAuthenticatorRegistrationStatus TSXAuthenticatorRegistrationStatusSet;

/**
 * Describes an authenticator. This includes general description
 * of the authenticator and its status.
 *
 * \ingroup sdkProvided
 */
@interface TSXAuthenticatorDescription : NSObject { }

/**
 * Programmatic ID of the authenticator.
 */
@property (readonly) NSString* _Null_unspecified authenticatorId;

/**
 * Authenticator type.
 */
@property (readonly) TSXAuthenticatorType type;

/**
 * Readable name of this authenticator.
 */
@property (readonly) NSString* _Null_unspecified name;

/**
 * true if the authenticator is expired (and will thus typically require registration after authentication).
 */
@property (readonly) BOOL expired;

/**
 * true if the authenticator is registered for the current user and app (registrationStatus == Registered)
 */
@property (readonly) BOOL registered;

/**
 * Registration state of authenticator.
 */
@property (readonly) TSXAuthenticatorRegistrationStatus registrationStatus;

/**
 * true if the authenticator is locked.
 */
@property (readonly) BOOL locked;

/**
 * true if this authenticator is designated as the "default authenticator" for the user (the last used authenticator).
 */
@property (readonly) BOOL defaultAuthenticator;

/**
 * true if the authenticator can be supported on the present device.
 */
@property (readonly) BOOL supportedOnDevice;

/**
 * true if the authenticator can be used during this authentication action and on the current device -- taking into
 * account factors such as locking, registration  and device support
 */
@property (readonly) BOOL enabled;

/**
 * If exists, the UI can present a credential recovery link that will branch to specific journey branch on the server.
 * If user expresses intent, the UI can invoke this escape option.
 */
@property (readonly) TSXActionEscapeOption* _Nullable credentialRecoveryEscapeOption;
@end

/**
 * A base value-type, representing a parameter setting for an authentication action. Concnrete parameter settings
 * are derived from this object. An authetnication action can be subject to multiple such parameters.
 * The permitted parameters and their semantics is dependent upon the authentication method.
 */
@interface TSXAuthenticationActionParameter : NSObject { }
@end

/**
 * A single entry in an authentication action menu. The entry comprises of an authenticator type
 * and a set of possible / suggested parameters for use with that authenticator type.
 */
@interface TSXAuthenticationOption : NSObject { }

/**
 * Authenticator type represented by this authentication option.
 */
@property (readonly) TSXAuthenticatorDescription* _Null_unspecified authenticator;

/**
 * Suggested parameters for this authentication option. Note that it's possible that
 * the authenticator supports parameters additional to the ones specified in this list;
 * this is just a recommendation.
 * Specific authenticators may define the exact set of parameters that's included in this list.
 */
@property (readonly) NSArray<TSXAuthenticationActionParameter*> * _Null_unspecified suggestedParameters;
@end

/**
 * An interface for managing an authenticator UI session. When the SDK needs to invoke an authenticator, it does that
 * in the context of an authenticator UI session. An authenticator UI session is started once an authenticator is
 * selected, and ends when authentication using the authenticator completes, or is aborted (e.g due to the user
 * choosing a different authenticator or cancelling an authentication action altogether).
 *
 * An authenticator session can be in one of two modes (represented by AuthenticatorSessionMode) -- authentication
 * (Authentication) or registration (Registration). The mode is set on session start, but may change during the
 * session. For example, when authenticating with an expired authenticator, the session mode will change from
 * authentication to registration rather than starting a separate UI session for the registration action. This allows
 * the client to distinguish between registration done in the same context as the (expired) authentication vs.
 * a standalone registration session.
 *
 * A session class is associated with a response type -- the type of session response input. This is the type used
 * to relay input from the authenticator session to the SDK. Authenticator UI sessions for different authenticator
 * types would use different response types.
 *
 * The session lifecycle always begins with a call to startSession, done by the SDK shortly after the session object
 * is created through one of the createXXXXAuthSession methods in UIHandler. With startSession the session receives
 * the initial session mode and the clientContext for the SDK operation invocation within which the session is created.
 *
 * After the call to startSession, the SDK will call promiseInput() -- asking the UI session to collect and provide
 * input from the user. For some authenticators, the input may be one of several classes with a common base class;
 * for others the input may be a concrete class. For example, for the password authenticator, the input would be
 * the password input by the user. In addition to authenticator input, promiseInput may also return a control
 * request -- affecting the processing of the authentication action. A control request may, for example, signal that
 * the authentication process should be aborted or that the user should be offered to change an authenticator. For a
 * list of possible control requests see the ControlRequestType enum.
 *
 * Once inputPromise returns an input the SDK processes it. It then may report an error in processing -- by
 * invoking promiseRecoveryForError. If there's no error, the SDK may invoke promiseInput again to ask for additional
 * input. If the authenticator is expired, and the SDK now needs to register a new secret for it,
 * it would invoke changeSessionModeToRegistrationAfterExpiration.
 *
 * When the SDK can complete the authentication flow based on the input received from  promiseInput, or
 * when the SDK needs to otherwise end the session due to a control request or an error condition, it will invoke
 * endSession to signal that the authentication session has ended.
 *
 * \ingroup clientProvided
 */
@interface TSXUIAuthenticatorSession<ResponseType> : NSObject { }

/**
 * Called to start the authenticator UI session. This is the first function invoke on the session by the SDK.
 * Its purpose is to setup the UI and associate it with the clientContext of the current running authentication
 * action.
 *
 * Implementations should prepare the UI for interaction with the authenticator -- typically (but not necessarily)
 * presenting new UI elements on screen, recording the clientContext and setting the UI to the session mode provided.
 *
 * @param description Decription of the authenticator and settings for this session.
 * @param mode The initial mode for this session (authenticate / register)
 * @param actionContext Information on the policy action currently executing, within which this callback is invoked. This is optional since session may be invoked outside the scope of an action.
 * @param clientContext The clientContext for the SDK operation invocation for which this callback is invoked.
 */
-(void)startSessionWithDescription:(TSXAuthenticatorDescription* _Nonnull)description mode:(TSXAuthenticatorSessionMode)mode actionContext:(TSXPolicyAction* _Nullable)actionContext clientContext:(NSDictionary * _Nullable)clientContext;

/**
 * Change the session mode to registration due to an expired authenticator. This method is invoked by the SDK when
 * during a session it needs to switch from authentication to registration of the authenticator -- due to
 * an expired authenticator is being used for authentication (after successful authentication the SDK will invoke
 * this method to switch to registration mode for the authenticator).
 *
 * Implementations should make the user aware that they are now registering a new secret for the authenticator,
 * possible showing an alert or other visual cue, and then setup the UI accordingly to support registration. The
 * implementation should make it known to the user that this is done due to an expired authenticator.
 *
 */
-(void)changeSessionModeToRegistrationAfterExpiration;

/**
 * Notify the session that an error has occurred processing input. This function is invoked by the SDK if it
 * encounters an error processing the input provided to it on return from promiseInput. The SDK provides the
 * encountered error, and the session should asynchronously return a recovery action instructing the SDK
 * how to respond to this error.
 *
 * See AuthenticationErrorRecovery for a list of recovery options.
 *
 * Implementations should examine the error and based on its nature decide how to communicate it to the user and
 * what recovery action to return to the SDK. For example, for an error indicating that credential input is wrong
 * (e.g wrong password), an implementation may display a prompt to the user that notifies them about the wrong
 * password and requests them to retry, and return a RetryAuthenticator recovery action. On the other hand, if the
 * error is a locked authenticator, the notification to the user may be a more intrusive alert and the recovery
 * action may be taking the user back to the authentication selection method (ChangeAuthenticator).
 *
 * The implementation may consult the defaultRecovery parameter to see what is the default recovery mode suggested
 * by the SDK.
 *
 * @param error Reported authentication error.
 * @param validRecoveries Allowed recovery responses, based on authentication session mode and context.
 * @param defaultRecovery Default recovery suggested by the SDK.
 * @param handler Handler to receive asynchronous results. First argument -- return: AuthenticationErrorRecovery value describing which recovery action should be taken.
 *
 */
-(void)promiseRecoveryForErrorWithError:(TSXAuthenticationError* _Nonnull)error validRecoveries:(TSXAuthenticationErrorRecoverySet)validRecoveries defaultRecovery:(TSXAuthenticationErrorRecovery)defaultRecovery asynchronouslyWithHandler:(void (^ _Nonnull)(TSXAuthenticationErrorRecovery))handler;

/**
 * Collect input from the session. This function is invoked by the SDK when it wishes to collect input from the
 * authenticator UI. This will first be invoked right after startSession, and may then be invoked after subsequent
 * errors that were handled using Retry, when there's a need to register an expired authenticator after
 * registration, and for some authenticators -- when there's additional input needed to complete authentication even
 * after some input was provided (possibly after updating the session with data about the additional required
 * input).
 *
 * In addition to responding with input relevant to the authenticator (such as a PasswordInput for a
 * password authenticator), this method may asynchronously return a control request -- instructing the SDK to abort
 * or otherwise alter the authentication process. See ControlRequestType for a list of available request types.
 *
 * To accomodate both return options -- one for the authenticator input and one for control request -- the
 * declared return type of promiseInput() is InputOrControlResponse; see the documentation for that class for more
 * information on how it accomodates both types of return values.
 *
 * Implementations should asynchronously return input from this function as it becomes available. For example, a
 * password input session may drive a UI with a password input field and a submit button. Such an implementation
 * would then return the input password once the submit button is activated.
 *
 * @param handler Handler to receive asynchronous results. First argument -- return: InputOrControlResponse encoding either an authenticator input or a contorl request.
 */
-(void)promiseInputAsynchronouslyWithHandler:(void (^ _Nonnull)(TSXInputOrControlResponse<ResponseType>* _Nonnull))handler;

/**
 * End the authentication session.
 *
 * Implementations should update the UI to reflect the fact that the current authentication session is no longer
 * active; e.g by tearing down UI elements that were setup to collect input for this session.
 */
-(void)endSession;
@end

/** \enum TSXAuthenticatorFallbackAction
*
 * Possible responses to authenticator fallback suggestion by the SDK.
 *
 * \ingroup sdkProvided
 */
typedef NS_OPTIONS(NSUInteger, TSXAuthenticatorFallbackAction) {
   AuthenticatorFallbackActionFallback = 1 << 0    /**< Change authentication method to a fallback authenticator as configured in the policy. */,
   AuthenticatorFallbackActionAuthMenu = 1 << 1    /**< Invoke the authentication method menu. */,
   AuthenticatorFallbackActionRetry = 1 << 2    /**< Do not perform fallback; continue retrying the current authenticator. */,
   AuthenticatorFallbackActionCancel = 1 << 3    /**< Abort the authentication flow. */
} ;
typedef TSXAuthenticatorFallbackAction TSXAuthenticatorFallbackActionSet;

/** \enum TSXAuthenticatorSelectionResultType
*
 * Denotes the type of an AuthenticatorSelectionResult object.
 *
 * \ingroup sdkProvided
 */
typedef NS_OPTIONS(NSUInteger, TSXAuthenticatorSelectionResultType) {
   AuthenticatorSelectionResultTypeSelectAuthenticator = 1 << 0    /**< Authentication selection response denotes a request to select an authenticator */,
   AuthenticatorSelectionResultTypeAbort = 1 << 1    /**< Authentication selection response denotes a request to abort authentication*/,
   AuthenticatorSelectionResultTypeEscape = 1 << 2    /**< Authentication selection response denotes a request to escape the authentication action*/
} ;
typedef TSXAuthenticatorSelectionResultType TSXAuthenticatorSelectionResultTypeSet;

/**
 * The result of an authenticator selection request made by the SDK e.g UIHandler#selectAuthenticator. This can either
 * encode a selected authenticator, or a request to cancel the authentication.
 *
 * \ingroup sdkProvided
 */
@interface TSXAuthenticatorSelectionResult : NSObject { }

/**
 * General category of this selection result -- e.g abort vs. select an authenticator.
 */
@property () TSXAuthenticatorSelectionResultType resultType;

/**
 * Selected authenticator if resultType == AuthenticatorSelectionResultType#SelectAuthenticator
 */
@property () TSXAuthenticatorDescription* _Null_unspecified selectedAuthenticator;

/**
 * Selected authentication parameters if resultType == AuthenticatorSelectionResultType#SelectAuthenticator
 */
@property () NSArray<TSXAuthenticationActionParameter*> * _Null_unspecified selectedAuthenticationParameters;

/**
 * Selected escape option and paramaters
 */
@property () TSXActionEscapeRequest* _Null_unspecified actionEscapeRequest;

/**
 * Create an AuthenticatorSelectionResult that encodes an abort request (resultType =
 * AuthenticatorSelectionResultType#Abort)
 */
+(TSXAuthenticatorSelectionResult* _Nonnull) createAbortRequest;

/**
 * Create an AuthenticatorSelectionResult that encodes a request to escape the action
 *
 * @param actionEscape The escape option to signal
 * @param escapeParams Additional parameters to pass to the journey when escaping.
 */
+(TSXAuthenticatorSelectionResult* _Nonnull) createEscapeRequestWithActionEscape:(TSXActionEscapeOption* _Nonnull)actionEscape escapeParams:(NSDictionary * _Nullable)escapeParams;

/**
 * Create an AuthenticatorSelectionResult that encodes an authenticator selection request (resultType =
 * AuthenticatorSelectionResultType#SelectAuthenticator, with the provided selected authenticator.)
 *
 * @param selectedAuthenticator The authenticator to be selected.
 *
 */
+(TSXAuthenticatorSelectionResult* _Nonnull) createSelectionRequestWithSelectedAuthenticator:(TSXAuthenticatorDescription* _Nonnull)selectedAuthenticator;

/**
 * Create an AuthenticatorSelectionResult that encodes an authenticator selection request (resultType =
 * AuthenticatorSelectionResultType#SelectAuthenticator, with the provided selected authenticator.)
 *
 * @param selectedAuthenticator The authenticator to be selected.
 * @param parameters Authentication parameters to use for the authenticator
 *
 */
+(TSXAuthenticatorSelectionResult* _Nonnull) createParameterizedSelectionRequestWithSelectedAuthenticator:(TSXAuthenticatorDescription* _Nonnull)selectedAuthenticator parameters:(NSArray<TSXAuthenticationActionParameter*> * _Nonnull)parameters;
@end

/**
 * Superclass for interface describing a single input step in a multi-step input authentication session; this
 * is passed to UIMultiInputAuthenticationSession#setInputStep to describe the current input step and may include
 * e.g a hint or instructions on the input to provide.
 *
 * \ingroup sdkProvided
 */
@interface TSXMultiInputStepDescription : NSObject { }

/**
 * Tag for the current step.
 * This is an identification or name for the current step, allowing the application to distinguish between steps.
 */
-(NSString* _Null_unspecified)getStepTag;
@end

/**
 * An interface for managing an authenticator UI session where multiple inputs are required during a successful session.
 * This is an exception of the UIAuthenticatorSession interface, with support multiple iterations of input.
 *
 * The session lifecycle for sessions implementing this interface is similar to the lifecycle for 'regular',
 * UIAuthenticatorSession-based sessions, with the exception that prior to each invoccation of promiseInput(), a call
 * to setInputStep is made to report to the session the information about the currently required input.
 *
 * For error recovery calls, a request for recovery via retry (AuthenticationErrorRecvoery#RetryAuthetnicator) will
 * in fact resume from the same step where an error has occurred and not restart the recovery.
 *
 * \ingroup clientProvided
 */
@interface TSXUIMultiInputAuthenticationSession<aResponseType,StepType> : TSXUIAuthenticatorSession<aResponseType> { }

/**
 * Set the current input step. This is called before invocations of promiseInput to provide information about
 * the current input step.
 *
 * @param stepNumber The current, 0-based step number. This is incremented to reflect progress in the session.
 * @param maxStepNumber The number of steps in the session, if known in advance. If this is not known this is -1.
 * @param stepDescription An object describing the step, and possibly the input required for this step.
 */
-(void)setInputStepWithStepNumber:(long)stepNumber maxStepNumber:(long)maxStepNumber stepDescription:(StepType _Nonnull)stepDescription;
@end

/**
 * A password authenticator input response carrying an input password. This is an object returned from the authenticator UI
 * session for a password authenticator (UIAutneticatorSession) in response to a promiseInput call. When this object is returned,
 * the SDK will verify the password value it carries with the Transmit Server.
 *
 * \ingroup sdkProvided
 */
@interface TSXPasswordInput : TSXInputResponseType { }

/**
 * Password submitted by the UI to the authenticator.
 */
@property () NSString* _Null_unspecified password;

/**
 * Create a PasswordInput object with the specified password submission.
 *
 * @param password Initial value of the password attribute.
 */
+(TSXPasswordInput* _Nonnull) createWithPassword:(NSString* _Nonnull)password;
@end

/**
 * A set of services for conducting a TOTP code generation session. An implementation of this object is passed to the
 * application to allow it to start and stop the TOTP code generation process.
 *
 * After successful start, the TOTP codes passed to application may change; this will be done via a call to {@link UITotpGenerationSession#setTotpCode}.
 *
 * \ingroup sdkProvided
 */
@interface TSXTotpGenerationSessionServices : NSObject { }

/**
 * UIContext contains ui utils.
 */
@property (readonly) TSXUIContext* _Null_unspecified uiContext;

/**
 * When the application wishes to start displaying TOTP generated codes, it should invoke this method. This will construct a UITotpGenerationSession object
 * and make a series of invocation on that session. First, {@link UITotpGenerationSession#startSession} will be called. Soon after that, if the TOTP session
 * was constructed with a challengeBased flag enabled then {@link UITotpGenerationSession#promiseChallengeInput} will be invoked to acquire the challenge.
 * After this, the SDK will periodically invoke {@link UITotpGenerationSession#setTotpCode} with a generated TOTP code.
 */
-(void)startCodeGeneration;

/**
 * When the application wishes to end the generation of TOTP codes (e.g. the user closes the TOTP code display UI), it should invoke
 * this method. The SDK will invoke {@link UITotpGenerationSession#endSession} shortly after.
 */
-(void)finishSession;
@end

/**
 * A TOTP generator challenge input response carrying an input challenge. This is an object returned from the authenticator UI
 * session for a TOTP generation session (UITotpGenerationSession) in response to a promiseChallengeInput call. When this object is returned,
 * the SDK will use it for the generation of TOTP codes.
 *
 * \ingroup sdkProvided
 */
@interface TSXTotpChallengeInput : TSXInputResponseType { }

/**
 * TOTP challenge submitted by the UI to the generation session.
 */
@property () NSString* _Null_unspecified challenge;

/**
 * Create a TotpChallengeInput object with the specified challenge submission.
 *
 * @param challenge Initial value of the challenge attribute.
 */
+(TSXTotpChallengeInput* _Nonnull) createWithChallenge:(NSString* _Nonnull)challenge;
@end

/**
 * An interface for managing a TOTP code generation UI session. When the SDK is required to ganerate TOTP codes in order to be used by the user
 * for TOTP authentication on another device or web page, it creates a TOTP code generation UI session, after the user has successfully authenticated using the
 * authenticator which was provisioned for TOTP code generation (on a previous authentication policy action, using the application-provided UIHandler. The
 * application then constructs an object implementing this interface, and the SDK invokes callbacks on this session
 * interface to manage the session lifecycle and interact with the application through the course of the TOTP code generation
 * session.
 *
 * Typically the TOTP code generation session ends when the application asks to end it. Regardless of whether the
 * application or the SDK terminate the TOTP code generation session, its endSession method is invoked.
 *
 * The session lifecycle always begins with a call to startSession, done by the SDK shortly after the session object
 * is created. With startSession the session receives the clientContext for the SDK operation invocation within
 * which the session is created. Also, the SDK passes a {@link TotpGenerationSessionServices} object to this session, which the
 * application can use to start the TOTP code generation process and in order to end the session.
 *
 * A TOTP code generation session consists of generating numerical codes according to parameters specified on the server side (such as
 * code length and ttl) and possibly a server generated challenge. If the method was configured to present a challenge, it will be
 * displayed on the authenticating device and this session is expected to acquire it on invocation of the
 * {@link UITotpGenerationSession#promiseChallengeInput()}. Post challenge acquisition or if method was not configured to
 * include a challenge the session services object will begin generating TOTP codes periodically. These codes are updated during the
 * session lifetime. When this happens, {@link #setTotpCode} is invoked by the SDK. Since each generated code is constrained by a TTL
 * specification, {@link #setTotpCode} is also invoked periodically, to update the application with the remaining time the current TOTP
 * code will be valid and until a new code will be generated. This happens after the application invokes the
 * {@link TotpGenerationSessionServices#startCodeGeneration}.
 *
 * When the application decides the TOTP code generation session is complete (e.g the user asked to close the TOTP code display UI), it
 * invokes the {@link TotpGenerationSessionServices#finishSession} callback. When either the SDK or the application decide
 * to finish the session, the SDK will invoke {@link UITotpGenerationSession#endSession()}.
 *
 * \ingroup clientProvided
 */
@interface TSXUITotpGenerationSession : NSObject { }

/**
 * Called to start the TOTP code generation session. This is invoked by the SDK shortly after the session is created.
 *
 * The implementation is expected to setup the UI and associate it with the clientContext, as well as keep a reference to the
 * totpGenerationSessionServices object to invoke it to perform operations related to the session.
 *
 * @param totpGenerationSessionServices An interface provided to the application for performing actions operations related to the session.
 * @param actionContext Information on the policy action currently executing, within which this callback is invoked. This is optional since session may be invoked outside the scope of an action.
 * @param clientContext The clientContext for the SDK operation invocation for which this callback is invoked.
 */
-(void)startSessionWithTotpGenerationSessionServices:(TSXTotpGenerationSessionServices* _Nonnull)totpGenerationSessionServices actionContext:(TSXPolicyAction* _Nullable)actionContext clientContext:(NSDictionary * _Nullable)clientContext;

/**
 * Collect challenge input from the session. This function is invoked by the SDK when it wishes to collect challenge input
 * from the generation UI. If the TOTP session was constructed with a challengeBased flag enabled, then this will be invoked soon
 * after startSession, and may then be invoked after subsequent requests to Retry.
 *
 * In addition to responding with a challenge input relevant to the generation, this method may asynchronously return a
 * control request -- instructing the SDK to abort or otherwise alter the generation process.
 * See ControlRequestType for a list of available request types.
 *
 * To accomodate both return options -- one for the challenge input and one for control request -- the
 * declared return type of promiseChallengeInput() is InputOrControlResponse; see the documentation for that class for more
 * information on how it accomodates both types of return values.
 *
 * Implementations should asynchronously return challenge input from this function as it becomes available. For example, a
 * numeric challenge input session may drive a UI with a numeric challenge input field and a submit button. Such an implementation
 * would then return the numeric challenge input once the submit button is activated.
 *
 * @param handler Handler to receive asynchronous results. First argument -- return: InputOrControlResponse encoding either a challenge input or a contorl request.
 */
-(void)promiseChallengeInputAsynchronouslyWithHandler:(void (^ _Nonnull)(TSXInputOrControlResponse<TSXTotpChallengeInput*>* _Nonnull))handler;

/**
 * End the TOTP code generation session.
 *
 * Implementations should update the UI to reflect the fact that the current TOTP code generation session is no longer
 * active; e.g by tearing down UI elements that were setup to display output for this session.
 */
-(void)endSession;

/**
 * Invoked by the SDK when ever the TOTP code changes (according to the generation algorithm and prameters which were specified by the server
 * on provisioning). Also by the SDK periodically (usually every second) to indicate the remaining time interval until 'ttl' elapses and 'code' changes,
 * reflected by the 'remainingSeconds' argument.
 *
 * @param code The current generated TOTP code.
 * @param ttlSeconds The time interval in seconds in which this code is valid and until a new code is generated.
 * @param remainingSeconds The time in seconds until 'ttl' elapses and 'code' changes.
 */
-(void)setTotpCodeWithCode:(NSString* _Nonnull)code ttlSeconds:(long)ttlSeconds remainingSeconds:(long)remainingSeconds;

/**
 * Optionally invoked (according to the configuration of the TOTP type/provider on the server) prior to the invocation of {@link #setTotpCode},
 * in order to give the application a chance to display this message to the user along with the generated code.
 */
-(void)setMessage:(NSString* _Nonnull)message;
@end

/** \enum TSXUserHandleType
*
 * The type or kind of the handle returned from {@link UserHandle}.
 */
typedef NS_OPTIONS(NSUInteger, TSXUserHandleType) {
   UserHandleTypeUserId = 1 << 0    /**< The "username" used for authentication. E.g. "john.doe@domain.com" */,
   UserHandleTypeIdToken = 1 << 1    /**< A token provided by certain authentication journies on relevant server side configuration, to be used with relevant SDK APIs in place of a userId */
} ;
typedef TSXUserHandleType TSXUserHandleTypeSet;

/**
 * An object holding a known (e.g. registered on this device) user information
 */
@interface TSXUserInfo : NSObject { }

/** An object holding a handle to be used as a user identification for the SDK APIs (e.g. {@link TransmitSDKXm#clearDataForUser}, {@link TransmitSDKXm#authenticate}) */
@property (readonly) NSString* _Null_unspecified userHandle;

/** The type of user identification represented by the user handle {@link UserHandleType} for more details */
@property (readonly) TSXUserHandleType userHandleType;

/** A "real" user name appropriate for UI presentation. E.g. "John Doe" or "john.doe@domain.com" when the former isn't provided */
@property (readonly) NSString* _Null_unspecified displayName;

/** Is the current device bound for the user */
@property (readonly) BOOL deviceBound;

/** Has the user perfromed successful authentication on this device */
@property (readonly) BOOL hasLoggedIn;
@end

/**
 * An interface representing a request to generate a TOTP code, encapsulating all parameters necessary for generation of the code,
 * e.g the generator to use for generation, a challenge to be provided to it, etc.
 * An object implementing this interface may be obtained by invoking {@link TransmitSDKXm#totpGenerationRequestForUserFromCanonicalString}
 * on a relevant string representation (e.g. produced by scanning a designated QR code).
 */
@interface TSXTotpGenerationRequest : NSObject { }

/**
 * The user identification handle {@link UserHandleType} for whom the TOTP session is to be invoked.
 */
@property () NSString* _Null_unspecified userId;

/**
 * The type of user identification represented by the user handle {@link UserHandleType} for more details
 */
@property () TSXUserHandleType userHandleType;

/**
 * The challenge to be used by the SDK for a TOTP generation session
 */
@property () NSString* _Null_unspecified challenge;

/**
 * The generator id to be used by the SDK for a TOTP generation session
 */
@property () NSString* _Null_unspecified generatorName;
@end

/**
 * A fingerprint authenticator input response carrying the prompt to show for fingerprint acquisition.  This is an
 * object returned from the authenticator UI session for a fingerprint authenticator (UIAutneticatorSession) in
 * response to a promiseInput call. When this object is returned, the SDK will start acquiring a fingerprint from
 * the user after displaying the prompt provided in this object.
 * Note that this is somewhat different than other authenticators where the return from promiseInput is the actual
 * authenticator secret to be verified whereas in this case the returned value encodes instructions for acquisition
 * done by the SDK.
 *
 * \ingroup sdkProvided
 */
@interface TSXFingerprintInput : TSXInputResponseType { }

/**
 * Prompt message to display when acquiring the fingerprint.
 */
@property () NSString* _Null_unspecified prompt;

/**
 * Customized cancel button title to display in system biometric prompt.
 * Leave unset to use system default. Deployment availability is platform dependent.
 */
@property () NSString* _Null_unspecified cancelButtonTitle;

/**
 * Customized fallback button title to display in system biometric prompt.
 * Leave unset to disable fallback and hide button.
 */
@property () NSString* _Null_unspecified fallbackButtonTitle;

/**
 * Control request to assign to system biometric prompt fallback button.
 * Clicking the fallback button (if enabled, see #fallbackButtonTItle) will behave as if
 * this control request was returned from promiseInput.
 * Default control request is ControlRequestType#SelectMethod.
 */
@property () TSXControlRequestType fallbackControlRequestType;

/**
 * Create a FingerprintInput object with a provided prompt. Fallback button will be hidden.
 *
 * @param prompt An initial value for the prompt attribute.
 */
+(TSXFingerprintInput* _Nonnull) createWithPrompt:(NSString* _Nullable)prompt;

/**
 * Create a FingerprintInput object with a provided prompt and fallback button title and control request.
 * Fallback button is only available in the context of authentication and promotion actions.
 *
 * @param prompt An initial value for the prompt attribute.
 * @param fallbackButtonTitle An initial value for the fallbackButtonTitle attribute.
 * @param fallbackControlRequestType An initial value for the type of contorl request to associate with the fallback button.
 */
+(TSXFingerprintInput* _Nonnull) createFallbackEnabledPromptWithPrompt:(NSString* _Nullable)prompt fallbackButtonTitle:(NSString* _Nullable)fallbackButtonTitle fallbackControlRequestType:(TSXControlRequestType)fallbackControlRequestType;
@end

/**
 * A face-id authenticator input response carrying the prompt to show for face ID acquisition.  This is an
 * object returned from the authenticator UI session for a native face (face-id) authenticator (UIAuthenticatorSession) in
 * response to a promiseInput call. When this object is returned, the SDK will start acquiring a face ID from
 * the user after displaying the prompt provided in this object.
 * Note that this is somewhat different than other authenticators where the return from promiseInput is the actual
 * authenticator secret to be verified whereas in this case the returned value encodes instructions for acquisition
 * done by the SDK.
 *
 * \ingroup sdkProvided
 */
@interface TSXNativeFaceInput : TSXInputResponseType { }

/**
 * Prompt message to display when acquiring the face ID sample.
 */
@property () NSString* _Null_unspecified prompt;

/**
 * Customized cancel button title to display in system biometric prompt.
 * Leave unset to use system default. Deployment availability is platform dependent.
 */
@property () NSString* _Null_unspecified cancelButtonTitle;

/**
 * Customized fallback button title to display in system biometric prompt.
 * Leave unset to disable fallback and hide button.
 */
@property () NSString* _Null_unspecified fallbackButtonTitle;

/**
 * Control request to assign to system biometric prompt fallback button.
 * Clicking the fallback button (if enabled, see #fallbackButtonTItle) will behave as if
 * this control request was returned from promiseInput.
 * Default control request is ControlRequestType#SelectMethod.
 */
@property () TSXControlRequestType fallbackControlRequestType;

/**
 * Create a NativeFaceInput object with a provided prompt. Fallback button will be hidden.
 *
 * @param prompt An initial value for the prompt attribute.
 */
+(TSXNativeFaceInput* _Nonnull) createWithPrompt:(NSString* _Nullable)prompt;

/**
 * Create a NativeFaceInput object with a provided prompt and fallback button title and control request.
 * Fallback button is only available in the context of authentication and promotion actions.
 *
 * @param prompt An initial value for the prompt attribute.
 * @param fallbackButtonTitle An initial value for the fallbackButtonTitle attribute.
 * @param fallbackControlRequestType An initial value for the type of contorl request to associate with the fallback button.
 */
+(TSXNativeFaceInput* _Nonnull) createFallbackEnabledPromptWithPrompt:(NSString* _Nullable)prompt fallbackButtonTitle:(NSString* _Nullable)fallbackButtonTitle fallbackControlRequestType:(TSXControlRequestType)fallbackControlRequestType;
@end

/**
 * A device biometrics input response carrying the textual attributes to display for device biometrics authenticator operation.  This is an
 * object returned from the authenticator UI session for a device biometrics authenticator (UIAuthenticatorSession) in
 * response to a promiseInput call. When this object is returned, the SDK will start operating the device biometrics authenticator.
 *
 * Note that this is somewhat different than other authenticators where the return from promiseInput is the actual
 * authenticator secret to be verified whereas in this case the returned value encodes instructions for acquisition
 * done by the SDK.
 *
 * The textual attributes actual deployment may be dependent and subject to specific platform or OS version availability.
 *
 * \ingroup sdkProvided
 */
@interface TSXDeviceBiometricsInput : TSXInputResponseType { }

/**
 * Prompt message to display when running the device biometrics authenticator.
 */
@property () NSString* _Null_unspecified prompt;

/**
 * Title text to display when running the device biometrics authenticator.
 */
@property () NSString* _Null_unspecified title;

/**
 * Subtitle text to display when running the device biometrics authenticator.
 */
@property () NSString* _Null_unspecified subtitle;

/**
 * A cancel button title text to display when running the device biometrics authenticator.
 */
@property () NSString* _Null_unspecified cancelButtonTitle;

/**
 * Create a DeviceBiometricsInput object with a provided prompt.
 *
 * @param prompt An initial value for the prompt attribute.
 */
+(TSXDeviceBiometricsInput* _Nonnull) createWithPrompt:(NSString* _Nullable)prompt;

/**
 * Create a DeviceBiometricsInput object with the provided textual attributes.
 *
 * @param prompt An initial value for the prompt attribute.
 */
+(TSXDeviceBiometricsInput* _Nonnull) createFullWithTitle:(NSString* _Nullable)title subtitle:(NSString* _Nullable)subtitle prompt:(NSString* _Nullable)prompt cancelButtonTitle:(NSString* _Nullable)cancelButtonTitle;
@end

/**
 * A PIN authenticator input response carrying an input PIN. This is an object returned from the authenticator UI
 * session for a PIN authenticator (UIAutneticatorSession) in response to a promiseInput call. When this object is returned,
 * the SDK will verify the PIN value it carries with the Transmit Server.
 *
 * \ingroup sdkProvided
 */
@interface TSXPinInput : TSXInputResponseType { }

/**
 * PIN submitted by the UI to the authenticator.
 */
@property () NSString* _Null_unspecified pin;

/**
 * Create a PinInput object with the specified PIN submission.
 *
 * @param pin Initial value of the pin attribute.
 */
+(TSXPinInput* _Nonnull) createWithPin:(NSString* _Nonnull)pin;
@end

/**
 * A Pattern authenticator input response carrying an input pattern. This is an object returned from the authenticator UI
 * session for a pattern authenticator (UIAutneticatorSession) in response to a promiseInput call. When this object is returned,
 * the SDK will verify the pattern value it carries with the Transmit Server.
 *
 * \ingroup sdkProvided
 */
@interface TSXPatternInput : TSXInputResponseType { }

/**
 * Pattern submitted by the UI to the authenticator.
 */
@property () NSString* _Null_unspecified patternDescription;

/**
 * Create a PatternInput object with the specified pattern submission.
 *
 * @param patternDescription Value of the patternDescription attribute.
 */
+(TSXPatternInput* _Nonnull) createWithPatternDescription:(NSString* _Nonnull)patternDescription;
@end

/**
 * A response for unregistration requests via UIHandler handleAuthenticatorUnregistration. This object represents the response sent from the client
 * to the SDK when asked to unregister an authenticator.
 *
 * \ingroup sdkProvided
 */
@interface TSXUnregistrationInput : NSObject { }

/**
 * An integer representing a user selection in the unregistration.
 * Value of "0" denotes "continue with unregistration" whereas a value of "1" denotes aborting the execution and policy.
 */
@property () long userChoice;

/**
 * Create a UnregistrationInput object with a specified userChoice value.
 *
 * @param userChoice Initial value for the userChoice attribute.
 */
+(TSXUnregistrationInput* _Nonnull) createWithUserChoice:(long)userChoice;
@end

/**
 * Top level superclass for placeholder authenticator input responses; this can either be a failure response
 * or a successful authenticator response.
 *
 * \ingroup sdkProvided
 */
@interface TSXPlaceholderInputResponse : TSXInputResponseType { }

/**
 * Create a PlaceholderAuthSuccessResponse object with the specified placeholder token submission.
 *
 * @param placeholderToken Value of the placeholderToken attribute.
 */
+(TSXPlaceholderInputResponse* _Nonnull) createSuccessResponseWithPlaceholderToken:(NSString* _Nonnull)placeholderToken;

/**
 * Create a PlaceholderAuthFailureResponse object with the specified placeholder error information and updated authenticator status.
 * @param currentAuthenticatorStatus An AuthenticatorDescription object that holds the current status of the authenticator. This is where initial post-failure status will be taken from.
 * @param error An error describing the failure mode for the authentication.
 */
+(TSXPlaceholderInputResponse* _Nonnull) createdFailedResponseWithCurrentAuthenticatorStatus:(TSXAuthenticatorDescription* _Nonnull)currentAuthenticatorStatus error:(TSXAuthenticationError* _Nonnull)error;

/**
 * Create a PlaceholderAuthFailureWithServerProvidedStatusResponse object with the specified placeholder error. Authenticator status will be updated according to server response.
 *
 * @param error An error describing the failure mode for the authentication.
 */
+(TSXPlaceholderInputResponse* _Nonnull) createFailedResponseWithServerProvidedStatusWithError:(TSXAuthenticationError* _Nonnull)error;
@end

/**
 * Represents a successful authentication using placeholder authenticator
 *
 * \ingroup sdkProvided
 */
@interface TSXPlaceholderAuthSuccessResponse : TSXPlaceholderInputResponse { }

/**
 * Placeholder received from the Transmit Server (via the app server) to attest to successful external authentication.
 */
@property () NSString* _Null_unspecified placeholderToken;
@end

/**
 * Represents a failed authentication using placeholder authenticator; encapsulates an error result with
 * an updated authenticator status.
 *
 * \ingroup sdkProvided
 */
@interface TSXPlaceholderAuthFailureResponse : TSXPlaceholderInputResponse { }

/**
 * An error representing the failure mode of the authenticator
 */
@property () TSXAuthenticationError* _Null_unspecified failureError;

/**
 * Post failure status: true if the authenticator is expired (and will thus typically require registration after authentication).
 */
@property () BOOL expired;

/**
 * Post failure status: true if the authenticator is registered for the current user and app (registrationStatus == Registered)
 */
@property () BOOL registered;

/**
 * Post failure status: Registration state of authenticator.
 */
@property () TSXAuthenticatorRegistrationStatus registrationStatus;

/**
 * Post failure status: true if the authenticator is locked.
 */
@property () BOOL locked;
@end

/**
 * Represents a failed authentication using placeholder authenticator where authenticator status is updated from server response;
 * encapsulates an error result.
 *
 * \ingroup sdkProvided
 */
@interface TSXPlaceholderAuthFailureWithServerProvidedStatusResponse : TSXPlaceholderInputResponse { }

/**
 * An error representing the failure mode of the authenticator
 */
@property () TSXAuthenticationError* _Null_unspecified failureError;
@end

/**
 * Top level superclass for FIDO authenticator input responses; this can either be a failure response
 * or a successful authenticator response.
 *
 * \ingroup sdkProvided
 */
@interface TSXFidoInputResponse : TSXInputResponseType { }

/**
 * Create a FidoAuthenticatorSuccessResponse object with the specified FIDO response JSON message.
 *
 * @param fidoResponse Value of the fidoResponse attribute.
 */
+(TSXFidoInputResponse* _Nonnull) createSuccessResponseWithFidoResponse:(NSDictionary * _Nonnull)fidoResponse;

/**
 * Create a FidoAuthFailedResponse object with the specified failure information
 *
 * @param currentAuthenticatorStatus An AuthenticatorDescription object that holds the current status of the authenticator. This is where initial post-failure status will be taken from.
 * @param error An error describing the failure mode for the authentication.
 */
+(TSXFidoInputResponse* _Nonnull) createdFailedResponseWithCurrentAuthenticatorStatus:(TSXAuthenticatorDescription* _Nonnull)currentAuthenticatorStatus error:(TSXAuthenticationError* _Nonnull)error;
@end

/**
 * Represents a successful authentication input using fido authenticator
 *
 * \ingroup sdkProvided
 */
@interface TSXFidoAuthSuccessResponse : TSXFidoInputResponse { }

/**
 * FIDO response message received from the FIDO client to attest to successful authentication/registration.
 */
@property () NSDictionary * _Null_unspecified fidoResponse;
@end

/**
 * Represents a failed authentication using FIDO authenticator; encapsulates an error result with
 * an updated authenticator status.
 *
 * \ingroup sdkProvided
 */
@interface TSXFidoAuthFailureResponse : TSXFidoInputResponse { }

/**
 * An error representing the failure mode of the authenticator
 */
@property () TSXAuthenticationError* _Null_unspecified failureError;

/**
 * Post failure status: true if the authenticator is expired (and will thus typically require registration after authentication).
 */
@property () BOOL expired;

/**
 * Post failure status: true if the authenticator is registered for the current user and app (registrationStatus == Registered)
 */
@property () BOOL registered;

/**
 * Post failure status: Registration state of authenticator.
 */
@property () TSXAuthenticatorRegistrationStatus registrationStatus;

/**
 * Post failure status: true if the authenticator is locked.
 */
@property () BOOL locked;
@end

/**
 * Represents a camera-based input response; this is essentiall a JSON representation
 * of a response to an image acquisition challenge.
 *
 * \ingroup sdkProvided
 */
@interface TSXCameraInputResponse : TSXInputResponseType { }

/**
 * JSON representation of the response to the acquisition challenge.
 */
@property () NSDictionary * _Null_unspecified acquisitionResponse;
@end

/**
 * A single step in a multi-step camera acquisition session. This step description object includes
 * a set of acquisition challenges (CameraAcquisitionStepDescription#acquisitionChallenges).
 * The authentication input session must provide an acquisition response that meets one of these
 * challenges as the input for this step. This is done by passing the list of challenges to the
 * camera acquisition control for the platform.
 *
 * \ingroup sdkProvided
 */
@interface TSXCameraAcquisitionStepDescription : TSXMultiInputStepDescription { }

/**
 * The acquisition instructions for the current acquisition step. This set of acuiqisition instructions
 * should be passed to the camera acquisition control for the platform to obtain the input for this
 * step.
 */
@property (readonly) NSArray<NSDictionary *> * _Null_unspecified acquisitionChallenges;
@end

/**
 * Represents a security question.
 */
@interface TSXSecurityQuestion : NSObject { }

/**
 * An identifier for the secuirty question.
 */
@property (readonly) NSString* _Null_unspecified securityQuestionId;

/**
 * The text of the security question.
 */
@property (readonly) NSString* _Null_unspecified securityQuestionText;
@end

@interface TSXSecurityQuestionAnswer : NSObject { }

@property (readonly) NSString* _Null_unspecified answerText;

+(TSXSecurityQuestionAnswer* _Nonnull) createWithTextWithAnswerText:(NSString* _Nonnull)answerText;
@end

@interface TSXSecurityQuestionAndAnswer : NSObject { }

@property (readonly) TSXSecurityQuestion* _Null_unspecified question;

@property (readonly) TSXSecurityQuestionAnswer* _Null_unspecified answer;

+(TSXSecurityQuestionAndAnswer* _Nonnull) createAnswerToQuestionWithQuestion:(TSXSecurityQuestion* _Nonnull)question answer:(TSXSecurityQuestionAnswer* _Nonnull)answer;
@end

/**
 * Represents a question-based authetnicator response type.
 * This is the superclass of the only-supported response type for the questions authetnicator,
 * SecurityQuestionAnswersInputResponse.
 * \ingroup sdkProvided
 */
@interface TSXSecurityQuestionInputResponse : TSXInputResponseType { }

+(TSXSecurityQuestionInputResponse* _Nonnull) createSecurityQuestionAnswersInputResponseWithAnswers:(NSArray<TSXSecurityQuestionAndAnswer*> * _Nonnull)answers;
@end

/**
 * An input response for a questions authetnicator.
 * Provides a set of answers to questions previosuly provided to the authenticator as part of the
 * current step descriptor.
 *
 * Note that only answers that are part of the current step may be provided.
 */
@interface TSXSecurityQuestionAnswersInputResponse : TSXSecurityQuestionInputResponse { }

@property (readonly) NSArray<TSXSecurityQuestionAndAnswer*> * _Null_unspecified answers;
@end

/**
 * A single step in a multi-step questions authenticator session. This step description object includes
 * a set questions that the user should answer to authenticate.
 *
 * \ingroup sdkProvided
 */
@interface TSXSecurityQuestionStepDescription : TSXMultiInputStepDescription { }

/**
 * The set of questions to be answered by the user.
 */
@property (readonly) NSArray<TSXSecurityQuestion*> * _Null_unspecified securityQuestions;

/**
 * Minimum number of secuirty questions desired in this step
 */
@property (readonly) long minAnswersNeeded;
@end

/**
 * Represents an audio-based input response; this is essentiall a JSON representation
 * of a response to an audio acquisition challenge.
 *
 * \ingroup sdkProvided
 */
@interface TSXAudioInputResponse : TSXInputResponseType { }

/**
 * JSON representation of the response to the acquisition challenge.
 */
@property () NSDictionary * _Null_unspecified acquisitionResponse;
@end

/**
 * A single step in a multi-step audio acquisition session. This step description object includes
 * a set of acquisition challenges (AudioAcquisitionStepDescription#acquisitionChallenges).
 * The authentication input session must provide an acquisition response that meets one of these
 * challenges as the input for this step. This is done by passing the list of challenges to the
 * audio acquisition control for the platform.
 *
 * \ingroup sdkProvided
 */
@interface TSXAudioAcquisitionStepDescription : TSXMultiInputStepDescription { }

/**
 * The acquisition instructions for the current acquisition step. This set of acuiqisition instructions
 * should be passed to the audio acquisition control for the platform to obtain the input for this
 * step.
 */
@property (readonly) NSArray<NSDictionary *> * _Null_unspecified acquisitionChallenges;

/**
 * Passphrase text -- for speaking by the user in this step.
 */
@property (readonly) NSString* _Null_unspecified passphraseText;
@end

/**
 * Represents a target -- device / channel / combination thereof -- that should be
 * used with a target-based authenticator.
 *
 * This is a base interface; specific targets for specific authenticators are
 * derived from this interface.
 */
@interface TSXAuthenticatorTarget : NSObject { }

/**
 * User-facing description of the target.
 */
@property (readonly) NSString* _Null_unspecified description;
@end

/**
 * An authentication action parameter selecting a target for target-based authenticators.
 *
 * When a parameter of this type is used in an authentication action, it will set the target
 * for use by the target-based authenticator. At most one parameter of this type may be specified
 * for an authentication action.
 *
 * Typically if this parameter is not specified and there is more than one target available for a selected
 * authenticator, the authenticator session will have to select the target (e.g by asking the user for a target).
 *
 */
@interface TSXAuthenticationActionParameterTargetSelection : TSXAuthenticationActionParameter { }

/**
 * The authenticator target for selection for this authentication action.
 */
@property (readonly) TSXAuthenticatorTarget* _Null_unspecified target;

/**
 * Construct an authentication action target selection parameter for selecting a specified target.
 *
 * @param target the target value for the constructed object.
 */
+(TSXAuthenticationActionParameterTargetSelection* _Nonnull) createWithTarget:(TSXAuthenticatorTarget* _Nonnull)target;
@end

/**
 * The input type for all target-based authenticators' authenticator input response. This object
 * represents either a target selection request, or an input response. Two type parameters are defined
 * for this type -- the ConcreteAuthenticatorInputType is the class of input responses that may be
 * carried by it and the TargetType is the type of target carried by target selection requests.
 * All UIAuthenticatorSessionTargetBased-based sessions use a response type which is a specialization
 * of this generic type, with a specific ConcreateAuthenticatorInputType and TargetType types.
 *
 * A UIAuthenticatorSessionTargetBased-based session returns an instance of this class created by
 * #createTargetSelectionRequest to indicate a request to change the target from promiseInput.
 *
 * A UIAuthenticatorSessionTargetBased-based session returns an instance of this class created by
 * #createAuthenticatorInput to provide concrete authenticator input response to promiseInput.
 */
@interface TSXTargetBasedAuthenticatorInput<ConcreteAuthenticatorInputType,TargetType> : TSXInputResponseType { }

/**
 * Indicates a concrete authenticator input. Can't contain a non-null value if #selectedTarget contains a
 * non-null value.
 */
@property () ConcreteAuthenticatorInputType _Null_unspecified authenticatorInput;

/**
 * Indicates selected targets.  Can't contain a non-null value if #authenticatorInput contains a
 * non-null value.
 */
@property () NSArray<TargetType> * _Null_unspecified selectedTargets;

/**
 * Construct a target-based authenticator input conveying a concrete input for the
 * concrete authenticator type.
 *
 * @param authenticatorInput The concrete input for the concrete authenticator type.
 */
+(TSXTargetBasedAuthenticatorInput* _Nonnull) createAuthenticatorInputWithAuthenticatorInput:(ConcreteAuthenticatorInputType _Nonnull)authenticatorInput;

/**
 * Construct a target-based authenticator input conveying a request to change the authenticator
 * target with a single target selection. Note: Maintained for backwards compatibility.
 *
 * @param target The target to select.
 */
+(TSXTargetBasedAuthenticatorInput* _Nonnull) createTargetSelectionRequestWithTarget:(TargetType _Nonnull)target;

/**
 * Construct a target-based authenticator input conveying a request to change the authenticator
 * target with multiple target selection.
 *
 * @param targets The targets to select.
 */
+(TSXTargetBasedAuthenticatorInput* _Nonnull) createTargetsSelectionRequestWithTargets:(NSArray<TargetType> * _Nonnull)targets;
@end

/**
 * Base interface for all target-based authenticator sessions.
 *
 * Target-based authenticators involve using an OOB channel or device during the authentication process. For example,
 * an OTP authenticator allows selecting how the OTP will be delivered (and where to). Similarly a mobile approve
 * authenticator allows selecting which device(s) should be used for approval.
 *
 * These authenticators' input response is always a specialization of TargetBasedAuthenticatorInput. The specialization
 * specifies a type for concrete inputs to the authenticator as well as the type for authentiactor targets.
 *
 * These authenticators allow selecting the target to use among a list of targets; this is done by
 * #promiseInput method returning an instance of #TargetBasedAuthenticatorInput created by a call to
 * TargetBasedAuthenticatorInput#createTargetSelectionRequest, with the selected
 * target. The list of available targets for selection is provided to the session via a call to setAvailableTargets
 * that always precedes promiseInput if there's a change to the set of available targets (and specifically prior to
 * the first invocation of promiseInput).
 *
 * To provide actual input to the authenticator, as opposed to a request to change the target, the #promiseInput
 * method returns an instance of #TargetBasedAuthenticatorInput created by a call to
 * TargetBasedAuthenticatorInput#createAuthenticatorInput, with the desired input response instance.
 *
 * Target-based authenticators allow specifying at most one parameter of type
 * AuthenticationActionParameterTargetSelection when starting the authentication action (e.g using
 * selectAuthenticator). When such a parameter is provided and it identifies a valid target, this target will be
 * initially used for authentication.
 */
@interface TSXUIAuthenticatorSessionTargetBased<MResponseType,TargetType> : TSXUIAuthenticatorSession<TSXTargetBasedAuthenticatorInput<MResponseType,TargetType>*> { }

/**
 * Notify the session of the list of targets available for authentication.
 * This is invoked by the SDK prior to #promiseInput whenever there's an update to the set of available targets,
 * and prior to the first invocation of #promiseInput to provide the initial list of targets.
 *
 * @param targets List of targets available for this session.
 */
-(void)setAvailableTargets:(NSArray<TargetType> * _Nullable)targets;
@end

/** \enum TSXOtpChannel
*
 * Represents the type of an OTP channel.
 *
 * \ingroup sdkProvided
 */
typedef NS_OPTIONS(NSUInteger, TSXOtpChannel) {
   OtpChannelUnknown = 1 << 0    /**< An unknown channel type */,
   OtpChannelSms = 1 << 1    /**< SMS based OTP delivery */,
   OtpChannelEmail = 1 << 2    /**< E-mail based OTP delivery */,
   OtpChannelPushNotification = 1 << 3    /**< Delivery via a push notification */,
   OtpChannelVoiceCall = 1 << 4    /**< Delivery via a voice telephone call */
} ;
typedef TSXOtpChannel TSXOtpChannelSet;

/**
 * Represents target device info for selection, may be used for mobile approve, OTP push or TOTP.
 *
 * \ingroup sdkProvided
 */
@interface TSXTargetDeviceDetails : NSObject { }

/**
 * Target device id
 */
@property (readonly) NSString* _Null_unspecified deviceId;

/**
 * Target device model
 */
@property (readonly) NSString* _Null_unspecified model;

/**
 * Target device last access date
 */
@property (readonly) NSDate * _Null_unspecified lastAccessed;

/**
 * Is target device also current device
 */
@property (readonly) BOOL isCurrent;

/**
 * Target device os model
 */
@property (readonly) NSString* _Null_unspecified osType;

/**
 * Target device os version
 */
@property (readonly) NSString* _Null_unspecified osVersion;

/**
 * Target device alias
 */
@property (readonly) NSString* _Nullable alias;

/**
 * Creates a description string for this device
 */
-(NSString* _Null_unspecified)describe;
@end

/**
 * Represents an OTP target, to which an OTP code may be generated and sent.
 *
 * \ingroup sdkProvided
 */
@interface TSXOtpTarget : TSXAuthenticatorTarget { }

/**
 * Type of channel for this OTP target.
 */
@property (readonly) TSXOtpChannel channel;

/**
 * Optional device attributes if a target designates a device
 */
@property (readonly) TSXTargetDeviceDetails* _Nullable deviceDetails;
@end

/**
 * A supertype for all OTP concrete authenticator inputs.
 *
 * \ingroup sdkProvided
 */
@interface TSXOtpInput : TSXInputResponseType { }
@end

/**
 * An OTP authenticator input response carrying a request to resent an OTP code. This is an object
 * returned from the authenticator UI session for an OTP (UIAutneticatorSessionOtp) in response to a promiseInput
 * call. When this object is returned, the SDK will trigger generation of an OTP code to the last selected target.
 * The SDK will then invoke the session's UIAuthenticatorSession#promiseInput again to receive further inputs from the
 * authenticator session (e.g an OtpInputOtpSubmission object). Also, once the new OTP code is generated, the SDK will
 * invoke the session's UIAuthenticatorSessionOtp#setGeneratedOtp.
 *
 * \ingroup sdkProvided
 */
@interface TSXOtpInputRequestResend : TSXOtpInput { }

/**
 * Create an OtpInputRequestResend object.
 */
+(TSXOtpInputRequestResend* _Nonnull) createOtpResendRequest;
@end

/**
 * An OTP authenticator input response carrying an input OTP. This is an object returned from the authenticator UI
 * session for an OTP (UIAutneticatorSessionOtp) in response to a promiseInput call. When this object is returned,
 * the SDK will verify the OTP value it carries with the Transmit Server. This object is to be returned by the session
 * only after at least one OTP was generated either through auto exec or by providing an OtpInputSelectTarget
 * response.
 *
 * \ingroup sdkProvided
 */
@interface TSXOtpInputOtpSubmission : TSXOtpInput { }

/**
 * OTP value submitted by the UI to the authenticator.
 */
@property () NSString* _Null_unspecified otp;

/**
 * Create an OtpInputOtpSubmission with the specified OTP value.
 *
 * @param otp Initial value for the otp property.
 */
+(TSXOtpInputOtpSubmission* _Nonnull) createOtpSubmissionWithOtp:(NSString* _Nonnull)otp;
@end

/**
 * Represents the format of a generated OTP. This is an abstract base for concrete
 * OtpFormat types.
 *
 * \ingroup sdkProvided
 */
@interface TSXOtpFormat : NSObject { }
@end

/**
 * Represents an OTP Format that describes a numeric OTP, comprising of a fixed
 * number of digits.
 *
 * \ingroup sdkProvided
 */
@interface TSXOtpFormatNumeric : TSXOtpFormat { }

/**
 * Number of digits in the generated OTP
 */
@property (readonly) long otpLength;
@end

/**
 * Represents an OTP Format that describes a QR OTP.
 *
 * \ingroup sdkProvided
 */
@interface TSXOtpFormatQr : TSXOtpFormat { }
@end

/**
 * Represents an OTP Format that describes an externally defined OTP format.
 * This includes a single JSON object that may include additional OTP format parameters.
 *
 * \ingroup sdkProvided
 */
@interface TSXOtpFormatExternal : TSXOtpFormat { }

@property (readonly) NSDictionary * _Null_unspecified data;
@end

/**
 * Superclass for push request payloads comprehensible by the TransmitSDK. These are
 * payloads sent via push notifications that instruct the SDK to perform some action (e.g
 * display mobile approvals).
 *
 * \ingroup sdkProvided
 */
@interface TSXPushRequestPayload : NSObject { }

/**
 * Return the semantic title content the push notification should display.
 */
-(NSString* _Null_unspecified)title;
@end

/**
 * A push request payload that holds the code for an OTP based authentication. Objects
 * of this class encode parameters for showing the OTP code. Typically they are
 * created based on data sent via a push notification, and used by the application to display a push notification.
 *
 * \ingroup sdkProvided
 */
@interface TSXOtpPushRequestPayload : TSXPushRequestPayload { }

/**
 * Return the user ID specified by this mobile approve push request payload, if any.
 */
-(NSString* _Null_unspecified)userId;

/**
 * Return the semantic body content the push notification should display.
 */
-(NSString* _Null_unspecified)body;
@end

/**
 * An authenticator UI session for OTP. This interface, implemented by the client, is a specialization of the
 * UIAuthenticatorSessionTargetBased protocol used for OTP authentication. In addition to the protocol defined by
 * UIAuthenticatorSessionTargetBased, this interface provides facilities for the SDK to notify the UI session that an OTP
 * was generated, along with information on the target to which the OTP was sent and the format of the OTP.
 *
 * The valid inputs from a UIAuthenticatorSessionOtp's promiseInput call are classes derived from #OtpInput or
 * #TargetBasedAuthenticatorInputSelectTarget.
 *
 * \ingroup clientProvided
 */
@interface TSXUIAuthenticatorSessionOtp : TSXUIAuthenticatorSessionTargetBased<TSXOtpInput*,TSXOtpTarget*> { }

/**
 * Notify the session that an OTP was generated with a specific format and target. This notification is sent
 * every time the client returns an OtpInputRequestResend or TargetBasedAuthenticatorInputSelectTarget response in
 * a call to promiseInput(), once the new OTP code was sent. In addition if an OTP code was automatically generated
 * when action execution began, details of this automatically generated code will be relayed using this call
 * once the session starts (note that when the session is created, UIHandler#createOtpAuthSession is called
 * with parameters that reflect that as well).
 *
 * This is also invoked by the SDK with a null \ref format and \ref target to indicate that there is no valid OTP
 * generated and pending validation. If that is the case, an implementation should select a valid OTP target in the
 * next call to promiseInput.
 *
 * Implementations should update the UI to reflect the newly generated OTP format and the target to which the
 * OTP was sent.
 *
 * @param format Format of the generated OTP
 * @param target OtpTarget describing the target to which the OTP was sent.
 *
 */
-(void)setGeneratedOtpWithFormat:(TSXOtpFormat* _Nullable)format target:(TSXOtpTarget* _Nullable)target;
@end

/**
 * A supertype for all Mobile Approve authenticator inputs.
 *
 * \ingroup sdkProvided
 */
@interface TSXMobileApproveInput : TSXInputResponseType { }
@end

/**
 * Represents a Mobile Approve target, for which an approval may be created.
 *
 * \ingroup sdkProvided
 */
@interface TSXMobileApproveTarget : TSXAuthenticatorTarget { }

/**
 * Target device details.
 */
@property (readonly) TSXTargetDeviceDetails* _Null_unspecified deviceDetails;
@end

/**
 * A Mobile Approve authenticator input response carrying a request to poll for authentication. This is an object
 * returned from the authenticator UI session for a MobileApprove (UIAutneticatorSessionMobileApprove) in response to
 * a promiseInput call. When this object is returned, the SDK will poll the server asking if authentication was
 * completed and what was the result. This object is to be returned by the session only after approval was created
 * either through auto exec or by providing an MobileApproveTargetSelectionInput response.
 *
 * There are two types of polling requests: long polling and short polling. A short polling request issues a request
 * to the server that returns immediately, either indicating that the mobile approve was approved or denied, or indicating
 * the approval is still pending (in which case the session isn't complete and promiseInput will be invoked again).
 * Clients should request the SDK for short polling requests periodically (eg. once every 3 seconds). To do this,
 * a client would typically create a timer in a call to UIAuthenticatorSessionMobileApprove#promiseInput, such that
 * promiseInput will return the polling request asynchronously after that period. With a polling period of P it may
 * take up to period P to detect that an approval was confirmed / denied (or on average P/2).
 *
 * A long polling request indicates to the server that it should return a response as soon as an approval is no longer pending
 * -- or after a timeout occurs (the timeout is configurable in the long polling request). Here a client would typically issue the
 * long polling request immediately on invocation of UIAuthenticatorSessionMobileApprove#promiseInput, specifiying a timeout
 * period P. If ater period P the approval is still pending, promiseInput will be invoked again (and will probably return the same
 * long polling request.)
 *
 * \ingroup sdkProvided
 */
@interface TSXMobileApproveInputRequestPolling : TSXMobileApproveInput { }

/**
 * If nonzero -- timeout in seconds for long polling request to issue.
 * If zero -- this is a short poll request.
 */
@property () long pollingTimeout;

/**
 * Create a MobileApproveInputRequestPolling object representing a short polling request.
 */
+(TSXMobileApproveInputRequestPolling* _Nonnull) createRequestPollingInput;

/**
 * Create a MobileApproveInputRequestPolling object representing a long polling request, with
 * given timeout.
 */
+(TSXMobileApproveInputRequestPolling* _Nonnull) createRequestLongPollingInputWithTimeoutInSeconds:(long)timeoutInSeconds;
@end

/**
 * Represents the an OTP generated for mobile approval.
 *
 * \ingroup sdkProvided
 */
@interface TSXMobileApproveOtp : NSObject { }

@property (readonly) NSString* _Null_unspecified value;

@property (readonly) TSXOtpFormat* _Null_unspecified format;

@property (readonly) NSString* _Nullable qrAlternativeRepresentation;
@end

/**
 * An authenticator UI session for Mobile Approve. This interface, implemented by the client, is a
 * specialization of the UIAuthenticatorSessionTargetBased protocol used for Mobile Approve authentication. In
 * addition to the protocol defined by UIAuthenticatorSessionTargetBased, this interface provides facilities
 * for the SDK to notify the UI session that an approval was created, along with information on the target for
 * which the approval was created.
 *
 * \ingroup clientProvided
 */
@interface TSXUIAuthenticatorSessionMobileApprove : TSXUIAuthenticatorSessionTargetBased<TSXMobileApproveInput*,TSXMobileApproveTarget*> { }

/**
 * Notify the session that an approval was created for target. This notification is sent when the client returns
 * a MobileApproveTargetSelectionInput response in a call to promiseInput(), as soon as the new approval was
 * created. In addition if an approval was automatically created when action execution began, details of this
 * automatically created approval will be relayed using this call once the session starts (note that when the
 * session is created, UIHandler#createMobileApproveAuthSession is called with parameters that reflect that as
 * well).
 *
 * Implementations should update the UI to reflect the newly created approval and the target for which the
 * approval was created. If otp was generated for the approval the generated otp and format will be transferred
 * here as well.
 *
 * Calling this with null targets notifies the session that it should reset it's state to allow retry of the
 * authentication process. This should include cleaning up of targets and possibly otp, resetting the state of
 * the session to inital state.
 *
 * @param targets the targets for which the approval was created.
 *
 */
-(void)setCreatedApprovalInfoWithTargets:(NSArray<TSXMobileApproveTarget*> * _Nullable)targets otp:(TSXMobileApproveOtp* _Nullable)otp;
@end

/**
 * Represents the format of a TOTP challenge. This is an abstract base for concrete TotpChallengeFormat types.
 *
 * \ingroup sdkProvided
 */
@interface TSXTotpChallengeFormat : NSObject { }
@end

/**
 * Represents a TOTP challenge format that describes an alpha-numeric readable TOTP challenge.
 *
 * \ingroup sdkProvided
 */
@interface TSXTotpChallengeFormatAlphaNumeric : TSXTotpChallengeFormat { }
@end

/**
 * Represents a TOTP challenge format that describes a numeric TOTP challenge.
 *
 * \ingroup sdkProvided
 */
@interface TSXTotpChallengeFormatNumeric : TSXTotpChallengeFormat { }
@end

/**
 * Represents a TOTP challenge format that describes a QR TOTP challenge.
 *
 * \ingroup sdkProvided
 */
@interface TSXTotpChallengeFormatQr : TSXTotpChallengeFormat { }
@end

/**
 * Represents a TOTP challenge with value and format.
 *
 * \ingroup sdkProvided
 */
@interface TSXTotpChallenge : NSObject { }

/**
 * Challenge value.
 */
@property () NSString* _Null_unspecified value;

/**
 * Challenge format.
 */
@property () TSXTotpChallengeFormat* _Null_unspecified format;
@end

/**
 * Represents a Totp target, on which an temporary code may be generated.
 *
 * \ingroup sdkProvided
 */
@interface TSXTotpTarget : TSXAuthenticatorTarget { }

/**
 * Target device details.
 */
@property (readonly) TSXTargetDeviceDetails* _Null_unspecified deviceDetails;
@end

/**
 * A supertype for all Totp authenticator inputs.
 *
 * \ingroup sdkProvided
 */
@interface TSXTotpInput : TSXInputResponseType { }
@end

/**
 * A Totp authenticator input response carrying an input code. This is an object returned from the authenticator UI
 * session for an Totp (UIAutneticatorSessionTotp) in response to a promiseInput call. When this object is returned,
 * the SDK will verify the Totp value it carries with the Transmit Server.
 *
 * \ingroup sdkProvided
 */
@interface TSXTotpInputCodeSubmission : TSXTotpInput { }

/**
 * Totp value submitted by the UI to the authenticator.
 */
@property () NSString* _Null_unspecified code;

/**
 * Create an TotpInputCodeSubmission with the specified code value.
 *
 * @param code the code value for the Totp.
 */
+(TSXTotpInputCodeSubmission* _Nonnull) createTotpCodeSubmissionWithCode:(NSString* _Nonnull)code;
@end

/**
 * An authenticator UI session for Totp. This interface, implemented by the client, is a specialization of the
 * UIAuthenticatorSessionTargetBased protocol used for Totp authentication. In addition to the protocol defined
 * by UIAuthenticatorSessionTargetBased, this interface provides facilities for the SDK to notify the UI session
 * that a target device(s) was selected for code generation.
 *
 * The interface also provides a method setChallenge to be used to update the UI session of a created challenge.
 * The UI session is then expected to display the challenge to the user on current device. The challenge is
 * expected to then be acquired by the code generating device.
 *
 * UIAuthenticatorSessionTargetBased.setAvailableTargets is called with null to indicate there's no need for target
 * selection. In such a case the UI Session is expected to move directly to display challenge (if needed) and TOTP
 * code input.
 *
 * \ingroup clientProvided
 */
@interface TSXUIAuthenticatorSessionTotp : TSXUIAuthenticatorSessionTargetBased<TSXTotpInput*,TSXTotpTarget*> { }

/**
 * Notify the session that a target device(s) was selected for code generation. This notification is sent when the
 * client returns a TotpTargetSelectionInput response in a call to promiseInput().
 *
 * Implementations should update the UI to reflect the target on which the code may be generated.
 *
 * @param targets the targets for which the approval was created.
 *
 */
-(void)setTargetDevices:(NSArray<TSXTotpTarget*> * _Nullable)targets;

/**
 * Notify the session that a challenge was created for code generation. This notification is sent if the server created
 * a challenge to be used in TOTP code generation, soon after startSession was called.
 *
 * Implementations should update the UI to display the challenge so that it can be acquired by generating the code
 * generating device.
 *
 * @param challenge The challenge created by the server for this code generation.
 */
-(void)setChallenge:(TSXTotpChallenge* _Nullable)challenge;
@end

/**
 * Top level superclass for FIDO2 authenticator input responses; this can either be a failure response
 * or a successful authenticator response.
 *
 * \ingroup sdkProvided
 */
@interface TSXFido2InputResponse : TSXInputResponseType { }

/**
 * Create a Fido2AuthenticatorSuccessResponse object with the specified FIDO2 response JSON message.
 *
 * @param fido2Response Value of the fido2Response attribute.
 */
+(TSXFido2InputResponse* _Nonnull) createSuccessResponseWithFido2Response:(NSDictionary * _Nonnull)fido2Response;

/**
 * Create a Fido2AuthenticationFailedResponse object with the specified failure information
 *
 * @param error An error describing the failure mode for the authentication.
 */
+(TSXFido2InputResponse* _Nonnull) createdFailedResponseWithError:(TSXAuthenticationError* _Nonnull)error;
@end

/**
 * Represents a successful authentication input using fido2 authenticator
 *
 * \ingroup sdkProvided
 */
@interface TSXFido2AuthenticatorSuccessResponse : TSXFido2InputResponse { }

/**
 * FIDO2 response message received from the FIDO2 client to attest to successful authentication/registration.
 */
@property () NSDictionary * _Null_unspecified fido2Response;
@end

/**
 * Represents a failed authentication using FIDO2 authenticator; encapsulates an error result.
 *
 * \ingroup sdkProvided
 */
@interface TSXFido2AuthenticationFailedResponse : TSXFido2InputResponse { }

/**
 * An error representing the failure mode of the authenticator
 */
@property () TSXAuthenticationError* _Null_unspecified failureError;
@end

/**
 * A response to a confirmation or information screen. This object represents the response sent from the client
 * to the SDK when asked to display a confirmation or information screen.
 *
 * \ingroup sdkProvided
 */
@interface TSXConfirmationInput : NSObject { }

/**
 * An integer representing a user selection in the confirmation or information screen. The exact semantics of this
 * value depends on the context in which the ConfirmationInput object is returned. For example, for a confirmation
 * screen a value of "0" denotes "continue" whereas a value of "1" denotes "cancel"; these values are returned
 * to the policy evaluation engine for use in the policy downstream.
 */
@property () long userChoice;

/**
 * An escape request, if this object is signalling a request to invoke an escape path in the journey.
 */
@property () TSXActionEscapeRequest* _Null_unspecified actionEscapeRequest;

/**
 * Create a ConfirmationInput object with a specified userChoice value.
 *
 * @param userChoice Initial value for the userChoice attribute.
 */
+(TSXConfirmationInput* _Nonnull) createWithUserChoice:(long)userChoice;

/**
 * Create an ConfirmationInput that encodes a request to escape the action
 *
 * @param actionEscape The escape option to signal
 * @param escapeParams Additional parameters to pass to the journey when escaping.
 */
+(TSXConfirmationInput* _Nonnull) createEscapeRequestWithActionEscape:(TSXActionEscapeOption* _Nonnull)actionEscape escapeParams:(NSDictionary * _Nullable)escapeParams;
@end

typedef NS_OPTIONS(NSUInteger, TSXQrCodeFormat) {
   QrCodeFormatNumeric = 1 << 0    /**< Numeric data */,
   QrCodeFormatAlphanumeric = 1 << 1    /**< Alphanumeric data */,
   QrCodeFormatBinary = 1 << 2    /**< Binary data */
} ;
typedef TSXQrCodeFormat TSXQrCodeFormatSet;

/**
 * Represents a qr code result.
 */
@interface TSXQrCodeResult : NSObject { }

@property (readonly) NSString* _Null_unspecified qrCode;

@property (readonly) TSXQrCodeFormat qrCodeFormat;

+(TSXQrCodeResult* _Nonnull) createQrCodeResultWithQrCode:(NSString* _Nonnull)qrCode qrCodeFormat:(TSXQrCodeFormat)qrCodeFormat;
@end

/**
 * A response to scan qr code action. The object represents the response sent from the client
 * to the SDK when asked to display a scan qr code screen.
 *
 * \ingroup sdkProvided
 */
@interface TSXScanQrCodeInput : TSXInputResponseType { }

/**
 * An object representing scanned qr code.
 */
@property () TSXQrCodeResult* _Null_unspecified qrCodeResult;

/**
 * Create a ScanQrCodeInput object with a specified qr code value.
 *
 * @param qrCodeResult Initial value for the qrCodeResult attribute.
 */
+(TSXScanQrCodeInput* _Nonnull) createScanQrCodeInputWithQrCodeResult:(TSXQrCodeResult* _Nonnull)qrCodeResult;
@end

/**
 * The result of a JSON processing callback. This object is returned by a client implementation of UIHandler in
 * response to an SDK request to process JSON data as part of handling of a JSON Data action.
 * The object encodes a selection whether policy processing should continue or abort -- allowing JSON processing
 * code to halt policy evaluation.
 *
 * \ingroup sdkProvided
 */
@interface TSXJsonDataProcessingResult : NSObject { }

/**
 * Indicates whether policy execution should continue. When set to true -- policy execution will continue after this
 * JsonDataProcessingResult is returned to the SDK. When set to false -- policy execution will abort at that time,
 * with a AuthenticationErrorCode#UserCanceled code.
 */
@property () BOOL continueProcessing;

/**
 * Create a JsonDataProcessingResult.
 *
 * @param continueProcessing Initial value for the continueProcessing attribute.
 */
+(TSXJsonDataProcessingResult* _Nonnull) createWithContinueProcessing:(BOOL)continueProcessing;
@end

/** \enum TSXRedirectResponseType
*
 * Type of redirect handling response. Defines how the multi-policy flow should be continue after current
 * policy completion and having a redirection to another policy.
 *
 * \ingroup sdkProvided
 */
typedef NS_OPTIONS(NSUInteger, TSXRedirectResponseType) {
   RedirectResponseTypeRedirectToPolicy = 1 << 0    /**< Continue to redirection target policy */,
   RedirectResponseTypeCancelRedirect = 1 << 1    /**< Quit at current policy without proceeding to next policy */
} ;
typedef TSXRedirectResponseType TSXRedirectResponseTypeSet;

/**
 * A response to a redirect handling request. This object represents the response sent from the client
 * to the SDK when asked to confirm redirect, complete without redirect or abort with error.
 *
 * \ingroup sdkProvided
 */
@interface TSXRedirectInput : NSObject { }

/**
 * The response type, if this object represents a control request.
 */
@property () TSXRedirectResponseType redirectResponse;

/**
 * Optional additional parameters to use instead of those provided in the server request.
 */
@property () NSDictionary * _Nullable additionalParametersOverride;

/**
 * Create a RedirectInput object with a specified redirectResponse value.
 *
 * @param redirectResponse Initial value for the redirectResponse attribute.
 */
+(TSXRedirectInput* _Nonnull) createWithRedirectResponse:(TSXRedirectResponseType)redirectResponse;
@end

/** \enum TSXRedirectType
*
 * Type of redirect by policy invocation options in SDK API. See uiHandler#handlePolicyRedirect use case.
 */
typedef NS_OPTIONS(NSUInteger, TSXRedirectType) {
   RedirectTypeRedirectTypeBind = 1 << 0    /**< Next policy device bind policy - TransmitSDKXm#bind*/,
   RedirectTypeRedirectTypeAuthenticate = 1 << 1    /**< Next policy is a session starting policy invoked with TransmitSDKXm#authenticate */,
   RedirectTypeRedirectTypeBindOrAuthenticate = 1 << 2    /**< Next policy is a session starting policy invoked with TransmitSDKXm#bind or TransmitSDKXm#authenticate according to device state. */,
   RedirectTypeRedirectTypeInvokePolicy = 1 << 3    /**< Next policy is of general form invoked with TransmitSDKXm#invokePolicy */
} ;
typedef TSXRedirectType TSXRedirectTypeSet;

/** \enum TSXFormControlRequest
*
 * Represents the type of #FormInput control request, as input from a form
 * session's promiseInput call. */
typedef NS_OPTIONS(NSUInteger, TSXFormControlRequest) {
   FormControlRequestSubmit = 1 << 0    /**< This is a request to submit the jsonData attribute for the form. */,
   FormControlRequestAbort = 1 << 1    /**< This is a request to abort the policy executing the form action. */,
   FormControlRequestEscape = 1 << 2    /**< This is a request to escape the form action. */
} ;
typedef TSXFormControlRequest TSXFormControlRequestSet;

/**
 * A form input response carrying a JSON or a cancellation request.
 * When this object is returned via promiseFormInput#complete() the SDK will assert the next step of the form or
 * abort the current action.
 */
@interface TSXFormInput : NSObject { }

/**
 Json provided by the the UI to the form.
 */
@property () NSDictionary * _Null_unspecified jsonData;

/**
 * Input type -- indicates whether this is an abort request, or a submit request.
 */
@property () TSXFormControlRequest controlRequest;

/**
 * An escape request, if this object is signalling a request to invoke an escape path in the journey.
 */
@property () TSXActionEscapeRequest* _Null_unspecified actionEscapeRequest;

/**
 * Create a FormInput with a Submit control request, and the provided submission data.
 *
 * @param jsonData Initial value for the jsonData attribute.
 */
+(TSXFormInput* _Nonnull) createFormInputSubmissionRequestWithJsonData:(NSDictionary * _Nonnull)jsonData;

/**
 * Create a FormInput with an Abort control request
 */
+(TSXFormInput* _Nonnull) createFormCancellationRequest;

/**
 * Create a FormInput that encodes a request to escape the action
 *
 * @param actionEscape The escape option to signal
 * @param escapeParams Additional parameters to pass to the journey when escaping.
 */
+(TSXFormInput* _Nonnull) createEscapeRequestWithActionEscape:(TSXActionEscapeOption* _Nonnull)actionEscape escapeParams:(NSDictionary * _Nullable)escapeParams;
@end

/**
 * An interface for managing an form UI session. When the SDK needs to show form, it first creates an
 * form UI session using the application-provided UIHandler. The application then constructs an object implementing
 * this interface, and the SDK invokes callback on this session interface to manage the session lifecycle and
 * interact with the application through the course of the form session.
 *
 * Form session ends when the SDK asks to end it.
 *
 * The session lifecycle always begins with a call to startSession, done by the SDK shortly after the session object
 * is created. With startSession the session receives the clientContext for the SDK operation invocation within
 * which the session is created, and the actionContext describing the policy action, if any, that triggered this session
 * creation.
 * promiseFormInput is called right after startSession.
 *
 * After promiseFormInput asyncly returns the SDK will trigger a call to onContinue,onError or endSession, depending on the data sent and the classifiers defined in Management UI server.
 * Calling promiseFormInput will trigger endSession when a fatal error occurs, or when the form is done.
 * In case of a fatal error, the SDK will call UIHandler handlePolicyRejection after calling endSession.
 *
 * \ingroup clientProvided
 */
@interface TSXUIFormSession : NSObject { }

/**
 * Called to start the form UI session. This is the first function invoke on the session by the SDK.
 * Its purpose is to setup the UI and associate it with the clientContext of the current running action.
 *
 * Implementations should prepare the UI for interaction with the form -- typically (but not necessarily)
 * presenting new UI elements on screen and recording the clientContext.
 *
 * @param clientContext The clientContext for the SDK operation invocation for which this callback is invoked.
 * @param actionContext Information on the policy action currently executing, within which this callback is invoked. This is optional since session may be invoked outside the scope of an action.
 */
-(void)startSessionWithClientContext:(NSDictionary * _Nullable)clientContext actionContext:(TSXPolicyAction* _Nullable)actionContext;

/**
 * End the form session.
 *
 * Implementations should update the UI to reflect the fact that the current authentication session is no longer
 * active; e.g by tearing down UI elements that were setup to collect input for this session.
 */
-(void)endSession;

/**
 * Notify the session that the form processing backend has requested that form interaction will continue to another stage.
 * This method can be multiple times. Each time promiseFormInput().complete() and the response calls for 'continue'.
 * Implementation should update the UI to present the form data received from the server.
 *  @param payload containing the new data received as JSON.
 */
-(void)onContinueWithPayload:(NSDictionary * _Nullable)payload;

/**
 * Notify the session that the form processing backend has requested that an error in form processing will be reported to the user.
 * This method can be multiple times. Each time promiseFormInput.complete() and the response calls for 'continue'.
 * Implementation should update the UI to present the form error received from the server.
 *  @param payload containing the new data received as JSON.
 */
-(void)onErrorWithPayload:(NSDictionary * _Nullable)payload;

/**
 * Collect input from the session. This function is invoked by the SDK when it wishes to collect input from the
 * form UI. This will first be invoked right after startSession, and is called again after onContinue and onError.
 * @param handler Handler to receive asynchronous results. First argument -- return: A promise object. On successful result, returns: FromInput holding Json object.
 */
-(void)promiseFormInputAsynchronouslyWithHandler:(void (^ _Nonnull)(TSXFormInput* _Nonnull))handler;
@end

/** \enum TSXPromotionControlRequest
*
 * Represents a control request from a UI promotion session, asking to continue or dismiss the promotion flow.
 *
 * \ingroup sdkProvided
 */
typedef NS_OPTIONS(NSUInteger, TSXPromotionControlRequest) {
   PromotionControlRequestSkip = 1 << 0    /**< Cancel the promotion. Does not affect the rest of the authentication process. */,
   PromotionControlRequestAbort = 1 << 1    /**< Abort the authentication process altogether, returning an error from the SDK invocation */,
   PromotionControlRequestContinue = 1 << 2    /**< Continue promotion by calling the authenticators list via UIPromotionSession#setAuthenticatorsList */
} ;
typedef TSXPromotionControlRequest TSXPromotionControlRequestSet;

/**
 * Communicates either an input response or control response from an promotion UI session to the SDK.
 * This is a container that can contain either an AuthenticatorDescription object **or** a PromotionControlType object.
 *
 * \ingroup sdkProvided
 */
@interface TSXPromotionInput : NSObject { }

/**
 * Is this a promotion control request?
 *
 * @return true if this object contains a promotion control request (obtained through the controlRequest property), false if it contains an authenticator description (obtained through the description property)
 */
-(BOOL)isControlRequest;

/**
 * The control request, if this object represents a control request.
 */
@property () TSXPromotionControlRequest controlRequest;

/**
 * The authenticator description, if this object represents an authenticator selection request.
 */
@property () TSXAuthenticatorDescription* _Null_unspecified selectedAuthenticator;

/**
 * The selected escape option, if this object represents an escape option request.
 */
@property () TSXActionEscapeRequest* _Null_unspecified actionEscapeRequest;

/**
 * Create a PromotionControlRequest object representing a control request.
 *
 * @param controlRequest the PromotionControlRequest to represent in the created object.
 */
+(TSXPromotionInput* _Nonnull) createControlResponseWithControlRequest:(TSXPromotionControlRequest)controlRequest;

/**
 * Create a PromotionInput that encodes a request to escape the action
 *
 * @param actionEscape The escape option to signal
 * @param escapeParams Additional parameters to pass to the journey when escaping.
 */
+(TSXPromotionInput* _Nonnull) createEscapeRequestWithActionEscape:(TSXActionEscapeOption* _Nonnull)actionEscape escapeParams:(NSDictionary * _Nullable)escapeParams;

/**
 * Create a PromotionInput object representing an authenticator selection.
 *
 * @param selectedAuthenticator the AuthenticatorDescription to represent in the created object.
 */
+(TSXPromotionInput* _Nonnull) createAuthenticatorDescriptionWithSelectedAuthenticator:(TSXAuthenticatorDescription* _Nonnull)selectedAuthenticator;
@end

/**
 * An interface for managing an promotion UI session. When the SDK needs to show promotion, it first creates an
 * form UI session using the application-provided UIHandler. The application then constructs an object implementing
 * this interface, and the SDK invokes callback on this session interface to manage the session lifecycle and
 * interact with the application through the course of the form session.
 *
 * Promotion session ends when the SDK asks to end it.
 *
 * The session lifecycle always begins with a call to startSession, done by the SDK shortly after the session object
 * is created. With startSession the session receives the clientContext for the SDK operation invocation within
 * which the session is created, and the actionContext describing the policy action, if any, that triggered this session
 * creation.
 * promptIntroduction is called right after startSession.
 *
 * After promptIntroduction asyncly returns the SDK will trigger a call to setPromotedAuthenticators or endSession, depending on the PromotionControlRequest provided.Returning Abort or Skip will trigger endSession, Continue will trigger setAuthenticatorsList.
 * After setPromotedAuthenticators asyncly returns the SDK will trigger setPromotedAuthenticators again or endSession.
 * If AuthenticatorDescription was provided, the SDK will either trigger endSession if all promotion conditions were met, or setPromotedAuthenticators to offer registering other authenticators.
 * If PromotionControlRequest of Abort or Skip will be provided, the SDK will trigger endSession.
 *
 * \ingroup clientProvided
 */
@interface TSXUIPromotionSession : NSObject { }

/**
 * Called to start the promotion UI session. This is the first function invoke on the session by the SDK.
 * Its purpose is to setup the UI and associate it with the clientContext of the current running action.
 *
 * Implementations should prepare the UI for interaction with the promotion -- typically (but not necessarily)
 * presenting new UI elements on screen and recording the clientContext.
 *
 * @param clientContext The clientContext for the SDK operation invocation for which this callback is invoked.
 * @param actionContext Information on the policy action currently executing, within which this callback is invoked. This is optional since session may be invoked outside the scope of an action.
 */
-(void)startSessionWithClientContext:(NSDictionary * _Nullable)clientContext actionContext:(TSXPolicyAction* _Nullable)actionContext;

/**
 * End the promotion session.
 *
 * Implementations should update the UI to reflect the fact that the current authentication session is no longer
 * active; e.g by tearing down UI elements that were setup to collect input for this session.
 */
-(void)endSession;

/**
 * Get user response to promotion screen. This callback is invoked by the SDK to execute a confirmation screen
 * policy action.
 * The callback is expected to present a some UI to the user, collect its input and return it asynchronously to the SDK as a PromotionControlRequest object.
 *
 * @param title Title of promotion screen to display.
 * @param text  Text to display in promotion screen.
 * @param continueText  Label for a promotion button (pressing this button will cause policy execution to continue)
 * @param cancelText Label for a cancellation button (pressing this button will cause policy execution to skip)
 * @param handler Handler to receive asynchronous results. First argument -- return: A promise object. On successful result, returns: A ConfirmationInput object encoding user choice. For the ConfirmationInput#userChoice property, a value of "0" means continue and a value of "1" means cancel.
 *
 */
-(void)promptIntroductionWithTitle:(NSString* _Nonnull)title text:(NSString* _Nonnull)text continueText:(NSString* _Nonnull)continueText cancelText:(NSString* _Nonnull)cancelText asynchronouslyWithHandler:(void (^ _Nonnull)(TSXPromotionInput* _Nonnull))handler;

/**
 * Called to provide an updated list of unregistered authenticators. The implementation is expected to choose authenticator to register.
 *
 * @param options list of unregistered authenticators for the current session.
 * @param handler Handler to receive asynchronous results. First argument -- return: On successful result, returns: PromotionInput encoding either an authenticator to register  or a control request to end session.
 */
-(void)setPromotedAuthenticatorsWithOptions:(NSArray<TSXAuthenticatorDescription*> * _Nonnull)options asynchronouslyWithHandler:(void (^ _Nonnull)(TSXPromotionInput* _Nonnull))handler;
@end

/**
 * An interface for managing scan qr session. When the SDK needs to show scan QR action, it first creates scan QR
 * UI session using the application-provided UIHandler. The application then constructs an object implementing
 * this interface, and the SDK invokes callback on this session interface to manage the session lifecycle and
 * interact with the application through the course of the form session.
 *
 * Scan QR session ends when the SDK asks to end it.
 *
 * The session lifecycle always begins with a call to startSession, done by the SDK shortly after the session object
 * is created. With startSession the session receives the clientContext for the SDK operation invocation within
 * which the session is created, and the actionContext describing the policy action, if any, that triggered this session
 * creation.
 * promptIntroduction is called right after startSession.
 *
 * After promptIntroduction asyncly returns the SDK will trigger a call to setPromotedAuthenticators or endSession, depending on the PromotionControlRequest provided.Returning Abort or Skip will trigger endSession, Continue will trigger setAuthenticatorsList.
 * After setPromotedAuthenticators asyncly returns the SDK will trigger setPromotedAuthenticators again or endSession.
 * If AuthenticatorDescription was provided, the SDK will either trigger endSession if all promotion conditions were met, or setPromotedAuthenticators to offer registering other authenticators.
 * If PromotionControlRequest of Abort or Skip will be provided, the SDK will trigger endSession.
 *
 * \ingroup clientProvided
 */
@interface TSXScanQrSession : NSObject { }

/**
 * Called to start the scan qr session. This is the first function invoke on the session by the SDK.
 * Its purpose is to setup the UI and associate it with the clientContext of the current running action.
 *
 * @param clientContext The clientContext for the SDK operation invocation for which this callback is invoked.
 * @param actionContext Information on the policy action currently executing, within which this callback is invoked. This is optional since session may be invoked outside the scope of an action.
 */
-(void)startSessionWithClientContext:(NSDictionary * _Nullable)clientContext actionContext:(TSXPolicyAction* _Nullable)actionContext;

/**
 * End the scan qr session.
 *
 * Implementations should update the UI to reflect the fact that the current session is no longer
 * active; e.g by tearing down UI elements that were setup to collect input for this session.
 */
-(void)endSession;

/**
 * Get user response to scan QR screen. This callback is invoked by the SDK to execute a scan qr code
 * policy action.
 * The callback is expected to present scan qr code UI to the user, collect its input and return it asynchronously to the SDK as a ScanQrCodeInput object.
 *
 * @param instructions text to display in scan QR code screen
 * @param handler Handler to receive asynchronous results. First argument -- return: InputOrControlResponse encoding either a qr code input or a contorl request with user cancellation
 *
 */
-(void)getScanQrResponseWithInstructions:(NSString* _Nonnull)instructions qrCodeFormat:(TSXQrCodeFormat)qrCodeFormat asynchronouslyWithHandler:(void (^ _Nonnull)(TSXInputOrControlResponse<TSXScanQrCodeInput*>* _Nonnull))handler;
@end

/** \enum TSXDeviceStatus
*
 * Status of a device -- indicates whether a device is available for use and how recently it was used.
 *
 * \ingroup sdkProvided
 */
typedef NS_OPTIONS(NSUInteger, TSXDeviceStatus) {
   DeviceStatusRecentlyUsed = 1 << 0    /**< Device was recently used */,
   DeviceStatusNoRecentActivity = 1 << 1    /**< Device wasn't recently used */,
   DeviceStatusLongInactivity = 1 << 2    /**< Device has been inactive for a long period of time */,
   DeviceStatusDisabled = 1 << 3    /**< Device disabled and cannot be used for login etc */,
   DeviceStatusRemoved = 1 << 4    /**< Device has just been removed from service, need to login to re-add the device */
} ;
typedef TSXDeviceStatus TSXDeviceStatusSet;

/**
 * Information about a device group
 */
@interface TSXDeviceGroup : NSObject { }

/**
 * Group identifier, can be used to invoke operations on server management API.
 */
@property (readonly) NSString* _Null_unspecified id;

/**
 * Human readable group name as defined by the administrator in the Transmit management console.
 */
@property (readonly) NSString* _Null_unspecified name;
@end

/**
 * Human readable location attributes
 */
@interface TSXLocationAttributes : NSObject { }

@property (readonly) NSString* _Null_unspecified city;

@property (readonly) NSString* _Null_unspecified state;

@property (readonly) NSString* _Null_unspecified country;
@end

/**
 * A push request payload that was triggered by identifying a device using DeviceManagementAction#Identify. This object is
 * created based on data sent via a push notification, and used by the application to display a push notification.
 *
 * \ingroup sdkProvided
 */
@interface TSXIdentifyDevicePushRequestPayload : TSXPushRequestPayload { }

/**
 * Return the user ID specified by this mobile approve push request payload, if any.
 */
-(NSString* _Null_unspecified)userId;
@end

/**
 * Information about a device known to the Transmit platform.
 *
 * \ingroup sdkProvided
 */
@interface TSXDeviceInfo : NSObject { }

/**
 * The Transmit Logical Device ID for the device.
 */
@property (readonly) NSString* _Null_unspecified deviceId;

/**
 * The Transmit Device Hardware ID for the device.
 */
@property (readonly) NSString* _Null_unspecified deviceHwId;

/**
 * Auto-generated or given name of device
 */
@property (readonly) NSString* _Null_unspecified name;

/**
 * Status of the device
 */
@property (readonly) TSXDeviceStatus status;

/**
 * Last device bind time
 */
@property (readonly) NSDate * _Null_unspecified lastBind;

/**
 * Last device access time
 */
@property (readonly) NSDate * _Null_unspecified lastAccess;

/**
 * Location of last access
 */
@property (readonly) CLLocationCoordinate2D lastAccessLocation;

@property (readonly) TSXLocationAttributes* _Null_unspecified lastAccessLocationAttributes;

/**
 * Time of device registration
 */
@property (readonly) NSDate * _Null_unspecified registered;

/**
 * Model of device
 */
@property (readonly) NSString* _Null_unspecified model;

/**
 * Type of OS run by the device
 */
@property (readonly) NSString* _Null_unspecified osType;

/**
 * Version of OS run by the device
 */
@property (readonly) NSString* _Null_unspecified osVersion;

/**
 * Number of times device was used
 */
@property (readonly) long useCount;

/**
 * Is push supported by this device?
 */
@property (readonly) BOOL pushSupported;

/**
 * Is this object describing the current device?
 */
@property (readonly) BOOL isCurrent;

/**
 * Groups that this device belongs to
 */
@property (readonly) NSArray<TSXDeviceGroup*> * _Null_unspecified groups;
@end

/** \enum TSXDeviceManagementAction
*
 * An action available on a device in a device management session.
 *
 * \ingroup sdkProvided
 */
typedef NS_OPTIONS(NSUInteger, TSXDeviceManagementAction) {
   DeviceManagementActionRemove = 1 << 0    /**< Remove a registered device */,
   DeviceManagementActionIdentify = 1 << 1    /**< Identify a device */,
   DeviceManagementActionRename = 1 << 2    /**< Rename a device */
} ;
typedef TSXDeviceManagementAction TSXDeviceManagementActionSet;

/**
 * Represents a single device for management within a device management session.
 *
 * \ingroup sdkProvided
 **/
@interface TSXManagedDevice : NSObject { }

/**
 * Information about the managed device represented by this ManagedDevice.
 */
@property (readonly) TSXDeviceInfo* _Null_unspecified info;

/**
 * List of actions available within this session on this device.
 */
@property (readonly) TSXDeviceManagementActionSet availableActions;
@end

/**
 * A set of services for conducting a device management session. An implementation of this object is passed to the
 * application to allow it to carry out device management operations.
 *
 * After successful completion of each of these services, the list of devices passed to application at the beginning of the
 * session may change; this will be done via a call to UIDeviceManagementSession#setSessionDevicesList.
 *
 * \ingroup sdkProvided
 */
@interface TSXDeviceManagementSessionServices : NSObject { }

/**
 * UIContext contains ui utils.
 */
@property (readonly) TSXUIContext* _Null_unspecified uiContext;

/**
 * Remove a managed device.
 *
 * Calling this on the current device will cause an error to be raised. To delete the current device use
 * #removeCurrentDeviceAndFinishSession.
 *
 * @param device Device to operate on.
 * @param clientContext An object map for client use. This map will be passed to all callbacks invoked in the context of this invocation.
 * @param handler Handler to receive asynchronous results. First argument -- return: true to indicate successful completion.
 *
 */
-(void)removeDeviceWithDevice:(TSXManagedDevice* _Nonnull)device clientContext:(NSDictionary * _Nullable)clientContext asynchronouslyWithHandler:(void (^ _Nonnull)(BOOL, TSXAuthenticationError* _Nullable))handler;

/**
 * Identify a managed device. Trigger sending a push notification to the device.
 *
 * @param device Device to operate on.
 * @param clientContext An object map for client use. This map will be passed to all callbacks invoked in the context of this invocation.
 * @param handler Handler to receive asynchronous results. First argument -- return: true to indicate successful completion.
 *
 */
-(void)identifyDeviceWithDevice:(TSXManagedDevice* _Nonnull)device clientContext:(NSDictionary * _Nullable)clientContext asynchronouslyWithHandler:(void (^ _Nonnull)(BOOL, TSXAuthenticationError* _Nullable))handler;

/**
 * Change the name of a registered managed device.
 *
 * @param device Device to operate on.
 * @param newName New name for device.
 * @param clientContext An object map for client use. This map will be passed to all callbacks invoked in the context of this invocation.
 * @param handler Handler to receive asynchronous results. First argument -- return: true to indicate successful completion.
 *
 */
-(void)renameDeviceWithDevice:(TSXManagedDevice* _Nonnull)device newName:(NSString* _Nonnull)newName clientContext:(NSDictionary * _Nullable)clientContext asynchronouslyWithHandler:(void (^ _Nonnull)(BOOL, TSXAuthenticationError* _Nullable))handler;

/**
 * Request to refresh devices list from the server. This will asyncly return after device list is updated
 * from the server and delivered to the session via a call to UIDeviceManagementSession#setSessionDevicesList.
 *
 * @param handler Handler to receive asynchronous results. First argument -- return: true to indicate successful operation.
 */
-(void)requestRefreshDevicesAsynchronouslyWithHandler:(void (^ _Nonnull)(BOOL, TSXAuthenticationError* _Nullable))handler;

/**
 * Remove the current device from the server, and then finish the current device management session,
 * clear the current logged in session and clear the current user data from the device -- completing
 * an orderly and clean device unregistration.
 *
 
 * This call will asynchronously return once the server request to remove the current device completes.
 * After this asynchronously returns, the same sequence of calls that occurs on a call to #finishSession
 * executes, but prior to the #startDeviceManagementSession asyncorhonus call returning the session will be
 * logged off and the current user's persistent data will be cleared.
 *
 * @param clientContext An object map for client use. This map will be passed to all callbacks invoked in the context of this invocation.
 * @param handler Handler to receive asynchronous results. First argument -- return: true to indicate successful completion.
 *
 */
-(void)removeCurrentDeviceAndFinishSessionWithClientContext:(NSDictionary * _Nullable)clientContext asynchronouslyWithHandler:(void (^ _Nonnull)(BOOL, TSXAuthenticationError* _Nullable))handler;

/**
 * Request to end the session. This will cause endSession to be called on the UIDeviceManagementSession.
 */
-(void)finishSession;
@end

/**
 * An interface for managing a device management UI session. When the SDK is required to allow the user to manage
 * his devices, it first creates a device management UI session using the application-provided UIHandler. The
 * application then constructs an object implementing this interface, and the SDK invokes callback on this session
 * interface to manage the session lifecycle and interact with the application through the course of the device management
 * session.
 *
 * The session lifecycle always begins with a call to startSession, done by the SDK shortly after the session object
 * is created.  With startSession the session receives the clientContext for the SDK operation invocation within
 * which the session is created, and the actionContext describing the policy action, if any, that triggered this session
 * creation. Also, the SDK passes a DeviceManagemenetSessionServices object to this session, using which the
 * application can invoke operations on devices or the session itself.
 *
 * A device management session operates on a list of devices registered for the user. This list may be updated during session
 * lifetime. When this happens, UIDeviceManagementSession#setSessionDevicesList is invoked by the SDK. This happens
 * right before the session is started and between invocation of device services made by the application (see below).
 *
 * Once it has a list of devices and the services provider, the client may invoke operations on devices. Each device
 * in the list of devices is accompanied with a specification of which management operations are available
 * for it. The application may invoke services in the deviceManagementSession object provided on session start
 * to actually invoke these operations. Note that operations may only be invoked on device objects provided to this session through
 * #setSessionDevicesList.
 *
 * When the application decides the device management session is complete (e.g the user asked to close an device management UI), it
 * invokes the DeviceManagementSessionServices#finishSession callback. When either the SDK or the application decide
 * to finish the session, the SDK will invoke endSession().
 *
 * The application may also terminate the device management sesion by removing the current device. This is done by
 * invoking removeCurrentDeviceAndFinishSession, and will cause removal of the device in the server followed by termination
 * of the device management session, logging out of the current user session and finally clearing the user data from the SDK.
 *
 * \ingroup clientProvided
 */
@interface TSXUIDeviceManagementSession : NSObject { }

/**
 * Called to provide an updated list of managed devices to the session. The implementation is expected to refresh
 * the UI as needed to reflect the new list.
 *
 * @param devices Updated list of devices for the current session.
 */
-(void)setSessionDevicesList:(NSArray<TSXManagedDevice*> * _Nonnull)devices;

/**
 * Called to start the device management session. This is invoked by the SDK shortly after the session is created and
 * after the initial call to #setSessionDevicesList.
 *
 * The implementation is expected to setup the UI and associate it with the clientContext and actionContext
 * of the current running authentication action, as well keep a reference to the deviceManagementSessionServices
 * object to invoke it to perform operations on devices during the session.
 *
 * @param deviceManagementSessionServices An interface provided to the application for performing actions on devices and the session itself.
 * @param actionContext Information on the policy action currently executing, within which this callback is invoked. This is optional since session may be invoked outside the scope of an action.
 * @param clientContext The clientContext for the SDK operation invocation for which this callback is invoked.
 */
-(void)startSessionWithDeviceManagementSessionServices:(TSXDeviceManagementSessionServices* _Nonnull)deviceManagementSessionServices actionContext:(TSXPolicyAction* _Nullable)actionContext clientContext:(NSDictionary * _Nullable)clientContext;

/**
 * End the device management session.
 *
 * Implementations should update the UI to reflect the fact that the current device management session is no longer
 * active; e.g by tearing down UI elements that were setup to collect input for this session.
 */
-(void)endSession;
@end

/** \enum TSXAuthenticatorConfigurationAction
*
 * An action available on an authenticator in an authentication configuration session.
 *
 * \ingroup sdkProvided
 */
typedef NS_OPTIONS(NSUInteger, TSXAuthenticatorConfigurationAction) {
   AuthenticatorConfigurationActionRegister = 1 << 0    /**< Register an (unregistered) authenticator */,
   AuthenticatorConfigurationActionUnregister = 1 << 1    /**< Unregister a registered authenticator */,
   AuthenticatorConfigurationActionReregister = 1 << 2    /**< Re-register an already registered authenticator */
} ;
typedef TSXAuthenticatorConfigurationAction TSXAuthenticatorConfigurationActionSet;

/**
 * Represents a single authenticator for configuration within an authentication configuration session.
 *
 * \ingroup sdkProvided
 **/
@interface TSXConfigurableAuthenticator : NSObject { }

/**
 * Information about the authenticator represented by this ConfigurableAuthenticator.
 */
@property (readonly) TSXAuthenticatorDescription* _Null_unspecified description;

/**
 * List of actions available within this session on this authenticator.
 */
@property (readonly) TSXAuthenticatorConfigurationActionSet availableActions;
@end

/**
 * A set of services for conducting an authentication configuration session. An implementation of this object is
 * passed to the application to allow it to carry out operations relevant to authentication configuration.
 *
 * After successful completion of each of these services, the list of authenticators passed to the application
 * at the beginning of the session may change; the application will be notified of such changes through a all to
 * UIAuthenticationConfigurationSession#setAuthenticatorsList.
 *
 * Note that some operations may trigger additional UIHandler callbacks, e.g to initiate policy execution for
 * authenticating a registration request. Some of these may create other UI sessions (e.g for authenticators).
 *
 * \ingroup sdkProvided
 */
@interface TSXAuthenticationConfigurationSessionServices : NSObject { }

/**
 * UIContext contains ui utils.
 */
@property (readonly) TSXUIContext* _Null_unspecified uiContext;

/**
 * Register an authenticator. This call will initiate execution of a control flow to authenticate the registration.
 *
 * @param authenticator Authenticator to register.
 * @param clientContext An object map for client use. This map will be passed to all callbacks invoked in the context of this invocation.
 * @param handler Handler to receive asynchronous results. First argument -- return: AuthenticationResult for the policy executed as part of successful registration.
 *
 */
-(void)registerAuthenticatorWithAuthenticator:(TSXConfigurableAuthenticator* _Nonnull)authenticator clientContext:(NSDictionary * _Nullable)clientContext asynchronouslyWithHandler:(void (^ _Nonnull)(TSXAuthenticationResult* _Nullable, TSXAuthenticationError* _Nullable))handler;

/**
 * Re-register an already registered authenticator. This call will initiate execution of a control flow to
 * authenticate the registration.
 *
 * @param authenticator Authenticator to re-register.
 * @param clientContext An object map for client use. This map will be passed to all callbacks invoked in the context of this invocation.
 * @param handler Handler to receive asynchronous results. First argument -- return: AuthenticationResult for the policy executed as part of successful re-registration.
 *
 */
-(void)reregisterAuthenticatorWithAuthenticator:(TSXConfigurableAuthenticator* _Nonnull)authenticator clientContext:(NSDictionary * _Nullable)clientContext asynchronouslyWithHandler:(void (^ _Nonnull)(TSXAuthenticationResult* _Nullable, TSXAuthenticationError* _Nullable))handler;

/**
 * Unregister an authenticator. This call will initiate execution of a control flow to deregister the authenticator.
 *
 * @param authenticator Authenticator to unregister.
 * @param clientContext An object map for client use. This map will be passed to all callbacks invoked in the context of this invocation.
 * @param handler Handler to receive asynchronous results. First argument -- return: true to indicate successful completion.
 *
 */
-(void)unregisterAuthenticatorWithAuthenticator:(TSXConfigurableAuthenticator* _Nonnull)authenticator clientContext:(NSDictionary * _Nullable)clientContext asynchronouslyWithHandler:(void (^ _Nonnull)(BOOL, TSXAuthenticationError* _Nullable))handler;

/**
 * Request to refresh list of authenticators for this user from the server. This will asyncly return after
 * the list is updated from the server and delivered to the session via a call to
 * UIAuthenticationConfigurationSession#setAuthenticatorsList.
 *
 * @param handler Handler to receive asynchronous results. First argument -- return: true to indicate successful operation.
 */
-(void)requestRefreshAuthenticatorsAsynchronouslyWithHandler:(void (^ _Nonnull)(BOOL, TSXAuthenticationError* _Nullable))handler;

/**
 * Request to set an authenticator as the default authenticator.
 *
 * @param handler Handler to receive asynchronous results. First argument -- return: true to indicate succesful operation
 */
-(void)setDefaultAuthenticatorWithAuthenticator:(TSXConfigurableAuthenticator* _Nonnull)authenticator asynchronouslyWithHandler:(void (^ _Nonnull)(BOOL, TSXAuthenticationError* _Nullable))handler;

/**
 * Request to end the session. This will cause endSession to be called on the UIAuthenticationConfigurationSession
 * object representing the session bound to this services object.
 */
-(void)finishSession;
@end

/**
 * An interface for managing an authentication configuration UI session. When the SDK is required to start an
 * authentication configuration session, it first creates an authentication configuration UI session using the
 * application-provided UIHandler. The application then constructs an object implementing this interface, and
 * the SDK invokes callback on this session interface to manage the session lifecycle and interact with the
 * application through the course of the device authentication configuration session.
 *
 * Typically the authentication configuration session ends when the application asks to end it. Regardless of whether the
 * application or the SDK terminate the approval session, its endSession method is invoked.
 *
 * The session lifecycle always begins with a call to startSession, done by the SDK shortly after the session object
 * is created.  With startSession the session receives the clientContext for the SDK operation invocation within
 * which the session is created, and the actionContext describing the policy action, if any, that triggered this session
 * creation. Also, the SDK passes an AuthenticationConfigurationSessionServices object to this session, using which the
 * application can invoke operations on authenticators or the session itself.
 *
 * An authentication configuration session operates on a list of authenticators registered for the user. This list may
 * be updated during session lifetime. When this happens, UIAuthenticationConfigurationSession#setAuthenticatorsList is
 * invoked by the SDK. This happens right before the session is started and between invocation of
 * AuthenticationConfigurationSessionServices services made by the application (see below).
 *
 * Once it has a list of authenticators and the services provider, the application may invoke operations on devices.
 * Each device in the list of devices is accompanied with a specification of which operations are available
 * for it. The application may invoke services in the authenticationConfigurationSessionServices object provided on
 * session start to actually invoke these operations. Note that operations may only be invoked on authenticator
 * objects provided to this session through #setAuthenticatorsList.
 *
 * When the application decides the session is complete (e.g the user asked to close an authentication configuration
 * screen), it invokes the AuthenticationConfigurationSessionServices#finishSession callback. When either the SDK or
 * the application decide to finish the session, the SDK will invoke endSession().
 *
 * \ingroup clientProvided
 */
@interface TSXUIAuthenticationConfigurationSession : NSObject { }

/**
 * Called to provide an updated list of authenticators to configure to the session. The implementation is expected to refresh
 * the UI as needed to reflect the new list.
 *
 * @param authenticators Updated list of authenticators for configuration in the current session.
 */
-(void)setAuthenticatorsList:(NSArray<TSXConfigurableAuthenticator*> * _Nonnull)authenticators;

/**
 * Called to start the authentication configuration session. This is invoked by the SDK shortly after the session is created and
 * after the initial call to #setAuthenticatorsList.
 *
 * The implementation is expected to setup the UI and associate it with the clientContext and actionContext
 * of the current running authentication action, as well keep a reference to the authenticationConfigurationSessionServices
 * object to invoke it to perform operations on authenticators and the session itself during the session.
 *
 * @param authenticationConfigurationSessionServices An interface provided to the application for performing actions on authenticators and the session itself.
 * @param actionContext Information on the policy action currently executing, within which this callback is invoked. This is optional since session may be invoked outside the scope of an action.
 * @param clientContext The clientContext for the SDK operation invocation for which this callback is invoked.
 */
-(void)startSessionWithAuthenticationConfigurationSessionServices:(TSXAuthenticationConfigurationSessionServices* _Nonnull)authenticationConfigurationSessionServices actionContext:(TSXPolicyAction* _Nullable)actionContext clientContext:(NSDictionary * _Nullable)clientContext;

/**
 * End the authentication configuration session.
 *
 * Implementations should update the UI to reflect the fact that the current authentication configuration session
 * is no longer active; e.g by tearing down UI elements that were setup to collect input for this session.
 */
-(void)endSession;
@end

/** \enum TSXMobileApprovalStatus
*
 * The status of a mobile approval record.
 *
 * \ingroup sdkProvided
 */
typedef NS_OPTIONS(NSUInteger, TSXMobileApprovalStatus) {
   MobileApprovalStatusPending = 1 << 0    /**< Pending user's confirmation */,
   MobileApprovalStatusApproved = 1 << 1    /**< Approved */,
   MobileApprovalStatusDenied = 1 << 2    /**< Denied */,
   MobileApprovalStatusExpired = 1 << 3    /**< Request expired */
} ;
typedef TSXMobileApprovalStatus TSXMobileApprovalStatusSet;

/**
 * Contents of a mobile approval request
 *
 * \ingroup sdkProvided
 */
@interface TSXMobileApproval : NSObject { }

/**
 * Approval Identifier.
 */
@property (readonly) NSString* _Null_unspecified approvalId;

/**
 * Remote source that created the approval.
 * Transmit Management console refers to source as "Title 2".
 * Referred as "Title 2" by Transmit Server.
 */
@property (readonly) NSString* _Null_unspecified source;

/**
 * Approval title for the user.
 * Transmit Management console refers to source as "Title 1".
 */
@property (readonly) NSString* _Null_unspecified title;

/**
 * Approval text for the user.
 */
@property (readonly) NSString* _Null_unspecified details;

/**
 * Creation time.
 */
@property (readonly) NSDate * _Null_unspecified creationTime;

/**
 * Completion time (if completed)
 */
@property (readonly) NSDate * _Null_unspecified finishTime;

/**
 * Expiration time
 */
@property (readonly) NSDate * _Null_unspecified expiresAt;

/**
 * Mobile approval status.
 */
@property (readonly) TSXMobileApprovalStatus status;

/**
 * The application Id.
 */
@property (readonly) NSString* _Null_unspecified originAppId;

/**
 * The approval location
 */
@property (readonly) CLLocationCoordinate2D location;

/**
 * The origin device who request approve.
 */
@property (readonly) TSXTargetDeviceDetails* _Nullable originDevice;

/**
 * Additional custom params.
 */
@property (readonly) NSDictionary * _Null_unspecified customParams;

/** Returns true if the approal has expired, false otherwise. */
-(BOOL)isExpired;
@end

/** \enum TSXMobileApprovalAction
*
 * An action available on a mobile approval in a mobile approval session.
 *
 * \ingroup sdkProvided
 */
typedef NS_OPTIONS(NSUInteger, TSXMobileApprovalAction) {
   MobileApprovalActionApprove = 1 << 0    /**< Confirm an approval */,
   MobileApprovalActionDeny = 1 << 1    /**< Deny an approval */
} ;
typedef TSXMobileApprovalAction TSXMobileApprovalActionSet;

/**
 * Represents a single mobile approval for operation within a mobile approval session.
 *
 * \ingroup sdkProvided
 **/
@interface TSXManagedMobileApproval : NSObject { }

/**
 * Information about the approval represented by this ManagedMobileApproval.
 */
@property (readonly) TSXMobileApproval* _Null_unspecified approval;

/**
 * List of actions available within this session on this approval.
 */
@property (readonly) TSXMobileApprovalActionSet availableActions;
@end

/**
 * A set of operations for execution on approvals in a mobile approval session. An implementation of this object is passed to the
 * application to allow it to carry out approval management operations, in the call to the UIApprovalsSession#startSession
 * callback.
 *
 * After successful completion of each of these services, the list of approvals associated with the session may change;
 * this is communicated to the application through an invocation of UIApprovalSession#setSessionApprovalsList.
 *
 * \ingroup sdkProvided
 */
@interface TSXApprovalManagementSessionServices : NSObject { }

/**
 * UIContext contains ui utils.
 */
@property (readonly) TSXUIContext* _Null_unspecified uiContext;

/**
 * Confirm an approval.
 * This may trigger an authentication policy execution. If that's the case, all callbacks invoked as part of this
 * policy execution will have the clientContext parameter passed to this call passed to them.
 *
 * @param approval Approval to operate on.
 * @param clientContext A clientContext to use for all invocations run as part of this approval operation (e.g when there's
 * @param handler Handler to receive asynchronous results. First argument -- return: an AuthenticationResult object to indicate successful completion.
 * an approval policy associated with this operation).
 */
-(void)approveWithApproval:(TSXManagedMobileApproval* _Nonnull)approval clientContext:(NSDictionary * _Nullable)clientContext asynchronouslyWithHandler:(void (^ _Nonnull)(TSXAuthenticationResult* _Nullable, TSXAuthenticationError* _Nullable))handler;

/**
 * Deny an approval.
 *
 * @param approval Approval to operate on.
 * @param handler Handler to receive asynchronous results. First argument -- return: true to indicate succesful operation.
 */
-(void)denyWithApproval:(TSXManagedMobileApproval* _Nonnull)approval asynchronouslyWithHandler:(void (^ _Nonnull)(BOOL, TSXAuthenticationError* _Nullable))handler;

/**
 * Request to refresh approvals list from the server. This will asyncly return after approvals list is updated
 * from the server and delivered to the session via a call to UIApprovalsSession#setSessionApprovalsList.
 *
 * @param handler Handler to receive asynchronous results. First argument -- return: true to indicate successful operation.
 */
-(void)requestRefreshApprovalsAsynchronouslyWithHandler:(void (^ _Nonnull)(BOOL, TSXAuthenticationError* _Nullable))handler;

/**
 * Request to end the session. This will cause endSession to be called on the UIApprovalsSession.
 */
-(void)finishSession;
@end

/**
 * An interface for managing an approvals UI session. When the SDK needs to show approvals, it first creates an
 * approval UI session using the application-provided UIHandler. The application then constructs an object implementing
 * this interface, and the SDK invokes callback on this session interface to manage the session lifecycle and
 * interact with the application through the course of the approval session.
 *
 * Typically the approval session ends when the application asks to end it. Regardless of whether the application or
 * the SDK terminate the approval session, its endSession method is invoked.
 *
 * The session lifecycle always begins with a call to startSession, done by the SDK shortly after the session object
 * is created.  With startSession the session receives the clientContext for the SDK operation invocation within
 * which the session is created, and the actionContext describing the policy action, if any, that triggered this session
 * creation. Also, the SDK passes an ApprovalManagemenetSessionServices object to this session, using which the
 * application can invoke operations on approvals (such as deny, approve) or the session itself.
 *
 * An approvals session has an associated list of approvals managed by it. This list may be updated during session
 * lifetime. When this happens, UIApprovalsSession#setSessionApprovalsList is invoked by the SDK. This happens
 * right before the session is started and between invocation of approval services made by the application (see below).
 *
 * Once it has a list of approvals and the services providers, the client may invoke operations on approvals. Approvals
 * in the list include an indication of which operations are permitted on them. Note that some operations may trigger
 * additional UIHandler callbacks, e.g to initiate policy execution for an approval. Some of these may create other UI sessions
 * (e.g for authenticators). Between operation invocations, the SDK may update the approvals list for the session. Note
 * that the methods in ApprovalManagemenetSessionServices must only be invoked on approval objects from the current approval
 * list in the session.
 *
 * When the application decides the approvals session is complete (e.g the user asked to close an approvals UI), it
 * invokes the ApprovalManagementSessionServices#finishSession callback. When either the SDK or the application decide
 * to finish the session, the SDK will invoke endSession().
 *
 * \ingroup clientProvided
 */
@interface TSXUIApprovalsSession : NSObject { }

/**
 * Called to provide an updated list of managed approvals to the session. The implementation is expected to refresh
 * the UI as needed to reflect the new list.
 *
 * @param approvals Updated list of approvals for the current session.
 */
-(void)setSessionApprovalsList:(NSArray<TSXManagedMobileApproval*> * _Nonnull)approvals;

/**
 * Called to start the approvals session. This is invoked by the SDK shortly after the session is created and
 * after the initial call to #setSessionApprovalsList.
 *
 * The implementation is expected to setup the UI and associate it with the clientContext and actionContext
 * of the current running authentication action, as well keep a reference to the approvalManagementSessionServices
 * object to invoke it to perform operations on approvals during the session.
 *
 * @param approvalManagementSessionServices An interface provided to the application for performing actions on approvals and the session itself.
 * @param actionContext Information on the policy action currently executing, within which this callback is invoked. This is optional since session may be invoked outside the scope of an action.
 * @param clientContext The clientContext for the SDK operation invocation for which this callback is invoked.
 */
-(void)startSessionWithApprovalManagementSessionServices:(TSXApprovalManagementSessionServices* _Nonnull)approvalManagementSessionServices actionContext:(TSXPolicyAction* _Nullable)actionContext clientContext:(NSDictionary * _Nullable)clientContext;

/**
 * End the approvals session.
 *
 * Implementations should update the UI to reflect the fact that the current approvals session is no longer
 * active; e.g by tearing down UI elements that were setup to collect input for this session.
 */
-(void)endSession;
@end

/**
 * A response to ticket wait action. The object represents the response sent from the client
 * to the SDK when asked to display ticket ID and wait for an extranal scan or input. The
 * action in this case is a polling request, requiring the SDK to check if the
 * ticket is already consumed.
 *
 * There are two types of polling requests: long polling and short polling. A short polling request issues a request
 * to the server that returns immediately, either indicating that the ticket was consumed, or indicating
 * the ticket is still pending (in which case the session is not done and promiseInput will be invoked again).
 * Clients should request the SDK for short polling requests periodically (eg. once every 3 seconds). To do this,
 * a client would typically create a timer in a call to UITicketWaitSession#promiseInput, such that promiseInput
 * will return the polling request asynchronously after that period. With a polling period of P it may take up to
 * period P to detect that a ticket was consumed (or on average P/2).
 *
 * A long polling request indicates to the server that it should return a response as soon as a ticket is consumed
 * -- or after a timeout occurs (the timeout is configurable in the long polling request). Here a client would typically issue the
 * long polling request immediately on invocation of UITicketWaitSession#promiseInput, specifiying a timeout
 * period P. If ater period P the ticket is still pending, promiseInput will be invoked again (and will probably return the same
 * long polling request.)
 *
 * \ingroup sdkProvided
 */
@interface TSXTicketWaitInput : TSXInputResponseType { }

/**
 * Create a TicketWaitInput object representing a short polling request.
 */
+(TSXTicketWaitInput* _Nonnull) createPollRequest;

/**
 * Create a TicketWaitInput object representing a long polling request, with
 * given timeout in seconds.
 */
+(TSXTicketWaitInput* _Nonnull) createLongPollRequestWithTimeoutInSeconds:(long)timeoutInSeconds;
@end

@interface TSXTicketWaitInputPollRequest : TSXTicketWaitInput { }

/**
 * If nonzero -- timeout in seconds for long polling request to issue.
 * If zero -- this is a short poll request.
 */
@property () long pollingTimeout;
@end

typedef NS_OPTIONS(NSUInteger, TSXTicketIdFormat) {
   TicketIdFormatQr = 1 << 0    /**< QR code */,
   TicketIdFormatAlphanumeric = 1 << 1    /**< Alphanumeric code */
} ;
typedef TSXTicketIdFormat TSXTicketIdFormatSet;

/**
 * Represents ticket ID information, as provider by the server to the ticket-wait
 * action. This will typically be used to be rendered by the UI layer.
 *
 * \ingroup sdkProvided
 */
@interface TSXTicketId : NSObject { }

/**
 * The format of the proivided ticket ID. The format instructs how to use the value attribute.
 */
@property (readonly) TSXTicketIdFormat format;

/**
 * The value of the ticket ID, matching the provided format. For Qr format, this will
 * be a Base64 encoded JPEG. For Alphanumeric format this will be a simple string.
 */
@property (readonly) NSString* _Null_unspecified value;

/**
 * An alternative representaiton of the value. For Qr format, this will be the text
 * encoded by the QR code.
 */
@property (readonly) NSString* _Nullable valueAltRepresentation;
@end

/**
 * Represents the information from the server regarding the ticket wait action. This includes a
 * message to the user (title and text), and an optional ticket ID in some format. The UI layer should
 * display this when received.
 *
 * \ingroup sdkProvided
 */
@interface TSXTicketWaitingInformation : NSObject { }

@property (readonly) NSString* _Null_unspecified title;

@property (readonly) NSString* _Null_unspecified text;

@property (readonly) TSXTicketId* _Nullable ticketId;
@end

/**
 * An interface for managing a ticket wait session. When the SDK needs to wait for a ticket, it creates an instance
 * of this object and manages the action through services of this interface.
 *
 * The session lifecycle always begins with a call to startSession, done by the SDK shortly after the session object
 * is created through UIHandler#createTicketWaitSession. With startSession the session receives the clientContext for
 * the SDK operation invocation within which the session is created.
 *
 * Right before the session begins its lifecycle, the #setWaitingTicket call is invoked to provide informaton about
 * the ticket that's being waited upon (e.g the ticket ID and instructions to present to the user).
 *
 * After the call to startSession, the SDK will call promiseInput() -- providing the UI handler a chance to either
 * cancel the ticket wait operation by returning a proper control response, or ask to poll for ticket consumption.
 * As a result from a poll request, the sessino may end (if the ticket was consumed, or expired, etc.), or #promiseInput
 * may be invoked again -- providing the client with further opportunity to cancel or ask for polling. Typical client
 * implementations will, in response to promiseInput, either handle a cancel request from the UI or wait for a polling
 * period and then ask the SDK to poll for ticket status again.
 *
 * When the SDK can complete the ticket wait action (succesfuly or failing), it will invoke
 * endSession to signal that the authentication session has ended.
 *
 * \ingroup sdkProvided
 */
@interface TSXUITicketWaitSession : NSObject { }

/**
 * Sets the ticket information for the session
 */
-(void)setWaitingTicket:(TSXTicketWaitingInformation* _Nonnull)ticketWaitInfo;

/**
 * Called to start the ticket wait session. This is invoked by the SDK shortly after the session is created, and after
 * setWaitingTicket was called.
 *
 * The implementation is expected to setup the UI and associate it with the clientContext and actionContext.
 * It should display the information provided by setWaitingTicket
 *
 * @param actionContext Information on the policy action currently executing, within which this callback is invoked. This is optional since session may be invoked outside the scope of an action.
 * @param clientContext The clientContext for the SDK operation invocation for which this callback is invoked.
 */
-(void)startSessionWithActionContext:(TSXPolicyAction* _Nullable)actionContext clientContext:(NSDictionary * _Nullable)clientContext;

/**
 * The implementation is expected to set a poll timeout, and once ended return a TicketWaitInput.createPollRequest().
 *
 * @param handler Handler to receive asynchronous results. First argument -- return: InputOrControlResponse encoding either a ticket wait input or a control request. Only ControlRequestType#CancelAuthenticator is supprted as a control request.
 */
-(void)promiseInputAsynchronouslyWithHandler:(void (^ _Nonnull)(TSXInputOrControlResponse<TSXTicketWaitInput*>* _Nonnull))handler;

/**
 * End the wait for ticket session.
 *
 * Implementations should update the UI to reflect the fact that the current ticket wait session is no longer
 * active; e.g by stopping the polling mechanism, removing UI elements, etc.
 */
-(void)endSession;
@end

/**
 * Represents a header sent with a request or a response in the transport protocol.
 *
 * \ingroup sdkProvided
 */
@interface TSXTransportHeader : NSObject { }

/**
 * Name of header.
 */
@property () NSString* _Null_unspecified name;

/**
 * Value of header.
 */
@property () NSString* _Null_unspecified value;
@end

/**
 * Represents a request to be sent via the SDK transport.
 *
 * \ingroup sdkProvided
 */
@interface TSXTransportRequest : NSObject { }

/**
 * URL of request.
 */
@property () NSString* _Null_unspecified url;

/**
 * Request method
 */
@property () NSString* _Null_unspecified method;

/**
 * Request headers
 */
@property () NSArray<TSXTransportHeader*> * _Null_unspecified headers;

/**
 * Request body.
 */
@property () NSString* _Null_unspecified bodyJson;
@end

/**
 * Represents a response received via SDK transport.
 *
 * \ingroup sdkProvided
 */
@interface TSXTransportResponse : NSObject { }

/**
 * Response status code
 */
@property () long status;

/**
 * Response status reason
 */
@property () NSString* _Null_unspecified method;

/**
 * Response headers
 */
@property () NSArray<TSXTransportHeader*> * _Null_unspecified headers;

/**
 * Response body.
 */
@property () NSString* _Null_unspecified bodyJson;
@end

/**
 * An interface representing a transport for use by the SDK when communicating with the server.
 *
 * \ingroup clientProvided
 */
@interface TSXTransportProvider : NSObject { }

/**
 * Used to ask the transport provider to send a request to the server. Implementations of this interface should
 * send the request and return the response asynchronously.
 *
 * @param  request Request to send to the server.
 * @param handler Handler to receive asynchronous results. First argument -- return: A TransportResponse object representing the response from the server.
 */
-(void)sendRequestWithRequest:(TSXTransportRequest* _Nonnull)request asynchronouslyWithHandler:(void (^ _Nonnull)(TSXTransportResponse* _Nullable, TSXAuthenticationError* _Nullable))handler;
@end

/**
 * Client-provided callbacks for the SDK. This is the primary interface between the SDK and the client. An
 * implementation of this interface must be connected to the SDK by calling TransmitSDKXm#setUiHandler. Whenever
 * the SDK requires user or client input during operations such as policy invocation, it would invoke callbacks
 * implemented in this class.  The UI handler set at the time of policy invocation will be used throughout that
 * entire invocation, even if during invocation another call to TransmitSDKXm#setUiHandler replaces the UI handler.
 *
 * Most of the callbacks in this interface receive a clientContext. This is a map of objects provided by the client
 * when invoking an SDK operation, such as TransmitSDKXm#authenticate. The map of objects provided to the invocation
 * call will be passed back by the SDK in callback invocations that are initiated as part of this call. This makes the
 * clientContext parameter useful for relating callback invocations to the original invocations that initiated them.
 *
 * Callbacks used to receive input from the application, such as selectAuthenticator, follow an asynchronous
 * calling model where the input (such as a user selection or user input) is returned asynchronously after callback
 * invocation. This allows implementations of this interface to collect information from the user and return it
 * as the user becomes available, without blocking the input request call.
 *
 * The SDK communicates the commencement and termination of long-running background operations by invoking
 * startActivityIndicator and endActivityIndicator.
 *
 * Authentication actions are handled by invocations to selectAuthenticator, selectAuthenticatorFallbackAction,
 * controlOptionForCancellationRequestInSession, and the different authenticator session calls (of the form
 * createXXXXXAuthSession). Note that for authenticator sessions, the clientContext parameter is not passed to the
 * creation call but rather when UIAuthenticatorSession#startSession is invoked.
 *
 * Approvals, device management and authentication configuration menu are all handled by calls to
 * create[session-type]Session. Each of these calls creates a session for one of these activities, and through that
 * session object the SDK notifies the UI of changes to data that it presents, and receives requests to perform
 * actions available in the session.
 *
 * Simpler user input, such as responses to confirmation and information messages is obtained by the SDK invoking
 * calls such as getConfirmationInput, getInformationResponse.
 *
 * When an authentication policy includes a JSON processing action, processJsonData is invoked for handling the
 * provided JSON data.
 *
 * Rejection is signalled by a call to handlePolicyRejection.
 *
 * \ingroup clientProvided
 *
 */
@interface TSXUIHandler : NSObject { }

/**
 * Show activity indicator. This callback is invoked by the SDK to indicate that a long-running operation is starting.
 * When the long-running operation ends, endActivityIndicator will be invoked.
 *
 * For a given SDK operation invocation, two calls to startActivityIndicator may not be made without an
 * intermediate call to endActivityIndicator for the same operation. However, there are no constraints on calls
 * to these functions for different operation invocations.
 *
 * @param actionContext Information on the policy action currently executing, within which this callback is invoked. This is optional since background activity can be initiated before the first action or after the last action as well.
 * @param clientContext The clientContext for the SDK operation invocation for which this callback is invoked.
 */
-(void)startActivityIndicatorWithActionContext:(TSXPolicyAction* _Nullable)actionContext clientContext:(NSDictionary * _Nullable)clientContext;

/**
 * Hide activity indicator. This callback is invoked by the SDK to indicate that a long-running operation has ended.
 * When the long-running operation ends, endActivityIndicator will be invoked.
 *
 * For a given SDK operation invocation, two calls to startActivityIndicator may not be made without an
 * intermediate call to endActivityIndicator for the same operation. However, there are no constraints on calls
 * to these functions for different operation invocations.
 *
 * @param actionContext Information on the policy action currently executing, within which this callback is invoked. This is optional since background activity can be initiated before the first action or after the last action as well.
 * @param clientContext The clientContext for the SDK operation invocation for which this callback is invoked.
 */
-(void)endActivityIndicatorWithActionContext:(TSXPolicyAction* _Nullable)actionContext clientContext:(NSDictionary * _Nullable)clientContext;

/**
 * Invoked to notify the UI handler that a control flow is being cancelled programatically due to a call to
 * TransmitSDKXm#cancelCurrentRunningControlFlow. This is a good chance for the UI handler
 * to tear down all UI currently setup for the control flow.
 *
 * @param clientContext The clientContext for the SDK operation invocation for which this callback is invoked.
 */
-(void)controlFlowCancelledWithClientContext:(NSDictionary * _Nullable)clientContext;

/**
 * Invoked to notify the UI handler that a control flow is being started.
 *
 * @param clientContext The clientContext for the SDK operation invocation for which this callback is invoked.
 */
-(void)controlFlowStartingWithClientContext:(NSDictionary * _Nullable)clientContext;

/**
 * Invoked to notify the UI handler that a control flow has ended.
 *
 * @param error If the flow is ending with an error, this is the error causing it to end. If the flow has completed succesfully, this is null.
 * @param clientContext The clientContext for the SDK operation invocation for which this callback is invoked.
 */
-(void)controlFlowEndedWithError:(TSXAuthenticationError* _Nullable)error clientContext:(NSDictionary * _Nullable)clientContext;

/**
 * Invoked to notify the UI handler that a control flow action is being started.
 *
 * @param actionContext Information on the policy action being started.
 * @param clientContext The clientContext for the SDK operation invocation for which this callback is invoked.
 */
-(void)controlFlowActionStartingWithActionContext:(TSXPolicyAction* _Nullable)actionContext clientContext:(NSDictionary * _Nullable)clientContext;

/**
 * Invoked to notify the UI handler that a control flow action has ended.
 *
 * @param error If the action is ending with an error, this is the error causing it to end. If the action has completed succesfully, this is null.
 * @param actionContext Information on the policy action that has ended.
 * @param clientContext The clientContext for the SDK operation invocation for which this callback is invoked.
 */
-(void)controlFlowActionEndedWithError:(TSXAuthenticationError* _Nullable)error actionContext:(TSXPolicyAction* _Nullable)actionContext clientContext:(NSDictionary * _Nullable)clientContext;

/**
 * Unregister an authenticator session. This callback is invoked by the SDK as part of
 * an deregister action.
 *
 * The callback receives information about the to-be unregistered authenticator: description and is placeholder authenticator.
 * The callback is expected to return a result asynchronously as a UnregistrationInput object.
 *
 * @param authenticatorDescription The authenticator that will be unregistered.
 * @param isPlaceholder Is this authenticator of placeholder type or not.
 * @param actionContext Information on the policy action currently executing, within which this callback is invoked.
 * @param clientContext The clientContext for the SDK operation invocation for which this callback is invoked.
 * @param handler Handler to receive asynchronous results. First argument -- return: A UnregistrationInput object encoding user choice. For the UnregistrationInput#userChoice property, a value of "0" means unregister and a value of "1" means leave authenticator registered and fail policy.
 *
 */
-(void)handleAuthenticatorUnregistrationWithAuthenticatorDescription:(TSXAuthenticatorDescription* _Nonnull)authenticatorDescription isPlaceholder:(BOOL)isPlaceholder actionContext:(TSXPolicyAction* _Nullable)actionContext clientContext:(NSDictionary * _Nullable)clientContext asynchronouslyWithHandler:(void (^ _Nonnull)(TSXUnregistrationInput* _Nonnull))handler;

/**
 * Invoked by the SDK prior to invoking #selectAuthenticator, to allow the UI handler to specify whether
 * authenticators that are disabled (e.g locked or unregistered) should be included in the list of authenticators
 * provided to #selectAuthenticator.
 *
 * @param actionContext Information on the policy action currently executing, within which this callback is invoked.
 * @param clientContext The clientContext for the SDK operation invocation for which this callback is invoked.
 *
 * @return true if disabled authenticators should be included in the list provided to selectAuthenticator; false otherwise.
 */
-(BOOL)shouldIncludeDisabledAuthenticatorsInMenuWithActionContext:(TSXPolicyAction* _Nullable)actionContext clientContext:(NSDictionary * _Nullable)clientContext;

/**
 * Select an authenticator from a list of options. This callback is invoked by the SDK as part of processing an
 * action that requires selecting an authenticator among a list of authenticators. One example to such a scenario is
 * when executing a Primary or Secondary authentication action with more than one authenticator.
 *
 * An implementation may allow the user to select one of the authenticators or otherwise select by applying some
 * application-defined logic.
 *
 * The asynchronously-returned AuthenticatorSelectionResult can either encode cancellation
 * (AuthenticatorSelectionResult#createAbortRequest) or an authenticator selection
 * (AuthenticatorSelectionResult#createSelectionRequest or
 * AuthenticatorSelectionResult#createParameterizedSelectionRequest). In the case of a selection, the selected
 * AuthenticatorDescription must be the authenticator description of one of the options passed in the options
 * parameter. Moreover, it must be an object that is enabled -- by AuthenticatorDescription#enabled. Failure to
 * meet these requirements will trigger a failure in the originating SDK operation invocation with error
 * AuthenticationErrorCode#AppImplementation.
 *
 * The implementation may also provide, in additional to the selected authenticator, futher parameters to the
 * authentication process. This is done by returning an object constructed by calls to
 * AuthenticatorSelectionResult#createParameterizedSelectionRequest. The authentication parameters valid for this
 * call depend on the authenticator type. For example for a target-based authenticator such as OTP the parameters
 * may include a selection of an OTP target. Where an authenticator type supports parameters, the SDK may include
 * suggested parameters in the AuthenticationOption object. For example for target-based authenticators, the
 * AuthenticationOption#suggestedParameters property will include a list of possible targets and by returning one of
 * them in the AuthenticatorSelectionResult object the implementation may select the corresponding target (the
 * implementation may choose not to include any of the target parameters which will cause the SDK to ask for target
 * selection).
 *
 * @param options List of authenticators to select from.
 * @param actionContext Information on the policy action currently executing, within which this callback is invoked.
 * @param clientContext The clientContext for the SDK operation invocation for which this callback is invoked.
 * @param handler Handler to receive asynchronous results. First argument -- return: An AuthenticatorSelectionResult object signalling either a selected authenticator or request to abort the flow
 *
 */
-(void)selectAuthenticatorWithOptions:(NSArray<TSXAuthenticationOption*> * _Nonnull)options actionContext:(TSXPolicyAction* _Nullable)actionContext clientContext:(NSDictionary * _Nullable)clientContext asynchronouslyWithHandler:(void (^ _Nonnull)(TSXAuthenticatorSelectionResult* _Nonnull))handler;

/**
 * Select action to perform when authenticator fallback is needed. This callback is invoked by the SDK as
 * part of an authentication action (e.g Primary or Secondary authentication), when an authentication fallback
 * threshold is defined and the user has reached that failure threshold when attempting authentication.
 *
 * The SDK then invokes the fallback action callback to allow the application to decide how to respond to the suggestion
 * to fallback. The callback is provided with information on the valid responses for fallback based on current available
 * authenticators and the policy definition for acceptable fallbacks. If the policy defines a specific authenticator
 * to fallback to, this is also provided to the callback.
 *
 * An implementation may allow the user to select a fallback action or run application-specific logic to make that
 * decision.
 *
 * The asynchronously-returned AuthenticatorFallbackAction value must be one of the values listed in the validOptions
 * parameter. Failure to meet this requirement will trigger a failure in the originating SDK operation invocation.
 *
 * See AuthenticatorFallbackAction for the possible responses from this callback and their meaning.
 *
 * @param validOptions List of fallback response actions to choose form.
 * @param fallbackAuth For the AuthenticatorFallbackAction#Fallback value, the authenticator to which fallback will be done
 * @param session The UIAuthenticatorSession during which a fallback request has occurred.
 * @param actionContext Information on the policy action currently executing, within which this callback is invoked.
 * @param clientContext The clientContext for the SDK operation invocation for which this callback is invoked.
 * @param handler Handler to receive asynchronous results. First argument -- return: AuthenticatorFallbackAction describing the action to take.
 *
 */
-(void)selectAuthenticatorFallbackActionWithValidOptions:(TSXAuthenticatorFallbackActionSet)validOptions fallbackAuth:(TSXAuthenticatorDescription* _Nullable)fallbackAuth session:(TSXUIAuthenticatorSession<TSXInputResponseType*>* _Nonnull)session actionContext:(TSXPolicyAction* _Nullable)actionContext clientContext:(NSDictionary * _Nullable)clientContext asynchronouslyWithHandler:(void (^ _Nonnull)(TSXAuthenticatorFallbackAction))handler;

/**
 * Select control request action to perform in response to authentication cancellation request. This callback is
 * invoked by the SDK as part of an authentication action (e.g Primary or Secondary authentication), when authentication
 * cancellation is requested by the user (or the application). Authentication cancellation request is signalled to
 * the SDK by returning a control response with type ControlRequestType#CancelAuthenticator from
 * UIAuthenticatorSession#promiseInput. When the client returns this value, the SDK will normally respond by invoking
 * the controlOptionForCancellationRequestInSession callback to "trade" this control request with a control
 * request which is NOT ControlRequestType#CancelAuthenticator. The control request returned by this callback is
 * then used in lieu of the original control request returned from UIAuthenticatorSession#promiseInput.
 *
 * This callback allows (and in fact, encourages) applications to implement a uniform response to use cancellation
 * request regardless of the exact type of authentication session such a request is defined in.
 *
 * The SDK may decide to enable or disable some possible control request types when invoking this callback. The
 * enabled, or permissible, control request types are available in the validOptions parameter. The returned
 * control request must be one of these request types. Failure to meet this requirement will trigger a failure in
 * the originating SDK operation invocation.
 *
 * See ControlRequest for the possible responses from this callback and their meaning.
 *
 * @param validOptions List of control request types to choose form.
 * @param session The UIAuthenticatorSession during which a cancellation request has occurred.
 * @param handler Handler to receive asynchronous results. First argument -- return: ControlRequest describing the control request to use in lieu of the ControlRequestType#CancelAuthenticator
 *
 */
-(void)controlOptionForCancellationRequestInSessionWithValidOptions:(TSXControlRequestTypeSet)validOptions session:(TSXUIAuthenticatorSession<TSXInputResponseType*>* _Nonnull)session asynchronouslyWithHandler:(void (^ _Nonnull)(TSXControlRequest* _Nonnull))handler;

/**
 * Create an authenticator session for the Password authenticator. This callback is invoked by the SDK as part of
 * an authentication action (e.g Primary or Secondary authentication), when this authenticator needs to be invoked.
 *
 * The callback receives information about the current authentication session such as title, user-name and any
 * other constraints on the authentication session, and is expected to return an authenticator session object that
 * will be used by the SDK to manage the authentication process with that authenticator.
 *
 * Note that this call isn't supplied with a clientContext parameter, however the first call on the returned
 * authenticator session object, UIAuthenticatorSession#startSession, *is* supplied with this parameter.
 *
 * See UIAuthenticatorSession for a discussion of the authentication session lifecycle and sequence of calls
 * made on that object.
 *
 * The authenticator input type for Password authenticator sessions is PasswordInput, which encapsulates
 * the password input by the user.
 *
 * @param title Title of authentication action
 * @param username Username {@link UserInfo#getDisplayName} of current authentication
 *
 * @return UIAuthenticatorSession object for managing the authentication process with this authenticator.
 */
-(TSXUIAuthenticatorSession<TSXPasswordInput*>* _Null_unspecified)createPasswordAuthSessionWithTitle:(NSString* _Nonnull)title username:(NSString* _Nonnull)username;

/**
 * Create an authenticator session for the Fingerprint authenticator. This callback is invoked by the SDK as part of
 * an authentication action (e.g Primary or Secondary authentication), when this authenticator needs to be invoked.
 *
 * The callback receives information about the current authentication session such as title, user-name and any
 * other constraints on the authentication session, and is expected to return an authenticator session object that
 * will be used by the SDK to manage the authentication process with that authenticator.
 *
 * Note that this call isn't supplied with a clientContext parameter, however the first call on the returned
 * authenticator session object, UIAuthenticatorSession#startSession, *is* supplied with this parameter.
 *
 * See UIAuthenticatorSession for a discussion of the authentication session lifecycle and sequence of calls
 * made on that object. Note, however, that fingerprint authenticator sessions are different from other
 * authenticator sessions in the fact that the authenticator input for these sessions (of type FingerprintInput)
 * is not really the authentication secret but rather the prompt to display when collecting the fingerprint. Actual
 * fingerprint collection is done by the SDK, outside of the invocation of UIAuthenticatorSession#promiseInput.
 *
 * @param title Title of authentication action
 * @param username Username {@link UserInfo#getDisplayName} of current authentication
 *
 * @return UIAuthenticatorSession object for managing the authentication process with this authenticator.
 */
-(TSXUIAuthenticatorSession<TSXFingerprintInput*>* _Null_unspecified)createFingerprintAuthSessionWithTitle:(NSString* _Nonnull)title username:(NSString* _Nonnull)username;

/**
 * Create an authenticator session for the native face authenticator. This callback is invoked by the SDK as part of
 * an authentication action (e.g Primary or Secondary authentication), when this authenticator needs to be invoked.
 *
 * The callback receives information about the current authentication session such as title, user-name and any
 * other constraints on the authentication session, and is expected to return an authenticator session object that
 * will be used by the SDK to manage the authentication process with that authenticator.
 *
 * Note that this call isn't supplied with a clientContext parameter, however the first call on the returned
 * authenticator session object, UIAuthenticatorSession#startSession, *is* supplied with this parameter.
 *
 * See UIAuthenticatorSession for a discussion of the authentication session lifecycle and sequence of calls
 * made on that object. Note, however, that native face authenticator sessions are different from other
 * authenticator sessions in the fact that the authenticator input for these sessions (of type NativeFaceInput)
 * is not really the authentication secret but rather the prompt to display when collecting the native face sample. Actual
 * face sample collection is done by the SDK, outside of the invocation of UIAuthenticatorSession#promiseInput.
 *
 * @param title Title of authentication action
 * @param username Username {@link UserInfo#getDisplayName} of current authentication
 *
 * @return UIAuthenticatorSession object for managing the authentication process with this authenticator.
 */
-(TSXUIAuthenticatorSession<TSXNativeFaceInput*>* _Null_unspecified)createNativeFaceAuthSessionWithTitle:(NSString* _Nonnull)title username:(NSString* _Nonnull)username;

/**
 * Create an authenticator session for the device biometrics authentication authenticator. This callback
 * is invoked by the SDK as part of an authentication action (e.g Primary or Secondary authentication),
 * when this authenticator needs to be invoked.
 *
 * The callback receives information about the current authentication session such as title, user-name and any
 * other constraints on the authentication session, and is expected to return an authenticator session object that
 * will be used by the SDK to manage the authentication process with that authenticator.
 *
 * Note that this call isn't supplied with a clientContext parameter, however the first call on the returned
 * authenticator session object, UIAuthenticatorSession#startSession, *is* supplied with this parameter.
 *
 * See UIAuthenticatorSession for a discussion of the authentication session lifecycle and sequence of calls
 * made on that object. Note, however, that device biometrics authenticator sessions are different from other
 * authenticator sessions in the fact that the authenticator input for these sessions (of type DeviceBiometricsInput)
 * is not really the authentication secret but rather the prompt to display when operating the authenticator. Actual
 * authenticator operation is done by the SDK, outside of the invocation of UIAuthenticatorSession#promiseInput.
 *
 * @param title Title of authentication action
 * @param username Username of current authentication
 *
 * @return UIAuthenticatorSession object for managing the authentication process with this authenticator.
 */
-(TSXUIAuthenticatorSession<TSXDeviceBiometricsInput*>* _Null_unspecified)createDeviceBiometricsAuthSessionWithTitle:(NSString* _Nonnull)title username:(NSString* _Nonnull)username;

/**
 * Create an authenticator session for the PIN authenticator. This callback is invoked by the SDK as part of
 * an authentication action (e.g Primary or Secondary authentication), when this authenticator needs to be invoked.
 *
 * The callback receives information about the current authentication session such as title, user-name and the
 * length of the PIN to retrieve, and is expected to return an authenticator session object that will be used by
 * the SDK to manage the authentication process with that authenticator.
 *
 * Note that this call isn't supplied with a clientContext parameter, however the first call on the returned
 * authenticator session object, UIAuthenticatorSession#startSession, *is* supplied with this parameter.
 *
 * See UIAuthenticatorSession for a discussion of the authentication session lifecycle and sequence of calls
 * made on that object.
 *
 * The authenticator input type for PIN authenticator sessions is PinInput, which encapsulates  the PIN code
 * input by the user.
 *
 * @param title Title of authentication action
 * @param username Username {@link UserInfo#getDisplayName} of current authentication
 * @param pinLength Length of expected PIN input
 *
 * @return UIAuthenticatorSession object for managing the authentication process with this authenticator.
 */
-(TSXUIAuthenticatorSession<TSXPinInput*>* _Null_unspecified)createPinAuthSessionWithTitle:(NSString* _Nonnull)title username:(NSString* _Nonnull)username pinLength:(long)pinLength;

/**
 * Create an authenticator session for the Pattern authenticator. This callback is invoked by the SDK as part of
 * an authentication action (e.g Primary or Secondary authentication), when this authenticator needs to be invoked.
 *
 * The callback receives information about the current authentication session: title, user-name and the
 * size of the pattern grid in which the pattern should be input. This is expected to return an authenticator session
 * object that will be used by the SDK to manage the authentication process with the pattern authenticator.
 *
 * Note that this call isn't supplied with a clientContext parameter, however the first call on the returned
 * authenticator session object, UIAuthenticatorSession#startSession, *is* supplied with this parameter.
 *
 * See UIAuthenticatorSession for a discussion of the authentication session lifecycle and sequence of calls
 * made on that object.
 *
 * The authenticator input type for Pattern authenticator sessions is PatternInput. This object is constructed
 * based on user input by the platform Transmit UI Toolkit component for pattern based auth.
 *
 * @param title Title of authentication action
 * @param username Username {@link UserInfo#getDisplayName} of current authentication
 * @param gridWidth Width of pattern input grid, in points
 * @param gridHeight Height of pattern input grid, in points
 *
 * @return UIAuthenticatorSession object for managing the authentication process with this authenticator.
 */
-(TSXUIAuthenticatorSession<TSXPatternInput*>* _Null_unspecified)createPatternAuthSessionWithTitle:(NSString* _Nonnull)title username:(NSString* _Nonnull)username gridWidth:(long)gridWidth gridHeight:(long)gridHeight;

/**
 * Create an authenticator session for the OTP authenticator. This callback is invoked by the SDK as part of
 * an authentication action (e.g Primary or Secondary authentication), when this authenticator needs to be invoked.
 *
 * The callback receives information about the current authentication session such as title, user-name, the list of
 * available OTP trasmission targets, and optionally if one of the OTP targets was automatically triggered -- that
 * OTP target. The callback is expected to return an authenticator session object that will be used by the SDK to
 * manage the authentication process with that authenticator.
 *
 * If the server has automatically triggered an OTP generation to a target, that target will be specified
 * as the autoExecedTarget parameter. Note that this specified auto-execed target may or may not be the active target.
 * For example, if a target was auto executed, then the OTP code was invalidated, and then the user cancelled
 * the authenticator and selected it again (within the same authentication action) -- the autoexeced target is not
 * really active (as the OTP code was expired); howver on the second call to createOtpAuthSession (invoked when the
 * user selected the OTP authenticator again), it will still be passed as the value of autoExecedTarget.
 * The session's setGeneratedOtp call will be invoked to signal which target, if at all, is active.
 * In most cases the target passed to setGeneratedOtp should drive UI rather than autoExecedTarget.
 *
 * Note that this call isn't supplied with a clientContext parameter, however the first call on the returned
 * authenticator session object, UIAuthenticatorSession#startSession, *is* supplied with this parameter.
 *
 * See UIAuthenticatorSessionOtp and UIAuthenticatorSession for a discussion of the authentication session
 * lifecycle and sequence of calls made on that object. Note that the lifecycle of the OTP authenticator session
 * is specialized since it allows the SDK to notify the authentication UI session about changes to the expected
 * OTP as new OTP codes are generated throughout the session.
 *
 * The authenticator input type for OTP authenticator sessions may be one of the classes derived from OtpInput --
 *   * OtpInputOtpSubmission which encapsulates a submitted OTP password typed by the user,
 *   * OtpInputRequestResend which indicates a request to re-send the OTP to the last selected target, and
 *   * OtpInputSelectTarget which indicates a request to send an OTP to a newly selected target.
 *
 * The SDK will re-invoke the session's UIAuthenticatorSession#promiseInput callback after processing an
 * OtpInputRequestResend or OtpInputSelectTarget request.
 *
 * @param title Title of authentication action
 * @param username Username {@link UserInfo#getDisplayName} of current authentication
 * @param possibleTargets List of possible targets for sending the OTP to. OtpInputSelectTarget requests must specify one of these target objects.
 * @param autoExecedTarget If the Server has automatically triggered OTP transmission to one of the targets, this will identify that target.
 *
 * @return UIAuthenticatorSession object for managing the authentication process with this authenticator.
 */
-(TSXUIAuthenticatorSessionOtp* _Null_unspecified)createOtpAuthSessionWithTitle:(NSString* _Nonnull)title username:(NSString* _Nonnull)username possibleTargets:(NSArray<TSXOtpTarget*> * _Nonnull)possibleTargets autoExecedTarget:(TSXOtpTarget* _Nullable)autoExecedTarget;

/**
 * Create an authenticator session for the face detection authenticator. This callback is invoked by the SDK as part of
 * an authentication action (e.g Primary or Secondary authentication), when this authenticator needs to be invoked.
 *
 * The callback receives information about the current authentication session. This is the title and user-name. The
 * callback is expected to return an authenticator session object that will be used by the SDK to manage the
 * authentication process with that authenticator.
 *
 * Note that this call isn't supplied with a clientContext parameter, however the first call on the returned
 * authenticator session object, UIAuthenticatorSession#startSession, *is* supplied with this parameter.
 *
 * This is a multi-step input authenticator. See UIAuthenticatorSession and UIMultiInputAuthenticationSession for a
 * discussion of the authentication session lifecycle and sequence of calls made on that object.
 *
 * The authenticator input type for face authentication sessions is CameraInputResponse, encapsulating a JSON representation
 * of the acquisition result. This input should be generated using the platform camera acquisition control, which
 * will be configured with aquisition parameters on each input step through the supplied CameraAcquisitionStepDescription object
 * for that step.
 *
 * @param title Title of authentication action
 * @param username Username {@link UserInfo#getDisplayName} of current authentication
 *
 * @return UIMultiInputAuthenticationSession object for managing the authentication process with this authenticator.
 */
-(TSXUIMultiInputAuthenticationSession<TSXCameraInputResponse*,TSXCameraAcquisitionStepDescription*>* _Null_unspecified)createFaceAuthSessionWithTitle:(NSString* _Nonnull)title username:(NSString* _Nonnull)username;

/**
 * Create an authenticator session for the voice detection authenticator. This callback is invoked by the SDK as part of
 * an authentication action (e.g Primary or Secondary authentication), when this authenticator needs to be invoked.
 *
 * The callback receives information about the current authentication session. This is the title and user-name. The
 * callback is expected to return an authenticator session object that will be used by the SDK to manage the
 * authentication process with that authenticator.
 *
 * Note that this call isn't supplied with a clientContext parameter, however the first call on the returned
 * authenticator session object, UIAuthenticatorSession#startSession, *is* supplied with this parameter.
 *
 * This is a multi-step input authenticator. See UIAuthenticatorSession and UIMultiInputAuthenticationSession for a
 * discussion of the authentication session lifecycle and sequence of calls made on that object.
 *
 * The authenticator input type for voice authentication sessions is AudioInputResponse, encapsulating a JSON representation
 * of the acquisition result. This input should be generated using the platform voice acquisition control, which
 * will be configured with aquisition parameters on each input step through the supplied AudioAcquisitionStepDescription object
 * for that step.
 *
 * @param title Title of authentication action
 * @param username Username {@link UserInfo#getDisplayName} of current authentication
 *
 * @return UIMultiInputAuthenticationSession object for managing the authentication process with this authenticator.
 */
-(TSXUIMultiInputAuthenticationSession<TSXAudioInputResponse*,TSXAudioAcquisitionStepDescription*>* _Null_unspecified)createVoiceAuthSessionWithTitle:(NSString* _Nonnull)title username:(NSString* _Nonnull)username;

/**
 * Create an authenticator session for a placeholder authenticator. This callback is invoked by the SDK as part of
 * an authentication action (e.g Primary or Secondary authentication), when this authenticator needs to be invoked.
 *
 * The callback receives information about the current authentication session: title, user-name and placeholder
 * authetnicator server payload for the authentication process. This is expected to return an authenticator session
 * object that will be used by the SDK to manage the authentication process with the placeholder authenticator.
 *
 * Note that this call isn't supplied with a clientContext parameter, however the first call on the returned
 * authenticator session object, UIAuthenticatorSession#startSession, *is* supplied with this parameter.
 *
 * See UIAuthenticatorSession for a discussion of the authentication session lifecycle and sequence of calls
 * made on that object.
 *
 * The authenticator input type for placeholder authenticators is PlaceholderInputResponse. This object may either represent
 * a successful authentication -- in which case it is of type PlaceholderAuthSuccessResponse based on a token received
 * by the app from the app server (which in turn received it from the Transmit Server).
 *
 * Alternatively, it may be a PlaceholderAuthFailureResponse, reporting a failure to authenticate, in which case it relays
 * the failure error code (for recovery), as well as a custom message and updated authenticator status.
 *
 * @param placeholderName Name of the placeholder authenticator
 * @param placeholderType Type of the placeholder authenticator
 * @param title Title of authentication action
 * @param username Username {@link UserInfo#getDisplayName} of current authentication
 * @param authenticatorConfiguredData Data configured for the authenticator in the Transmit Server
 * @param serverPayload Placeholder authenticator server payload -- this should be passed to the application server
 *        and from there to Transmit Server when issuing a successful authetnication token.
 
 *
 * @return UIAuthenticatorSession object for managing the authentication process with this authenticator.
 */
-(TSXUIAuthenticatorSession<TSXPlaceholderInputResponse*>* _Null_unspecified)createPlaceholderAuthSessionWithPlaceholderName:(NSString* _Nonnull)placeholderName placeholderType:(NSString* _Nonnull)placeholderType title:(NSString* _Nonnull)title username:(NSString* _Nonnull)username authenticatorConfiguredData:(NSString* _Nonnull)authenticatorConfiguredData serverPayload:(NSString* _Nonnull)serverPayload;

/**
 * Create an authenticator session for mobile approve. This callback is invoked by the SDK as part of
 * an authentication action (e.g Primary or Secondary authentication), when this authenticator needs to be invoked.
 *
 * The callback receives information about the current authentication session such as title, user-name and any
 * other constraints on the authentication session, and is expected to return an authenticator session object that
 * will be used by the SDK to manage the authentication process with that authenticator.
 *
 * Note that this call isn't supplied with a clientContext parameter, however the first call on the returned
 * authenticator session object, UIAuthenticatorSession#startSession, *is* supplied with this parameter.
 *
 * See UIAuthenticatorSession for a discussion of the authentication session lifecycle and sequence of calls
 * made on that object.
 *
 * The authenticator input type for Mobile Approve authenticator sessions is MobileApproveInput. This object is
 * an empty input response since the authentication input is taking place on a different device out of this SDK's
 * control.
 *
 * This is a polling authenticator session - once approval is created the session starts polling the server waiting
 * until authentication is completed on mobile approval.
 *
 * @param title Title of authentication action
 * @param username Username {@link UserInfo#getDisplayName} of current authentication
 *
 * @return UIAuthenticatorSession object for managing the authentication process with this authenticator.
 */
-(TSXUIAuthenticatorSessionMobileApprove* _Null_unspecified)createMobileApproveAuthSessionWithTitle:(NSString* _Nonnull)title username:(NSString* _Nonnull)username instructions:(NSString* _Nonnull)instructions;

/**
 * Create an authenticator session for Totp. This callback is invoked by the SDK as part of
 * an authentication action (e.g Primary or Secondary authentication), when this authenticator needs to be invoked.
 *
 * The callback receives information about the current authentication session such as title and user-name and any
 * other constraints on the authentication session, and is expected to return an authenticator session object that
 * will be used by the SDK to manage the authentication process with that authenticator.
 *
 * Note that this call isn't supplied with a clientContext parameter, however the first call on the returned
 * authenticator session object, UIAuthenticatorSession#startSession, *is* supplied with this parameter.
 *
 * See UIAuthenticatorSession for a discussion of the authentication session lifecycle and sequence of calls
 * made on that object.
 *
 * The authenticator input type for Totp authenticator sessions is TotpInput. This object is
 * an empty input response since the authentication input is taking place on a different device out of this SDK's
 * control.
 *
 * @param title Title of authentication action
 * @param username Username {@link UserInfo#getDisplayName} of current authentication
 *
 * @return UIAuthenticatorSession object for managing the authentication process with this authenticator.
 */
-(TSXUIAuthenticatorSessionTotp* _Null_unspecified)createTotpAuthSessionWithTitle:(NSString* _Nonnull)title username:(NSString* _Nonnull)username;

/**
 * Create an authenticator session for the security question authenticator. This callback is invoked by the SDK as part of
 * an authentication action (e.g Primary or Secondary authentication), when this authenticator needs to be invoked.
 *
 * The callback receives information about the current authentication session. This is the title and user-name. The
 * callback is expected to return an authenticator session object that will be used by the SDK to manage the
 * authentication process with that authenticator.
 *
 * Note that this call isn't supplied with a clientContext parameter, however the first call on the returned
 * authenticator session object, UIAuthenticatorSession#startSession, *is* supplied with this parameter.
 *
 * This is a multi-step input authenticator. See UIAuthenticatorSession and UIMultiInputAuthenticationSession for a
 * discussion of the authentication session lifecycle and sequence of calls made on that object.
 *
 * The authenticator input type for voice authentication sessions is SecurityQuestionInputResponse,
 * encapsulating answers to security question challenged as part of the current authentication step.
 * Only questions that were challenged in the current step may be provided, and at least the number of
 * questions specified in the step as the minimum permissible submission must be provided. Failure to comply
 * with either of these requirements will lead to an AppImplementation error being triggered.
 *
 * @param title Title of authentication action
 * @param username Username {@link UserInfo#getDisplayName} of current authentication
 *
 * @return UIMultiInputAuthenticationSession object for managing the authentication process with this authenticator.
 */
-(TSXUIMultiInputAuthenticationSession<TSXSecurityQuestionInputResponse*,TSXSecurityQuestionStepDescription*>* _Null_unspecified)createSecurityQuestionAuthSessionWithTitle:(NSString* _Nonnull)title username:(NSString* _Nonnull)username;

/**
 * Get user response to a confirmation screen. This callback is invoked by the SDK to execute a confirmation screen
 * policy action.
 *
 * The callback is expected to present a confirmation screen to the user, collect its input and return it
 * asynchronously to the SDK as a ConfirmationInput object.
 *
 * @param title Title of confirmation screen to display.
 * @param text  Text to display in confirmation screen.
 * @param continueText  Label for a confirmation button (pressing this button will cause policy execution to continue)
 * @param cancelText Label for a cancellation button (pressing this button will cause policy execution to abort)
 * @param actionContext Information on the policy action currently executing, within which this callback is invoked.
 * @param clientContext The clientContext for the SDK operation invocation for which this callback is invoked.
 * @param handler Handler to receive asynchronous results. First argument -- return: A ConfirmationInput object encoding user choice. For the ConfirmationInput#userChoice property, a value of "0" means continue and a value of "1" means cancel.
 *
 *
 */
-(void)getConfirmationInputWithTitle:(NSString* _Nonnull)title text:(NSString* _Nonnull)text continueText:(NSString* _Nonnull)continueText cancelText:(NSString* _Nonnull)cancelText actionContext:(TSXPolicyAction* _Nullable)actionContext clientContext:(NSDictionary * _Nullable)clientContext asynchronouslyWithHandler:(void (^ _Nonnull)(TSXConfirmationInput* _Nonnull))handler;

/**
 * Get user response to an information screen. This callback is invoked by the SDK to execute an information screen
 * policy action.
 *
 * The callback is expected to present an information screen to the user, wait for confirmation and return
 * asynchronously to the SDK with a ConfirmationInput object with user selection "-1" once policy evaluation may
 * resume.
 *
 * @param title Title of information screen to display.
 * @param text  Text to display in information screen.
 * @param continueText  Label for the confirmation button
 * @param actionContext Information on the policy action currently executing, within which this callback is invoked.
 * @param clientContext The clientContext for the SDK operation invocation for which this callback is invoked.
 * @param handler Handler to receive asynchronous results. First argument -- return: A ConfirmationInput object. The ConfirmationInput#userChoice property must be set to "-1".
 *
 *
 */
-(void)getInformationResponseWithTitle:(NSString* _Nonnull)title text:(NSString* _Nonnull)text continueText:(NSString* _Nonnull)continueText actionContext:(TSXPolicyAction* _Nullable)actionContext clientContext:(NSDictionary * _Nullable)clientContext asynchronouslyWithHandler:(void (^ _Nonnull)(TSXConfirmationInput* _Nonnull))handler;

/**
 * Start a scan QR code session. This callback is invoked by the SDK in response to a policy-initiated request to launch the scan qr code screen.
 *
 * The callback is expected to create a ScanQrSession that represents the UI session for showing the scan QR code screen.
 * The SDK will invoke methods on this callback to drive the scan qr session lifecycle.
 *
 * See documentation of ScanQrSession for more information on the session lifecycle.
 *
 * @param actionContext Information on the policy action currently executing, within which this callback is invoked.
 * @param clientContext The clientContext for the SDK operation invocation for which this callback is invoked.
 *
 * @return a ScanQrSession object representing the scan qr code session.
 */
-(TSXScanQrSession* _Null_unspecified)createScanQrSessionWithActionContext:(TSXPolicyAction* _Nullable)actionContext clientContext:(NSDictionary * _Nullable)clientContext;

/**
 * Start a wait on ticket session. This callback is invoked by the SDK in response to a policy-initiated request to launch the wait for ticket screen.
 *
 * The callback is expected to create a UITicketWaitSession that represents the UI session for showing the ticket ID (or encoded QR) screen.
 * The SDK will invoke methods on this callback to drive the wait session polling lifecycle.
 *
 * See documentation of UITicketWaitSession for more information on the session lifecycle.
 *
 * @param actionContext Information on the policy action currently executing, within which this callback is invoked.
 * @param clientContext The clientContext for the SDK operation invocation for which this callback is invoked.
 *
 * @return a UITicketWaitSession object representing the wait for ticket session.
 */
-(TSXUITicketWaitSession* _Null_unspecified)createTicketWaitSessionWithActionContext:(TSXPolicyAction* _Nullable)actionContext clientContext:(NSDictionary * _Nullable)clientContext;

/**
 * Start a form session. This callback is invoked by the SDK in response to a policy-initiated request.
 *
 * The callback is expected to create a UIFormSession object that represents the UI session for showing forms.
 * The SDK will invoke methods on this session object as necessary to implement the session lifecycle.
 *
 * @param formId defined in Management UI Server policy as a identifier for this form.
 * @param payload JSON defined in Management UI Server policy to initialize the form session.
 *
 * @return a UIFormSession object representing the form session.
 */
-(TSXUIFormSession* _Null_unspecified)createFormSessionWithFormId:(NSString* _Nonnull)formId payload:(NSDictionary * _Nonnull)payload;

/**
 * Start an authentication configuration session. This callback is invoked by the SDK in response to
 * an application-initiated or policy-initiated request to launch the authentication configuration screen.
 *
 * The callback is expected to create a UIAuthenticationConfigurationSession that represents the UI session for
 * setting various authentication parameters  for the user -- most importantly the list of registered authenticators.
 * The SDK will invoke methods on this callback to drive the authentication configuration session lifecycle --
 * passing and updating the list of authenticators for configuration, allowing the app to execute operations
 * on these authenticators by providing a configuration services callback interface, and notifying the app when the session
 * should end.
 *
 * See documentation of UIAuthenticationConfigurationSession for more information on the session lifecycle.
 *
 * @param userId User identification handle {@link UserHandleType} for authentication configuration session.
 *
 * @return a UIAuthenticationConfigurationSession object representing the authentication configuration session.
 */
-(TSXUIAuthenticationConfigurationSession* _Null_unspecified)createAuthenticationConfigurationSessionWithUserId:(NSString* _Nonnull)userId;

/**
 * Start an authentication promotion session. This callback is invoked by the SDK in response to a policy-initiated request to launch the authentication promotion screen.
 *
 * The callback is expected to create a UIPromotionSession that represents the UI session for offering registration of a list of supported unregistered authenticators.
 * The SDK will invoke methods on this callback to drive the authentication promotion session lifecycle --
 * passing and updating the list of authenticators for registration.
 *
 * See documentation of createRegistrationPromotionSession for more information on the session lifecycle.
 *
 * @param userId User identification handle {@link UserHandleType} for authentication promotion session.
 * @param actionContext Information on the policy action currently executing, within which this callback is invoked.
 *
 * @return a createRegistrationPromotionSession object representing the authentication promotion session.
 */
-(TSXUIPromotionSession* _Null_unspecified)createRegistrationPromotionSessionWithUserId:(NSString* _Nonnull)userId actionContext:(TSXPolicyAction* _Nullable)actionContext;

/**
 * Start a device management session. This callback is invoked by the SDK in response to an application-initiated
 * or policy-initiated request to manage devices.
 *
 * The callback is expected to create a UIDeviceManagementSession that represents the UI session for managing
 * a set of devices belonging to a user. The SDK will invoke methods on this callback to drive the device management
 * session lifecycle -- passing and updating the list of managed devices, allowing the app to execute operations
 * on these devices by providing a device services callback interface, and notifying the app when the session
 * should end.
 *
 * See documentation of UIDeviceManagementSession for more information on the session lifecycle.
 *
 * @param userId User identification handle {@link UserHandleType} for device management session.
 *
 * @return a UIDeviceManagementSession object representing the device management session.
 */
-(TSXUIDeviceManagementSession* _Null_unspecified)createDeviceManagementSessionWithUserId:(NSString* _Nonnull)userId;

/**
 * Start an approval management session. This callback is invoked by the SDK in response to an application-initiated
 * or policy-initiated request to manage approvals.
 *
 * The callback is expected to create a UIApprovalSession object that represents the UI session for showing one or
 * more approvals from the approvals session and allowing to act on them. The SDK will invoke methods on this session
 * object as necessary to implement the session lifecycle. These methods allow the SDK to provide the approvals to
 * the Session UI, as well as provide a set of services to the session for carrying out operations on approvals.
 *
 * @param userId User identification handle {@link UserHandleType} for approvals management session.
 *
 * @return a UIApprovalsSession object representing the approval session.
 */
-(TSXUIApprovalsSession* _Null_unspecified)createApprovalsSessionWithUserId:(NSString* _Nonnull)userId;

/**
 * Create a TOTP code generation session. This callback is invoked by the SDK as part of the flow that is initiated by
 * invoking {@link TransmitSDKXm#startTotpSessionForUser}, after a successful authentication using the authenticator provisioned for
 * the TOTP code generation (as part of an authentication policy).
 *
 * The callback receives information about the current authentication session such as username and is expected to return
 * a totp code generation session that will be used by the SDK to manage the TOTP code generation process.
 *
 * Note that this call isn't supplied with a clientContext parameter, however the first call on the returned
 * authenticator session object, UIAuthenticatorSession#startSession, *is* supplied with this parameter.
 *
 * See {@link UITotpGenerationSession} for a discussion of the TOTP code generation session lifecycle and sequence of calls
 * made on that object.
 *
 * @param userId User identification handle {@link UserHandleType} for whom this session is requested.
 * @param generatorName The TOTP generation settings as configured on provisioning (server side settings), null is passed incase default is used.
 *
 * @return UITotpGenerationSession object for managing the TOTP generation process.
 */
-(TSXUITotpGenerationSession* _Null_unspecified)createTotpGenerationSessionWithUserId:(NSString* _Nonnull)userId generatorName:(NSString* _Nullable)generatorName;

/**
 * Process a JSON object transmitted by the policy. This callback is invoked by the SDK in response to a
 * JSON Data action defined in the policy. The callback is provided with the JSON data object specified in the
 * policy action for processing by the client, and may request the policy to abort or continue based on processing
 * of the data. Policy execution is suspended until this callback provides (asynchronously) returns the processing
 * result.
 *
 * The callback is expected to perform any application-specific processing on the received JSON data, then
 * return asynchronously a JsonDataProcessingResult object to determine how policy execution should continue.
 *
 * @param jsonData The JSON data sent by the policy
 * @param actionContext Information on the policy action currently executing, within which this callback is invoked.
 * @param clientContext The clientContext for the SDK operation invocation for which this callback is invoked.
 * @param handler Handler to receive asynchronous results. First argument -- return: A JsonDataProcessingResult indicating how to resume policy evaluation. See documentation of this type for possible responses.
 *
 *
 */
-(void)processJsonDataWithJsonData:(NSDictionary * _Nonnull)jsonData actionContext:(TSXPolicyAction* _Nullable)actionContext clientContext:(NSDictionary * _Nullable)clientContext asynchronouslyWithHandler:(void (^ _Nonnull)(TSXJsonDataProcessingResult* _Nonnull))handler;

/**
 * Notify policy evaluation rejection. This callback is invoked in response to the policy asking to reject
 * the authentication flow (either using a Reject action or rejection defined for other actions on failure).
 *
 * Implementations should present a rejection screen as defined in the callback parameters to the user,
 * and once policy evaluation may continue (i.e the policy will abort and the SDK invocation will asynchronously return)
 * the implementation must return a ConfirmationInput object asynchronously to the SDK with a user selection value of
 * "-1".
 *
 * @param title Title of rejection screen to display.
 * @param text  Text to display in rejection screen.
 * @param buttonText Label for a confirmation button (to dismiss the screen)
 * @param failureData Optional data which may be specified on the Transmit SP Server for session rejection cases. Holds one JSON field named "value", where it's value type may vary.
 * @param actionContext Information on the policy action currently executing, within which this callback is invoked.
 * @param clientContext The clientContext for the SDK operation invocation for which this callback is invoked.
 * @param handler Handler to receive asynchronous results. First argument -- return: A ConfirmationInput object encoding user choice. For the ConfirmationInput#userChoice property, set a value of "-1"
 *
 *
 */
-(void)handlePolicyRejectionWithTitle:(NSString* _Nullable)title text:(NSString* _Nullable)text buttonText:(NSString* _Nullable)buttonText failureData:(NSDictionary * _Nullable)failureData actionContext:(TSXPolicyAction* _Nullable)actionContext clientContext:(NSDictionary * _Nullable)clientContext asynchronouslyWithHandler:(void (^ _Nonnull)(TSXConfirmationInput* _Nonnull))handler;

/**
 * Handle policy redirection. This callback is invoked in response to the policy asking to redirect
 * to another policy with a possibly different user Id.
 *
 * Redirection target policy has a RedirectType indicating which SDK API function is used for starting the next policy.
 * RedirectTypeBind redirects to Id-less device bind policy, having null policyId value.
 * For authentication policy or general policy, RedirectTypeAuthenticate or RedirectTypeInvokePolicy with policyId will be provided, respectively.
 * RedirectTypeBindOrAuthenticate allows the client to decide which type to trigger according to local bind state of the SDK.
 *
 * The client context object passed to the invocation which triggered the redirect (which is the one passed to this callback) will continue to
 * be in effect for the redirected policy.
 *
 * @param redirectType Policy redirect type for next policy invocation.
 * @param policyId  Optional policy Id
 * @param userId Current or different user handle (e.g. userId, idToken) to use in next policy invocation. Null value when redirected to anonymous policy.
 * @param additionalParameters A JSON with additional parameters to be sent for next policy evaluation.
 * @param clientContext The clientContext for the SDK operation invocation for which this callback is invoked.
 * @param handler Handler to receive asynchronous results. First argument -- return: A RedirectInput object encoding client choice.
 *
 *
 */
-(void)handlePolicyRedirectWithRedirectType:(TSXRedirectType)redirectType policyId:(NSString* _Nullable)policyId userId:(NSString* _Nullable)userId additionalParameters:(NSDictionary * _Nullable)additionalParameters clientContext:(NSDictionary * _Nullable)clientContext asynchronouslyWithHandler:(void (^ _Nonnull)(TSXRedirectInput* _Nonnull))handler;

/**
 * This callback to the UI handler when local authenticator (fingerprint or face id)
 * becomes invalidated during authentication process
 *
 * @param description AuthenticatorDescription of the local authenticator that was invalidated
 * @param clientContext The clientContext for the SDK operation invocation for which this callback is invoked.
 * @param handler Handler to receive asynchronous results. First argument -- return: boolean indicating whether the invalidation was acknowledged.
 */
-(void)localAuthenticatorInvalidatedWithDescription:(TSXAuthenticatorDescription* _Nonnull)description clientContext:(NSDictionary * _Nullable)clientContext asynchronouslyWithHandler:(void (^ _Nonnull)(BOOL))handler;
@end

/** \enum TSXLogLevel
*
 * Represents log verbosity levels.
 *
 * \ingroup sdkProvided
 */
typedef NS_OPTIONS(NSUInteger, TSXLogLevel) {
   LogLevelOff = 1 << 0    /**< No logging */,
   LogLevelCritical = 1 << 1    /**< Log critical errors only */,
   LogLevelError = 1 << 2    /**< Log critical and non-critical errors */,
   LogLevelWarning = 1 << 3    /**< Log warnings, critical and non-critical errors */,
   LogLevelInfo = 1 << 4    /**< Log informative messages, warnings, critical and non-critical errors */,
   LogLevelDebug = 1 << 5    /**< Log debug messages, informative messages, warnings, critical and non-critical errors */
} ;
typedef TSXLogLevel TSXLogLevelSet;

/** \enum TSXCollectorType
*
 * Identifies types of device fingerprint data collectors
 *
 * \ingroup sdkProvided
 */
typedef NS_OPTIONS(NSUInteger, TSXCollectorType) {
   CollectorTypeAccounts = 1 << 0    /**< Collector for cloud accounts data */,
   CollectorTypeDeviceDetails = 1 << 1    /**< General device data. This collector is mandatory. */,
   CollectorTypeContacts = 1 << 2    /**< Contact data stored on the device */,
   CollectorTypeOwner = 1 << 3    /**< Device owner data */,
   CollectorTypeSoftware = 1 << 4    /**< Software installed on the device */,
   CollectorTypeLocation = 1 << 5    /**< Device location data. The 'lng' and 'lat' attributes and the 'LocationCountry' collector attributes are mutually exclusive. */,
   CollectorTypeLocationCountry = 1 << 6    /**< Device reverse geolocation data, specifically country. Disabled by default. The 'lat' and 'lng' attributes of the 'Location' collector and the attributes of this collector are mutually exclusive.*/,
   CollectorTypeBluetooth = 1 << 7    /**< Bluetooth accessory data */,
   CollectorTypeExternalSDKDetails = 1 << 8    /**< Supported modules. This collector is mandatory. */,
   CollectorTypeHWAuthenticators = 1 << 9    /**< Supported hw authenticators. This collector is mandatory. */,
   CollectorTypeCapabilities = 1 << 10    /**< Capabilities, such as fingerprint, audiocapture, persistent keys. This collector is mandatory. */,
   CollectorTypeFidoAuthenticators = 1 << 11    /**< Fido authenticators aaids. This data is saved to local cache and refreshed once a week. */,
   CollectorTypeLargeData = 1 << 12    /**< Larger sized fingerprint data */,
   CollectorTypeLocalEnrollments = 1 << 13    /**< Local enrollments registration status. This collector is mandatory. */
} ;
typedef TSXCollectorType TSXCollectorTypeSet;

/** \enum TSXConnectionCryptoMode
*
 * Identifies types of data transfer encryption modes (on top of any connection security used, like SSL), which
 * could be considered as "double" encryption, for a new authentication session.
 *
 * \ingroup sdkProvided
 */
typedef NS_OPTIONS(NSUInteger, TSXConnectionCryptoMode) {
   ConnectionCryptoModeNone = 1 << 0    /**< No encryption is added over any connection security setting */,
   ConnectionCryptoModeCredentials = 1 << 1    /**< Cryptography handshake is performed over the current data transfer and encryption begins when it's complete */,
   ConnectionCryptoModeFull = 1 << 2    /**< Cryptography handshake is performed prior to any data transfer, thus all data transfer is encrypted */
} ;
typedef TSXConnectionCryptoMode TSXConnectionCryptoModeSet;

/**
 * Represents parameters that define the connection between this app and the authentication server.
 *
 * \ingroup sdkProvided
 */
@interface TSXSDKConnectionSettings : NSObject { }

/**
 * URL of the Transmit Security server to communicate with. The SDK will use this URL whenever
 * it wants to communicate with Transmit Security server. Access to a URL relative to this URL should be
 * routed relative to the root URL of the server.
 */
@property () NSString* _Null_unspecified serverAddress;

/**
 * Realm in the Transmit Security Server to communicate with. If this is left as an empty string,
 * the default realm will be used.
 */
@property () NSString* _Null_unspecified realm;

/**
 * Application ID for this application, as defined in the management console. All policy invocations issued
 * from the SDK will be for policies within this application.
 */
@property () NSString* _Null_unspecified appId;

/**
 * SDK API token for use with the Transmit Server. This should be an API token name which
 * was provisioned in the Transmit Server management UI console.
 */
@property () NSString* _Null_unspecified tokenName;

/**
 * SDK API token for use with the Transmit Server. This should be the token value of an API token
 * provisioned in the Transmit Server management UI console.
 */
@property () NSString* _Null_unspecified token;

/**
 * The data transfer encryption mode to be used on top of any connection security for a new authentication session
 */
@property () TSXConnectionCryptoMode cryptoMode;

/**
 * Create a server connection object with the specified parameters.
 *
 * @param serverAddress serverAddress for the newly created object
 * @param appId appId for the newly created object
 * @param tokenName tokenName for the newly created object
 * @param token token for the newly created object
 */
+(TSXSDKConnectionSettings* _Nonnull) createWithServerAddress:(NSString* _Nonnull)serverAddress appId:(NSString* _Nonnull)appId tokenName:(NSString* _Nonnull)tokenName token:(NSString* _Nonnull)token;

/**
 * Create a server connection object with the specified parameters.
 *
 * @param serverAddress serverAddress for the newly created object
 * @param appId appId for the newly created object
 * @param tokenName tokenName for the newly created object
 * @param token token for the newly created object
 * @param cryptoMode The data transfer encryption mode
 */
+(TSXSDKConnectionSettings* _Nonnull) createWithCryptoModeWithServerAddress:(NSString* _Nonnull)serverAddress appId:(NSString* _Nonnull)appId tokenName:(NSString* _Nonnull)tokenName token:(NSString* _Nonnull)token cryptoMode:(TSXConnectionCryptoMode)cryptoMode;
@end

/**
 * Represents parameters that define parameters for procedures and elements which take part in the various
 * cryptography algorithms deployed by the SDK.
 *
 * \ingroup sdkProvided
 */
@interface TSXClientCryptoSettings : NSObject { }

/**
 * Specifying the key size resulting by deploying the PBKDF algorithm.
 */
@property (readonly) long localEnrollmentKeySizeInBytes;

/**
 * The number of iterations to deploy in the PBKDF algorithm (defaults to 1000).
 */
@property () long localEnrollmentKeyIterationCount;

/**
 * Create a crypto settings object with the specified parameters.
 *
 * @param keygenIterationCount The number of iterations to deploy in the PBKDF algorithm (large numbers have implications on performance)
 */
+(TSXClientCryptoSettings* _Nonnull) createWithKeygenIterationCount:(long)keygenIterationCount;
@end

/**
 * A push request payload denoting a request to invoke a mobile-approval session. Objects
 * of this class encode parameters for running the approval session. Typically they are
 * created based on data sent via a push notification, and then transferred to the SDK
 * (e.g. TransmitSDKXm#startApprovalsSessionForPushedRequest) to create an approval session based on them.
 *
 * Application developers may choose to relay push notifications externally to the platform,
 * implement their own push notification parsing process and creating push request payloads
 * synthetically; for example, an application may encode a user ticket in some field in push
 * requests sent to the application, and then extract that field when the push notification is received
 * and pass it to createWithUserTicket. In this case, the application completely controls the
 * push notification format and, in fact, transport.
 *
 * Alternatively, if the application is able to attach a JSON object payload to the push notification,
 * it can use createWithJsonPayload, passing it the JSON payload attached to the message. The JSON
 * payload is generated by the Transmit Server and passed to the push notification service provider
 * for inclusion in the push notification. This way, the Transmit platform takes care of relaying
 * push requests to the application (except for the transport itself), and the application only needs to
 * implant the payload in a preferred place in the push message (at the server), and extract it from
 * the push message in the client.
 *
 * Finally, if the application is using the Transmit builtin push service, the application only needs
 * to provide the JSON payload from the notification to createWithJsonPayload; this constructor
 * will locate the push request payload in that JSON payload as implanted by the server.
 *
 * \ingroup sdkProvided
 */
@interface TSXMobileApprovePushRequestPayload : TSXPushRequestPayload { }

/**
 * Return the semantic body content the push notification should display.
 */
-(NSString* _Null_unspecified)body;

/**
 * Return the origin of the push notification.
 */
-(NSString* _Null_unspecified)source;

/**
 * Return the user ID specified by this mobile approve push request payload, if any.
 */
-(NSString* _Null_unspecified)userId;

/**
 * Return the ticket specified by this mobile approve push request payload, if any.
 */
-(NSString* _Null_unspecified)ticket;

/**
 * Construct a synthetic push payload encoding a request to show approvals for a specific user ID.
 *
 * @param userId User identification handle {@link UserHandleType} for which approvals should be displayed to process this request.
 */
+(TSXMobileApprovePushRequestPayload* _Nonnull) createWithUserIdWithUserId:(NSString* _Nonnull)userId;

/**
 * Construct a synthetic push payload encoding a request to show approvals given a specific user ticket.
 * User tickets allow identifying users without including the user ID in the push payload. This is often
 * a desired approach to since it's preferable not to include sensitive information as part of push notifications.
 * The ticket is generated and provided to the push notification provider at the server. It refers
 * to a specific user and has an expiation period, after which it is no longer valid.
 *
 * @param ticket User ID for which approvals should be displayed to process this request.
 */
+(TSXMobileApprovePushRequestPayload* _Nonnull) createWithUserTicketWithTicket:(NSString* _Nonnull)ticket;

/**
 * Construct a push payload based on the JSON payload generated at the Transmit Server
 * and included in the push notification.
 *
 * @param payload JSON Object attached to the push notification (or at the root of the notification when using the Transmit standard push provider).
 */
+(TSXMobileApprovePushRequestPayload* _Nonnull) createWithJsonPayloadWithPayload:(NSDictionary * _Nonnull)payload;
@end

/**
 * An object referring to a suspended control flow execution.
 */
@interface TSXSuspensionContext : NSObject { }
@end

/**
 * An application-provided log handler. The application providers this to the SDK by invoking
 * TransmitSDKXm#setExternalLogger. From that point onwards the SDK will invoke this logger
 * to log messages.
 *
 * \ingroup clientProvided
 */
@interface TSXTransmitSDKLogger : NSObject { }

/**
 * Request to log a message.
 *
 * @param level Log level in which message should be logged
 * @param category A tag describing the topic or category of the message
 * @param message Message to log
 */
-(void)logWithLevel:(TSXLogLevel)level category:(NSString* _Nonnull)category message:(NSString* _Nonnull)message;
@end

/**
 * Entry point to the TSX API. This interface encapsulates all base services provided by the TSX API.
 * It is the starting point for initializing, configuring and invoking authentication processes.
 *
 * \ingroup sdkProvided
 */
@interface TSXTransmitSDKXm : NSObject { }

/**
 * @return A {@link VersionInfo} object carrying information regarding the versions of the elements comprising this SDK and its APIs.
 */
-(TSXVersionInfo* _Null_unspecified)getVersionInfo;

/**
 * Set the connection settings of the SDK for this application. This includes parameters such as server address,
 * API tokens, and application ID.
 *
 * The connection settings object passed to this call is copied and used. Changes to the connection settings object
 * after it was passed to the SDK will not have any effect.
 *
 * @param connectionSettings Connection settings to apply to the SDK.
 */
-(void)setConnectionSettings:(TSXSDKConnectionSettings* _Nonnull)connectionSettings;

/**
 * Optionally, set the cryptographic algorithms parameters in the SDK for this application. This includes parameters such as PBKDF iteration count.
 * For more details please see {@link ClientCryptoSettings}.
 *
 * The connection settings object passed to this call is copied and used. Changes to the connection settings object
 * after it was passed to the SDK will not have any effect.
 *
 * @param clientCryptoSettings Cryptographic algorithms parameters to deploy in the SDK.
 */
-(void)setClientCryptoSettings:(TSXClientCryptoSettings* _Nonnull)clientCryptoSettings;

/**
 * Set the list of enabled device fingerprinting data collectors.
 * By default all data collectors are enabled.
 *
 * @param enabledCollectors list of enabled device fingerprinting data collectors.
 */
-(void)setEnabledCollectors:(TSXCollectorTypeSet)enabledCollectors;

/**
 * Set the SDK invalid user recovery mode. This governs how the SDK behaves when encountering an error that indicates mismatch between
 * the user record on the client and server state. This includes errors {@link AuthenticationErrorCode#InvalidDeviceBinding} and
 * {@link DeviceNotFound}. Depending on the set recovery mode, the SDK may either just report the error or attempt to clear the user record
 * before reporting it. Whether the SDK has performed such deletion is reported in the error's UserRecordDeleted property.
 *
 * For API level  until 9, the default behavior is to not attempt to delete user records.
 * For API level 9 onwards, the default behavior is to attempt to delete user records.
 *
 * @param recoveryMode Recovery mode to set for invalid user record errors.
 */
-(void)setInvalidUserRecordRecoveryMode:(TSXInvalidUserRecordRecoveryMode)recoveryMode;

/**
 * Set the SDK client API level. This controls different SDK behaviors as documented in the user guide and throughout the
 * API definitions. If this is not set prior to invocation of {@link #initialize}, the system will assume the latest API level.
 * It is an error to invoke this API more than once on an SDK instance.
 *
 * @param apiLevel Client API level to enable for the SDK.
 */
-(void)setClientApiLevel:(long)apiLevel;

/**
 * Set the logging level for the SDK's internal logger. See the LogLevel enumeration for available logging levels and their meanings.
 * The default log level is LogLevel#Error.
 *
 * @param level logging level for the SDK.
 */
-(void)setLogLevel:(TSXLogLevel)level;

/**
 * Set an external logger for this SDK in addition to the default logger. The external logger is notified about every log message generated by the SDK.
 *
 * @param logger External logger to use.
 */
-(void)setExternalLogger:(TSXTransmitSDKLogger* _Nonnull)logger;

/**
 * Connect a transport provider to the SDK. The connected transport provider will be in use for all communication
 * between the SDK and the server. Once the SDK is initialized the connect transport provider must not be changed;
 * doing so will result in undefined behavior.
 *
 * @param transportProvider The TransportProvider object to connect to the SDK.
 */
-(void)setTransportProvider:(TSXTransportProvider* _Nonnull)transportProvider;

/**
 * Set the UI handler for policy invocations. This is the object that will be used by the SDK to
 * ask the client to display UI and provide input. The UI handler set at the time of policy
 * invocation will be used throughout that entire invocation, even if during invocation another
 * call to setUiHandler replaces the UI handler. The new UI handler will go into effect starting
 * with subsequent policy invocations.
 *
 * @param uiHandler UI handler object to use for subsequent policy invocations.
 *
 * @throw {@link AuthenticationError} An invalid UI handler was provided to the SDK.
 */
-(void)setUiHandler:(TSXUIHandler* _Nonnull)uiHandler;

/**
 * Notify the SDK that a push token is associated with this device. The push token will be registered with
 * the Transmit Server and will be used for subsequent attempts by the platform to send push notification
 * to this device, e.g as part of mobile approve.
 *
 * @param pushToken The updated push token to use for this device.
 *
 */
-(void)setPushToken:(NSString* _Nonnull)pushToken;

/**
 * Load a plugin into the SDK, given the plugin name and configuration
 * specific to that plugin.
 *
 * @param pluginName Name of plugin to load
 * @param config Configuration for plugin
 */
-(void)installPluginWithPluginName:(NSString* _Nonnull)pluginName config:(NSDictionary * _Nonnull)config;

/**
 * Initialize the SDK. This must be called after the configuration calls but before actually invoking
 * authentication requests.
 *
 * @param handler Handler to receive asynchronous results. First argument -- return: boolean flag indicating successful initialization. Second argument -- error: {@link AuthenticationError} An error occurred during the initialization
 */
-(void)initializeAsynchronouslyWithHandler:(void (^ _Nonnull)(BOOL, TSXAuthenticationError* _Nullable))handler;

/**
 * Construct a push payload based on the JSON payload generated at the Transmit Server and included in the push notification.
 *
 * @param payload JSON Object attached to the push notification (or at the root of the notification when using the Transmit standard push provider).
 */
-(TSXPushRequestPayload* _Null_unspecified)pushRequestPayloadFromJSONWithPayload:(NSDictionary * _Nonnull)payload;

/**
 * Query whether TOTP is provisioned on this device for u user. 'provisioned' means that the user has completed a TOTP provisioning action,
 * in an authentication policy, on this device.
 *
 * @param userId User identification handle {@link UserHandleType} to use for TOTP provisioning query.
 * @param generatorName The TOTP generation settings as configured on provisioning (server side settings), in case of null, "default" is used.
 *
 * @return 'true' if TOTP is provisioned for the user on this device, 'false' otherwise.
 */
-(BOOL)isTotpProvisionedForUserWithUserId:(NSString* _Nonnull)userId generatorName:(NSString* _Nullable)generatorName;

/**
 * Invoke a TOTP code generation session. This initiates the TOTP code generation process, which consists of two main stages:
 *  a. Authentication which the user is required to perform with the authenticator which he chose during the TOTP provisioning.
 *  b. (Optional) Acquisition of a server generated challenge presented on the client which is attempting to authenticate with TOTP.
 *  c. TOTP code generation session during which, TOTP codes are generated for the user in order to be used as OTP authentication wherever required.
 *
 * As part of this process execution the SDK will invoke the different callbacks in the currently set
 * UI handler in order to interact with the application and user.
 *
 * It is illegal to call {@link #startTotpSessionForUser} on a user for whom TOTP wasn't provisioned on this device.
 *
 * @param userId User identification handle {@link UserHandleType} to use for the TOTP code generation process.
 * @param challengeBased True iff this TOTP session should involve acquisition of a server generated challenge.
 * @param generatorName The TOTP generation settings as configured on provisioning (server side settings), in case of null, "default" is used.
 * @param clientContext An object map for client use. This map will be passed to all callbacks invoked in the context of this session invocation.
 * @param handler Handler to receive asynchronous results. First argument -- return: A boolean indicating the status of the request completion. Second argument -- error: {@link AuthenticationError} upon unsuccessful completion of the session invocation.
 *
 */
-(void)startTotpSessionForUserWithUserId:(NSString* _Nonnull)userId challengeBased:(BOOL)challengeBased generatorName:(NSString* _Nullable)generatorName clientContext:(NSDictionary * _Nullable)clientContext asynchronouslyWithHandler:(void (^ _Nonnull)(BOOL, TSXAuthenticationError* _Nullable))handler;

/**
 * Creates an object holding the TOTP code generation related attributes (e.g. *generatorName*, *challenge*) as extracted from
 * a canonical string reprasention (e.g. as produced by scanning a designated QR code).
 * A canonical representation of TOTP code generation attributes, for instance, is generated and expressed in the form of a QR barcode by the
 * Transmit server when a "web API" application is configured to enable authentication with a TOTP authenticator using a "Canonical QR Code"
 * challenge format. This challnge is supposed to be used by the mobile application providing the TOTP code for the web application authenticator.
 * See {@link #TotpGenerationRequest} for more details.
 *
 * @param userId User identification handle {@link UserHandleType} for whom this QR representation is to be processed.
 * @param repr The canonical string reprasention.
 *
 * @return An object holding the TOTP related attributes.
 * @throws AuthenticationError in case no attributes matching the TOTP provisioning on the current device could be found in the canonical string.
 */
-(TSXTotpGenerationRequest* _Null_unspecified)totpGenerationRequestForUserFromCanonicalStringWithUserId:(NSString* _Nonnull)userId repr:(NSString* _Nonnull)repr;

/**
 * Functions, essentially, is the same as with {@link #startTotpSessionForUser} but deducts the requirement of a chellenge and the challenge it self from
 * the given *attributes* argument. Thus, even if a challenge is required, the {@link UITotpGenerationSession#promiseChallengeInput} callback
 * will not be called as the chellenge is deduced from this argument.
 * @param handler 
 */
-(void)startTotpSessionWithRequestWithRequest:(TSXTotpGenerationRequest* _Nonnull)request clientContext:(NSDictionary * _Nullable)clientContext asynchronouslyWithHandler:(void (^ _Nonnull)(BOOL, TSXAuthenticationError* _Nullable))handler;

/**
 * Invoke a binding policy. This initiates the processing of the single configured binding policy in the app,
 * actually performing the device binding and finishing by returning the result of the policy execution asynchronously.
 *
 * As part of policy execution the SDK will invoke the different callbacks in the currently set
 * UI handler in order to interact with the application and user.
 *
 * It is illegal to call bind for a bound user on this device. Doing so will result in an AppImplementation error
 * code.
 *
 * A succesful bind operation is also equivalent to login -- meaning that it creates a login session and sets the
 * current primary session to this session. A failed login leave the SDK without a session.
 * It is illegal to invoke this call with a current primary session.
 *
 * @param userId User id {@link UserHandleType#UserId} to use for authentication action
 * @param additionalParameters A JSON with additional parameters to be sent for policy evaluation.
 * @param clientContext An object map for client use. This map will be passed to all callbacks invoked in the context of this policy invocation.
 * @param handler Handler to receive asynchronous results. First argument -- return: An authentication result object upon successful completion of the binding operation invocation, with an optional token. Second argument -- error: AuthenticationError upon unsuccessful completion of the policy invocation.
 *
 */
-(void)bindWithUserId:(NSString* _Nonnull)userId additionalParameters:(NSDictionary * _Nullable)additionalParameters clientContext:(NSDictionary * _Nullable)clientContext asynchronouslyWithHandler:(void (^ _Nonnull)(TSXAuthenticationResult* _Nullable, TSXAuthenticationError* _Nullable))handler;

/**
 * Query whether this device is bound for a user. 'bound' means that a binding authentication policy was completed successfully for this user on this
 * device. This status may change if this device storage is purged. This method may return 'True' for a user but the server may still revoke the binding
 * status of this device for this user on later requests.
 *
 * @param userId User identification handle {@link UserHandleType} to use for the binding status query
 *
 * @return 'true' if this device is marked as bound for this user, 'false' otherwise.
 */
-(BOOL)isBoundForUserWithUserId:(NSString* _Nonnull)userId;

/**
 * Returns a list of objects holding information about each known user on this device.
 */
-(NSArray<TSXUserInfo*> * _Null_unspecified)getUsersInfo;

/**
 * Looks up the user info based on provided user identifer.
 *
 * @param userId User identification handle {@link UserHandleType} to use for the binding status query
 *
 * @return {@link UserInfo} if the provided handle mapped to an existing user record or raises an error otherwise.
 */
-(TSXUserInfo* _Null_unspecified)getUserInfoWithUserHandle:(NSString* _Nonnull)userHandle;

/**
 * Return the list of users for whom this device is currently bound. These are all and only users for which #isBoundForUser
 * would return true.
 *
 * @return List of user IDs for whom the device is bound and have a userId {@link UserHandleType#UserId} property.
 */
-(NSArray<NSString*> * _Null_unspecified)getBoundUserIds;

/**
 * Return the list of users who previously completed a successful login on this device.
 *
 * @return List of user IDs who previously completed a successful login on this device and have a userId {@link UserHandleType#UserId} property.
 */
-(NSArray<NSString*> * _Null_unspecified)getKnownUserIds;

/**
 * Invoke an authentication policy. This initiates the processing of an authentication policy
 * and returns the result of the policy execution asynchronously. This also starts a new authentication session
 * that will be saved by the SDK until a call to logout.
 *
 * As part of policy execution the SDK will invoke the different callbacks in the currently set
 * UI handler in order to interact with the application and user.
 *
 * It is illegal to invoke this call with a current primary session; invoke #logout if there's an existing session
 * and you'd like to start a new one.
 *
 * @param userId User identification handle {@link UserHandleType#UserId} to use for authentication action
 * @param policyId ID of policy to invoke
 * @param additionalParameters A JSON with additional parameters to be sent for policy evaluation.
 * @param clientContext An object map for client use. This map will be passed to all callbacks invoked in the context of this policy invocation.
 * @param handler Handler to receive asynchronous results. First argument -- return: An authentication result object upon successful completion of the policy invocation, with an optional token. Second argument -- error: AuthenticationError upon unsuccessful completion of the policy invocation.
 *
 */
-(void)authenticateWithUserId:(NSString* _Nonnull)userId policyId:(NSString* _Nullable)policyId additionalParameters:(NSDictionary * _Nullable)additionalParameters clientContext:(NSDictionary * _Nullable)clientContext asynchronouslyWithHandler:(void (^ _Nonnull)(TSXAuthenticationResult* _Nullable, TSXAuthenticationError* _Nullable))handler;

/**
 * Ends an authentication session. This call invalidates and ends an authentication session created by #authenticate
 * or #bind.
 *
 * It is illegal to call logout while the current session is in use. The current session is in use if one or more
 * of the following calls has been made and didn't asynchronously return yet: #bind, #authenticate, #invokePolicy,
 * #startAuthenticationConfiguration, #startAuthenticationConfigurationWithToken, #startDeviceManagementSession,
 * #startApprovalsSessionForCurrentSession.
 *
 * - There's a control flow running that didn't complete;
 *
 * @param handler Handler to receive asynchronous results. First argument -- return: An authentication result object upon successful completion of the operation. Second argument -- error: AuthenticationError upon unsuccessful logoff
 */
-(void)logoutAsynchronouslyWithHandler:(void (^ _Nonnull)(BOOL, TSXAuthenticationError* _Nullable))handler;

/**
 * Invoke a policy. This initiates the invocation of a server policy, without creating a new authentication session.
 * There must be an existing session when this is invoked by the user.
 * Returns the result of the policy execution asynchronously.
 * As part of policy execution the SDK will invoke the different callbacks in the currently set
 * UI handler in order to interact with the application and user.
 *
 * It is illegal to invoke this call while a control flow is already running for the current session.
 *
 * @param policyId ID of policy to invoke
 * @param additionalParameters A JSON with additional parameters to be sent for policy evaluation.
 * @param clientContext An object map for client use. This map will be passed to all callbacks invoked in the context of this policy invocation.
 * @param handler Handler to receive asynchronous results. First argument -- return: An authentication result object upon successful completion of the policy invocation, with an optional token. Second argument -- error: AuthenticationError upon unsuccessful completion of the policy invocation.
 *
 */
-(void)invokePolicyWithPolicyId:(NSString* _Nullable)policyId additionalParameters:(NSDictionary * _Nullable)additionalParameters clientContext:(NSDictionary * _Nullable)clientContext asynchronouslyWithHandler:(void (^ _Nonnull)(TSXAuthenticationResult* _Nullable, TSXAuthenticationError* _Nullable))handler;

/**
 * Cancel the current running control flow for the primary session, if any. This will make a best-effort attempt
 * to terminate the currently executing policy (whether invoked by #bind, #authenticate, #invokePolicy, or a
 * session service for the approvals / device management / authenticator configuration sessions).
 *
 * If successful, cancellation will cause the SDK invocation that started the control flow to return with an
 * authentication error of type AuthenticationErrorCode#AppImplementation.
 *
 * Requesting a cancellation may still result in the running control flow completing succesfully -- depending
 * on the policy state at the time of cancellation invocation.
 *
 */
-(void)cancelCurrentRunningControlFlow;

/**
 * Resume a previously suspended control flow. This can be invoked after the original SDK instance executing the control flow has prepared
 * for suspension, and possibly destroyed. A new SDK instance can then resume the suspended control flow. Any action occurring as successful
 * completion of the original control flow (e.g bind, authenticate) will complete pending successful resumption of the control flow.
 *
 * When resuming a suspended control flow, parameters can be provided to it. This allows a control flow to request suspension to allow input collection,
 * and resumption of the control flow with the collected input.
 *
 * @param suspensionContext A context object that represents the suspended control flow. If this is not provided, a default control flow will be resumed.
 * @param resumptionParameters Parameters to pass to the control flow execution context when resuming.
 * @param clientContext An object map for client use. This map will be passed to all callbacks invoked in the
 * @param handler 
 * context of this invocation.
 */
-(void)resumeSuspendedControlFlowWithSuspensionContext:(TSXSuspensionContext* _Nullable)suspensionContext resumptionParameters:(NSDictionary * _Nonnull)resumptionParameters clientContext:(NSDictionary * _Nullable)clientContext asynchronouslyWithHandler:(void (^ _Nonnull)(TSXAuthenticationResult* _Nullable, TSXAuthenticationError* _Nullable))handler;

/**
 * Start an authentication configuration session. This will trigger invocation of the
 * UIHandler#createAuthenticationConfigurationSession call followed by session lifecycle management on the
 * returned object, and will async-return once the session ends.
 *
 * See UIAuthenticationConfigurationSession for more details on the session lifecycle.
 *
 * This call requires that an active, logged-in session exists for this SDK object; the user whose authentication
 * configuration will be updated is determined by the current session.
 *
 * @param clientContext An object map for client use. This map will be passed to all callbacks invoked in the
 * @param handler Handler to receive asynchronous results. First argument -- return: true on completion of configuration session. Second argument -- error: {@link AuthenticationError} upon unsuccessful completion of the session
 * context of this invocation.
 *
 */
-(void)startAuthenticationConfigurationWithClientContext:(NSDictionary * _Nullable)clientContext asynchronouslyWithHandler:(void (^ _Nonnull)(BOOL, TSXAuthenticationError* _Nullable))handler;

/**
 * Start an authentication configuration session based on an externally provided authentication token.
 * This is identical to #startAuthenticationConfiguration but rather than relying on an active current session,
 * it is done based on an authentication token provided by the client to obtain access to the configuration session.
 *
 * @param configurationToken A configuration menu access token, provided externally to the application.
 * @param clientContext An object map for client use. This map will be passed to all callbacks invoked in the
 * @param handler Handler to receive asynchronous results. First argument -- return: true on completion of configuration session. Second argument -- error: {@link AuthenticationError} upon unsuccessful completion of the session
 * context of this invocation.
 *
 */
-(void)startAuthenticationConfigurationWithTokenWithConfigurationToken:(NSString* _Nonnull)configurationToken clientContext:(NSDictionary * _Nullable)clientContext asynchronouslyWithHandler:(void (^ _Nonnull)(BOOL, TSXAuthenticationError* _Nullable))handler;

/**
 * Start a device management session. This will trigger invocation of the UIHandler#createDeviceManagementSession
 * call followed by session lifecycle management on the returned object, and will async-return once the session ends
 * either by calling the DeviceManagementSessionServices#finishSession or
 * DeviceManagementSessionServices#removeCurrentDeviceAndFinishSession.
 *
 * See UIDeviceManagementSession for more details on the session lifecycle.
 *
 * This call requires that an active, logged-in session exists for this SDK object; the user whose
 * devices will be managed is determined by the current session.
 *
 * @param clientContext An object map for client use. This map will be passed to all callbacks invoked in the
 * @param handler Handler to receive asynchronous results. First argument -- return: true on completion of management session. Second argument -- error: {@link AuthenticationError} upon unsuccessful completion of the session
 * context of this invocation.
 *
 */
-(void)startDeviceManagementSessionWithClientContext:(NSDictionary * _Nullable)clientContext asynchronouslyWithHandler:(void (^ _Nonnull)(BOOL, TSXAuthenticationError* _Nullable))handler;

/**
 * Start a mobile approval management session. This will trigger invocation of the
 * UIHandler#createApprovalsSession call followed by session lifetime management, and will async-return
 * once the session ends.
 *
 * See UIApprovalsSession for more details on the session lifecycle.
 *
 * This call requires that an active, logged-in session exists for this SDK; the user
 * for whom the approval management session will be started is determined by the current session.
 *
 * @param clientContext An object map for client use. This map will be passed to all callbacks invoked in the
 * @param handler Handler to receive asynchronous results. First argument -- return: true on completion of approvals session. Second argument -- error: {@link AuthenticationError} upon unsuccessful completion of the session
 * context of this invocation.
 *
 */
-(void)startApprovalsSessionForCurrentSessionWithClientContext:(NSDictionary * _Nullable)clientContext asynchronouslyWithHandler:(void (^ _Nonnull)(BOOL, TSXAuthenticationError* _Nullable))handler;

/**
 * Start a mobile approval management session based on a push request payload. This will trigger invocation of the
 * UIHandler#createApprovalsSession call followed by session lifetime management, and will async-return
 * once the session ends.
 *
 * See UIApprovalsSession for more details on the session lifecycle.
 *
 * The approval session is run with parameters specified in the pushRequestPayload parameter;
 * the user for whom the push approval is addressed is either specified verbatim on the payload or
 * as a one-time token generated by the Transmit Server, that identifies the user at the server. See the
 * the MobileApprovePushRequestPayload class for a discussion on how push requests can be relayed
 * to the application.
 *
 * This call does not affect the current active session for the SDK; if the push request identifies
 * a user other than the currently logged in user for a current session in the SDK, only the approvals
 * session will run based on a separate session; other SDK calls continue to use the default session.
 *
 *
 * @param pushRequestPayload A push notification payload object that encodes a request to start an approval session.
 * @param clientContext An object map for client use. This map will be passed to all callbacks invoked in the
 * @param handler Handler to receive asynchronous results. First argument -- return: true on completion of approvals session. Second argument -- error: {@link AuthenticationError} upon unsuccessful completion of the session
 * context of this invocation.
 *
 */
-(void)startApprovalsSessionForPushedRequestWithPushRequestPayload:(TSXMobileApprovePushRequestPayload* _Nonnull)pushRequestPayload clientContext:(NSDictionary * _Nullable)clientContext asynchronouslyWithHandler:(void (^ _Nonnull)(BOOL, TSXAuthenticationError* _Nullable))handler;

/**
 * Invoke an anonymous user policy. This initiates the processing of anonymous policy in the server app, starts an anonymous policy
 * and returns the result of the policy execution asynchronously.
 *
 * As part of policy execution the SDK will invoke the different callbacks in the currently set
 * UI handler in order to interact with the application and user.
 *
 * This call does not affect the current active session for the SDK, if one exists.
 *
 * @param policyId ID of policy to invoke
 * @param additionalParameters A JSON with additional parameters to be sent for policy evaluation.
 * @param clientContext An object map for client use. This map will be passed to all callbacks invoked in the context of this policy invocation.
 * @param handler Handler to receive asynchronous results. First argument -- return: An authentication result object upon successful completion of the anonymous operation invocation. Second argument -- error: AuthenticationError upon unsuccessful completion of the policy invocation.
 *
 */
-(void)invokeAnonymousPolicyWithPolicyId:(NSString* _Nullable)policyId additionalParameters:(NSDictionary * _Nullable)additionalParameters clientContext:(NSDictionary * _Nullable)clientContext asynchronouslyWithHandler:(void (^ _Nonnull)(TSXAuthenticationResult* _Nullable, TSXAuthenticationError* _Nullable))handler;

/**
 * Clear data for a specific user. If data for the user exists on the device, it will be deleted.
 *
 * It is illegal to invoke this call with an active current session.
 *
 *
 * @param userId User identification handle {@link UserHandleType} for whom data should be cleared.
 */
-(void)clearDataForUserWithUserId:(NSString* _Nonnull)userId;

/**
 * Clear all SDK data from the device
 *
 * It is illegal to invoke this call with an active current session.
 *
 */
-(void)clearAllData;

/**
 * Generate a debug PIN for the control flow started with a provided client context.
 *
 * It is illegal to invoke this call with a client context that wasn't used in one of the
 * journey-starting calls.
 *
 * @param handler Handler to receive asynchronous results. First argument -- return: A PIN code that can be used in the admin console to start debugging the journey.
 */
-(void)generateDebugPinForControlFlowWithClientContext:(NSDictionary * _Nonnull)clientContext asynchronouslyWithHandler:(void (^ _Nonnull)(NSString* _Nullable, TSXAuthenticationError* _Nullable))handler;

/**
 * Configure the UI assets download mode, there are two modes for the configuration, Disable and DownloadOnInit.
 * The default is DownloadOnInit.
 *
 * @param uiAssetsDownloadMode UIAssetsDownloadMode  UI assets download mode.
 */
-(void)setUiAssetsDownloadMode:(TSXUIAssetsDownloadMode)uiAssetsDownloadMode;

/**
 * API to set the locale of the Client Strings feature that application wants to work with,
 * this API will fetch the require locale table strings from the server and will update the strings table with the new response,
 * if the require locale table strings doesn't exist the response will return an error.
 * The API is async, the default is the preferred language that app work with it.
 *
 * @param locale string and should be in the format ISO-639(language code-Country code, ex: "en-US").
 * @param handler  Second argument -- error: {@link AuthenticationError} upon unsuccessful completion of the session
 */
-(void)setLocaleWithLocale:(NSString* _Nonnull)locale asynchronouslyWithHandler:(void (^ _Nonnull)(BOOL, TSXAuthenticationError* _Nullable))handler;
@end

