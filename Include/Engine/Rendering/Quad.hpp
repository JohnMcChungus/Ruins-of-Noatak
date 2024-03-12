#pragma once

#include <iostream>
#include "Triangle.hpp"

struct Quad{
	Triangle
		bottomLeft{},
		topRight{};

	static const int VERTICES_PER_QUAD;
	static const Quad EMPTY;

	Quad();
	Quad(const Quad& _other);
	~Quad();

	void operator=(const Quad& _other);

	bool operator==(Quad& _other)const;
	bool operator==(const Quad& _other)const;

	bool operator!=(Quad& _other)const;
	bool operator!=(const Quad& _other)const;

	static Quad CreateFromVertexArray(sf::VertexArray& _copyArray,const size_t _quadScanIndex);
};
