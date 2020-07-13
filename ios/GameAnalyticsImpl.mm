#include "GameAnalyticsImpl.h"
#include "GAnalytics.h"

#import "GameAnalytics.h"

void GameAnalyticsImpl::Init(const char* version, const char* game_key, const char* secret_key, bool debug)
{
    if (debug)
    {
        [GameAnalytics setEnabledInfoLog:YES];
        [GameAnalytics setEnabledVerboseLog:YES];
    }
    [GameAnalytics configureAutoDetectAppVersion:YES];
    auto _game_key = [NSString stringWithUTF8String:game_key];
    auto _secret_key = [NSString stringWithUTF8String:secret_key];
    [GameAnalytics initializeWithGameKey:_game_key gameSecret:_secret_key];
}

void GameAnalyticsImpl::Release()
{
}

void GameAnalyticsImpl::addProgressionEvent(int progressionStatus, const char* progression01, const char* progression02, const char* progression03)
{
    auto _progression01 = progression01 ? [NSString stringWithUTF8String:progression01] : nil;
    auto _progression02 = progression02 ? [NSString stringWithUTF8String:progression02] : nil;
    auto _progression03 = progression03 ? [NSString stringWithUTF8String:progression03] : nil;
    [GameAnalytics addProgressionEventWithProgressionStatus:(GAProgressionStatus)progressionStatus progression01:_progression01 progression02:_progression02 progression03:_progression03];
}

void GameAnalyticsImpl::addProgressionEvent(int progressionStatus, const char* progression01, const char* progression02, const char* progression03, int score)
{
    auto _progression01 = progression01 ? [NSString stringWithUTF8String:progression01] : nil;
    auto _progression02 = progression02 ? [NSString stringWithUTF8String:progression02] : nil;
    auto _progression03 = progression03 ? [NSString stringWithUTF8String:progression03] : nil;
    [GameAnalytics addProgressionEventWithProgressionStatus:(GAProgressionStatus)progressionStatus progression01:_progression01 progression02:_progression02 progression03:_progression03 score:score];
}

void GameAnalyticsImpl::addDesignEvent(const char* eventId)
{
    auto _eventId = [NSString stringWithUTF8String:eventId];
    [GameAnalytics addDesignEventWithEventId:_eventId];
}

void GameAnalyticsImpl::addDesignEvent(const char* eventId, double value)
{
    auto _eventId = [NSString stringWithUTF8String:eventId];
    [GameAnalytics addDesignEventWithEventId:_eventId value:[NSNumber numberWithDouble:value]];
}
