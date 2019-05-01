#pragma once
#include <vector>
#include "player.h"
#include "ofGraphics.h"
class Rocket {
public:
	Rocket(Player* player);
	void SetSize(float w, float h);
	void SetVelocity(float v);
	void SetPosition(float x, float y);
	float GetX();
	float GetY();
	void SetColor(int R, int G, int B);
	std::vector<int> GetColor();
	void Update();
	float GetWidth();
	float GetHeight();
	float GetVelocity();
	Block* GetBlock();
private:
	Block* rocket_block;
	float width;
	float height;
	float velocity;
	float x_pos;
	float y_pos;
	int red;
	int green;
	int blue;
	void UpdatePosition();
};