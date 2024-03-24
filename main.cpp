#include <iostream>
#include <time.h>  
#include "Classes/Game.h"

int main()
{
	srand(time(NULL));
	Game game; 
	game.loadHomeScreen();
	game.chooseOptions();

	return 0;
}
