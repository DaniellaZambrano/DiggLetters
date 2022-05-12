#pragma once

#include <Godot.hpp>

#include <iostream>
#include <Button.hpp>

#define NUM_LETTERS 28

namespace godot{

class Tile : public Button {

private:

    char letter;
    int value;
 
    GODOT_CLASS(Tile,Button)

public:

    Tile(){}

    Tile(char l, int v)
    {
        this->letter = l;
        this->value = v;
    }

    ~Tile(){}

    static void _register_methods();

    char get_letter()
    {           
        return this->letter;
    }

    int get_value()
    {
        return this->value;
    }

    void _ready();
    void _init();
    void _process(float);
   
};

}

