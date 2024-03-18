#pragma once
class Entity
{
public:
	enum class Class {
		CHEVALIER, ORC
	};

	Entity(int health, int def, int damage, int abilityChargeTurns);
	virtual ~Entity() = default;

	int getHealth() const;
	int getDefense() const;
	int getDamage() const;
	Class getClass() const;

	void attack();
	void takeDamage(int damage);
	bool isAlive() const;
	void showInfo() const;
	virtual std::string getClassName() const = 0;
	static std::string getClassName(Class type);

	virtual void useSpecialAbility() = 0;
	virtual void resetSpecialAbility() = 0;

private : 
	int m_health;
	int m_defense;
	int m_damage; 

protected:
	Class m_Class;
	int m_abilityChargeTurns;


};

