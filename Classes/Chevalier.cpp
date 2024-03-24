#include <iostream>
#include "Chevalier.h"

Chevalier::Chevalier() : Entity(20, 50, new Weapon(5), new ChargeCapacity()) {
    mClass = Class::CHEVALIER;
    mChargeAbility = static_cast<ChargeCapacity*>(mCapacity); // Convertit la capacité générale en capacité spécifique
}

Chevalier::~Chevalier()
{
}


std::string Chevalier::getClassName() const {
    return "Chevalier";
}

void Chevalier::useSpecialAbility(Entity* target) {
    if (mChargeAbility->useAbility()) {
        mWeapon->setDamage(mWeapon->getDamage() * 2);
        std::cout << "CAPACITE SPECIALE reussi " << std::endl;
    }
    else {
        std::cout << "CAPACITE SPECIALE echoue " << std::endl;
    }
}

void Chevalier::resetSpecialAbility(Entity* target) {
    if (mChargeAbility->resetAbility()) {
        mWeapon->setDamage(mWeapon->getDamage() / 2);
    }
}
