#include "../../Include/Engine/Engine.hpp"

namespace eng{
	Engine::Engine(){
		input.RegisterWindow(window);
		animationManager.RegisterTime(time);
	}

	Engine::~Engine(){

	}

	void Engine::Quit(){
		isRunning=false;
	}

	const bool Engine::IsRunning() const{
		return isRunning;
	}

	void Engine::ProcessFrame(){
		HandleEvents();
		Update();
		Render();
	}

	void Engine::HandleEvents(){
		if(isRunning){
			while(window.GetWindow().pollEvent(sfmlEvent)){
				for(int i=0;i<sceneRegistry.size();i++){
					auto& s{*sceneRegistry[i]};
					if(s.enabled){
						s.OnEvent(sfmlEvent);
					}
				}
				if(sfmlEvent.type==sf::Event::Closed){
					Quit();
				}
			}
		}
	}

	void Engine::Update(){
		if(isRunning){
			time.Update();
			animationManager.Update();

			for(int i=0;i<sceneRegistry.size();i++){
				auto& s{*sceneRegistry[i]};
				if(s.enabled){
					//s.OnInput();
					s.OnUpdate();
				}
			}
		}
	}

	void Engine::Render(){
		if(isRunning){
			window.GetWindow().clear(sf::Color::Black);
			for(int i=0; i<sceneRegistry.size(); i++){
				auto& s{*sceneRegistry[i]};
				if(s.enabled){
					std::vector<sf::Drawable*> drawables{};
					s.OnDraw(drawables);
					for(int drawIndex=0; drawIndex<drawables.size(); drawIndex++){
						window.GetWindow().draw(*drawables[drawIndex]);
					}
				}
			}
			window.GetWindow().display();
		}
	}

	void Engine::RegisterScene(Scene* _scene){
		sceneRegistry.push_back(_scene);
		sceneRegistry.back()->OnInitialisation();
	}

	void Engine::SetScene(const std::string& _sceneName){
		Scene* scene{nullptr};
		for(int i=0;i<sceneRegistry.size();i++){
			auto& s{*sceneRegistry[i]};
			if(s.name==_sceneName){
				scene=&s;
			}
			else if(s.enabled){
				s.enabled=false;
				s.OnDisable();
			}
		}

		if(scene){
			scene->enabled=true;
			scene->OnEnable();
		}
	}
}
