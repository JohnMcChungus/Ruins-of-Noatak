#pragma once

#include <SFML/Graphics.hpp>

#include "Util/ResourceManager.hpp"

namespace eng{
	class Window{
		sf::RenderWindow sfmlWindow{};

	public:
		sf::RenderWindow& GetWindow();

		void Create(const sf::Vector2i& _resolution,const std::string& _windowTitle,const sf::Uint32 _style=sf::Style::Default);

		void SetIcon(std::shared_ptr<Resources::ResourceContainer<sf::Texture>> _textureResource);
		void SetVSync(const bool _state);
		void SetFrameRateLimit(const unsigned int _targetFPS);

		const sf::Vector2u GetSize() const;
		const sf::Vector2u GetSizeHalf() const;
	};
}
