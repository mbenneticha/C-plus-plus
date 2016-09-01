

#ifndef Die_H
#define Die_H


class Die
{
public:
    Die();
    Die(int user_sides);
    int Roll();
    
protected:
    int num_sides;
    int rolled_value;

};

#endif 

