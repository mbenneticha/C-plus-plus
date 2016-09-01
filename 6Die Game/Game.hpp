

#ifndef Game_hpp
#define Game_hpp
#include "Die.hpp"
#include "LoadedDie.hpp"

class Game {
public:
    Game();
    bool player_has_fair_die(int player);
    bool die_type(int player);
    int war_game(int p1_score, int p2_score, int play_rounds);
    
private:
    int rounds;
    int player;
    int p1_game_score;
    int p2_game_score;
};

#endif
