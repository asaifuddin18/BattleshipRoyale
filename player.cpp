#include"player.h";
#include <vector>;
#include "ofApp.h";

void player::SetPosition(int x, int y)
{
	if (x > ofGetWindowWidth() - 10) {
		x_pos = ofGetWindowWidth() - 10;
	}
	else if (x < 0) {
		x_pos = 0;
	}
	else {
		x_pos = x;
	}
	if (y > ofGetWindowHeight() - 10) {
		y_pos = ofGetWindowHeight() - 10;
	}
	else if (y < 0) {
		y_pos = 0;
	}
	else {
		y_pos = y;
	}
}

void player::SetSize(int w, int h)
{
	width = w;
	height = h;
}

int player::GetWidth()
{
	return width;
}

int player::GetHeight()
{
	return height;
}

int player::GetXPos()
{
	return x_pos;
}

int player::GetYPos()
{
	return y_pos;
}

int player::GetInventorySize()
{
	return inventory;
}

void player::AddItem()
{
	inventory++;
}

void player::RemoveItem()
{
	inventory--;
}

void player::SetColor(std::string color)
{
	if (color == "RED") {
		R = 255;
		G = 0;
		B = 0;
	}
	else {
		R = 0;
		G = 255;
		B = 0;
	}
}

std::vector<int> player::GetColor()
{
	std::vector<int> colors;
	colors.push_back(R);
	colors.push_back(B);
	colors.push_back(G);
	return colors;
}
