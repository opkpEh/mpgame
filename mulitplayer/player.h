#pragma once
#include "raylib.h"
#include "animation.h"
#include "frames.h"

namespace entities
{  
    enum class AnimationState
	{
		Idle,
		LWalk,
		RWalk,
		UWalk,
		DWalk
	};

    struct player
    {
        Rectangle dest;
        Vector2 source;

        Texture2D animationTexture;
        SpriteAnimation animation;

        float rotation;
        float speed;

        AnimationState animationState = AnimationState::Idle;
        
        void animate(AnimationState previousState)
        {
            if (previousState != animationState)
            {
                switch (animationState)
                {
                case AnimationState::Idle:
                    animation = CreateSpriteAnimation(animationTexture, 8, idle, 4);
                    break;
                case AnimationState::LWalk:
                    animation = CreateSpriteAnimation(animationTexture, 8, leftWalk, 6);
                    break;
                case AnimationState::RWalk:
                    animation = CreateSpriteAnimation(animationTexture, 8, rightWalk, 6);
                    break;
                }
            }
            if ((!IsKeyDown(KEY_D) && previousState == AnimationState::LWalk) || (!IsKeyDown(KEY_A) && previousState == AnimationState::RWalk))
            {
                animationState = AnimationState::Idle;
                animation = CreateSpriteAnimation(animationTexture, 8, idle, 4);
            }
        };
        
        void move()
        {
            AnimationState previousState = animationState;
            
                if (IsKeyDown(KEY_W) && dest.y >= 0)
                {
                    dest.y -= speed;
                    animationState = AnimationState::Idle;
                }
                if (IsKeyDown(KEY_S) && dest.y <= (int)GetScreenHeight() - dest.height)
                {
                    dest.y += speed;
                    animationState = AnimationState::Idle;
                }
                if (IsKeyDown(KEY_A) && dest.x >= 0)
                {
                    dest.x -= speed;
                    animationState = AnimationState::RWalk;
                }
                if (IsKeyDown(KEY_D) && dest.x <= (int)GetScreenWidth() - dest.width)
                {
                    dest.x += speed;
                    animationState = AnimationState::LWalk;
                }
           
            animate(previousState);
        }

        void UpdateDrawFrame(float x, float y)
        {
            dest = { x, y, 64, 64 };
            move();
        }

        void render()
        {
            DrawSpriteAnimationPro(animation, dest, source, rotation, WHITE);
            UpdateDrawFrame(dest.x, dest.y);
        }

    };
}
