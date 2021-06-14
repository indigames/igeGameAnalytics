#include "GameAnalyticsImpl.h"
#include "GAnalytics.h"

#ifdef BUILD_EXTENSION
    #include "GameAnalytics.h"
    using namespace gameanalytics;
#endif

void GameAnalyticsImpl::Init(const char* version, const char* game_key, const char* secret_key, bool debug)
{
#ifdef BUILD_EXTENSION
	if (debug)
	{
		GameAnalytics::setEnabledInfoLog(true);
		GameAnalytics::setEnabledVerboseLog(true);
	}
	GameAnalytics::configureBuild(version);
	GameAnalytics::initialize(game_key, secret_key);
#endif
}

void GameAnalyticsImpl::Release()
{
#ifdef BUILD_EXTENSION
	GameAnalytics::onQuit();
#endif
}

void GameAnalyticsImpl::addProgressionEvent(int progressionStatus, const char* progression01, const char* progression02, const char* progression03)
{
#ifdef BUILD_EXTENSION
	GameAnalytics::addProgressionEvent((EGAProgressionStatus)progressionStatus, progression01, progression02, progression03);
#endif
}

void GameAnalyticsImpl::addProgressionEvent(int progressionStatus, const char* progression01, const char* progression02, const char* progression03, int score)
{
#ifdef BUILD_EXTENSION
	GameAnalytics::addProgressionEvent((EGAProgressionStatus)progressionStatus, progression01, progression02, progression03, score);
#endif
}

void GameAnalyticsImpl::addDesignEvent(const char* eventId)
{
#ifdef BUILD_EXTENSION
	GameAnalytics::addDesignEvent(eventId);
#endif
}

void GameAnalyticsImpl::addDesignEvent(const char* eventId, double value)
{
#ifdef BUILD_EXTENSION
	GameAnalytics::addDesignEvent(eventId, value);
#endif
}