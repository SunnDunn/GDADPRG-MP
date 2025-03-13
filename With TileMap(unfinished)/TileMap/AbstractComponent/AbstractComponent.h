#pragma once

#include <string>
#include <SFML/Graphics.hpp>

class AGameObject; // Forward declaration to avoid circular dependency

class AComponent {
public:
	enum ComponentType { NotSet = -1, Script = 0, Renderer = 1, Input = 2 };
	AComponent(std::string name, ComponentType type);
	virtual ~AComponent();

	void attachOwner(AGameObject* object);
	void detachOwner();
	AGameObject* getOwner();
	ComponentType getType();
	std::string getName();

	void setDeltaTime(sf::Time deltaTime);
	virtual void perform() = 0; //Perform associated action

protected:
	AGameObject* owner;
	ComponentType type;
	std::string name;
	sf::Time deltaTime;
};