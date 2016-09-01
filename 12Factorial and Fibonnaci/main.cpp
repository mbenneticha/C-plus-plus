

#include "functions.hpp"

#include <iostream>
#include <cstdlib>
#include <ctime>


int main()
{
    int menu;
    do {
        display_menu();
        std::cin >> menu;
        
        if (menu == 1)
        {
            //Prompt user for value
            int value;
            std::cout << "Input a value to calculate using Fibonnaci sequence." <<std::endl;
            std::cin >> value;
            
            clock_t start, end;
            
            //measure run-time for Recursive Fibonacci
            int fib_rec;
            start = clock();
            std::cout <<"start " <<start <<std::endl;
            fib_rec = Fibonacci_Rec(value);
            end = clock();
            std::cout <<"end " <<end <<std::endl;
            std::cout <<"Recursive Fibonacci at " << value <<": " << fib_rec <<std::endl;
            std::cout <<"It took me " << (end-start) << " clicks " <<(((float)(end-start)*1000)/CLOCKS_PER_SEC ) <<" ms."  <<std::endl;
            
            //measure run-time for Iterative Fibonacci
            long fib_iter;
            start = clock();
            fib_iter = Fibonacci_Iter(value);
            end = clock();
            std::cout <<"Iterative Fibonacci at " << value <<": " <<fib_iter <<std::endl;
            std::cout <<"It took me " << (end-start) << " clicks " <<(((float)(end-start)*1000)/CLOCKS_PER_SEC) <<" ms."  <<std::endl;
            
            
            //Prompt user for a value
            int number;
            std::cout <<std::endl;
            std::cout <<"Input a value to calculate using Factorials." <<std::endl;
            std::cin >> number;
            
            //measure run-time for Tail-Recursive Factorial
            long tail_fac;
            start = clock();
            tail_fac = factorial(number);
            end = clock();
            std::cout <<"Tail Factorial of " << number <<": " <<tail_fac <<std::endl;
            std::cout <<"It took me " << (end-start) << " clicks " <<(((float)(end-start)*1000)/CLOCKS_PER_SEC ) <<" ms."  <<std::endl;
            
            
            //measure run-time for Non-Tail Recursive Factorial
            long non_tail_fac;
            start = clock();
            non_tail_fac = rfactorial(number);
            end = clock();
            std::cout <<"Non-Tail Factorial of " << number <<": " <<non_tail_fac <<std::endl;
            std::cout <<"It took me " << (end-start) << " clicks " <<(((float)(end-start)*1000)/CLOCKS_PER_SEC ) <<" ms."  <<std::endl;
        }
        else if (menu == 2)
        {
            std::cout <<"Program Ended." <<std::endl;
            return 0;
        }
        else
        {
            std::cout <<"Please enter a number corrseponding to a valid option." <<std::endl;
        }
        
    } while (menu != 2);
    
    return 0;
}
