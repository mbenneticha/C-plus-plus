
#ifndef Encryption_hpp
#define Encryption_hpp

#include "FileFilter.hpp"
#include <iostream>

class Encryption: public FileFilter
{
    
public:
    Encryption();
    Encryption(int kee);
    
    //function prompts user to enter integer key value
    int prompt_key();
    
    //function to encrypt a character
    char transform(char ch);
    
private:
    int key;

    
};

#endif
