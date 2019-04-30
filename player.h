#pragma once
#include <vector>
#include "block.h"
class player {
public:
	void SetPosition(float x, float y);
	void SetSize(float w, float h);
	float GetWidth();
	float GetHeight();
	float GetXPos();
	float GetYPos();
	int GetInventorySize();
	void AddItem();
	void RemoveItem();
	void SetColor(std::string color);
	std::vector<int> GetColor();
	void SetId(int new_id);
	int GetId();
	void UpdatePlayer();
private:
	int inventory = 0;
	static const int kMaxInventorySize = 5;
	float width;
	float height;
	float x_pos;
	float y_pos;
	int R;
	int G;
	int B;
	int id;
};
