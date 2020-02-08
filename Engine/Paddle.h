#pragma once
#include "Vect.h"

class Paddle
{
public:
	Paddle(const Vect<float>& topleft, const Vect<float>& topright);
	Paddle(float x1, float y1, float x2, float y2);
private:
	Vect<float> topleft;
	Vect<float> bottomright;
};