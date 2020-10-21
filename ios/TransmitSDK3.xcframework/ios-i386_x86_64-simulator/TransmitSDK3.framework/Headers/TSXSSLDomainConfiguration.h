//
//  TSXSSLDomainConfiguration.h
//  TransmitSDK
//
//  Created by Sletean Inbar on 28/05/2018.
//  Copyright © 2018 TransmitSecurity. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef NS_OPTIONS(NSUInteger, TSXPublicKeyPinningSupportedAlgorithmSet) {
    TSXAlgorithmRsa2048 = 1 << 0, //RSA 2048.
    TSXAlgorithmRsa4096 = 1 << 1, //  RSA 4096.
    TSXAlgorithmEcDsaSecp256r1 = 1 << 2, //  ECDSA with secp256r1 curve.
    TSXAlgorithmEcDsaSecp384r1 = 1 << 3 // ECDSA with secp384r1 curve.
};


@interface TSXSSLDomainConfiguration : NSObject 
//@param hashes -  An array of SSL pins, where each pin is the base64-encoded SHA-256 hash of a certificate's Subject Public Key Info
//@param algorithms -  An array of `TSXSupportedAlgorithm` constants to specify the public key algorithms for the keys to be pinned.
-(instancetype)initWithPublicHashes:(NSArray<NSString*>*)hashes andSupportedAlgorithms:(TSXPublicKeyPinningSupportedAlgorithmSet)algorithms;

@property (nonatomic) BOOL enforcePinning;
@property (nonatomic) BOOL includeSubdomains;
@property (nonatomic) BOOL excludeSubdomainFromParentPolicy;
@property (nonatomic) NSDate* expirationDate; //yyyy-MM-dd format
@property (nonatomic) NSArray<NSString*>* reportUris;
-(NSDictionary*)toTrustKitConfigDictionary;


@end
