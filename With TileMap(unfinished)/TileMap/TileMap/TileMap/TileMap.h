#pragma once
#include <vector>
#include <string>
#include "../../AbstractGameObject/AbstractGameObject.h"
#include "../Tile/Tile.h"

class TileMap {
public:
    TileMap(std::string, sf::Texture tileSet, sf::VertexArray vertexArray,
        int width, int height, float tileTextureDimension, float tileWorldDimension) {
        this->tileSet = tileSet;
        this->width = width;
        this->height = height;
        this->tileTextureDimension = tileTextureDimension;
        this->tileWorldDimension = tileWorldDimension;

        this->vertexArray = new sf::VertexArray(sf::PrimitiveType::Quads, (unsigned int)(width * height * 4));
        Tile* tile = new Tile(0, 0, sf::Color::White);
        for (int i = 0; i < width; i++) {
            for (int j = 0; j < height; j++) {
                addTileVertices();
            }
        }
    }


private:
    void addTileVertices(Tile tile, sf::Vector2f position) {

    }

    std::string name;
    sf::Texture tileSet;
    sf::VertexArray* vertexArray;

    int width;
    int height;
    float tileTextureDimension;
    float tileWorldDimension;
    


    

};