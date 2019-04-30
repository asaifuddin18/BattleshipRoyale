#pragma once
#include "block.h"
#include "ofAppRunner.h"
std::vector<int> block::GetColor()
{
	std::vector<int> colors;
	colors.push_back(red);
	colors.push_back(green);
	colors.push_back(blue);
	return colors;

}

block::block(int R, int G, int B, float x_pos, float y_pos)
{
	red = R;
	green = G;
	blue = B;
	array_x = x_pos;
	array_y = y_pos;
	Resize();
	empty = false;
}

block::block()
{
}

void block::Resize()
{
	x = (array_x) * (ofGetWindowWidth() / 60);
	y = (array_y) * (ofGetWindowHeight() / 35);
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

bool block::IsEmpty()
{
	return empty;
}

void block::SetEmpty()
{
	empty = true;
}
