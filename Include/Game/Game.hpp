#pragma once

#include "../Engine/Engine.hpp"

class Game{
	static std::unique_ptr<eng::Engine> engine;
	static std::unique_ptr<eng::Resources::ResourceManager> resourceManager;

public:
	Game()=delete;
	~Game()=delete;
	Game(const Game& _other)=delete;
	void operator=(const Game& _other)=delete;

	static eng::Engine& GetEngine();
	static eng::Resources::ResourceManager& GetResourceManager();
};
