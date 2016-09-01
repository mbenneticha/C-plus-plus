
#include "Game.hpp"
#include <iostream>
#include <cstdlib>

//default constructor
Game::Game()
{
    rounds = 0;
    player = 0;
    p1_game_score = 0;
    p2_game_score = 0;
}


//func to print to user what type of die each player is using
bool Game::die_type(int player)
{
    return (player == 1);
}


//func keeps track of # rounds played
//func keeps track of who wins current round
//func keeps track of who wins game
//func prints which player wins the game
int Game::war_game(int p1_score, int p2_score, int play_rounds)
{
    rounds++;
    
    if (p1_score > p2_score)
    {
        p1_game_score += 1;
    }
    else if (p1_score < p2_score)
    {
        p2_game_score += 1;
    }
   
    if (rounds == play_rounds)
    {
        if (p1_game_score > p2_game_score)
        {
            std::cout << "Player 1 is the winner! The score is: ";
        }
        else if (p1_game_score < p2_game_score)
        {
            std::cout << "Player 2 is the winner! The score is: ";
        }
        else if (p1_game_score == p2_game_score)
        {
            std::cout << "The game is a draw! The score is: ";
        }
        std::cout << p1_game_score << ":" << p2_game_score <<std::endl;
    }
    
    return 0;
}




