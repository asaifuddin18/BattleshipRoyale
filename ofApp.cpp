#include "ofApp.h"
#include<iostream>
#include<vector>
//--------------------------------------------------------------
void ofApp::setup(){
	rocket_hit.load("rocket_hit.mp3");
	rocket_hit.setVolume(.5);
	rocket_fire.load("rocket_fire.mp3");
	rocket_fire.setVolume(.5);
	victory.load("victory.mp3");
	victory.setVolume(.5);
	player1 = new Player(max_x / 2, 0, player1_id, max_color, no_color, no_color);
	player2 = new Player(max_x / 2, max_y - 1, player2_id, no_color, max_color, no_color);
	ofSetBackgroundColor(no_color, 102, 204);
	map = new Map("shipbattle.txt");
}

//--------------------------------------------------------------
void ofApp::update(){
	GenerateAmmo();
	CheckForRocketCollision();
	CheckForAmmoPickUp();
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
	DrawAmmo();
	DrawPlayer1();
	DrawPlayer2();
	DrawRockets();
	DrawAmmoCount();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	first_move = true;
	int player1_x = player1->GetPlayerBlock()->GetX();
	int player1_y = player1->GetPlayerBlock()->GetY();
	int player2_x = player2->GetPlayerBlock()->GetX();
	int player2_y = player2->GetPlayerBlock()->GetY();
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
		if (player2->GetInventorySize() > 0) {
			Rocket* new_rocket = new Rocket(player2);
			active_rockets.push_back(new_rocket);
			player2->RemoveItem();
			rocket_fire.play();
		}
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
		if (player1->GetInventorySize() > 0) {
			Rocket* new_rocket = new Rocket(player1);
			active_rockets.push_back(new_rocket);
			player1->RemoveItem();
			rocket_fire.play();
		}
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
	for (Block* current : ammo) {
		current->Resize();
	}
	player1->UpdatePlayer();
	player2->UpdatePlayer();
	for (Rocket* current : active_rockets) {
		current->SetSize(w / max_x, h / max_y);
	}
}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

void ofApp::DrawPlayer1()
{
	std::vector<int> colors = player1->GetPlayerBlock()->GetColor();
	ofSetColor(colors[red_index], colors[green_index], colors[blue_index]);
	ofFill();
	ofDrawRectangle(player1->GetPlayerBlock()->GetRectangle());
}

void ofApp::DrawPlayer2()
{
	std::vector<int> colors = player2->GetPlayerBlock()->GetColor();
	ofSetColor(colors[red_index], colors[green_index], colors[blue_index]);
	ofFill();
	ofDrawRectangle(player2->GetPlayerBlock()->GetRectangle());
}

void ofApp::DrawRockets()
{
	for (int i = 0; i < active_rockets.size(); i++) {
		Rocket* rocket = active_rockets[i];
		if (rocket->GetY() < 0 || rocket->GetY() > max_y) {
			active_rockets.erase(active_rockets.begin() + i);
			delete rocket;
			continue;
		}
		ofSetColor(no_color, no_color, max_color);
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
				ofSetColor(colors[red_index], colors[green_index], colors[blue_index]);
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

bool ofApp::CheckIfInShip(Player* player)
{
	for (int i = 0; i < map->GetMap().size(); i++) {
		for (int j = 0; j < map->GetMap()[0].size(); j++)
			if (!map->GetMap()[i][j]->IsEmpty() && player->GetPlayerBlock()->GetX() == i && player->GetPlayerBlock()->GetY() == j) {
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
		Rocket* current = active_rockets.at(i);
		int rocket_x = current->GetX();
		int rocket_y = current->GetY();
		for (int j = 0; j < map->GetMap().size(); j++) {
			for (int k = 0; k < map->GetMap()[0].size(); k++) {
				if (rocket_x == j && rocket_y == k && !map->GetMap()[j][k]->IsEmpty()) {
					rocket_hit.play();
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
	int x1 = player1->GetPlayerBlock()->GetX();
	int y1 = player1->GetPlayerBlock()->GetY();
	int x2 = player2->GetPlayerBlock()->GetX();
	int y2 = player2->GetPlayerBlock()->GetY();
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
	if (!victorySoundPlayed) {
		victorySoundPlayed = true;
		victory.play();
	}
	ofTrueTypeFont* player = new ofTrueTypeFont();
	int font = ofGetWindowWidth() / 40;
	ofSetColor(max_color, max_color / 2, no_color);
	player->loadFont("customfont.ttf", font);
	if (player1_won && player2_won) { //tie case
		player->drawString("Tie!", (ofGetWindowWidth() / 2) - player->getSize() * 4, (ofGetWindowHeight() / 2));
		return;
	}
	if (player1_won) {
		player->drawString("Player 1 Won!", (ofGetWindowWidth() / 2) - player->getSize() * 4, (ofGetWindowHeight() / 2));
	}
	else if (player2_won) {
		player->drawString("Player 2 Won!", (ofGetWindowWidth() / 2) - player->getSize() * 4, (ofGetWindowHeight() / 2));
	}
	delete player;

}

void ofApp::GenerateAmmo()
{
	int odds = rand() % 17;
	int ammo_x = rand() % max_x;
	int ammo_y = rand() % max_y;
	if (odds == 4 && !map->GetMap()[ammo_x][ammo_y]->IsEmpty()) {
		Block *new_ammo = new Block(max_color, max_color / 2, no_color, ammo_x, ammo_y);
		ammo.push_back(new_ammo);
	}

}

void ofApp::CheckForAmmoPickUp()
{
	for (int i = 0; i < ammo.size(); i++) {
		Block* current = ammo[i];
		int ammo_x = current->GetX();
		int ammo_y = current->GetY();
		if (player1->GetXPos() == ammo_x && player1->GetYPos() == ammo_y) {
			player1->AddItem();
			ammo.erase(ammo.begin() + i);
			delete current;
		}
		else if (player2->GetXPos() == ammo_x && player2->GetYPos() == ammo_y) {
			player2->AddItem();
			ammo.erase(ammo.begin() + i);
			delete current;
		}
	}
}

void ofApp::DrawAmmo()
{
	for (Block* current : ammo) {
		std::vector<int> colors = current->GetColor();
		ofSetColor(colors[red_index], colors[green_index], colors[blue_index]);
		ofDrawRectangle(current->GetRectangle());
	}
}
void ofApp::DrawAmmoCount()
{
	ofTrueTypeFont* player = new ofTrueTypeFont();
	ofSetColor(max_color, max_color / 2, no_color);
	player->loadFont("customfont.ttf", ofGetWindowWidth() / max_x);
	player->drawString(std::to_string(player1->GetInventorySize()), ofGetWindowWidth() - (ofGetWindowWidth() / max_x), (ofGetWindowHeight() / max_y));
	player->drawString(std::to_string(player2->GetInventorySize()), ofGetWindowWidth() - (ofGetWindowWidth() / max_x), ofGetWindowHeight() - (ofGetWindowHeight() / max_y));
	delete player;
}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
