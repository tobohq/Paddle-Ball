#include "ball.h"

// Constructors
Ball::Ball()
    : Ball(0, 0, 0) {

}

Ball::Ball(float radius, float x, float y)
    : sf::CircleShape(radius), start_position(x, y), velocity(2, 2), radius(radius)
{
    sf::Vector2f center = sf::Vector2f(radius, radius); // need to make the anchor in middle

    setOrigin(center);
    setFillColor(sf::Color::White);
    setPosition(start_position);

}

// Getters
sf::Vector2f Ball::getVelocity() {
    return velocity;
}

// Setters
void Ball::setVelocity(const sf::Vector2f& velocity) {
    this->velocity = velocity;
}


// Member Functions
void Ball::bounceBall(const sf::Vector2u &winSize) {
    sf::Vector2f velocity = this->velocity;
    float x = winSize.x; // 0 -> 1440
    float y = winSize.y; // 0 -> 785

    float ball_y = getPosition().y;
    float ball_x = getPosition().x;

    if ( ball_y > y-radius || ball_y-radius < 0) { // if the ball goes over the max y window size
        if (ball_y > y-radius) {
            velocity = sf::Vector2f(velocity.x, -velocity.y); // go down
        } else {
            velocity = sf::Vector2f(velocity.x, abs(velocity.y)); // else go up
        }
        setVelocity(velocity);
    } else if ( ball_x > x-radius || ball_x-radius < 0 ) { //if the ball goes over the max x window size
        if (ball_x > x-radius) {
            velocity = sf::Vector2f(-velocity.x, velocity.y); // go left
        } else {
            velocity = sf::Vector2f(abs(velocity.x), velocity.y); // else go right
        }
        setVelocity(velocity);
    }

    // std::cout << "VELOCITY" << std::endl;
    // std::cout << velocity.x << "," << velocity.y << std::endl;
    // std::cout << "BALL POSITION" << std::endl;
    // std::cout << ball_x << "," << ball_y << std::endl << std::endl;
    move(velocity);
}
