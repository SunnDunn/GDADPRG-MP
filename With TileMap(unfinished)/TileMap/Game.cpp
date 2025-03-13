#include "Game.h"
#include "GenericObject/GenericObject.h"

Game::Game() : mWindow(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "SFML Application"){
	mWindow.setFramerateLimit(60);
	
	TextureManager::getInstance()->loadAll();

	GameObjectManager* gameInstance = GameObjectManager::getInstance();

	//Rectangle* rect = new Rectangle("rectangle", 200, 150);
	//gameInstance->addObject(rect);

	//Circle* circle = new Circle("circle", 50);
	//circle->setPosition(50, 50);
	//gameInstance->addObject(circle);



}

void Game::addEntity(std::string key, float x, float y) {
	sf::Texture* texture = TextureManager::getInstance()->getTexture(key);
	Entity* newEntity = Entity::createEntity(texture, x, y);
	mEntityList.push_back(newEntity);
}

void Game::run() {
	sf::Clock clock;
	sf::Time timeSinceLastUpdate = sf::Time::Zero;
	while (mWindow.isOpen()) {
		processEvents();
		timeSinceLastUpdate += clock.restart();
		while (timeSinceLastUpdate > TimePerFrame) {
			timeSinceLastUpdate -= TimePerFrame;
			processEvents();
			update(TimePerFrame);
		}
		render();
	}
}

void Game::processEvents() {
	sf::Event event;
	while (mWindow.pollEvent(event)) {
		switch (event.type) {
		case sf::Event::Closed:
			mWindow.close();
			break;
		default:
			GameObjectManager::getInstance()->processInput(event);
		}
	}
}

void Game::drawObjects() {
	for (int i = 0; i < mEntityList.size(); i++) {
		mWindow.draw(*mEntityList[i]->getSprite());
	}
}

void Game::render() {
	mWindow.clear();
	GameObjectManager::getInstance()->draw(&mWindow);
	mWindow.display();
}

void Game::update(sf::Time deltaTime) {
	GameObjectManager::getInstance()->update(deltaTime);
}


void Game::debug() {

}