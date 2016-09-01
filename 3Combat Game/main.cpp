
#include "menu.hpp"
#include "Combat.hpp"
#include "Creature.hpp"
#include "Goblin.hpp"
#include "Barbarian.hpp"
#include "ReptilePeople.hpp"
#include "BlueMen.hpp"
#include "TheShadow.hpp"

#include <iostream>
#include <cstdlib>
#include <cmath>
#include <ctime>

int main()
{
    
    unsigned seed;
    seed = time_t(0);
    srand(seed);
    
    
    Goblin dobby, kreacher;
    Barbarian harry, ron;
    Reptile basilisk, nagini;
    BlueMen sprytes, pixie;
    Shadow voldemort, tom_riddle;
    
    Combat combat;
    
    int m;
    int subclass_type = 0;
   
    do{
        m = main_menu();
        
        if (m == 1)
        {
            int creature_a;
            int creature_b;

            creature_a = combat_menu();
            creature_b = combat_menu();
            
            if ((creature_a || creature_b == 1) && (creature_a || creature_b == 1)) {
                //Goblin vs Goblin
                Goblin dobby, kreacher;
                subclass_type = 0;
                subclass_type = combat.same_subclass(&dobby, &kreacher);
                combat.do_combat(&dobby, &kreacher, subclass_type);
            }
            else if ((creature_a || creature_b == 1) && (creature_a || creature_b == 2)) {
                //Goblin vs Barbarian
                Goblin dobby;
                Barbarian harry;
                subclass_type = 0;
                subclass_type = combat.same_subclass(&dobby, &harry);
                combat.do_combat(&dobby, &harry, subclass_type);
            }
            else if ((creature_a || creature_b == 1) && (creature_a || creature_b == 3)) {
                //Goblin vs Reptile
                Goblin dobby;
                Reptile basilisk;
                subclass_type = 0;
                subclass_type = combat.same_subclass(&dobby, &basilisk);
                combat.do_combat(&dobby, &basilisk, subclass_type);
            }
            else if ((creature_a || creature_b == 1) && (creature_a || creature_b == 4)) {
                //Goblin vs Blue Men
                Goblin dobby;
                BlueMen sprytes;
                subclass_type = 0;
                subclass_type = combat.same_subclass(&dobby, &sprytes);
                combat.do_combat(&dobby, &sprytes, subclass_type);
            }
            else if ((creature_a || creature_b == 1) && (creature_a || creature_b == 5)) {
                //Goblin vs Shadow
                Goblin dobby;
                Shadow voldemort;
                subclass_type = 0;
                subclass_type = combat.same_subclass(&dobby, &voldemort);
                combat.do_combat(&dobby, &voldemort, subclass_type);
            }
            else if ((creature_a || creature_b == 2) && (creature_a || creature_b == 2)) {
                //Barbarian vs Barbarian
                Barbarian harry, ron;
                subclass_type = 0;
                subclass_type = combat.same_subclass(&harry, &ron);
                combat.do_combat(&harry, &ron, subclass_type);
            }
            else if ((creature_a || creature_b == 2) && (creature_a || creature_b == 3)) {
                //Barbarian vs Reptile
                Barbarian harry;
                Reptile basilisk;
                subclass_type = 0;
                subclass_type = combat.same_subclass(&harry, &basilisk);
                combat.do_combat(&harry, &basilisk, subclass_type);
            }
            else if ((creature_a || creature_b == 2) && (creature_a || creature_b == 4)) {
                //Barbarian vs Blue Men
                Barbarian harry;
                BlueMen sprytes;
                subclass_type = 0;
                subclass_type = combat.same_subclass(&harry, &sprytes);
                combat.do_combat(&harry, &sprytes, subclass_type);
            }
            else if ((creature_a || creature_b == 2) && (creature_a || creature_b == 5)) {
                //Barbarian vs Shadow
                Barbarian harry;
                Shadow voldemort;
                subclass_type = 0;
                subclass_type = combat.same_subclass(&harry, &voldemort);
                combat.do_combat(&harry, &voldemort, subclass_type);
            }
            else if ((creature_a || creature_b == 3) && (creature_a || creature_b == 3)) {
                //Reptile vs Reptile
                Reptile basilisk, nagini;
                subclass_type = 0;
                subclass_type = combat.same_subclass(&nagini, &basilisk);
                combat.do_combat(&nagini, &basilisk, subclass_type);
            }
            else if ((creature_a || creature_b == 3) && (creature_a || creature_b == 4)) {
                //Reptile vs Blue Men
                Reptile basilisk;
                BlueMen sprytes;
                subclass_type = 0;
                subclass_type = combat.same_subclass(&basilisk, &sprytes);
                combat.do_combat(&basilisk, &sprytes, subclass_type);
            }
            else if ((creature_a || creature_b == 3) && (creature_a || creature_b == 5)) {
                //Reptile vs Shadow
                Reptile basilisk;
                Shadow voldemort;
                subclass_type = 0;
                subclass_type = combat.same_subclass(&basilisk, &voldemort);
                combat.do_combat(&basilisk, &voldemort, subclass_type);
            }
            else if ((creature_a || creature_b == 4) && (creature_a || creature_b == 4)) {
                //Blue Men vs Blue Men
                BlueMen sprytes, pixie;
                subclass_type = 0;
                subclass_type = combat.same_subclass(&pixie, &sprytes);
                combat.do_combat(&pixie, &sprytes, subclass_type);
            }
            else if ((creature_a || creature_b == 4) && (creature_a || creature_b == 5)) {
                //Blue Men vs Shadow
                BlueMen pixie;
                Shadow voldemort;
                subclass_type = 0;
                subclass_type = combat.same_subclass(&pixie, &voldemort);
                combat.do_combat(&pixie, &voldemort, subclass_type);
            }
            else if ((creature_a || creature_b == 5) && (creature_a || creature_b == 5)) {
                //Shadow vs Shadow
                Shadow voldemort, tom_riddle;
                subclass_type = 0;
                subclass_type = combat.same_subclass(&tom_riddle, &voldemort);
                combat.do_combat(&tom_riddle, &voldemort, subclass_type);
            }
        }
        else if (m == 2)
        {
            std::cout << "Program End." <<std::endl;
        }
        else
        {
            std::cout << "Please select the number corresponding to the action you wish to complete." << std::endl;
        }
    }while (m != 2);

    
    return 0;
}
