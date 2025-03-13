#include "TextureManager.h"

TextureManager* TextureManager::sharedInstance = nullptr;

TextureManager* TextureManager::getInstance() {
	if (sharedInstance == nullptr) {
		sharedInstance = new TextureManager();
	}

	return sharedInstance;
}

void TextureManager::testFunction() {
	std::cout << "Texture manager singleton!" << std::endl;
}

void TextureManager::loadAll() {
	for (int i = 0; i < 8; i++) {
		std::string str_i = std::to_string(i);
		loadTexture("bed_" + str_i, "Media/Textures/Objects/bed000" + str_i + ".png");
		loadTexture("bench_" + str_i, "Media/Textures/Objects/bench000" + str_i + ".png");
		loadTexture("gift_" + str_i, "Media/Textures/Objects/boxGift_000" + str_i + ".png");
		loadTexture("coin_" + str_i, "Media/Textures/Objects/coin000" + str_i + ".png");
	}
	loadTexture("planePlayer", "Media/Textures/Eagle.png");
	loadTexture("cat", "Media/Textures/Cat.jpg");
}

void TextureManager::loadTexture(std::string key, std::string path) {
	sf::Texture* texture = new sf::Texture();
	texture->loadFromFile(path);
	textureMap[key] = texture;
}

sf::Texture* TextureManager::getTexture(std::string key) {
	if (textureMap[key] != nullptr) {
		return textureMap[key];
	}
	else {
		std::cout << "No texture found for " << key << std::endl;
		return nullptr;
	}
}