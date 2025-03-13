#include "GenericObject.h"
#include <iostream>
#include "../Game.h"
#include "../Renderer/Renderer.h"
#include "../TextureManager/TextureManager.h"

GenericObject::GenericObject(std::string name) : AGameObject(name){
}

GenericObject::~GenericObject() {
	delete shape;
}

void GenericObject::initialize(){
	std::cout << "Declared as " << this->getName() << std::endl;

	sf::Texture* texture = TextureManager::getInstance()->getTexture("cat");
	this->sprite = new sf::Sprite;
	this->sprite->setTexture(*texture);

	this->shape = getShape();

	this->shape->setTexture(texture);
	
	//sf::Vector2u textureSize = this->sprite->getTexture()->getSize();
	//this->sprite->setOrigin(textureSize.x / 2, textureSize.y / 2);
	//std::cout << "origin at " << textureSize.x / 2 << " " << textureSize.y / 2 << std::endl;
	//this->sprite->setPosition(Game::WINDOW_WIDTH / 2, Game::WINDOW_HEIGHT / 2);
	//std::cout << "position at " << Game::WINDOW_WIDTH / 2 << " " << Game::WINDOW_HEIGHT / 2 << std::endl;
	
	Renderer* renderer = new Renderer(this->getName());
	renderer->assignDrawable(this->shape);
	this->attachComponent(renderer);
}
void GenericObject::processInput(sf::Event event){}
void GenericObject::update(sf::Time deltaTime){}
