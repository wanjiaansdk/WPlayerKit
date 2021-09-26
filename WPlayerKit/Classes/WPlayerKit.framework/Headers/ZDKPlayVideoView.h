//
//  ZDKPlayVideoView.h
//  ZDKMediaFramework
//
//  Created by UI design on 2017/4/24.
//  Copyright © 2017年 Mouse. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <MetalKit/MetalKit.h>

@interface ZDKPlayVideoView : MTKView

@property (atomic, strong) NSString *playID;

@property (nonatomic, strong) NSString *cameraId;


@end
