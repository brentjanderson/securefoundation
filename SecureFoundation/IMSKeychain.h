//
//  IMSKeychain.h
//  SecureFoundation
//
//  Created by Caleb Davenport on 10/15/12.
//  Copyright (c) 2012 The MITRE Corporation. All rights reserved.
//

#import <Foundation/Foundation.h>

/*
 
 File-based keychain API replacement. This stores its data in tha application
 sandbox such that when the app is uninstalled, this data goes with it. It
 works together with `IMSCryptoManager` to encrypt and decrypt data with the
 shared application key.
 
 */
@interface IMSKeychain : NSObject

#pragma mark - force keychain write

/*
 
 Force the keychain to write its contents to disk. This method will block
 until the write is complete.
 
 */
+ (void)synchronize;

#pragma mark - get and set unsecured data

/*
 
 Get a list of all accounts across all services.
 
 */
+ (NSArray *)accounts;

/*
 
 Get the account names for the given service.
 
 */
+ (NSArray *)accountsForService:(NSString *)service;

/*
 
 Set password data in the unsecured password store.
 
 */
+ (BOOL)setPassword:(NSString *)password forService:(NSString *)service account:(NSString *)account;
+ (BOOL)setPasswordData:(NSData *)password forService:(NSString *)service account:(NSString *)account;

/*
 
 Fetch password data from the unsecured password store.
 
 */
+ (NSString *)passwordForService:(NSString *)service account:(NSString *)account;
+ (NSData *)passwordDataForService:(NSString *)service account:(NSString *)account;

#pragma mark - delete passwords

/*
 
 Delete passwords 
 
 */
+ (BOOL)deletePasswordForService:(NSString *)service account:(NSString *)account;

#pragma mark - get and set encrypted data

/*
 
 Set password data in the secured password store. This will have no effect
 if the encryption key has not been set of if it has been cleared.
 
 */
+ (BOOL)setSecurePassword:(NSString *)password forService:(NSString *)service account:(NSString *)account;
+ (BOOL)setSecurePasswordData:(NSData *)password forService:(NSString *)service account:(NSString *)account;

/*
 
 Fetch password data from the secured password store. This will return `nil`
 if the encryption key has not been set of if it has been cleared.
 
 */
+ (NSString *)securePasswordForService:(NSString *)service account:(NSString *)account;
+ (NSData *)securePasswordDataForService:(NSString *)service account:(NSString *)account;

@end
