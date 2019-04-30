#pragma once
#include <vector>
//#include "ofApp.h"
#include "ofGraphics.h"
class block {
public:
	block(int R, int G, int B, float x, float y);
private:
	int height;
	int width;
	int red;
	int green;
	int blue;
	int x;
	int y;

};
