#pragma once
#include "Vect.h"
#include "Rect.h"

class Ball
{
public:
	Ball(const Vect<float>& topleft, float dimension);
	Ball(float x1, float y1, float dimension);
	Rect<float> GetHitBox();
private:
	Vect<float> topleft;
	float dimension;
};