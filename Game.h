#pragma once
#include "Chevalier.h"
#include "Orc.h"

class Game {
public:
    // Constructeur
    Game();

    // Destructeur
    ~Game();

    // Méthode implémentant la boucle de jeu
    void playGame();

private:
    Chevalier* mKnight; // Instance du chevalier
    Orc* mOrc; // Instance de l'Orc
};
