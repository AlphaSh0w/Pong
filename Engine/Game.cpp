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
	paddleleft(Vect<float>(screenrect.topleft.x + (paddlewidth * 2) , (screenrect.bottomright.y /2) - (paddleheight / 2)),
		paddleheight, paddlewidth, Vect<float>(0.f, paddlespeed), Colors::Blue),
	paddleright(Vect<float>(screenrect.bottomright.x - (paddlewidth * 3),(screenrect.bottomright.y / 2) - paddleheight/2),
		paddleheight,paddlewidth, Vect<float>(0.f, paddlespeed), Colors::Blue)
	//paddles are initialised in a way that puts them at the middle of the playable rectangle height, further from the borders by two times their width.
	,
	playerleft('Z','S'),
	playerright('O','L'),
	ball((screenrect.bottomright.x / 2) - (ball_dimension/2), (screenrect.bottomright.y / 2) - (ball_dimension / 2),
		ball_dimension,starting_ballspeed_X,starting_ballspeed_Y,Colors::White)
{
}

void Game::Go()
{
	gfx.BeginFrame();	
	UpdateModel();
	ComposeFrame();
	gfx.EndFrame();
}

void Game::UpdateModel()
{
	float dt= ft.mark();
	
	paddleleft.Move(playerleft.GetNextMoveDirection(wnd.kbd), dt);
	paddleleft.SnapToLimitBorder(screenrect);
	paddleright.Move(playerright.GetNextMoveDirection(wnd.kbd), dt);
	paddleright.SnapToLimitBorder(screenrect);
	ball.Move(dt);
	ball.SnapToLimitBorder(screenrect);

}

void Game::ComposeFrame()
{
	paddleleft.Draw(gfx);
	paddleright.Draw(gfx);
	ball.Draw(gfx);


}
