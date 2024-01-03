#include <raylib.h>
#include "main.h"
#include "draw.h"
#include <iostream>

int main()
{
	SetWindowState(FLAG_VSYNC_HINT);
	SetTargetFPS(60);
	SetExitKey(0);

	InitWindow(worldWidth, worldHeight, gameName);

	draw::initializePlayer1Animation();
	draw::initializePlayer2Animation();

	while (!WindowShouldClose())
	{
		BeginDrawing();

		draw::drawFrame();
		draw::UpdateDrawFrame();

		ClearBackground(bkgColor);
		
		EndDrawing();
	}

    CloseWindow();
	
	return 0;
}
