#ifndef FLAPPY_BIRD_COURSE_WORK_FLASH_H
#define FLAPPY_BIRD_COURSE_WORK_FLASH_H

#pragma once

#include <SFML/Graphics.hpp>
#include "Game.h"
#include "defines.h"

class Flash {
public:
    Flash(GameDataRef data);

    ~Flash();

    void Show(float dt);

    void Draw();

private:
    GameDataRef _data;
    sf::RectangleShape _shape;
    bool _flashOn;
};


#endif //FLAPPY_BIRD_COURSE_WORK_FLASH_H
