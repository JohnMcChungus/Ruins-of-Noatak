#pragma once

#include <SFML/Graphics.hpp>
#include <string>
#include <vector>

#include "Input/InputData.hpp"

namespace eng{
	class Scene{
	public:
		std::string name="";
		bool enabled=false;

		Scene(const std::string& _stateName);
		~Scene();

		Scene(const Scene& _other)=delete;
		void operator=(const Scene& _other)=delete;

		virtual void OnInitialisation()=0;
		virtual void OnEnable()=0;
		virtual void OnDisable()=0;
		virtual void OnEvent(const sf::Event& _e)=0;
		virtual void OnInput(const InputData& _input)=0;
		virtual void OnUpdate()=0;
		virtual void OnDraw(std::vector<sf::Drawable*>& _drawables)=0;
	};
}
