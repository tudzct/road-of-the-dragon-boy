#include "Timer.h"

Timer::Timer()
{
	mStartTicks = mPausedTicks = 0;
	mStarted = mPaused = false;
}

void Timer::start()
{
	mStarted = true;
	mPaused = false;
	mStartTicks = SDL_GetTicks();
	mPausedTicks = 0;
}

void Timer::stop()
{
	mStarted = mPaused = false;
	mStarted = mPausedTicks = 0;
}

void Timer::pause()
{
	if (mStarted && !mPaused)
	{
		mPaused = true;
		mPausedTicks = SDL_GetTicks() - mStartTicks;
		mStartTicks = 0;
	}
}

void Timer::unpause()
{
	if (mStarted && mPaused)
	{
		mPaused = false;
		mStartTicks = SDL_GetTicks() - mPausedTicks;
		mPausedTicks = 0;
	}
}

Uint32 Timer::getTicks()
{
	Uint32 time = 0;
	if (mStarted)
	{
		if (mPaused)
		{
			time = mPausedTicks;
		}
		else
		{
			time = SDL_GetTicks() - mStartTicks;
		}
	}

	return time;
}

bool Timer::isStarted()
{
	return mStarted;
}

bool Timer::isPaused()
{
	return (mStarted && mPaused);
}