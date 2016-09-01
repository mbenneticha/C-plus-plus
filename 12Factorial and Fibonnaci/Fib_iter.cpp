//
// function by Diego on TalkBinary
// code created on Dec 2011
// site: talkbinary.com/programming/c/fibonacci-in-c/
// code used and cited by Mariam Ben-Neticha on Dec 3, 2015
//

#include <stdio.h>

//Iterative Fibonacci
int Fibonacci_Iter(int n)
{
    if ( n == 0 || n == 1 )
        return n;
    
    int fib1 = 0;
    int fib2 = 1;
    int fib = 0;
    
    for ( int i = 2; i <= n; i++ )
    {
        fib = fib1 + fib2;
        fib1 = fib2;
        fib2 = fib;
    }
    
    return fib;
}