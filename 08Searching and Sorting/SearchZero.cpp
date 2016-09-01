

#include "SearchZero.hpp"
#include <fstream>

int search_value(int val, std::string beg, std::string mid, std::string end)
{
    std::ifstream beg_file;
    std::ifstream mid_file;
    std::ifstream end_file;
    
    beg_file.open(beg, std::ios::in);
    mid_file.open(mid, std::ios::in);
    end_file.open(end, std::ios::in);
    
    int search_val = val;
    int beg_size = 21;
    int a[beg_size];
    
    int mid_size = 21;
    int b[mid_size];
    
    int end_size = 21;
    int c[end_size];
    
    
    //search early_zero.txt file
    if (beg_file)
    {
        int i = 0;
        while (!beg_file.eof())
        {
            beg_file >> a[i];
            i++;
        }
    }
    
    for (int i = 0; i < beg_size; i++)
    {
        if (a[i] == search_val)
        {
            std::cout << "Early: " <<search_val <<" is located at " << i << std::endl;
           // return i;
        }
    }

    
    //search mid_zero.txt file
    if (mid_file)
    {
        int i = 0;
        while (!mid_file.eof())
        {
            mid_file >> b[i];
            i++;
        }
    }
    
    for (int i = 0; i < mid_size; i++)
    {
        if (b[i] == search_val)
        {
            std::cout << "Mid: " <<search_val <<" is located at " << i << std::endl;
            //return i;
        }
    }
    
    
    //search end_zero.txt file
    if (end_file)
    {
        int i = 0;
        while (!end_file.eof())
        {
            end_file >> c[i];
            i++;
        }
    }
    
    for (int i = 0; i < end_size; i++)
    {
        if (c[i] == search_val)
        {
            std::cout << "End: " <<search_val <<" is located at " << i << std::endl;
            //return i;
        }
    }
    
    return -1;
}
