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

    // Méthode pour obtenir le nom de la classe
    std::string getClassName() const final;

    // Méthodes pour utiliser et réinitialiser la capacité spéciale
    void useSpecialAbility(Entity* target = nullptr) override;
    void resetSpecialAbility(Entity* target = nullptr) override;

private:
    ChargeCapacity* mChargeAbility; // Capacité spéciale du chevalier
};