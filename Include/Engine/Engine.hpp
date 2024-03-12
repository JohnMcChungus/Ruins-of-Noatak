#pragma once

#include <SFML/Graphics.hpp>

#include "Scene.hpp"
#include "Animation/AnimationManager.hpp"
#include "Time.hpp"
#include "Window.hpp"
#include "Input/Input.hpp"

namespace eng{
	class Engine{
		bool isRunning{true};

		sf::Event sfmlEvent{};

		std::vector<Scene*> sceneRegistry{};

		void HandleEvents();
		void Update();
		void Render();

	public:
		Engine();
		~Engine();

		Engine(const Engine& _other)=delete;
		void operator=(const Engine& _other)=delete;

		Time time{};
		Window window{};
		AnimationManager animationManager{};
		Input input{};

		void Quit();
		const bool IsRunning() const;

		void ProcessFrame();

		void RegisterScene(Scene* _scene);
		void SetScene(const std::string& _sceneName);
	};
}
