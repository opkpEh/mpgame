#include "animation.h"

SpriteAnimation CreateSpriteAnimation(Texture2D atlas, int framesPerSecond, const std::vector<Rectangle>& frames)
{
    SpriteAnimation spriteAnimation =
    {
        atlas,
        framesPerSecond,
        GetTime(),
        frames
    };

    return spriteAnimation;
}

void DisposeSpriteAnimation(SpriteAnimation& animation)
{
    // Vector is automatically cleaned up when it goes out of scope
    animation.rectangles.clear();
}

void DrawSpriteAnimationPro(const SpriteAnimation& animation, Rectangle dest, Vector2 origin, float rotation, Color tint)
{
    int index = static_cast<int>((GetTime() - animation.timeStarted) * animation.framesPerSecond) % animation.rectangles.size();

    Rectangle source = animation.rectangles[index];
    DrawTexturePro(animation.atlas, source, dest, origin, rotation, tint);
}
