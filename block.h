#pragma once
#include "ofGraphics.h"
#include <vector>
class block {
public:
	std::vector<int> GetColor();
	block(int R, int G, int B, float x, float y);
	block();
	void Resize();
	int GetWidth();
	int GetHeight();
	int GetX();
	int GetY();
	ofRectangle GetRectangle();
	bool IsEmpty();
	void SetEmpty();
private:
	ofRectangle rect;
	int height;
	int width;
	int red;
	int green;
	int blue;
	int x;
	int y;
	int array_x;
	int array_y;
	bool empty = true;

};
