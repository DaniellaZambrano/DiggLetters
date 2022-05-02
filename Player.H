#ifndef _PLAYER_H_
#define _PLAYER_H_


#include <bits/stdc++.h>

#include "Tile.H"
#include "Bag.H"

#include "point2D.H"

using namespace Designar;


class Player
{
private:
    int score = 0;
    std::vector<std::shared_ptr<Tile>> rack;

public:

    Point2D start_word;
    Point2D end_word;


    Player(){};
    ~Player(){};

    int get_tiles_rack()
    {
        return this->rack.size();
    }

    void fill_rack(int fill, Bag& bag)
    {
        for (int i = 0; i < fill; i++)
        {   
            this->rack.push_back(bag.get_tile());
        }              

        return;
    }
};


#endif
