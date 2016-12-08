//
//  RCTJMessageModule.h
//  RCTJMessage
//
//  Created by xsdlr on 2016/11/30.
//  Copyright © 2016年 xsdlr. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "RCTBridgeModule.h"
#import "RCTEventEmitter.h"
#import <JMessage/JMessage.h>
#import <JMessage/JMessageDelegate.h>

#define OPTION_NULL(value) value ? value : [NSNull null]

@interface RCTJMessageModule : RCTEventEmitter <RCTBridgeModule, JMessageDelegate>

typedef NS_ENUM(NSInteger, JMSGRNErrorCode) {
    // ------------------------ Message (1865xxx)
    /// 无效的消息内容
    kJMSGRNErrorParamContentInvalid = 1865001,
    /// 空消息
    kJMSGRNErrorParamMessageNil = 1865002,
    /// 消息不符合发送的基本条件检查
    kJMSGErrorRNMessageNotPrepared = 1865003,
    /// 收到不支持消息内容类型(目前只支持文本和图片)
    kJMSGErrorRNMessageProtocolContentTypeNotSupport = 1865009,
    /// 发送消息超时
    kJMSGRNErrorMessageTimeout = 1865010,
};

@property NSString* appKey;
@property NSString* masterSecret;

+ (void)setupJMessage:(NSDictionary *)launchOptions
              channel:(NSString *)channel
     apsForProduction:(BOOL)isProduction
             category:(NSSet *)category;

@end