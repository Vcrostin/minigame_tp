#include "Game.h"

// Constructor / Destructor

Game::Game() {
	initVariables();
	initWindow();
}

Game::~Game() {
	delete window;
}

void Game::initVariables() {
	window = nullptr;
}

void Game::initWindow() {
	videoMode.width = 800;
	videoMode.height = 600;

	window = new sf::RenderWindow(videoMode, "Game");
	window->setFramerateLimit(60);

	background.setSize(sf::Vector2f(videoMode.width, videoMode.height - 40));
	background.setFillColor(sf::Color(0, 51, 0));
	background.setPosition(sf::Vector2f(0, 40));
	background.setOutlineThickness(0.5f);
	background.setOutlineColor(sf::Color::White);
}

void Game::update() {
	pollEvent();

	// Mouse position in display
	//std::cout << "Mouse pos: " << sf::Mouse::getPosition().x << ' '
	//	<< sf::Mouse::getPosition().y << "\n";

	std::cout << "Mouse pos: " << sf::Mouse::getPosition(*window).x << ' '
		<< sf::Mouse::getPosition(*window).y << "\n";
}

void Game::render() {
	window->clear(sf::Color::Black);

	window->draw(background);
	// to do


	window->display();
}

void Game::pollEvent() {
	while (window->pollEvent(event)) {
		switch (event.type) {
		case (sf::Event::Closed):
			window->close();
			break;
		case (sf::Event::KeyPressed):
			if (event.key.code == sf::Keyboard::Escape)
				window->close();
			break;
		}
	}
}

bool Game::running() {
	return window->isOpen();
}
