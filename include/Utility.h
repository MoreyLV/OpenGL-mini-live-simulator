//
// Created by Morey on 20/12/2025.
//
#pragma once
#include <glad/glad.h>
#include "random"

class Utility {
    public:
    Utility();
    static void ClearWindow(const float& r, const float& g, const float& b, const float& a);

    static int RandomInt(const int& min, const int& max);
};

