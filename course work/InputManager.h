#ifndef FLAPPY_BIRD_COURSE_WORK_INPUTMANAGER_H
#define FLAPPY_BIRD_COURSE_WORK_INPUTMANAGER_H

#pragma once

#include "SFML/Graphics.hpp"

class InputManager {
public:
    InputManager() {}

    ~InputManager() {}

    bool IsSpriteClicked(sf::Sprite object, sf::Mouse::Button button, sf::RenderWindow &window);

    sf::Vector2i GetMousePosition(sf::RenderWindow &window);
};


#endif //FLAPPY_BIRD_COURSE_WORK_INPUTMANAGER_H
