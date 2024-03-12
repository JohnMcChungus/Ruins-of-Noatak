#include "../../../Include/Engine/Rendering/Triangle.hpp"

Triangle::Triangle():
	a{nullptr},
	b{nullptr},
	c{nullptr}{

}

Triangle::Triangle(const Triangle& _other):
	a{_other.a},
	b{_other.b},
	c{_other.c}{

}

Triangle::~Triangle(){

}

void Triangle::operator=(const Triangle& _other){
	a=_other.a;
	b=_other.b;
	c=_other.c;
}

bool Triangle::operator==(Triangle& _other)const{
	if(ContainsNullVertices()||_other.ContainsNullVertices()){
		return false;
	}

	return (
		a->color==_other.a->color&&
		a->position==_other.a->position&&
		a->texCoords==_other.a->texCoords&&

		b->color==_other.b->color&&
		b->position==_other.b->position&&
		b->texCoords==_other.b->texCoords&&

		c->color==_other.c->color&&
		c->position==_other.c->position&&
		c->texCoords==_other.c->texCoords);
}

bool Triangle::operator==(const Triangle& _other)const{
	if(ContainsNullVertices()||_other.ContainsNullVertices()){
		return false;
	}

	return (
		a->color==_other.a->color&&
		a->position==_other.a->position&&
		a->texCoords==_other.a->texCoords&&

		b->color==_other.b->color&&
		b->position==_other.b->position&&
		b->texCoords==_other.b->texCoords&&

		c->color==_other.c->color&&
		c->position==_other.c->position&&
		c->texCoords==_other.c->texCoords);
}

bool Triangle::operator!=(Triangle& _other)const{
	if(ContainsNullVertices()||_other.ContainsNullVertices()){
		return false;
	}

	return (
		a->color!=_other.a->color&&
		a->position!=_other.a->position&&
		a->texCoords!=_other.a->texCoords&&

		b->color!=_other.b->color&&
		b->position!=_other.b->position&&
		b->texCoords!=_other.b->texCoords&&

		c->color!=_other.c->color&&
		c->position!=_other.c->position&&
		c->texCoords!=_other.c->texCoords);
}

bool Triangle::operator!=(const Triangle& _other)const{
	if(ContainsNullVertices()||_other.ContainsNullVertices()){
		return false;
	}

	return (
		a->color!=_other.a->color&&
		a->position!=_other.a->position&&
		a->texCoords!=_other.a->texCoords&&

		b->color!=_other.b->color&&
		b->position!=_other.b->position&&
		b->texCoords!=_other.b->texCoords&&

		c->color!=_other.c->color&&
		c->position!=_other.c->position&&
		c->texCoords!=_other.c->texCoords);
}

bool Triangle::ContainsNullVertices() const{
	return
		a==nullptr||
		b==nullptr||
		c==nullptr;
}
