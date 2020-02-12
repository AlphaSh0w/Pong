#pragma once
#include "Ball.h"
#include "Paddle.h"
#include "Rect.h"

class Bot
{
public:
	Bot(Paddle& controlled_paddle,int starting_y_seek, float simulation_precision, float seek_tolerance = 20.f);
	float SimulateBall(Ball ball,Rect<float>& play_area); //returns the y position of the center of the ball the moment it should reache the range of the paddle.
	void Update_Seek(Ball ball, Rect<float>& play_area);
	Vect<float> GetMove();
	void SetSeek(int seek_y);
private:
	Paddle& controlled_paddle;
	int current_y_seek;
	float seek_tolerance; //If seek tolerance is too low, the bot might start having a seasure when reaching destination.
	float simulation_precision;
};