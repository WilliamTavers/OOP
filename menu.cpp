#include "Menu.hpp"
// description in header file

// The window for the game to be played
void Menu::initWindow() {
  this->window = new sf::RenderWindow(sf::VideoMode(1000, 1000), "OOP Project", // renders a window of the desired size for the menu page
                                      sf::Style::Close | sf::Style::Titlebar);
  this->window->setFramerateLimit(60); // sets a frame limit for the window
}

// The specific font used to display the score
void Menu::initFont() {
  if (!this->font.loadFromFile(
          "PixellettersFull.ttf")) {  // loading in the font from file
    std::cout << "ERROR::INITFONT::COULD NOT LOAD"
              << std::endl;  // Error message used for testing
  }
}

// The text for the main menu
// The text will be white from the font loaded in from font
void Menu::initWrite() {
  this->write.setFont(this->font);
  this->write.setFillColor(sf::Color::White); // sets the colour of the main menu
  this->write.setCharacterSize(100); // sets the character size of the main menu
  this->write.setString(
      "Controls:\nArrow Keys: Shoot\nWASD: Move\nESC: Quit\n\n\nPress Space to "
      "continue");
  this->write.setPosition(
      this->window->getSize().x / 2 - write.getGlobalBounds().width / 2, 0.f); // sets the position on the screen where the text will be
}

// constructor
Menu::Menu() {
  this->initWindow(); //Initialises the window
  this->initFont(); //Initialises the font
  this->initWrite(); //Initialises what is written
}
// destructor
Menu::~Menu() { delete this->window; }

sf::RenderWindow* Menu::getWindow() { return this->window; }

// Functions
// a void function for the menu when it is running
// opens a window and renders it
void Menu::running() {
  while (this->window->isOpen()) {
    this->pollEvents();
    this->render();
  }
}


// the poll of events for the menu
void Menu::pollEvents() { // runs the main menu window
  while (this->window->pollEvent(this->sfmlEvent)) {
    switch (this->sfmlEvent.type) {
      case sf::Event::Closed:
        this->window->close();
        break;
      case sf::Event::KeyPressed:
        if (this->sfmlEvent.key.code == sf::Keyboard::Escape) // will close the window when escape is pressed
          this->window->close(); //Closes the window
        if (this->sfmlEvent.key.code == sf::Keyboard::Space) // will start the game and close the main menu window
          this->window->close(); //Closes the window
        break;
      default:
        break;
    }
  }
}

// menu function used to render gui and write/draw the text
void Menu::renderGUI(sf::RenderTarget* focus) { focus->draw(this->write); }
void Menu::render() {
  this->window->clear(); // clears window
  this->renderGUI(this->window);
  this->window->display(); // displays window
}
