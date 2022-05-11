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

    Play horizontal_play(Point2D point, int init, int end, Board& b,
                         const std::vector<std::shared_ptr<Tile>>& a)
    {
      Play p;
      int i = 0, x = point.get_x(), y = point.get_y();
      auto table = b.get_board();
      for(;init <= end; init++)
      {
        if (table[init][y].get_tile() != nullptr and (init * OFFSET) != x)
          return Play();
        else
          p.push_back(std::make_pair(a[i],Point2D(init * OFFSET,y)));      
      }

      return p;
    }
    
    Play vertical_play(Point2D point, int init, int end, Board& b,
                       const std::vector<std::shared_ptr<Tile>>& a)
    {
      Play p;
      int 
      i = 0, x = point.get_x(), y = point.get_y();
      auto table = b.get_board();
      for(;init <= end; init++)
      {      
        if (table[x][init].get_tile() != nullptr and (init * OFFSET) != y)
          return Play();
        else
          p.push_back(std::make_pair(a[i],Point2D(x,init * OFFSET)));
      }
       
      return p;
    }
    
    std::vector<Play> get_plays(Cnode& tree, Board& board) 
    {
        int used_word = rand() % this->registered_word.size();

        auto f = std::get<0>(this->registered_word[used_word]);
        auto direction = std::get<1>(this->registered_word[used_word]);
        auto pos = std::get<2>(this->registered_word[used_word]);

        auto options = words_generator(this->rack, tree, std::make_shared<Tile>(f[0], 0));
        std::vector<Play> plays;        
        
        for (auto& option: options) {
            Play p;
            int k;
            for (k=0 ; k < option.size(); k++){
                if (option[k]->get_letter() == f[0])
                    break;
            }

            int to_end_of_word = option.size() - k;

            bool is_horizontal = direction == 0 or direction == 1;
            
            if (is_horizontal) {
                p = horizontal_play(pos,pos.get_x() - k,
                                            pos.get_x() + to_end_of_word,
                                            board,option);
                if (pos.get_x() - k < 0 or
                    pos.get_x() + to_end_of_word >= BOARD_SIZE or
                    p.empty())
                    continue;
            }
            else
            {
                p = vertical_play(pos,pos.get_y() - k,
                                            pos.get_y() + to_end_of_word,
                                            board,option);
                if (pos.get_y() - k < 0 or
                    pos.get_y() + to_end_of_word >= BOARD_SIZE or
                    p.empty())
                    continue;
            }
            plays.push_back(p);
         }
       return plays;
    }

    Play get_best_play(std::vector<Play>& plays, Board& board)
    {
      auto b = board.get_board();
      int max_score = 0, score, value;
      unsigned position_best_play, i = 0, x, y, double_word, triple_word;
      
      for(auto aux_p : plays)
      {
        score = value = 0;
        double_word = triple_word = 0;
        for(auto pair_tp : aux_p)
        {
          value = pair_tp.first->get_value();
          x = pair_tp.second.get_x() / OFFSET;
          y = pair_tp.second.get_y() / OFFSET;
          if(get_mod(x,y) == Modifier::DOUBLE_LETTER)
            value *= 2;
          else if(get_mod(x,y) == Modifier::TRIPLE_LETTER)
            value *= 3;
          else if(get_mod(x,y) == Modifier::DOUBLE_WORD)
            double_word++;
          else if(get_mod(x,y) == Modifier::TRIPLE_WORD)
            triple_word++;
        }
        score += score * (double_word * 2)  * (triple_word * 3);
        if(aux_p.size() == 7)
          score += 50;
        if(max_score < score)
        {        
          max_score = score;
          position_best_play = i;
        }
        i++;
      }
            
      return plays[position_best_play];
    }

public:

    Scrabot(){}
    ~Scrabot(){}

    void set_registered_word(std::string w, int dir, Point2D p)
    {
      this->registered_word.push_back(std::make_tuple(w,dir,p));
    }

    Play play(Cnode& tree, Board& board)
    {
        auto plays {get_plays(tree,board)};
        
        return get_best_play(plays,board);
    }


};


#endif
