#ifndef _UTILITIES_H_
#define _UTILITIES_H_


#include <bits/stdc++.h>
#include "Cnode.H"

#define LETTERS_IN_RACK 7

std::set<std::string> words_generator(std::string letters, const Cnode &prefixTree)
{
  std::set<std::string> words{};
  std::string s = letters, sc;    
  std::sort (s.begin(),s.end());
  
  do {
    sc.push_back(s[0]);
    for(size_t i = 1; i <= LETTERS_IN_RACK; i++)
    { 
      if(prefixTree.contains(sc))
        words.insert(sc);
      sc.push_back(s[i]);
    }
    sc = "";
  }while (std::next_permutation(s.begin(),s.end()));
   
  return words;
}

#endif
