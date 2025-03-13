#pragma once
#include <string>
#include <SFML/Graphics.hpp>
#include "../AbstractComponent/AbstractComponent.h"

class AComponent;
//An abstract method "= 0" requires implementation and can't self instantiate
//Abstract objects are meant to be subclassed 
class AShapeObject {
public:
	AShapeObject(std::string name);
	virtual ~AShapeObject();
	virtual void initialize() = 0;
	virtual void processInput(sf::Event event);
	virtual void update(sf::Time deltaTime);
	//renderStates contains the transforms to be passed down the hierarchy
	virtual void draw(sf::RenderWindow* targetWindow, sf::RenderStates renderStates);
	std::string getName();

	sf::Transformable* getTransformable();
	void attachChild(AShapeObject* child);
	void detachChild(AShapeObject* child);
	void setPosition(float x, float y);

	void attachComponent(AComponent* component);
	void detachComponent(AComponent* component);

	/*AShapeObject* findComponentByName(std::string name);
	AShapeObject* findComponentOfType(AComponent::ComponentType type, std::string name);
	std::vector<AShapeObject*> getComponentsOfType(AComponent::ComponentType type);
	std::vector<AShapeObject*> getComponentsOfTypeRecursive(AComponent::ComponentType type);

	void setEnabled(bool flag);
	bool isEnabled();*/

protected:
	//keep track of the object we are transforming, responsible for applying transformations and operations we will apply
	sf::Transformable transformable;
	std::string name;
	sf::Sprite* sprite;
	sf::Texture texture;
	std::vector<AShapeObject*> childList;
	std::vector<AComponent*> componentList;
	//optional: sf::AGameObject* mParent; 

private:
	/*std::vector<AComponent*> getComponentsRecursiveProper(
		AGameObject* object, AComponent::ComponentType type,
		std::vector<AComponent*> foundList
	);*/
	bool enabled = true;
};
