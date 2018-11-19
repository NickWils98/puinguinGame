//
// Created by nick on 19.11.18.
//

#ifndef GAME_PLATFORM_H
#define GAME_PLATFORM_H


#include <SFML/Graphics.hpp>
#include "Collider.h"

class Platform {
public:
    Platform(sf::Color col, sf::Vector2f size, sf::Vector2f position);
    ~Platform();

    void Draw(sf::RenderWindow& window);
    Collider GetCollider(){return Collider(body);};


private:
    sf::RectangleShape body;
};


#endif //GAME_PLATFORM_H
