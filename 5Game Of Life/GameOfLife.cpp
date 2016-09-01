/************
 * Program: GameOfLife.cpp
 * Author: Mariam Ben-Neticha
 * Date: 10/4/15
 * Description: This program allows the user to choose one of three different, preset shapes to display on the screen. The user is then prompted to give the x- and y-coordinates to denote the starting location of their chosen shape. Finally, the user chooses how many generations they would like to iterate through. The program will print the viewing window of the starting matrix with the shape in it's starting location. A copy this screen/array is saved. A function called "occupied_neighbors" runs through the entire array and counts how many neighbors each cell in the array has. Based on the number of neighbors each cell has and the rules of the game, that cell will die (denoted by '-'), it will be newly born (denoted by 'O') or it will remain live (denoted by 'O'). Based on these changes, the cells will evolve and show the oscillating/gliding/cannon movements.
 ************/

#include <iostream>


//function that determines how many neighbors each cell in the window has.
int occupied_neighbors (char con[][80], int cell_x, int cell_y)
{
    int value = 0;
    
    //find neighbors of shape
    if (cell_y-1 > 0 && con[cell_x][cell_y-1] != '-')
        value ++;
    
    if (cell_y+1 < 80 && con[cell_x][cell_y+1] != '-')
        value ++;
    
    if (cell_x+1 < 80 && con[cell_x+1][cell_y] != '-')
        value ++;
    
    if (cell_x-1 > 0 && con[cell_x-1][cell_y] != '-')
        value ++;
    
    if (cell_y-1 > 0 && cell_x+1 < 80 && con[cell_x+1][cell_y-1] != '-')
        value ++;
    
    if (cell_y-1 > 0 && cell_x-1 > 0 && con[cell_x-1][cell_y-1] != '-')
        value ++;
    
    if (cell_y+1 < 80 && cell_x+1 < 80 && con[cell_x+1][cell_y+1] != '-')
        value ++;
    
    if (cell_y+1 < 80 && cell_x-1 > 0 && con[cell_x-1][cell_y+1] != '-')
        value ++;
    
    //std::cout << value <<std::endl;
    return value;
    
}


int main() {
    //char game_array[y][x] is format of below.
    char game_array[40][80];
    char old_array[40][80];
    char fixed_oscil[3][1] = {'O', 'O', 'O'};
    char simple_glide[3][3] = {'-', 'O', '-',
                               '-', '-', 'O',
                               'O', 'O', 'O'};
    char cannon_glide[7][22] = {'-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', 'O', '-', '-', '-', '-', '-', '-', '-', '-',
                                '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', 'O', '-', 'O', '-', '-', '-', '-', '-', '-', '-',
                                '0', '0', '-', '-', '-', '-', '-', '-', '-', '-', '-', 'O', '-', '-', '-', 'O', 'O', '-', '-', '-', '0', '0',
                                '0', '0', '-', '-', '-', '-', '-', '-', '-', '-', '-', 'O', '-', '-', '-', 'O', 'O', '-', '-', '-', '0', '0',
                                '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', 'O', '-', '-', '-', 'O', 'O', '-', '-', '-', '-', '-',
                                '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', 'O', '-', 'O', '-', '-', '-', '-', '-', '-', '-',
                                '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', 'O', '-', '-', '-', '-', '-', '-', '-', '-',};
    
    
    //create matrix
    for (int i=0; i < 40; i++)
    {
        for (int j=0; j < 80; j++)
        {
            game_array[i][j] = '-';
        }
    }
    
    //prompt user for shape they wish to view.
    int shape;
    std::cout << "What shape would you like to view?" <<std::endl;
    std::cout << " 1. Fixed Oscillator" <<std::endl;
    std::cout << " 2. Glider" <<std::endl;
    std::cout << " 3. Glider Cannon" <<std::endl;
    std::cout << "Type in the number of the shape you wish to view." <<std::endl;
    std::cin >> shape;
    
    
    //prompt user for starting location of shape.
    // x and y coordinates switched throughout. x= columns; y=rows.
    int x;
    int y;
    int generation;
    
    std::cout << "Enter the starting x-coordinate between 0 and 40 for your shape." <<std::endl;
    std::cin >> y;
    std::cout << "Enter the starting y-coordinate between 0 and 20 for your shape." <<std::endl;
    std::cin >> x;
    std::cout << "Through how many generations do you wish to iterate?" <<std::endl;
    std::cin >> generation;

    
    //offset values due to larger 'world' than viewable display
    y += 20;
    x += 10;
    
    //input shape into matrix/array
    //case # = shape # entered by user.
    switch (shape) {
        case 1:
            for (int i = 0; i < 3; i++)
            {
                game_array[x+i][y] = fixed_oscil[i][0];
            }
            break;
        case 2:
            for (int i = 0; i < 3; i++)
            {
                for (int j = 0; j < 3; j++)
                {
                    game_array[x+i][y+j] = simple_glide[i][j];
                }
            }
            break;
        case 3:
            for (int i = 0; i < 7; i++)
            {
                for (int j = 0; j < 22; j++)
                {
                    game_array[x+i][y+j] = cannon_glide[i][j];
                }
            }
            break;
        default:
            break;
    }
    
    
    
    //print the first array with the chosen shape
    //and print a line between text outputs
    for (int i=10; i < 30; i++)
    {
        for (int j=20; j < 60; j++)
        {
            std::cout << game_array[i][j] ;
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
    
    
    
    //print a certain amount of iterations of the array
    for (int m = 0; m < generation; m++)
    {
        //make a copy of the original starting array with the starting shape
        //necessary to allow death and birth of cell to be simultaneous
        for (int i=0; i < 40; i++)
        {
            for (int j=0; j < 80; j++)
            {
                old_array[i][j] = game_array[i][j];
            }
        }
        


        //input Game of Life Rules to allow cell evolution and generation
        for (int i=0; i < 40; i++)
        {
            for (int j=0; j < 80; j++)
            {
                
                int n = occupied_neighbors(old_array, i, j);
                if (n > 3)
                {
                    game_array[i][j] = '-';
                }
                
                else if (n < 2)
                    game_array[i][j] = '-';
                else if (n == 3)
                {
                    game_array[i][j] = 'O';
                }
            }
        }
        
        //print the evolving array(s)
        for (int i=10; i < 30; i++)
        {
            for (int j=20; j < 60; j++)
            {
                std::cout << game_array[i][j] ;
            }
            std::cout << std::endl;
        }
        std::cout << std::endl;
    }
    
    
    return 0;
}
