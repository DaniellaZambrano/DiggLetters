#ifndef _SCRABOT_H_
#define _SCRABOT_H_

#include <bits/stdc++.h>

#include "Player.H"
#include "Game.H"
#include "Utilities.H"

#include "point2D.H"

using namespace Designar;

class Scrabot : public Player{

private:

    std::vector<std::tuple<std::string, int, Point2D>> registered_word;


public:

    Scrabot(){}
    ~Scrabot(){}

    void play(Cnode& tree)
    {
        std::string letters;

        for (auto tile : this->rack)
        {
            letters.push_back(tile->get_letter());
        }

        words_generator(letters, tree);
        
        
    }

};


#endif