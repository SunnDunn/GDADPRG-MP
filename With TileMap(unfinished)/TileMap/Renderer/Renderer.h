#pragma once
#include "../AbstractComponent/AbstractComponent.h"

enum class RendererType { Custom, Sprite };

class Renderer : public AComponent {
public:
	Renderer(std::string name);
	virtual ~Renderer();
	void assignTargetWIndow(sf::RenderWindow* window);
	void assignDrawable(sf::Drawable* drawable);
	void setRednerStates(sf::RenderStates renderStates);

	void perform();

	static Renderer* Create(std::string name, std::string resourceName, RendererType rendererType);
	static Renderer* CreateSprite(std::string name, std::string resourceName);

protected:
	sf::Drawable* drawable = nullptr;

private:
	sf::RenderWindow* targetWindow = nullptr;
	sf::RenderStates renderStates = sf::RenderStates::Default;
};