#pragma once
#include <string>
#include "Entity.h"
#include "StunCapacity.h"

class Orc : public Entity {
public:
    // Constructeur
    Orc();

    // Destructeur
    ~Orc() override;

    // M�thode pour obtenir le nom de la classe
    std::string getClassName() const final;

    // M�thodes pour utiliser et r�initialiser la capacit� sp�ciale
    void useSpecialAbility(Entity* target) override;
    void resetSpecialAbility(Entity* target) override;

private:
    StunCapacity* mStunAbility; // Capacit� sp�ciale de l'Orc
};
