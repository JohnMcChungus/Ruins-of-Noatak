#include "../../Include/Game/Game.hpp"

#include "../../Include/Game/Scenes/SceneLoading.hpp"
#include "../../Include/Game/Scenes/SceneMainMenu.hpp"

int main(){
	Game::GetEngine().RegisterScene(new SceneLoading{"loading"});
	Game::GetEngine().RegisterScene(new SceneMainMenu{"main_menu"});

	Game::GetEngine().SetScene("loading");

	while(Game::GetEngine().IsRunning()){
		Game::GetEngine().ProcessFrame();
	}

	return 0;
}