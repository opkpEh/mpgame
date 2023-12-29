#pragma once
#include "raylib.h"

namespace entites
{
    struct entity
    {
        float initX;
        float initY;
        float height;
        float width;
        float speed;
        Color color;

        //Constructor with default values
        entity(float h = 10.0f, float w = 20.0f, float s = 1.0f, float x = 10.0f, int y = 20.0f, Color c = WHITE)
            : height(h), width(w), speed(s), initX(x), initY(y), color(c) {}

        // Member function to draw rectangle
        void drawE()
        {
            DrawRectangle(initX, initY, width, height, color);
        }
        
        //entity movement
        void moveE()
        {
            if (IsKeyDown(KEY_W) && (int)initY<=height)
            {
                initY -= speed;
            }
            else if (IsKeyDown(KEY_S) && (int)initY<= worldHeight-height)
            {
				initY += speed;
			}
            else if (IsKeyDown(KEY_A))
            {
                initX -= speed;
            }
            else if (IsKeyDown(KEY_D))
            {
				initX += speed;
			}   
        }
    };
}