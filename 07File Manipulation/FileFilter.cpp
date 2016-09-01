

#include "FileFilter.hpp"
#include <iostream>
#include <fstream>


FileFilter::FileFilter()
{
}

//filter function
void FileFilter::doFilter(std::ifstream &in, std::ofstream &out)
{
    char ch;
    char transform_ch;
    out.clear();
    in.clear();
    in.seekg(0, std::ios::beg);
    in.get(ch);
    
    while (!in.fail())
    {
        transform_ch = transform(ch);
        out.put(transform_ch);
        in.get(ch);
    }
}
