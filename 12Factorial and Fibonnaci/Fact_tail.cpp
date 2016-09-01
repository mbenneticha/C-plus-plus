//
// function code from Lab 10 document by Terry Rooker
// code used and cited by Mariam Ben-Neticha on Dec 3, 2015
//

#include <stdio.h>


//Tail Recursive
long factorialHelper (int n, int result)
{
    if (n == 1)
    {
        return result;
    }
    else
    {
        return factorialHelper(n-1, n*result);
    }
}

long factorial(int n)
{
    return factorialHelper(n,1);
}
