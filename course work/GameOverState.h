#ifndef FLAPPY_BIRD_COURSE_WORK_GAMEOVERSTATE_H
#define FLAPPY_BIRD_COURSE_WORK_GAMEOVERSTATE_H

#pragma once

#include <SFML/Graphics.hpp>
#include "State.h"
#include "Game.h"

class GameOverState : public State {
public:
    GameOverState(GameDataRef data, int score);

    void Init();

    void HandleInput();

    void Update(float dt);

    void Draw(float dt);

private:
    GameDataRef _data;

    sf::Sprite _background;

    sf::Sprite _gameOverContainer;
    sf::Sprite _gameOverTitle;
    sf::Sprite _retryButton;
    sf::Sprite _medal;

    sf::Text _scoreText;
    sf::Text _highScoreText;

    int _score;
    int _highscore;
};


#endif //FLAPPY_BIRD_COURSE_WORK_GAMEOVERSTATE_H
