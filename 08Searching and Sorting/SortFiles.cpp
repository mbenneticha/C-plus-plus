

#include "SortFiles.hpp"
#include <fstream>

void bubble_sort(std::string beg, std::string mid, std::string end, std::string beg_sort, std::string mid_sort, std::string end_sort)
{
    std::ifstream beg_file;
    std::ifstream mid_file;
    std::ifstream end_file;
    
    std::ofstream sort_beg_file;
    std::ofstream sort_mid_file;
    std::ofstream sort_end_file;
    
    beg_file.open(beg, std::ios::in);
    mid_file.open(mid, std::ios::in);
    end_file.open(end, std::ios::in);
    
    sort_beg_file.open(beg_sort, std::ios::out);
    sort_mid_file.open(mid_sort, std::ios::out);
    sort_end_file.open(end_sort, std::ios::out);
    
    int beg_size = 21;
    int a[beg_size];
    
    int mid_size = 21;
    int b[mid_size];
    
    int end_size = 21;
    int c[end_size];
    
    
    //sort early_zero.txt
    //put values into array
    if (beg_file)
    {
        int i = 0;
        while (!beg_file.eof())
        {
            beg_file >> a[i];
            i++;
        }
    }
    //sort values
    for (int i = (beg_size-1); i >=0; i--)
    {
        for (int j = 1; j<=i; j++)
        {
            if(a[j-1] > a[j])
            {
                int temp = a[j-1];
                a[j-1] = a[j];
                a[j] = temp;
            }
        }
    }
    //put array into sorted file
    for (int i = 0; i < 21; i++)
    {
        sort_beg_file << a[i] <<std::endl;
    }
    
    
    //sort mid_zero.txt
    //put values into array
    if (mid_file)
    {
        int i = 0;
        while (!mid_file.eof())
        {
            mid_file >> b[i];
            i++;
        }
    }
    //sort values
    for (int i = (mid_size-1); i >=0; i--)
    {
        for (int j = 1; j<=i; j++)
        {
            if(b[j-1] > b[j])
            {
                int temp = b[j-1];
                b[j-1] = b[j];
                b[j] = temp;
            }
        }
    }
    //put array into sorted file
    for (int i = 0; i < 21; i++)
    {
        sort_mid_file << b[i] <<std::endl;
    }
   
    
    
    
    //sort end_zero.txt
    //put values into array
    if (end_file)
    {
        int i = 0;
        while (!end_file.eof())
        {
            end_file >> c[i];
            i++;
        }
    }
    //sort values
    for (int i = (end_size-1); i >=0; i--)
    {
        for (int j = 1; j<=i; j++)
        {
            if(c[j-1] > c[j])
            {
                int temp = c[j-1];
                c[j-1] = c[j];
                c[j] = temp;
            }
        }
    }
    //put array into sorted file
    for (int i = 0; i < 21; i++)
    {
        sort_end_file << c[i] <<std::endl;
    }
}