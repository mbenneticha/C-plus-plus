/****************************************
 * Function: hailstone.cpp
 * Author: Mariam Ben-Neticha
 * Date: 7/19/15
 * Description: This function will take the input positive integer and determine
                whether it is even or odd. If the integer is even, it will
                divide it by 2. If it is odd, it will multiply it by 3 and add
                1. The function will then reassign the new value to the original
                variable and continue these calculations based on if the integer
                is even or odd until it reaches the integer 1. The function will
                also count how many steps were taken to reach the ending value,
                1, and return this value. This function will not display
                anything.
****************************************/

#include <iostream>
using namespace std;

int  hailstone(int& a);     //references address of a
int start, counter;         //start = starting integer value; counter = tracks number of steps


int main() {
    cout << "Input some positive integer value." <<endl;
    cin >> start;
    hailstone(start);

return 0;
}

//function counts and returns number of steps it takes for integer to become 1
//if value is even, divide in half (as one step)
//if value is odd, multiply by 3 and add 1 (all as one step)
int hailstone(int& a) {
     int x = a;
     while (x > 1) {
	if (x % 2 == 0) {
	    x = (x/2);
	}
        else if (x % 2 != 0){
	    x = ((x * 3) + 1);
	}
        ++counter;
     }
     cout << counter <<endl;
     return counter;
}
