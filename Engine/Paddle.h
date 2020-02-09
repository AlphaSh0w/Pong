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
	void Move(const Vect<float>& direction,float delta_time);
	bool SnapToLimitBorder(const Rect<float> border);
	void Draw(Graphics& gfx);
private:
	Vect<float> topleft;
	Vect<float> speed;
	Color c;
	float height;
	float width;
};