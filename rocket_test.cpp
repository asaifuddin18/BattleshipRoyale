#include "catch.hpp"
#include "player.h"
#include "rocket.h"
TEST_CASE("Correct Direction") {
	Player* player1 = new Player(30, 0, 1, 255, 0, 0);
	Player* player2 = new Player(30, 33, 2, 0, 255, 0);
	Rocket* rocket_1 = new Rocket(player1);
	Rocket* rocket_2 = new Rocket(player2);
	SECTION("Correct Starting Direction") {
		SECTION("Player 1") {
			REQUIRE(rocket_1->GetY() == 1);
		}
		SECTION("Player 2") {
			REQUIRE(rocket_2->GetY() == 32);
		}
	}
	SECTION("Correct Velocity") {
		SECTION("Player 1") {
			REQUIRE(rocket_1->GetVelocity() == 1);
		}
		SECTION("Player 2") {
			REQUIRE(rocket_2->GetVelocity() == -1);
		}
	}
}

TEST_CASE("Updated Position") {
	Player* player1 = new Player(30, 0, 1, 255, 0, 0);
	Player* player2 = new Player(30, 33, 2, 0, 255, 0);
	Rocket* rocket_1 = new Rocket(player1);
	Rocket* rocket_2 = new Rocket(player2);
	SECTION("Player 1") {
		rocket_1->Update();
		REQUIRE(rocket_1->GetY() == 2);
	}
	SECTION("Player 2") {
		rocket_2->Update();
		REQUIRE(rocket_2->GetY() == 31);
	}
}
TEST_CASE("Color") {
	Player* player1 = new Player(30, 0, 1, 254, 0, 0);
	Player* player2 = new Player(30, 33, 2, 0, 254, 0);
	Rocket* rocket_1 = new Rocket(player1);
	Rocket* rocket_2 = new Rocket(player2);
	SECTION("Player 1") {
		std::vector<int> player1_colors = { 127, 0, 0 };
		REQUIRE(rocket_1->GetColor() == player1_colors);
	}
	SECTION("Player 2") {
		std::vector<int> player2_colors = { 0, 127, 0 };
		REQUIRE(rocket_2->GetColor() == player2_colors);
	}
}