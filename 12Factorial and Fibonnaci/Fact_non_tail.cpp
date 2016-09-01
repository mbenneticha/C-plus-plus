//
// function code from Lab 10 document by Terry Rooker
// code used and cited by Mariam Ben-Neticha on Dec 3, 2015
//

#include <stdio.h>


//Not Tail Recursive
long rfactorial (int n)
{
    if (n == 1)
    {
        return 1;
    }
    else
    {
        return (n * rfactorial(n-1));
    }
}