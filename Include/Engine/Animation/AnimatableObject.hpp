#pragma once

#include <SFML/Graphics.hpp>
#include <array>

#include "../Util/ResourceManager.hpp"
#include "../Rendering/Quad.hpp"

namespace eng{
	class AnimatableObject:public sf::Drawable{
		sf::VertexArray vertices{};
		Quad quad{};

		sf::Vector2f
			position{0,0},
			size{0,0},
			scale{1,1};

		sf::FloatRect
			uvs{0,0,0,0};

		std::shared_ptr<Resources::ResourceContainer<sf::Texture>> texture{nullptr};

		void draw(sf::RenderTarget& _target,sf::RenderStates _states)const override;

		void UpdateTransform();
		void UpdateUVs();

	public:
		AnimatableObject();
		AnimatableObject(sf::VertexArray& _vertexArray);
		AnimatableObject(Quad _quad);
		AnimatableObject(const AnimatableObject& _other);
		~AnimatableObject();

		void SetPosition(const sf::Vector2f _position);
		void MovePosition(const sf::Vector2f _position);
		const sf::Vector2f GetPosition()const;

		void SetSize(const sf::Vector2f _size);
		void Resize(const sf::Vector2f _amount);
		const sf::Vector2f GetSize()const;

		void SetScale(const sf::Vector2f _scale);
		void Rescale(const sf::Vector2f _amount);
		const sf::Vector2f GetScale()const;

		void SetUVs(const sf::FloatRect _uvs,bool _resize = false);
		void SetUVsPosition(const sf::Vector2f _amount,bool _resize=false);
		const sf::FloatRect GetUVs()const;

		void SetTexture(std::shared_ptr<Resources::ResourceContainer<sf::Texture>> _textureResource);
		std::shared_ptr<Resources::ResourceContainer<sf::Texture>> GetTexture();

		sf::VertexArray& GetVertices();
		Quad& GetQuad();

		void Refresh();
		void ResizeToUVs();
	};
}
