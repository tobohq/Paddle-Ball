
#include "ball.h"
Ball::Ball()
    : Ball(0, 0, 0) {

}

Ball::Ball(float radius, float x, float y)
    : sf::CircleShape(radius), position(x,y), velocity(0,0) {
    sf::Vector2f center = sf::Vector2f(radius, radius); // need to make the anchor in middle

    setOrigin(center);
    setFillColor(sf::Color::White);
    setPosition(position);
}