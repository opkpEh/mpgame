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
            grass3 = 3,
            grass4 = 4,
            grass5 = 5,
            grass6= 6,
            grass7 = 7,
            flower1 = 8,
            flower2 = 9,
        };

        const static int rows = (int)worldWidth/16;  
        const static int cols = (int)worldHeight/16;

        int mapMatrix[rows][cols];

        void generateMap()
        {
            for (int i = 0; i < rows; ++i)
            {
                for (int j = 0; j < cols; ++j)
                {
                    mapMatrix[i][j] = GetRandomValue(1, 9);
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
                        break;
                    case tileType::grass2:
						tileSource.x = 64;
						tileSource.y = 0;
						break;
                    case tileType::grass3:
                        tileSource.x = 80;
                        tileSource.y = 0;
                        break;
                    case tileType::grass4:
                        tileSource.x = 48;
                        tileSource.y = 16;
                        break;
                    case tileType::grass5:
                        tileSource.x = 64;
                        tileSource.y = 16;
                        break;
                    case tileType::grass6:
						tileSource.x = 80;
						tileSource.y = 16;
						break;
                    case tileType::grass7:
                        tileSource.x = 48;
						tileSource.y = 32;
						break;
                    case tileType::flower1:
                        tileSource.x = 64;
                        tileSource.y = 32;
                        break;
                    case tileType::flower2:
                        tileSource.x = 80;
                        tileSource.y = 32;
                        break;
                    }

                    tileDest.x = (float)(j * 32);  
                    tileDest.y = (float)(i * 32);  

                    DrawTexturePro(tileTexture, tileSource, tileDest, { 0, 0 }, 0, WHITE);
                }
            }
        }

        

    };
}
