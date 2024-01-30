#ifndef FLAPPY_BIRD_COURSE_WORK_SPLASHSTATE_H
#define FLAPPY_BIRD_COURSE_WORK_SPLASHSTATE_H

#include <SFML/Graphics.hpp>
#include "State.h"
#include "Game.h"

class SplashState {
public:
    SplashState(GameDataRef data);

    void Init();

    void HandleInput();

    void Update(float dt);

    void Draw(float dt);

private:
    GameDataRef _data;
    sf::Clock _clock;
    sf::Sprite _background;
};


#endif //FLAPPY_BIRD_COURSE_WORK_SPLASHSTATE_H
