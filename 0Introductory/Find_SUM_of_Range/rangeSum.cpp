/****************************************
 * Program: rangeSum.cpp
 * Author: Mariam Ben-Neticha
 * Date: 7/7/15
 * Desciption: This is an interactive program that asks the user to enter 
 * two integer values. The program will then take the sum of all the 
 * integers that fall between the entered integers and print the total sum
 * on the screen.
 ****************************************/

#include <iostream>
using namespace std;

int main() { 

    int range1, range2, Counter, sum=0, Sum=0;

    //Prompt user to enter two integers.
    cout << "Please enter two integers." <<endl;
    cin >> range1;
    cin >> range2; 


    //Determine which integer value is larger than the other.
    //Larger integer will be the upper end of the range.
    //Smaller number will be the lower end of the range. 
    if (range1 > range2) {
	for (Counter = range2; Counter <= range1; Counter++) {
	    sum += Counter;  
	}

	cout << "The sum of the values in that range is:" <<endl;
	cout << sum <<endl;
    }

    else if (range2 > range1) {
	for (Counter = range1; Counter <= range2; Counter++) {
	    Sum += Counter; 
	}

	cout << "The sum of the values in that range is:" <<endl;
	cout << Sum <<endl;
    }

    else {
	cout << "The sum of the values in that range is:" <<endl;
	cout << range1+range2 <<endl;
    }

return 0;
}
