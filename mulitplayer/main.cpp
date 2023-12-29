#include "entites.h"
#include <raylib.h>
#include <iostream>
#include "main.h"
#include "draw.h"
//#include "screens.h"



int main()
{
	SetWindowState(FLAG_VSYNC_HINT);
	SetTargetFPS(60);

	InitWindow(worldHeight, worldWidth, gameName);
	while (!WindowShouldClose())
	{
		BeginDrawing();

		draw::drawPlayer();

		ClearBackground(WHITE);

		EndDrawing();
	}
	return 0;
}