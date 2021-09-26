#ifdef __OBJC__
#import <UIKit/UIKit.h>
#else
#ifndef FOUNDATION_EXPORT
#if defined(__cplusplus)
#define FOUNDATION_EXPORT extern "C"
#else
#define FOUNDATION_EXPORT extern
#endif
#endif
#endif

#import "MediaCallBackDelegate.h"
#import "MediaClient.h"
#import "MediaHeader.h"
#import "MessageManager.h"
#import "NetApiManager.h"
#import "P2PPlayManager.h"
#import "P2PRecordVideoManager.h"
#import "PlayerManager.h"
#import "Server.h"
#import "SpeakVoiceManager.h"
#import "WPlayerKit.h"
#import "ZDKBeautyControl.h"
#import "ZDKPlayVideoView.h"
#import "ZDKSpeakerVoice.h"

FOUNDATION_EXPORT double WPlayerKitVersionNumber;
FOUNDATION_EXPORT const unsigned char WPlayerKitVersionString[];

