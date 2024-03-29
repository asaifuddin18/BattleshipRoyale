#pragma once
#include "ofGraphics.h"
#include <vector>
class Block {
public:
	std::vector<int> GetColor();
	Block(int R, int G, int B, float x, float y);
	Block();
	void Resize();
	int GetWidth();
	int GetHeight();
	ofRectangle GetRectangle();
	bool IsEmpty();
	void SetEmpty();
	void Reposition(int set_x, int set_y);
	int GetX();
	int GetY();
private:
	int max_x = 60;
	int max_y = 35;
	ofRectangle rect;
	int height;
	int width;
	int red;
	int green;
	int blue;
	int x;
	int y;
	bool empty = true;

};
