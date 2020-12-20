#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>

class Hero {
private:
	sf::Texture texture;
	sf::Sprite sprite;

public: 
	Hero();
	Hero(std::string fname);
	~Hero();

	void setTexture(std::string fname);
	void setTexture(sf::Texture& text);
	void setPosition(sf::Vector2f a);
	void move(sf::Vector2f a);
	
	sf::Sprite getSprite();

	bool checkBorder(sf::Vector2f& a, sf::VideoMode& b);
};

