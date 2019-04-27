#pragma once
#include "block.h"
std::vector<int> block::GetColor()
{
	std::vector<int> colors;
	colors.push_back(red);
	colors.push_back(green);
	colors.push_back(blue);

}

block::block(int R, int G, int B, float x_pos, float y_pos)
{
	red = R;
	green = G;
	blue = B;
	x = x_pos * (ofGetWindowWidth() / 60);
	y = y_pos * (ofGetWindowHeight() / 35);
	Resize();
}

void block::Resize()
{
	width = ofGetWindowWidth() / 60;
	height = ofGetWindowHeight() / 35;
	rect = ofRectangle(x, y, width, height);
}

int block::GetWidth()
{
	return width;
}

int block::GetHeight()
{
	return height;
}

int block::GetX()
{
	return x;
}

int block::GetY()
{
	return y;
}

ofRectangle block::GetRectangle()
{
	return rect;
}
