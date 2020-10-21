//
//  TSXDefaultUIHandler.h
//  TSXDemo
//
//  Created by Sletean Inbar on 25/03/2018.
//  Copyright © 2018 Transmit Security LTD. All rights reserved.
//
#import <UIKit/UIKit.h>
#import "SDK3.h"

@class TSXDefaultUIHandlerHostingContext;
/**
 Default Transmit Security implementation for UI Layer TSXUIHandler class.
 TSXDefaultUIHandler supports two presentation modes referred to as "navigation" and "presented".
 On "navigation" the default UI handler relies on an application provided UINavigationController.
 Any SDK UI will be presented using the application provided navigation controller.

 On "presented" the default UI handler will create its own UINavigationController and present it modally on top
 of the provided view controller.
 Any SDK UI will be presented using the SDK provided navigation controller.
 
 Please note that adding UI to the hosting context view controller or navigation controller is discouraged.
 Any UI to be added after the hosting context has been created should come from the default UI, customized
 UI handler or its related SDK UI classes implementations.
 */
@interface TSXDefaultUIHandler : TSXUIHandler

/**
 Navigation controller used by the default UI layer. See more details in hosting context creation methods.
 */
@property (weak, nonatomic, nullable) UINavigationController* currentNVC;


/**
 Create a client context dictionary holding hosting context with modally presented view controller.
 Transmit Security default UI generates a navigation controller to be presented on top of the provided
 view controller.

 @param viewController hosting view controller
 @return client context dictionary
 */
+(NSMutableDictionary*)createClientContextForPresentingViewController:(UIViewController*)viewController;

/**
 Create a client context dictionary holding hosting context with provided navigation controller.
 Transmit Security default UI uses the provided navigation controller to present its UI.

 @param navigationController hosting navigation controller
 @return client context dictionary
 */
+(NSMutableDictionary*)createClientContextForNavigationViewController:(UINavigationController*)navigationController;

/**
 Create a client context dictionary holding provided hosting context.

 @param hostingContext hosting context object
 @return client context dictionary
 */
+(NSMutableDictionary*)createClientContextWithHostingContext:(TSXDefaultUIHandlerHostingContext*)hostingContext;
/**
 Access hosting context object in client context dictionary

 @param clientContext client context dictionary
 @return hosting context object
 */
+(TSXDefaultUIHandlerHostingContext*)hostingContextFromClientContext:(NSDictionary*)clientContext;

/**
 Generate a default hosting context.

 @return hosting context object
 */
+(TSXDefaultUIHandlerHostingContext*)defaultHostingContext;


/**
  Change UI branding
 
 @param brandingJson json of UI branding as received from policy
 */
+(void)updateBranding:(NSDictionary*)brandingJson;

@end


/**
 Default UI Handler for QS App (contains manage account form)
 */
@interface TSXQSDefaultUIHandler : TSXDefaultUIHandler
@end
