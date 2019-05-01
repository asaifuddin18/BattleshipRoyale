#pragma once
#include "block.h"
#include "ofAppRunner.h"
std::vector<int> Block::GetColor()
{
	std::vector<int> colors;
	colors.push_back(red);
	colors.push_back(green);
	colors.push_back(blue);
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
	int rect_x = (x) * (ofGetWindowWidth() / 60);
	int rect_y = (y) * (ofGetWindowHeight() / 35);
	width = ofGetWindowWidth() / 60;
	height = ofGetWindowHeight() / 35;
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
	if (set_x > 60) {
		x = 60;
	}
	else if (set_x < 0) {
		x = 0;
	}
	else {
		x = set_x;
	}
	if (set_y > 35) {
		y = 35;
	}
	else if (set_y < 0) {
		y = 0;
	}
	else {
		y = set_y;
	}
	Resize();
}
