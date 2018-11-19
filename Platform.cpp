//
// Created by nick on 19.11.18.
//

#include "Platform.h"

Platform::Platform(sf::Color col, sf::Vector2f size, sf::Vector2f position) {
    body.setSize(size);
    body.setFillColor(col);
    body.setPosition(position);
    body.setOrigin(size/2.0f);
}

Platform::~Platform() {

}

void Platform::Draw(sf::RenderWindow &window) {
    window.draw(body);
}
