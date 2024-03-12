#pragma once

#include <SFML/Graphics.hpp>

#include <iostream>
#include <string>
#include <vector>

#include "ResourceResult.hpp"
#include "ResourceContainer.hpp"

#define TextureResource std::shared_ptr<eng::Resources::ResourceContainer<sf::Texture>>
#define FontResource std::shared_ptr<eng::Resources::ResourceContainer<sf::Font>>

namespace eng{
	namespace Resources{
		class ResourceManager{
			const static std::string RES_SUCCESS_LOAD;
			const static std::string RES_SUCCESS_GET;

			const static std::string RES_ERROR_LOAD_NAME_ALREADY_LOADED;
			const static std::string RES_ERROR_LOAD_INVALID_PATH;
			const static std::string RES_ERROR_GET_NO_RESOURCES_OF_TYPE;
			const static std::string RES_ERROR_GET_DOES_NOT_EXIST;

			std::vector<TextureResource> textures{};
			std::vector<FontResource> fonts{};

		public:
			ResourceResult<sf::Texture> LoadTexture(const std::string& _name,const std::string& _path);

			ResourceResult<sf::Texture> GetTexture(const std::string& _name);

			ResourceResult<sf::Font> LoadFont(const std::string& _name,const std::string& _path);
			ResourceResult<sf::Font> GetFont(const std::string& _name);

			void DebugPrintResources();
		};
	}
}