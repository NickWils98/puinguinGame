//
// Created by nick on 19.11.18.
//

#ifndef GAME_PLAYER_H
#define GAME_PLAYER_H


#include <SFML/Graphics/RectangleShape.hpp>
#include "Animation.h"
#include "Collider.h"

class Player {
public:
    Player(sf::Texture *texture, sf::Vector2u imageCount, float switchTime, float speed, float jumpHeight);
    ~Player();

    void Update(float deltaTime);
    void Draw(sf::RenderWindow& window);
    void OnCollision(sf::Vector2f direction);

    sf::Vector2f getPosition() {return body.getPosition();};
    Collider GetCollider() {return Collider(body);};

private:
    sf::RectangleShape body;
    Animation animation;
    unsigned int row;
    float speed;
    bool faceRight;

    sf::Vector2f velocity;
    bool canJump;
    float jumpHeight;
};


#endif //GAME_PLAYER_H
