#include "map.h"
#include <iostream>

Map::Map(std::string file_name)
{
	std::cout << file_name;
	std::ifstream map_file(file_name);
	std::string current_line;
	int y = 0;
	while (std::getline(map_file, current_line)) {
		for (int i = 0; i < current_line.size(); i++) {
			char tile = current_line.at(i);
			if (tile == 'B') {
				//block* new_tile = new block(153, 102, 0, i, y);
				map_array[i][y] = new block(153, 102, 0, i, y);
			}
			else {
				block* new_tile;
				map_array[i][y] = new block();
			}
		}
		y++;
	}
}


std::array<std::array<block*, 35>, 60> Map::GetMap()
{
	return map_array;
}
