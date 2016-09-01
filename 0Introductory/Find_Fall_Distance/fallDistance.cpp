/***********************************************
 * Function: fallDistance.cpp
 * Author: Mariam Ben-Neticha
 * Date: 7/15/15
 * Description: This funtion will calculate the distance (in meters)
 * 		 an object falls due to gravity when the user inputs
 * 		 a specific time period value in seconds.
***********************************************/

#include <iostream>
#include <cmath>
using namespace std;

void fallDistance();       //Declare function
int main() {
	cout << "Input time value in seconds." <<endl;
	fallDistance();

return 0;
}

void fallDistance() {

   double fallTime, d;

	cin >> fallTime;
	d = (0.5)*(9.8)*(pow (fallTime, 2));
	cout << d <<endl;
}


