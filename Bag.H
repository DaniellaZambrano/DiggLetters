#ifndef _BAG_H_
#define _BAG_H_

#include <bits/stdc++.h>

#include "Tile.H"

#define NUM_TILES 100

class Bag {

private:

	Tile* tiles[NUM_TILES];
    int frequency[NUM_LETTERS] = {2, 9, 2, 2, 4, 12, 2, 3, 2, 9, 1, 1, 4, 2, 6, 8, 2, 1, 6, 4, 6, 4, 2, 2, 1, 2, 1, 2};
    int num_act_tiles = NUM_TILES;

public:
	
    Bag()
    {
		int pos = 0;
		for (int i = 0; i < NUM_LETTERS; i++)
		{
            tiles[pos]->get_letter(i);
		}
	
	}


	int get_freq(char l)
    {
        int pos = std::toupper(l) - 64;

        if (l == '0')
            pos = 0;

        return this->frequency[pos];
    }

    int get_freq(int pos)
    {
        return this->frequency[pos];
    }

	Tile* get_tile(int &a, int index)
	{
		if (this->num_act_tiles == 0)
            return nullptr;

		
		srand((unsigned)time(NULL));

		int random_tile = rand() % NUM_TILES;

        this->num_act_tiles--;
	
		return this->tiles[random_tile];
	}

	void test_bag()
	{
		std::cout << "Tiles in Bag" << '\n';

		for (int i = 0; i < num_act_tiles; i++)
		{
			std::cout << i << " " << this->tiles[i] << '\n';
		}
	}
};


#endif