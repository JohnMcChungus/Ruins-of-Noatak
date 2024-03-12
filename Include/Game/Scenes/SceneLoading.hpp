#pragma once

#include "../../Engine/Scene.hpp"
#include "../../Engine/Engine.hpp"
#include "../../Engine/Util/ResourceManager.hpp"
#include "../Game.hpp"

class SceneLoading:public eng::Scene{
public:
	SceneLoading(const std::string& _stateName);

	void OnInitialisation() override;
	void OnEnable() override;
	void OnDisable() override;
	void OnEvent(const sf::Event& _e) override;
	void OnInput(const eng::InputData& _input) override;
	void OnUpdate() override;
	void OnDraw(std::vector<sf::Drawable*>& _drawables) override;
};
