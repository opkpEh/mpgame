#include <raylib.h>
#include "draw.h"
#include <iostream>

const int worldHeight = 960;
const int worldWidth = 1320;
const Color bkgColor = { 118, 173, 168 };
const char* gameName = "Run";

enum GameState
{
	MAIN_MENU=1,
	PLAYING
};
GameState gameState = MAIN_MENU;

int main()
{
	SetWindowState(FLAG_VSYNC_HINT);
	SetTargetFPS(60);	

	InitWindow(worldWidth, worldHeight, gameName);

	draw::initializeGame();

	while (!WindowShouldClose())
	{
		BeginDrawing();
		
		switch(gameState)
		{
			case MAIN_MENU:
				draw::drawMainMenu();
				if(IsKeyPressed(KEY_ENTER))
				{
					gameState = PLAYING;
				}
				ClearBackground(bkgColor);
				break;
			case PLAYING:
				draw::drawGame();
				break;
		}

		EndDrawing();
	}
    CloseWindow();
	return 0;
}
