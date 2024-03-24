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

    // Méthode pour obtenir le nom de la classe
    std::string getClassName() const final;

    // Méthodes pour utiliser et réinitialiser la capacité spéciale
    void useSpecialAbility(Entity* target) override;
    void resetSpecialAbility(Entity* target) override;

private:
    StunCapacity* mStunAbility; // Capacité spéciale de l'Orc
};
