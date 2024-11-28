#pragma once

class Player
{
public:
	int getPlayerX();
	void setPlayerX(int arg);
	int getPlayerY();
	void setPlayerY(int arg);


private:
	int playerX;
	int playerY;
};