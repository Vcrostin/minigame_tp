#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>

class Game
{
private:
	// Variables

	// Window
	sf::RenderWindow* window;
	sf::VideoMode videoMode;
	sf::Event event;
	sf::RectangleShape background;


	void initVariables();
	void initWindow();

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

