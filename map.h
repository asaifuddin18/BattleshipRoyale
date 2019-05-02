#pragma once
#include <iostream>
#include "block.h"
#include <array>
#include <fstream>
#include <vector>
#include <map>
class Map {
public:
	Map(std::string file_name);
	std::array<std::array<Block*, 35>, 60> GetMap();
private:
	int index_of_key_char = 0;
	int red_substring = 4;
	int green_sibstring = 7;
	int blue_substring = 10;
	int length_of_substring = 3;
	int red_index = 0;
	int green_index = 1;
	int blue_index = 2;

	std::array<std::array<Block*, 35>, 60> map_array;
};
