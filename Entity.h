#pragma once
#include "Capacity.h"
#include "Weapon.h"
#include <string>

class Entity {
public:
    enum class Class {
        CHEVALIER, ORC, NONE
    };

    // Constructeur initialisant les membres de donn�es
    Entity(int health, int def, Weapon* weapon, Capacity* capacity);

    // Destructeur pour lib�rer la m�moire des objets Weapon et Capacity
    virtual ~Entity();

    // Accesseurs pour les attributs mHealth, mDefense et les d�g�ts inflig�s par l'arme
    int getHealth() const;
    int getDefense() const;
    int getDamage() const;

    // Accesseur pour l'�tat d'attaque de l'entit�
    bool getCanAttack() const;

    // Mutateur pour l'�tat d'attaque de l'entit�
    void setCanAttack(bool value);

    // Fonction pour attaquer une autre entit�
    bool attack(Entity* target);

    // Fonction pour infliger des d�g�ts � l'entit� en fonction de sa d�fense
    void takeDamage(int damage);

    // Fonction pour afficher les informations de l'entit�
    void showInfo() const;

    // Fonction pour diminuer le nombre de tours de charge restants de la capacit� sp�ciale
    void decreaseChargeTurns();

    // M�thodes virtuelles pures pour obtenir le nom de la classe et utiliser/r�initialiser la capacit� sp�ciale
    virtual std::string getClassName() const = 0;
    virtual void useSpecialAbility(Entity* target = nullptr) = 0;
    virtual void resetSpecialAbility(Entity* target = nullptr) = 0;

protected:
    Class mClass;           // Classe de l'entit�
    Capacity* mCapacity;    // Capacit� sp�ciale de l'entit�
    Weapon* mWeapon;        // Arme de l'entit�

private:
    int mHealth;            // Points de vie de l'entit�
    int mDefense;           // Valeur de d�fense de l'entit�
    bool canAttack;         // Indique si l'entit� peut attaquer

};