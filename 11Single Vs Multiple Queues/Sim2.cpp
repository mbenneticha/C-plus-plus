//
//  Grocery check-out line
//

#include "Sim2.hpp"



int multi_click(std::queue<int> multi_queue[], int num_servers)
{
    int sim2_click = 0;
    int n = num_servers;
    
    while (!multi_queue[0].empty())
    {
        sim2_click++;
        multi_queue[0].pop();
    }
    
    for (int i = 1; i < n; i++)
    {
        if (!multi_queue[i].empty())
        {
            multi_queue[i].pop();
        }
        else
        {
            break;
        }
    }
    return sim2_click;
}



void sim2(std::queue<int> multi_line[], int servers)
{
    int m = servers;  //do not manipulate this variable
    int n = servers;  //can manipulate this variable
    int sim2_waiting_time = 0;
    
    //Cycle 1: begin with n = servers customers
    while (n != 0)
    {
        for (int i = 0; i < servers; i++)
        {
            multi_line[i].push(n);
            n--;
            
            if (n == 0)
            {
                break;
            }
        }
    }
    
    //simulate click
    int clicker = multi_click(multi_line, m);
    sim2_waiting_time += clicker;
    //std::cout <<"Emptied multi-line queue in " <<clicker <<" 'clicks'." <<std::endl;
    
    
    //Cycle 2: increase # customers
    int RND = rand() % servers;
    int num_customer = (2*m + RND);
    while (num_customer != 0)
    {
        for (int i = 0; i < m; i++)
        {
            multi_line[i].push(num_customer);
            num_customer--;

            if (num_customer == 0)
            {
                break;
            }
        }
    }
    
    //simulate click
    clicker = multi_click(multi_line, m);
    sim2_waiting_time += clicker;
    //std::cout <<"Emptied multi-line queue in " <<clicker <<" 'clicks'." <<std::endl;
    
    
    //Cycle 3: increase # customers -- PEAK
    RND = rand() % servers;
    num_customer = (4*m + RND);
    while (num_customer != 0)
    {
        for (int i = 0; i < m; i++)
        {
            multi_line[i].push(num_customer);
            num_customer--;
            
            if (num_customer == 0)
            {
                break;
            }
        }
    }
    
    //simulate click
    clicker = multi_click(multi_line, m);
    sim2_waiting_time += clicker;
    //std::cout <<"Emptied multi-line queue in " <<clicker <<" 'clicks'." <<std::endl;
    
    
    //Cycle 4: decrease # customers
    RND = rand() % servers;
    num_customer = (3*m + RND);
    while (num_customer != 0)
    {
        for (int i = 0; i < m; i++)
        {
            multi_line[i].push(num_customer);
            num_customer--;
            
            if (num_customer == 0)
            {
                break;
            }
        }
    }
    
    //simulate click
    clicker = multi_click(multi_line, m);
    sim2_waiting_time += clicker;
    //std::cout <<"Emptied multi-line queue in " <<clicker <<" 'clicks'." <<std::endl;
    
    
    //Cycle 5: decrease # customers -- final
    RND = rand() % servers;
    num_customer = (2*m + RND);
    while (num_customer != 0)
    {
        for (int i = 0; i < m; i++)
        {
            multi_line[i].push(num_customer);
            num_customer--;
            
            if (num_customer == 0)
            {
                break;
            }
        }
    }
    
    //simulate click
    clicker = multi_click(multi_line, m);
    sim2_waiting_time += clicker;
    //std::cout <<"Emptied multi-line queue in " <<clicker <<" 'clicks'." <<std::endl;

    
    //Print calculated waiting time (multi-lines/queues)
    std::cout <<"Multiple Queues/Multiple Servers" <<std::endl;
    std::cout <<"Wait Time: " <<sim2_waiting_time <<" 'clicks'."<<std::endl;
}

