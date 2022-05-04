#ifndef _SCRABOT_H_
#define _SCRABOT_H_

#include <bits/stdc++.h>

#include "Player.H"
#include "Game.H"
#include "Utilities.H"
#include "Board.H"

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

    std::vector<std::pair<Tile, Point2D>> get_plays(Cnode& tree, Board& board) 
    {
        int used_word = rand() % this->registered_word.size();

        auto f = std::get<0>(this->registered_word[used_word]);
        auto direction = std::get<1>(this->registered_word[used_word]);
        auto pos = std::get<2>(this->registered_word[used_word]);

        auto options = words_generator(this->rack, tree, std::make_shared<Tile>(f[0], 0));

        for (auto& option: options) {
            int k;
            for (k=0 ; k<option.size(); k++){
                if (option[k]->get_letter() == f[0])
                    break;
            }

            int to_end_of_word = option.size() - k;

            bool is_horizontal = direction == 0 or direction == 1;

            if (is_horizontal) {
                if (pos.get_x() - k < 0 or pos.get_x() + to_end_of_word >= BOARD_SIZE)
                    continue;
            }

            if (pos.get_y() - k < 0 or pos.get_y() + to_end_of_word >= BOARD_SIZE)
                continue;

            
            }
    }

};


#endif