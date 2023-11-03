#pragma once

#include <SFML/System/Vector2.hpp>
#include "sprites.h"

namespace game
{
    struct SpriteRenderData
    {
        sf::Vector2f pos;
        SpriteTypes type;

        SpriteRenderData(sf::Vector2f pos, SpriteTypes type) : pos(pos), type(type) {}
    };

} // namespace game
