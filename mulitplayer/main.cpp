#include <raylib.h>
#include "main.h"
#include "draw.h"
#include "entites.h"

int main()
{
	SetWindowState(FLAG_VSYNC_HINT);
	SetTargetFPS(60);
	SetExitKey(0);

	InitWindow(worldHeight, worldWidth, gameName);

	draw::initializePlayerAnimation();

	while (!WindowShouldClose())
	{
		BeginDrawing();

		draw::drawFrame();
		draw::UpdateDrawFrame();

		ClearBackground(RAYWHITE);
		EndDrawing();
	}

    CloseWindow();
	return 0;
}
