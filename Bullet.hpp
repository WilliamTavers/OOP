#ifndef __BULLET_H__
#define __BULLET_H__
#include "Player.hpp"
// Header file for the bullet
// The bullet is used to kill enemies
// The bullet has a trajectory, shape, and coordinates

class Bullet {
 private:
  // initialzing shape information of bullet
  void initShape();

 public:
  // The bullets's shape
  sf::CircleShape shape;
  // How fast the bullet will travel
  float movementspeed;
  // The direction of the bullet upon creation
  sf::Vector2f direction;
  // contrutor with specific paramters
  Bullet(float pos_x, float pos_y, float dir_x, float dir_y,
         float movementspeed);
  // deconstructor
  virtual ~Bullet();
  // updating bullet information prior to next render
  void update();
  // render, the target parameter is the window
  void render(sf::RenderTarget *target);
};

#endif  // __BULLET_H__