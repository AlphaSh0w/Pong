#pragma once
#include "Vect.h"
#include "Rect.h"
#include "Graphics.h"

class Paddle
{
public:
	//constructors
	Paddle(const Vect<float>& topleft, float length, float width,Vect<float>& speed, Color c);
	Paddle(float x1, float y1, float length, float width, float speed_x, float speed_y, Color c);

	//functions
	Rect<float> GetHitBox() const;
	void Move(float delta_time);
	void Draw(Graphics& gfx);
private:
	Vect<float> topleft;
	Vect<float> speed;
	Color c;
	float height;
	float width;
};