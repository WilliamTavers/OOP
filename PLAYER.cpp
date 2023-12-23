#include "Player.hpp"
Player::Player() {
  this->initvariables();
  this->initshape();
}

Player::~Player() {}

void Player::updateInput() {
  // keyboard input
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
    this->shape.move(-this->movementSpeed, 0.f);
  } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
    this->shape.move(this->movementSpeed, 0.f);
  };
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
    this->shape.move(0.f, -this->movementSpeed);
  } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
    this->shape.move(0.f, this->movementSpeed);
  };
}

void Player::updateWindowBoundCollision(const sf::RenderTarget* target) {
  // left
  if (this->shape.getGlobalBounds().left <= 0.f) {
    this->shape.setPosition(0.f, this->shape.getGlobalBounds().top);
  }
  // right
  if (this->shape.getGlobalBounds().left +
          this->shape.getGlobalBounds().width >=
      target->getSize().x) {
    this->shape.setPosition(
        target->getSize().x - this->shape.getGlobalBounds().width,
        this->shape.getGlobalBounds().top);
  };
  // top
  if (this->shape.getGlobalBounds().top <= 0.f) {
    this->shape.setPosition(this->shape.getGlobalBounds().left, 0.f);
  }
  // bottom
  if (this->shape.getGlobalBounds().top +
          this->shape.getGlobalBounds().height >=
      target->getSize().y) {
    this->shape.setPosition(
        this->shape.getGlobalBounds().left,
        target->getSize().y - this->shape.getGlobalBounds().height);
  };
}

void Player::updateCooldown() {
  if (this->attackcooldown < attackcooldownMax) {
    this->attackcooldown += 0.5f;
  }
}

void Player::update(const sf::RenderTarget* target) {
  this->updateCooldown();
  this->updateInput();
  this->updateWindowBoundCollision(target);
}

void Player::render(sf::RenderTarget* target) { target->draw(this->shape); }

const bool Player::canAttack() {
  if (this->attackcooldown >= this->attackcooldownMax) {
    this->attackcooldown = 0.f;
    return true;
  }
  return false;
}

void Player::initvariables() {
  this->isAlive = true;
  this->movementSpeed = 5.f;
  this->attackcooldownMax = 25.f;
  this->attackcooldown = this->attackcooldownMax;
}

void Player::initshape() {
  this->shape.setFillColor(sf::Color::Green);
  this->shape.setSize(sf::Vector2f(50.f, 50.f));
}
