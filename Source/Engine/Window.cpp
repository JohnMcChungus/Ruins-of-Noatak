#include "../../Include/Engine/Window.hpp"

namespace eng{
	sf::RenderWindow& Window::GetWindow(){
		return sfmlWindow;
	}

	void Window::Create(const sf::Vector2i& _resolution,const std::string& _windowTitle,const sf::Uint32 _style){
		sfmlWindow.create(
			{static_cast<unsigned int>(_resolution.x),static_cast<unsigned int>(_resolution.y)},
			_windowTitle,
			_style);
	}

	void Window::SetIcon(std::shared_ptr<Resources::ResourceContainer<sf::Texture>> _textureResource){
		sf::Image iconImage{_textureResource->data.copyToImage()};
		sfmlWindow.setIcon(iconImage.getSize().x,iconImage.getSize().y,iconImage.getPixelsPtr());
	}

	void Window::SetVSync(const bool _state){
		sfmlWindow.setVerticalSyncEnabled(_state);
	}

	void Window::SetFrameRateLimit(const unsigned int _limit){
		sfmlWindow.setFramerateLimit(_limit);
	}

	const sf::Vector2u Window::GetSize() const{
		return sfmlWindow.getSize();
	}

	const sf::Vector2u Window::GetSizeHalf() const{
		return {GetSize().x/2,GetSize().y/2};
	}
}
