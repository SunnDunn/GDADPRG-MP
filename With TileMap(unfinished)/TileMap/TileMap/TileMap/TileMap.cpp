#include "TileMap.h"
#include <iostream>

TileMap::TileMap(std::string name, std::vector<int>* frame, bool rotated, bool trimmed,
	std::vector<int>* tileSourceSize, std::vector<int>* sourceSize) {
	this->name = name;
	this->frame = *frame;
	this->rotated = rotated;
	this->trimmed = trimmed;
	this->tileSourceSize = *tileSourceSize;
	this->sourceSize = *sourceSize;
}

