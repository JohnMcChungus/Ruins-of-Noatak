#include "../../../Include/Engine/Animation/AnimatableObject.hpp"

namespace eng{
	void AnimatableObject::draw(sf::RenderTarget& _target,sf::RenderStates _states)const{
		_states.texture=&texture->data;
		_target.draw(vertices,_states);
	}

	AnimatableObject::AnimatableObject():
		vertices{sf::Triangles,Quad::VERTICES_PER_QUAD}{

	}

	AnimatableObject::AnimatableObject(sf::VertexArray& _vertexArray):
		vertices{_vertexArray}
	{

	}

	AnimatableObject::AnimatableObject(Quad _quad):
		quad{_quad}
	{

	}

	AnimatableObject::AnimatableObject(const AnimatableObject& _other):
		position{_other.position},
		size{_other.size},
		scale{_other.scale},
		uvs{_other.uvs},
		texture{_other.texture},
		vertices{_other.vertices},
		quad{_other.quad}
	{

	}

	AnimatableObject::~AnimatableObject(){

	}

	void AnimatableObject::UpdateTransform(){
		if(quad!=Quad::EMPTY){
			quad.bottomLeft.a->position=position;
			quad.bottomLeft.b->position=position+sf::Vector2f{size.x*scale.x,0.0f};
			quad.bottomLeft.c->position=position+sf::Vector2f{size.x*scale.x,size.y*scale.y};

			quad.topRight.a->position=position;
			quad.topRight.b->position=position+sf::Vector2f{size.x*scale.x,size.y*scale.y};
			quad.topRight.c->position=position+sf::Vector2f{0.0f,size.y*scale.y};
		}
		else if(vertices.getVertexCount()>0){
			for(int i=0;i<Quad::VERTICES_PER_QUAD;i++){
				vertices[i].position=position;
			}
			vertices[1].position+={size.x* scale.x,0.0f};
			vertices[2].position+={size.x* scale.x,size.y* scale.y};
			vertices[4].position+={size.x* scale.x,size.y* scale.y};
			vertices[5].position+={0.0f,size.y* scale.y};
		}

	}

	void AnimatableObject::UpdateUVs(){
		if(quad!=Quad::EMPTY){
			quad.bottomLeft.a->texCoords={uvs.left,uvs.top};
			quad.bottomLeft.b->texCoords={uvs.left+uvs.width,uvs.top};
			quad.bottomLeft.c->texCoords={uvs.left+uvs.width,uvs.top+uvs.height};

			quad.topRight.a->texCoords={uvs.left,uvs.top};
			quad.topRight.b->texCoords={uvs.left+uvs.width,uvs.top+uvs.height};
			quad.topRight.c->texCoords={uvs.left,uvs.top+uvs.height};
		}
		else if(vertices.getVertexCount()>0){
			vertices[0].texCoords={uvs.left,uvs.top};
			vertices[1].texCoords={uvs.left+uvs.width,uvs.top};
			vertices[2].texCoords={uvs.left+uvs.width,uvs.top+uvs.height};

			vertices[3].texCoords={uvs.left,uvs.top};
			vertices[4].texCoords={uvs.left+uvs.width,uvs.top+uvs.height};
			vertices[5].texCoords={uvs.left,uvs.top+uvs.height};
		}
	}

	void AnimatableObject::SetPosition(const sf::Vector2f _position){
		position=_position;
		UpdateTransform();
	}

	void AnimatableObject::MovePosition(const sf::Vector2f _position){
		SetPosition(position+_position);
	}

	const sf::Vector2f AnimatableObject::GetPosition()const{
		return position;
	}

	void AnimatableObject::SetSize(const sf::Vector2f _size){
		size=_size;
		UpdateTransform();
	}

	void AnimatableObject::Resize(const sf::Vector2f _amount){
		SetSize(size+_amount);
	}

	const sf::Vector2f AnimatableObject::GetSize()const{
		return size;
	}

	void AnimatableObject::SetScale(const sf::Vector2f _scale){
		scale=_scale;
		UpdateTransform();
	}

	void AnimatableObject::Rescale(const sf::Vector2f _amount){
		SetScale(scale+_amount);
	}

	const sf::Vector2f AnimatableObject::GetScale()const{
		return scale;
	}

	void AnimatableObject::SetUVs(const sf::FloatRect _uvs,bool _resize){
		uvs=_uvs;
		UpdateUVs();

		if(_resize){
			ResizeToUVs();
		}
	}

	void AnimatableObject::SetUVsPosition(const sf::Vector2f _position,bool _resize){
		SetUVs({_position.x,_position.y,uvs.width,uvs.height},_resize);
	}

	const sf::FloatRect AnimatableObject::GetUVs()const{
		return uvs;
	}

	void AnimatableObject::SetTexture(std::shared_ptr<Resources::ResourceContainer<sf::Texture>> _textureResource){
		texture=_textureResource;
	}

	std::shared_ptr<Resources::ResourceContainer<sf::Texture>> AnimatableObject::GetTexture(){
		return texture;
	}

	sf::VertexArray& AnimatableObject::GetVertices(){
		return vertices;
	}

	Quad& AnimatableObject::GetQuad(){
		return quad;
	}

	void AnimatableObject::Refresh(){
		UpdateTransform();
		UpdateUVs();
	}

	void AnimatableObject::ResizeToUVs(){
		SetSize(uvs.getSize());
	}
}
