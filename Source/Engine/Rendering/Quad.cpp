#include "../../../Include/Engine/Rendering/Quad.hpp"

const int Quad::VERTICES_PER_QUAD{6};

const Quad Quad::EMPTY{};

Quad::Quad():
	bottomLeft{},
	topRight{}{

}

Quad::Quad(const Quad& _other):
	bottomLeft{_other.bottomLeft},
	topRight{_other.topRight}{

}

Quad::~Quad(){

}

void Quad::operator=(const Quad& _other){
	bottomLeft=_other.bottomLeft;
	topRight=_other.topRight;
}

bool Quad::operator==(Quad& _other)const{
	return (
		bottomLeft==_other.bottomLeft&&
		topRight==_other.topRight);
}

bool Quad::operator==(const Quad& _other)const{
	return (
		bottomLeft==_other.bottomLeft&&
		topRight==_other.topRight);
}

bool Quad::operator!=(Quad& _other)const{
	return (
		bottomLeft!=_other.bottomLeft&&
		topRight!=_other.topRight);
}

bool Quad::operator!=(const Quad& _other)const{
	return (
		bottomLeft!=_other.bottomLeft&&
		topRight!=_other.topRight);
}

Quad Quad::CreateFromVertexArray(sf::VertexArray& _copyArray,const size_t _quadScanIndex){
	if(_quadScanIndex<0){
		std::cout<<"Quad::CopyQuad: Index is less than zero."<<std::endl;
		return EMPTY;
	}
	else if(_quadScanIndex>_copyArray.getVertexCount()-6){ // Keep an eye on this.
		std::cout<<"Quad::CopyQuad: Index is too high."<<std::endl;
		return EMPTY;
	}
	else if(_copyArray.getVertexCount()<VERTICES_PER_QUAD){
		std::cout<<"Quad::CopyQuad: Provided sf::VertexArray is too small."<<std::endl;
		return EMPTY;
	}

	Quad quad{};

	quad.bottomLeft.a=std::make_shared<sf::Vertex>(_copyArray[_quadScanIndex+0]);
	quad.bottomLeft.b=std::make_shared<sf::Vertex>(_copyArray[_quadScanIndex+1]);
	quad.bottomLeft.c=std::make_shared<sf::Vertex>(_copyArray[_quadScanIndex+2]);

	quad.topRight.a=std::make_shared<sf::Vertex>(_copyArray[_quadScanIndex+3]);
	quad.topRight.b=std::make_shared<sf::Vertex>(_copyArray[_quadScanIndex+4]);
	quad.topRight.c=std::make_shared<sf::Vertex>(_copyArray[_quadScanIndex+5]);

	return quad;
}