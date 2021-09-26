//
//  ZDKMediaCallBackDelegate.h
//  ZDKMediaFramework
//
//  Created by yanyueya on 2017/6/29.
//  Copyright © 2017年 Mouse. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef enum{
    
    BaseEvent_Nothing = 0,                //不做处理的回调
    
    BaseEvent_CodeNull,                  //Encoder Creation Failed
    BaseEvent_Connecting,                //Network Connection
    BaseEvent_ConnectSuc,                //Connection Succeeded
    BaseEvent_ConnectFail,               //Connection Fail
    BaseEvent_ConnectTimeout,            //Connection TimeOut
    
    BaseEvent_InvalidUrl,                //Invalid connection address
    BaseEvent_UnknowMediaFile,           //Unrecognized streaming media files
    BaseEvent_WaitData,                  //Poor network Waiting for Data
    BaseEvent_CancelWaitData,            //Good network Cancels waiting Data
    
    BaseEvent_ActiveAliveError,          //Heartbeat detection timeout network connection disconnected
    BaseEvent_ActivePushError,           //Live push timeout network disconnected
    BaseEvent_ActivePlayError,           //E_Event_Code_Active_Play_Error
    BaseEvent_NotSuitForLive,            //E_Event_Code_Net_NotSuitForLive
    
    BaseEvent_FirstSnapSuc,              //First screenshot success
    BaseEvent_SnapSuc,                   //Manual screenshot Success
    BaseEvent_SnapFail,                  //Manual screenshot Failed
    BaseEvent_PlayComplete,              //End Of Play
    
    BaseEvent_LinkTransSuccess,          //Successful P2P Penetration
    BaseEvent_LinkTransFailure,          //Penetration Failed P2P
    BaseEvent_UdtConnectSuccess,         //UDT establishes a successful connection
    BaseEvent_UdtConnectFailure,         //UDT Failed to establish a connection
    BaseEvent_DelStreamResOk,            //Close audio and video streaming successfully
    BaseEvent_CloseLinkResOk,            //Close the P2P connection successfully
    BaseEvent_P2PError,                  //P2P Error
    BaseEvent_RemoteFileSearchSuccess,   //Get recording list successfully
    BaseEvent_RemoteFileSearchFailure,   //Failed to Get List
    BaseEvent_RemoteFileRequestSuccess,  //Choose recording file successfully
    BaseEvent_RemoteFileCtrlPlaySuccess, //Recording file played successfully
    BaseEvent_RemoteFileCtrlPlayFailure, //Recording file playback failed
    BaseEvent_RemoteFileCtrlPlayeof,     //End of playing recorded file
    BaseEvent_HeartbeatError,            //P2P heartbeat connection error
    BaseEvent_P2PCancelWaitData,         //Start Playing
    BaseEvent_Device_License_check_Failure,     //Authorization Failed
    BaseEvent_Device_License_expired,           //Expiration of authorization（鉴权过期）
    BaseEvent_Link_Direct_Connected,            //Direct connection
    BaseEvent_Link_Retweet,                     //Forwarding
    BaseEvent_Code_Video_FPS_INFO,        //Dynamic frame rate
    BaseEvent_Code_Add_Video,             //Add video stream successfully
    BaseEvent_Code_Add_Audio,              //Add audio stream successfully
    BaseEvent_Code_CameraPWD_Check_Failed,   //camera password check failed
    BaseEvent_Code_Msg_Search_File_Time_List, // Search tf for the day that video exists
    BaseEvent_Code_Audio_Is_Used_By_Other_Apps_Start,   //Audio is used by other apps
    BaseEvent_Code_Audio_Is_Used_By_Other_Apps_End,      //Audio is the other end of the APP
    BaseEvent_Code_Msg_P2P_WaitData,                    //Need to wait for loading（3秒未接收到数据启动等待动画）
    BaseEvent_Code_Msg_P2P_DataChannel_Broken,           //Transmission interrupt, need to delete the flow and make hole again(启动等待动画20秒后未收到数据，数据通道中断)
    BaseEvent_Code_InvalidData_input,   //Invalid file input data (data or null)(无效的文件输入数据（数据或为空))
    BaseEvent_Code_Msg_P2P_Topic,           //topic(订阅主题)
    BaseEvent_Code_Msg_P2P_CancelTopic,       //cancel topic(取消订阅主题)
    BaseEvent_Code_License_Token_Error,     // token invalid（token过期）
    BaseEvent_Code_License_Routine_Error,     // The authentication routine is incorrect（鉴权常规错误）
}ZDKCallBackEvent;


@protocol CallBackEventDelegate <NSObject>
@optional
/**
 Event Callback
 
 @param callBack callBack
 @param useInfo useInfo
 */
- (void)zdkCallBackEvent:(ZDKCallBackEvent)callBack andWithInfo:(NSDictionary*)useInfo; ///<

/**
 TF Video Play Progress
 
 @param playBack playBack
 */
-(void)zdkTFVideoProgressCallBackPlay:(NSDictionary*)playBack;

/**
 Cloud Video Play Progress
 
 @param playBack playBack
 */
-(void)zdkCloudVideoProgressCallBackPlay:(NSDictionary*)playBack;

/**
 tfCardInfo
 
 @param tfCardInfo tfCardInfo
 */
-(void)zdkCallBackTFCard:(NSDictionary*)tfCardInfo;

/**
 RemoteFile List
 
 @param remoteFile remoteFile
 */
-(void)zdkCallBackRemoteFile:(NSDictionary*)remoteFile;

/**
 TF Single video file duration
 
 @param totaltime totaltime
 */
-(void)ZDKCallBackTotalTime:(NSDictionary*)totaltime;



/// Receive internal message callback（接受到内部消息回调）
/// @param responseObject 返回值
-(void)ZDKMqttTopicResponseObject:(id)responseObject;

@end
