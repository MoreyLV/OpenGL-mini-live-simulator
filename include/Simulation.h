//
// Created by Morey on 22/12/2025.
//

#pragma once
#include "Map.h"
#include "../include/Utility.h"

extern Utility utility;

extern float dead_color[4];
extern float default_color[4];
extern float food_color[4];


class Simulation {
    public:
    Simulation();

    void live(std::vector<SquareObject>& tiles, float map_width, float map_height);
    void movement(std::vector<SquareObject>& tiles, int id, float map_width, float map_height);
    void death(std::vector<SquareObject>& tiles, int id);
    void divide(std::vector<SquareObject>& tiles, int id, int fx, int fy, int sx, int sy);
};
