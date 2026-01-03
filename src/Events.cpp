//
// Created by Morey on 20/12/2025.
//

#include "../include/Events.h"
#include <iostream>

Events::Events() {
    std::cout << "Creating Events" << std::endl;
}

bool Events::CheckClosingEvent(const sf::Event& event) {
    if (event.type == sf::Event::Closed){
        running = false;
        std::cout << "Closing..." << std::endl;
        return running;
    }
    if (event.type == sf::Event::KeyPressed &&
        event.key.code == sf::Keyboard::Escape){
        running = false;
        std::cout << "Closing..." << std::endl;
        return running;
    }
    if (running) {
        return true;
    }
}


