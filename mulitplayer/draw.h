#pragma once
#include "raylib.h"
#include "player.h"
#include "enemy.h"
#include "animation.h"
#include "frames.h"
#include "world.h"

entities::player player;
enemies::enemy enemy;
world::mapGen map;

Font gameFont;
const char* caughtMessage = "You've Been Caught!";
int fontSize = 40;

namespace draw
{
    void initializePlayer()
    {
        player.animationTexture = LoadTexture("assets/character/redDino.png");
        player.dest = { 800, 600, 32, 32 };
        player.source = { 4, 4 };
        player.rotation = 0.0f;
        player.speed = 14.0f;

        player.animation = CreateSpriteAnimation(player.animationTexture, 8, idle, 4);
        //                                     texture, fps, rectangles, length
        player.isAlive = true;
    }

    void initializeEnemy()
    {
        enemy.animationTexture = LoadTexture("assets/character/blueDino.png");
        enemy.dest = { (float)GetRandomValue(32, GetScreenWidth()),  (float)GetRandomValue(32, GetScreenHeight()), 32, 32 };
        enemy.source = { 4, 4 };
        enemy.rotation = 0.0f;
        enemy.speed = 6.0f;
        enemy.animation = CreateSpriteAnimation(enemy.animationTexture, 8, idle, 4);
        enemy.playerX = (int)player.dest.x;
        enemy.playerY = (int)player.dest.y;
        enemy.caught = false;
    }

    void initializeMap()
    {
        map.mapTexture = LoadTexture("assets/map/grass.png");
        map.mapDest = { 0, 0, 32, 32 };

        int rows = (int)(GetScreenHeight() / enemy.dest.height);
        int cols = (int)(GetScreenWidth() / enemy.dest.width);
        map.initMap(rows, cols);
    }

    void unloadGame()
    {
        UnloadTexture(player.animationTexture);
        UnloadTexture(enemy.animationTexture);
        UnloadFont(gameFont);
        DisposeSpriteAnimation(player.animation);
        DisposeSpriteAnimation(enemy.animation);
        UnloadTexture(map.mapTexture);
    }

    void initializeGame()
    {
        unloadGame();
        initializePlayer();
        initializeEnemy();
        initializeMap();
        gameFont = LoadFont("assets/fonts/DungeonFont.ttf");
    }

    void drawMainMenu()
    {
        float logoX = static_cast<float>(GetScreenWidth() / 2) - MeasureText("Dino Escape", 50) / 2;
        float logoY = static_cast<float>(GetScreenHeight() / 2 - 50);
        player.render();
        DrawTextEx(gameFont, " Dino Escape", { logoX, logoY }, 50, 0, WHITE);
        DrawTextEx(gameFont, "[Press W  A  S  D to Start]", { logoX - 100, logoY + 50 }, 50, 0, GRAY);
    }

    void drawEndScreen()
    {
        float caughtMessageX = static_cast<float>(GetScreenWidth() / 2) - MeasureText(caughtMessage, fontSize) / 2;
        float caughtMessageY = static_cast<float>(GetScreenHeight() / 2 - fontSize);

        DrawTextEx(gameFont, caughtMessage, { caughtMessageX, caughtMessageY }, (float)fontSize, 0, WHITE);
        DrawTextEx(gameFont, "[Press Space to Restart]", { caughtMessageX - 25, caughtMessageY + 50 }, (float)fontSize, 0, WHITE);

    }

    void drawGame()
    {
        map.renderMap();
        player.render();
        enemy.playerX = (int)player.dest.x;
        enemy.playerY = (int)player.dest.y;
        enemy.render();
        
        if(enemy.caught)
		{
            player.isAlive = false;
            drawEndScreen();

            if (IsKeyDown(KEY_SPACE))
            {
                map.unloadMap();
                initializeGame();
            }
        }
    }
}