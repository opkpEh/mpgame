#pragma once
#include "raylib.h"
#include "entites.h"

namespace draw
{
	entites::entity player(10, 10, 50, 60, 0.02f, RED);

	void drawPlayer()
	{
		player.drawE();
		player.moveE();
	}
}