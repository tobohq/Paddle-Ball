#include <SFML/Graphics.hpp>
#include <iostream>
#include "ball.h"
#include "Paddle.h"

int main()
{
    auto window = sf::RenderWindow(sf::VideoMode({1920u, 1080u}), "CMake SFML Project");
    window.setFramerateLimit(144);

    sf::Vector2u windowSize = window.getSize();
    float x = windowSize.x / 2.0f; // gets centered x
    float y = windowSize.y / 2.0f; // gets centered y

    Ball ball(80, x, y);

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

        window.display();

    }
}
