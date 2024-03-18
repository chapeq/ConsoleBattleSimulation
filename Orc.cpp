#include "Orc.h"

Orc::Orc() : Entity(60,0,8)
{   
    m_Class = Class::ORC;
}

std::string Orc::getClassName() const
{
    return "Orc";
}