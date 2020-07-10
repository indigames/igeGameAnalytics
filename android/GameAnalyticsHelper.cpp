#include <jni.h>
#include "GameAnalyticsHelper.h"
#include "android/log.h"

JavaVM* gameAnalytics_VM;
jclass mGameAnalyticsClass;

/* method signatures */
jmethodID midGameAnalyticsInit;
jmethodID midGameAnalyticsRelease;
jmethodID midGameAnalyticsAddProgressionEvent1;
jmethodID midGameAnalyticsAddProgressionEvent1Score;
jmethodID midGameAnalyticsAddProgressionEvent12;
jmethodID midGameAnalyticsAddProgressionEvent12Score;
jmethodID midGameAnalyticsAddProgressionEvent123;
jmethodID midGameAnalyticsAddProgressionEvent123Score;
jmethodID midGameAnalyticsAddDesignEvent;
jmethodID midGameAnalyticsAddDesignEventValue;

void GameAnalytics_NativeInit(JavaVM* vm)
{
    gameAnalytics_VM = vm;

    JNIEnv* env;
    if (vm->GetEnv(reinterpret_cast<void**>(&env), JNI_VERSION_1_6) != JNI_OK) {
        return;
    }

    mGameAnalyticsClass = reinterpret_cast<jclass>(env->NewGlobalRef(env->FindClass(className)));

    midGameAnalyticsInit = env->GetStaticMethodID(mGameAnalyticsClass, "Init",
                                                  "(Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;Z)V");
    midGameAnalyticsRelease = env->GetStaticMethodID(mGameAnalyticsClass, "Release", "()V");
    midGameAnalyticsAddProgressionEvent1 = env->GetStaticMethodID(mGameAnalyticsClass, "AddProgressionEvent", "(ILjava/lang/String;)V");
    midGameAnalyticsAddProgressionEvent1Score = env->GetStaticMethodID(mGameAnalyticsClass, "AddProgressionEvent", "(ILjava/lang/String;I)V");
    midGameAnalyticsAddProgressionEvent12 = env->GetStaticMethodID(mGameAnalyticsClass, "AddProgressionEvent", "(ILjava/lang/String;Ljava/lang/String;)V");
    midGameAnalyticsAddProgressionEvent12Score = env->GetStaticMethodID(mGameAnalyticsClass, "AddProgressionEvent", "(ILjava/lang/String;Ljava/lang/String;I)V");
    midGameAnalyticsAddProgressionEvent123 = env->GetStaticMethodID(mGameAnalyticsClass, "AddProgressionEvent", "(ILjava/lang/String;Ljava/lang/String;Ljava/lang/String;)V");
    midGameAnalyticsAddProgressionEvent123Score = env->GetStaticMethodID(mGameAnalyticsClass, "AddProgressionEvent", "(ILjava/lang/String;Ljava/lang/String;Ljava/lang/String;I)V");
    midGameAnalyticsAddDesignEvent = env->GetStaticMethodID(mGameAnalyticsClass, "AddDesignEvent", "(Ljava/lang/String;)V");
    midGameAnalyticsAddDesignEventValue = env->GetStaticMethodID(mGameAnalyticsClass, "AddDesignEvent", "(Ljava/lang/String;D)V");
}

JNIEnv* GameAnalyticsGetJniEnv(bool &envAttached)
{
    JNIEnv* env;
    int getEnvStat = gameAnalytics_VM->GetEnv((void **)&env, JNI_VERSION_1_6);
    if (getEnvStat == JNI_EDETACHED)
    {
        envAttached = true;
        if (gameAnalytics_VM->AttachCurrentThread(&env, NULL) != 0) {
            LOG("Failed to attach env");
            return nullptr;
        }
    }
    else if (getEnvStat == JNI_EVERSION) {
        LOG("GetEnv: version not supported");
        return nullptr;
    }
    return env;
}

void GameAnalyticsDetachVM(bool envAttached)
{
    if(envAttached)
    {
        gameAnalytics_VM->DetachCurrentThread();
    }
}