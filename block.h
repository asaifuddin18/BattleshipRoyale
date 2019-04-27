#pragma once
#include "ofApp.h"
#include <vector>
class block {
public:
	std::vector<int> GetColor();
	block(int R, int G, int B, float x, float y);
	void Resize();
	int GetWidth();
	int GetHeight();
	int GetX();
	int GetY();
	ofRectangle GetRectangle();
private:
	ofRectangle rect;
	int height;
	int width;
	int red;
	int green;
	int blue;
	int x;
	int y;

};
