#ifndef _BOARD_H_
#define _BOARD_H_

#include <bits/stdc++.h>

#include "Square.H"
#include "buildgraph.H"
#include "graph.H"

const unsigned int BOARD_SIZE = 15;
const unsigned int OFFSET = 100;

using namespace Designar;
using BoardGraph = Graph<Square>;

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
    { 0, 0, 0, 3, 0, 0, 0, 2, 0, 0, 0, 3, 0, 0, 0 },
    { 0, 4, 0, 0, 0, 4, 0, 2, 0, 4, 0, 0, 0, 4, 0 },
    { 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0 },
    { 0, 0, 1, 0, 0, 3, 0, 3, 0, 0, 0, 0, 1, 0, 0 },
    { 0, 1, 0, 0, 4, 0, 0, 2, 4, 0, 0, 0, 0, 1, 0 },
    { 2, 0, 0, 3, 0, 0, 0, 2, 0, 0, 0, 3, 0, 0, 2 },
  };

  return static_cast<Modifier>(positions[x][y]);
}

class Board {

  private:
  BoardGraph game_board;

  public:
  Board()
  {
    this->game_board = build_grid<BoardGraph>(
        BOARD_SIZE, BOARD_SIZE,
        [&](BoardGraph::Node* n, nat_t j, nat_t i) {
          n->get_info().set_point(Point2D(j * OFFSET, i * OFFSET));
          n->get_info().set_mod(get_mod(j, i));
        },
        [](BoardGraph::Arc* a){});
  }

  BoardGraph& get_graph() { return this->game_board; }

  void test_board()
  {
    int row = 0;
    this->game_board.for_each_node([&](BoardGraph::Node* n) {
      if (n->get_info().get_point().get_x() > row) {
        std::cout << "\n";
        row = n->get_info().get_point().get_x();
      }

    // std::cout << '(' << n->get_info().get_point().get_x() << "," << n->get_info().get_point().get_y() << ')' << " " << static_cast<int> (n->get_info().get_mod()) << " ";
      std::cout << static_cast<int> (n->get_info().get_mod()) << " ";
    });
  }
};

#endif