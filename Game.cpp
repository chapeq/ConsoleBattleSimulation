#include "Game.h"
#include  <iostream>

Game::Game() : knight(new Chevalier()), orc(new Orc()) {}

Game::~Game()
{
	delete knight;
	delete orc;
}

void Game::playGame()
{

	while (knight->getHealth() > 0 && orc->getHealth > 0) {
		launchSpecialAbilities();
		combatRound();
		displayInfo();
	}

	if (knight->getHealth() <= 0) {
		std::cout << "L'orc a gagné!" << std::endl;
	}
	else {
		std::cout << "Le chevalier a gagné!" << std::endl;
	}
}


void Game::launchSpecialAbilities()
{
}

void Game::combatRound()
{
}

void Game::displayInfo() const
{
}
