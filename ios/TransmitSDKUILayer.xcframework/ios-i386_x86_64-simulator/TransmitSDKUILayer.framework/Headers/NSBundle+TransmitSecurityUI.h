//
//  NSBundle+TransmitSecurityUI.h
//  TransmitSecurity
//
//  Created by Eran Berkovitz on 11/10/14.
//  Copyright (c) 2014 TransmitSecurity. All rights reserved.
//

#ifndef TS_BUNDLE_h
#define TS_BUNDLE_h
#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

#define TRANSMIT_SECURITY_UILAYER_RESOURCES_BUNDLE_RESOURCES_NAME @"TransmitSDKUILayerResources"


@interface NSBundle (TransmitSecurityUILayer)

+ (nullable id)loadUILayerNibNamed:(NSString *)nibName withOwner:(nullable id)owner ofClass:(nullable Class)objClass;
+ (nullable UINib*)nibWithNibName:(NSString *)nibName;
- (nullable NSString*) tsLocalizedStringForKey:(NSString * )key value:(nullable NSString *)value table:(nullable NSString *)tableName;

+(nullable NSBundle*)tsUIResourcesBundle;
+(nullable NSArray<NSBundle*>*)uiLayerBundles;
+(void)setCustomUILayerResourceBundle:(nonnull NSBundle*)bundle;

@end


/* Localization */
#define TSXLocalizedString(key, comment) \
[[NSBundle tsUIResourcesBundle] tsLocalizedStringForKey:(key) value:@"" table:nil]

#endif

NS_ASSUME_NONNULL_END
