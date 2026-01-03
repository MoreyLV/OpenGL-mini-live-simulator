//
// Created by Morey on 20/12/2025.
//

#include "../include/Rendering.h"
#include <iostream>

Rendering::Rendering() {
    std::cout << "Creating Rendering" << std::endl;
}
void Rendering::RenderTriangle(const int& size_of_object) {
    glDrawArrays(GL_TRIANGLES, 0, size_of_object);
    glBindVertexArray(0);
}
