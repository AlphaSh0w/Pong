#include "Paddle.h"

Paddle::Paddle(const Vect<float>& topleft, float height, float width)
	:
	topleft(topleft),
	height(height),
	width(width)
{
}

Paddle::Paddle(float x1, float y1, float height, float width)
	:
	Paddle(Vect<float>(x1,y1),height,width)
{
}

Rect<float> Paddle::gethitbox() const
{
	return Rect<float>(topleft, topleft.x + width, topleft.y + height);
}
