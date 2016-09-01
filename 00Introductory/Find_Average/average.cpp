;/*********************************
 * Program: average.cpp
 * Author: Mariam Ben-Neticha
 * Date: 7/1/15
 * Description: This program is an interactive program that will ask the user for five numbers and output the numbers entered as well as the average of the numbers.
 * *******************************/
#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
   // use "double" in order to allow for non-integer numbers such as negative numbers and decimals.
	double firstNum, secondNum, thirdNum, fourthNum, fifthNum, sum, average;
   //Have the user input five numbers.
	cout << "Please enter five numbers." <<endl;
	cin >> firstNum >>secondNum >>thirdNum >>fourthNum >>fifthNum;

   //Compute the average of the numbers
	sum = firstNum + secondNum + thirdNum + fourthNum + fifthNum;
	average = sum / 5;

   //Display numbers entered and the average
	cout << fixed << showpoint << setprecision(1);
	cout << firstNum <<endl;
	cout << secondNum <<endl;
	cout << thirdNum <<endl;
	cout << fourthNum <<endl;
	cout << fifthNum <<endl;
	cout << "The average of those numbers is:" <<endl;
	cout << fixed << setprecision(1) << average <<endl;
	return 0;
}

