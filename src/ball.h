
#ifndef BALL_H
#define BALL_H

#include <SFML/Graphics.hpp>

class Ball : public sf::CircleShape {
    private:
    sf::Vector2f position;
    sf::Vector2f velocity;

    public:
    Ball();
    Ball(float radius, float x, float y);
};

#endif //BALL_H
