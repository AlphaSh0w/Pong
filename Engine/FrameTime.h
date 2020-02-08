#pragma once
#include <chrono>

class FrameTime
{
public:
	FrameTime();
	float mark();
private:
	std::chrono::steady_clock::time_point last;
};