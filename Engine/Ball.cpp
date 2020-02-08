#include "Ball.h"

Ball::Ball(const Vect<float>& topleft, float dimension, const Vect<float>& speed)
	:
	topleft(topleft),
	dimension(dimension),
	speed(speed)
{
}

Ball::Ball(const Vect<float>& topleft, float dimension, float speed_x, float speed_y)
	:
	Ball(topleft, dimension, Vect<float>(speed_x, speed_y))
{
}

Ball::Ball(float x1, float y1, float dimension, const Vect<float>& speed)
	:
	Ball(Vect<float>(x1,y1),dimension,speed)
{
}

Ball::Ball(float x1, float y1, float dimension, float speed_x, float speed_y)
	:
	Ball(x1,y1,dimension,Vect<float>(speed_x,speed_y))
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
