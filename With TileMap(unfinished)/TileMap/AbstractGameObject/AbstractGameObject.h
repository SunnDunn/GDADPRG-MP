#pragma once
#include <string>
#include <SFML/Graphics.hpp>
#include "../AbstractComponent/AbstractComponent.h"


//An abstract method "= 0" requires implementation and can't self instantiate
//Abstract objects are meant to be subclassed 
class AGameObject {
public:
	AGameObject(std::string name);
	virtual ~AGameObject();
	virtual void initialize() = 0;
	virtual void processInput(sf::Event event);
	virtual void update(sf::Time deltaTime);
	//renderStates contains the transforms to be passed down the hierarchy
	virtual void draw(sf::RenderWindow* targetWindow, sf::RenderStates renderStates);
	std::string getName();

	sf::Transformable* getTransformable();
	void attachChild(AGameObject* child);
	void detachChild(AGameObject* child);
	void setPosition(float x, float y);

	void attachComponent(AComponent* component);
	void detachComponent(AComponent* component);
	AComponent* findComponentByName(std::string name);
	AComponent* findComponentOfType(AComponent::ComponentType type, std::string name);
	std::vector<AComponent*> getComponentsOfType(AComponent::ComponentType type);
	std::vector<AComponent*> getComponentsOfTypeRecursive(AComponent::ComponentType type);

	void setEnabled(bool flag);
	bool isEnabled();
	AGameObject* getParent();

protected:
	void setParent(AGameObject* gameObject);
	//keep track of the object we are transforming, responsible for applying transformations and operations we will apply
	sf::Transformable transformable;
	std::string name;
	sf::Sprite* sprite;
	sf::Texture texture;
	std::vector<AGameObject*> childList;
	std::vector<AComponent*> componentList;
	

private:
	AGameObject* mParent;
	std::vector<AComponent*> getComponentsRecursiveProper(
		AGameObject* object, AComponent::ComponentType type,
		std::vector<AComponent*> foundList
	);
	bool enabled = true;
}; 
