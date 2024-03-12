#pragma once

#include "AnimatableObject.hpp"
#include "AnimationData.hpp"
#include "AnimationEndAction.hpp"

namespace eng{
	class AnimationPlaybackInfo{
	public:
		AnimatableObject* object{nullptr};
		sf::FloatRect uvsPreAnimation{};
		AnimationData data{};
		float startTime{};
		AnimationEndAction endAction{};

		AnimationPlaybackInfo(AnimatableObject* _object,const AnimationData _data,const float _startTime,AnimationEndAction _endAction);
	};
}