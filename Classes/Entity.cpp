#include <iostream>
#include "Entity.h"


Entity::Entity(int health, int def, Weapon* weapon, Capacity* capacity)
	: mHealth(health), mDefense(def), mWeapon(weapon), mCapacity(capacity), mClass(Class::NONE), canAttack(true) {}


Entity::~Entity() {
	delete mWeapon;
	delete mCapacity;
}

int Entity::getHealth() const {
	return mHealth;
}

int Entity::getDefense() const {
	return mDefense;
}

int Entity::getDamage() const {
	return mWeapon->getDamage();
}

bool Entity::getCanAttack() const {
	return canAttack;
}

void Entity::setCanAttack(bool value) {
	canAttack = value;
}

bool Entity::attack(Entity* target) {
	if (target && canAttack) {
		target->takeDamage(getDamage());
		return true;
	}
	return false;
}

void Entity::takeDamage(int damage) {
	if (mDefense > 0) {
		if (mDefense >= damage) {
			mDefense -= damage;
		}
		else {
			mHealth -= (damage - mDefense);
			mDefense = 0;
		}
	}
	else {
		mHealth -= damage;
	}
}

void Entity::defend() {
	if ((rand() % 100) < 50) {
		mDefense += 2;
		std::cout << "Defense augmente de 2 !" << std::endl;
	}
	else 
		std::cout << "Defense echoue ..." << std::endl;
}


void Entity::showInfo() const {
	std::cout << "[Class: " << getClassName() << "] ";
	std::cout << "[Health: " << getHealth() << "] ";
	std::cout << "[Armor: " << getDefense() << "] ";
	std::cout << "[Damage: " << getDamage() << "]\n";
}

void Entity::decreaseChargeTurns() {
	mCapacity->decreaseChargeTurns();
}
