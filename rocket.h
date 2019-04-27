#pragma once
#include <vector>
#include "player.h"
class rocket {
public:
	rocket(player player);
	void SetSize(float w, float h);
	void SetVelocity(float v);
	void SetAcceleration(float a);
	void SetPosition(float x, float y);
	float GetX();
	float GetY();
	void SetColor(int R, int G, int B);
	std::vector<int> GetColor();
	void Update();
	float GetWidth();
	float GetHeight();
	float GetVelocity();
	void Reflect();
private:
	float width;
	float height;
	float velocity;
	float acceleration;
	float x_pos;
	float y_pos;
	int red;
	int green;
	int blue;
	void SpeedUp();
	void UpdatePosition();
};