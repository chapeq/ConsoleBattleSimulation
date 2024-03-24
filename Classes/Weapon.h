#pragma once

class Weapon {
public:
    // Constructeur
    Weapon(int damage);

    // Destructeur
    ~Weapon() {}

    // Accesseur pour obtenir les d�g�ts de l'arme
    int getDamage() const;

    // Mutateur pour d�finir les d�g�ts de l'arme
    void setDamage(int amount);

private:
    int mDamage; // D�g�ts de l'arme
};