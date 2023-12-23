// The cpp file for the Game Header
// This will create the game variables, the font used for the game, the score
// tracker Th

#include "Game.hpp"

#include <cmath>
#include <iostream>

using namespace std;
// Initializing variables
void Game::initVaraibles() {
  this->endGame = false;
  this->spawnTimer = this->spawnTimerMax;
  this->spawnTimerMax = 50.f;
  this->spawnTimer2 = this->spawnTimer2Max;
  this->spawnTimerMax = 100.f;
  this->maxEnemies2 = 2;
  this->maxEnemies =
      5;            // The max amount of enemies to be in the came at a time
  this->score = 0;  // creating a score system to track kill count
}

// The window for the game to be played
void Game::initWindow() {
  this->videoMode = sf::VideoMode(1200, 1000);  // The size of the window
  this->window = new sf::RenderWindow(this->videoMode, "OOP Project",
                                      sf::Style::Close | sf::Style::Titlebar);
  this->window->setFramerateLimit(60);
}

// The specific font used to display the score

// Writing the score tracker
// The tracker will be white and will be using the font loaded in from file
void Game::initSystems() { this->score = 0; }
void Game::initGUI() {
  // if texts fail to load then produce message
  if (!this->font.loadFromFile("PixellettersFull.ttf")) {
    cout << "ERROR::INITFONT::COULD NOT LOAD" << endl;
  }
  // intitialize the score text variables and the gameover text varibales
  this->write.setFont(this->font);
  this->write.setFillColor(sf::Color::White);
  this->write.setCharacterSize(40);
  this->write.setString("SCORE: ");
  this->Gameover.setFont(this->font);
  this->Gameover.setFillColor(sf::Color::Red);
  this->Gameover.setCharacterSize(60);
  this->Gameover.setString("GAMEOVER!");
  this->Gameover.setPosition(
      window->getSize().x / 2.f - Gameover.getGlobalBounds().width / 2.f,
      window->getSize().y / 2.f - Gameover.getGlobalBounds().height / 2.f);
}

// constructor
Game::Game() {
  // run all the intiliazing functions and spawn the player
  this->initWindow();
  this->spawnPlayer();
  this->initSystems();
  this->initVaraibles();

  this->initGUI();
}
// destructor
Game::~Game() { delete this->window; }

sf::RenderWindow* Game::getWindow() { return this->window; }
// The movement of the enemy
// Enemies will move in the direction of the user
// Enemies will be slower than the user
// loop to perform movement of every enemy
void Game::EnemyMovement() {
  for (int i = 0; i < Enemies.size(); i++) {
    // create a vector
    sf::Vector2f vec;

    // finding direction for enemy movement
    // find the x and y difference of player position with
    // enemy position
    vec.x =
        player.shape.getPosition().x - Enemies[i].getShape().getPosition().x;
    vec.y =
        player.shape.getPosition().y - Enemies[i].getShape().getPosition().y;

    // draw a line from the player and enemy using pythagoreas
    float magnitude = sqrtf(vec.x * vec.x + vec.y * vec.y);
    if (magnitude != 0) {
      // noamlize the vector so that it is constant and not dependent on the
      // distance
      vec.x /= magnitude;
      vec.y /= magnitude;
    }
    // multiply by desired speed
    vec.x *= Enemies[i].movementspeed;
    vec.y *= Enemies[i].movementspeed;
    // move the current enemy usig the normalised vector
    this->Enemies[i].shape.move(vec);
  }
  for (int i = 0; i < Enemies2.size(); i++) {
    // create a vector
    sf::Vector2f vec;

    // finding direction for enemy movement
    // find the x and y difference of player position with
    // enemy position
    vec.x =
        player.shape.getPosition().x - Enemies2[i].getShape().getPosition().x;
    vec.y =
        player.shape.getPosition().y - Enemies2[i].getShape().getPosition().y;

    // draw a line from the player and enemy using pythagoreas
    float magnitude = sqrtf(vec.x * vec.x + vec.y * vec.y);
    if (magnitude != 0) {
      // noamlize the vector so that it is constant and not dependent on the
      // distance
      vec.x /= magnitude;
      vec.y /= magnitude;
    }
    // multiply by desired speed
    vec.x *= Enemies2[i].movementspeed;
    vec.y *= Enemies2[i].movementspeed;
    // move the current enemy usig the normalised vector
    this->Enemies2[i].shape.move(vec);
  }
}
// Spawning the player in middle of screen
void Game::spawnPlayer() {
  // set position of the player relative to the windows size/2
  this->player.shape.setPosition(
      this->window->getSize().x / 2 -
          this->player.shape.getGlobalBounds().width / 2,
      this->window->getSize().x / 2 -
          this->player.shape.getGlobalBounds().height / 2);
}

// while the player is alive, update the game
void Game::running() {
  while (this->window->isOpen()) {
    this->pollEvents();
    if (player.isAlive) {
      this->update();
    }
    this->render();
  }
}
// poll events are just closing window inputs
void Game::pollEvents() {
  while (this->window->pollEvent(this->sfmlEvent)) {
    switch (this->sfmlEvent.type) {
      // if the user pressed the x and the top of the window
      case sf::Event::Closed:
        this->window->close();
        break;
        // if the user pressed the escape key
      case sf::Event::KeyPressed:
        if (this->sfmlEvent.key.code == sf::Keyboard::Escape)
          this->window->close();
        break;
      default:
        break;
    }
  }
}

// Updating game inputs/movement
void Game::updateInputs() {
  // BULLET INPUTS
  // The bullet inputs check for arrow key presses whilst keepung track of
  // whether the player can attack yet
  // Once an arrow key is pressed, the bullet constructor is passed its
  // direction and speed
  // Up arrow
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) &&
      this->player.canAttack()) {
    this->bullets.push_back(
        new Bullet(this->player.shape.getPosition().x +
                       this->player.shape.getGlobalBounds().width / 2,
                   this->player.shape.getPosition().y, 0.f, -1.f, 5.f));
  }
  // Down arrow
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) &&
      this->player.canAttack()) {
    this->bullets.push_back(
        new Bullet(this->player.shape.getPosition().x +
                       this->player.shape.getGlobalBounds().width / 2,
                   this->player.shape.getPosition().y +
                       this->player.shape.getGlobalBounds().height,
                   0.f, 1.f, 5.f));
  }
  // Left arrow
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) &&
      this->player.canAttack()) {
    this->bullets.push_back(
        new Bullet(this->player.shape.getPosition().x,
                   this->player.shape.getPosition().y +
                       this->player.shape.getGlobalBounds().height / 2,
                   -1.f, 0.f, 5.f));
  }
  // Right arrow
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) &&
      this->player.canAttack()) {
    this->bullets.push_back(
        new Bullet(this->player.shape.getPosition().x +
                       +this->player.shape.getGlobalBounds().width,
                   this->player.shape.getPosition().y +
                       this->player.shape.getGlobalBounds().height / 2,
                   1.f, 0.f, 5.f));
  }
}

// There is only one actively changing compenent in the GUI
// the score
void Game::updateGUI() {
  stringstream ss;
  ss << "SCORE: " << this->score;
  this->write.setString(ss.str());
}

// Becuase the bullets are dynamically alloctaed, it is important to delete them
// properly once they leave the screen
void Game::updateBullets() {
  // the counter will track which bullet
  unsigned counter = 0;
  // go across the bullet vector
  for (int i = 0; i < bullets.size(); i++) {
    // update the bullets movement
    bullets[i]->update();
    // bullet culling top screen
    if (bullets[i]->shape.getGlobalBounds().top +
            bullets[i]->shape.getGlobalBounds().height <
        0.f) {
      delete this->bullets.at(counter);
      this->bullets.erase(this->bullets.begin() + counter);
      --counter;
    }
    // bottom of screen
    if (bullets[i]->shape.getGlobalBounds().top -
            bullets[i]->shape.getGlobalBounds().height >
        this->window->getSize().y) {
      delete this->bullets.at(counter);

      this->bullets.erase(this->bullets.begin() + counter);
      --counter;
    }
    // left
    if (bullets[i]->shape.getGlobalBounds().left +
            bullets[i]->shape.getGlobalBounds().width <
        0.f) {
      delete this->bullets.at(counter);

      this->bullets.erase(this->bullets.begin() + counter);
      --counter;
    }
    // right
    if (bullets[i]->shape.getGlobalBounds().left > this->window->getSize().x) {
      delete this->bullets.at(counter);

      this->bullets.erase(this->bullets.begin() + counter);
      --counter;
    }

    ++counter;
  }
}

// The enemies need to be checked against collision of any bullets
void Game::updateEnemies() {
  // scan across all enemies

  for (int i = 0; i < Enemies.size(); i++) {
    // create a flag for the enemy's state
    // otherwise bullets will be checked againt a dead enemy in some cases,
    // causing the game to crash
    bool enemy_deleted = false;

    // scan across all bullets if the enenmy is still alive
    for (int j = 0; j < bullets.size() && enemy_deleted == false; j++) {
      // check if bounds of enemy and bullet intersect
      if (this->bullets[j]->shape.getGlobalBounds().intersects(
              this->Enemies[i].getShape().getGlobalBounds())) {
        this->Enemies.erase(Enemies.begin() + i);
        // if they do, delete the bullet
        delete this->bullets[j];

        // delete the bullet and enemy from respective vectors
        this->bullets.erase(bullets.begin() + j);
        // delete enemy

        // increase the score
        this->score++;
        // change the state of the enemy so no other bullets are checked against
        // it
        enemy_deleted = true;
      }
    }

    // Run collision againt enemy and player for each enemy
    if (this->Enemies[i].getShape().getGlobalBounds().intersects(
            this->player.shape.getGlobalBounds())) {
      // if true, player dies
      player.isAlive = false;
    }
  }
}
void Game::updateEnemies2() {
  for (int i = 0; i < Enemies2.size(); i++) {
    // create a flag for the enemy's state
    // otherwise bullets will be checked againt a dead enemy in some cases,
    // causing the game to crash
    bool enemy2_deleted = false;
    // scan across all bullets if the enenmy is still alive
    for (int j = 0; j < bullets.size() && enemy2_deleted == false; j++) {
      // check if bounds of enemy and bullet intersect
      if (this->bullets[j]->shape.getGlobalBounds().intersects(
              this->Enemies2[i].getShape().getGlobalBounds())) {
        // delete enemy

        this->Enemies2.erase(Enemies2.begin() + i);
        // if they do, delete the bullet

        // delete the bullet and enemy from respective vectors
        delete this->bullets[j];
        this->bullets.erase(bullets.begin() + j);

        // increase the score
        this->score++;
        // change the state of the enemy so no other bullets are checked against
        // it
        enemy2_deleted = true;
      }
    }

    // Run collision againt enemy and player for each enemy
    if (this->Enemies2[i].getShape().getGlobalBounds().intersects(
            this->player.shape.getGlobalBounds())) {
      // if true, player dies
      player.isAlive = false;
    }
  }
}
// the update function combines all previous updates to make it neater and
// also control the flow of updates ie what gets updated first
void Game::update() {
  this->player.update(this->window);
  this->spawnEnemies();
  this->EnemyMovement();
  this->updateInputs();
  this->updateEnemies();
  this->updateEnemies2();
  this->updateBullets();
  this->updateGUI();
}
// draw the score and if player is  dead draw the gameover
void Game::renderGUI(sf::RenderTarget* focus) {
  focus->draw(this->write);
  if (player.isAlive == false) {
    focus->draw(this->Gameover);
  }
}

// Game Render
void Game::render() {
  // clear the window of previous frame
  this->window->clear();
  // render player
  this->player.render(this->window);
  // render GUI
  this->renderGUI(this->window);
  // render bullets
  for (auto* i : this->bullets) {
    i->render(this->window);
  }
  // render enemies
  for (auto i : this->Enemies) {
    i.render(this->window);
  }
  for (auto i : this->Enemies2) {
    i.render(this->window);
  }
  // display render
  this->window->display();
}

// Enemy Spawn
// Enemies spawn a second apart fro one another
// There cannot be more enemies than 8
void Game::spawnEnemies() {
  // timer
  if (this->spawnTimer <= this->spawnTimerMax) {
    this->spawnTimer += 1.f;
  } else {
    if (Enemies.size() < maxEnemies) {
      this->Enemies.push_back(Enemy(*this->window));
      this->spawnTimer = 0.f;
    }
  }
  if (this->spawnTimer2 <= this->spawnTimer2Max) {
    this->spawnTimer2 += 1.f;
  } else {
    if (Enemies2.size() < maxEnemies2) {
      this->Enemies2.push_back(Enemy2(*this->window));
      this->spawnTimer2 = 0.f;
    }
  }
}
