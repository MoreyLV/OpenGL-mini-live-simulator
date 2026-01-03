//
// Created by Morey on 20/12/2025.
//
#pragma once
#include <glad/glad.h>
#include <string>

#include "glm/fwd.hpp"

class Shader {
public:
    GLuint ID;

    Shader(const char* vertexPath, const char* fragmentPath);
    void use();
    void setMat4(const char* name, const float* value);

    void setVec2(const std::string &name, float x, float y);

    void setVec3(const std::string &name, float r, float g, float b);

    void setVec4(const std::string &name, float r, float g, float b, float a);
};
