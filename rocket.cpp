#include "rocket.h"
#include <iostream>

Rocket::Rocket(Player* player)
{
	x_pos = player->GetPlayerBlock()->GetX();
	y_pos = player->GetPlayerBlock()->GetY();
	if (player->GetId() == 1) {
		velocity = 1;
	}
	else {
		velocity = -1;
	}
	if (player->GetId() == 1) {
		y_pos += 1;
	}
	else {
		y_pos -= 1;
	}
	red = player->GetColor()[0] / 2;
	green = player->GetColor()[1] / 2;
	blue = player->GetColor()[2] / 2;

	rocket_block = new Block(red, green, blue, x_pos, y_pos);

}

void Rocket::SetSize(float w, float h)
{
	width = w;
	height = h;
}

void Rocket::SetVelocity(float v)
{
	velocity = v;
}

void Rocket::SetPosition(float x, float y)
{
	x_pos = x;
	y_pos = y;
}

float Rocket::GetX()
{
	return x_pos;
}

float Rocket::GetY()
{
	return y_pos;
}

void Rocket::SetColor(int R, int G, int B)
{
	red = R;
	green = G;
	blue = B;
}

std::vector<int> Rocket::GetColor()
{
	std::vector<int> colors;
	colors.push_back(red);
	colors.push_back(green);
	colors.push_back(blue);
	return colors;
}

void Rocket::Update()
{
	UpdatePosition();
	rocket_block->Reposition(x_pos, y_pos);
}

float Rocket::GetWidth()
{
	return width;
}

float Rocket::GetHeight()
{
	return height;
}

float Rocket::GetVelocity()
{
	return velocity;
}

Block * Rocket::GetBlock()
{
	return rocket_block;
}

void Rocket::UpdatePosition()
{
	y_pos += velocity;
}



