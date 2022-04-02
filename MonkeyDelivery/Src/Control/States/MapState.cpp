#include "MapState.h"
#include "../MapCommand.h"
#include "../CommandExit.h"
#include "../../sdlutils/InputHandler.h"

MapState::MapState(Game* game) : State(game)
{
	registerCommands();
	string path = "../Images/Mapa/imagenMiniMapa.png";
	backgroundTex_ = new Texture(game->getRenderer(), path);

	path = "../Images/Mapa/marcador.png";
	pointTex_ = new Texture(game->getRenderer(), path);
}

MapState::~MapState()
{
	delete backgroundTex_;  backgroundTex_ = nullptr;
	delete pointTex_;       pointTex_ = nullptr;
}

void MapState::update()
{
}

void MapState::draw()
{
	SDL_Rect rectPanel = { 0,0,game->getWindowWidth(), game->getWindowHeight() };
	backgroundTex_->render(rectPanel);

	SDL_Rect rectPoint = { x_ - 50, y_ - 50, 100, 100 };

	auto& ihdlr = ih();
	if (ihdlr.mouseButtonEvent()) {
		
		if (ihdlr.getMouseButtonState(InputHandler::MOUSEBUTTON::LEFT)==1) {
			SDL_GetMouseState(&x_, &y_);
			put = true;
			rectPoint = { x_-50, y_ -50, 100, 100 };
		}
	}

	if (put) {
		pointTex_->render(rectPoint);
	}
}

void MapState::next()
{
}

void MapState::registerCommands()
{
	commandFactory->add(new MapCommand());
	commandFactory->add(new CommandExit());
}