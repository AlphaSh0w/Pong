#include "Ball.h"
#include <cassert>
#include <random>

Ball::Ball(const Vect<float>& topleft, float dimension, float min_speed, float max_speed, Color c)
	:
	topleft(topleft),
	dimension(dimension),
	min_speed(min_speed),
	max_speed(max_speed),
	c(c)

{
}


Ball::Ball(float x1, float y1, float dimension, float min_speed, float max_speed, Color c)
	:
	Ball(Vect<float>(x1,y1),dimension,min_speed,max_speed,c)
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

void Ball::SetPosition(float in_x, float in_y)
{
	topleft.x = in_x;
	topleft.y = in_y;
}


bool Ball::IsColliding(const Rect<float>& paddlehitbox) const
{
	Rect<float> ballhitbox = GetHitBox();
	return (ballhitbox.topleft.x <= paddlehitbox.bottomright.x && ballhitbox.topleft.y <= paddlehitbox.bottomright.y
		&& ballhitbox.bottomright.x >= paddlehitbox.topleft.x && ballhitbox.bottomright.y >= paddlehitbox.topleft.y);
}

bool Ball::SnapToLimitBorderTOPBOTTOM(const Rect<float>& border)
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

	
	return (hitborder_y);
}

bool Ball::SnapToLimitBorderLEFTRIGHT(const Rect<float>& border)
{
	Rect<float> currenthitbox = GetHitBox();
	
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
	return hitborder_x;
}

void Ball::GenerateRandomSpeed()
{

	std::random_device rd;
	std::mt19937 rng(rd());
	std::uniform_int_distribution<int> speed_dist((int)min_speed, (int)max_speed);
	std::uniform_int_distribution<int> bool_dist(0, 1);

	//generate the speeds
	speed.x = (float)speed_dist(rng);
	speed.y = (float)speed_dist(rng);
	//randomly choose the speed direction.
	if (bool_dist(rng))
	{
		speed.x = -speed.x;
	}
	if (bool_dist(rng))
	{
		speed.y = -speed.y;
	}

}


void Ball::AdjustYSpeedOnHit(const Paddle & paddle)
{
	Rect<float> paddle_hitbox = paddle.GetHitBox();
	const float paddle_center_y = paddle.GetCenter().y;
	const float ball_center_y = GetCenter().y;
	float coeficient = std::min(1.f,std::abs(paddle_center_y - ball_center_y) / (paddle.GetHeight() / 2));

	if (ball_center_y < paddle_center_y)
	{
		if (speed.y > 0.f)
		{
			speed.y = -max_speed * coeficient;
		}
		else
		{
			speed.y = -max_speed * coeficient;
		}
	}
	else
	{
		if (speed.y < 0.f)
		{
			speed.y = max_speed * coeficient;
		}
		else
		{
			speed.y = max_speed * coeficient;
		}
	}
}

float Ball::GetDimension() const
{
	return dimension;
}

Vect<float> Ball::GetCenter() const
{
	return Vect<float>(topleft.x + dimension/2, topleft.y + dimension/2);
}

Vect<float> Ball::GetSpeed() const
{
	return speed;
}
