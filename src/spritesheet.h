#pragma once

#include <SFML/Graphics/Rect.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/System/Vector2.hpp>

namespace game {
class Spritesheet {
private:
  sf::Texture &_sheet;
  int _spriteWidth;
  int _spriteHeight;
  int _spritesPerRow;

public:
  Spritesheet(sf::Texture &sheet, int spriteWidth, int spriteHeight,
              int spritesPerRow)
      : _sheet(sheet), _spriteWidth(spriteWidth), _spriteHeight(spriteHeight),
        _spritesPerRow(spritesPerRow){};
  ~Spritesheet(){};

  sf::IntRect getRectForSpriteAt(int row, int col);
  sf::IntRect getRectForSpriteAt(int index);
  sf::Sprite getNewSpriteAt(int row, int col);
  sf::Sprite getNewSpriteAt(int index);
};
} // namespace game