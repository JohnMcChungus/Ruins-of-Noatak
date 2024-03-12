#pragma once

#include <SFML/Graphics.hpp>

namespace eng{
	class AnimationData{
	public:
		int
			numFrames{},
			textureSize{},
			frameRate{};

		sf::Vector2i startPosition{};

		AnimationData();
		AnimationData(int _numFrames,int _frameRate,int _textureSize,sf::Vector2i _startPosition);
	};
}
