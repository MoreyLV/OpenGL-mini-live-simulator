//
// Created by Morey on 21/12/2025.
//

#pragma once
#include <string>
#include "Mesh.h"
#include "Vertices.h"

struct SquareObject {
    int id;
    float x, y;
    float r, g, b, a;
    std::string type;
    int steps_left;
};

class Map {
public:
    std::vector<SquareObject> tiles;
    Map(const int map_width, const int map_height, int species_num, int food_num);
    static float GetTileSize(int map_width, int map_height);
};
