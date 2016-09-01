//
//  DSW check-out line
//

#include "Sim1.hpp"

#include <cstdlib>
#include <iostream>
#include <queue>


int one_click(std::queue<int> *one_line, int num_servers)
{
    int sim1_click = 0;
    while (!one_line->empty())
    {
        sim1_click++;
        for (int i = 0; i < num_servers; i++)
        {
            if (!one_line->empty())
            {
                one_line->pop();
            }
            else
            {
                break;
            }
        }
    }
    return sim1_click;
}



void sim1(std::queue<int> one_line, int servers)
{
    int n = servers;
    int sim1_waiting_time = 0;
    
    //Randomly generate value
    int RND = rand() % servers;
    
    //Cycle 1: begin with n = servers customers
    for (int i = 0; i < n; i++)
    {
        one_line.push(i);
    }
    
    //simulate click
    int clicker = one_click(&one_line, n);
    sim1_waiting_time += clicker;
    //std::cout <<"Emptied one-line queue in " <<clicker <<" 'clicks'." <<std::endl;
   
   
    //Cycle 2: increase # customers
    RND = rand() % servers;
    int num_customer = (2*n + RND);
    for (int i = 0; i < num_customer; i++)
    {
        one_line.push(i);
    }
   
    //simulate click
    clicker = one_click(&one_line, n);
    sim1_waiting_time += clicker;
    //std::cout <<"Emptied one-line queue in " <<clicker <<" 'clicks'."<<std::endl;
    
    
    //Cycle 3: increase # customers -- PEAK
    RND = rand() % servers;
    num_customer = (4*n + RND);
    for (int i = 0; i < num_customer; i++)
    {
        one_line.push(i);
    }
    
    //simulate click
    clicker = one_click(&one_line, n);
    sim1_waiting_time += clicker;
    //std::cout <<"Emptied one-line queue in " <<clicker <<" 'clicks'."<<std::endl;
   
    
    //Cycle 4: decrease # customers
    RND = rand() % servers;
    num_customer = (3*n + RND);
    for (int i = 0; i < num_customer; i++)
    {
        one_line.push(i);
    }
    
    //simulate click
    clicker = one_click(&one_line, n);
    sim1_waiting_time += clicker;
    //std::cout <<"Emptied one-line queue in " <<clicker <<" 'clicks'."<<std::endl;
    
    
    //Cycle 5: decrease # customers -- final
    RND = rand() % servers;
    num_customer = (2*n + RND);
    for (int i = 0; i < num_customer; i++)
    {
        one_line.push(i);
    }
    
    //simulate click
    clicker = one_click(&one_line, n);
    sim1_waiting_time += clicker;
    //std::cout <<"Emptied one-line queue in " <<clicker <<" 'clicks'."<<std::endl;
    
    
    
    //Print calculated waiting time (One-line queue)
    std::cout <<"One Queues/Multiple Servers" <<std::endl;
    std::cout <<"Wait Time: " <<sim1_waiting_time <<" 'clicks'."<<std::endl;
}


