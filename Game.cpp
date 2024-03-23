#include "Game.h"
#include <iostream>
#include <ctime>

Game::Game() {
    mKnight = new Chevalier();
    mOrc = new Orc();

    std::srand(static_cast<unsigned int>(std::time(nullptr)));
}

Game::~Game() {
    delete mKnight;
    delete mOrc;
}

void Game::playGame() {
    int round = 1;

    while (mKnight->getHealth() > 0 && mOrc->getHealth() > 0) {
        std::cout << "Tour " << round << std::endl;
        std::cout << "------------------------------------" << std::endl;

        mKnight->showInfo();
        mOrc->showInfo();

        std::cout << "Le chevalier utilise CAPACITE SPECIALE ! " << std::endl;
        mKnight->useSpecialAbility();

        std::cout << "L'Orc utilise CAPACITE SPECIALE !" << std::endl;
        mOrc->useSpecialAbility(mKnight);

        mKnight->showInfo();
        mOrc->showInfo();

        if (mKnight->attack(mOrc)) {
            std::cout << "Le chevalier attaque l'orc " << std::endl;
        }
        if (mOrc->attack(mKnight)) {
            std::cout << "L'Orc attaque le chevalier  " << std::endl;
        }

        mKnight->showInfo();
        mOrc->showInfo();

        mKnight->resetSpecialAbility();
        mOrc->resetSpecialAbility(mKnight);

        mKnight->decreaseChargeTurns();
        mOrc->decreaseChargeTurns();

        std::cout << "------------------------------------" << std::endl;

        ++round;
    }

    // Affichage du résultat
    std::cout << "Le jeu est terminé!" << std::endl;
    if (mKnight->getHealth() <= 0) {
        std::cout << "L'orc a gagné!" << std::endl;
    }
    else {
        std::cout << "Le chevalier a gagné!" << std::endl;
    }
}

