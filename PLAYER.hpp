#ifndef __PLAYER_H__
#define __PLAYER_H__
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <ctime>

class Player {
 private:
  void initshape();
  void initvariables();
  float movementSpeed;
  float attackcooldown;
  float attackcooldownMax;

 public:
  bool isAlive;
  sf::RectangleShape shape;
  Player();

  ~Player();

  void updateInput();
  void updateWindowBoundCollision(const sf::RenderTarget* target);
  void updateCooldown();
  void update(const sf::RenderTarget* target);
  void render(sf::RenderTarget* target);
  const bool canAttack();
};
#endif