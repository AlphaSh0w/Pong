#include "Ball.h"
#include <assert.h>

Ball::Ball(const Vect<float>& topleft, float dimension, const Vect<float>& speed, Color c)
	:
	topleft(topleft),
	dimension(dimension),
	speed(speed),
	c(c)
{
}

Ball::Ball(const Vect<float>& topleft, float dimension, float speed_x, float speed_y, Color c)
	:
	Ball(topleft, dimension, Vect<float>(speed_x, speed_y),c)
{
}

Ball::Ball(float x1, float y1, float dimension, const Vect<float>& speed, Color c)
	:
	Ball(Vect<float>(x1,y1),dimension,speed,c)
{
}

Ball::Ball(float x1, float y1, float dimension, float speed_x, float speed_y, Color c)
	:
	Ball(x1,y1,dimension,Vect<float>(speed_x,speed_y),c)
{
}

Rect<float> Ball::GetHitBox() const
{
	return Rect<float>(topleft, topleft.x + dimension, topleft.y + dimension);
}

void Ball::Move(float delta_time)
{
	topleft += speed * delta_time;
}

void Ball::Draw(Graphics & gfx) const
{
	gfx.DrawRect(GetHitBox(), c);
}

void Ball::InvertXMovement()
{
	speed.x = -speed.x;
}

void Ball::InvertYMovement()
{
	speed.y = -speed.y;
}

void Ball::SetMovementToRight()
{
	if (speed.x < 0.f)
	{
		speed.x = -speed.x;
	}
}

void Ball::SetMovementToLeft()
{
	if (speed.x > 0.f)
	{
		speed.x = -speed.x;
	}
}

bool Ball::IsColliding(const Rect<float>& paddlehitbox) const
{
	Rect<float> ballhitbox = GetHitBox();
	return (ballhitbox.topleft.x <= paddlehitbox.bottomright.x && ballhitbox.topleft.y <= paddlehitbox.bottomright.y
		&& ballhitbox.bottomright.x >= paddlehitbox.topleft.x && ballhitbox.bottomright.y >= paddlehitbox.topleft.y);
}

bool Ball::SnapToLimitBorder(const Rect<float>& border)
{
	Rect<float> currenthitbox = GetHitBox();

	bool hitborder_y = false;
	if (currenthitbox.topleft.y < border.topleft.y)
	{
		topleft.y += border.topleft.y - currenthitbox.topleft.y;
		InvertYMovement();
		hitborder_y = true;
	}

	if (currenthitbox.bottomright.y > border.bottomright.y)
	{
		assert(hitborder_y == false); //If assertion fails: the height of the ball is too big to fit into the given border.
		topleft.y -= currenthitbox.bottomright.y - border.bottomright.y;
		InvertYMovement();
		hitborder_y = true;
	}

	bool hitborder_x = false;
	if (currenthitbox.topleft.x < border.topleft.x)
	{
		topleft.x += border.topleft.x - currenthitbox.topleft.x;
		InvertXMovement();
		hitborder_x = true;
	}

	if (currenthitbox.bottomright.x > border.bottomright.x)
	{
		assert(hitborder_x == false); //If assertion fails : The width of the ball is too big to fit into the given border.
		topleft.x -= currenthitbox.bottomright.x - border.bottomright.x;
		InvertXMovement();
		hitborder_x = true;
	}
	return (hitborder_x || hitborder_y);
}

