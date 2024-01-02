#pragma once
#include "raylib.h"
#include "entites.h"
#include "animation.h"
#include "frames.h"

entites::entity player = { 64.0, 64.0, 10.0, 450.0, 300.0, RED };
//                           h     w     s     x      y      c

namespace draw
{

   
    void initializePlayerAnimation()
    {
        player.dest = { player.initX, player.initY, player.width, player.height };
        player.origin = { 0, 0 };
        player.rotation = 0.0f;

        player.playerAnimationTexture = LoadTexture("assets/character/sheets/blueDino.png");

        player.playerAnimation = CreateSpriteAnimation(player.playerAnimationTexture, 8, idle, 4);
        //                                     texture, fps, rectangles, length
    }

    void renderPlayer()
    {
        DrawSpriteAnimationPro(player.playerAnimation, player.dest, player.origin, player.rotation, WHITE);
    }

    void UpdateDrawFrame()
    {
        player.dest = { player.initX, player.initY, player.width, player.height };

        player.moveE();
    }

    void drawFrame()
    {   
        player.drawE();
        renderPlayer();
    }

    
}