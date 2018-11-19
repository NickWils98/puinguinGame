//
// Created by nick on 19.11.18.
//

#ifndef GAME_ANIMATION_H
#define GAME_ANIMATION_H


#include <SFML/Graphics.hpp>

class Animation {
public:
    Animation(sf::Texture* texture, sf::Vector2u imageCount, float switchTime);
    ~Animation();

    void Update(int row, float deltaTime, bool faceRight);
public:
    sf::IntRect uvRect;

private:
    sf::Vector2u imageCount;
    sf::Vector2u currentImage;

    float totalTime;
    float switchTime;


};


#endif //GAME_ANIMATION_H
