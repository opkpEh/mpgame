#pragma once
#include "raylib.h"
#include "raymath.h"
#include "entites.h"
#include "animation.h"

namespace draw
{
    entites::entity player = { 32, 32, 10, 450, 300, RED };

    // Define animation texture and rectangles
    Texture2D playerAnimationTexture;

    Rectangle playerFrames[] = {
        {49, 64, 16, 32},
        {158, 64, 16, 32},
        {270, 64, 16, 32},
        {382, 64, 16, 32},
        {493, 64, 16, 32},
        {607, 64, 16, 32},
        {721, 64, 16, 32},
        {832, 64, 16, 32},

        
    };
    SpriteAnimation playerAnimation;

    Rectangle dest = { player.initX, player.initY, player.width, player.height };
    Vector2 origin = { player.width / 2, player.height / 2 };
    float rotation = 0;
    
    void UpdateDrawFrame(void);

    void initializePlayerAnimation()
    {
        srand(time(0));

        // Load animation texture
        playerAnimationTexture = LoadTexture("assets/playerAtlas.png");

        // Create the SpriteAnimation
        playerAnimation = CreateSpriteAnimation(playerAnimationTexture, 8, playerFrames, 8);
    }

    void UpdateDrawFrame(void)
    {
        //Rectangle dest = { player.initX, player.initY, player.width, player.height };
        //Vector2 origin = { player.width / 2, player.height / 2 };

        BeginDrawing();

        ClearBackground(RAYWHITE);

        DrawSpriteAnimationPro(playerAnimation, dest, origin, 0, WHITE);
        player.moveE();

        EndDrawing();
    }
}
