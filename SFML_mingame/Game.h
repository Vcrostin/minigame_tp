#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include "Hero.h"

class Game
{
private:
	// Variables
	Hero hero;
	// Window
	sf::RenderWindow* window;
	sf::VideoMode videoMode;
	sf::Event event;
	sf::RectangleShape background;
	sf::Font font;
	std::vector<Hero> enemy; // to do

	void initVariables();
	void initWindow();
	void initCrown();
	// Logic
	bool heroCheckBorder(sf::Vector2f a);

public:
	// Constructor / Destructor

	Game();
	~Game();

	// Functions

	void update();
	void render();

	void pollEvent();
	bool running();

	sf::Text crown(std::string word, sf::Vector2f a);
};

