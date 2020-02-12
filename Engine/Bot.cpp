#include "Bot.h"

#include <assert.h>

Bot::Bot(Paddle& controlled_paddle,float starting_y_seek,float simulation_precision,float seek_tolerance)
	:
	controlled_paddle(controlled_paddle),
	current_y_seek(starting_y_seek),
	seek_tolerance(seek_tolerance),
	simulation_precision(simulation_precision)
{
}

float Bot::SimulateBall(Ball ball,Rect<float>& play_area)
{
	const Rect<float> paddlehitbox = controlled_paddle.GetHitBox();

	if (controlled_paddle.GetSide() == Side::right)
	{
		assert(ball.GetSpeed().x > 0.f); //If assertion fails, the ball is going away from the paddle, which makes the simulation infinite as the ball will never reach the paddle.
		while (ball.GetHitBox().bottomright.x <= paddlehitbox.topleft.x)
		{
			ball.Move(simulation_precision);
			ball.SnapToLimitBorderTOPBOTTOM(play_area);
		}

		return ball.GetCenter().y;
	}
	else
	{
		assert(ball.GetSpeed().x < 0.f); //If assertion fails, the ball is going away from the paddle, which makes the simulation infinite as the ball will never reach the paddle.
		while (ball.GetHitBox().topleft.x >= paddlehitbox.bottomright.x)
		{
			ball.Move(simulation_precision);
			ball.SnapToLimitBorderTOPBOTTOM(play_area);
		}

		return ball.GetCenter().y;
	}
}

void Bot::Update_Seek(Ball ball, Rect<float>& play_area)
{
	if (controlled_paddle.GetSide() == Side::right && ball.GetSpeed().x > 0.f)
	{
		current_y_seek = SimulateBall(ball, play_area);
	}
	if (controlled_paddle.GetSide() == Side::left && ball.GetSpeed().x < 0.f)
	{
		current_y_seek = SimulateBall(ball, play_area);
	}
}

Vect<float> Bot::GetMove()
{
	if (current_y_seek - seek_tolerance > controlled_paddle.GetCenter().y)
	{
		return Vect<float>(0.f,1.f);
	}
	else
	{
		if (current_y_seek + seek_tolerance < controlled_paddle.GetCenter().y)
		{
			return Vect<float>(0.f, -1.f);
		}
		else
		{
			return Vect<float>(0.f, 0.f);
		}
	}
}

void Bot::SetSeek(float seek_y)
{
	current_y_seek = seek_y;
}
