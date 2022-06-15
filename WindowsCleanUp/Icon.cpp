#include "Icon.h"
#include<iostream>

using namespace sf;

void Icon::initShape(const RenderWindow& window, Vector2f playerPos)
{
	this->shape.setTextureRect(IntRect(0, 0, 35, 35));
	this->shape.setPosition( //randomowa pozycja
		Vector2f(
			static_cast<float>(rand() % (window.getSize().x - 20) - this->shape.getGlobalBounds().width + 20),
			static_cast<float>(rand() % (window.getSize().y - 50) - this->shape.getGlobalBounds().height + 20) //30 to szerokosc paska XP, 20 to margines
		)
	);
	while (shape.getPosition().y >= playerPos.y and shape.getPosition().y <= (playerPos.y + 300) //zapobiega spawnie wokol gracza
		and shape.getPosition().x >= playerPos.x and shape.getPosition().x <= (playerPos.x + 300)
		) 
	{ 
		this->shape.setPosition( 
			Vector2f(
				static_cast<float>(rand() % (window.getSize().x - 20) - this->shape.getGlobalBounds().width + 20),
				static_cast<float>(rand() % (window.getSize().y - 50) - this->shape.getGlobalBounds().height + 20) //30 to szerokosc paska XP, 20 to margines
			)
		);
	}
}


Icon::Icon(const RenderWindow& window, int type, Vector2f playerPos)
{
	this->type = type;
	this->initShape(window, playerPos);
}

Icon::~Icon()
{
}

Sprite Icon::getShape()
{
	return this->shape;
}

const int & Icon::getType() const
{
	return this->type;
}

const Vector2f & Icon::getPosition() const
{
	return this->shape.getPosition();
}

void Icon::renderXP(RenderTarget & target)
{
	switch (this->type)
	{
	case MALWARE:
		this->texture.loadFromFile("Textures/XP/malware.png");
		this->shape.setTexture(texture);
		break;
	case MALWARE2:
		this->texture.loadFromFile("Textures/XP/malware2.png");
		this->shape.setTexture(texture);
		break;
	case ANTIVIRUS:
		this->texture.loadFromFile("Textures/XP/antivirus.png");
		this->shape.setTexture(texture);
		break;
	case Win98:
		this->texture.loadFromFile("Textures/XP/Win98.png");
		this->shape.setTexture(texture);
		break;
	case WinXP:
		this->texture.loadFromFile("Textures/98/WinXP.png");
		this->shape.setTexture(texture);
		break;
	case PowerUp:
		this->texture.loadFromFile("Textures/XP/PowerUp.png");
		this->shape.setTexture(texture);
		break;
	}
	target.draw(this->shape);
}

void Icon::render98(RenderTarget & target)
{
	switch (this->type)
	{
	case MALWARE:
		this->texture.loadFromFile("Textures/98/malware.png");
		this->shape.setTexture(texture);
		break;
	case MALWARE2:
		this->texture.loadFromFile("Textures/98/malware2.png");
		this->shape.setTexture(texture);
		break;
	case ANTIVIRUS:
		this->texture.loadFromFile("Textures/98/antivirus.png");
		this->shape.setTexture(texture);
		break;
	case Win98:
		this->texture.loadFromFile("Textures/XP/Win98.png");
		this->shape.setTexture(texture);
		break;
	case WinXP:
		this->texture.loadFromFile("Textures/98/WinXP.png");
		this->shape.setTexture(texture);
		break;
	case PowerUp:
		this->texture.loadFromFile("Textures/98/PowerUp.png");
		this->shape.setTexture(texture);
		break;
	}
	target.draw(this->shape);
}
