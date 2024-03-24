#pragma once

class Weapon {
public:
    // Constructeur
    Weapon(int damage);

    // Destructeur
    ~Weapon() {}

    // Accesseur pour obtenir les dégâts de l'arme
    int getDamage() const;

    // Mutateur pour définir les dégâts de l'arme
    void setDamage(int amount);

private:
    int mDamage; // Dégâts de l'arme
};