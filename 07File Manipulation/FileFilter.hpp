

#ifndef FileFilter_hpp
#define FileFilter_hpp

#include <iostream>

class FileFilter
{
public:
    FileFilter();
    //function to filter
    //read a char, transform using transform(), write char to output file
    void doFilter(std::ifstream &in, std::ofstream &out);
    virtual char transform (char ch) = 0;
    
private:
    
};

#endif
