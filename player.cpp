#include"player.h";
#include <vector>;
#include "ofApp.h";

Player::Player(float x, float y, int set_id, int R, int G, int B)
{
	player_block = new Block(R, G, B, x, y);
	id = set_id;
	red = R;
	green = G;
	blue = B;

}

void Player::SetPosition(float x, float y) //keep updating player class
{
	player_block->Reposition(x, y);
}

float Player::GetWidth()
{
	return player_block->GetWidth();
}

float Player::GetHeight()
{
	return player_block->GetHeight();
}

float Player::GetXPos()
{
	return player_block->GetX();
}

float Player::GetYPos()
{
	return player_block->GetY();
}

int Player::GetInventorySize()
{
	return inventory;
}

void Player::AddItem()
{
	inventory++;
}

void Player::RemoveItem()
{
	inventory--;
}

std::vector<int> Player::GetColor()
{
	std::vector<int> colors = { red, green, blue };
	return colors;
}

void Player::SetId(int new_id)
{
	id = new_id;
}

int Player::GetId()
{
	return id;
}

void Player::UpdatePlayer()
{
	player_block->Resize();
}

Block * Player::GetPlayerBlock()
{
	return player_block;
}

