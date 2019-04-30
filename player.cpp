#include"player.h";
#include <vector>;
#include "ofApp.h";

void player::SetPosition(float x, float y)
{
	float block_width = ofGetWindowWidth() / 60;
	float block_height = ofGetWindowHeight() / 35;
	if (x > ofGetWindowWidth() - block_width) {
		x_pos = ofGetWindowWidth() - block_width;
	}
	else if (x < 0) {
		x_pos = 0;
	}
	else {
		x_pos = x;
	}
	if (y > ofGetWindowHeight() - block_height) {
		y_pos = ofGetWindowHeight() - block_height;
	}
	else if (y < 0) {
		y_pos = 0;
	}
	else {
		y_pos = y;
	}
}

void player::SetSize(float w, float h)
{
	width = w;
	height = h;
}

float player::GetWidth()
{
	return width;
}

float player::GetHeight()
{
	return height;
}

float player::GetXPos()
{
	return x_pos;
}

float player::GetYPos()
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

void player::SetId(int new_id)
{
	id = new_id;
}

int player::GetId()
{
	return id;
}

void player::UpdatePlayer()
{
	float temp_width = ofGetWindowWidth() / 60;
	float temp_height = ofGetWindowHeight() / 35;
	x_pos = (x_pos / width) * temp_width;
	y_pos = (y_pos / height) * temp_height;
	width = temp_width;
	height = temp_height;
}
