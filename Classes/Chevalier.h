#pragma once
#include <string>
#include "Entity.h"
#include "ChargeCapacity.h"

class Chevalier : public Entity {
public:
    // Constructeur
    Chevalier();

    // Destructeur
    ~Chevalier() override;

    // M�thode pour obtenir le nom de la classe
    std::string getClassName() const final;

    // M�thodes pour utiliser et r�initialiser la capacit� sp�ciale
    void useSpecialAbility(Entity* target = nullptr) override;
    void resetSpecialAbility(Entity* target = nullptr) override;

private:
    ChargeCapacity* mChargeAbility; // Capacit� sp�ciale du chevalier
};