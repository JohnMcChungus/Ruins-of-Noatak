#pragma once

#include <SFML/Graphics.hpp>
#include <string>
#include <vector>
#include <array>

#include "InputData.hpp"
#include "../Window.hpp"

namespace eng{
	class Input{
		Window* window{nullptr};

		std::vector<std::pair<std::string,InputCode>> inputRegistry{};
		std::array<InputState,(int)InputCode::_ENUM_SIZE-1> inputStates{};

		void UpdateKeyboardButtonState(const InputCode _code,const sf::Keyboard::Key _key);
		void UpdateMouseButtonState(const InputCode _code,const sf::Mouse::Button _button);
		void UpdateMouseAxisState();

	public:
		Input();
		~Input();

		Input(const Input& _other)=delete;
		void operator=(const Input& _other)=delete;

		void RegisterWindow(Window& _window);

		bool RegisterInput(const std::string& _inputName,const InputCode _code);
		void Update();

		const InputCode GetRawInput();
	};
}
