

#include "PlayerIdentity.hpp"


bool same_subclass( Creature *c_1, Creature *c_2)
{
    if (typeid(*c_1) == typeid(*c_2))
    {
        return true;
    }
    else
        return false;
}