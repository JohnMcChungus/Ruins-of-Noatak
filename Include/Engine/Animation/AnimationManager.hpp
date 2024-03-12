#pragma once

#include <SFML/Graphics.hpp>
#include <array>
#include <vector>

#include "AnimatableObject.hpp"
#include "AnimationData.hpp"
#include "AnimationEndAction.hpp"
#include "AnimationPlaybackInfo.hpp"
#include "../Time.hpp"

namespace eng{
	class AnimationManager{
		std::vector<AnimationPlaybackInfo> animations{};

		void SetFrame(AnimationPlaybackInfo& _info,int _frame);

		Time* time{nullptr};

	public:
		AnimationManager();
		~AnimationManager();

		AnimationManager(const AnimationManager& _other)=delete;
		void operator=(const AnimationManager& _other)=delete;

		void RegisterTime(Time& _time);

		void Update();

		void Play(AnimatableObject& _object,const AnimationData& _data,const AnimationEndAction _endAction=AnimationEndAction::RESET);
		void Stop(AnimatableObject& _object,const AnimationEndAction _endAction=AnimationEndAction::RESET);
	};
}
