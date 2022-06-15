#include "Game.h"

using namespace sf;


int main()
{
	srand(static_cast<unsigned>(time(0))); //randomowe wartosci

	//Zainicjuj obiekt w grze
	Game game;

	while (game.running()) //render okna gdy gra jest wlaczona
	{
		game.update();
		game.render();
	}

	return 0;
}