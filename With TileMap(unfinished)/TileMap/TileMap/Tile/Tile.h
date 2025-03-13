#pragma once
#include <SFML/Graphics.hpp>

class Tile {
public:
	Tile(int x, int y, sf::Color color);
	int x;
	int y;

	//Color in map file that represents this file
	sf::Color color;

private:


};