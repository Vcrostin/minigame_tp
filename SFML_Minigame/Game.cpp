#include "Game.h"


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
}


void Game::pollEvent() {
	while (window->pollEvent(event)) {
		switch (event.type) {
		case sf::Event::Closed:
			window->close();
			break;
		case sf::Event::KeyPressed:
			if (event.key.code == sf::Keyboard::Escape)
				window->close();
			// to do
			break;

		}
	}
}

void Game::update() {
	pollEvent();
	// to do
}

void Game::render() {
	window->clear(sf::Color(0, 51, 0));

	// to do
	// window->draw(...);

	window->display();
}


bool Game::running() {
	return window->isOpen();
}