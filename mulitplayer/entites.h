#pragma once
#include "raylib.h"
#include "main.h"
#include <iostream>
#include "animation.h"

namespace entites
{
    struct entity
    {
        float height;
        float width;
        float speed;
        float initX;
        float initY;
        Color color;
        bool isMoving = false;

        Texture2D playerAnimationTexture;
        SpriteAnimation playerAnimation;

        Rectangle dest;
        Vector2 origin;
        float rotation;

        void drawE()
        {
            DrawRectangle((int)initX, (int)initY, (int)width, (int)height, color);
        }

        void moveE()
        {
            if (IsKeyDown(KEY_W) && initY>=2)
            {
                initY -= speed;
                isMoving = true;
            }
            if (IsKeyDown(KEY_S) && initY<=worldWidth-height-4)
            {
				initY += speed;
                isMoving = true;
			}
            if (IsKeyDown(KEY_A) && initX>=3)
            {
                initX -= speed;
                isMoving = true;
            }
            if (IsKeyDown(KEY_D) && initX<=worldHeight-width-6)
            {
				initX += speed;
                isMoving = true;
			}
            else
            {
                isMoving = false;
            }
        }
    };
}