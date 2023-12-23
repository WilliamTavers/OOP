#include "Enemy2.hpp"

#include "Player.hpp"

// initializing the enemy's shape
void Enemy2::initshape() {
  // set radius/size to 20
  this->shape.setRadius(40);
  // set colour to red
  this->shape.setFillColor(sf::Color::Red);
}

sf::CircleShape Enemy2::getShape() { return this->shape; }

float Enemy2::getMovementspeed() { return this->movementspeed; }
// Run the constructor given the window
Enemy2::Enemy2(const sf::RenderWindow& window) {
  this->movementspeed = 1.f;
  this->initshape();
  this->generatespawn(window);
}

Enemy2::~Enemy2() {}
// Generate spawn function
void Enemy2::generatespawn(const sf::RenderWindow& window) {
  // creating a random point in the window
  float randx = static_cast<float>(rand() % window.getSize().x -
                                   this->shape.getGlobalBounds().width);
  float randy = static_cast<float>(rand() % window.getSize().y -
                                   this->shape.getGlobalBounds().height);
  // if the x position is closer to a windows edge than the y position
  if (window.getSize().x - randx <= window.getSize().y - randy) {
    // if generated x value is closer to left border (0), set x position to 0
    // otherwise set x position ro right border
    if (randx <= window.getSize().x - randx) {
      randx = this->shape.getGlobalBounds().width;
    } else {
      randx = window.getSize().x - this->shape.getGlobalBounds().width;
    }
  } else {
    // if generated y value is closer to bottom border set y position to bottom
    // border otherwise set y position to top border (0)
    if (randy >= window.getSize().y - randy) {
      randy = window.getSize().y - this->shape.getGlobalBounds().height;
    } else {
      randy = this->shape.getGlobalBounds().height;
    }
  }

  this->shape.setPosition(randx, randy);
}

// render the enemy
void Enemy2::render(sf::RenderTarget* target) { target->draw(this->shape); }
