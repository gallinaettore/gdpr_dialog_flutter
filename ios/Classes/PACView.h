//
//  Copyright 2018 Google LLC
//
//  Licensed under the Apache License, Version 2.0 (the "License");
//  you may not use this file except in compliance with the License.
//  You may obtain a copy of the License at
//
//      http://www.apache.org/licenses/LICENSE-2.0
//
//  Unless required by applicable law or agreed to in writing, software
//  distributed under the License is distributed on an "AS IS" BASIS,
//  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
//  See the License for the specific language governing permissions and
//  limitations under the License.
//

#import "PACConsentForm.h"

#import <WebKit/WebKit.h>

@class EGADialogStyle;


typedef NSString *PACFormKey NS_STRING_ENUM;
static PACFormKey _Nonnull const PACFormKeyOfferPersonalized = @"offer_personalized";
static PACFormKey _Nonnull const PACFormKeyOfferNonPersonalized = @"offer_non_personalized";
static PACFormKey _Nonnull const PACFormKeyOfferAdFree = @"offer_ad_free";
static PACFormKey _Nonnull const PACFormKeyAppPrivacyPolicyURLString = @"app_privacy_url";
static PACFormKey _Nonnull const PACFormKeyConstentInfo = @"consent_info";
static PACFormKey _Nonnull const PACFormKeyAppName = @"app_name";
static PACFormKey _Nonnull const PACFormKeyAppIcon = @"app_icon";
static PACFormKey _Nonnull const PACFormKeyPlatform = @"plat";

/// Loads and displays the consent form.
@interface PACView : UIView <WKNavigationDelegate>
@property(nonatomic, nullable) PACDismissCompletion dismissCompletion;
@property(nonatomic) BOOL shouldNonPersonalizedAds;
@property(nonatomic) BOOL shouldOfferAdFree;

/// Loads the view with form information and calls the handler on the main queue.
- (void)loadWithFormInformation:(nonnull NSDictionary<PACFormKey, id> *)formInformation
                          style:(nullable EGADialogStyle*) style
                   languageCode:(nullable NSString*)languageCode
              completionHandler:(nonnull PACLoadCompletion)handler;
@end
