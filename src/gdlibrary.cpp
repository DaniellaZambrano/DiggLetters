#include <Godot.hpp>

#include "Bag.H"
#include "Board.H"
#include "Cnode.H"
#include "Game.H"
#include "Player.H"
#include "Scrabot.H"
#include "Square.H"
#include "Tile.H"
#include "Utilities.H"

using namespace godot;

extern "C" void GDN_EXPORT godot_gdnative_init(godot_gdnative_init_options *o) {
    godot::Godot::gdnative_init(o);
}

extern "C" void GDN_EXPORT godot_gdnative_terminate(godot_gdnative_terminate_options *o) {
    godot::Godot::gdnative_terminate(o);
}

extern "C" void GDN_EXPORT godot_nativescript_init(void *handle) {
    godot::Godot::nativescript_init(handle);

    register_class<Player>();
}