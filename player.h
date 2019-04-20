#pragma once
#include <vector>
class player {
public:
	void SetPosition(int x, int y);
	void SetSize(int w, int h);
	int GetWidth();
	int GetHeight();
	int GetXPos();
	int GetYPos();
	int GetInventorySize();
	void AddItem();
	void RemoveItem();
	void SetColor(std::string color);
	std::vector<int> GetColor();
private:
	int inventory = 0;
	static const int kMaxInventorySize = 5;
	int width;
	int height;
	int x_pos;
	int y_pos;
	int R;
	int G;
	int B;
};
