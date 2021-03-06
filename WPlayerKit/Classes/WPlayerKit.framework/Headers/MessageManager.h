//
//  MessageManager.h
//  WPlayerKit
//
//  Created by List on 26/9/2019.
//  Copyright © 2019 List. All rights reserved.
//

#import <Foundation/Foundation.h>

@protocol MessageManager <NSObject>


/// Add topic listening（设置监听主题）
/// @param userId 用户ID
/// @param appId 声波ID
- (void)setTopicWithUserId:(NSString *)userId appId:(NSString *)appId DEPRECATED_MSG_ATTRIBUTE("Please use [MessageManager setTopicTopic:]");;

/// Add topic listening（设置监听主题）
/// @param topic 服务器返回的主题
- (void)setTopicTopic:(NSString *)topic;

/// Cancel subject listening（取消主题监听）
- (void)cancelTopic;


/// Sends a message to the specified topic（往指定主题发送消息）
/// @param topic 主题
/// @param message 消息体
- (void)sendMessageToTopic:(NSString *)topic message:(NSString *)message;

@end
