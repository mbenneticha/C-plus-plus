/*********************************
 * Program: change.cpp
 * Author: Mariam Ben-Neticha
 * Date: 7/1/15
 * Description: This is an interactive program that asks for an integer number of cents that ranges between 0 to 99. It then outputs the fewest amount of coins to represent that amount in quarters, dimes, nickels, and pennies.
 *********************************/

#include <iostream>
#include <cmath>		//Needed to use complex math functions.
using namespace std;

int main()
{
	//Use integer because user should only enter integer numbers.
	//Define q,d,n, and p as constants and give their values.
	const int q = 25;
	const int d = 10;
	const int n = 5;
	const int p = 1;
	int x, qt, dm, nk, pn, loOne, loTwo, loThree;

	//Ask user to enter integer amount of cents
	cout << "Please enter an amount in cents less than a dollar." <<endl;
	cin >> x;

	//Check to make sure entered amount "x" is within 0-99 range
	((x >= 0) && (x <= 99));

	//Calculate amount of quarters
	qt = ( x / q );

	//Calculate leftover amount
	loOne = ( x - ( qt * q ) );

	//Calulate amount of dimes
	dm = ( loOne / d );

	//Calculate leftover amount 2
	loTwo =( loOne - ( dm * d ) );

	//Calculate amount of nickels
	nk = ( loTwo / n );

	//Calculate leftover amount 3
	loThree = ( loTwo - ( nk * n ) );

	//Calculate amount of pennies
	pn = ( loThree / p );

	//Display change amount to user
	cout << "Your change will be:" <<endl;
	cout << "Q: " << qt <<endl;
	cout << "D: " << dm <<endl;
	cout << "N: " << nk <<endl;
	cout << "P: " << pn <<endl;

	return 0;
	}
