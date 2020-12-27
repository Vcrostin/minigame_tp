#pragma once
#include <string>
#include <SFML/Graphics.hpp>
//__interface IItem
//{
//	//���
//public:
//	virtual std::string GetName();
//	//����
//	virtual int GetValue();
//	//����. ���-�� ��������� � �����
//	virtual int GetStack();
//};
//
//__interface IArmor :IItem
//{
//public:
//	//���������
//	virtual int Strength();
//	//������ �����
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
	//TODO: �������� Sqord;
	std::string source = "resours/Sword.png";
	sf::Texture texture;
	sf::Sprite sprite;
};

class Knife {
public:
	Knife();
private:
	std::string name = "Knife";
	//TODO: �������� Sqord;
	std::string source = "resours/Knife.png";
	sf::Texture texture;
	sf::Sprite sprite;
};
