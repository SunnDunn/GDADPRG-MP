#pragma once
#include "../AbstractGameObject/AbstractGameObject.h"
#include "../Game.h"
class GenericObject : public AGameObject{
public:
	GenericObject(std::string name);
	~GenericObject();
	void initialize();
	void processInput(sf::Event event);
	void update(sf::Time deltaTime);

	virtual sf::Shape* getShape() = 0;

	virtual void setPosition(float x, float y) = 0;
	virtual void setOrigin(float x, float y) = 0;

	virtual sf::Vector2f getPosition() = 0;
private:


protected:
	sf::Shape* shape;
	sf::Vector2f position;
	sf::Vector2f origin;
	sf::Vector2f scale;

};

class Rectangle : public GenericObject {
public:
	Rectangle(std::string name, float width, float height) : GenericObject(name){
		this->rectangle = new sf::RectangleShape;
		this->rectangle->setSize(sf::Vector2f(width, height));

		this->rectangle->setOrigin(width / 2, height / 2);
		setPosition(Game::WINDOW_WIDTH / 2, Game::WINDOW_HEIGHT / 2);
	}
	sf::Shape* getShape() {
		return rectangle;
	}

	void setSize(float width, float height) {
		this->rectangle->setSize(sf::Vector2f(width, height));
	}
	void setFillColor(sf::Color color) {
		this->rectangle->setFillColor(color);
	}

	void setOrigin(float x, float y) {
		this->rectangle->setOrigin(x, y);
	}
	void setPosition(float x, float y) {
		this->rectangle->setPosition(sf::Vector2f(x, y));
	}
	sf::Vector2f getPosition() {
		return this->rectangle->getPosition();
	}
private:
	sf::RectangleShape* rectangle;
};

class Circle : public GenericObject {
public:
	Circle(std::string name,float radius) : GenericObject(name) {
		circle = new sf::CircleShape;
		circle->setRadius(radius);

		setOrigin(radius, radius);
		setPosition(Game::WINDOW_WIDTH / 2, Game::WINDOW_HEIGHT / 2);
	}
	sf::Shape* getShape() {
		return circle;
	}
	void setSize(float radius) {
		this->circle->setRadius(radius);
	}
	void setFillColor(sf::Color color) {
		this->circle->setFillColor(color);
	}

	void setOrigin(float x, float y) {
		this->circle->setOrigin(x, y);
	}
	void setPosition(float x, float y) {
		this->circle->setPosition(sf::Vector2f(x, y));
	}
	sf::Vector2f getPosition() {
		return this->circle->getPosition();
	}
	
private:
	sf::CircleShape* circle;
};