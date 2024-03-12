#include "../../../Include/Game/Scenes/SceneMainMenu.hpp"

SceneMainMenu::SceneMainMenu(const std::string& _stateName):
	Scene{_stateName}
{

}

void SceneMainMenu::OnInitialisation(){
	sf::View v{Game::GetEngine().window.GetWindow().getView()};
	v.zoom(0.25f);
	v.setCenter({128,128});
	Game::GetEngine().window.GetWindow().setView(v);

	auto chunkTexture{Game::GetResourceManager().GetTexture("terrain")};
	chunkTexture.Print();
	if(chunkTexture.succeeded){
		chunk.SetTexture(chunkTexture.resource);

		for(int y=1;y<TERRAIN_CHUNK_SIZE-1;y++){
			for(int x=1;x<TERRAIN_CHUNK_SIZE-1;x++){
				TerrainType terrainType{(TerrainType)eng::Math::RandomRange(0,(int)TerrainType::END_OF_ENUM)};
				chunk.tiles[x][y].type=terrainType;
			}
		}

		chunk.UpdateSubTiles();
	}

	auto playerTexture{Game::GetResourceManager().GetTexture("entities")};
	playerTexture.Print();
	if(playerTexture.succeeded){
		player.SetTexture(playerTexture.resource);
	}

	player.SetSize({16,16});
	player.SetPosition({32,32});
	player.SetUVs({16,0,16,16});

	Game::GetResourceManager().DebugPrintResources();
}

void SceneMainMenu::OnEnable(){

}

void SceneMainMenu::OnDisable(){

}

void SceneMainMenu::OnEvent(const sf::Event& _e){
	if(_e.type==sf::Event::KeyPressed){
		if(_e.key.code==sf::Keyboard::W){
			player.MovePosition({0,-16});
		}
		else if(_e.key.code==sf::Keyboard::S){
			player.MovePosition({0,16});
		}
		else if(_e.key.code==sf::Keyboard::A){
			player.MovePosition({-16,0});
		}
		else if(_e.key.code==sf::Keyboard::D){
			player.MovePosition({16,0});
		}
	}
}

void SceneMainMenu::OnInput(const eng::InputData& _input){
	//if(_input.state==eng::InputState::HELD&&
	//   _input.code==eng::InputCode::MOUSE_AXIS_X){
	//	player.MovePosition({_input.value,0});
	//}
}

void SceneMainMenu::OnUpdate(){
	sf::View v{Game::GetEngine().window.GetWindow().getView()};
	v.setCenter(player.GetPosition()+sf::Vector2f{8,8});
	Game::GetEngine().window.GetWindow().setView(v);
}

void SceneMainMenu::OnDraw(std::vector<sf::Drawable*>& _drawables){
	_drawables.push_back(&chunk);
	_drawables.push_back(&player);
}
