#pragma once
#include "Capacity.h"
#include "Weapon.h"
#include <string>

class Entity {
public:
    enum class Class {
        CHEVALIER, ORC, NONE
    };

    // Constructeur initialisant les membres de données
    Entity(int health, int def, Weapon* weapon, Capacity* capacity);

    // Destructeur pour libérer la mémoire des objets Weapon et Capacity
    virtual ~Entity();

    // Accesseurs pour les attributs mHealth, mDefense et les dégâts infligés par l'arme
    int getHealth() const;
    int getDefense() const;
    int getDamage() const;

    // Accesseur pour l'état d'attaque de l'entité
    bool getCanAttack() const;

    // Mutateur pour l'état d'attaque de l'entité
    void setCanAttack(bool value);

    // Fonction pour attaquer une autre entité
    bool attack(Entity* target);

    // Fonction pour infliger des dégâts à l'entité en fonction de sa défense
    void takeDamage(int damage);

    // Fonction pour afficher les informations de l'entité
    void showInfo() const;

    // Fonction pour diminuer le nombre de tours de charge restants de la capacité spéciale
    void decreaseChargeTurns();

    // Méthodes virtuelles pures pour obtenir le nom de la classe et utiliser/réinitialiser la capacité spéciale
    virtual std::string getClassName() const = 0;
    virtual void useSpecialAbility(Entity* target = nullptr) = 0;
    virtual void resetSpecialAbility(Entity* target = nullptr) = 0;

protected:
    Class mClass;           // Classe de l'entité
    Capacity* mCapacity;    // Capacité spéciale de l'entité
    Weapon* mWeapon;        // Arme de l'entité

private:
    int mHealth;            // Points de vie de l'entité
    int mDefense;           // Valeur de défense de l'entité
    bool canAttack;         // Indique si l'entité peut attaquer

};