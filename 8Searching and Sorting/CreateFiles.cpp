

#include "CreateFiles.hpp"
#include <fstream>
#include <cstdlib>
#include <cmath>
#include <ctime>

void create_file(std::string name, std::string beg, std::string mid, std::string end)
{
    std::ofstream out_file;
    std::ofstream beg_file;
    std::ofstream mid_file;
    std::ofstream end_file;
    
    out_file.open(name, std::ios::out);
    beg_file.open(beg, std::ios::out);
    mid_file.open(mid, std::ios::out);
    end_file.open(end, std::ios::out);
    
    
    unsigned seed;
    seed = time_t(0);
    srand(seed);
    
    
    int number;
    //input 20 random numbers into the file
    for (int i = 0; i < 19 ; i++)
    {
        number = (rand() % 9) + 1;
        out_file << number <<std::endl;
    }
    number = (rand() % 9) + 1;
    out_file << number;
    
    out_file.close();
    
    //open file as ifstream
    std::ifstream in_file;
    in_file.open(name, std::ios::in);
    
    //create array of size 21, we will input a zero
    int a[21];
    int i = 0;
    
    //put file values into array
    if (in_file)
    {
        while (!in_file.eof())
        {
            in_file >> a[i];
            i++;
        }
    }
    
    //insert zero at start of this file
    beg_file << 0 <<std::endl;
    
    //insert all values from in_file into these two files
    for (int i = 0; i < 20; i++)
    {
        beg_file << a[i] <<std::endl;
        end_file << a[i] <<std::endl;
    }
    
    //insert zero at end of this file
    end_file << 0 <<std::endl;
    
    //insert half of values from in_file into this file
    for (int i = 0; i < 10; i++)
    {
         mid_file << a[i] <<std::endl;
    }
    //insert zero into this file
    mid_file << 0 <<std::endl;
    //insert second half of values from in_file into this file
    for (int i = 10; i < 20; i++)
    {
        mid_file << a[i] <<std::endl;
    }
    
    //close all files
    in_file.close();
    beg_file.close();
    mid_file.close();
    end_file.close();
}

