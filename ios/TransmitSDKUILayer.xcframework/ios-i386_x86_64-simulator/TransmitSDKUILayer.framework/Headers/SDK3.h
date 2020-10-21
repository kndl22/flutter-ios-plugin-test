//
//  SDK3.h
//  TransmitSDKUILayer
//
//  Created by Avihai Apatoff on 07/01/2019.
//  Copyright © 2019 Transmit Security. All rights reserved.
//

#import <UIKit/UIKit.h>

#if defined(TS_SDK_AS_STATIC_LIB)
@import libTransmitSDK3;
#else
@import TransmitSDK3;
#endif
