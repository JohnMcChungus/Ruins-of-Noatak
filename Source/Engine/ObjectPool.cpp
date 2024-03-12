#include "../../Include/Engine/Rendering/ObjectPool.hpp"

namespace eng{
	void ObjectPool::draw(sf::RenderTarget& _target,sf::RenderStates _states) const{
		_states.texture=&texture->data;
		_target.draw(vertices,_states);
	}

	ObjectPool::ObjectPool(size_t _size):
		vertices{sf::Triangles,_size*Quad::VERTICES_PER_QUAD}{
		for(size_t i=0;i<_size*Quad::VERTICES_PER_QUAD;i+=Quad::VERTICES_PER_QUAD){
			objects.push_back(AnimatableObject{Quad::CreateFromVertexArray(vertices,i)});
		}
	}

	ObjectPool::ObjectPool(const ObjectPool& _other):
		objects{_other.objects},
		vertices{_other.vertices},
		texture{_other.texture}
	{

	}

	ObjectPool::~ObjectPool(){

	}

	std::vector<AnimatableObject>& ObjectPool::GetObjects(){
		return objects;
	}

	std::shared_ptr<AnimatableObject> ObjectPool::GetObject(int _index){
		if(_index<0){
			std::cout<<"ObjectPool::GetObject: Index is less than zero."<<std::endl;
			return nullptr;
		}
		else if(_index>=objects.size()){
			std::cout<<"ObjectPool::GetObject: Index is too high."<<std::endl;
			return nullptr;
		}

		return std::make_shared<AnimatableObject>(objects[_index]);
	}

	void ObjectPool::SetTexture(TextureResource _textureResource){
		texture=_textureResource;
	}

	TextureResource ObjectPool::GetTexture() const{
		return texture;
	}
}
