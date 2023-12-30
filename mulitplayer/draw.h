#pragma once
#include "raylib.h"
#include "raymath.h"
#include "entites.h"
#include "animation.h" 

namespace draw
{
    entites::entity player = {50, 50, 10, 450, 300, RED};
    //                         w   h  s   x   y   c
    
    // Function to draw the player
    Texture2D _texture = LoadTexture("assets/red_hood/redHood.png");
    SpriteAnimation _animation = CreateSpriteAnimation(_texture, 8, {
       {0, 0, 32, 32},
       {32, 0, 32, 32},
       {64, 0, 32, 32}
     });


	void drawPlayer()
	{
        Rectangle dest = { player.initX, player.initY, player.width, player.height };
        Vector2 origin = { player.width / 2, player.height / 2 };

        DrawSpriteAnimationPro(_animation, dest, origin, 0, WHITE);
	}

}