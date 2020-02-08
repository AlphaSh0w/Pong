#pragma once
#include "Vect.h"
#include "Rect.h"

class Paddle
{
public:
	Paddle(const Vect<float>& topleft, float length, float width);
	Paddle(float x1, float y1, float length, float width);
	Rect<float> gethitbox();
private:
	Vect<float> topleft;
	float height;
	float width;
};