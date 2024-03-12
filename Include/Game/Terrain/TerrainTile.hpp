#pragma once

#include <array>

#include "../../Engine/Animation/AnimatableObject.hpp"
#include "SubTileIndex.hpp"
#include "ConstTerrainData.hpp"
#include "TerrainType.hpp"

class TerrainTile{

public:
	std::array<eng::AnimatableObject*,TERRAIN_SUB_TILE_COUNT> subTiles{};
	TerrainType type{TerrainType::AIR};

	TerrainTile();

	void SetPosition(const sf::Vector2f _position);
};
