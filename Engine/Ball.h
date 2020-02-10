#pragma once
#include "Vect.h"
#include "Rect.h"
#include "Graphics.h"
#include "Paddle.h"


class Ball
{
public:
	//constructors
	Ball(const Vect<float>& topleft, float dimension, const Vect<float>& speed, Color c);
	Ball(const Vect<float>& topleft, float dimension, float speed_x,float speed_y, Color c);
	Ball(float x1, float y1, float dimension,const Vect<float>& speed, Color c);
	Ball(float x1, float y1, float dimension, float speed_x, float speed_y, Color c);
	
	//functions
	Rect<float> GetHitBox() const;
	void Move(float delta_time);
	void Draw(Graphics& gfx) const;
	void InvertXMovement();
	void InvertYMovement();
	void SetMovementToRight();
	void SetMovementToLeft();
	void SetPosition(float in_x, float in_y);
	void SetSpeed(float in_x, float in_y);
	bool IsColliding(const Rect<float>& paddlehitbox) const;
	bool SnapToLimitBorderTOPBOTTOM(const Rect<float>& border); //This automatically reverses the ball's speed on the concerned axis.
	bool SnapToLimitBorderLEFTRIGHT(const Rect<float>& border); //This automatically reverses the ball's speed on the concerned axis.
	void GenerateRandomSpeed();
private:
	Vect<float> topleft;
	Vect<float> speed;
	Color c;
	const float dimension;
	static constexpr float max_speed = 500.f;
	static constexpr float min_speed = 250.f;
};