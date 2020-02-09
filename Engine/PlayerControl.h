#pragma once
#include "Vect.h"
#include "Keyboard.h"

class PlayerControl
{
public:
	PlayerControl(const char keyup, const char keydown);

	Vect<float> GetNextMoveDirection(Keyboard& kbd) const;
private:
	char keyup;
	char keydown;
};