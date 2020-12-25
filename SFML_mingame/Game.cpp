#include "Game.h"

std::string strToInt(int a) {
	std::string hp = "";
	for (; a > 0; a /= 10) {
		hp.push_back(a % 10 + '0');
	}
	reverse(hp.begin(), hp.end());
	return hp;
}

// Constructor / Destructor

Game::Game() {
	initVariables();
	initWindow();
	initCrown();
}

Game::~Game() {
	delete window;
}

void Game::initVariables() {
	window = nullptr;
	videoMode.width = 1980;
	videoMode.height = 1080;

	// set Hero
	hero.setTexture("resours/Hero_norm.png");
	hero.setPosition(sf::Vector2f(videoMode.width / 2, videoMode.height / 2));
}

void Game::initWindow() {
	window = new sf::RenderWindow(videoMode, "Game");
	window->setFramerateLimit(60);

	// set Background
	background.setSize(sf::Vector2f(videoMode.width, videoMode.height - 40));
	background.setFillColor(sf::Color(0, 51, 0));
	background.setPosition(sf::Vector2f(0, 40));
	background.setOutlineThickness(3);
	background.setOutlineColor(sf::Color::White);
}

void Game::initCrown() {
	if (!font.loadFromFile("resours/font.ttf")) {
		std::cout << "Error.\n";
		exit(1);
	}
}

sf::Text Game::crown(std::string word, sf::Vector2f a) {
	sf::Text text;
	text.setFont(font);
	text.setString(word);
	text.setPosition(a);
	return text;
}

bool Game::heroCheckBorder(sf::Vector2f a) {
	return hero.checkBorder(a, videoMode);
}

void Game::update() {
	pollEvent();

	// Mouse position in display
	//std::cout << "Mouse pos: " << sf::Mouse::getPosition().x << ' '
	//	<< sf::Mouse::getPosition().y << "\n";
	/*std::cout << "Mouse pos: " << sf::Mouse::getPosition(*window).x << ' '
		<< sf::Mouse::getPosition(*window).y << "\n";*/
}

void Game::render() {
	window->clear(sf::Color::Black);

	window->draw(background);
	window->draw(hero.getSprite());
	window->draw(crown("HP: " + strToInt(hero.getHP()), sf::Vector2f(5, 5)));
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
			if (event.key.code == sf::Keyboard::W && heroCheckBorder(sf::Vector2f(0, -5)))
				hero.move(sf::Vector2f(0, -5));
			if (event.key.code == sf::Keyboard::A && heroCheckBorder(sf::Vector2f(-5, 0)))
				hero.move(sf::Vector2f(-5, 0));
			if (event.key.code == sf::Keyboard::S && heroCheckBorder(sf::Vector2f(0, 5)))
				hero.move(sf::Vector2f(0, 5));
			if (event.key.code == sf::Keyboard::D && heroCheckBorder(sf::Vector2f(5, 0)))
				hero.move(sf::Vector2f(5, 0));
			std::cout << hero.getSprite().getPosition().x << ' ' << hero.getSprite().getPosition().y << '\n';
			break;
		}
	}
}

bool Game::running() {
	return window->isOpen();
}


