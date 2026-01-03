//
// Created by Morey on 20/12/2025.
//
#pragma once
#include <glad/glad.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

class Camera {
public:
    Camera();

    static glm::mat4 GetOrthoMatrix(unsigned int& width,unsigned int& height, float& tileSize);
};
