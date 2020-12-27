#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>

class Hero {
private:
	sf::Texture texture;
	sf::Sprite sprite;

	int healthPoint;

public: 
	Hero(int a = 0);
	Hero(std::string fname);
	~Hero();

	void setTexture(std::string fname);
	void setTexture(sf::Texture& text);
	void setPosition(sf::Vector2f a);
	void setHP(int a);
	void move(sf::Vector2f a);
	
	sf::Sprite getSprite();
	int getHP();

	bool checkBorder(sf::Vector2f& a, sf::VideoMode& b);
};

