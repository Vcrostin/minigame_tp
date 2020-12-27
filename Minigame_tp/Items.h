#pragma once
#include <string>
#include <SFML/Graphics.hpp>
//__interface IItem
//{
//	//имя
//public:
//	virtual std::string GetName();
//	//цена
//	virtual int GetValue();
//	//макс. кол-во предметов в стаке
//	virtual int GetStack();
//};
//
//__interface IArmor :IItem
//{
//public:
//	//прочность
//	virtual int Strength();
//	//Эффект брони
//	virtual int Buff();
//};
//
//__interface IWeapon
//{
//	virtual int Strength();
//
//	virtual int Damage();
//
//};

class Sword {
public:
	Sword();
private:
	std::string name = "Sword";
	//TODO: Добавить Sqord;
	std::string source = "resours/Sword.png";
	sf::Texture texture;
	sf::Sprite sprite;
};

class Knife {
public:
	Knife();
private:
	std::string name = "Knife";
	//TODO: Добавить Sqord;
	std::string source = "resours/Knife.png";
	sf::Texture texture;
	sf::Sprite sprite;
};
