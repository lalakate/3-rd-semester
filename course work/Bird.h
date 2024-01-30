#ifndef FLAPPY_BIRD_COURSE_WORK_BIRD_H
#define FLAPPY_BIRD_COURSE_WORK_BIRD_H

#pragma once

#include "defines.h"
#include "Game.h"
#include <vector>

class Bird {
public:
    Bird(GameDataRef data);

    ~Bird();

    void Draw();

    void Animate(float dt);

    void Update(float dt);

    void Tap();

    const sf::Sprite &GetSprite() const;

private:
    GameDataRef _data;
    sf::Sprite _birdSprite;
    std::vector<sf::Texture> _animationFrames;
    unsigned int _animationIterator;
    sf::Clock _clock;
    sf::Clock _movementClock;
    int _birdState;
    float _rotation;
};


#endif //FLAPPY_BIRD_COURSE_WORK_BIRD_H
