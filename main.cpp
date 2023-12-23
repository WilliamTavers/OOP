
#include "Game.hpp"
#include "menu.hpp"
int main() {
  // Initialize random seed
  srand(static_cast<unsigned>(time(0)));
  Menu mainMenu;
  mainMenu.running();

  while (mainMenu.getWindow()->isOpen()) {
    mainMenu.render();
  }
  // Initialize game object
  Game game;
  game.running();
  while (game.getWindow()->isOpen()) {
    game.update();
    game.render();
  }
  return 0;
}
