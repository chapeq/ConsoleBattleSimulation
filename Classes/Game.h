#pragma once
#include <string>
#include "Entity.h"
#include "Chevalier.h"
#include "Orc.h"

class Game {
public:
    Game(); // Constructeur
    ~Game(); // Destructeur

    void loadHomeScreen(); // Méthode pour afficher le texte du fichier d'écran d'accueil (régles du jeu). 
    void chooseOptions();

private:
    Entity* mEntity1; // Pointeur vers la première entité (joueur 1)
    Entity* mEntity2; // Pointeur vers la deuxième entité (joueur 2)

    void playGame(); // Méthode pour démarrer le jeu
    void chooseCharacter(Entity*& entity, const std::string& playerName); // Méthode pour choisir la classe de l'entité
};
