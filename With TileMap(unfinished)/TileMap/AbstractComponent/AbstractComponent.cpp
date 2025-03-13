#include "AbstractComponent.h"

AComponent::AComponent(std::string name, ComponentType type) {
	this->name = name;
	this->owner = nullptr;
	this->type = type;
}

AComponent::~AComponent() {
	this->owner = nullptr;
	this->type = NotSet;
}

void AComponent::attachOwner(AGameObject* object) {
	this->owner = object;
}

void AComponent::detachOwner() {
	//If object owner gets detached, then component must also be deleted
	delete this;
}

AGameObject* AComponent::getOwner() {
	return this->owner;
}

AComponent::ComponentType AComponent::getType() {
	return this->type;
}

std::string AComponent::getName() {
	return this->name;
}

void AComponent::setDeltaTime(sf::Time deltaTime) {
	this->deltaTime = deltaTime;
}
