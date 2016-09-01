

#ifndef Copy_hpp
#define Copy_hpp

#include "FileFilter.hpp"
#include <iostream>

class Copy: public FileFilter
{
public:
    Copy();
    char transform(char ch);
    
private:
    
};


#endif
