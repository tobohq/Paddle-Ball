
#ifndef BALL_H
#define BALL_H

#include <SFML/Graphics.hpp>
#include <iostream>

class Ball : public sf::CircleShape {
    private:
    sf::Vector2f start_position;
    sf::Vector2f velocity;
    float radius;

    public:
    Ball();
    Ball(float radius, float x, float y);

    sf::Vector2f getVelocity();
    void setVelocity(const sf::Vector2f& velocity);
    void bounceBall(const sf::Vector2u& winSize);
};

#endif //BALL_H
