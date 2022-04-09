#include "MapState.h"
#include "../MapCommand.h"
#include "../CommandExit.h"
#include "../../sdlutils/InputHandler.h"
#include "../../Logic/MapPoint.h"

MapState::MapState(Game* game) : State(game)
{
	registerCommands();
	string path = "Images/Mapa/imagenMiniMapa.png";
	backgroundTex_ = new Texture(game->getRenderer(), path);
}

MapState::~MapState()
{
	delete backgroundTex_;  backgroundTex_ = nullptr;
}

void MapState::update() {}

void MapState::draw()
{
	//Mapa
	SDL_Rect rectPanel = { 0,0,game->getWindowWidth(), game->getWindowHeight() };
	backgroundTex_->render(rectPanel);
	
	game->MapPoint()->setDimension(24, 24);
	game->MapPoint()->setPosition(game->minimapinfo_.X, game->minimapinfo_.Y);

	//Evento para colocar la baliza del mapa
	auto& ihdlr = ih();
	if (ihdlr.mouseButtonEvent()) {
		
		if (ihdlr.getMouseButtonState(InputHandler::MOUSEBUTTON::LEFT)==1) {
			SDL_GetMouseState(&x_, &y_);
			
			game->setPointerMapPuting(true);
			
			game->MapPoint()->setPosition((double)x_ - 12, (double)y_ - 12);//actualizo la pos
			
			game->minimapinfo_.X = (double)x_ - 12;
			game->minimapinfo_.Y = (double)y_ - 12;
		}
	}

	if (game->IsPointerMapPuting()) {//si esta puesto el punto lo pinto
		game->MapPoint()->draw();
	}
}

void MapState::next() {}

void MapState::registerCommands()
{
	commandFactory->add(new MapCommand());
	commandFactory->add(new CommandExit());
}