#pragma once

#include "ofMain.h"
#include "rocket.h"
#include "player.h"
#include "map.h"
#include <vector>
#include "ofSoundPlayer.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
private:
	int player1_id = 1;
	int player2_id = 2;
	int no_color = 0;
	int red_index = 0;
	int green_index = 1;
	int blue_index = 2;
	int max_color = 255;
	int max_x = 60;
	int max_y = 35;
	bool victorySoundPlayed = false;
	ofSoundPlayer rocket_hit;
	ofSoundPlayer rocket_fire;
	ofSoundPlayer victory;
	bool first_move = false;
	bool player2_won = false;
	bool player1_won = false;
	Map* map;
	Player* player1;
	Player* player2;
	void DrawPlayer1();
	void DrawPlayer2();
	void DrawRockets();
	void DrawMap();
	std::vector<Rocket*> active_rockets;
	std::vector<Block*> ammo;
	void ResizeMap();
	bool CheckIfInShip(Player* player);
	void CheckForRocketCollision();
	void CheckForWinner();
	void DrawWinningText();
	void GenerateAmmo();
	void CheckForAmmoPickUp();
	void DrawAmmo();
	void DrawAmmoCount();
};
