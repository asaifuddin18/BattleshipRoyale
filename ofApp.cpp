#include "ofApp.h"
#include<iostream>
#include<vector>
//--------------------------------------------------------------
void ofApp::setup(){
	float block_width = ofGetWindowWidth() / 60;
	float block_height = ofGetWindowHeight() / 35;
	ofSetBackgroundColor(0, 102, 204);
	player1.SetPosition(ofGetWindowWidth()/2, 0);
	player2.SetPosition(ofGetWindowWidth() / 2, ofGetWindowHeight() - block_height);
	player1.SetSize(block_width, block_height);
	player2.SetSize(block_width, block_height);
	player1.SetId(1);
	player2.SetId(2);
	player1.SetColor("RED");
	player2.SetColor("BLUE");
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
	DrawPlayer1();
	DrawPlayer2();
	DrawRockets();
	DrawMap();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	int player1_x = player1.GetXPos();
	int player1_y = player1.GetYPos();
	int player2_x = player2.GetXPos();
	int player2_y = player2.GetYPos();
	switch (key) {
	case 57357: //up arrow
		player2.SetPosition(player2_x, player2_y - 20);
		break;
	case 57356: //left arrow
		player2.SetPosition(player2_x - 20, player2_y);
		break;
	case 57359: //down arrow
		player2.SetPosition(player2_x, player2_y + 20);
		break;
	case 57358: //right arrow
		player2.SetPosition(player2_x + 20, player2_y);
		break;
	case 13: //enter key
		rocket* new_rocket = new rocket(player2);
		active_rockets.push_back(new_rocket);
	}
	char letter =  toupper(key);
	switch (letter) {
	case 'W':
		player1.SetPosition(player1_x, player1_y - 20);
		break;
	case 'A':
		player1.SetPosition(player1_x - 20, player1_y);
		break;
	case 'S':
		player1.SetPosition(player1_x, player1_y + 20);
		break;
	case 'D':
		player1.SetPosition(player1_x + 20, player1_y);
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
	player1.SetSize(w / 60, h / 35);
	player2.SetSize(w / 60, h / 35);
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
	std::cout << active_rockets.size() << std::endl;
	for (int i = 0; i < active_rockets.size(); i++) {
		rocket* rocket = active_rockets[i];
		if (rocket->GetY() < 0 || rocket->GetY() > ofGetWindowHeight()) {
			active_rockets.erase(active_rockets.begin() + i);
			delete rocket;
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
	map = new Map("shipbattle.txt");
	for (int i = 0; i < map->GetMap()[0].size(); i++) {
		for (int j = 0; j < map->GetMap().size(); j++) {
			ofDrawRectangle(map->GetMap()[j][i]->GetRectangle());
		}
	}
}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
