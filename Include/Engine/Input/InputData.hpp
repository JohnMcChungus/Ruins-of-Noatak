#pragma once

#include <string>

#include "InputCode.hpp"
#include "InputState.hpp"

namespace eng{
	struct InputData{
		std::string name{""};
		InputCode code{InputCode::_NONE};
		InputState::State state{InputState::NONE};
		float value{0.0f};
	};
}
