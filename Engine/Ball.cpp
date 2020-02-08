#include "Ball.h"

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

void Ball::Draw(Graphics & gfx)
{
	gfx.DrawRect(GetHitBox(), c);
}

