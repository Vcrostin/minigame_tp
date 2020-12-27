#include "Items.h"

Sword::Sword()
{
	if (texture.loadFromFile(source)) {
		sprite.setTexture(texture);
	}
}

Knife::Knife()
{
	if (texture.loadFromFile(source)) {
		sprite.setTexture(texture);
	}
}

Armor::Armor()
{
	if (texture.loadFromFile(source)) {
		sprite.setTexture(texture);
	}
}

Shield::Shield()
{
	if (texture.loadFromFile(source)) {
		sprite.setTexture(texture);
	}
}

Helmet::Helmet()
{
	if (texture.loadFromFile(source)) {
		sprite.setTexture(texture);
	}
}
