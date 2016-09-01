
#ifndef Uppercase_hpp
#define Uppercase_hpp

#include "FileFilter.hpp"
#include <iostream>

class Uppercase: public FileFilter
{
    
public:
    Uppercase();
    char transform(char ch);
    
private:
    
};

#endif
