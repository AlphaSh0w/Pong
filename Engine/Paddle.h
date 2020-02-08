#pragma once
#include "Vect.h"
#include "Rect.h"

class Paddle
{
public:
	Paddle(const Vect<float>& topleft, const Vect<float>& topright);
	Paddle(float x1, float y1, float x2, float y2);
private:
	Rect<float> hitbox;
};