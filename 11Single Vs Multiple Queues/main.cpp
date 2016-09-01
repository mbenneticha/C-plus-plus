
#include "Sim1.hpp"
#include "Sim2.hpp"

#include <iostream>
#include <cstdlib>
#include <cmath>
#include <queue>

int main() {
    
    //seed random number generator
    srand(static_cast<unsigned int>(time(0)));
    
    int servers;
    std::cout <<"Enter the number of servers available at check-out." <<std::endl;
    std::cin >> servers;
    
    
    
    //instantiate the queues
    //sim1 = dsw line (1 queue/multiple servers)
    std::queue<int> sim1_queue;
    
    //sim2 = wegmans line (multiple queues/multiple servers)
    std::queue<int> sim2_queues[50];
    
    
    
    //Run simulation
    //sim 1
    sim1(sim1_queue, servers);
    
    //sim 2
    sim2(sim2_queues, servers);
    
    
    return 0;
}
