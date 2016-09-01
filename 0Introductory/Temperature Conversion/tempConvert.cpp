/*******************************
 * Program: tempConvert.cpp
 * Author: Mariam Ben-Neticha
 * Date: 7/1/15
 * Description: This program is an interactive program that will convert input Celsius temperatures to Fahrenheit temperatures.
 ******************************/

#include <iostream>
#include <iomanip>		//Needed to use stream manipulators
using namespace std;

int main()
{

	// use "double" to allow for non-integer numbers such as negative numbers and decimals.
	double Celsius, mult, Fahrenheit;
	cout << "Please enter a Celsius temperature." <<endl;
	cin >> Celsius;

	//Compute the Fahrenheit temperature from the input Celsius temperature.
	mult = (9 * Celsius) / 5;		//multi stands for multiplicants
	Fahrenheit =( mult ) + 32;

	//Display the converted temperature in Fahrenheit.
	cout << "The equivalent Fahrenheit temperature is:" <<endl;
	cout << fixed << setprecision(1) << Fahrenheit <<endl;

	return 0;
}
