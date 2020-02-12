#pragma once
#include "Vect.h"
#include "Rect.h"
#include "Graphics.h"
#include "Paddle.h"

class Ball
{
public:
	//constructors
	Ball(const Vect<float>& topleft, float dimension, float min_speed,float max_speed, Color c);
	Ball(float x1, float y1, float dimension, float min_speed_x, float max_speed_y, Color c);
	
	//functions
	Rect<float> GetHitBox() const;
	void Move(float delta_time);
	void Draw(Graphics& gfx) const;
	void InvertXMovement();
	void InvertYMovement();
	void SetMovementToRight();
	void SetMovementToLeft();
	void SetPosition(float in_x, float in_y);
	bool IsColliding(const Rect<float>& paddlehitbox) const;
	bool SnapToLimitBorderTOPBOTTOM(const Rect<float>& border); //This automatically reverses the ball's speed on the concerned axis.
	bool SnapToLimitBorderLEFTRIGHT(const Rect<float>& border); //This automatically reverses the ball's speed on the concerned axis.
	void GenerateRandomSpeed();
	void AdjustYSpeedOnHit(const Paddle & paddle);
	float GetDimension() const;
	Vect<float> GetCenter() const;
	Vect<float> GetSpeed() const;

private:
	Vect<float> topleft;
	Vect<float> speed;
	Color c;
	float dimension;
	float min_speed = 400.f;
	float max_speed = 500.f;
};