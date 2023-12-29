#ifndef ANIMATION_H_
#define ANIMATION_H_

#include "raylib.h"
#include <vector>

struct SpriteAnimation
{
    Texture2D atlas;
    int framesPerSecond;
    float timeStarted;

    std::vector<Rectangle> rectangles;
};

SpriteAnimation CreateSpriteAnimation(Texture2D atlas, int framesPerSecond, const std::vector<Rectangle>& frames);
void DisposeSpriteAnimation(SpriteAnimation& animation);
void DrawSpriteAnimationPro(const SpriteAnimation& animation, Rectangle dest, Vector2 origin, float rotation, Color tint);

#endif
