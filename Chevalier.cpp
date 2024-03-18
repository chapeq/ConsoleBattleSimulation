#include "Chevalier.h"

Chevalier::Chevalier() :Entity(20, 50, 5, 3)
{
	m_Class = Class::CHEVALIER;

}

std::string Chevalier::getClassName() const
{
	return "Chevalier";
}

void Chevalier::useSpecialAbility() {
	if (m_abilityChargeTurns == 0) {
		damage *= 2;
	}
	m_abilityChargeTurns = 3;

}

void Chevalier::resetSpecialAbility() {
	if (m_abilityChargeTurns > 0)
	{
		m_abilityChargeTurns--;
	}
	if (m_abilityChargeTurns == 0) {
		damage /= 2;
	}
}