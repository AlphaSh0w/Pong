#pragma once
#include "Vect.h"
#include "Rect.h"
#include "Graphics.h"
enum Side
{
	left,
	right
};

class Paddle
{
public:
	//constructors
	Paddle(const Vect<float>& topleft, float height, float width,Vect<float>& speed,Side side, Color c);
	Paddle(float x1, float y1, float height, float width, float speed_x, float speed_y,Side side, Color c);

	//functions
	Rect<float> GetHitBox() const;
	void Move(const Vect<float>& direction,float delta_time);
	bool SnapToLimitBorder(const Rect<float> border);
	void Draw(Graphics& gfx) const;
	void SetPosition(Vect<float>& in_topleft);
	float GetWidth() const;
	float GetHeight() const;
	Vect<float> GetCenter() const;
	Side GetSide() const;
private:
	Side side;
	Vect<float> topleft;
	Vect<float> speed;
	Color c;
	float height;
	float width;
};