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
	int GetX();
	int GetY();
	ofRectangle GetRectangle();
	bool IsEmpty();
	void SetEmpty();
	void Reposition(int set_x, int set_y);
	int GetXArray();
	int GetYArray();
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
