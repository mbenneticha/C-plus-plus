/************************************
 * Function: smallSort.cpp
 * Author: Mariam Ben-Neticha
 * Date: 7.15.15
 * Description: This function will take the three inputed values and rearrange
                them from smallest value to largest value and displays it.
************************************/

#include <iostream>
using namespace std;

//function rearranged referenced integers in ascending order
void smallSort(int& a, int& b,int& c);


int main() {
	int num1, num2, num3;
	cout << "Input three integer values." <<endl;
	cin >> num1 >> num2 >> num3;
	smallSort(num1, num2, num3);

return 0;
}


void smallSort(int& a, int& b,int& c) {
   if (a < b) {
	if (b < c)
	    cout << a << ", " << b << ", " << c <<endl;
	else
	    cout << a << ", " << c << ", " << b <<endl;
   }
   else if (b < c) {
	if (a < c)
	    cout << b << ", " << a << ", " << c <<endl;
	else
	    cout << b << ", " << c << ", " << a <<endl;
   }
   else if (c < a){
	if (a < b)
	    cout << c << ", " << a << ", " << b <<endl;
	else
	    cout << c << ", " << b << ", " << a <<endl;
	}
}
