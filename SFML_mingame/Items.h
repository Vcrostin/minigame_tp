#pragma once
#include <string>
#include <SFML/Graphics.hpp>
#include <iostream>

class Sword {
public:
	Sword();
private:
	std::string name = "Sword";
	//TODO: Добавить Sqord;
	std::string source = "resours/Sword.png";
	sf::Texture texture;
	sf::Sprite sprite;
};

class Knife {
public:
	Knife();
private:
	std::string name = "Knife";
	//TODO: Добавить Sqord;
	std::string source = "resours/Knife.png";
	sf::Texture texture;
	sf::Sprite sprite;
};

class Armor {
public:
	Armor();
private:
	std::string name = "Armor";
	//TODO: Добавить Sqord;
	std::string source = "resours/Armor.png";
	sf::Texture texture;
	sf::Sprite sprite;
};

class Shield {
public:
	Shield();
private:
	std::string name = "Shield";
	std::string source = "resours/Shield.png";
	sf::Texture texture;
	sf::Sprite sprite;
};

class Helmet {
public:
	Helmet();
private:
	std::string name = "Shield";
	std::string source = "resours/Shield.png";
	sf::Texture texture;
	sf::Sprite sprite;
};