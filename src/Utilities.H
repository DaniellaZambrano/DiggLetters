#ifndef _UTILITIES_H_
#define _UTILITIES_H_

#include "Cnode.H"
#include "Tile.H"
#include <bits/stdc++.h>

#define LETTERS_IN_RACK 7

std::set<std::string> words_generator(std::string letters, const Cnode& prefixTree)
{
  std::set<std::string> words {};
  std::string s = letters, sc;
  std::sort(s.begin(), s.end());

  do {
    sc.push_back(s[0]);
    for (size_t i = 1; i < LETTERS_IN_RACK; i++) {
      if (prefixTree.contains(sc))
        words.insert(sc);
      sc.push_back(s[i]);
    }
    sc = "";
  } while (std::next_permutation(s.begin(), s.end()));

  return words;
}

struct compare_tiles {
  bool operator()(std::shared_ptr<Tile> rhs, std::shared_ptr<Tile> lhs) const
  {
    return rhs->get_letter() < lhs->get_letter();
  }
} cmp_tiles;

struct compare_as_set {
  bool operator()(const
      std::vector<std::shared_ptr<Tile>>& rhs, const std::vector<std::shared_ptr<Tile>>& lhs) const
  {
    return std::lexicographical_compare(rhs.begin(), rhs.end(), lhs.begin(), lhs.end(), cmp_tiles);
  }
} cmp_set;

std::set<std::vector<std::shared_ptr<Tile>>, compare_as_set> words_generator(
    std::vector<std::shared_ptr<Tile>> letters, const Cnode& prefixTree, std::shared_ptr<Tile> c)
{
  std::set<std::vector<std::shared_ptr<Tile>>, compare_as_set> words {};
  std::vector<std::shared_ptr<Tile>> s = letters;
  std::string sc;
  std::vector<std::shared_ptr<Tile>> aux_tiles;

  s.push_back(c);

  std::sort(s.begin(), s.end(), cmp_tiles);

  do {
    sc.push_back(s[0]->get_letter());
    aux_tiles.push_back(s[0]);
    for (size_t i = 1; i <= LETTERS_IN_RACK; i++) {
      if (prefixTree.contains(sc))
        words.insert(aux_tiles);
      sc.push_back(s[i]->get_letter());
      aux_tiles.push_back(s[i]);
    }
    sc = "";
    aux_tiles.clear();
  } while (std::next_permutation(s.begin(), s.end(), cmp_tiles));

  return words;
}

#endif
