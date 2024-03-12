#include "../../../Include/Game/Terrain/TerrainTile.hpp"

TerrainTile::TerrainTile(){

}

void TerrainTile::SetPosition(const sf::Vector2f _position){
	for(int i=0;i<TERRAIN_SUB_TILE_COUNT;i++){
		subTiles[i]->SetPosition(_position);

		switch((SubTileIndex)i){
		case SubTileIndex::TOP_RIGHT:
			subTiles[i]->MovePosition({TERRAIN_SUB_TILE_SIZE,0});
			break;
		case SubTileIndex::BOTTOM_RIGHT:
			subTiles[i]->MovePosition({TERRAIN_SUB_TILE_SIZE,TERRAIN_SUB_TILE_SIZE});
			break;
		case SubTileIndex::BOTTOM_LEFT:
			subTiles[i]->MovePosition({0,TERRAIN_SUB_TILE_SIZE});
			break;
		}
	}
}
