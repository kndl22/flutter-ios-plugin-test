//
//  TSXDefaultUIHandlerHostingContext.h
//  TransmitSDK3Static
//
//  Created by Eldan Ben Haim on 10/12/2017.
//  Copyright © 2017 TransmitSecurity. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface TSXDefaultUIHandlerHostingContext : NSObject
/**
 Present a view controller according to hosting context logic (navigation, presented).
 Unlike -[UINavigationController pushViewController:animated:], presentation will dismiss the current top view controller
 and replace it with the viewControllerToPresent.
 Use -[dismissViewControlelrAnimated:] to remove the view controller.

 @param viewControllerToPresent View controller to present.
 @param animated should animate
 */
-(void)presentViewController:(UIViewController*_Nonnull)viewControllerToPresent animated:(BOOL)animated;
/**
 Dismiss a view controller according to hosting context logic (navigation, presented).

 @param animated should animate
 */
-(void)dismissViewControllerAnimated:(BOOL)animated;
/**
 Add a view controller according to hosting context logic (navigation, presented).
 Use -[dismissViewControlelrAnimated:] to remove the view controller.

 @param viewControllerToAdd View controller to add on top of previous top view controller.
 @param animated should animate
 */
-(void)pushViewController:(UIViewController*_Nonnull)viewControllerToAdd animated:(BOOL)animated;
/**
 Present a view controller on top of current top view controller as a modal.

 @param dialogViewController view controller to present
 */
-(void)presentDialogViewController:(UIViewController*_Nonnull)dialogViewController;
/**
 Dismiss currently presented modal view controller.

 @param completion dismiss completion handler
 */
-(void)dismissDialogViewControllerWithCompletion:(void (^ __nullable)(void))completion;
/**
 Dismiss all presented UI.
 Should be used on SDK call completion block to remove the UI when flow has completed.
 */
-(void)teardownUi;

//Currently presented activity indicator.
@property (nullable) UIView *activityIndicator;
//Hosting view controller with which the hosting context was created
@property (readonly, nonnull) UIViewController *hostingViewController;
//Current top view controller in hierarchy
@property (readonly, nonnull) UIViewController* topViewController;

@property (nonatomic) BOOL hideActivityIndicator;

-(void)snapshotMaskImage:(UIImage* _Nonnull)snapshotMask;
-(void)snapshotMaskEnabled:(BOOL)enabled;

@end
