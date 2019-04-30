#include "rocket.h"
#include <iostream>

rocket::rocket(player player)
{
	width = player.GetWidth();
	height = player.GetHeight();
	x_pos = player.GetXPos();
	y_pos = player.GetYPos();
	velocity = player.GetHeight() / 2;
	//acceleration = height / 20;
	acceleration = 0;
	//acceleration disabled
	if (player.GetId() == 1) {
		y_pos += height;
		//acceleration = height / 20;
	}
	else {
		y_pos -= height;
		//acceleration = -(height / 20);
	}
	red = player.GetColor()[0] / 2;
	green = player.GetColor()[1] / 2;
	blue = player.GetColor()[2] / 2;
	rect = ofRectangle(x_pos, y_pos, width, height);

}

void rocket::SetSize(float w, float h)
{
	width = w;
	height = h;
}

void rocket::SetVelocity(float v)
{
	velocity = v;
}

void rocket::SetAcceleration(float a)
{
	acceleration = a;
}

void rocket::SetPosition(float x, float y)
{
	x_pos = x;
	y_pos = y;
}

float rocket::GetX()
{
	return x_pos;
}

float rocket::GetY()
{
	return y_pos;
}

void rocket::SetColor(int R, int G, int B)
{
	red = R;
	green = G;
	blue = B;
}

std::vector<int> rocket::GetColor()
{
	std::vector<int> colors;
	colors.push_back(red);
	colors.push_back(green);
	colors.push_back(blue);
	return colors;
}

void rocket::Update()
{
	SpeedUp();
	UpdatePosition();
	//std::cout << "X " << x_pos << " Y " << y_pos << std::endl;
	rect = ofRectangle(x_pos, y_pos, width, height);
}

float rocket::GetWidth()
{
	return width;
}

float rocket::GetHeight()
{
	return height;
}

float rocket::GetVelocity()
{
	return velocity;
}

void rocket::Reflect()
{
	velocity = -velocity;
	acceleration = -acceleration;
}

ofRectangle rocket::GetRectangle()
{
	return rect;
}

void rocket::SpeedUp()
{
	velocity += acceleration;
}

void rocket::UpdatePosition()
{
	//std::cout << y_pos << " BEFORE" << std::endl;
	y_pos += velocity;
	//std::cout << y_pos << " AFTER" << std::endl;
}



