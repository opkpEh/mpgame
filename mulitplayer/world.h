#pragma once
#include "raylib.h"

namespace world
{
    struct grass
    {
        Texture2D tileTexture;
        Rectangle tileSource;
        Rectangle tileDest;

        enum class tileType
        {
            grass = 1,
            flower = 2
        };

        const int rows = 10;  // Adjust as needed
        const int cols = 10;  // Adjust as needed

        int mapMatrix[10][10];  // Adjust dimensions based on rows and cols

        void generateMap()
        {
            for (int i = 0; i < rows; ++i)
            {
                for (int j = 0; j < cols; ++j)
                {
                    mapMatrix[i][j] = GetRandomValue(1, 2);
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
                    case tileType::grass:
                        tileSource.x = 48;
                        tileSource.y = 0;
                        tileSource.width = 48;
                        tileSource.height = 24;
                        break;
                    case tileType::flower:
                        tileSource.x = 48;
                        tileSource.y = 24;
                        tileSource.width = 48;
                        tileSource.height = 24;
                        break;
                    }

                    tileDest.x = j * 48;  // Adjust as needed
                    tileDest.y = i * 48;  // Adjust as needed

                    DrawTexturePro(tileTexture, tileSource, tileDest, { 0, 0 }, 0, WHITE);
                }
            }
        }
    };
}
