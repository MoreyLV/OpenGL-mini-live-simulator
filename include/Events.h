//
// Created by Morey on 20/12/2025.
//

#pragma once
#include <glad/glad.h>
#include "SFML/Window/Event.hpp"
#include "SFML/Window/VideoMode.hpp"

class Events {
    bool running = true;

    public:
    Events();
    bool CheckClosingEvent(const sf::Event& event);
};
