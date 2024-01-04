#pragma once
#include "raylib.h"
#include "main.h"
namespace world
{
    struct grass
    {
        Texture2D tileTexture;
        Rectangle tileSource;
        Rectangle tileDest;

        enum class tileType
        {
            grass1 = 1,
            grass2= 2,
            flower1 = 3,
            flower2= 4,
        };

        const static int rows = (int)worldWidth/24;  
        const static int cols = (int)worldHeight/24;

        int mapMatrix[rows][cols];

        void generateMap()
        {
            for (int i = 0; i < rows; ++i)
            {
                for (int j = 0; j < cols; ++j)
                {
                    mapMatrix[i][j] = GetRandomValue(1, 4);
                }
            }
        }

        void renderMap()
        {
            for (int i = 0; i < rows; ++i)
            {
                for (int j = 0; j < cols; ++j)
                {
                    switch (static_cast<tileType>(mapMatrix[i][j]))
                    {
                    case tileType::grass1:
                        tileSource.x = 48;
                        tileSource.y = 0;
                        tileSource.width = 24;
                        tileSource.height = 24;
                        break;
                    case tileType::grass2:
						tileSource.x = 72;
						tileSource.y = 0;
						tileSource.width = 24;
						tileSource.height = 24;
						break;
                    case tileType::flower1:
                        tileSource.x = 48;
                        tileSource.y = 24;
                        tileSource.width = 24;
                        tileSource.height = 24;
                        break;
                    case tileType::flower2:
						tileSource.x = 72;
						tileSource.y = 24;
						tileSource.width = 24;
						tileSource.height = 24;
						break;
                    }

                    tileDest.x = (float)(j * 48);  
                    tileDest.y = (float)(i * 48);  

                    DrawTexturePro(tileTexture, tileSource, tileDest, { 0, 0 }, 0, WHITE);
                }
            }
        }
    };
}
