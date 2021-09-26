//
//  NetApiManager.h
//  WPlayerKit
//
//  Created by List on 22/7/2021.
//  Copyright © 2021 List. All rights reserved.
//


#import <Foundation/Foundation.h>

typedef void(^DpsSuccess)(id data);
typedef void(^DpsFailure)(id data);

@protocol NetApiManager <NSObject>

/// Initialize Token and Topic（初始化token和topic）
/// @param token required
/// @param topic required
- (void)initDeviceCtrlWithUserToken:(NSString *)token topic:(NSString *)topic;

///Set the server domain name, not required（设置服务器域名，非必需）
- (void)setDominServerUrl:(NSString *)url;


///Send control instructions to the device （向设备发送控制指令）
/// @param deviceId required
/// @param dpsData  parameter   { "sleep_switch":0, "indicator_switch":0 }
/// @param success Success
/// @param failure The error message

- (void)setStatusWithDeviceId:(NSString *)deviceId dpsData:(NSDictionary *)dpsData success:(DpsSuccess)success failure:(DpsFailure)failure;

/// Read information from the device （从设备读取信息）
/// @param deviceId required
/// @param dpsData  parameter   ["sleep_switch","indicator_switch"]
/// @param success Success
/// @param failure The error message

- (void)getStatusWithDeviceId:(NSString *)deviceId dpsData:(NSDictionary *)dpsData success:(DpsSuccess)success failure:(DpsFailure)failure;


/// Wake up the device（唤醒设备）
/// @param deviceId required
/// @param success success description
/// @param failure failure description
- (void)wakeUpDeviceWithDeviceId:(NSString *)deviceId success:(DpsSuccess)success failure:(DpsFailure)failure;

///Check whether the firmware of the device can be upgraded （检查设备固件是否可以升级）
/// @param deviceId required
/// @param language optionals （cn、en）The default en
- (void)checkUpgradeWithDevice:(NSString *)deviceId language:(NSString *)language success:(DpsSuccess)success failure:(DpsFailure)failure;

/// Device firmware upgrade （设备固件升级）
/// @param deviceId required
- (void)upgradeWithDevice:(NSString *)deviceId progressBlock:(void(^)(NSString *deviceId, NSInteger updateStatus, NSInteger progress))progressBlock failure:(DpsFailure)failure;

/// Sends a message to the specified topic（往指定主题发送消息）
/// @param topic required
/// @param message required
- (void)publishToTopic:(NSString *)topic message:(NSString *)message;

/// Cancel subject listening（取消主题监听）
- (void)cancelTopic;

/// The system notifies the callback（系统通知回调，json字符串）
- (void)onSystemNotifyBlock:(void(^)(NSString *notify))onSystemNotifyBlock;

/// Device online status changes（设备在线状态变化）
/// 0: Offline,1: Online,2: Sleep（0:离线,1 :在线,2:休眠）
- (void)onOnlineStatusNotifyBlock:(void(^)(NSString *deviceId, NSInteger status))onOnlineStatusNotifyBlock;

/// The state of the device to be bound（待绑定设备的状态）
/// 1:The device can be bound 3: already bound The device 4: already bound by someone else
/// 1:此设备可以绑定 3:已经绑定该设备 4:已经被别人绑定
- (void)onBindStatusNotifyBlock:(void(^)(NSString *deviceId, NSInteger status))onBindStatusNotifyBlock;
 

/// Submission of equipment information（设备消息的上报）
/// resport The message data   （设备消息json字符串）
- (void)onDeviceResportBlock:(void(^)(NSString *deviceId, NSString *resport))onDeviceResportBlock;


///Callbacks to other MQTT messages （其他mqtt消息的回调）
- (void)onMsgArrivedBlock:(void(^)(NSString *topic,NSString *arrivedMsg))onMsgArrivedBlock;



@end
