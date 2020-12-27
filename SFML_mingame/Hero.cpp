#include "Hero.h"

Hero::Hero(int a) {
	healthPoint = 100 + a * 10;
}

Hero::Hero(std::string fname) {
	healthPoint = 100;
	setTexture(fname);
}

Hero::~Hero() { }

void Hero::setTexture(std::string fname) {
	if (texture.loadFromFile(fname)) {
		sprite.setTexture(texture);
		std::cout << "Hero size: " << texture.getSize().x << ' ' << texture.getSize().y << '\n';
	}	
}

void Hero::setTexture(sf::Texture& text) {
	texture = text;
	sprite.setTexture(texture);
	std::cout << "Hero size: " << texture.getSize().x << ' ' << texture.getSize().y << '\n';
}

void Hero::setPosition(sf::Vector2f a) {
	sprite.setPosition(a);
}

void Hero::setHP(int a) {
	healthPoint -= a;
}

void Hero::move(sf::Vector2f a) {
	sprite.move(a);
}

sf::Sprite Hero::getSprite() {
	return sprite;
}

int Hero::getHP() {
	return healthPoint;
}

bool Hero::checkBorder(sf::Vector2f& a, sf::VideoMode& b) {
	if (sprite.getPosition().y + a.y < 40 || sprite.getPosition().x + a.x < 0
		|| b.height - texture.getSize().y - a.y < sprite.getPosition().y
		|| b.width < sprite.getPosition().x + texture.getSize().x + a.x) {
		std::cout << "False\n";
		return 0;
	}

	/*if (0 > sprite.getPosition().x + a.x || sprite.getPosition().x + a.x > b.width - sprite.getTexture()->getSize().x
		|| sprite.getPosition().y + a.y < 40 || sprite.getPosition().x + a.y > b.height - sprite.getTexture()->getSize().y) {
		std::cout << "False\n";
		return 0;
	}*/
	return 1;
}