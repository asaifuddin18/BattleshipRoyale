#include "ofApp.h"
#include<iostream>
#include<vector>
//--------------------------------------------------------------
void ofApp::setup(){
	float block_width = ofGetWindowWidth() / 60;
	float block_height = ofGetWindowHeight() / 35;
	ofSetBackgroundColor(0, 102, 204);
	player1.SetPosition(ofGetWindowWidth()/2, 0);
	player2.SetPosition(ofGetWindowWidth() / 2, ofGetWindowHeight() - 2*block_height);
	player1.SetSize(block_width, block_height);
	player2.SetSize(block_width, block_height);
	player1.SetId(1);
	player2.SetId(2);
	player1.SetColor("RED");
	player2.SetColor("BLUE");
	map = new Map("shipbattle.txt");
}

//--------------------------------------------------------------
void ofApp::update(){
	CheckForRocketCollision();
	if (first_move) {
		CheckForWinner();
	}
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
	int player1_x = player1.GetXPos();
	int player1_y = player1.GetYPos();
	int player2_x = player2.GetXPos();
	int player2_y = player2.GetYPos();
	ofRectangle temp_player;
	switch (key) {
	case 57357: //up arrow
		temp_player = ofRectangle(player2_x, player2_y - player2.GetHeight(), player2.GetWidth(), player2.GetHeight());
		if (CheckIfInShip(temp_player)) {
			player2.SetPosition(player2_x, player2_y - player2.GetHeight());
		}
		break;
	case 57356: //left arrow
		temp_player = ofRectangle(player2_x - player2.GetWidth(), player2_y, player2.GetWidth(), player2.GetHeight());
		if (CheckIfInShip(temp_player)) {
			player2.SetPosition(player2_x - player2.GetWidth(), player2_y);
		}
		break;
	case 57359: //down arrow
		temp_player = ofRectangle(player2_x, player2_y + player2.GetHeight(), player2.GetWidth(), player2.GetHeight());
		if (CheckIfInShip(temp_player)) {
			player2.SetPosition(player2_x, player2_y + player2.GetHeight());
		}
		break;
	case 57358: //right arrow
		temp_player = ofRectangle(player2_x + player2.GetWidth(), player2_y, player2.GetWidth(), player2.GetHeight());
		if (CheckIfInShip(temp_player)) {
			player2.SetPosition(player2_x + player2.GetWidth(), player2_y);
		}
		break;
	case 13: //enter key
		rocket* new_rocket = new rocket(player2);
		active_rockets.push_back(new_rocket);
	}
	char letter =  toupper(key);
	switch (letter) {
	case 'W':
		temp_player = ofRectangle(player1_x, player1_y - player1.GetHeight(), player1.GetWidth(), player1.GetHeight());
		if (CheckIfInShip(temp_player)) {
			player1.SetPosition(player1_x, player1_y - player1.GetHeight());
		}
		break;
	case 'A':
		temp_player = ofRectangle(player1_x - player1.GetWidth(), player1_y, player1.GetWidth(), player1.GetHeight());
		if (CheckIfInShip(temp_player)) {
			player1.SetPosition(player1_x - player1.GetWidth(), player1_y);
		}
		break;
	case 'S':
		temp_player = ofRectangle(player1_x, player1_y + player1.GetHeight(), player1.GetWidth(), player1.GetHeight());
		if (CheckIfInShip(temp_player)) {
			player1.SetPosition(player1_x, player1_y + player1.GetHeight());
		}
		break;
	case 'D':
		temp_player = ofRectangle(player1_x + player2.GetWidth(), player1_y, player1.GetWidth(), player1.GetHeight());
		if (CheckIfInShip(temp_player)) {
			player1.SetPosition(player1_x + player1.GetWidth(), player1_y);
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
	player1.UpdatePlayer();
	player2.UpdatePlayer();
	for (rocket* current : active_rockets) {
		current->SetSize(w / 60, h / 35);
	}
}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

void ofApp::DrawPlayer1()
{
	//std::vector<int> colors = player1.GetColor();
	ofSetColor(player1.GetColor()[0], player1.GetColor()[1], player1.GetColor()[2]);
	ofFill();
	player1_rect = ofRectangle(player1.GetXPos(), player1.GetYPos(), player1.GetWidth(), player1.GetHeight());
	ofDrawRectangle(player1_rect);
}

void ofApp::DrawPlayer2()
{
	//std::vector<int> colors = player2.GetColor();
	ofSetColor(player2.GetColor()[0], player2.GetColor()[1], player2.GetColor()[2]);
	ofFill();
	player2_rect = ofRectangle(player2.GetXPos(), player2.GetYPos(), player2.GetWidth(), player2.GetHeight());
	ofDrawRectangle(player2_rect);
}

void ofApp::DrawRockets()
{
	for (int i = 0; i < active_rockets.size(); i++) {
		rocket* rocket = active_rockets[i];
		if (rocket->GetY() < 0 || rocket->GetY() > ofGetWindowHeight()) {
			active_rockets.erase(active_rockets.begin() + i);
			delete rocket;
			continue;
		}
		ofSetColor(rocket->GetColor()[0], rocket->GetColor()[1], rocket->GetColor()[2]);
		ofFill();
		ofRectangle rocket_rect(rocket->GetX(), rocket->GetY(), rocket->GetWidth(), rocket->GetHeight());
		//ofDrawRectangle(rocket->GetX(), rocket->GetY(), rocket->GetWidth(), rocket->GetHeight());
		if (rocket_rect.intersects(player1_rect) || rocket_rect.intersects(player2_rect)) {
			rocket->Reflect();
		}
		ofDrawRectangle(rocket_rect);
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

bool ofApp::CheckIfInShip(ofRectangle player)
{
	for (int i = 0; i < map->GetMap().size(); i++) {
		for (int j = 0; j < map->GetMap()[0].size(); j++)	
			if (!map->GetMap()[i][j]->IsEmpty() && map->GetMap()[i][j]->GetRectangle().intersects(player)) {
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
	for (int k = 0; k < active_rockets.size(); k++) {
		rocket* current = active_rockets[k];
		for (int i = 0; i < map->GetMap().size(); i++) {
			for (int j = 0; j < map->GetMap()[0].size(); j++) {
				if (current->GetRectangle().intersects(map->GetMap()[i][j]->GetRectangle()) && !map->GetMap()[i][j]->IsEmpty()) {
					int size = active_rockets.size();
					map->GetMap()[i][j]->SetEmpty();
					active_rockets.erase(active_rockets.begin() + k);
					i = map->GetMap().size();
					j = map->GetMap()[0].size();
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
	for (int i = 0; i < map->GetMap().size(); i++) {
		for (int j = 0; j < map->GetMap()[0].size(); j++) {
			if (!player1_on_ship && !map->GetMap()[i][j]->IsEmpty() && player1_rect.intersects(map->GetMap()[i][j]->GetRectangle())) {
				player1_on_ship = true;
			}
			if (!player2_on_ship && !map->GetMap()[i][j]->IsEmpty() && player2_rect.intersects(map->GetMap()[i][j]->GetRectangle())) {
				player2_on_ship = true;
			}
		}
	}
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
