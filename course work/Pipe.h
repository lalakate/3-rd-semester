#ifndef FLAPPY_BIRD_COURSE_WORK_PIPE_H
#define FLAPPY_BIRD_COURSE_WORK_PIPE_H

#pragma once

#include <SFML/Graphics.hpp>
#include "Game.h"
#include <vector>

class Pipe {
public:
    Pipe(GameDataRef data);

    void SpawnBottomPipe();

    void SpawnTopPipe();

    void SpawnInvisiblePipe();

    void SpawnScoringPipe();

    void MovePipes(float dt);

    void DrawPipes();

    void RandomisePipeOffset();

    const std::vector<sf::Sprite> &GetSprites() const;

    std::vector<sf::Sprite> &GetScoringSprites();

private:
    GameDataRef _data;
    std::vector<sf::Sprite> pipeSprites;
    std::vector<sf::Sprite> scoringPipes;

    int landHeight;
    int pipeSpawnYOffset;
};


#endif //FLAPPY_BIRD_COURSE_WORK_PIPE_H
