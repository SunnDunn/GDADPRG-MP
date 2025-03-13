#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

//Also known as a GameObject class
//A game element in the world (enemies, bullet, pickups)
//Keeps track of an object's state(physics state, hitpoints)
class Entity {
public:
    Entity();
    void SetTexture(sf::Texture texture);
    sf::Sprite* getSprite();

    static Entity* createEntity(sf::Texture* tex, float x, float y);
    
private:
    sf::Texture mTexture;
    sf::Sprite mSprite;
};