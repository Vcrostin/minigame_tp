#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
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
	


	void initVariables();
	void initWindow();

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
};

