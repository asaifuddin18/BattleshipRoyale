#pragma once

#include "ofMain.h"
#include "rocket.h"
#include "player.h"
#include "map.h"
#include <vector>

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
	bool first_move = false;
	bool player2_won = false;
	bool player1_won = false;
	Map* map;
	player* player1;
	player* player2;
	void DrawPlayer1();
	void DrawPlayer2();
	void DrawRockets();
	void DrawMap();
	std::vector<rocket*> active_rockets;
	void ResizeMap();
	bool CheckIfInShip(player* player);
	void CheckForRocketCollision();
	void CheckForWinner();
	void DrawWinningText();
};
