#include "Paddle.h"

Paddle::Paddle(const Vect<float>& topleft, const Vect<float>& bottomright)
	:
	hitbox(topleft,bottomright)
{
}

Paddle::Paddle(float x1, float y1, float x2, float y2)
	:
	Paddle(Vect<float>(x1, y1), Vect<float>(x2, y2))
{

}
