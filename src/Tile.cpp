#include "Tile.H"

using namespace godot;

void Tile::_register_methods()
{
    
    register_method("_ready", &Tile::_ready);
    register_method("_process", &Tile::_process);
    register_property<Tile, int>("value", &Tile::value, 5);

    
}

void Tile::_init() {
    // initialize any variables here
    value = 5;
}

void Tile::_process(float delta) {
    // initialize any variables here
    value = 5;
    Button* boton = get_node<Button>("Button");

    boton->set_visible(false);
}

