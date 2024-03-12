#pragma once

#include "../../Engine/Rendering/ObjectPool.hpp"
#include "TerrainTile.hpp"
#include "ConstTerrainData.hpp"
#include "../../Engine/Util/Math.hpp"

class TerrainChunk:public sf::Drawable{
	eng::ObjectPool subTiles;

	static sf::FloatRect EvaluateUVs(const sf::Vector2i _textureIndex,const SubTileIndex _subTile);
	static sf::FloatRect GetAirUVs();

	void draw(sf::RenderTarget& _target,sf::RenderStates _states)const override;

public:
	TerrainChunk();

	std::array<std::array<TerrainTile,TERRAIN_CHUNK_SIZE>,TERRAIN_CHUNK_SIZE> tiles;

	void SetTexture(TextureResource _textureResource);
	void UpdateSubTiles();

	eng::ObjectPool& GetObjectPool();
};