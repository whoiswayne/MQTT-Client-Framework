//
//  MQTTLog.m
//  MQTTClient
//
//  Created by Josip Cavar on 06/07/2017.
//
//

#import "MQTTLog.h"

@implementation MQTTLog

#ifdef DEBUG

MQTTDDLogLevel ddLogLevel = MQTTDDLogLevelVerbose;

#else

MQTTDDLogLevel ddLogLevel = MQTTDDLogLevelWarning;

#endif

+ (void)setLogLevel:(MQTTDDLogLevel)logLevel {
    ddLogLevel = logLevel;
}

@end
