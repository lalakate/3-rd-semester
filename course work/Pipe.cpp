#include "Pipe.h"
#include "defines.h"

#include <iostream>

Pipe::Pipe(GameDataRef data) : _data(data) {
    landHeight = this->_data->assets.GetTexture("Land").getSize().y;
    pipeSpawnYOffset = 0;
}

void Pipe::SpawnBottomPipe() {
    sf::Sprite sprite(this->_data->assets.GetTexture("Pipe Up"));

    sprite.setPosition(this->_data->window.getSize().x,
                       this->_data->window.getSize().y - sprite.getLocalBounds().height - pipeSpawnYOffset);

    pipeSprites.push_back(sprite);
}

void Pipe::SpawnTopPipe() {
    sf::Sprite sprite(this->_data->assets.GetTexture("Pipe Down"));

    sprite.setPosition(this->_data->window.getSize().x, -pipeSpawnYOffset);

    pipeSprites.push_back(sprite);
}

void Pipe::SpawnInvisiblePipe() {
    sf::Sprite sprite(this->_data->assets.GetTexture("Pipe Down"));

    sprite.setPosition(this->_data->window.getSize().x, -pipeSpawnYOffset);
    sprite.setColor(sf::Color(0, 0, 0, 0));

    pipeSprites.push_back(sprite);
}

void Pipe::SpawnScoringPipe() {
    sf::Sprite sprite(this->_data->assets.GetTexture("Scoring Pipe"));

    sprite.setPosition(this->_data->window.getSize().x, 0);

    scoringPipes.push_back(sprite);
}

void Pipe::MovePipes(float dt) {
    for (int i = 0; i < pipeSprites.size(); i++) {
        if (pipeSprites.at(i).getPosition().x < 0 - pipeSprites.at(i).getLocalBounds().width) {
            pipeSprites.erase(pipeSprites.begin() + i);
        } else {
            sf::Vector2f position = pipeSprites.at(i).getPosition();
            float movement = PIPE_MOVEMENT_SPEED * dt;

            pipeSprites.at(i).move(-movement, 0);
        }
    }

    for (int i = 0; i < scoringPipes.size(); i++) {
        if (scoringPipes.at(i).getPosition().x < 0 - scoringPipes.at(i).getLocalBounds().width) {
            scoringPipes.erase(scoringPipes.begin() + i);
        } else {
            sf::Vector2f position = scoringPipes.at(i).getPosition();
            float movement = PIPE_MOVEMENT_SPEED * dt;

            scoringPipes.at(i).move(-movement, 0);
        }
    }
}

void Pipe::DrawPipes() {
    for (unsigned short int i = 0; i < pipeSprites.size(); i++) {
        this->_data->window.draw(pipeSprites.at(i));
    }
}

void Pipe::RandomisePipeOffset() {
    pipeSpawnYOffset = rand() % (landHeight + 1);
}

const std::vector<sf::Sprite> &Pipe::GetSprites() const {
    return pipeSprites;
}

std::vector<sf::Sprite> &Pipe::GetScoringSprites() {
    return scoringPipes;
}