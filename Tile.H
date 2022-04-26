#ifndef _TILE_H_
#define _TILE_H_

#include <iostream>

#define NUM_LETTERS 28

class Tile {

private:

    char letter[NUM_LETTERS] = { '0', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'Ñ', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z' };
    int value[NUM_LETTERS] = { 0, 1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 4, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10 };
	
public:

    Tile(){}

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