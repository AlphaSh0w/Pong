#include "Paddle.h"

Paddle::Paddle(const Vect<float>& topleft, float height, float width, Vect<float>& speed, Color c)
	:
	topleft(topleft),
	height(height),
	width(width),
	speed(speed),
	c(c)
{
}

Paddle::Paddle(float x1, float y1, float height, float width, float speed_x, float speed_y, Color c)
	:
	Paddle(Vect<float>(x1,y1),height,width,Vect<float>(speed_x,speed_y),c)
{
}

Rect<float> Paddle::GetHitBox() const
{
	return Rect<float>(topleft, topleft.x + width, topleft.y + height);
}

void Paddle::Move(float delta_time)
{
	topleft += speed * delta_time;
}

void Paddle::Draw(Graphics & gfx)
{
	gfx.DrawRect(GetHitBox(), c);
}
