#include "AbstractGameObject.h"
#include <iostream>
	//#include "../GenericInputController/GenericInputController.h"
#include "../Renderer/Renderer.h"

AGameObject::AGameObject(std::string name) {
	this->name = name;
}

AGameObject::~AGameObject() {
	//iterate through childlist and delete
	for (int i = 0; i < this->childList.size(); i++) {
		delete this->childList[i];
	}

	for (int i = 0; i < this->componentList.size(); i++) {
		delete this->componentList[i];
	}

	this->childList.clear(); //Removes all elements of container
	this->childList.shrink_to_fit(); //Shrinks capacity (not size) of childlist

}

std::string AGameObject::getName() {
	return name;
}

sf::Transformable* AGameObject::getTransformable() {
	return &this->transformable;
}

void AGameObject::draw(sf::RenderWindow* targetWindow, sf::RenderStates renderStates) {
	if (!this->isEnabled()) return;
	std::vector<AComponent*> componentList = this->getComponentsOfType(AComponent::ComponentType::Renderer);
	
	//Gets the current object transform and sets it in renderState
	renderStates.transform = renderStates.transform * this->transformable.getTransform();

	//Draws sprite of current object
	for (int j = 0; j < componentList.size(); j++) {
		Renderer* renderer = (Renderer*)componentList[j];
		renderer->assignTargetWIndow(targetWindow);
		renderer->setRednerStates(renderStates);
		renderer->perform();
	}

	//Draws each child object. Each child will apply their own transform
	for (int i = 0; i < this->childList.size(); i++) {
		AGameObject* child = this->childList[i];
		child->draw(targetWindow, renderStates);
	}
}

void AGameObject::processInput(sf::Event event) {
	if (!this->isEnabled()) return;
	//Get a list of components of type Input and store into a list componentList
	std::vector<AComponent*> componentList = this->getComponentsOfType(AComponent::ComponentType::Input);
	/*Typecast each component from Componentlist into a GenericInputController* and
	assign the parameter event to componentList before componentlist can perform the event
	*/
	/*for (int j = 0; j < componentList.size(); j++) {
		((GenericInputController*)componentList[j])->assignEvent(event);
		componentList[j]->perform();
	}*/

	//Repeat recursively for each child of current object
	for (int i = 0; i < this->childList.size(); i++) {
		childList[i]->processInput(event);
	}
}

void AGameObject::update(sf::Time deltaTime) {
	if (!this->isEnabled()) return;

	std::vector<AComponent*> componentList =
		this->getComponentsOfType(AComponent::ComponentType::Script);

	for (int j = 0; j < componentList.size(); j++) {
		componentList[j]->setDeltaTime(deltaTime);
		componentList[j]->perform();
	}

	for (int i = 0; i < this->childList.size(); i++) {
		childList[i]->update(deltaTime);
	}
}

void AGameObject::attachChild(AGameObject* child) {
			//std::cout << "pushing back " << child->getName();
	if (child == nullptr) {
		std::cout << child->getName() << " is nullptr" << std::endl;
	}
	else{
		this->childList.push_back(child);
			//std::cout << " | AGameObj" << std::endl;
		child->setParent(this);
		child->initialize();
	}
}

void AGameObject::detachChild(AGameObject* child){
	int index = -1;
	for (int i = 0; i < this->childList.size(); i++) {
		if (this->childList[i] == child) {
			index = i;
		}
	}

	if (index != -1) {
		this->childList.erase(this->childList.begin() + index);
		this->childList.shrink_to_fit();
	}
}

void AGameObject::setPosition(float x, float y){
	this->transformable.setPosition(x, y); 
}

void AGameObject::attachComponent(AComponent* component)
{
	this->componentList.push_back(component);
	component->attachOwner(this);
}


void AGameObject::detachComponent(AComponent* component) {
	int index = -1;
	for (int i = 0; i < this->componentList.size(); i++) {
		if (this->componentList[i] == component) {
			index = i;
			this->componentList[i]->detachOwner();
			break;
		}
		if (index != -1) {
			this->componentList.erase(this->componentList.begin() + index);
		}
	}
}

AComponent* AGameObject::findComponentByName(std::string name){
	for (int i = 0; i < this->componentList.size(); i++) {
		if (this->componentList[i]->getName() == name) {
			return this->componentList[i];
		}
	}
	return nullptr;
}

AComponent* AGameObject::findComponentOfType(AComponent::ComponentType type, std::string name){
	for (int i = 0; i < this->componentList.size(); i++) {
		if (this->componentList[i]->getName() == name && this->componentList[i]->getType() == type) {
			return this->componentList[i];
		}
	}

	return nullptr;
}

std::vector<AComponent*> AGameObject::getComponentsOfType(AComponent::ComponentType type){
	std::vector<AComponent*> foundList;
	for (int i = 0; i < this->componentList.size(); i++) {
		if (this->componentList[i]->getType() == type) {
			foundList.push_back(this->componentList[i]);
		}
	}

	return foundList;
}

std::vector<AComponent*> AGameObject::getComponentsOfTypeRecursive(AComponent::ComponentType type) {
	std::vector<AComponent*> foundList;

	for (int i = 0; i < this->componentList.size(); i++) {
		if (this->componentList[i]->getType() == type) {
			foundList.push_back(this->componentList[i]);
		}
	}

	for (int i = 0; i < this->childList.size(); i++) {
		foundList = this->getComponentsRecursiveProper(this->childList[i], type, foundList);
	}

	return foundList;
}

std::vector<AComponent*> AGameObject::getComponentsRecursiveProper(
	AGameObject* object, AComponent::ComponentType type,
	std::vector<AComponent*> foundList
) {
	std::vector<AComponent*> list;
	return list;
}

void AGameObject::setEnabled(bool flag) {
	this->enabled = flag;
}

bool AGameObject::isEnabled(){
	return this->enabled;
}

AGameObject* AGameObject::getParent() {
	return this->mParent;
}

void AGameObject::setParent(AGameObject* parent) {
	this->mParent = parent;
}