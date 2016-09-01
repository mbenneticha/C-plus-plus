

#include "FileFilter.hpp"
#include "Copy.hpp"
#include "Uppercase.hpp"
#include "Encryption.hpp"
#include <iostream>
#include <fstream>

int main()
{
    char temp;
    int key_value;
    std::ifstream input_file;
    std::ofstream original_file;
    std::ofstream copy_file;
    std::ofstream upper_file;
    std::ofstream encrypt_file;
    
    original_file.open("original_test.txt", std::ios::out);
    encrypt_file.open("encrypt_test.txt", std::ios::out);
    copy_file.open("copy_test.txt", std::ios::out);
    upper_file.open("upper_test.txt", std::ios::out);
    
    Copy make_copy;
    Uppercase make_upper;
    Encryption make_encrypt;
    
    
    std::cout << "Enter a word to encrypt. Enter '#' at end of input." <<std::endl;

    do {
        temp = std::cin.get();
        if(temp != '#')
        original_file.put(temp);
    } while (temp != '#');
    
    //close original file to avoid tampering
    original_file.close();
    
    //gets user input prompt key
    key_value = make_encrypt.prompt_key();
    
    
    //open original file
    input_file.open("original_test.txt", std::ios::in);
    
    //copies original file
    make_copy.doFilter(input_file, copy_file);
    
    //makes file uppercase
    make_upper.doFilter(input_file, upper_file);
    
    //encrypts file
    make_encrypt.doFilter(input_file, encrypt_file);
    

    //close files
    input_file.close();
    copy_file.close();
    upper_file.close();
    encrypt_file.close();
    
    return 0;
}
