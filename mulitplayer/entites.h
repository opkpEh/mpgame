#pragma once
#include "raylib.h"
#include "main.h"
#include <iostream>

namespace entites
{
    struct entity
    {
        int height;
        int width;
        int speed;
        int initX;
        int initY;
        Color color;

        //Constructor with default values
        entity(int h = 10, int w = 20, int s = 10, int x = 10, int y = 20, Color c = WHITE)
           : height(h), width(w), speed(s), initX(x), initY(y), color(c) {}

        // Member function to draw rectangle
        void drawE()
        {
            DrawRectangle(initX, initY, width, height, color);
        }
        
        //entity movement
        void moveE()
        {
            if (IsKeyDown(KEY_W) && initY>=2)
            {
                initY -= speed;
            }
            if (IsKeyDown(KEY_S) && initY<=worldWidth-height-1)
            {
				initY += speed;
			}
            if (IsKeyDown(KEY_A) && initX>=3)
            {
                initX -= speed;
            }
            if (IsKeyDown(KEY_D) && initX<=worldHeight-width)
            {
				initX += speed;
			}   
        }
    };
}