//
//  MQTTLog.h
//  MQTTClient
//
//  Created by Christoph Krey on 10.02.16.
//  Copyright © 2016-2017 Christoph Krey. All rights reserved.
//

@import Foundation;

#ifdef LUMBERJACK

#define LOG_LEVEL_DEF ddLogLevel
#import <CocoaLumberjack/CocoaLumberjack.h>

#else /* LUMBERJACK */

typedef NS_OPTIONS(NSUInteger, MQTTDDLogFlag){
    /**
     *  0...00001 MQTTDDLogFlagError
     */
    MQTTDDLogFlagError      = (1 << 0),

    /**
     *  0...00010 MQTTDDLogFlagWarning
     */
    MQTTDDLogFlagWarning    = (1 << 1),

    /**
     *  0...00100 MQTTDDLogFlagInfo
     */
    MQTTDDLogFlagInfo       = (1 << 2),

    /**
     *  0...01000 MQTTDDLogFlagDebug
     */
    MQTTDDLogFlagDebug      = (1 << 3),

    /**
     *  0...10000 MQTTDDLogFlagVerbose
     */
    MQTTDDLogFlagVerbose    = (1 << 4)
};


typedef NS_ENUM(NSUInteger, MQTTDDLogLevel){
MQTTDDLogLevelOff       = 0,

/**
 *  Error logs only
 */
MQTTDDLogLevelError     = (MQTTDDLogFlagError),

/**
 *  Error and warning logs
 */
MQTTDDLogLevelWarning   = (MQTTDDLogLevelError   | MQTTDDLogFlagWarning),

/**
 *  Error, warning and info logs
 */
MQTTDDLogLevelInfo      = (MQTTDDLogLevelWarning | MQTTDDLogFlagInfo),

/**
 *  Error, warning, info and debug logs
 */
MQTTDDLogLevelDebug     = (MQTTDDLogLevelInfo    | MQTTDDLogFlagDebug),

/**
 *  Error, warning, info, debug and verbose logs
 */
MQTTDDLogLevelVerbose   = (MQTTDDLogLevelDebug   | MQTTDDLogFlagVerbose),

/**
 *  All logs (1...11111)
 */
MQTTDDLogLevelAll       = NSUIntegerMax
};

#ifdef DEBUG

#define DDLogVerbose if (ddLogLevel & MQTTDDLogFlagVerbose) NSLog
#define DDLogDebug if (ddLogLevel & MQTTDDLogFlagDebug) NSLog
#define DDLogWarn if (ddLogLevel & MQTTDDLogFlagWarning) NSLog
#define DDLogInfo if (ddLogLevel & MQTTDDLogFlagInfo) NSLog
#define DDLogError if (ddLogLevel & MQTTDDLogFlagError) NSLog

#else

#define DDLogVerbose(...)
#define DDLogDebug(...)
#define DDLogWarn(...)
#define DDLogInfo(...)
#define DDLogError(...)

#endif /* DEBUG */
#endif /* LUMBERJACK */

extern MQTTDDLogLevel ddLogLevel;

/** MQTTLog lets you define the log level for MQTTClient
 *  independently of using CocoaLumberjack
 */
@interface MQTTLog: NSObject

/** setLogLevel controls the log level for MQTTClient
 *  @param logLevel as follows:
 *
 *  default for DEBUG builds is MQTTDDLogLevelVerbose
 *  default for RELEASE builds is MQTTDDLogLevelWarning
 *
 *  Available log levels:
 *  MQTTDDLogLevelAll
 *  MQTTDDLogLevelVerbose
 *  MQTTDDLogLevelDebug
 *  MQTTDDLogLevelInfo
 *  MQTTDDLogLevelWarning
 *  MQTTDDLogLevelError
 *  MQTTDDLogLevelOff
 */
+ (void)setLogLevel:(MQTTDDLogLevel)logLevel;

@end
