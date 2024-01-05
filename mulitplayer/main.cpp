#include <raylib.h>
#include "main.h"
#include "draw.h"
#include <iostream>

int main()
{
	SetWindowState(FLAG_VSYNC_HINT);
	SetTargetFPS(60);

	InitWindow(worldWidth, worldHeight, gameName);

	draw::initializePlayer();
	draw::initializeEnemy();
	draw::initializeMap();

	while (!WindowShouldClose())
	{
		BeginDrawing();
		draw::drawFrame();
		ClearBackground(bkgColor);

		EndDrawing();
	}
    CloseWindow();
	return 0;
}
