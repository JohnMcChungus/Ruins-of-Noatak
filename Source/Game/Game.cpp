#include "../../Include/Game/Game.hpp"

std::unique_ptr<eng::Engine> Game::engine{new eng::Engine{}};
std::unique_ptr<eng::Resources::ResourceManager> Game::resourceManager{new eng::Resources::ResourceManager{}};

eng::Engine& Game::GetEngine(){
	return *engine;
}

eng::Resources::ResourceManager& Game::GetResourceManager(){
	return *resourceManager;
}
