#include "FrameTime.h"


FrameTime::FrameTime()
{
	last = std::chrono::steady_clock::now();
}

float FrameTime::mark()
{
	auto old = last;
	last = std::chrono::steady_clock::now();
	std::chrono::duration<float> frametime = last - old;
	return frametime.count();
}
