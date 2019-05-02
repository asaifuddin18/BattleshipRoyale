#include "map.h"
#include <iostream>

Map::Map(std::string file_name)
{
	bool reading_key = true;
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
			char tile_name = current_line.at(index_of_key_char);
			std::vector<int> colors;
			colors.push_back(std::stoi(current_line.substr(red_substring, length_of_substring)));
			colors.push_back(std::stoi(current_line.substr(green_sibstring, length_of_substring)));
			colors.push_back(std::stoi(current_line.substr(blue_substring)));
			color_key[tile_name] = colors;
			continue;
		}
		for (int i = 0; i < current_line.size(); i++) {
			char tile = current_line.at(i);
			if (color_key.find(tile) != color_key.end()) {
				std::vector<int> colors = color_key[tile];
				map_array[i][y] = new Block(colors[red_index], colors[green_index], colors[blue_index], i, y);
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
