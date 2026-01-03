//
// Created by Morey on 20/12/2025.
//
#include "../include/Utility.h"
#include "../include/Mesh.h"
#include <iostream>

std::mt19937 gen(std::random_device{}());


Utility::Utility() {
    std::cout << "Creating Utilities" << std::endl;
}
void Utility::ClearWindow(const float& r, const float& g, const float& b, const float& a) {
    glClearColor(r, g, b, a);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}
int Utility::RandomInt(const int& min, const int& max) {
    std::uniform_int_distribution<int> dist(min, max);
    return dist(gen);
}
