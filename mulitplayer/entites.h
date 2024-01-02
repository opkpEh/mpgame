#pragma once
#include <iostream>
#include "raylib.h"
#include "main.h"
#include "animation.h"
#include "frames.h"

namespace entites
{  
    enum class AnimationState
	{
		Idle,
		LWalk,
		RWalk,
		UWalk,
		DWalk
	};

    struct entity
    {
        float height;
        float width;
        float speed;
        float initX;
        float initY;
        Color color;

        bool isMoving = false;
        bool isUp = false;
        bool isDown = false;
        bool isLeft = false;
        bool isRight = false;
        bool isIdle = true;
        
        AnimationState animationState = AnimationState::Idle;

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
            AnimationState previousState = animationState;

            if (IsKeyDown(KEY_W) && initY >= 2)
            {
                initY -= speed;
                isMoving = true;
                isUp = true;
                animationState = AnimationState::Idle;
            }
            if (IsKeyDown(KEY_S) && initY <= worldWidth - height - 4)
            {
                initY += speed;
                isMoving = true;
                isDown = true;
                animationState = AnimationState::Idle;
            }
            if (IsKeyDown(KEY_A) && initX >= 3)
            {
                initX -= speed;
                isMoving = true;
                isLeft = true;
                animationState = AnimationState::Idle;
            }
            if (IsKeyDown(KEY_D) && initX <= worldHeight - width - 6)
            {
                initX += speed;
                isMoving = true;
                isRight = true;
                animationState = AnimationState::LWalk;
            }

            if (previousState != animationState)
            {
                switch (animationState)
                {
                case AnimationState::Idle:
                    playerAnimation = CreateSpriteAnimation(playerAnimationTexture, 8, idle, 4);
                    break;
                case AnimationState::LWalk:
                    playerAnimation = CreateSpriteAnimation(playerAnimationTexture, 8, walk, 6);
                    break;
                }
            }

            if (!IsKeyDown(KEY_D) && previousState == AnimationState::LWalk)
            {
                animationState = AnimationState::Idle;
                playerAnimation = CreateSpriteAnimation(playerAnimationTexture, 8, idle, 4);
            }

            isMoving = false;
            isUp = false;
            isDown = false;
            isLeft = false;
            isRight = false;
        }

    };
}
