#include "catch.hpp"
#include "map.h"
TEST_CASE("Map Generated Correctly") {
	Map* map = new Map("shiptest.txt");
	Block *brown = new Block(102, 51, 0, 0, 0);
	Block *white = new Block(255, 255, 255, 0, 0);
	Block *empty = new Block();
	for (int i = 0; i < map->GetMap().size(); i++) {
		for (int j = 0; j < map->GetMap().size(); j++) {
			if (j == 0 || j == 33) {
				REQUIRE(map->GetMap()[i][j]->GetColor() == white->GetColor());
			}
			else if (j == 1 || j == 34) {
				REQUIRE(map->GetMap()[i][j]->GetColor() == brown->GetColor());
			}
		}
	}
	
}