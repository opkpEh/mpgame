#pragma once
#include "raylib.h"
#include "entites.h"
#include "animation.h"
#include "frames.h"

entites::entity player = { 64.0, 64.0, 10.0, 450.0, 300.0, RED };
//                           h     w     s     x      y      c
//entites::entity player2= { 64.0, 64.0, 10.0, 300.0, 300.0, BLUE };

//Texture2D grassTexture = LoadTexture("assets/grass/grass.png");

Camera2D camera;
float cameraZoom = 1.0f;

namespace draw
{  
    void initializePlayer1Animation()
    {
        player.dest = { player.x, player.y, player.width, player.height };
        player.origin = { 0, 0 };
        player.rotation = 0.0f;

        player.playerAnimationTexture = LoadTexture("assets/character/sheets/blueDino.png");

        player.playerAnimation = CreateSpriteAnimation(player.playerAnimationTexture, 8, idle, 4);
        //                                     texture, fps, rectangles, length

        camera = Camera2D{ Vector2{(float)(GetScreenWidth() / 2.0f),(float)(GetScreenHeight() / 2.0f)}, Vector2{(player.x - player.width / 2),(player.y - player.height / 2)}, 0.0, 1.0 };
        
    }
    
    /*void initializePlayer2Animation()
    {
        player2.dest = { player2.x, player2.y, player2.width, player2.height };
        player2.origin = { 0, 0 };
        player2.rotation = 0.0f;

        player2.playerAnimationTexture = LoadTexture("assets/character/sheets/redDino.png");
        player2.playerAnimation = CreateSpriteAnimation(player2.playerAnimationTexture, 8, idle, 4);
    }*/
    
    void renderPlayer1()
    {
        DrawSpriteAnimationPro(player.playerAnimation, player.dest, player.origin, player.rotation, WHITE);
    }

    /*void renderPlayer2()
    {
        DrawSpriteAnimationPro(player2.playerAnimation, player2.dest, player2.origin, player2.rotation, WHITE);
    }*/

    void UpdateDrawFrame()
    {
        player.dest = { player.x, player.y, player.width, player.height };
        player.moveE();

        
        camera.target = Vector2{ (player.x - player.width / 2),(player.y - player.height / 2) };

        /*player2.dest= { player2.x, player2.y, player2.width, player2.height };
        player2.moveE();*/

    }

    void drawFrame()
    {   
        //player.drawE();
        //player2.drawE();
        renderPlayer1();
        //renderPlayer2();
    }

}