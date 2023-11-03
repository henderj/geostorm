// QCMs grid demo example for SFML & replit
#include <SFML/Graphics.hpp>
#include <chrono>  // For std::chrono
#include <cstdlib> // For rand() and srand()
#include <ctime>   // For time()
#include <fstream> // For std::ifstream
#include <iostream>
#include <thread> // For std::this_thread::sleep_for

#include "src/spritesheet.h"

void updateGrid(const int gridSize, sf::Color *gridColors);
void drawGrid(const int gridSize, const int cellSize, sf::Color *gridColors,
              sf::RenderWindow &window);

int main() {

  // Seed the random number generator
  std::srand(static_cast<unsigned int>(std::time(nullptr)));

  // Timer for updating colors
  std::chrono::time_point<std::chrono::system_clock> lastUpdateTime =
      std::chrono::system_clock::now();

  // Create the window
  sf::RenderWindow window(sf::VideoMode(400, 400), "Grid Game");

  // Load colored-transparent_packed.png into memory
  // sf::Texture spritesheetTexture;
  // if (!spritesheetTexture.loadFromFile("hello_world.bmp")) {
  //   std::cerr << "Failed to load texture" << std::endl;
  //   std::cout << sf::Texture::getMaximumSize() << std::endl;
  //   return 1;
  // }

  sf::ConvexShape triangle;
  triangle.setPointCount(3);
  triangle.setPoint(0, sf::Vector2f(0, 0));
  triangle.setPoint(1, sf::Vector2f(100, 0));
  triangle.setPoint(2, sf::Vector2f(50, 50));
  triangle.setFillColor(sf::Color::Red);
  triangle.setOutlineColor(sf::Color::Black);
  triangle.setOutlineThickness(5);
  triangle.setPosition(100, 100);

  sf::CircleShape circle;
  circle.setRadius(50);
  circle.setFillColor(sf::Color::Blue);
  circle.setOutlineColor(sf::Color::White);
  circle.setOutlineThickness(5);
  circle.setPosition(200, 200);


  sf::Clock clock;
  // Main Logic loop
  while (window.isOpen()) {
    // Process events
    sf::Event event;
    while (window.pollEvent(event)) {
      if (event.type == sf::Event::Closed)
        window.close();
    }

    float deltaTime = clock.restart().asSeconds();

    // updateGrid(gridSize, (sf::Color *)gridColors);

    // Clear the window
    window.clear();

    // drawGrid(gridSize, cellSize, (sf::Color *)gridColors, window);
    window.draw(triangle);
    window.draw(circle);
    // Display the window
    window.display();
  }

  return 0;
}

// extract the update grid logic to a separate function named updateGrid
void updateGrid(const int gridSize, sf::Color *gridColors) {
  // Update a random block with a random color
  int row = std::rand() % gridSize;
  int col = std::rand() % gridSize;
  sf::Uint8 red = std::rand() % 256;
  sf::Uint8 green = std::rand() % 256;
  sf::Uint8 blue = std::rand() % 256;
  gridColors[row * gridSize + col] = sf::Color(red, green, blue);
}

void drawGrid(const int gridSize, const int cellSize, sf::Color *gridColors,
              sf::RenderWindow &window) {
  for (int row = 0; row < gridSize; ++row) {
    for (int col = 0; col < gridSize; ++col) {
      // Create a rectangle shape for each grid cell
      sf::RectangleShape cell(sf::Vector2f(cellSize, cellSize));

      // Set the position of the cell based on the row and column
      cell.setPosition(col * cellSize, row * cellSize);

      // Set the color of the cell based on the random color
      cell.setFillColor(gridColors[row * gridSize + col]);

      // Draw the cell
      window.draw(cell);
    }
  }
}