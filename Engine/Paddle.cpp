#include "Paddle.h"
#include <cassert>

Paddle::Paddle(const Vect<float>& topleft, float height, float width, Vect<float>& speed,Side side, Color c)
	:
	topleft(topleft),
	height(height),
	width(width),
	speed(speed),
	side(side),
	c(c)
{
}

Paddle::Paddle(float x1, float y1, float height, float width, float speed_x, float speed_y,Side side, Color c)
	:
	Paddle(Vect<float>(x1,y1),height,width,Vect<float>(speed_x,speed_y),side,c)
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
	Rect<float> currenthitbox = GetHitBox();

	bool hitborder_y = false;
	if (currenthitbox.topleft.y < border.topleft.y)
	{
		topleft.y += border.topleft.y - currenthitbox.topleft.y;
		hitborder_y = true;
	}
	
	if (currenthitbox.bottomright.y > border.bottomright.y)
	{
		assert(hitborder_y == false); //If assertion fails: the height of the paddle is too big to fit into the given border.
		topleft.y -= currenthitbox.bottomright.y - border.bottomright.y;
		hitborder_y = true;
	}

	bool hitborder_x = false;
	if (currenthitbox.topleft.x < border.topleft.x)
	{
		topleft.x += border.topleft.x - currenthitbox.topleft.x;
		hitborder_x = true;
	}
	
	if (currenthitbox.bottomright.x > border.bottomright.x)
	{
		assert(hitborder_x == false); //If assertion fails : The width of the paddle is too big to fit into the given border.
		topleft.x -= currenthitbox.bottomright.x - border.bottomright.x;
		hitborder_x = true;
	}
	return (hitborder_x || hitborder_y);
}

void Paddle::Draw(Graphics & gfx) const
{
	gfx.DrawRect(GetHitBox(), c);
}

void Paddle::SetPosition(Vect<float>& in_topleft)
{
	topleft = in_topleft;
}

float Paddle::GetWidth() const
{
	return width;
}

float Paddle::GetHeight() const
{
	return height;
}

Vect<float> Paddle::GetCenter() const
{
	return Vect<float>(topleft.x + width/2,topleft.y + height/2);
}

Side Paddle::GetSide() const
{
	return side;
}
