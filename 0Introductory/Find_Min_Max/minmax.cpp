/*****************************************
 * Program: minmax.cpp
 * Author:Mariam Ben-Neticha
 * Date: 7/7/15
 * Description: This is an interactive program that asks the user how many
 * integer values they want to enter. Then the program asks the user to
 * enter the specified amount of integers. Finally, the program will print 
 * on screen the minimum value entered and the maximum value entered.
 *****************************************/

#include <iostream>
using namespace std;

int main() {
    int howMany, num, max, min;

    //Prompt user to enter how many integers they want to enter.
    cout << "How many integers would you like to enter?" <<endl;
    cin >> howMany;

    if (howMany == 0 ) {
	return 0;
    }

    //Prompt user to enter specified number of integers
    cout << "Please enter " <<howMany << " integers." <<endl;   

	for(int x=0; x<howMany; x++) {
	   cin >> num;
	   if (x == 0) {
		max = min = num;
    	   }	
	   if (num > max) {
		max = num;
	   }
    	   if (num < min) {
		min = num;
    	   }
	}

    cout << "min: " << min <<endl;
    cout << "max: " << max <<endl;
return 0;
}
