#include "../../../Include/Game/Scenes/SceneLoading.hpp"

SceneLoading::SceneLoading(const std::string& _sceneName):
	Scene{_sceneName}
{
	
}

void SceneLoading::OnInitialisation(){
	Game::GetEngine().window.Create(
		{16*100,16*64},
		"Ruins of Noatak",
		sf::Style::Close);

	Game::GetEngine().window.SetVSync(true);
	Game::GetEngine().window.SetFrameRateLimit(120);

	Game::GetResourceManager().LoadTexture("terrain","Resources/Textures/Terrain.png").Print();
	Game::GetResourceManager().LoadTexture("entities","Resources/Textures/Entities.png").Print();
	Game::GetResourceManager().LoadTexture("app_icon_64","Resources/Textures/Icon64.png").Print();

	Game::GetResourceManager().LoadFont("gentium","Resources/Typefaces/GentiumBookBasic-Regular.ttf").Print();

	Game::GetResourceManager().DebugPrintResources();

	auto iconTexture{Game::GetResourceManager().GetTexture("app_icon_64")};
	iconTexture.Print();
	if(iconTexture.succeeded){
		Game::GetEngine().window.SetIcon(iconTexture.resource);
	}
}

void SceneLoading::OnEnable(){
	Game::GetEngine().SetScene("main_menu");
}

void SceneLoading::OnDisable(){

}

void SceneLoading::OnEvent(const sf::Event& _e){

}

void SceneLoading::OnInput(const eng::InputData& _input){

}

void SceneLoading::OnUpdate(){

}

void SceneLoading::OnDraw(std::vector<sf::Drawable*>& _drawables){

}
