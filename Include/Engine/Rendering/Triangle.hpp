#pragma once

#include <SFML/Graphics.hpp>

struct Triangle{
	std::shared_ptr<sf::Vertex>
		a{nullptr},
		b{nullptr},
		c{nullptr};

	Triangle();
	Triangle(const Triangle& _other);
	~Triangle();

	void operator=(const Triangle& _other);

	bool operator==(Triangle& _other)const;
	bool operator==(const Triangle& _other)const;

	bool operator!=(Triangle& _other)const;
	bool operator!=(const Triangle& _other)const;

	bool ContainsNullVertices()const;
};