

#include "SearchBinary.hpp"
#include <fstream>

int search_redux(int value, std::string beg_sort, std::string mid_sort, std::string end_sort)
{
    int val = value;
    
    std::ifstream sort_beg_file;
    std::ifstream sort_mid_file;
    std::ifstream sort_end_file;
    
    sort_beg_file.open(beg_sort, std::ios::in);
    sort_mid_file.open(mid_sort, std::ios::in);
    sort_end_file.open(end_sort, std::ios::in);
    
    int beg_size = 21;
    int a[beg_size];
    
    int mid_size = 21;
    int b[mid_size];
    
    int end_size = 21;
    int c[end_size];
    
    
    //put values into array
    if (sort_beg_file)
    {
        int i = 0;
        while (!sort_beg_file.eof())
        {
            sort_beg_file >> a[i];
            i++;
        }
    }
    
    //search for value
    int beg_low = 0;
    int beg_high = beg_size - 1;
    while (beg_low <= beg_high)
    {
        int beg_mid = (beg_low + beg_high)/2;
        int beg_diff = a[beg_mid] - val;
        if (beg_diff == 0)
        {
            std::cout << "Early: Value " << val <<" is located at " << beg_mid << std::endl;
            break;
            //return beg_mid;
        }
        else if (beg_diff < 0)
            beg_low = beg_mid + 1;
        else
            beg_high = beg_mid - 1;
    }
    
    
    //put values into array
    if (sort_mid_file)
    {
        int i = 0;
        while (!sort_mid_file.eof())
        {
            sort_mid_file >> b[i];
            i++;
        }
    }
    //search for value
    int mid_low = 0;
    int mid_high = mid_size - 1;
    while (mid_low <= mid_high)
    {
        int mid_mid = (mid_low + mid_high)/2;
        int mid_diff = a[mid_mid] - val;
        if (mid_diff == 0)
        {
            std::cout << "Mid: Value " << val <<" is located at " << mid_mid << std::endl;
            break;
            //return mid_mid;
        }
        else if (mid_diff < 0)
            mid_low = mid_mid + 1;
        else
            mid_high = mid_mid - 1;
    }
    
    
    
    //put values into array
    if (sort_end_file)
    {
        int i = 0;
        while (!sort_end_file.eof())
        {
            sort_end_file >> c[i];
            i++;
        }
    }
    //search for value
    int end_low = 0;
    int end_high = end_size - 1;
    while (end_low <= end_high)
    {
        int end_mid = (end_low + end_high)/2;
        int end_diff = a[end_mid] - val;
        if (end_diff == 0)
        {
            std::cout << "End: Value " << val <<" is located at " << end_mid << std::endl;
            break;
            //return end_mid;
        }
        else if (end_diff < 0)
            end_low = end_mid + 1;
        else
            end_high = end_mid - 1;
    }
    
    return -1;
}