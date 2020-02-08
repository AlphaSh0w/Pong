#pragma once
#include "Vect.h"
#include "Rect.h"

class Paddle
{
public:
	//constructors
	Paddle(const Vect<float>& topleft, float length, float width,Vect<float>& speed);
	Paddle(float x1, float y1, float length, float width, float speed_x, float speed_y);

	//functions
	Rect<float> GetHitBox() const;
	void Move(float delta_time);
private:
	Vect<float> topleft;
	Vect<float> speed;
	float height;
	float width;
};