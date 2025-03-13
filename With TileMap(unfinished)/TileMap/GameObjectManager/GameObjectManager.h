#pragma once
#include <iostream>
#include <unordered_map>
#include "../AbstractGameObject/AbstractGameObject.h"

//Manages a game object's lifecycle
//Minimizes code in Game.cpp
class GameObjectManager {
public:
	static GameObjectManager* getInstance();
	AGameObject* findObjectByName(std::string name);
	std::vector<AGameObject*> getAllObjects();
	int activeObjects();
	void processInput(sf::Event event);
	void update(sf::Time deltaTime);
	void draw(sf::RenderWindow* window);
	void addObject(AGameObject* gameObject);
	void deleteObject(AGameObject* gameObject);
	void deleteObjectByName(std::string name);
	//void deleteAllObjectsInScene();

private:
	GameObjectManager() {};
	GameObjectManager(GameObjectManager const&) {};
	GameObjectManager& operator= (GameObjectManager const&) {};

	static GameObjectManager* sharedInstance;

	//To reference objects quickly. Mainly used for searching
	std::unordered_map<std::string, AGameObject*> mGameObjectMap;
	//To use in process, update, and draw. Mainly used for iteration
	//A list of class AGameObject*'s which stores an object(sprite and texture) and allows us to 
	//have our own abstract methods
	std::vector<AGameObject*> mGameObjectList;
};