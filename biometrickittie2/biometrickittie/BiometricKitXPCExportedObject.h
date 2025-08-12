

@interface BiometricKitXPCServerMesa  {
    unsigned int _services;
    unsigned int _connect;
    unsigned int _status;
    unsigned int _rootPowerDomain;
    struct IONotificationPort * _sleepNotifyPortRef;
    unsigned int _sleepNotifierObject;
    bool _systemSleepState;
    unsigned long long _lastWakeFromHibernationTime;
    unsigned short _commProtocolVersion;
    NSMutableDictionary * _cachedImageDB;
    bool _showDebugImages;
    NSMutableData * _templListCache;
    long long _enrollmentCount;
    NSDate * _currentDate;
    NSObject<OS_dispatch_queue> * _hidClientQueue;
    struct __IOHIDEventSystemClient * _hidClient;
    bool _fingerIsOn;
    bool _hidEventFilterCallbackRegistered;
    int _lastSBFingerMsg;
    int _lastSBLockMsg;
    bool _hidEventCallbackRegistered;
    NSNumber * _displayOn;
    unsigned long long _loggingType;
    NSObject<OS_dispatch_source> * _sigTERMDispatchSource;
    NSMutableSet * _bluetoothAccessories;
    NSObject<OS_dispatch_source> * _dailyUpdateTimer;
    bool _sensorReady;
}
@property (nonatomic) bool sensorReady;
@property (readonly) unsigned long long hash;
@property (readonly) Class superclass;
@property (readonly,copy) NSString * description;
@property (readonly,copy) NSString * debugDescription;
+ (id)getSysCfgCalibrationData;
- (void)updateBioLogState;
- (unsigned long long)getLastWakeFromHibernationTime;
- (id)init;
- (int)initAutoBugCapture;
- (int)initDisplayService;
- (void)dealloc;
- (void)disconnectingClient:(id)v1;
- (void)notifyAppIsInactive:(bool)v1 withClient:(id)v2;
- (void)sendStatusMessage:(unsigned int)v1 toClient:(id)v2;
- (int)enroll:(int)v1 forUser:(unsigned int)v2 withOptions:(id)v3 withClient:(id)v4;
- (int)initEnrollOperation:(id)v1 biometricType:(int)v2 userID:(unsigned int)v3 options:(id)v4 client:(id)v5;
- (int)performEnrollCommand:(id)v1;
- (int)match:(id)v1 withOptions:(id)v2 withClient:(id)v3;
- (id)createMatchOperation;
- (int)initMatchOperation:(id)v1 filter:(id)v2 options:(id)v3 client:(id)v4;
- (int)performMatchCommand:(id)v1;
- (int)detectPresenceWithOptions:(id)v1 withClient:(id)v2;
- (int)performPresenceDetectCommand:(id)v1;
- (int)cancelWithClient:(id)v1;
- (int)performCancelCommand;
- (int)updateIdentity:(id)v1 withOptions:(id)v2 withClient:(id)v3;
- (int)removeIdentity:(id)v1 withOptions:(id)v2 withClient:(id)v3;
- (int)removeAllIdentitiesForUser:(unsigned int)v1 withOptions:(id)v2 withClient:(id)v3;
- (id)getIdentityFromUUID:(id)v1 withClient:(id)v2;
- (id)identities:(id)v1 withClient:(id)v2;
- (long long)getMaxIdentityCount:(int)v1 withClient:(id)v2;
- (long long)getFreeIdentityCount:(int)v1 forUser:(unsigned int)v2 withClient:(id)v3;
- (void)homeButtonPressed;
- (void)touchIDButtonPressed:(bool)v1;
- (int)systemSleepStateChanged:(bool)v1;
- (int)checkSensorReadiness;
- (int)initSensor;
- (int)resetSensor;
- (int)cachePatch;
- (int)registerDSID:(unsigned long long)v1 withOptions:(id)v2 withClient:(id)v3;
- (int)registerStoreToken:(id)v1 withClient:(id)v2;
- (int)getCountersignedStoreToken:(id *)v1 withClient:(id)v2;
- (int)diagnostics:(int)v1 withOptions:(id)v2 passed:(bool *)v3 withDetails:(id *)v4 withClient:(id)v5;
- (void)timestampEvent:(unsigned long long)v1 absoluteTime:(unsigned long long)v2;
- (int)setUserDSID:(unsigned long long)v1 withOptions:(id)v2 withClient:(id)v3;
- (int)resetAppleConnectCounterWithClient:(id)v1;
- (id)getIdentitiesDatabaseUUIDForUser:(unsigned int)v1 withClient:(id)v2;
- (id)getIdentitiesDatabaseHashForUser:(unsigned int)v1 withClient:(id)v2;
- (int)dropUnlockTokenWithClient:(id)v1;
- (int)forceBioLockoutForUser:(unsigned int)v1 withOptions:(id)v2 withClient:(id)v3;
- (int)enrollContinue;
- (id)pullAlignmentData;
- (id)pullMatchPolicyInfoData;
- (id)getNodeTopologyForIdentity:(id)v1 withClient:(id)v2;
- (id)getProtectedConfigurationForUser:(unsigned int)v1 withClient:(id)v2;
- (id)getSystemProtectedConfigurationWithClient:(id)v1;
- (int)setProtectedConfiguration:(id)v1 forUser:(unsigned int)v2 withOptions:(id)v3 withClient:(id)v4;
- (int)setSystemProtectedConfiguration:(id)v1 withOptions:(id)v2 withClient:(id)v3;
- (bool)getEnabledForUnlock;
- (int)setAppleMesaSEPLoggingLevel;
- (void)vibrate:(long long)v1;
- (long long)getProvisioningStateWithClient:(id)v1;
- (int)getBioLockoutState:(long long *)v1 forUser:(unsigned int)v2 withClient:(id)v3;
- (bool)isFingerOnWithClient:(id)v1;
- (int)enableBackgroundFdet:(bool)v1 withClient:(id)v2;
- (bool)isXARTAvailableWithClient:(id)v1;
- (int)getBiometryAvailability:(long long *)v1 forUser:(unsigned int)v2 withClient:(id)v3;
- (int)getLastMatchEvent:(id *)v1 withClient:(id)v2;
- (int)setCalibrationData:(id)v1 source:(int)v2;
- (id)getModuleSerialNumber;
- (id)getFDRCalibrationData;
- (id)getRemoteFDRCalibrationData;
- (id)getEEPROMCalibrationData;
- (int)performDisplayStatusChangedCommand:(bool)v1;
- (unsigned long long)getLoggingType;
- (long long)getEnrollmentCount;
- (int)getTimestampCollection:(struct anonymous_type_51 *)v1;
- (int)getDataFromDriverCommand:(unsigned char)v1 value:(unsigned char)v2 data:(char *)v3 size:(unsigned long long)v4;
- (void)registerDelegate:(bool)v1 withClient:(id)v2;
- (int)getCommProtocolVersion;
- (bool)shouldFilterStatusForSB:(unsigned int)v1;
- (void)cancelUnlockMatchIfTokenNotPresent:(struct anonymous_type_52 *)v1;
- (void)writeAuditRecordWithToken:(struct anonymous_type_53)v1 sucess:(bool)v2;
- (int)cacheSensorInfo;
- (unsigned long long)getSensorType;
- (void)checkDailyUpdate;
- (void)setupDailyUpdateTimer;
- (void)resetContinuousCounters;
- (id)pullCalibrationDataWithClient:(id)v1;
- (id)pullCaptureBufferWithClient:(id)v1;
- (int)setDebugImages:(bool)v1 withClient:(id)v2;
- (id)pullDebugImageData:(bool)v1 rotated:(bool)v2 hasWidth:(unsigned int *)v3 hasHeight:(unsigned int *)v4 withClient:(id)v5;
- (void)cacheImageDB:(struct anonymous_type_54 *)v1;
- (void)updateImageDB:(id)v1 templateUpdateInfo:(struct anonymous_type_56 *)v2;
- (id)getSerialisedTemplatesForUser:(unsigned int)v1;
- (long long)getSensorCalibrationStatusWithClient:(id)v1;
- (id)getCalibrationDataInfoWithClient:(id)v1;
- (long long)getCalBlobVersion;
- (long long)getCalibrationDataState;
- (float)getModulationRatio;
- (id)getSensorInfoWithClient:(id)v1;
- (id)getLogs:(bool)v1 withDetails:(id *)v2;
- (bool)fileRadarWithLogs:(id)v1 withDescription:(id)v2;
- (int)setIORegistryProperty:(id)v1 toValue:(id)v2 onService:(id)v3;
- (void)enrollResult:(id)v1 withTimestamp:(unsigned long long)v2;
- (void)matchResult:(id)v1 timestamp:(unsigned long long)v2;
- (void)matchEventMessage:(struct anonymous_type_65 *)v1;
- (void)deviceAuthRequiredMessage:(struct anonymous_type_67 *)v1;
- (void)statisticsMessage:(struct anonymous_type_68 *)v1;
- (void)statusMessage:(unsigned int)v1 withData:(id)v2 timestamp:(unsigned long long)v3;
- (void)templateUpdateMessage:(struct anonymous_type_70 *)v1;
- (int)loadCalibrationData;
- (bool)templatesExistAtBoot;
- (int)serviceStatus:(unsigned int)v1 version:(unsigned int)v2 ordinal:(unsigned long long)v3 data:(id)v4 timestamp:(unsigned long long)v5;
- (int)performCommand:(unsigned short)v1 version:(unsigned short)v2 inValue:(unsigned short)v3 inData:(void *)v4 inSize:(unsigned long long)v5 outData:(char *)v6 outSize:(unsigned long long *)v7;
- (int)performCommand:(unsigned short)v1 inValue:(unsigned short)v2 inData:(void *)v3 inSize:(unsigned long long)v4 outData:(char *)v5 outSize:(unsigned long long *)v6;
- (int)restoreAndSyncTemplates;
- (void)clearTemplateList;
- (void)clearTemplateListForUser:(unsigned int)v1;
- (void)removeIdentityObject:(id)v1;
- (void)addIdentityObjects:(id)v1;
- (int)getCatacombSaveListForComponents:(id)v1 list:(id *)v2;
- (int)archiveCatacombDataForComponent:(id)v1 toArchiver:(id)v2;
- (int)unarchiveCatacombDataForComponent:(id)v1 fromUnarchiver:(id)v2 secureData:(id *)v3 identities:(id *)v4;
- (int)saveTemplateListSU:(bool)v1;
- (int)decodeCatacombDataV1:(char *)v1 withSize:(unsigned long long)v2;
- (int)restoreCatacombMap;
- (int)saveCatacombMap;
- (int)restoreTemplateListSU;
- (int)saveCatacombForComponents:(id)v1;
- (bool)isBaseSystem;
- (int)saveCatacomb;
- (int)saveCatacombForIdentity:(id)v1;
- (int)loadCatacombForComponent:(id)v1;
- (int)loadCatacomb;
- (unsigned int)catacombVersion;
- (int)performGetIdentitiesListCommand:(unsigned int)v1 outBuffer:(id)v2;
- (int)performGetCatacombStateCommand:(id)v1;
- (int)performGetCatacombGroupStateCommand:(id)v1;
- (int)performGetIdentityRecordsCommand:(id)v1;
- (int)performGetBioDeviceListCommand:(id)v1;
- (int)performGetFreeIdentityCountCommand:(unsigned int)v1 group:(struct anonymous_type_79 *)v2 outCount:(unsigned int *)v3;
- (id)accessoryInfo:(id)v1;
- (id)accessorySensorInfo:(id)v1;
- (void)accessoryAdded:(id)v1;
- (void)accessoryRemoved:(id)v1;
- (void)accessoryConnected:(id)v1;
- (void)accessoryDisconnected:(id)v1;
- (void)accessoryMayHaveChanged;
- (void)osLogImageInfoMessage:(struct anonymous_type_80 *)v1;
- (id)accessoryCalibrationData:(id)v1;
- (int)performGetTemplatesValidityCommand:(unsigned int)v1 isValid:(bool *)v2;
- (int)performRemoveIdentityCommand:(struct anonymous_type_88 *)v1;
- (int)performGetBiometrickitdInfoCommand:(struct anonymous_type_89 *)v1;
- (int)performRemoveUserDataCommand:(unsigned int)v1;
- (int)performPrepareSaveCatacombCommand:(id)v1 outDataSize:(unsigned int *)v2;
- (int)performCompleteSaveCatacombCommand:(id)v1 outBuffer:(id)v2;
- (int)performConfirmSaveCatacombCommand:(id)v1;
- (int)performNoCatacombCommand:(unsigned int)v1;
- (int)performLoadCatacombCommand:(id)v1 inData:(id)v2;
- (int)performSaveBioLockoutRecordCommand:(id)v1;
- (int)performLoadBioLockoutRecordCommand:(id)v1;
- (int)performRequestMaxIdentityCountCommand:(unsigned int *)v1;
- (int)performGetFreeIdentityCountCommand:(unsigned int)v1 outCount:(unsigned int *)v2;
- (int)performGetCatacombUUIDCommand:(unsigned int)v1 outUUID:(id *)v2;
- (int)performGetCatacombHashCommand:(unsigned int)v1 outHash:(id *)v2;
- (int)performDropUnlockTokenCommand;
- (int)performForceBioLockoutCommand:(unsigned int)v1;
- (int)performGetSKSLockStateCommand:(unsigned int)v1 outState:(unsigned int *)v2;
- (int)performIsXARTAvailableCommand:(bool *)v1;
- (int)performGetLastMatchEventCommand:(struct anonymous_type_90 *)v1;
- (int)performGetProtectedConfigCommand:(unsigned int)v1 outSetCfg:(id *)v2 outEffectiveCfg:(id *)v3;
- (int)performGetSystemProtectedConfigCommand:(id *)v1;
- (int)performSetProtectedConfigCommand:(unsigned int)v1 cfg:(id)v2 authData:(struct anonymous_type_92 *)v3;
- (int)performSetSystemProtectedConfigCommand:(id)v1 authData:(struct anonymous_type_93 *)v2;
- (int)performRequestMessageDataCommand:(unsigned long long)v1 size:(unsigned long long)v2 outData:(id *)v3;
- (void)dumpSyslog;
- (void)dumpSyslogWithDelay:(double)v1;
- (id)getSyslog;
- (id)getSyslogArray;
- (id)getSyslogForQuery:(struct __asl_object_s *)v1 withFilter:(void (^ /* unknown block signature */)(void))v2;
- (bool)isDisplayOn;
- (void)dispatchBiometricHIDEvent;
- (void)registerForLiftToWakeNotifications:(bool)v1;
@end


/*****************************************************************/

@interface BLTimeBox : NSObject {
    bool _clockChanged;
    NSDate * _systemStartDate;
    double _lastMachCorrection;
    NSDate * _idleStartDate;
}
@property (readonly,retain) NSDate * systemStartDate;
@property (readonly) bool clockChanged;
@property double lastMachCorrection;
@property (retain) NSDate * idleStartDate;
- (id)init;
- (void)dealloc;
- (void)systemClockChanged:(id)v1;
- (id)getSystemStartDate;
- (double)idleTimeAtDate:(id)v1;
- (double)clockOffset;
- (double)synchronizeToClock;
- (double)machCorrectionWithCheck;
- (id)date;
- (id)dateFromAbsoluteTime:(unsigned long long)v1 hasNanoseconds:(unsigned long long *)v2;
- (void).cxx_destruct;
@end


/*****************************************************************/

@interface BLTemplateList : NSObject {
    NSMutableDictionary * _identityList;
    NSMutableDictionary * _templateList;
    NSLock * _listLock;
}
- (id)initWithIdentities:(id)v1;
- (void)setIdentity:(id)v1;
- (id)templateNameForIdentity:(id)v1;
- (id)allIdentities;
- (id)identitiesForUser:(unsigned int)v1;
- (unsigned long long)countForUser:(unsigned int)v1;
- (void)removeIdentity:(id)v1;
- (void)setIdentity:(id)v1 withTemplateName:(id)v2;
- (void)removeAll;
- (void)setIdentities:(id)v1;
- (id)identityByUUID:(id)v1;
- (void)setIdentitiesForUser:(unsigned int)v1 withTemplateListName:(id)v2;
- (void).cxx_destruct;
@end


/*****************************************************************/

@interface MesaCoreAnalyticsHelper : NSObject
+ (id)mesaCaDeviceTypeFromBioDeviceType:(unsigned int)v1;
@end


/*****************************************************************/

@interface MesaCAImageInfo : NSObject {
    NSNumber * _assessment;
    NSNumber * _feedback;
    NSNumber * _tidButtonState;
    NSNumber * _imageProblemClass;
    NSNumber * _wakeOnMenuPinUsed;
    NSNumber * _imagePixelOutlierCount;
    NSNumber * _imageContrast;
    NSNumber * _imageBrightness;
    NSNumber * _imageFeatureStrength;
    NSNumber * _imageContrastNorm;
    NSNumber * _imageBrightnessNorm;
    NSNumber * _imageFeatureStrengthNorm;
    NSNumber * _driveVoltage;
    NSData * _deblurringInfo;
    struct anonymous_type_95 _source;
}
@property struct anonymous_type_96 source;
@property (retain) NSNumber * assessment;
@property (retain) NSNumber * feedback;
@property (retain) NSNumber * tidButtonState;
@property (retain) NSNumber * imageProblemClass;
@property (retain) NSNumber * wakeOnMenuPinUsed;
@property (retain) NSNumber * imagePixelOutlierCount;
@property (retain) NSNumber * imageContrast;
@property (retain) NSNumber * imageBrightness;
@property (retain) NSNumber * imageFeatureStrength;
@property (retain) NSNumber * imageContrastNorm;
@property (retain) NSNumber * imageBrightnessNorm;
@property (retain) NSNumber * imageFeatureStrengthNorm;
@property (retain) NSNumber * driveVoltage;
@property (retain) NSData * deblurringInfo;
+ (id)imageInfoFromImageProcessingResult:(id)v1;
+ (id)imageInfoFromAccessoryImageInfo:(id)v1 souceBioDevice:(struct anonymous_type_97)v2;
- (void).cxx_destruct;
@end


/*****************************************************************/

@interface MesaCoreAnalytics : BiometricKitDStatistics {
    int _currentBioOpType;
    MesaCoreAnalyticsEvent * _currentEvent;
    MesaCoreAnalyticsMatchEvent * _matchEvent;
    MesaCoreAnalyticsUnlockEvent * _unlockEvent;
    MesaCoreAnalyticsEnrollEvent * _enrollEvent;
    MesaCoreAnalyticsFingerTouchTimeEvent * _fingerTouchTimeEvent;
    MesaCoreAnalyticsFingerLiftTimeEvent * _fingerLiftTimeEvent;
    MesaCoreAnalyticsDailyEvent * _dailyEvent;
    MesaCoreAnalyticsWeeklyEvent * _weeklyEvent;
    unsigned char _internalSensorType;
    unsigned long long _lastMatchAttemptTimeOffset;
    bool _displayOn;
    MesaCoreAnalyticsMatchEvent * _preArmedMatchEvent;
    BioLog * _bioLog;
    NSMutableArray * _events;
    NSObject<OS_dispatch_queue> * _analyticsDispatchQueue;
    unsigned long long _totalScanGroupCount;
    unsigned long long _totalScanCount;
}
+ (id)statistics;
- (id)init;
- (void)updateBioLog:(id)v1;
- (void)serviceMatch;
- (void)initSensor;
- (void)startBioOperation:(id)v1;
- (void)stopBioOperation;
- (void)cancel;
- (void)timestampEvent:(unsigned long long)v1 absoluteTime:(unsigned long long)v2;
- (void)startMatchOperation:(id)v1;
- (void)startMatchAttempt:(id)v1;
- (void)matchResult:(id)v1 withDictionary:(id)v2;
- (void)matchAttemptFinished:(bool)v1;
- (void)matchOperationFinished:(bool)v1;
- (void)matchEventFinished;
- (id)getWakeReason;
- (void)unlockAttemptStarted:(bool)v1;
- (void)unlockAttemptCanceled:(bool)v1;
- (void)unlockedByMesa;
- (void)unlockedByPasscode;
- (void)unlockAttemptFinished;
- (void)unlockEventFinished;
- (void)startEnrollOperation:(id)v1;
- (void)enrollProgress:(id)v1;
- (void)enrollEventFinished;
- (void)postDailyAndWeeklyUpdates;
- (void)templateUpdate:(id)v1 withDictionary:(id)v2;
- (void)addIdentitity:(id)v1;
- (void)removeIdentity:(id)v1;
- (void)removeAllIdentities;
- (void)resetMatchCounts;
- (id)getDaysSinceEnrollment;
- (id)getDaysSinceLastEnrollment;
- (id)getEnrolledUserIDs;
- (id)getEnrolledUsersCount;
- (id)getEnrolledIdentitiesCountForUser:(id)v1;
- (id)getEnrolledIdentitiesCountTotal;
- (id)getProtectedConfigurationMergedForAllUsers;
- (id)getEnrolledIdentitiesCountForAccessory:(id)v1;
- (id)getEnrolledUserIDsForAccessory:(id)v1;
- (void)setAccessoryTemplateStatsToEvent:(id)v1;
- (id)getGroupTypeForAccessory:(id)v1;
- (void)statusMessage:(unsigned int)v1 withData:(id)v2;
- (void)statisticsMessage:(struct anonymous_type_98 *)v1;
- (void)homeButtonStateChanged:(bool)v1;
- (void)lockStateUpdated:(unsigned int)v1;
- (void)displayStatusChanged:(bool)v1;
- (void)catacombCorrupted:(long long)v1;
- (void)setInternalSensorType:(unsigned char)v1;
- (void)logSensorSelfTestInfo;
- (id)deviceOrientation;
- (void)addBioAccessory:(id)v1;
- (void)accessoryImageInfo:(id)v1;
- (void).cxx_destruct;
@end


/*****************************************************************/

@interface TemplateInfo : NSObject {
    short _totalNodeCount;
    short _largestComponentNodeCount;
    short _clusterCount;
    double _totalArea;
    double _largestComponentArea;
    NSDate * _creationTime;
    long long _matchCount;
    long long _updateCount;
    NSNumber * _userID;
    BiometricKitAccessory * _accessory;
}
@property short totalNodeCount;
@property double totalArea;
@property short largestComponentNodeCount;
@property double largestComponentArea;
@property short clusterCount;
@property (retain,nonatomic) NSDate * creationTime;
@property (nonatomic) long long matchCount;
@property (nonatomic) long long updateCount;
@property (retain) NSNumber * userID;
@property (retain,nonatomic) BiometricKitAccessory * accessory;
- (void).cxx_destruct;
@end


/*****************************************************************/

@interface ADEvent : NSObject {
    long long _operation;
    long long _storage;
    long long _key;
    NSString * _stringKey;
    NSNumber * _value;
}
@property long long operation;
@property long long storage;
@property long long key;
@property (retain) NSString * stringKey;
@property (retain) NSNumber * value;
+ (id)eventWithOperation:(long long)v1 Storage:(long long)v2 Key:(long long)v3 Value:(id)v4;
+ (id)eventWithOperation:(long long)v1 Storage:(long long)v2 StringKey:(id)v3 Value:(id)v4;
- (id)initWithOperation:(long long)v1 Storage:(long long)v2 Key:(long long)v3 StringKey:(id)v4 Value:(id)v5;
- (id)stringKey:(long long)v1 useCase:(int)v2 prearmedApplePay:(bool)v3;
- (void)pushToAggregateDictionary:(long long)v1 useCase:(int)v2 prearmedApplePay:(bool)v3;
- (id)description;
- (void).cxx_destruct;
@end


/*****************************************************************/

@interface ADStorage : NSObject {
    NSMutableArray * _eventList;
}
+ (id)storage;
- (id)init;
- (void)addEvent:(id)v1;
- (void)pushToAggregateDictionary:(long long)v1 useCase:(int)v2 prearmedApplePay:(bool)v3;
- (void)clear;
- (void).cxx_destruct;
@end


/*****************************************************************/

@interface BiometricKitDStatistics : NSObject {
    ADStorage * _storage;
    bool _fingerOn;
    bool _unlockOperationInProgress;
    bool _unlockOperationStartedByCommand;
    bool _matchOperationInProgress;
    bool _haveMatchResult;
    bool _waitingForMatchResult;
    bool _haveImageToProcess;
    bool _matchWithDesensePauseLogged;
    bool _deviceWokeUpByHomeButton;
    bool _deviceWokeUpByLiftToWake;
    bool _pressureMitigationUsed;
    bool _prearmedApplePay;
    bool _lastMatchResultWakePin;
    bool _homeButtonPressedDuringTouch;
    int _lastBioOp;
    int _lastMatchUseCase;
    unsigned int _sksLockState;
    unsigned int _previousSKSLockState;
    float _modulationRatio;
    NSMutableDictionary * _templateStats;
    long long _lastStartedMatch;
    NSString * _clientName;
    unsigned long long _lastMatchResultID;
    unsigned long long _sensorOperationMode;
    NSDate * _sensorOperationStartDate;
    unsigned long long _imagesPerFingerDown;
    unsigned long long _sensorCaptureRestartsPerFingerDown;
    unsigned long long _imageCaptureRestartsPerFingerDown;
    unsigned long long _failTouchesToUnlock;
    unsigned long long _failQuickTapsToUnlock;
    unsigned long long _failTouchesToMatch;
    unsigned long long _matchRestarts;
    long long _calibrationDataState;
    BiometricKitXPCServerMesa * _server;
}
@property (retain) NSMutableDictionary * templateStats;
@property bool fingerOn;
@property bool unlockOperationInProgress;
@property bool unlockOperationStartedByCommand;
@property bool matchOperationInProgress;
@property bool haveMatchResult;
@property bool waitingForMatchResult;
@property bool haveImageToProcess;
@property bool matchWithDesensePauseLogged;
@property bool deviceWokeUpByHomeButton;
@property bool deviceWokeUpByLiftToWake;
@property bool pressureMitigationUsed;
@property bool prearmedApplePay;
@property bool lastMatchResultWakePin;
@property bool homeButtonPressedDuringTouch;
@property int lastBioOp;
@property long long lastStartedMatch;
@property int lastMatchUseCase;
@property (retain) NSString * clientName;
@property unsigned long long lastMatchResultID;
@property unsigned int sksLockState;
@property unsigned int previousSKSLockState;
@property unsigned long long sensorOperationMode;
@property (retain) NSDate * sensorOperationStartDate;
@property unsigned long long imagesPerFingerDown;
@property unsigned long long sensorCaptureRestartsPerFingerDown;
@property unsigned long long imageCaptureRestartsPerFingerDown;
@property unsigned long long failTouchesToUnlock;
@property unsigned long long failQuickTapsToUnlock;
@property unsigned long long failTouchesToMatch;
@property unsigned long long matchRestarts;
@property long long calibrationDataState;
@property float modulationRatio;
@property BiometricKitXPCServerMesa * server;
+ (id)statistics;
+ (unsigned int)clusterCount:(struct anonymous_type_100 *)v1;
- (id)init;
- (void)serviceMatch;
- (void)initSensor;
- (void)startBioOperation:(id)v1;
- (void)startMatchOperation:(id)v1;
- (void)cancel;
- (void)timestampEvent:(unsigned long long)v1 absoluteTime:(unsigned long long)v2;
- (void)matchResult:(id)v1 withDictionary:(id)v2;
- (void)templateUpdate:(id)v1 withDictionary:(id)v2;
- (void)addIdentitity:(id)v1;
- (void)removeIdentity:(id)v1;
- (void)removeAllIdentities;
- (void)resetMatchCounts;
- (void)statusMessage:(unsigned int)v1;
- (void)handleSensorOperationStatusMessage:(unsigned int)v1;
- (void)matchAttemptFinished:(bool)v1;
- (void)statisticsMessage:(struct anonymous_type_103 *)v1;
- (void)homeButtonStateChanged:(bool)v1;
- (void)updateDailyValues;
- (void)logTemplateCountPerUser:(bool)v1;
- (void)lockStateUpdated:(unsigned int)v1;
- (unsigned long long)totalClusterCount;
- (unsigned long long)totalNodeCount;
- (unsigned long long)totalPrimaryClusterNodeCount;
- (double)totalArea;
- (double)totalPrimaryClusterArea;
- (void)logTemplateAttributes:(bool)v1;
- (void)logTemplateMatchCounts;
- (bool)isMesaEnabled;
- (void)unlockedByMesa;
- (void)unlockedByPasscode;
- (void)displayStatusChanged:(bool)v1;
- (void)unlockAttemptCanceled:(bool)v1;
- (void)unlockAttemptStarted:(bool)v1;
- (void)unlockAttemptFinished;
- (void)matchOperationStarted;
- (void)matchOperationFinished:(bool)v1;
- (bool)isPasscodeNeeded;
- (bool)wasPasscodeNeeded;
- (bool)passcodeNedded:(long long)v1;
- (void)lastImageIsProcessed;
- (void)logFingerOff;
- (void)catacombCorrupted:(long long)v1;
- (bool)wasDeviceHibernated:(struct anonymous_type_105 *)v1;
- (void)postEvent:(id)v1;
- (id)getSensorSelfTestResult;
- (void)logSensorSelfTestInfo;
- (void).cxx_destruct;
@end
