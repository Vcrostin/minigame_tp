#include "Game.h"

std::string strToInt(int a) {
	std::string hp = "";
	bool flag = a < 0 ? 1 : 0;
	if (flag)
		a = -a;
	for (; a > 0; a /= 10) {
		hp.push_back(a % 10 + '0');
	}
	if (flag)
		hp.push_back('-');
	reverse(hp.begin(), hp.end());
	return hp;
}

int qrt(int a) {
	return a * a;
}

// Constructor / Destructor

Game::Game() {
	srand(time(0));
	initVariables();
	initWindow();
	initCrown();
}

Game::~Game() {
	delete window;
}

void Game::initVariables() {
	window = nullptr;
	videoMode.width = 1920;
	videoMode.height = 1080;

	// set Hero
	hero.setTexture("resours/Hero_norm.png");
	hero.setPosition(sf::Vector2f(videoMode.width / 2, videoMode.height / 2));

	//set Enemy
	enemy.resize(30);
	sprites.resize(10);
	texture.resize(3);
	texture[2].loadFromFile("resours/enemy3.png");
	texture[1].loadFromFile("resours/enemy2.png");
	texture[0].loadFromFile("resours/enemy1.png");
	sprites[0].setTexture(texture[0]);
	sprites[1].setTexture(texture[1]);
	sprites[2].setTexture(texture[2]);
	for (int i = 0; i < enemy.size(); i++) {
		enemy[i].second = sf::Vector2f(rand() % (int)(videoMode.width - sprites[enemy[i].first.view].getPosition().x), rand() % (int)(videoMode.height - 43 - sprites[enemy[i].first.view].getPosition().y) + 43);
	}
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

void Game::impact() {
	std::vector<std::pair<Enemy, sf::Vector2f> >::iterator iter = enemy.end();
	double srrHero = ((double)hero.getSprite().getTexture()->getSize().x + hero.getSprite().getTexture()->getSize().y) / 4;
	for (int i = 0; i < enemy.size(); i++) {
		double srr = ((double)texture[enemy[i].first.view].getSize().x + texture[enemy[i].first.view].getSize().y )/ 4;
		/*if (hero.getSprite().getPosition().x >= enemy[i].second.x
			&& hero.getSprite().getPosition().x <= enemy[i].second.x + texture[enemy[i].first.view].getSize().x
			&& hero.getSprite().getPosition().y >= enemy[i].second.y
			&& hero.getSprite().getPosition().y <= enemy[i].second.y + texture[en/emy[i].first.view].getSize().y) {
			std::cout << "Danger\n";
		}*/
		if (sqrt(qrt(srrHero + hero.getSprite().getPosition().x - (srr + enemy[i].second.x)) + qrt(srrHero + hero.getSprite().getPosition().y - (srr + enemy[i].second.y))) < (srrHero + srr)) {
			iter = enemy.begin() + i;
		}
	}
	if (iter != enemy.end()) {
		enemy.erase(iter);
		hero.setHP(20);
		if (hero.getHP() <= 0)
			window->close();
	}
}

void Game::update() {
	pollEvent();
	impact();
	// Mouse position in display
	//std::cout << "Mouse pos: " << sf::Mouse::getPosition().x << ' '
	//	<< sf::Mouse::getPosition().y << "\n";
	/*std::cout << "Mouse pos: " << sf::Mouse::getPosition(*window).x << ' '
		<< sf::Mouse::getPosition(*window).y << "\n";*/
}

void Game::render() {
	window->clear(sf::Color::Black);

	window->draw(background);
	window->draw(crown("HP: " + strToInt(hero.getHP()), sf::Vector2f(5, 5)));
	for (int i = 0; i < enemy.size(); i++) {
		sprites[enemy[i].first.view].setPosition(enemy[i].second);
		window->draw(sprites[enemy[i].first.view]);
	}
	window->draw(hero.getSprite());
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


