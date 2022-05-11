#ifndef _GAME_H_
#define _GAME_H_

#define UNUSED(name) (void)name;

#include "Aliases.H"
#include "Board.H"
#include "Cnode.H"
#include "Player.H"
#include "Scrabot.H"

const unsigned int NUM_TILES_IN_RACK = 7;
const unsigned int NUM_PLAYERS = 2;

class Game {

  private:
  Board board;
  Bag bag;
  std::vector<std::shared_ptr<Player>> players;
  // Prefix tree required for the game to work
  Cnode prefix_tree;
  // Index for the player playing on the current turn
  unsigned int current_player = 0;

  public:
  Game()
      : prefix_tree('$')
  {
    // Fill the players
    for (int i = 0; i < NUM_PLAYERS; i++) {
      // First player is human, every other player is a bot
      players.push_back(i == 0 ? std::make_shared<Player>() : std::make_shared<Scrabot>());
    }

    // Greet all players

    greet_players();

    // Choose starter player

    unsigned int starter = choose_starter_player();

    // Run turns sequentially until the bag is out tiles and no further plays can be done.

    start_match(starter);
  }

  unsigned int get_current_player() const { return this->current_player; }

  unsigned int get_player_count() const { return this->players.size(); }

  void greet_players()
  {
    // In case of a Graphical Interface, initial animations can be done here, after all resources
    // are properly loaded
    std::cout << "Welcome to DiggLetters!"
              << "\n";
  }

  unsigned int choose_starter_player() const
  {
    // Any innovative rule to define starter player can be implemented here, meanwhile its random
    unsigned int starter = rand() % get_player_count();
    return starter;
  }

  void start_match(unsigned int starter_player)
  {
    current_player = starter_player;

    while (bag.get_tiles_count() > 0 /** and someone can make plays **/) {
      before_turn();

      auto player = players[current_player];

      // Draw a full hand, if not already full

      int missing_tiles = NUM_TILES_IN_RACK - player->get_tiles_rack();

      player->fill_rack(missing_tiles, bag);

      // Make a play

      auto play = player->play(prefix_tree, board);

      // Validate play

      // Next player's turn

      after_turn();

      // This is to avoid current player to surpass player count and to cycle between current
      // players
      current_player = (current_player + 1) % get_player_count();
    }
  }

  void before_turn()
  {
    // This executes before every turn, both checking available plays and playing animations can be
    // done here
    std::cout << "Now its Player " << current_player + 1 << " turn."
              << "\n";
  }

  void after_turn()
  {
    // This executes after every turn, both score checking and playing animations can be done here
    std::cout << "Player " << current_player + 1 << " turn ended."
              << "\n";
  }

  bool is_valid_play(std::vector<LetterInBoard>& tiles) const
  {
    for (auto& tile : tiles) {
      // Check position within board bounds
      if (tile.second.get_x() < 0 or tile.second.get_x() > BOARD_SIZE or tile.second.get_y() < 0
          or tile.second.get_y() < BOARD_SIZE)
        return false;

      // Check the word is valid
    }

    return false;
  }

  std::pair<Point2D, Point2D> get_word_bounds(LetterInBoard& letter, bool horizontal = true)
  {
    int a, b;

    if (horizontal) {
      a = b = letter.second.get_x();
      int y = letter.second.get_y();

      while ((a >= 0 and a < BOARD_SIZE) and (b >= 0 and b < BOARD_SIZE)) {
        if (board.get_graph()[a][y].get_tile() != nullptr)
          a--;
        if (board.get_graph()[b][y].get_tile() != nullptr)
          b++;
      }

      return std::make_pair(Point2D(a, y), Point2D(b, y));
    }

    a = b = letter.second.get_y();
    int x = letter.second.get_x();

    while ((a >= 0 and a < BOARD_SIZE) and (b >= 0 and b < BOARD_SIZE)) {
      if (board.get_graph()[x][a].get_tile() != nullptr)
        a--;
      if (board.get_graph()[x][b].get_tile() != nullptr)
        b++;
    }

    return std::make_pair(Point2D(x, a), Point2D(x, b));
  }
};

#endif
