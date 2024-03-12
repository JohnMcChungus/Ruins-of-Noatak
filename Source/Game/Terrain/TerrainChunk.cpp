#include "../../../Include/Game/Terrain/TerrainChunk.hpp"

void TerrainChunk::draw(sf::RenderTarget& _target,sf::RenderStates _states) const{
	_states.texture=&subTiles.GetTexture()->data;
	_target.draw(subTiles,_states);
}

TerrainChunk::TerrainChunk():
	subTiles{TERRAIN_CHUNK_SUB_TILE_COUNT},
	tiles{std::array<TerrainTile,TERRAIN_CHUNK_SIZE>{}}{
	for(int i=0;i<subTiles.GetObjects().size();i++){
		auto& o{subTiles.GetObjects()[i]};
		o.SetSize({TERRAIN_SUB_TILE_SIZE,TERRAIN_SUB_TILE_SIZE});
	}

	for(int i=0;i<subTiles.GetObjects().size();i+=TERRAIN_SUB_TILE_COUNT){
		sf::Vector2i pos{
			(i/TERRAIN_SUB_TILE_COUNT)%TERRAIN_CHUNK_SIZE,
			(i/TERRAIN_SUB_TILE_COUNT)/TERRAIN_CHUNK_SIZE,
		};

		{
			auto& thisSubTile{subTiles.GetObjects()[(size_t)(i+(int)SubTileIndex::TOP_LEFT)]};
			tiles[pos.x][pos.y].subTiles[(int)SubTileIndex::TOP_LEFT]=&thisSubTile;
		}
		{
			auto& thisSubTile{subTiles.GetObjects()[(size_t)(i+(int)SubTileIndex::TOP_RIGHT)]};
			tiles[pos.x][pos.y].subTiles[(int)SubTileIndex::TOP_RIGHT]=&thisSubTile;
		}
		{
			auto& thisSubTile{subTiles.GetObjects()[(size_t)(i+(int)SubTileIndex::BOTTOM_RIGHT)]};
			tiles[pos.x][pos.y].subTiles[(int)SubTileIndex::BOTTOM_RIGHT]=&thisSubTile;
		}
		{
			auto& thisSubTile{subTiles.GetObjects()[(size_t)(i+(int)SubTileIndex::BOTTOM_LEFT)]};
			tiles[pos.x][pos.y].subTiles[(int)SubTileIndex::BOTTOM_LEFT]=&thisSubTile;
		}
	}

	for(int y=0;y<TERRAIN_CHUNK_SIZE;y++){
		for(int x=0;x<TERRAIN_CHUNK_SIZE;x++){
			tiles[x][y].SetPosition({(float)x*TERRAIN_TILE_SIZE,(float)y*TERRAIN_TILE_SIZE});

			tiles[x][y].subTiles[(int)SubTileIndex::TOP_LEFT]->SetUVs(GetAirUVs());
			tiles[x][y].subTiles[(int)SubTileIndex::TOP_RIGHT]->SetUVs(GetAirUVs());
			tiles[x][y].subTiles[(int)SubTileIndex::BOTTOM_RIGHT]->SetUVs(GetAirUVs());
			tiles[x][y].subTiles[(int)SubTileIndex::BOTTOM_LEFT]->SetUVs(GetAirUVs());

			tiles[x][y].subTiles[(int)SubTileIndex::TOP_LEFT]->ResizeToUVs();
			tiles[x][y].subTiles[(int)SubTileIndex::TOP_RIGHT]->ResizeToUVs();
			tiles[x][y].subTiles[(int)SubTileIndex::BOTTOM_RIGHT]->ResizeToUVs();
			tiles[x][y].subTiles[(int)SubTileIndex::BOTTOM_LEFT]->ResizeToUVs();
		}
	}
}

sf::FloatRect TerrainChunk::EvaluateUVs(const sf::Vector2i _textureIndex,const SubTileIndex _subTile){
	sf::FloatRect uvs{
		(float)_textureIndex.x*TERRAIN_TILE_SIZE,
		(float)_textureIndex.y*TERRAIN_TILE_SIZE,
		(float)TERRAIN_SUB_TILE_SIZE,
		(float)TERRAIN_SUB_TILE_SIZE
	};

	switch(_subTile){
	case SubTileIndex::TOP_LEFT:
		break;
	case SubTileIndex::TOP_RIGHT:
		uvs.left+=TERRAIN_SUB_TILE_SIZE;
		break;
	case SubTileIndex::BOTTOM_RIGHT:
		uvs.left+=TERRAIN_SUB_TILE_SIZE;
		uvs.top+=TERRAIN_SUB_TILE_SIZE;
		break;
	case SubTileIndex::BOTTOM_LEFT:
		uvs.top+=TERRAIN_SUB_TILE_SIZE;
		break;
	}

	return uvs;
}

sf::FloatRect TerrainChunk::GetAirUVs(){
	return{0,0,TERRAIN_TILE_SIZE,TERRAIN_TILE_SIZE};
}

eng::ObjectPool& TerrainChunk::GetObjectPool(){
	return subTiles;
}

void TerrainChunk::SetTexture(TextureResource _textureResource){
	subTiles.SetTexture(_textureResource);
}

void TerrainChunk::UpdateSubTiles(){
	for(int y=0;y<TERRAIN_CHUNK_SIZE;y++){
		for(int x=0;x<TERRAIN_CHUNK_SIZE;x++){
			auto& thisTile{tiles[x][y]};
			if(thisTile.type==TerrainType::AIR){
				for(int i=0;i<TERRAIN_SUB_TILE_COUNT;i++){
					thisTile.subTiles[i]->SetUVs(GetAirUVs());
				}
				continue;
			}

			int baseYIndex{
				((int)thisTile.type-1<0?
				0:(int)thisTile.type-1)
				*2+1
			};

			sf::FloatRect uvs[TERRAIN_SUB_TILE_COUNT]{};

			if(thisTile.type==tiles[x][(size_t)eng::Math::Clamp(y-1,0,TERRAIN_CHUNK_SIZE-1)].type){
				if(thisTile.type==tiles[(size_t)eng::Math::Clamp(x-1,0,TERRAIN_CHUNK_SIZE-1)][y].type){
					uvs[(int)SubTileIndex::TOP_LEFT]=EvaluateUVs({0,baseYIndex},SubTileIndex::TOP_LEFT);
				}
				else{
					uvs[(int)SubTileIndex::TOP_LEFT]=EvaluateUVs({1,baseYIndex},SubTileIndex::TOP_LEFT);
				}
			}
			else{
				if(thisTile.type==tiles[(size_t)eng::Math::Clamp(x-1,0,TERRAIN_CHUNK_SIZE-1)][y].type){
					uvs[(int)SubTileIndex::TOP_LEFT]=EvaluateUVs({4,baseYIndex},SubTileIndex::TOP_LEFT);
				}
				else{
					uvs[(int)SubTileIndex::TOP_LEFT]=EvaluateUVs({3,baseYIndex},SubTileIndex::TOP_LEFT);
				}
			}

			if(thisTile.type==tiles[x][(size_t)eng::Math::Clamp(y-1,0,TERRAIN_CHUNK_SIZE-1)].type){
				if(thisTile.type==tiles[(size_t)eng::Math::Clamp(x+1,0,TERRAIN_CHUNK_SIZE-1)][y].type){
					uvs[(int)SubTileIndex::TOP_RIGHT]=EvaluateUVs({0,baseYIndex},SubTileIndex::TOP_RIGHT);
				}
				else{
					uvs[(int)SubTileIndex::TOP_RIGHT]=EvaluateUVs({1,baseYIndex},SubTileIndex::TOP_RIGHT);
				}
			}
			else{
				if(thisTile.type==tiles[(size_t)eng::Math::Clamp(x+1,0,TERRAIN_CHUNK_SIZE-1)][y].type){
					uvs[(int)SubTileIndex::TOP_RIGHT]=EvaluateUVs({4,baseYIndex},SubTileIndex::TOP_RIGHT);
				}
				else{
					uvs[(int)SubTileIndex::TOP_RIGHT]=EvaluateUVs({3,baseYIndex},SubTileIndex::TOP_RIGHT);
				}
			}

			if(thisTile.type==tiles[x][(size_t)eng::Math::Clamp(y+1,0,TERRAIN_CHUNK_SIZE-1)].type){
				if(thisTile.type==tiles[(size_t)eng::Math::Clamp(x+1,0,TERRAIN_CHUNK_SIZE-1)][y].type){
					if(thisTile.type==tiles[(size_t)eng::Math::Clamp(x+1,0,TERRAIN_CHUNK_SIZE-1)][(size_t)eng::Math::Clamp(y+1,0,TERRAIN_CHUNK_SIZE-1)].type||
					   tiles[(size_t)eng::Math::Clamp(x+1,0,TERRAIN_CHUNK_SIZE-1)][(size_t)eng::Math::Clamp(y+1,0,TERRAIN_CHUNK_SIZE-1)].type!=TerrainType::AIR){
						uvs[(int)SubTileIndex::BOTTOM_RIGHT]=EvaluateUVs({0,baseYIndex},SubTileIndex::BOTTOM_RIGHT);
					}
					else{
						uvs[(int)SubTileIndex::BOTTOM_RIGHT]=EvaluateUVs({2,baseYIndex},SubTileIndex::BOTTOM_RIGHT);
					}
				}
				else{
					uvs[(int)SubTileIndex::BOTTOM_RIGHT]=EvaluateUVs({1,baseYIndex},SubTileIndex::BOTTOM_RIGHT);
				}
			}
			else if (tiles[x][(size_t)eng::Math::Clamp(y+1,0,TERRAIN_CHUNK_SIZE-1)].type==TerrainType::AIR){
				if(thisTile.type==tiles[(size_t)eng::Math::Clamp(x+1,0,TERRAIN_CHUNK_SIZE-1)][y].type){
					uvs[(int)SubTileIndex::BOTTOM_RIGHT]=EvaluateUVs({4,baseYIndex},SubTileIndex::BOTTOM_RIGHT);
				}
				else{
					uvs[(int)SubTileIndex::BOTTOM_RIGHT]=EvaluateUVs({3,baseYIndex},SubTileIndex::BOTTOM_RIGHT);
				}
			}
			else{
				if(thisTile.type==tiles[(size_t)eng::Math::Clamp(x+1,0,TERRAIN_CHUNK_SIZE-1)][y].type){
					if(thisTile.type==tiles[(size_t)eng::Math::Clamp(x+1,0,TERRAIN_CHUNK_SIZE-1)][(size_t)eng::Math::Clamp(y+1,0,TERRAIN_CHUNK_SIZE-1)].type||
					   tiles[(size_t)eng::Math::Clamp(x+1,0,TERRAIN_CHUNK_SIZE-1)][(size_t)eng::Math::Clamp(y+1,0,TERRAIN_CHUNK_SIZE-1)].type!=TerrainType::AIR){
						uvs[(int)SubTileIndex::BOTTOM_RIGHT]=EvaluateUVs({0,baseYIndex+1},SubTileIndex::BOTTOM_RIGHT);
					}
					else{
						uvs[(int)SubTileIndex::BOTTOM_RIGHT]=EvaluateUVs({2,baseYIndex+1},SubTileIndex::BOTTOM_RIGHT);
					}
				}
				else{
					uvs[(int)SubTileIndex::BOTTOM_RIGHT]=EvaluateUVs({1,baseYIndex+1},SubTileIndex::BOTTOM_RIGHT);
				}
			}

			if(thisTile.type==tiles[x][(size_t)eng::Math::Clamp(y+1,0,TERRAIN_CHUNK_SIZE-1)].type){
				if(thisTile.type==tiles[(size_t)eng::Math::Clamp(x-1,0,TERRAIN_CHUNK_SIZE-1)][y].type){
					if(thisTile.type==tiles[(size_t)eng::Math::Clamp(x-1,0,TERRAIN_CHUNK_SIZE-1)][(size_t)eng::Math::Clamp(y+1,0,TERRAIN_CHUNK_SIZE-1)].type||
					   tiles[(size_t)eng::Math::Clamp(x-1,0,TERRAIN_CHUNK_SIZE-1)][(size_t)eng::Math::Clamp(y+1,0,TERRAIN_CHUNK_SIZE-1)].type!=TerrainType::AIR){
						uvs[(int)SubTileIndex::BOTTOM_LEFT]=EvaluateUVs({0,baseYIndex},SubTileIndex::BOTTOM_LEFT);
					}
					else{
						uvs[(int)SubTileIndex::BOTTOM_LEFT]=EvaluateUVs({2,baseYIndex},SubTileIndex::BOTTOM_LEFT);
					}
				}
				else{
					uvs[(int)SubTileIndex::BOTTOM_LEFT]=EvaluateUVs({1,baseYIndex},SubTileIndex::BOTTOM_LEFT);
				}
			}
			else if (tiles[x][(size_t)eng::Math::Clamp(y+1,0,TERRAIN_CHUNK_SIZE-1)].type==TerrainType::AIR){
				if(thisTile.type==tiles[(size_t)eng::Math::Clamp(x-1,0,TERRAIN_CHUNK_SIZE-1)][y].type){
					uvs[(int)SubTileIndex::BOTTOM_LEFT]=EvaluateUVs({4,baseYIndex},SubTileIndex::BOTTOM_LEFT);
				}
				else{
					uvs[(int)SubTileIndex::BOTTOM_LEFT]=EvaluateUVs({3,baseYIndex},SubTileIndex::BOTTOM_LEFT);
				}
			}
			else{
				if(thisTile.type==tiles[(size_t)eng::Math::Clamp(x-1,0,TERRAIN_CHUNK_SIZE-1)][y].type){
					if(thisTile.type==tiles[(size_t)eng::Math::Clamp(x-1,0,TERRAIN_CHUNK_SIZE-1)][(size_t)eng::Math::Clamp(y+1,0,TERRAIN_CHUNK_SIZE-1)].type||
					   tiles[(size_t)eng::Math::Clamp(x-1,0,TERRAIN_CHUNK_SIZE-1)][(size_t)eng::Math::Clamp(y+1,0,TERRAIN_CHUNK_SIZE-1)].type!=TerrainType::AIR){
						uvs[(int)SubTileIndex::BOTTOM_LEFT]=EvaluateUVs({0,baseYIndex+1},SubTileIndex::BOTTOM_LEFT);
					}
					else{
						uvs[(int)SubTileIndex::BOTTOM_LEFT]=EvaluateUVs({2,baseYIndex+1},SubTileIndex::BOTTOM_LEFT);
					}
				}
				else{
					uvs[(int)SubTileIndex::BOTTOM_LEFT]=EvaluateUVs({1,baseYIndex+1},SubTileIndex::BOTTOM_LEFT);
				}
			}

			for(int i=0;i<TERRAIN_SUB_TILE_COUNT;i++){
				thisTile.subTiles[i]->SetUVs(uvs[i]);
			}
		}
	}
}
