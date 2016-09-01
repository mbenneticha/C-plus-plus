/********************************
 *Program: numGuess.cpp
 *Author: Mariam Ben-Neticha
 *Date: 7/6/15
 *Description: This is an interactive program that asks user1 to enter any
	 integer. Then the program asks the player(user2) to guess the 
	 number user1 entered. The program will respod to the guesses with
	 the appropriate reply, telling user2 that their guess was 
	 "too high", "too low", or correct. When user2 guesses correctly,
	 the program will tell user2 how many tries it took to guess
	 correctly and end the game.
*********************************/

#include <iostream>
using namespace std;

int main() {

  //value entered as targetInt is meant to be an integer, so use int
    int targetInt;
  //value entered by user2 as guess might not be an integer, so use double
    double guess;
  //use this counter to keep track of the number of attempts it took for 
  //user2 to guess correctly
    int counter = 1;

  //Prompt user1 for integer input targetInt
    cout << "Enter the number for the player to guess." <<endl;
  //Store input as targetInt
    cin >> targetInt;
  
  //Prompt player to enter a guess.
    cout << "Enter your guess." << endl;

    while (guess != targetInt) {  
    //Prompt player to enter a guess.
    cin >> guess;
    
	{
	    if (guess > targetInt) {
		cout << "Too high - try again." << endl ;
        ++counter;
	    } 
	    else if (guess < targetInt) {
		cout << "Too low - try again." <<endl;
	++counter;
	    } 
    //When guess !> and !< targetInt, it must be ==.
	    else {
		cout << "You guessed it in " << counter << " tries." <<endl;
	  }
	}
    }
    return 0;
}
