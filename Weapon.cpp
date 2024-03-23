#include "Weapon.h"

Weapon::Weapon(int damage) : mDamage(damage) {}

int Weapon::getDamage() const {
    return mDamage;
}

void Weapon::setDamage(int amount) {
    mDamage = amount;
}