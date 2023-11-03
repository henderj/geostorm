#include "spritesheet.h"

#include <SFML/Graphics/Rect.hpp>
#include <SFML/Graphics/Sprite.hpp>

namespace game {
sf::IntRect Spritesheet::getRectForSpriteAt(int row, int col) {
  return sf::IntRect(col * _spriteWidth, row * _spriteHeight, _spriteWidth,
                     _spriteHeight);
}

sf::IntRect Spritesheet::getRectForSpriteAt(int index) {
  return getRectForSpriteAt(index / _spritesPerRow, index % _spritesPerRow);
}

sf::Sprite Spritesheet::getNewSpriteAt(int row, int col) {
  sf::Sprite sprite;
  sprite.setTexture(_sheet);
  sprite.setTextureRect(getRectForSpriteAt(row, col));
  return sprite;
}

sf::Sprite Spritesheet::getNewSpriteAt(int index) {
  return getNewSpriteAt(index / _spritesPerRow, index % _spritesPerRow);
}
} // namespace game