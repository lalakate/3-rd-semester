#ifndef FLAPPY_BIRD_COURSE_WORK_HUD_H
#define FLAPPY_BIRD_COURSE_WORK_HUD_H

#pragma once

#include <SFML/Graphics.hpp>
#include "defines.h"
#include "Game.h"

class HUD {
public:
    HUD(GameDataRef data);

    ~HUD();

    void Draw();

    void UpdateScore(int score);

private:
    GameDataRef _data;
    sf::Text _scoreText;
};


#endif //FLAPPY_BIRD_COURSE_WORK_HUD_H
