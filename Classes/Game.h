#pragma once
#include <string>
#include "Entity.h"
#include "Chevalier.h"
#include "Orc.h"

class Game {
public:
    Game(); // Constructeur
    ~Game(); // Destructeur

    void loadHomeScreen(); // M�thode pour afficher le texte du fichier d'�cran d'accueil (r�gles du jeu). 
    void chooseOptions();

private:
    Entity* mEntity1; // Pointeur vers la premi�re entit� (joueur 1)
    Entity* mEntity2; // Pointeur vers la deuxi�me entit� (joueur 2)

    void playGame(); // M�thode pour d�marrer le jeu
    void chooseCharacter(Entity*& entity, const std::string& playerName); // M�thode pour choisir la classe de l'entit�
};
