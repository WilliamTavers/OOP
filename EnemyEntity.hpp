#ifndef __ENEMYENTITY_H__
#define __ENEMYENTITY_H__
#include "Player.hpp"
class EnemyEntity {
 public:
  virtual void initshape() = 0;
  virtual sf::CircleShape getShape() = 0;
  virtual float getMovementspeed() = 0;

  // generatespawn is a fucntion that ensures the spawn of each enemy is along
  // the windows edges
  virtual void generatespawn(const sf::RenderWindow& window) = 0;
  // no update function needed as the movement will be done in game.cpp
  //  render
  virtual void render(sf::RenderTarget* target) = 0;
};

#endif