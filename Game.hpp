#ifndef __GAME_H__
#define __GAME_H__
#include <sstream>
#include <vector>

#include "Bullet.hpp"
#include "Enemy.hpp"
#include "Enemy2.hpp"
#include "EnemyEntity.hpp"
#include "Player.hpp"

class Game {
 private:
  // window
  sf::VideoMode videoMode;
  sf::RenderWindow* window;
  bool endGame;
  sf::Event sfmlEvent;
  // initialize the window , game variables and systems
  void initVaraibles();
  void initWindow();
  void initSystems();
  // create the player
  Player player;
  // vector for enemies
  std::vector<Enemy> Enemies;
  std::vector<Enemy2> Enemies2;
  // timer for enemy spawn
  float spawnTimer2Max;
  float spawnTimer2;
  float spawnTimerMax;
  float spawnTimer;
  // max amount of enemies
  int maxEnemies;
  int maxEnemies2;
  // texts

  sf::Font font;
  sf::Text write;
  sf::Text Gameover;
  // Score System
  unsigned score;
  void initGUI();
  // vector for bullets
  std::vector<Bullet*> bullets;

 public:
  // constructor and destructor
  Game();
  ~Game();
  // Window accessor
  sf::RenderWindow* getWindow();
  // Functions
  void EnemyMovement();
  // Spawn enemies
  void spawnEnemies();
  // spawn the player
  void spawnPlayer();
  // Run the game
  void running();
  // Update functions that track collision, movement and inputs
  void pollEvents();     // closing the window
  void updateInputs();   // shooting ect
  void updateGUI();      // the score
  void updateBullets();  // bullet movement
  void updateEnemies();
  void updateEnemies2();  // enemy movement
  void update();          // overall update
  // Render functions for GUI and the update functions
  void renderGUI(sf::RenderTarget* focus);
  void render();
};
#endif  // __GAME_H__