#include "catch.hpp"
#include "ofApp.h"
void PlayerInit() {
	ofGLFWWindowSettings settings;
	settings.setSize(240, 175);
	settings.visible = false;
	ofCreateWindow(settings);
}
TEST_CASE("Get Player ID") {
	Player *player1 = new Player(0, 0, 1, 0, 0, 0);
	REQUIRE(player1->GetId() == 1);
}
TEST_CASE("Player Reposition") {
	PlayerInit();
	Player *player = new Player(10, 10, 1, 0, 0, 0);
	SECTION("Reposition X") {
		SECTION("Set Below 0") {
			player->SetPosition(-10, 10);
			REQUIRE(player->GetXPos() == 0);
		}
		SECTION("Set Above Max") {
			player->SetPosition(80, 10);
			REQUIRE(player->GetXPos() == 60);
		}
		SECTION("Set To Different Number") {
			player->SetPosition(35, 10);
			REQUIRE(player->GetXPos() == 35);
		}
	}
	SECTION("Reposition Y") {
		SECTION("Set Below 0") {
			player->SetPosition(10, -20);
			REQUIRE(player->GetYPos() == 0);
		}
		SECTION("Set Above Max") {
			player->SetPosition(10, 100);
			REQUIRE(player->GetYPos() == 35);
		}
		SECTION("Set To Different Number") {
			player->SetPosition(10, 23);
			REQUIRE(player->GetYPos() == 23);
		}
	}
	SECTION("Reposition Both") {
		player->SetPosition(45, 28);
		bool both_pos = player->GetXPos() == 45 && player->GetYPos() == 28;
		REQUIRE(both_pos);
	}
	SECTION("Equal Rectangles") {
		player->SetPosition(23, 21);
		player->UpdatePlayer();
		Block* block = new Block(0, 0, 0, 23, 21);
		REQUIRE(player->GetPlayerBlock()->GetRectangle() == block->GetRectangle());
	}
}