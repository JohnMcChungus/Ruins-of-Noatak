#include "../../../Include/Engine/Animation/AnimationData.hpp"

namespace eng{
	AnimationData::AnimationData(){

	}

	AnimationData::AnimationData(int _numFrames,int _frameRate,int _textureSize,sf::Vector2i _startPosition):
		numFrames{_numFrames},
		frameRate{_frameRate},
		textureSize{_textureSize},
		startPosition{_startPosition}{

	}
}
