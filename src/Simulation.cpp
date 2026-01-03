//
// Created by Morey on 22/12/2025.
//

#include "../include/Simulation.h"


float dead_color[4] = {
    60.0f/255.0f,
    60.0f/255.0f,
    60.0f/255.0f,
    1.0f
};
float default_color[4] {
    150.0f/255.0f,
    150.0f/255.0f,
    150.0f/255.0f,
    1.0f
};
float food_color[4] {
    190.f/ 255.0f,
    120.0f/255.0f,
    0.0f,
    1.0f
};


Simulation::Simulation() {
}

void Simulation::live(std::vector<SquareObject>& tiles, float map_width, float map_height) {
    for (auto& tile : tiles) {
        int id = tile.id;
        if (tile.steps_left <= 0 && tile.type != "default" && tile.type != "food") {
            tile.steps_left = 0;
            death(tiles, id);
        }
        if (tile.type == "dead") {
            int value = utility.RandomInt(0, 100);
            if (value >= 0) {
                tile.type = "food";
                tile.r = food_color[0];
                tile.g = food_color[1];
                tile.b = food_color[2];
                tile.a = food_color[3];
            }
            else {
                tile.type = "default";
                tile.r = default_color[0];
                tile.g = default_color[1];
                tile.b = default_color[2];
                tile.a = default_color[3];
            }
        }
        if (tile.type == "alive") {
            movement(tiles, id, map_width, map_height);
        }
    }
}

void Simulation::movement(std::vector<SquareObject>& tiles, int id, float map_width, float map_height) {
    for (auto& tile : tiles) {
        if (tile.id == id) {
            int move_direction = utility.RandomInt(1,4);
            bool canMove = true;
            float new_x = tile.x;
            float new_y = tile.y;
            float old_x = tile.x;
            float old_y = tile.y;

            float max_x = map_width;
            float max_y = map_height;

            switch (move_direction) {
                case 1: new_y -= 1; break; // up
                case 2: new_y += 1; break; // down
                case 3: new_x -= 1; break; // left
                case 4: new_x += 1; break; // right
            }
            if (new_x < -map_width/2 || new_x >= map_width/2 ||
            new_y < -map_height/2 || new_y >= map_height/2) {
                canMove = false;
            }


            // проверка коллизий
            for ( auto& other : tiles) {
                if (other.id != tile.id && other.x == new_x && other.y == new_y && other.type != "food" && canMove) {
                    other.x = old_x;
                    other.y = old_y;
                } else if (other.id != tile.id && other.x == new_x && other.y == new_y && other.type == "food" && canMove) {
                    other.type = "alive";
                    other.r = tile.r;
                    other.g = tile.g;
                    other.b = tile.b;
                    tile.steps_left = 50;
                    other.steps_left = 50;
                    canMove = false;
                }
            }

            // если свободно — двигаем
            if (canMove) {
                tile.x = new_x;
                tile.y = new_y;
                tile.steps_left -= 1;
            }
        }
    }
}
void Simulation::death(std::vector<SquareObject>& tiles, int id) {
    for (auto& tile : tiles) {
        if (tile.id == id) {
            tile.type = "dead";
            tile.r = dead_color[0];
            tile.g = dead_color[1];
            tile.b = dead_color[2];
            tile.a = dead_color[3];
            break;
        }
    }
}
