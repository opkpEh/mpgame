#include <raylib.h>
#include "draw.h"
#include <iostream>

const int worldHeight = 1008;
const int worldWidth = 1920;
const Color bkgColor = { 118, 173, 168 };
const char* gameName = "multiplayer";

int main()
{
	SetWindowState(FLAG_VSYNC_HINT);
	SetTargetFPS(60);	

	InitWindow(worldWidth, worldHeight, gameName);

	draw::initializePlayer();
	draw::initializeEnemy();
	draw::initializeMap();

	Font font = LoadFont("assets/fonts/DungeonFont.ttf");

	while (!WindowShouldClose())
	{
		BeginDrawing();
		draw::drawFrame();
		DrawText("Test", 20, 20, 20, LIGHTGRAY);
		ClearBackground(bkgColor);

		EndDrawing();
	}
    CloseWindow();
	return 0;
}
