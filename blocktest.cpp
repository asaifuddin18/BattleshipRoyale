#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "block.h"
#include "ofApp.h"
#include "ofMain.h"
#include "ofGraphics.h"
#include <vector>
void Initialize() {
	ofGLFWWindowSettings settings;
	settings.setSize(180, 105);
	settings.visible = false;
	ofCreateWindow(settings);
}
TEST_CASE("Block Constructor") {
	SECTION("No Parameters") {
		Block *no_param = new Block();
		REQUIRE(no_param->IsEmpty());
	}
}
TEST_CASE("Block Constructor with Parameters") {
	Initialize();
	SECTION("Not Empty") {
		Block *not_empty = new Block(255, 0, 0, 0, 0);
		REQUIRE_FALSE(not_empty->IsEmpty());
	}
 	SECTION("Set Empty") {
		Block *empty = new Block(255, 0, 0, 0, 0);
		empty->SetEmpty();
		REQUIRE(empty->IsEmpty());
	}
}
TEST_CASE("Color Getter") {
	Initialize();
	SECTION("Pure Red") {
		Block *red = new Block(255, 0, 0, 0, 0);
		std::vector<int> colors = { 255, 0, 0 };
		REQUIRE(red->GetColor() == colors);
	}
	SECTION("Pure Green") {
		Block *green = new Block(0, 255, 0, 0, 0);
		std::vector<int> colors = { 0, 255, 0 };
		REQUIRE(green->GetColor() == colors);
	}
	SECTION("Pure Blue") {
		Block *blue = new Block(0, 0, 255, 0, 0);
		std::vector<int> colors = { 0, 0, 255 };
		REQUIRE(blue->GetColor() == colors);
	}
	SECTION("Black") {
		Block *black = new Block(255, 255, 255, 0, 0);
		std::vector<int> colors = { 255, 255, 255 };
		REQUIRE(black->GetColor() == colors);
	}
	SECTION("White") {
		Block *white = new Block(0, 0, 0, 0, 0);
		std::vector<int> colors = { 0, 0, 0 };
		REQUIRE(white->GetColor() == colors);
	}
}
TEST_CASE("Dimensions") {
	Initialize();
	SECTION("Get Width") {
		REQUIRE(ofGetWindowWidth() == 180);
	}
	SECTION("Get Height") {
		REQUIRE(ofGetWindowHeight() == 105);
	}
	SECTION("Resize") {
		SECTION("Width") {
			Block *width = new Block(100, 100, 100, 0, 0);
			ofSetWindowShape(240, 105);
			width->Resize();
			REQUIRE(width->GetWidth() == 4);
		}
		SECTION("Height") {
			Block *height = new Block(100, 100, 100, 0, 0);
			ofSetWindowShape(180, 210);
			height->Resize();
			REQUIRE(height->GetHeight() == 6);
		}
		SECTION("Width and Height") {
			Block *block = new Block(100, 100, 100, 0, 0);
			ofSetWindowShape(480, 315);
			block->Resize();
			bool height_and_width = block->GetWidth() == 8 && block->GetHeight() == 9;
			REQUIRE(height_and_width);
		}
	}
}
TEST_CASE("X and Y") {
	Initialize();
	SECTION("X") {
		SECTION("Get X") {
			Block *block = new Block(100, 100, 100, 20, 0);
			REQUIRE(block->GetX() == 60);
		}
		SECTION("X Above 60") {
			Block *block = new Block(100, 100, 100, 80, 0);
			REQUIRE(block->GetX() == ofGetWindowWidth());
		}
		SECTION("X Below 0") {
			Block *block = new Block(100, 100, 100, -100, 0);
			REQUIRE(block->GetX() == 0);
		}
	}
	SECTION("Y") {
		SECTION("Get Y") {
			Block *block = new Block(100, 100, 100, 0, 20);
			REQUIRE(block->GetY() == 60);
		}
		SECTION("Y Above 35") {
			Block *block = new Block(100, 100, 100, 0, 50);
			REQUIRE(block->GetY() == ofGetWindowHeight());
		}
		SECTION("Y Below 0") {
			Block *block = new Block(100, 100, 100, 0, -100);
			REQUIRE(block->GetY() == 0);
		}
	}
	SECTION("Get X and Y") {
		Block *block = new Block(100, 100, 100, 40, 5);
		bool x_and_y = 120 == block->GetX() && 15 == block->GetY();
		REQUIRE(x_and_y);
	}
}
TEST_CASE("Get Rectangle") {
	Block *block = new Block(100, 100, 100, 30, 15);
	ofRectangle rect = ofRectangle(90, 45, 3, 3);
	REQUIRE(block->GetRectangle() == rect);
}