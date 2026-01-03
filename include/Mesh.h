//
// Created by Morey on 20/12/2025.
//

#pragma once
#include <glad/glad.h>
#include <vector>

struct Polygon  {
    float x,y,z;
    float r,g,b;
};


class Mesh {
public:
    GLuint VAO, VBO;
    std::vector<Polygon> vertices;

    Mesh(const std::vector<Polygon>& verts);
    void draw();
    void bindVAO();
};