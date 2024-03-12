#pragma once

#include <SFML/Graphics.hpp>
#include <vector>

#include "../Animation/AnimatableObject.hpp"
#include "../Util/ResourceManager.hpp"

namespace eng{
	class ObjectPool:public sf::Drawable{
		std::vector<AnimatableObject> objects{};
		sf::VertexArray vertices{};

		TextureResource texture{nullptr};

		void draw(sf::RenderTarget& _target,sf::RenderStates _states) const override;

	public:
		ObjectPool(size_t _size);
		ObjectPool(const ObjectPool& _other);
		~ObjectPool();

		std::vector<AnimatableObject>& GetObjects();
		std::shared_ptr<AnimatableObject> GetObject(int _index);

		void SetTexture(TextureResource _textureResource);
		TextureResource GetTexture()const;
	};
}
