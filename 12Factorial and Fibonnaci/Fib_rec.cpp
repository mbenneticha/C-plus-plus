//
// function code by Blaise Pascal
// code created on Jan 2011
// site: stackoverflow.com/questions/4586505/whats-the-term-for-double-recursion
// code used and cited by Mariam Ben-Neticha on Dec 3, 2015
//

#include <stdio.h>


//recursive Fibonacci
int Fibonacci_Rec(int n)
{
    if (n <= 2)
    {
        return 1;
    }
    else
    {
        return Fibonacci_Rec(n-1) + Fibonacci_Rec(n-2);
    }
}