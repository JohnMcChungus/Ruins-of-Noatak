#pragma once

#include "../../Engine/Scene.hpp"
#include "../../Engine/Rendering/ObjectPool.hpp"
#include "../../Engine/Animation/AnimationManager.hpp"
#include "../Terrain/TerrainChunk.hpp"
#include "../../Engine/Util/Math.hpp"
#include "../Game.hpp"

class SceneMainMenu:public eng::Scene{
public:
	SceneMainMenu(const std::string& _stateName);

	void OnInitialisation() override;
	void OnEnable() override;
	void OnDisable() override;
	void OnEvent(const sf::Event& _e) override;
	void OnInput(const eng::InputData& _input) override;
	void OnUpdate() override;
	void OnDraw(std::vector<sf::Drawable*>& _drawables) override;

	TerrainChunk chunk{};

	eng::AnimatableObject player{};
};
