#ifndef _BOARD_H_
#define _BOARD_H_

#include <bits/stdc++.h>

#include "Square.H"

const unsigned int BOARD_SIZE = 15;
const unsigned int OFFSET = 1;

Modifier get_mod(unsigned x, unsigned y)
{
  const unsigned int positions[BOARD_SIZE][BOARD_SIZE] = {
    { 2, 0, 0, 3, 0, 0, 0, 2, 0, 0, 0, 3, 0, 0, 2 },
    { 0, 1, 0, 0, 4, 0, 0, 2, 4, 0, 0, 0, 0, 1, 0 },
    { 0, 0, 1, 0, 0, 3, 0, 3, 0, 0, 0, 0, 1, 0, 0 },
    { 3, 0, 0, 1, 0, 0, 3, 0, 0, 0, 0, 1, 0, 0, 3 },
    { 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0 },
    { 0, 4, 0, 0, 0, 4, 0, 2, 0, 4, 0, 0, 0, 4, 0 },
    { 0, 0, 3, 0, 0, 0, 3, 0, 3, 0, 0, 3, 3, 0, 0 },
    { 2, 0, 0, 3, 0, 0, 0, 1, 0, 0, 0, 3, 0, 0, 2 },
    { 0, 0, 3, 0, 0, 0, 3, 0, 3, 0, 0, 3, 3, 0, 0 },
    { 0, 4, 0, 0, 0, 4, 0, 2, 0, 4, 0, 0, 0, 4, 0 },
    { 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0 },
    { 3, 0, 0, 1, 0, 0, 3, 0, 0, 0, 0, 1, 0, 0, 3 },
    { 0, 0, 1, 0, 0, 3, 0, 3, 0, 0, 0, 0, 1, 0, 0 },
    { 0, 1, 0, 0, 4, 0, 0, 2, 4, 0, 0, 0, 0, 1, 0 },
    { 2, 0, 0, 3, 0, 0, 0, 2, 0, 0, 0, 3, 0, 0, 2 },
  };

  return static_cast<Modifier>(positions[x][y]);
}

class Board {

  private:
  Square game_board[BOARD_SIZE][BOARD_SIZE];
  std::string word;

  public:
  Board()
  {
    for (int i=0; i<BOARD_SIZE; i++) {
      for (int j =0; j< BOARD_SIZE; j++) {
        game_board[i][j].set_point(Point2D(j * OFFSET, i * OFFSET));
        game_board[i][j].set_mod(get_mod(j, i));
      }
    }
  }

  auto get_graph() { return this->game_board; }
};

#endif