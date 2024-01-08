#pragma once
#include <iostream>
#include "cmath"
#include "raylib.h"
#include "animation.h"
#include "frames.h"

int calculate_distance(int x1, int y1, int x2, int y2) {
    return static_cast<int>(round(sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2))));
}

int shortest_path(int x1, int y1, int x2, int y2) {
    int distance = calculate_distance(x1, y1, x2, y2);
    return distance;
}

namespace enemies
{
    enum class AnimationState
    {
        Idle,
        LWalk,
        RWalk,
        UWalk,
        DWalk
    };

    struct enemy
    {
        Rectangle dest;
        Vector2 source;

        Texture2D animationTexture;
        SpriteAnimation animation;

        float rotation;
        float speed;

        int previousX;
        int previousY;
        int playerX;
        int playerY;

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
        };

        void move()
        {
            AnimationState previousState = animationState;

            int distanceToPlayer = shortest_path((int)dest.x, (int)dest.y, playerX, playerY);

            if (distanceToPlayer > 0)
            {
                float directionX = static_cast<float>(playerX - dest.x);
                float directionY = static_cast<float>(playerY - dest.y);

                float length = sqrt(directionX * directionX + directionY * directionY);
                if (length > 0)
                {
                    directionX /= length;
                    directionY /= length;
                }

                dest.x += static_cast<int>(directionX * speed);
                dest.y += static_cast<int>(directionY * speed);

                if (IsKeyDown(KEY_W))
                {
                    animationState = AnimationState::UWalk;
                }
                else if (IsKeyDown(KEY_S))
                {
                    animationState = AnimationState::DWalk;
                }
                else if (IsKeyDown(KEY_A) && dest.x > playerX)
                {
                    animationState = AnimationState::RWalk;
                }
                else if (IsKeyDown(KEY_D))
                {
                    animationState = AnimationState::LWalk;
                }
            }
            else
            {
                animationState = AnimationState::Idle;
                
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