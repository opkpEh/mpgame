#pragma once
#include "raylib.h"
#include "entites.h"
#include "animation.h"
#include "frames.h"
#include "world.h"

entities::entity player;
world::grass grassMap;

namespace draw
{  
    void initializePlayerAnimation()
    {
        player = { 64.0, 64.0, 10.0, 450.0, 300.0, RED };
        //          h     w     s     x      y      c

        player.dest = { player.x, player.y, player.width, player.height };
        player.origin = { 0, 0 };
        player.rotation = 0.0f;

        player.playerAnimationTexture = LoadTexture("assets/character/sheets/blueDino.png");

        player.playerAnimation = CreateSpriteAnimation(player.playerAnimationTexture, 8, idle, 4);
        //                                     texture, fps, rectangles, length

    }

    void initializeMap()
    {
        grassMap.tileTexture = LoadTexture("assets/grass/grass.png");
        //grassMap.tileSource = { 48, 0, 24, 24 };
        grassMap.tileSource.x = 48;
        grassMap.tileSource.y = 0;
        grassMap.tileSource.width = 24;
        grassMap.tileSource.height = 24;

        //grassMap.tileDest = { 48, 48, 48, 48 };
        grassMap.tileDest.width = 48;
        grassMap.tileDest.height = 48;

        grassMap.generateMap();
		
    }

    void drawFrame()
    {
        grassMap.renderMap();
        player.render();
        player.UpdateDrawFrame();
        
    }
}