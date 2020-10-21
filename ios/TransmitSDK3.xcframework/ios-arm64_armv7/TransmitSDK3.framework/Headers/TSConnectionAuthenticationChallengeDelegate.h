//
//  TSConnectionAuthenticationChallengeDelegate.h
//  TransmitSDK
//
//  Created by Eldan Ben Haim on 15/10/2018.
//  Copyright © 2018 TransmitSecurity. All rights reserved.
//

#import <Foundation/Foundation.h>


/*! \protocol TSConnectionAuthenticationChallengeDelegate TSConnectionAuthenticationChallengeDelegate.h
 *  \brief SSL handshake client certificate provier protocol
 *
 * Protocol a delegate object that can provide client certifiate for SSL handshake
 * client authentication challenge.
 */
@protocol TSConnectionAuthenticationChallengeDelegate <NSObject>

-(NSURLCredential*)clientCredential; /**< Delegate call for returning the client certificate in NSURLCredential object */

@end

