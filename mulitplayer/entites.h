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
        float x;
        float y;
        Color color;
        
        AnimationState animationState = AnimationState::Idle;

        Texture2D playerAnimationTexture;
        SpriteAnimation playerAnimation;

        Rectangle dest;
        Vector2 origin;
        float rotation;

        void drawE()
        {
            DrawRectangle((int)x, (int)y, (int)width, (int)height, color);
        }

        void animateE(AnimationState previousState)
        {
            if (previousState != animationState)
            {
                switch (animationState)
                {
                case AnimationState::Idle:
                    playerAnimation = CreateSpriteAnimation(playerAnimationTexture, 8, idle, 4);
                    break;
                case AnimationState::LWalk:
                    playerAnimation = CreateSpriteAnimation(playerAnimationTexture, 8, leftWalk, 6);
                    break;
                case AnimationState::RWalk:
                    playerAnimation = CreateSpriteAnimation(playerAnimationTexture, 8, rightWalk, 6);
                    break;
                }
            }
            if ((!IsKeyDown(KEY_D) && previousState == AnimationState::LWalk) || (!IsKeyDown(KEY_A) && previousState == AnimationState::RWalk))
            {
                animationState = AnimationState::Idle;
                playerAnimation = CreateSpriteAnimation(playerAnimationTexture, 8, idle, 4);
            }
        }

        void moveE()
        {
            AnimationState previousState = animationState;

            if (IsKeyDown(KEY_W) && y >= 0)
            {
                y -= speed;
                animationState = AnimationState::Idle;
            }
            if (IsKeyDown(KEY_S) && y <= worldHeight - height - 4)
            {
                y += speed;
                animationState = AnimationState::Idle;
            }
            if (IsKeyDown(KEY_A) && x >= 3)
            {
                x -= speed;
                animationState = AnimationState::RWalk;
            }
            if (IsKeyDown(KEY_D) && x <= worldWidth - width- 6)
            {
                x += speed;
                animationState = AnimationState::LWalk;
            }

            animateE(previousState);
        }
    };
}
