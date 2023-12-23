#include "Bullet.hpp"

// initializing the bullet's shape with aa radius and color
void Bullet::initShape() {
  this->shape.setRadius(12.f);
  this->shape.setFillColor(sf::Color::Yellow);
}

// constructor for bullet
// Becuase the bullet only spawns at the player and with a given direction, it
// needs parameters
Bullet::Bullet(float pos_x, float pos_y, float dir_x, float dir_y,
               float movementspeed) {
  // run the shape initilization function
  this->initShape();
  // Set the position given paramters and cetnre it on the player, the pos x and
  // y are given via game.cpp
  this->shape.setPosition(pos_x - shape.getGlobalBounds().width / 2,
                          pos_y - shape.getGlobalBounds().height / 2);
  // The direction of the bullet is either 1,0 0,1 -1,0 or 0,-1
  // These directions will be passed based on inputs from user
  this->direction.x = dir_x;
  this->direction.y = dir_y;
  // Initialize movementspeed
  this->movementspeed = movementspeed;
}

Bullet::~Bullet() {}

// update will concern the bullets movement
// using the direction and movementspeed from the constructor, we simply pass
// their product to the move function given by sfml
void Bullet::update() {
  this->shape.move(this->movementspeed * this->direction);
}

// rendering the bullet to the screen
void Bullet::render(sf::RenderTarget *target) { target->draw(this->shape); }
