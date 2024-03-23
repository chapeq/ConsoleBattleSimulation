#include "Orc.h"
#include  <iostream>


Orc::Orc() : Entity(60, 0, new Weapon(8), new StunCapacity()) {
	mClass = Class::ORC;
	mStunAbility = static_cast<StunCapacity*>(mCapacity); // Convertit la capacité générale en capacité spécifique
}

Orc::~Orc() {
	delete mStunAbility;
}

std::string Orc::getClassName() const {
	return "Orc";
}

void Orc::useSpecialAbility(Entity* target) {
	if (mStunAbility->useAbility()) {
		target->setCanAttack(false); 
		std::cout << "CAPACITE SPECIALE reussi " << std::endl;
	}
	else {
		std::cout << "CAPACITE SPECIALE echoue " << std::endl;
	}
}

void Orc::resetSpecialAbility(Entity* target)
{
	if (mStunAbility->resetAbility())
	{
		target->setCanAttack(true);
	}
}


