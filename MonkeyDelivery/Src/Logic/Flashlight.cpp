#include "Flashlight.h"
#include "Player.h"

Flashlight::Flashlight(Texture* tex) : active(false), InventoryObject(tex)
{
}

bool Flashlight::useObject() {
	if (!active) {
		cout << " Hola linternita";
		player_->changeFLState(true);
	}
	else {
		cout << "Adios linternita";
		player_->changeFLState(false);
	}
	cout << endl;
	active = !active;
	return false; //devolvemos false indicando que el objeto no debe destruirse tras ser usado
}

