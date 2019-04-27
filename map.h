#pragma once
#include <iostream>
#include "block.h"
#include <array>
#include <fstream>
class Map {
public:
	Map(std::string file_name);
	std::array<std::array<block*, 35>, 60> GetMap();
private:
	std::array<std::array<block*, 35>, 60> map_array;
};
