#include "../../../Include/Engine/Input/Input.hpp"

#define kb sf::Keyboard
#define ms sf::Mouse

namespace eng{
	void Input::UpdateKeyboardButtonState(const InputCode _code,const sf::Keyboard::Key _key){
		InputState& i{inputStates[(int)_code]};

		bool held=false;
		if(kb::isKeyPressed(_key)){
			held=true;
			if(i.activeLastFrame){
				i.currentState=InputState::HELD;
			}
			else{
				i.currentState=InputState::PRESSED;
			}
		}
		else if(i.activeLastFrame){
			i.currentState=InputState::RELEASED;

		}

		i.activeLastFrame=held;
	}

	void Input::UpdateMouseButtonState(const InputCode _code,const sf::Mouse::Button _button){
		InputState& i{inputStates[(int)_code]};

		bool held=false;
		if(ms::isButtonPressed(_button)){
			held=true;
			if(i.activeLastFrame){
				i.currentState=InputState::HELD;
			}
			else{
				i.currentState=InputState::PRESSED;
			}
		}
		else if(i.activeLastFrame){
			i.currentState=InputState::RELEASED;

		}

		i.activeLastFrame=held;
	}

	void Input::UpdateMouseAxisState(){
		InputState& i{inputStates[(int)InputCode::MOUSE_AXIS_X]};
		// Get the mouse delta somehow?
	}

	Input::Input(){

	}

	Input::~Input(){

	}

	void Input::RegisterWindow(Window& _window){
		window=&_window;
	}

	bool Input::RegisterInput(const std::string& _inputName,const InputCode _code){
		for(int i=0; i<inputRegistry.size();i++){
			if(inputRegistry[i].first==_inputName){
				return false;
			}
		}
		inputRegistry.push_back(std::make_pair(_inputName,_code));
		return true;
	}

	void Input::Update(){
		UpdateKeyboardButtonState(InputCode::KEYBOARD_ALPHA_0,kb::Num0);
		UpdateKeyboardButtonState(InputCode::KEYBOARD_ALPHA_1,kb::Num1);
		UpdateKeyboardButtonState(InputCode::KEYBOARD_ALPHA_2,kb::Num2);
		UpdateKeyboardButtonState(InputCode::KEYBOARD_ALPHA_3,kb::Num3);
		UpdateKeyboardButtonState(InputCode::KEYBOARD_ALPHA_4,kb::Num4);
		UpdateKeyboardButtonState(InputCode::KEYBOARD_ALPHA_5,kb::Num5);
		UpdateKeyboardButtonState(InputCode::KEYBOARD_ALPHA_6,kb::Num6);
		UpdateKeyboardButtonState(InputCode::KEYBOARD_ALPHA_7,kb::Num7);
		UpdateKeyboardButtonState(InputCode::KEYBOARD_ALPHA_8,kb::Num8);
		UpdateKeyboardButtonState(InputCode::KEYBOARD_ALPHA_9,kb::Num9);
	}

	const InputCode Input::GetRawInput(){
		return InputCode();
	}
}
