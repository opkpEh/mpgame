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

namespace draw
{  
    void initializePlayer()
    {
        player.animationTexture = LoadTexture("assets/character/redDino.png");
        player.dest = { 800, 500, 32, 32 };
        player.source = { 4, 4 };
        player.rotation = 0.0f;
        player.speed = 14.0f;

        player.animation = CreateSpriteAnimation(player.animationTexture, 8, idle, 4);
        //                                     texture, fps, rectangles, length
    }

    void initializeEnemy()
    {
        enemy.animationTexture= LoadTexture("assets/character/blueDino.png");
        enemy.dest = { (float)GetRandomValue(32, GetScreenWidth()),  (float)GetRandomValue(32, GetScreenHeight()), 32, 32};
        enemy.source = { 4, 4 };
        enemy.rotation= 0.0f;
        enemy.speed = 6.0f;
        enemy.animation = CreateSpriteAnimation(enemy.animationTexture, 8, idle, 4);
        enemy.playerX= (int)player.dest.x;
        enemy.playerY= (int)player.dest.y;
    }

    void initializeMap()
{
    map.grassTexture = LoadTexture("assets/map/Texture/TX_Tileset_Grass.png");
    map.grassSource = { 48, 0, 16, 16 };
    map.grassDest = { 0, 0, 32, 32 };

    int rows = (int)(GetScreenHeight() / enemy.dest.height);
    int cols = (int)(GetScreenWidth() / enemy.dest.width);
    map.initMap(rows, cols);
}

    void drawFrame()
    {
        grassMap.renderMap();
        player.render();
        enemy.playerX= (int)player.dest.x;
        enemy.playerY= (int)player.dest.y;
        enemy.render();
    }
}
