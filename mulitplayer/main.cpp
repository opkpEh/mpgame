#include "entites.h"
#include <raylib.h>
#include <iostream>
#include "main.h"
#include "draw.h"
#include "animation.h"
#include <vector>  

int main()
{
	SetWindowState(FLAG_VSYNC_HINT);
	SetTargetFPS(60);

	InitWindow(worldHeight, worldWidth, gameName);
	
	draw::initializePlayerAnimation();

	while (!WindowShouldClose())
	{
		
		draw::UpdateDrawFrame();

	}

    CloseWindow();
	return 0;
}
