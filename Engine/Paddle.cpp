#include "Paddle.h"

Paddle::Paddle(Vect<float>& topleft, Vect<float>& bottomright)
	:topleft(topleft),
	bottomright(bottomright)
{
}

Paddle::Paddle(float x1, float y1, float x2, float y2)
	:
	Paddle(Vect<float>(x1, y1), Vect<float>(x2, y2))
{

}
