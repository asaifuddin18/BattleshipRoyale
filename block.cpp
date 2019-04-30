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
	if (x_pos > 60) {
		array_x = 60;
	}
	else if (x_pos < 0) {
		array_x = 0;
	}
	else {
		array_x = x_pos;
	}
	if (y_pos > 35) {
		array_y = 35;
	}
	else if (y_pos < 0) {
		array_y = 0;
	}
	else {
		array_y = y_pos;
	}
	Resize();
	empty = false;
}

Block::Block()
{
}

void Block::Resize()
{
	x = (array_x) * (ofGetWindowWidth() / 60);
	y = (array_y) * (ofGetWindowHeight() / 35);
	width = ofGetWindowWidth() / 60;
	height = ofGetWindowHeight() / 35;
	rect = ofRectangle(x, y, width, height);
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
