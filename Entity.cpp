#include "Entity.h"
#include <iostream>


Entity::Entity(int health, int def, int damage, int abilityChargeTurns)
{
	m_health = health;
	m_defense = def;
	m_damage = damage;
	m_abilityChargeTurns = abilityChargeTurns;
}

int Entity::getHealth() const
{
	return m_health;
}
int Entity::getDefense() const
{
	return m_defense;
}
int Entity::getDamage() const
{
	return m_damage;
}

Entity::Class Entity::getClass() const
{
	return Class();
}

void Entity::attack()
{
}

void Entity::takeDamage(int damage)
{
	if (m_defense > 0) {
		if (m_defense >= damage) {
			m_defense -= damage;
		}
		else {
			m_health -= (damage - m_defense);
			m_defense = 0;
		}
	}
	else {
		m_health -= damage;
	}
}

bool Entity::isAlive() const
{
	if (m_health <= 0)
	{
		return false;
	}
	return true;
}

void Entity::showInfo() const
{
	std::cout << "[Class: " << getClassName() << "]\n";
	std::cout << "[Health: " << getHealth() << "]\n";
	std::cout << "[Armor: " << getDefense() << "]\n";
	std::cout << "[Damage: " << getDamage() << "]\n";
}

std::string Entity::getClassName(Entity::Class type)
{
	switch (type)
	{
	case Class::CHEVALIER:
		return "Chevalier";
	case Class::ORC:
		return "Orc";
	}
}