#pragma once
#include "Entity.h"
#include <string>

class Chevalier:public Entity
{
public:
    Chevalier();
    std::string getClassName() const final;

    void useSpecialAbility() override;
    void resetSpecialAbility() override;
};

