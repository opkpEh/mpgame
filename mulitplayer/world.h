#pragma once
#include "raylib.h"
#include <vector>

namespace world
{
    struct mapGen
    {
        Texture2D grassTexture;
        Rectangle grassSource;
        Rectangle grassDest;

        enum class TerrainType
        {
            Grass,
            Rock,
            Bush,
            Tree
        };

        int rows;
        int cols;
        
        std::vector<std::vector<TerrainType>> map;

        void generateTerrain(TerrainType terrain, int count) {
            while (count > 0) {
                int row = rand() % rows;
                int col = rand() % cols;

                if (map[row][col] == TerrainType::Grass) {
                    map[row][col] = terrain;
                    count--;
                }
            }
        }

        void generateMap() {
            srand(static_cast<unsigned>(time(nullptr)));

            generateTerrain(TerrainType::Grass, rows * cols / 2);
            generateTerrain(TerrainType::Rock, rows * cols / 8);
            generateTerrain(TerrainType::Bush, rows * cols / 8);
            generateTerrain(TerrainType::Tree, rows * cols / 8);
        }


        void initMap(int _rows, int _cols) {
            rows = _rows;
            cols = _cols;
            map.resize(rows, std::vector<TerrainType>(cols, TerrainType::Grass));
            generateMap();
        }

        void displayMap() const {
            for (const auto& row : map) {
                for (const auto& cell : row) {
                    char symbol = 0;
                    switch (cell) {
                    case TerrainType::Grass: symbol = '.'; break;
                    case TerrainType::Rock: symbol = '#'; break;
                    case TerrainType::Bush: symbol = '*'; break;
                    case TerrainType::Tree: symbol = 'T'; break;
                    }
                    std::cout << symbol << ' ';
                }
                std::cout << std::endl;
            }
        }

        void renderMap() {
            for (int i = 0; i < rows; ++i) {
                for (int j = 0; j < cols; ++j) {
                    switch (map[i][j]) {
                    case TerrainType::Grass:
                        grassSource.x = 0;
                        grassSource.y = 0;
                        break;
                    case TerrainType::Rock:
                        grassSource.x = 80;
                        grassSource.y = 0;
                        break;
                    case TerrainType::Bush:
                        grassSource.x = 64;
                        grassSource.y = 16;
                        break;
                    case TerrainType::Tree:
                        grassSource.x = 80;
                        grassSource.y = 16;
                        break;
                    }

                    grassDest.x = static_cast<float>(j * grassDest.height);
                    grassDest.y = static_cast<float>(i * grassDest.width);

                    DrawTexturePro(grassTexture, grassSource, grassDest, { 0, 0 }, 0, WHITE);
                }

            }
        }
    };
}
