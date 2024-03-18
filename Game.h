#pragma once
#include "Chevalier.h"
#include "Orc.h"
class Game
{
    Game();
    ~Game();

    void playGame();

private:
    Chevalier* knight;
    Orc* orc;

    void launchSpecialAbilities();
    void combatRound();
    void displayInfo() const;
};

