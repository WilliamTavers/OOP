#ifndef __ENEMY_H__
#define __ENEMY_H__
#include "EnemyEntity.hpp"
#include "Player.hpp"
class Enemy : public EnemyEntity {
 protected:
  // intialize the shape of the enemy
  void initshape();

 public:
  float movementspeed;
  sf::CircleShape getShape();
  float getMovementspeed();

  // constructor
  Enemy(const sf::RenderWindow& window);
  // destructor
  ~Enemy();
  // the enemies shape
  sf::CircleShape shape;
  // generatespawn is a fucntion that ensures the spawn of each enemy is along
  // the windows edges
  void generatespawn(const sf::RenderWindow& window);
  // no update function needed as the movement will be done in game.cpp
  //  render
  void render(sf::RenderTarget* target);
};

#endif  // __ENEMY_H__