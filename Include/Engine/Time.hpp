#pragma once

#include <chrono>

namespace eng{
	class Time{
		long long
			timeAtStart{},
			timeAtEndOfLastFrame{};

		long double ConvertMsToSec(long long _milliseconds);

	public:
		Time();
		~Time();

		Time(const Time& _other)=delete;
		void operator=(const Time& _other)=delete;

		void Update();

		long double GetUptime();
		long double GetCurrentSystemTime();
		long long GetCurrentSystemTimeMs();

		long double deltaTime{};
	};
}
