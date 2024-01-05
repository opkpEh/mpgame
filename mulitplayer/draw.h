#pragma once
#include "raylib.h"
#include "player.h"
#include "enemy.h"
#include "animation.h"
#include "frames.h"
#include "world.h"

entities::player player;
enemies::enemy enemy;
world::grass grassMap;

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
        enemy.playerX= player.dest.x;
        enemy.playerY= player.dest.y;
    }

    void initializeMap()
    {
        grassMap.tileTexture = LoadTexture("assets/grass/grass.png");
        grassMap.tileSource = { 48, 0, 16, 16 };
        grassMap.tileDest = { 48, 48, 32, 32 };
        grassMap.generateMap();
		
    }

    void drawFrame()
    {
        grassMap.renderMap();
        player.render();
        enemy.playerX= player.dest.x;
        enemy.playerY= player.dest.y;
        enemy.render();
    }
}