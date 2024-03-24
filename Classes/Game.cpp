#include <iostream>
#include <fstream>
#include "Game.h"

Game::Game() : mEntity1(nullptr), mEntity2(nullptr) {
}

Game::~Game() {
	delete mEntity1;
	delete mEntity2;
}

void Game::loadHomeScreen()
{
	std::ifstream file("data/HomeRules.txt");
	if (file.is_open()) {
		std::string line;
		while (std::getline(file, line)) {
			std::cout << line << std::endl;
		}
		file.close();
	}
	else {
		std::cerr << "Erreur : Impossible d'ouvrir le fichier game_rules.txt" << std::endl;
	}
}

void Game::chooseCharacter(Entity*& entity, const std::string& playerName) {
	std::cout << "Choisissez la classe pour le joueur " << playerName << " :" << std::endl;
	std::cout << "1. Chevalier" << std::endl;
	std::cout << "2. Orc" << std::endl;
	int choice;
	std::cin >> choice;
	switch (choice) {
	case 1:
		entity = new Chevalier();
		break;
	case 2:
		entity = new Orc();
		break;
	default:
		std::cout << "Choix invalide. Chevalier sera choisi par défaut." << std::endl;
		entity = new Chevalier();
		break;
	}
}

void Game::chooseOptions()
{

		std::cout << " ****  MENU ****"<< std::endl;
		std::cout << "1. Lancer une nouvelle partie" << std::endl;
		std::cout << "2. Quitter le jeu" << std::endl;
		std::cout << "Choix : ";
		int choice;
		std::cin >> choice;
		switch (choice) {
		case 1:
			playGame();
			break;
		case 2:
			std::cout << "Merci d'avoir joue ! Au revoir !" << std::endl;
			break;
		default:
			std::cout << "Choix invalide. Veuillez choisir une option valide." << std::endl;
			break;
		}
	
}

void Game::playGame() {

	chooseCharacter(mEntity1, "1");
	chooseCharacter(mEntity2, "2");

	if (!mEntity1 || !mEntity2) {
		std::cout << "Erreur : Veuillez choisir les classes des joueurs avant de commencer le jeu." << std::endl;
		return;
	}

	int round = 1;

	while (mEntity1->getHealth() > 0 && mEntity2->getHealth() > 0) {
		std::cout << "Tour " << round << std::endl;
		std::cout << "------------------------------------" << std::endl;

		mEntity1->showInfo();
		mEntity2->showInfo();

		std::cout << "Choisissez une action pour Joueur 1 " << mEntity1->getClassName() << " :" << std::endl;
		std::cout << "1. Utiliser la capacite speciale" << std::endl;
		std::cout << "2. Augmenter sa defense" << std::endl;

		int choice;
		std::cin >> choice;

		switch (choice) {
		case 1:
			mEntity1->useSpecialAbility(mEntity2);
			break;
		case 2:
			mEntity1->defend();
			break;
		default:
			std::cout << "Choix invalide. Joueur 1 augmentera sa defense par defaut." << std::endl;
			mEntity1->defend();
			break;
		}

		std::cout << "Choisissez une action pour Joueur 2 " << mEntity2->getClassName() << " :" << std::endl;
		std::cout << "1. Utiliser la capacite speciale" << std::endl;
		std::cout << "2. Augmenter sa defense" << std::endl;

		int choice2;
		std::cin >> choice2;

		switch (choice2) {
		case 1:
			mEntity2->useSpecialAbility(mEntity1);
			break;
		case 2:
			mEntity2->defend();
			break;
		default:
			std::cout << "Choix invalide. Joueur 2 augmentera sa defense par defaut." << std::endl;
			mEntity2->defend();
			break;
		}

		mEntity1->showInfo();
		mEntity2->showInfo();

		if (mEntity1->attack(mEntity2))
		{
			std::cout << "Joueur 1 attaque Joueur 2 ! " << std::endl;
		}
		else
			std::cout << "Joueur 1 attaque Joueur 2 mais echoue ... " << std::endl;

		if (mEntity2->attack(mEntity1))
		{
			std::cout << "Joueur 2 attaque Joueur 1 ! " << std::endl;
		}
		else
			std::cout << "Joueur 2 attaque Joueur 1 mais echoue ... " << std::endl;

		mEntity1->resetSpecialAbility(mEntity2);
		mEntity2->resetSpecialAbility(mEntity1);

		mEntity1->decreaseChargeTurns();
		mEntity2->decreaseChargeTurns();

		std::cout << "------------------------------------" << std::endl;

		++round;
	}

	// Affichage du résultat
	std::cout << " ---- Le jeu est termine ! ------- " << std::endl;
	if (mEntity1->getHealth() <= 0) {
		std::cout << "Joueur 2 " << mEntity2->getClassName() << " a gagne!" << std::endl;
	}
	else {
		std::cout << "Joueur 1 " << mEntity1->getClassName() << " a gagne!" << std::endl;
	}

	chooseOptions();
}