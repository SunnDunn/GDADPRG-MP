#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "GameObjectManager/GameObjectManager.h"
#include "TextureManager/TextureManager.h"
#include "Entity/Entity.h"

class Game {
public:
    Game();
    void run();

    static const int WINDOW_WIDTH = 800;
    static const int WINDOW_HEIGHT = 500;
private:
    void processEvents();
    void update(sf::Time);
    void render();

    void addEntity(std::string key, float x, float y);

    void drawObjects();

    void debug();
    sf::RenderWindow mWindow;
    sf::FloatRect bounds;

    sf::Shape* shape;

    float tick = 1.f;

    bool mIsMovingUp = false;
    bool mIsMovingDown = false;
    bool mIsMovingLeft = false;
    bool mIsMovingRight = false;
    bool mIsMousePress = false;
    bool mIsNumPressed = false;
    
    const sf::Time TimePerFrame = sf::seconds(1.0f / 60.0f);
    std::vector<Entity*> mEntityList;
};
