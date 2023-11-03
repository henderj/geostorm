#pragma once

#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics/Rect.hpp>
#include "sprites.h"

namespace game
{
  sf::IntRect GetSpriteRectFromSheet(const sf::Vector2f &pos);
  sf::IntRect GetSpriteRectFromSheet(const SpriteTypes type);
  // SDL_Surface *CreateBlankSurface(int w, int h);
} // namespace game