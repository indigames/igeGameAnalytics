#include "GameAnalyticsImpl.h"
#include "GAnalytics.h"
#include "GameAnalyticsHelper.h"


void GameAnalyticsImpl::Init(const char* version, const char* game_key, const char* secret_key, bool debug)
{
    bool envAttached = false;
    JNIEnv *env = GameAnalyticsGetJniEnv(envAttached);
	jstring _version = env->NewStringUTF(version);
	jstring _game_key = env->NewStringUTF(game_key);
	jstring _secret_key = env->NewStringUTF(secret_key);

    env->CallStaticVoidMethod(mGameAnalyticsClass, midGameAnalyticsInit, _version, _game_key, _secret_key, debug);

	env->DeleteLocalRef(_version);
	env->DeleteLocalRef(_game_key);
	env->DeleteLocalRef(_secret_key);
	GameAnalyticsDetachVM(envAttached);
}

void GameAnalyticsImpl::Release()
{
}

void GameAnalyticsImpl::addProgressionEvent(int progressionStatus, const char* progression01, const char* progression02, const char* progression03)
{
	bool envAttached = false;
	JNIEnv *env = GameAnalyticsGetJniEnv(envAttached);
	if(progression01 != nullptr && progression02 != nullptr && progression03 != nullptr)
	{
		jstring _progression01 = env->NewStringUTF(progression01);
		jstring _progression02 = env->NewStringUTF(progression02);
		jstring _progression03 = env->NewStringUTF(progression03);

		env->CallStaticVoidMethod(mGameAnalyticsClass, midGameAnalyticsAddProgressionEvent123, progressionStatus, _progression01, _progression02, _progression03);

		env->DeleteLocalRef(_progression01);
		env->DeleteLocalRef(_progression02);
		env->DeleteLocalRef(_progression03);
	}
	else if(progression01 != nullptr && progression02 != nullptr)
	{
		jstring _progression01 = env->NewStringUTF(progression01);
		jstring _progression02 = env->NewStringUTF(progression02);

		env->CallStaticVoidMethod(mGameAnalyticsClass, midGameAnalyticsAddProgressionEvent12, progressionStatus, _progression01, _progression02);

		env->DeleteLocalRef(_progression01);
		env->DeleteLocalRef(_progression02);
	}
	else if(progression01 != nullptr)
	{
		jstring _progression01 = env->NewStringUTF(progression01);

		env->CallStaticVoidMethod(mGameAnalyticsClass, midGameAnalyticsAddProgressionEvent1, progressionStatus, _progression01);

		env->DeleteLocalRef(_progression01);
	}
	GameAnalyticsDetachVM(envAttached);
}

void GameAnalyticsImpl::addProgressionEvent(int progressionStatus, const char* progression01, const char* progression02, const char* progression03, int score)
{
	bool envAttached = false;
	JNIEnv *env = GameAnalyticsGetJniEnv(envAttached);
	if(progression01 != nullptr && progression02 != nullptr && progression03 != nullptr)
	{
		jstring _progression01 = env->NewStringUTF(progression01);
		jstring _progression02 = env->NewStringUTF(progression02);
		jstring _progression03 = env->NewStringUTF(progression03);

		env->CallStaticVoidMethod(mGameAnalyticsClass, midGameAnalyticsAddProgressionEvent123Score, progressionStatus, _progression01, _progression02, _progression03, score);

		env->DeleteLocalRef(_progression01);
		env->DeleteLocalRef(_progression02);
		env->DeleteLocalRef(_progression03);
	}
	else if(progression01 != nullptr && progression02 != nullptr)
	{
		jstring _progression01 = env->NewStringUTF(progression01);
		jstring _progression02 = env->NewStringUTF(progression02);

		env->CallStaticVoidMethod(mGameAnalyticsClass, midGameAnalyticsAddProgressionEvent12Score, progressionStatus, _progression01, _progression02, score);

		env->DeleteLocalRef(_progression01);
		env->DeleteLocalRef(_progression02);
	}
	else if(progression01 != nullptr)
	{
		jstring _progression01 = env->NewStringUTF(progression01);

		env->CallStaticVoidMethod(mGameAnalyticsClass, midGameAnalyticsAddProgressionEvent1Score, progressionStatus, _progression01, score);

		env->DeleteLocalRef(_progression01);
	}
	GameAnalyticsDetachVM(envAttached);
}

void GameAnalyticsImpl::addDesignEvent(const char* eventId)
{
	bool envAttached = false;
	JNIEnv *env = GameAnalyticsGetJniEnv(envAttached);
	jstring _eventId = env->NewStringUTF(eventId);
	env->CallStaticVoidMethod(mGameAnalyticsClass, midGameAnalyticsAddDesignEvent, _eventId);

	GameAnalyticsDetachVM(envAttached);
}

void GameAnalyticsImpl::addDesignEvent(const char* eventId, double value)
{
	bool envAttached = false;
	JNIEnv *env = GameAnalyticsGetJniEnv(envAttached);
	jstring _eventId = env->NewStringUTF(eventId);
	env->CallStaticVoidMethod(mGameAnalyticsClass, midGameAnalyticsAddDesignEventValue, _eventId, value);

	GameAnalyticsDetachVM(envAttached);
}