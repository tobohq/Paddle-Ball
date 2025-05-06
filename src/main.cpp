#include <SFML/Graphics.hpp>
#include <iostream>
#include "ball.h"
#include "Paddle.h"
#include "SFML/Audio/Listener.hpp"

int main()
{
    auto window = sf::RenderWindow(sf::VideoMode({1920u, 1080u}), "CMake SFML Project");
    window.setFramerateLimit(144);

    sf::Vector2u windowSize = window.getSize();
    Ball ball(80, windowSize.x / 2.0f, windowSize.y / 2.0f);
    std::cout << windowSize.x << std::endl;
    std::cout << windowSize.y << std::endl;

    while (window.isOpen())
    {
        while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
            {
                window.close();
            }

        }
        window.clear();

        window.draw(ball);
        ball.bounceBall(windowSize);

        window.display();

    }
}
