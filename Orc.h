#pragma once
#include "Entity.h"
#include <string>

class Orc:public Entity
{
public:
    Orc();
    std::string getClassName() const final;

    void useSpecialAbility() override;
    void resetSpecialAbility() override;
};

