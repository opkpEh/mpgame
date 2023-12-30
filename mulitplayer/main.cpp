#include "entites.h"
#include <raylib.h>
#include <iostream>
#include "main.h"
#include "draw.h"
#include "animation.h"
#include <vector>  // Add this include for std::vector

int main()
{
    SetWindowState(FLAG_VSYNC_HINT);
    SetTargetFPS(60);

    srand(time(0));

    InitWindow(worldHeight, worldWidth, gameName);

    while (!WindowShouldClose())
    {
        BeginDrawing();

        draw::drawPlayer();

        ClearBackground(WHITE);

        EndDrawing();
    }

    CloseWindow();
    return 0;
}