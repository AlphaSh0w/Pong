#include "Paddle.h"
#include <assert.h>

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

void Paddle::Move(const Vect<float>& direction,float delta_time)
{
	topleft += speed * direction * delta_time;
}

bool Paddle::SnapToLimitBorder(const Rect<float> border)
{
	bool hitborder_y = false;
	if (topleft.y < border.topleft.y)
	{
		topleft.y += border.topleft.y - topleft.y;
		hitborder_y = true;
	}
	
	if (topleft.y + height> border.bottomright.y)
	{
		assert(hitborder_y == false); //If assertion fails: the height of the paddle is too big to fit into the given border.
		topleft.y -= (topleft.y + height) - border.bottomright.y;
		hitborder_y = true;
	}

	bool hitborder_x = false;
	if (topleft.x < border.topleft.x)
	{
		topleft.x += border.topleft.x - topleft.x;
		hitborder_x = true;
	}
	
	if (topleft.x + width > border.bottomright.x)
	{
		assert(hitborder_x == false); //If assertion fails : The width of the paddle is too big to fit into the given border.
		topleft.x -= (topleft.x + width) - border.bottomright.x;
		hitborder_x = true;
	}
	return (hitborder_x || hitborder_y);
}

void Paddle::Draw(Graphics & gfx)
{
	gfx.DrawRect(GetHitBox(), c);
}
