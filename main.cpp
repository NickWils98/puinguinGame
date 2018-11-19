#include <SFML/Graphics.hpp>
#include <iostream>
#include "Player.h"
#include "Platform.h"

#include <vector>

static const float VIEW_HEIGHT = 512.0f;

void ResizeView(const sf::RenderWindow& window, sf::View& view){
    float aspectRatio = static_cast<float>(window.getSize().x) / static_cast<float>(window.getSize().y);
    view.setSize(VIEW_HEIGHT*aspectRatio, VIEW_HEIGHT);
}
int main()
{
    sf::RenderWindow window(sf::VideoMode(700, 700), "SFML Tutorial", sf::Style::Close | sf::Style::Resize);
    sf::View view(sf::Vector2f(0.0f, 0.0f), sf::Vector2f(VIEW_HEIGHT, VIEW_HEIGHT));
    sf::Texture playerTexture;
    playerTexture.loadFromFile("../Textures/kisi.png");

    Player player(&playerTexture, sf::Vector2u(3,9), 0.3f, 100.0f, 200.0f);

    std::vector<Platform> platforms;
    platforms.push_back(Platform(sf::Color::Red, sf::Vector2f(400.0f, 200.0f), sf::Vector2f(500.0f, 200.0f)));
    platforms.push_back(Platform(sf::Color::Blue, sf::Vector2f(400.0f, 200.0f), sf::Vector2f(500.0f, 100.0f)));
    platforms.push_back(Platform(sf::Color(150,60,113), sf::Vector2f(1000.0f, 200.0f), sf::Vector2f(500.0f, 500.0f)));


    float deltaTime;
    sf::Clock clock;

    while(window.isOpen())
    {
        deltaTime = clock.restart().asSeconds();
//        if(deltaTime>1.0f/20.0f){
//            deltaTime= 1.0f/20.0f;
//        }

        sf::Event evnt;
        while(window.pollEvent(evnt))
        {
            switch(evnt.type)
            {
            case sf::Event::Closed:
                window.close();
                break;
            case sf::Event::Resized:
                ResizeView(window, view);
                break;
            }
        }

        player.Update(deltaTime);


        sf::Vector2f direction;
        Collider col = player.GetCollider();

        for(int i =0; i<platforms.size(); i++){
            if(platforms[2].GetCollider().CheckCollision(col, direction, 1.0f)){
                player.OnCollision((direction));
            } else if(platforms[0].GetCollider().CheckCollision(col, direction, 0.2f)){
                player.OnCollision((direction));
            } else if(platforms[1].GetCollider().CheckCollision(col, direction, 1.0f)){
                player.OnCollision((direction));
            }
        }




        view.setCenter(player.getPosition());

        window.clear(sf::Color(150, 150, 150));
        window.setView(view);
        player.Draw(window);
        for(Platform& platform : platforms){
            platform.Draw(window);
        }

        window.display();
    }

    return 0;
}