#include <jni.h>
#include "GAnalytics.h"
#include "android/log.h"

static const char* className = "net/indigames/lib/GameAnalyticsHelper";

extern jclass mGameAnalyticsClass;
/* method signatures */
extern jmethodID midGameAnalyticsInit;
extern jmethodID midGameAnalyticsRelease;
extern jmethodID midGameAnalyticsAddProgressionEvent1;
extern jmethodID midGameAnalyticsAddProgressionEvent1Score;
extern jmethodID midGameAnalyticsAddProgressionEvent12;
extern jmethodID midGameAnalyticsAddProgressionEvent12Score;
extern jmethodID midGameAnalyticsAddProgressionEvent123;
extern jmethodID midGameAnalyticsAddProgressionEvent123Score;
extern jmethodID midGameAnalyticsAddDesignEvent;
extern jmethodID midGameAnalyticsAddDesignEventValue;

void GameAnalytics_NativeInit(JavaVM* vm);
JNIEnv* GameAnalyticsGetJniEnv(bool &envAttached);
void GameAnalyticsDetachVM(bool envAttached);