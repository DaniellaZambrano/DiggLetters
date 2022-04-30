#ifndef _SQUARE_H_
#define _SQUARE_H_

#include <bits/stdc++.h>

#include "Tile.H"
#include "point2D.H"

using namespace Designar;

enum class Modifier {
    NORMAL,
    TRIPLE_WORD,
    DOUBLE_WORD,
    TRIPLE_LETTER,
    DOUBLE_LETTER
};

class Square {

private:
    Point2D p;
	Tile* tile;
    Modifier mod;

public:
	
    Square() : mod(Modifier::NORMAL), tile(nullptr)
    {}

    Square(Point2D& p, Tile* t, Modifier mod) : mod(mod), tile(t), p(p)
    {}

	Tile* get_tile()
	{
		return this->tile;
	}

    void set_tile(Tile* tile)
    {
        this->tile = tile;
    }

    Modifier get_mod() const
    {
        return this->mod;
    }

    const Point2D& get_point() const
    {
        return this->p;
    }

};


#endif