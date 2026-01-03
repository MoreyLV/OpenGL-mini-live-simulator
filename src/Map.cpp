//
// Created by Morey on 21/12/2025.
//

#include "../include/Map.h"
#include <iostream>
#include "../include/Utility.h"

Utility utility;

Map::Map(int map_width, int map_height, int species_num, int food_num) {
    int innerCount = 0;
    int aliveCells = species_num;
    int foodCells = food_num;
    std::string type_name;
    float rc, gc, bc, ac;
    bool special = false;

    std::vector<int> aliveList;
    std::vector<int> foodList;
    for (int i = 0; i < aliveCells; i++) {
        aliveList.push_back(utility.RandomInt(0, map_height*map_width));
    }for (int i = 0; i < foodCells; i++) {
        int bufer_value = utility.RandomInt(0, map_height*map_width);
        for (int j = 0; j < aliveCells; j++) {
            if (bufer_value == aliveList[j]) {
                bufer_value = utility.RandomInt(0, map_height*map_width);
            }
        }
        foodList.push_back(bufer_value);
    }

    for (int y = 0; y < map_height; ++y) {
        for (int x = 0; x < map_width; ++x) {
            innerCount++;
            for (int l = 0; l < aliveList.size(); ++l) {
                if (aliveList[l] == innerCount) {
                    type_name = "alive";
                    rc = utility.RandomInt(0, 255)/ 255.0f;
                    gc = utility.RandomInt(0, 255)/ 255.0f;
                    bc = utility.RandomInt(0, 255)/ 255.0f;
                    ac = 1.f;
                    special = true;
                    break;
                }else {
                    special = false;
                }
            }
            for (int l = 0; l < foodList.size(); ++l) {
                if (foodList[l] == innerCount) {
                    type_name = "food";
                    rc = 190.f/ 255.0f;
                    gc = 120.f/ 255.0f;
                    bc = 0.0f/ 255.0f;
                    ac = 1.f;
                    break;
                    special = true;
                } else if (!special) {
                    type_name = "default";
                    rc = 150.0f/255.0f;
                    gc = 150.0f/255.0f;
                    bc = 150.0f/255.0f;
                    ac = 1.0f;
                    special = false;
                }
            }

            tiles.push_back({
                innerCount,
                float(x)-(map_width/2), float(y)-(map_height/2),
                rc, gc, bc, ac,
                type_name,
                50
            });
        }
    }
}
float Map::GetTileSize(int map_width, int map_height) {
    float tileSizeX = 2.0f / map_width;
    float tileSizeY = 2.0f / map_height;
    float tileSize = std::min(tileSizeX, tileSizeY);
    std::cout << tileSize << std::endl;
    return tileSize;
}