#ifndef _TILE_H_
#define _TILE_H_

#include <iostream>

#define NUM_LETTERS 28

class Tile {

private:

    char letter;
    int value;
 
public:

    Tile(char l, int v)
    {
        this->letter = l;
        this->value = v;
    }

    ~Tile(){}

    char get_letter(int pos)
    {
        if (pos < 0 || pos > NUM_LETTERS)
            return '?';
            
        return this->letter[pos];
    }

    int get_value(char l)
    {
        int pos = std::toupper(l) - 64;

        if (l == '0')
            pos = 0;

        return this->value[pos];
    }
   
};

#endif