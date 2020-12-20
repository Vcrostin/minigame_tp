#include "Hero.h"

Hero::Hero() {}

Hero::Hero(std::string fname) {
	setTexture(fname);
}

Hero::~Hero() { }

void Hero::setTexture(std::string fname) {
	if (texture.loadFromFile(fname)) {
		sprite.setTexture(texture);
	}	
}

void Hero::setTexture(sf::Texture& text) {
	texture = text;
	sprite.setTexture(texture);
}

void Hero::setPosition(sf::Vector2f a) {
	sprite.setPosition(a);
}

void Hero::move(sf::Vector2f a) {
	sprite.move(a);
}

sf::Sprite Hero::getSprite() {
	return sprite;
}
