#pragma once

namespace eng{
	class InputState{
	public:
		enum State{
			NONE,
			PRESSED,
			HELD,
			RELEASED
		};

		State currentState{NONE};
		bool activeLastFrame{false};
	};
}
