#pragma once

#include "GameBase.h"

class Timer
{
public:
	Timer();

	Uint32 getTicks();

	void start();
	void stop();
	void pause();
	void unpause();

	bool isStarted();
	bool isPaused();

private:
	Uint32 mStartTicks;
	Uint32 mPausedTicks;

	bool mPaused;
	bool mStarted;
};