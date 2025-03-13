#include "Renderer.h"
#include "SpriteRenderer.h"

Renderer::Renderer(std::string name) : AComponent(name, AComponent::Renderer) {
	this->type = AComponent::Renderer;
	this->renderStates = sf::RenderStates::Default;
}

Renderer::~Renderer() {
	AComponent::~AComponent();
}

void Renderer::assignTargetWIndow(sf::RenderWindow* window) {
	this->targetWindow = window;
}

void Renderer::assignDrawable(sf::Drawable* drawable) {
	this->drawable = drawable;
}

void Renderer::setRednerStates(sf::RenderStates renderStates) {
	this->renderStates = renderStates;
}


void Renderer::perform() {
	this->targetWindow->draw(*this->drawable, this->renderStates);
}


Renderer* Renderer::Create(std::string name, std::string resourceName, RendererType rendererType) {
	switch (rendererType) {
	case RendererType::Sprite:
		return new SpriteRenderer(name, resourceName);
		break;
	case RendererType::Custom:
	default:
		return new Renderer(name);
		break;
	}
}

Renderer* Renderer::CreateSprite(std::string name, std::string resourceName) {
	return Renderer::Create(name, resourceName, RendererType::Sprite);
}
