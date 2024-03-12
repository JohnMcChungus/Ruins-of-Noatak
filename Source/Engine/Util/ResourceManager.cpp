#include "../../../Include/Engine/Util/ResourceManager.hpp"

namespace eng{
	namespace Resources{
		const std::string ResourceManager::RES_SUCCESS_LOAD{"Resource loaded successfully."};
		const std::string ResourceManager::RES_SUCCESS_GET{"Resource found."};

		const std::string ResourceManager::RES_ERROR_LOAD_NAME_ALREADY_LOADED{"Provided name is already loaded."};
		const std::string ResourceManager::RES_ERROR_LOAD_INVALID_PATH{"Provided path is invalid."};

		const std::string ResourceManager::RES_ERROR_GET_NO_RESOURCES_OF_TYPE{"There are no resources of the same type loaded."};
		const std::string ResourceManager::RES_ERROR_GET_DOES_NOT_EXIST{"Resource with that name does not exist."};

		ResourceResult<sf::Texture> ResourceManager::LoadTexture(const std::string& _name,const std::string& _path){
			for(int i=0;i<textures.size();i++){
				if(textures[i]->name==_name){
					ResourceResult<sf::Texture> result{
						false,
						RES_ERROR_LOAD_NAME_ALREADY_LOADED,
						textures[i]
					};
					return result;
				}
			}

			auto newTexture{ResourceContainer<sf::Texture>(_name)};
			textures.push_back(std::make_shared<ResourceContainer<sf::Texture>>(newTexture));

			if(!textures.back()->data.loadFromFile(_path)){
				textures.erase(textures.begin()+(textures.size()-1));
				ResourceResult<sf::Texture> result{
					false,
					RES_ERROR_LOAD_INVALID_PATH
				};
				return result;
			}

			ResourceResult<sf::Texture> result{
				true,
				RES_SUCCESS_LOAD,
				textures.back()
			};
			return result;
		}
		ResourceResult<sf::Texture> ResourceManager::GetTexture(const std::string& _name){
			if(textures.size()==0){
				auto emptyResource=ResourceContainer<sf::Texture>(_name);
				ResourceResult<sf::Texture> result{
					false,
					RES_ERROR_GET_NO_RESOURCES_OF_TYPE,
				std::make_shared<ResourceContainer<sf::Texture>>(emptyResource)
				};
				return result;
			}

			for(int i=0;i<textures.size();i++){
				if(textures[i]->name==_name){
					ResourceResult<sf::Texture> result{
						true,
						RES_SUCCESS_GET,
						textures[i]
					};
					return result;
				}
			}

			auto emptyResource=ResourceContainer<sf::Texture>(_name);
			ResourceResult<sf::Texture> result{
				false,
				RES_ERROR_GET_DOES_NOT_EXIST,
				std::make_shared<ResourceContainer<sf::Texture>>(emptyResource)
			};
			return result;
		}

		ResourceResult<sf::Font> ResourceManager::LoadFont(const std::string& _name,const std::string& _path){
			for(int i=0;i<fonts.size();i++){
				if(fonts[i]->name==_name){
					ResourceResult<sf::Font> result{
						false,
						RES_ERROR_LOAD_NAME_ALREADY_LOADED,
						fonts[i]
					};
					return result;
				}
			}

			auto newFont{ResourceContainer<sf::Font>(_name)};
			fonts.push_back(std::make_shared<ResourceContainer<sf::Font>>(newFont));

			if(!fonts.back()->data.loadFromFile(_path)){
				fonts.erase(fonts.begin()+(fonts.size()-1));
				ResourceResult<sf::Font> result{
					false,
					RES_ERROR_LOAD_INVALID_PATH
				};
				return result;
			}

			ResourceResult<sf::Font> result{
				true,
				RES_SUCCESS_LOAD,
				fonts.back()
			};
			return result;
		}
		ResourceResult<sf::Font> ResourceManager::GetFont(const std::string& _name){
			if(fonts.size()==0){
				auto emptyResource=ResourceContainer<sf::Font>(_name);
				ResourceResult<sf::Font> result{
					false,
					RES_ERROR_GET_NO_RESOURCES_OF_TYPE,
					std::make_shared<ResourceContainer<sf::Font>>(emptyResource)
				};
				return result;
			}

			for(int i=0;i<fonts.size();i++){
				if(fonts[i]->name==_name){
					ResourceResult<sf::Font> result{
						true,
						RES_SUCCESS_GET,
						fonts[i]
					};
					return result;
				}
			}

			auto emptyResource=ResourceContainer<sf::Font>(_name);
			ResourceResult<sf::Font> result{
				false,
				RES_ERROR_GET_DOES_NOT_EXIST,
					std::make_shared<ResourceContainer<sf::Font>>(emptyResource)
			};
			return result;
		}

		void ResourceManager::DebugPrintResources(){
			std::cout<<"--------------"<<std::endl;
			std::cout<<"Resource Dump:"<<std::endl;
			std::cout<<"--------------"<<std::endl;

			std::cout<<"Textures:"<<std::endl;
			std::cout<<textures.size()<<std::endl;
			for(int i{0};i<textures.size();i++){
				auto texture{textures[i]};
				std::cout<<"'"<<texture->name<<"'"<<std::endl;
			}

			std::cout<<"--------------"<<std::endl;
			std::cout<<"Fonts:"<<std::endl;
			std::cout<<fonts.size()<<std::endl;
			for(int i{0};i<fonts.size();i++){
				auto font{fonts[i]};
				std::cout<<"'"<<font->name<<"'"<<std::endl;
			}

			std::cout<<"--------------"<<std::endl;
		}
	}
}