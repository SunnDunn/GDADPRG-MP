#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <unordered_map>

class TextureManager {
public:
	static TextureManager* getInstance();
	void loadAll();
	sf::Texture* getTexture(std::string);
	void testFunction();

private:
	TextureManager() {};
	TextureManager(TextureManager const&) {}
	TextureManager& operator=(TextureManager const&) {};
	static TextureManager* sharedInstance;

	void loadTexture(std::string, std::string);
	std::unordered_map<std::string, sf::Texture*> textureMap;
};