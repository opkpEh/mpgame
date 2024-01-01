#pragma once
#include "raylib.h"
#include "entites.h"
#include "animation.h"

Rectangle idle[] = {
{04, 04, 15, 17},
{28, 04, 15, 17},
{52, 04, 15, 17},
{76, 04, 15, 17}
};
//4

Rectangle run[] = {
    {438, 06, 18, 15},
    {462, 06, 18, 15},
    {486, 06, 18, 15},
    {510, 06, 18, 15},
    {534, 06, 18, 15},
    {558, 06, 18, 15}
};
//6

Rectangle walk[] = {
    {100, 04, 15, 17},
    {124, 04, 15, 17},
    {148, 04, 15, 17},
    {172, 04, 15, 17},
    {196, 04, 15, 17},
    {220, 04, 15, 17},
};
//6

Rectangle hurt[] = {
    {340, 03, 15, 18},
    {362, 03, 15, 18},
    {386, 03, 15, 18}
};
//3

namespace draw
{
    entites::entity player = { 64.0, 64.0, 10.0, 450.0, 300.0, RED };
    //                          h     w     s     x      y      c

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