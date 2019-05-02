#pragma once
#include "block.h"
#include "ofAppRunner.h"
std::vector<int> Block::GetColor()
{
	std::vector<int> colors = { red, green, blue };
	return colors;

}
/*
R = 0-256
G = 0-256
B = 0-256
x_pos = 0-60
y_pos = 0-35
*/
Block::Block(int R, int G, int B, float x_pos, float y_pos)
{
	red = R;
	green = G;
	blue = B;
	Reposition(x_pos, y_pos);
	empty = false;
}

Block::Block()
{
}

void Block::Resize()
{
	int rect_x = (x) * (ofGetWindowWidth() / max_x);
	int rect_y = (y) * (ofGetWindowHeight() / max_y);
	width = ofGetWindowWidth() / max_x;
	height = ofGetWindowHeight() / max_y;
	rect = ofRectangle(rect_x, rect_y, width, height);
}

int Block::GetWidth()
{
	return width;
}

int Block::GetHeight()
{
	return height;
}

int Block::GetX()
{
	return x;
}

int Block::GetY()
{
	return y;
}

ofRectangle Block::GetRectangle()
{
	return rect;
}

bool Block::IsEmpty()
{
	return empty;
}

void Block::SetEmpty()
{
	empty = true;
}

void Block::Reposition(int set_x, int set_y)
{
	if (set_x > max_x) {
		x = max_x;
	}
	else if (set_x < 0) {
		x = 0;
	}
	else {
		x = set_x;
	}
	if (set_y > max_y) {
		y = max_y;
	}
	else if (set_y < 0) {
		y = 0;
	}
	else {
		y = set_y;
	}
	Resize();
}
