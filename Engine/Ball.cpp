#include "Ball.h"

Ball::Ball(const Vect<float>& topleft, float dimension)
	:
	topleft(topleft),
	dimension(dimension)
{
}

Ball::Ball(float x1, float y1, float dimension)
	:
	Ball(Vect<float>(x1,y1),dimension)
{
}

Rect<float> Ball::GetHitBox()
{
	return Rect<float>(topleft, topleft.x + dimension, topleft.y + dimension);
}
