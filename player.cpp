#include"player.h";
#include <vector>;
#include "ofApp.h";

player::player(float x, float y, int set_id, int R, int G, int B)
{
	player_block = new Block(R, G, B, x, y);
	id = set_id;

}

void player::SetPosition(float x, float y) //keep updating player class
{
	player_block->Reposition(x, y);
}

float player::GetWidth()
{
	return player_block->GetWidth();
}

float player::GetHeight()
{
	return player_block->GetHeight();
}

float player::GetXPos()
{
	return player_block->GetX();
}

float player::GetYPos()
{
	return player_block->GetY();
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
	player_block->Resize();
}

Block * player::GetPlayerBlock()
{
	return player_block;
}

