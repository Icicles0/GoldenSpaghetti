#include "player.h"
#include <SFML/Graphics.hpp>

int Player::getPlayerX()
{
	return playerX;
}

int Player::getPlayerY()
{
	return playerY;
}

void Player::setPlayerX(int arg)
{
	playerX = arg;
	sprite.setPosition(sf::Vector2f(arg, playerY));
}

void Player::setPlayerY(int arg)
{
	playerY = arg;
	sprite.setPosition(sf::Vector2f(playerX, arg));
}

void Player::setTexture(sf::Texture texture)
{
	sprite.setTexture(texture);
}

void Player::setTextureRect(sf::IntRect rect)
{
	sprite.setTextureRect(rect);
}

void Player::setColor(sf::Color color)
{
	sprite.setColor(color);
}

sf::Sprite Player::getSprite()
{
	return sprite;
}