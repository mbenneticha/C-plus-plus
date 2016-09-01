

#include "Encryption.hpp"
#include <iostream>


Encryption::Encryption()
{
}


//Constructor with integer key as parameter
Encryption::Encryption(int kee)
{
    key = kee;
}

//function prompts user to enter integer key value
int Encryption::prompt_key()
{
    int kee = 0;
    std::cout << "Enter an integer encryption key." <<std::endl;
    std::cin >> kee;
    return kee;
}


char Encryption::transform(char ch)
{
    return ((ch + key) % 26);
}

