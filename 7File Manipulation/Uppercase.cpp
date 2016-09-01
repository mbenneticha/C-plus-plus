

#include "Uppercase.hpp"
#include <iostream>

Uppercase::Uppercase()
{
}

char Uppercase::transform(char ch)
{
    return toupper(ch);
}