#pragma once
#include <vector>
#include "block.h"
class Player {
public:
	Player(float x, float y, int set_id, int R, int G, int B);
	void SetPosition(float x, float y);
	float GetWidth();
	float GetHeight();
	float GetXPos();
	float GetYPos();
	int GetInventorySize();
	void AddItem();
	void RemoveItem();
	std::vector<int> GetColor();
	void SetId(int new_id);
	int GetId();
	void UpdatePlayer();
	Block* GetPlayerBlock();
private:
	Block *player_block;
	int inventory = 0;
	static const int kMaxInventorySize = 5;
	float width;
	float height;
	float x_pos;
	float y_pos;
	int red;
	int green;
	int blue;
	int id;
};
