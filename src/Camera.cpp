//
// Created by Morey on 20/12/2025.
//

#include "../include/Camera.h"
#include <iostream>

Camera::Camera() {
    std::cout << "Creating Camera" << std::endl;
}

glm::mat4 Camera::GetOrthoMatrix(unsigned int& width,unsigned int& height, float& tileSize) {

    glm::mat4 ortho = glm::ortho(
    -width*tileSize/2.0f, width*tileSize/2.0f,
    -height*tileSize/2.0f, height*tileSize/2.0f,
    -1.0f, 1.0f
);

    return ortho;
}