//
// Created by Morey on 20/12/2025.
//

#include "../include/Shader.h"
#include <iostream>

Shader::Shader(const char *vsSrc, const char *fsSrc) {

    GLuint vshader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vshader, 1, &vsSrc, nullptr);
    glCompileShader(vshader);

    int success;
    char info[512];
    GLint programInfo;

    glGetShaderiv(vshader, GL_COMPILE_STATUS, &success);
    if (!success) {
        glGetShaderInfoLog(vshader, 512, nullptr, info);
        std::cout << info << std::endl;
    }else {
        std::cout << "VSHADER INITIALIZED SUCCESSFULLY " << std::endl;
    }
    GLuint fshader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fshader, 1, &fsSrc, nullptr);
    glCompileShader(fshader);

    glGetShaderiv(fshader, GL_COMPILE_STATUS, &success);
    if (!success) {
        glGetShaderInfoLog(fshader, 512, nullptr, info);
        std::cout << info << std::endl;
    }
    else {
        std::cout << "FSHADER INITIALIZED SUCCESSFULLY " << std::endl;
    }

    ID = glCreateProgram();

    glAttachShader(ID, vshader);
    glAttachShader(ID, fshader);
    glLinkProgram(ID);

    glGetProgramiv(ID, GL_LINK_STATUS, &success);
    if (!success) {
        glGetProgramiv(ID, GL_INFO_LOG_LENGTH, &programInfo);
        std::cout << programInfo << std::endl;
    }else {
        std::cout << "PROGRAM INITIALIZED WITHOUT ERRORS " << std::endl;
    }


    glDeleteShader(vshader);
    glDeleteShader(fshader);
    std::cout << "SHADER CACHE REMOVED" << std::endl;

}

void Shader::use() {
    glUseProgram(ID);
}

void Shader::setMat4(const char* name, const float* value) {
    GLuint loc = glGetUniformLocation(ID, name);
    glUniformMatrix4fv(loc, 1, GL_FALSE, value);
}

void Shader::setVec2(const std::string& name, float x, float y) {
    GLint loc = glGetUniformLocation(ID, name.c_str());
    glUniform2f(loc, x, y);
}

void Shader::setVec3(const std::string& name, float r, float g, float b) {
    GLint loc = glGetUniformLocation(ID, name.c_str());
    glUniform3f(loc, r, g, b);
}

void Shader::setVec4(const std::string& name, float r, float g, float b, float a) {
    GLint loc = glGetUniformLocation(ID, name.c_str());
    glUniform4f(loc, r, g, b, a);
}