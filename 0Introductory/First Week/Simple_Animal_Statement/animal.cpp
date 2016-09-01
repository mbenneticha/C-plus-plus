/********************************************************
** Author: Mariam Ben-Neticha
** Date: 6/24/15
** Description: This program is a basic interactive program that asks for the
subjects favorite animal and then prints 'Your favorite animal is the
[enteredInput]' to the console.
****************************************************** */

#include <iostream>
#include <string>

//a simple example program
int main()
{
	std::string faveAnimal;
	std::cout << "Please enter your favorite animal." <<std::endl;
	std::cin >> faveAnimal;
	std::cout << "Your favorite animal is the " << faveAnimal;
	std::cout << "." << std::endl;

	return 0;
}
