#pragma once
#include "Vect.h"
#include "Rect.h"

class Ball
{
public:
	//constructors
	Ball(const Vect<float>& topleft, float dimension, const Vect<float>& speed);
	Ball(const Vect<float>& topleft, float dimension, float speed_x,float speed_y);
	Ball(float x1, float y1, float dimension,const Vect<float>& speed);
	Ball(float x1, float y1, float dimension, float speed_x, float speed_y);
	
	//functions
	Rect<float> GetHitBox() const;
	void Move(float delta_time);
private:
	Vect<float> topleft;
	Vect<float> speed;
	float dimension;
};