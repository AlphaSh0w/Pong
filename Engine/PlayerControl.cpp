#include "PlayerControl.h"

PlayerControl::PlayerControl(const char keyup, const char keydown)
	:
	keyup(keyup),
	keydown(keydown)
{
}

Vect<float> PlayerControl::GetNextMoveDirection(Keyboard & kbd) const
{
	Vect<float> direction(0.f, 0.f);

	if (kbd.KeyIsPressed(keyup))
	{
		direction.y -= 1;
	}
	if (kbd.KeyIsPressed(keydown))
	{
		direction.y += 1;
	}

	return direction;
}
