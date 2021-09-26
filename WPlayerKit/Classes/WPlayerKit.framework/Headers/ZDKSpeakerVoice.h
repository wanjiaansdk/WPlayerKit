//
//  ZDKSpeakerVoice.h
//  ZDKMediaFramework
//
//  Created by UI design on 2017/5/31.
//  Copyright © 2017年 Mouse. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "SpeakVoiceManager.h"

@interface ZDKSpeakerVoice : NSObject <SpeakVoiceManager>




/**
 Initialize voice intercom

 @param cameraID cameraID
 @param sampleRate sampleRate
 @param type  Type 2 RTMP 4 P2P
 @param isPad isPad
 @return ZDKSpeakerVoice 
 */
- (id)initSpeakVoiceCameraID:(NSString *)cameraID SampleRate:(NSInteger)sampleRate andWithType:(NSString*)type isPad:(BOOL)isPad;
- (void)start;

- (void)stop;
@end
