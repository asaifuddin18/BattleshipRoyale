#include "ofApp.h"
#include<iostream>
#include<vector>
//--------------------------------------------------------------
void ofApp::setup(){
	ofSetBackgroundColor(0, 102, 204);
	player1.SetPosition(ofGetWindowWidth()/2, 0);
	player2.SetPosition(ofGetWindowWidth() / 2, ofGetWindowHeight() - 10);
	player1.SetSize(10, 10);
	player2.SetSize(10, 10);
	//player1.SetColor("RED");
	//player2.SetColor("BLUE");
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
	DrawPlayer1();
	DrawPlayer2();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	int player1_x = player1.GetXPos();
	int player1_y = player1.GetYPos();
	int player2_x = player2.GetXPos();
	int player2_y = player2.GetYPos();
	if (key > 400) {
		switch (key) {
		case 57357:
			player2.SetPosition(player2_x, player2_y - 10);
			break;
		case 57356:
			player2.SetPosition(player2_x - 10, player2_y);
			break;
		case 57359:
			player2.SetPosition(player2_x, player2_y + 10);
			break;
		case 57358:
			player2.SetPosition(player2_x + 10, player2_y);
			break;
		}
	}
	char letter =  toupper(key);
	switch (letter) {
	case 'W':
		player1.SetPosition(player1_x, player1_y - 10);
		break;
	case 'A':
		player1.SetPosition(player1_x - 10, player1_y);
		break;
	case 'S':
		player1.SetPosition(player1_x, player1_y + 10);
		break;
	case 'D':
		player1.SetPosition(player1_x + 10, player1_y);
		break;
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

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

void ofApp::DrawPlayer1()
{
	//std::vector<int> colors = player1.GetColor();
	ofSetColor(255, 0, 0);
	ofFill();
	ofDrawRectangle(player1.GetXPos(), player1.GetYPos(), player1.GetWidth(), player1.GetHeight());
}

void ofApp::DrawPlayer2()
{
	//std::vector<int> colors = player2.GetColor();
	ofSetColor(0, 255, 0);
	ofFill();
	ofDrawRectangle(player2.GetXPos(), player2.GetYPos(), player2.GetWidth(), player2.GetHeight());
}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
