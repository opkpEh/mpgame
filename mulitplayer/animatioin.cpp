#include "animation.h"

#include <stdlib.h>

SpriteAnimation CreateSpriteAnimation(Texture2D atlas, int framesPerSecond, Rectangle rectangles[], int length)
{
	//constructor  
	SpriteAnimation spriteAnimation =
	{
		atlas,
		framesPerSecond,
		GetTime(),
		NULL,
		length
	};

	//allocate memory for rectangles
	Rectangle* mem = (Rectangle*)malloc(sizeof(Rectangle) * length);

	if (mem == NULL)
	{
		TraceLog(LOG_FATAL, "No memory for CreateSpriteAnimation");
		spriteAnimation.rectanglesLength = 0;
		return spriteAnimation;
	}
	//copy rectangles
	spriteAnimation.rectangles = mem;

	//copy rectangles
	for (int i = 0; i < length; i++)
	{
		spriteAnimation.rectangles[i] = rectangles[i];
	}

	return spriteAnimation;
}

//destructor for the allocated memory
void DisposeSpriteAnimation(SpriteAnimation animation)
{
	free(animation.rectangles);
}

//draws the animation
void DrawSpriteAnimationPro(SpriteAnimation animation, Rectangle dest, Vector2 origin, float rotation, Color tint)
{
	int index = (int)((GetTime() - animation.timeStarted) * animation.framesPerSecond) % animation.rectanglesLength;

	Rectangle source = animation.rectangles[index];
	DrawTexturePro(animation.atlas, source, dest, origin, rotation, tint);
}


