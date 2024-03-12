#include "../../Include/Engine/Time.hpp"

namespace eng{
	long long Time::GetCurrentSystemTimeMs(){
		auto timeSinceEpoch{std::chrono::system_clock().now().time_since_epoch()};
		return std::chrono::duration_cast<std::chrono::milliseconds>(timeSinceEpoch).count();
	}

	long double Time::ConvertMsToSec(long long _milliseconds){
		return (long double)_milliseconds/1000.0f;
	}

	Time::Time():
		timeAtStart{GetCurrentSystemTimeMs()},
		timeAtEndOfLastFrame{GetCurrentSystemTimeMs()}{

	}

	Time::~Time(){

	}

	void Time::Update(){
		deltaTime=ConvertMsToSec(GetCurrentSystemTimeMs()-timeAtEndOfLastFrame);
		timeAtEndOfLastFrame=GetCurrentSystemTimeMs();
	}

	long double Time::GetCurrentSystemTime(){
		return ConvertMsToSec(GetCurrentSystemTimeMs());
	}

	long double Time::GetUptime(){
		return ConvertMsToSec(GetCurrentSystemTimeMs()-timeAtStart);
	}
}
