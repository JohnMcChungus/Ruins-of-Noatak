#include "../../../Include/Engine/Animation/AnimationPlaybackInfo.hpp"

namespace eng{
	AnimationPlaybackInfo::AnimationPlaybackInfo(AnimatableObject* _object,const AnimationData _data,const float _startTime,AnimationEndAction _endAction):
		object{_object},
		data{_data},
		startTime{_startTime},
		uvsPreAnimation{_object->GetUVs()},
		endAction{_endAction}
	{

	}
}