#pragma once

#include <SFML/Graphics.hpp>
#include <vector>


class Game {
private:
	// Window
	sf::RenderWindow* window;
	sf::VideoMode videoMode;
	sf::Event event;
	//vector<Hero> hero;

	void initVariables();
	void initWindow();
		

public: 

	Game();
	~Game();

	void update();
	void render();

	void pollEvent();
	
	bool running();
};

