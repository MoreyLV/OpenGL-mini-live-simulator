//
// Created by Morey on 20/12/2025.
//

#include "../include/Mesh.h"
#include <iostream>


Mesh::Mesh(const std::vector<Polygon> &verts) {
    vertices = verts;
    std::cout << "Creating Meshes" << std::endl;
}
void Mesh::draw() {
    std::cout << "GRAPHIC BUILD STARTED" << std::endl;
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);

    glBindVertexArray(VAO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(Polygon), vertices.data(), GL_STATIC_DRAW);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Polygon), (void*)0);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(Polygon), (void*)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);

    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);

    std::cout << "GRAPHIC BUILD FINISHED" << std::endl;
}
void Mesh::bindVAO() {
    glBindVertexArray(VAO);
}