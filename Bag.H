#ifndef _BAG_H_
#define _BAG_H_

#include <bits/stdc++.h>

#include "Tile.H"

#define NUM_TILES 100
#define NUM_LETTERS 28

class Bag {

private:

	std::vector<std::shared_ptr<Tile>> tiles;

	char letter[NUM_LETTERS] = { '0', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'Ñ', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z' };
	int value[NUM_LETTERS] = { 0, 1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 4, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10 };
    int frequency[NUM_LETTERS] = {2, 9, 2, 2, 4, 10, 2, 3, 2, 9, 1, 1, 4, 2, 6, 8, 2, 1, 6, 4, 6, 4, 2, 2, 1, 2, 1, 2};
    
	int num_act_tiles = NUM_TILES;

public:
	
    Bag()
    {
		int pos = 0;
		for (int i = 0; i < NUM_LETTERS; i++)
		{
			for (int j = 0; j < frequency[i]; j++)
			{
				Tile insert_tile(letter[i], value[i]);
				std::shared_ptr<Tile> ptr_tile = std::make_shared<Tile>(insert_tile);
            	tiles.push_back(ptr_tile);
			}
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

	std::shared_ptr<Tile> get_tile()
	{
		if (this->num_act_tiles == 0)
            return nullptr;

		
		srand((unsigned)time(NULL));

		int random_tile = rand() % num_act_tiles;

		std::shared_ptr<Tile> ret_tile = this->tiles[random_tile];

        this->tiles.erase(this->tiles.begin() + random_tile);
		num_act_tiles--;

		return ret_tile;
	}

	unsigned int get_tiles_count() const
	{
		return this->tiles.size();
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