#ifndef __MENU_H__
#define __MENU_H__
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <iostream>
// This class will be used to create a main menu page 
// This main menu window will be displayed before the game is played
// There will be a description of the controls
// There will be an escape option to close the window
// When the space button is hit the window will close and the game will start

#include "Game.hpp"

class Menu {
 private:
  // window
  sf::RenderWindow* window;
  sf::Event sfmlEvent;
  void initWindow(); //For the initialisation of the window
  sf::Font font; //Class for font 
  sf::Text write; //Class to write 
  void initFont(); // The loaded font
  void initWrite(); // What is written onto the page

 public:
  Menu(); //Constructor
  ~Menu(); //Destructor
  sf::RenderWindow* getWindow();
  void running(); //Function to run the menu window class
  void pollEvents(); // Function to update the events in the window
  void updateWrite(); //Function to update what has been written onto the menu window
  void renderGUI(sf::RenderTarget* focus);
  void render(); //Function to render the window 
};
#endif