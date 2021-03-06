/****************************************************************************************** 
 *	Chili DirectX Framework Version 16.07.20											  *	
 *	Game.cpp																			  *
 *	Copyright 2016 PlanetChili.net <http://www.planetchili.net>							  *
 *																						  *
 *	This file is part of The Chili DirectX Framework.									  *
 *																						  *
 *	The Chili DirectX Framework is free software: you can redistribute it and/or modify	  *
 *	it under the terms of the GNU General Public License as published by				  *
 *	the Free Software Foundation, either version 3 of the License, or					  *
 *	(at your option) any later version.													  *
 *																						  *
 *	The Chili DirectX Framework is distributed in the hope that it will be useful,		  *
 *	but WITHOUT ANY WARRANTY; without even the implied warranty of						  *
 *	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the						  *
 *	GNU General Public License for more details.										  *
 *																						  *
 *	You should have received a copy of the GNU General Public License					  *
 *	along with The Chili DirectX Framework.  If not, see <http://www.gnu.org/licenses/>.  *
 ******************************************************************************************/
#include "MainWindow.h"
#include "Game.h"


Game::Game(MainWindow& wnd)
	:
	wnd(wnd),
	gfx(wnd),
	screenrect(0.f, 0.f, Graphics::ScreenWidth - 1, Graphics::ScreenHeight - 1),
	leftpaddle(Vect<float>(screenrect.topleft.x + (paddlewidth * 2) , (screenrect.bottomright.y /2) - (paddle_height / 2)),
		paddle_height, paddlewidth, Vect<float>(0.f, paddle_speed),Side::left, Colors::Blue),
	rightpaddle(Vect<float>(screenrect.bottomright.x - (paddlewidth * 3),(screenrect.bottomright.y / 2) - paddle_height/2),
		paddle_height,paddlewidth, Vect<float>(0.f, paddle_speed),Side::right, Colors::Blue)
	//paddles are initialised in a way that puts them at the middle of the playable area height, further from the borders by two times their width.
	,
	rightbot(rightpaddle,Graphics::ScreenHeight/2,upper_bound_timestep,5.f),
	leftbot(leftpaddle, Graphics::ScreenHeight / 2, upper_bound_timestep, 5.f),
	playerleft('Z','S'),
	playerright(VK_UP,VK_DOWN),
	ball((screenrect.bottomright.x / 2) - (ball_dimension/2), (screenrect.bottomright.y / 2) - (ball_dimension / 2),
		ball_dimension,min_ballspeed,max_ballspeed,Colors::White)
{
	ball.GenerateRandomSpeed();
	rightbot.Update_Seek(ball, screenrect);
	leftbot.Update_Seek(ball, screenrect);
}

void Game::Go()
{
	gfx.BeginFrame();
	float elapsedtime = ft.mark();
	while (elapsedtime > 0.0f)
	{
		const float dt = std::min(upper_bound_timestep, elapsedtime);
		UpdateModel(dt);
		elapsedtime -= dt;
	}
	ComposeFrame();
	gfx.EndFrame();
}

void Game::UpdateModel(float dt)
{
	if (game_started)
	{
		if (!game_ended)
		{
			leftpaddle.Move(leftbot.GetMove(), dt);
			leftpaddle.SnapToLimitBorder(screenrect);
			rightpaddle.Move(rightbot.GetMove(), dt);
			rightpaddle.SnapToLimitBorder(screenrect);
			ball.Move(dt);
			ball.SnapToLimitBorderTOPBOTTOM(screenrect);
			if (ball.SnapToLimitBorderLEFTRIGHT(screenrect))
			{
				game_ended = true;
			}
			//check collisions with paddles.
			if (ball.IsColliding(leftpaddle.GetHitBox()))
			{
				ball.SetMovementToRight();
				ball.AdjustYSpeedOnHit(leftpaddle);
				rightbot.Update_Seek(ball, screenrect);
			}
			else
			{
				if (ball.IsColliding(rightpaddle.GetHitBox()))
				{
					ball.SetMovementToLeft();
					ball.AdjustYSpeedOnHit(rightpaddle);
					leftbot.Update_Seek(ball, screenrect);
				}
			}
		}
		else
		{
			if (wnd.kbd.KeyIsPressed(VK_RETURN)) //Waiting for enter key press to reset the game.
			{
				key_inhibitor = true;
			}
			else
			{
				if (key_inhibitor == true)
				{
					game_started = false;
					game_ended = false;
					key_inhibitor = false;
					//reset positions.
					ball.SetPosition((screenrect.bottomright.x / 2) - (ball_dimension / 2),
						(screenrect.bottomright.y / 2) - (ball_dimension / 2));
					leftpaddle.SetPosition(Vect<float>(screenrect.topleft.x + (paddlewidth * 2),
						(screenrect.bottomright.y / 2) - (paddle_height / 2)));
					rightpaddle.SetPosition(Vect<float>(screenrect.bottomright.x - (paddlewidth * 3),
						(screenrect.bottomright.y / 2) - paddle_height / 2));
					//reset speeds.
					ball.GenerateRandomSpeed();
					rightbot.SetSeek(gfx.ScreenHeight/2);
					rightbot.Update_Seek(ball, screenrect);
					leftbot.SetSeek(gfx.ScreenHeight/2);
					leftbot.Update_Seek(ball, screenrect);
				}
			}
		}
	}
	else
	{
		if (wnd.kbd.KeyIsPressed(VK_RETURN))
		{
			game_started = true;
		}
	}
}

void Game::ComposeFrame()
{
	leftpaddle.Draw(gfx);
	rightpaddle.Draw(gfx);
	ball.Draw(gfx);
}
