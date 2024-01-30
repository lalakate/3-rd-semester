#ifndef FLAPPY_BIRD_COURSE_WORK_ASSETMANAGER_H
#define FLAPPY_BIRD_COURSE_WORK_ASSETMANAGER_H

#include <SFML/Graphics.hpp>
#include <map>

class AssetManager {
public:
    AssetManager() {}

    ~AssetManager() {}

    void LoadTexture(std::string name, std::string fileName);

    sf::Texture &GetTexture(std::string name);

    void LoadFont(std::string name, std::string fileName);

    sf::Font &GetFont(std::string name);

private:
    std::map<std::string, sf::Texture> _textures;
    std::map<std::string, sf::Font> _fonts;
};


#endif //FLAPPY_BIRD_COURSE_WORK_ASSETMANAGER_H