/****************************************************************************************** 
 *	Chili DirectX Framework Version 16.07.20											  *	
 *	Game.h																				  *
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
#pragma once

#include "Keyboard.h"
#include "Mouse.h"
#include "Graphics.h"
#include "Vect.h"
#include "Paddle.h"
#include "Rect.h"
#include "Ball.h"
#include "FrameTime.h"
#include "PlayerControl.h"

class Game
{
public:
	Game( class MainWindow& wnd );
	Game( const Game& ) = delete;
	Game& operator=( const Game& ) = delete;
	void Go();
private:
	void ComposeFrame();
	void UpdateModel(float dt);
	/********************************/
	/*  User Functions              */
	/********************************/
private:
	MainWindow& wnd;
	Graphics gfx;
	FrameTime ft;
	const float upper_bound_timestep = 0.0025f;

	const float paddle_speed = 300.f;
	const float paddle_height = 200.f;
	const float paddlewidth = 25.f;
	const float starting_ballspeed_X = 300.f;
	const float starting_ballspeed_Y =  300.f;
	const float ball_dimension = 20.f;
	bool game_started = false;
	bool game_ended = false;
	bool key_inhibitor = false;

	Rect<float> screenrect; //this is the playable area, I chose the whole screen for now.

	Paddle leftpaddle;
	Paddle rightpaddle;
	PlayerControl playerleft;
	PlayerControl playerright;
	Ball ball;




	/********************************/
	/*  User Variables              */
	/********************************/
};