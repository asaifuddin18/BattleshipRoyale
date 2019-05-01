#include "map.h"
#include <iostream>

Map::Map(std::string file_name)
{
	bool reading_key = true;
	std::cout << file_name;
	std::ifstream map_file(file_name);
	std::string current_line;
	int y = 0;
	std::map<char, std::vector<int>> color_key;
	while (std::getline(map_file, current_line)) {
		if (reading_key) {
			if (current_line == "MAP") {
				reading_key = false;
				continue;
			}
			char tile_name = current_line.at(0);
			std::vector<int> colors;
			colors.push_back(std::stoi(current_line.substr(4, 3)));
			colors.push_back(std::stoi(current_line.substr(7, 3)));
			colors.push_back(std::stoi(current_line.substr(10)));
			color_key[tile_name] = colors;
			continue;
		}
		for (int i = 0; i < current_line.size(); i++) {
			char tile = current_line.at(i);
			if (color_key.find(tile) != color_key.end()) {
				std::vector<int> colors = color_key[tile];
				map_array[i][y] = new Block(colors[0], colors[1], colors[2], i, y);
			}
			else {
				Block* new_tile;
				map_array[i][y] = new Block();
			}
		}
		y++;
	}
}


std::array<std::array<Block*, 35>, 60> Map::GetMap()
{
	return map_array;
}
