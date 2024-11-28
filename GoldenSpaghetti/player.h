#pragma once
#include <SFML/Graphics.hpp>

class Player
{
public:
	int getPlayerX();
	void setPlayerX(int arg);
	int getPlayerY();
	void setPlayerY(int arg);
	void setTexture(sf::Texture);
	void setTextureRect(sf::IntRect);
	void setColor(sf::Color);
	sf::Sprite getSprite();


private:
	int playerX;
	int playerY;
	sf::Sprite sprite;
};