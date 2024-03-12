#include "../../../Include/Engine/Animation/AnimationManager.hpp"

namespace eng{
	void AnimationManager::SetFrame(AnimationPlaybackInfo& _info,int _frame){
		float
			left{(float)_info.data.startPosition.x*_info.data.textureSize+(_frame*_info.data.textureSize)},
			top{(float)_info.data.startPosition.y*_info.data.textureSize},
			width{(float)_info.data.textureSize},
			height{(float)_info.data.textureSize};

		_info.object->SetUVs({left,top,width,height});
	}

	AnimationManager::AnimationManager(){

	}

	AnimationManager::~AnimationManager(){

	}

	void AnimationManager::RegisterTime(Time& _time){
		time=&_time;
	}

	void AnimationManager::Update(){
		for(int i=0;i<animations.size();i++){
			auto& animationInfo{animations[i]};

			float frameDuration{1.0f/animationInfo.data.frameRate};
			float playbackStartTime{(float)(time->GetUptime()-animationInfo.startTime)};
			int numFramesPlayed{(int)(playbackStartTime/frameDuration)};

			if(numFramesPlayed>=animationInfo.data.numFrames){
				Stop(*animationInfo.object,animationInfo.endAction);

				if(animationInfo.endAction==AnimationEndAction::PAUSE){
					SetFrame(animationInfo,animationInfo.data.numFrames-1);
				}
			}
			else{
				SetFrame(animationInfo,numFramesPlayed);
			}
		}
	}

	void AnimationManager::Play(AnimatableObject& _object,const AnimationData& _data,const AnimationEndAction _endAction){
		AnimationPlaybackInfo newInfo{
			&_object,
			_data,
			(float)time->GetUptime(),
			_endAction};

		for(int i=0;i<animations.size();i++){
			if(animations[i].object==&_object){
				animations[i]=newInfo;
				return;
			}
		}

		animations.push_back(newInfo);
	}

	void AnimationManager::Stop(AnimatableObject& _object,const AnimationEndAction _endAction){
		for(int i=0;i<animations.size();i++){
			auto& a{animations[i]};

			if(a.object==&_object){
				switch(_endAction){
				case AnimationEndAction::RESET:
				{
					_object.SetUVs(a.uvsPreAnimation);
					break;
				}
				case AnimationEndAction::PAUSE:
				{
					break;
				}
				case AnimationEndAction::LOOP:
				{
					a.startTime=(float)time->GetUptime();
					return;
				}
				}

				animations.erase(animations.begin()+i);

				return;
			}
		}
	}
}
