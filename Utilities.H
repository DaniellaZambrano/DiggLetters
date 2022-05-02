#ifndef _UTILITIES_H_
#define _UTILITIES_H_

#define LETTERS_IN_RACK 7

std::set<string> words_generator(char *letters, const Cnode &prefixTree)
{
  std::set<string> words{};
  string s, sc;    
  s.append(letters,LETTERS_IN_RACK);
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
