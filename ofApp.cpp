#include "ofApp.h"
#include<iostream>
#include<vector>
//--------------------------------------------------------------
void ofApp::setup(){
	player1 = new player(30, 0, 1, 255, 0, 0);
	player2 = new player(30, 33, 2, 0, 255, 0);
	ofSetBackgroundColor(0, 102, 204);
	map = new Map("shipbattle.txt");
}

//--------------------------------------------------------------
void ofApp::update(){
	CheckForRocketCollision();
	//if (first_move) {
		//CheckForWinner();
	//}
	CheckForWinner();
}

//--------------------------------------------------------------
void ofApp::draw(){
	if (player1_won || player2_won) {
		DrawWinningText();
		return;
	}
	DrawMap();
	DrawPlayer1();
	DrawPlayer2();
	DrawRockets();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	first_move = true;
	int player1_x = player1->GetPlayerBlock()->GetXArray();
	int player1_y = player1->GetPlayerBlock()->GetYArray();
	int player2_x = player2->GetPlayerBlock()->GetXArray();
	int player2_y = player2->GetPlayerBlock()->GetYArray();
	ofRectangle temp_player;
	switch (key) {
	case 57357: //up arrow
		player2->SetPosition(player2_x, player2_y - 1);
		if (!CheckIfInShip(player2)) {
			player2->SetPosition(player2_x, player2_y);
		}
		break;
	case 57356: //left arrow
		player2->SetPosition(player2_x - 1, player2_y);
		if (!CheckIfInShip(player2)) {
			player2->SetPosition(player2_x, player2_y);
		}
		break;
	case 57359: //down arrow
		player2->SetPosition(player2_x, player2_y + 1);
		if (!CheckIfInShip(player2)) {
			player2->SetPosition(player2_x, player2_y);
		}
		break;
	case 57358: //right arrow
		player2->SetPosition(player2_x + 1, player2_y);
		if (!CheckIfInShip(player2)) {
			player2->SetPosition(player2_x, player2_y);
		}
		break;
	case 13: //enter key
		rocket* new_rocket = new rocket(player2);
		active_rockets.push_back(new_rocket);
	}
	char letter =  toupper(key);
	switch (letter) {
	case 'W':
		player1->SetPosition(player1_x, player1_y - 1);
		if (!CheckIfInShip(player1)) {
			player1->SetPosition(player1_x, player1_y);
		}
		break;
	case 'A':
		player1->SetPosition(player1_x - 1, player1_y);
		if (!CheckIfInShip(player1)) {
			player1->SetPosition(player1_x, player1_y);
		}
		break;
	case 'S':
		player1->SetPosition(player1_x, player1_y + 1);
		if (!CheckIfInShip(player1)) {
			player1->SetPosition(player1_x, player1_y);
		}
		break;
	case 'D':
		player1->SetPosition(player1_x + 1, player1_y);
		if (!CheckIfInShip(player1)) {
			player1->SetPosition(player1_x, player1_y);
		}
		break;
	case 'F':
		rocket* new_rocket = new rocket(player1);
		active_rockets.push_back(new_rocket);
	}
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){
	ResizeMap();
	player1->UpdatePlayer();
	player2->UpdatePlayer();
	for (rocket* current : active_rockets) {
		current->SetSize(w / 60, h / 35);
	}
}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

void ofApp::DrawPlayer1()
{
	std::vector<int> colors = player1->GetPlayerBlock()->GetColor();
	ofSetColor(colors[0], colors[1], colors[2]);
	ofFill();
	ofDrawRectangle(player1->GetPlayerBlock()->GetRectangle());
}

void ofApp::DrawPlayer2()
{
	std::vector<int> colors = player2->GetPlayerBlock()->GetColor();
	ofSetColor(colors[0], colors[1], colors[2]);
	ofFill();
	ofDrawRectangle(player2->GetPlayerBlock()->GetRectangle());
}

void ofApp::DrawRockets()
{
	for (int i = 0; i < active_rockets.size(); i++) {
		rocket* rocket = active_rockets[i];
		if (rocket->GetY() < 0 || rocket->GetY() > 35) {
			active_rockets.erase(active_rockets.begin() + i);
			delete rocket;
			continue;
		}
		ofSetColor(0, 0, 255);
		ofFill();
		ofDrawRectangle(rocket->GetBlock()->GetRectangle());
		rocket->Update();
	}
}

void ofApp::DrawMap()
{
	for (int i = 0; i < map->GetMap()[0].size(); i++) {
		for (int j = 0; j < map->GetMap().size(); j++) {
			ofFill();
			if (!map->GetMap()[j][i]->IsEmpty()) {
				std::vector<int> colors = map->GetMap()[j][i]->GetColor();
				ofSetColor(colors[0], colors[1], colors[2]);
				ofDrawRectangle(map->GetMap()[j][i]->GetRectangle());
			}
		}
	}
}

void ofApp::ResizeMap()
{
	for (int i = 0; i < map->GetMap()[0].size(); i++) {
		for (int j = 0; j < map->GetMap().size(); j++) {
			ofFill();
			if (!map->GetMap()[j][i]->IsEmpty()) {
				map->GetMap()[j][i]->Resize();
			}
		}
	}
}

bool ofApp::CheckIfInShip(player* player)
{
	for (int i = 0; i < map->GetMap().size(); i++) {
		for (int j = 0; j < map->GetMap()[0].size(); j++)
			if (!map->GetMap()[i][j]->IsEmpty() && player->GetPlayerBlock()->GetXArray() == i && player->GetPlayerBlock()->GetYArray() == j) {
				return true;
			}
	}
	return false;
}

void ofApp::CheckForRocketCollision()
{
	if (active_rockets.size() == 0) {
		return;
	}
	for (int i = 0; i < active_rockets.size(); i++) {
		rocket* current = active_rockets.at(i);
		int rocket_x = current->GetX();
		int rocket_y = current->GetY();
		for (int j = 0; j < map->GetMap().size(); j++) {
			for (int k = 0; k < map->GetMap().size(); k++) {
				if (rocket_x == j && rocket_y == k && !map->GetMap()[j][k]->IsEmpty()) {
					map->GetMap()[j][k]->SetEmpty();
					active_rockets.erase(active_rockets.begin() + i);
					j = map->GetMap().size();
					k = map->GetMap()[0].size();
					delete current;
				}
			}
		}
	}
}

void ofApp::CheckForWinner()
{
	bool player1_on_ship = false;
	bool player2_on_ship = false;
	int x1 = player1->GetPlayerBlock()->GetXArray();
	int y1 = player1->GetPlayerBlock()->GetYArray();
	int x2 = player2->GetPlayerBlock()->GetXArray();
	int y2 = player2->GetPlayerBlock()->GetYArray();
	for (int i = 0; i < map->GetMap().size(); i++) {
		for (int j = 0; j < map->GetMap()[0].size(); j++) {
			if (!player1_on_ship && !map->GetMap()[i][j]->IsEmpty() && x1 == i && y1 == j) {
				player1_on_ship = true;
			}
			if (!player2_on_ship && !map->GetMap()[i][j]->IsEmpty() && x2 == i && y2 ==j) {
				player2_on_ship = true;
			}
		}
	}
	//player2_won == !player1_on_ship;
	//player1_won == !player2_on_ship;
	if (!player1_on_ship) { //clean up
		player2_won = true;
	}
	else if (!player2_on_ship) {
		player1_won = true;
	}
}

void ofApp::DrawWinningText()
{
	if (player1_won) {
		ofDrawBitmapString("Player 1 Won!", 100, 100);
	}
	else if (player2_won) {
		ofDrawBitmapString("Player 2 Won!", 100, 100);
	}
}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
