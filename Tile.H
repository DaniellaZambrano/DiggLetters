#ifndef _TILE_H_
#define _TILE_H_

const unsigned int NUM_LETTERS = 28;


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

    char get_letter()
    {           
        return this->letter;
    }

    int get_value()
    {
        return this->value;
    }
   
};

#endif
