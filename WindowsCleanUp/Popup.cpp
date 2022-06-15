#include "Popup.h"
#include<iostream>

using namespace sf;

void Popup::initShape(const RenderWindow& window)
{
	this->textureXP1.loadFromFile("Textures/XP/ad.png");
	this->textureXP2.loadFromFile("Textures/XP/ad2.png");
	this->textureXP3.loadFromFile("Textures/XP/ad3.png");
	this->textureXP4.loadFromFile("Textures/XP/ad4.png");

	this->texture981.loadFromFile("Textures/98/ad.png");
	this->texture982.loadFromFile("Textures/98/ad2.png");
	this->texture983.loadFromFile("Textures/98/ad3.png");
	this->texture984.loadFromFile("Textures/98/ad4.png");

	this->shape.setPosition( //randomowa pozycja
		Vector2f(
			static_cast<float>(rand() % (window.getSize().x)/2),
			static_cast<float>(rand() % (window.getSize().y/2))
		)
	);
}


Popup::Popup(const RenderWindow& window, int type)
{
	this->type = type;
	this->initShape(window);
}

Popup::~Popup()
{
}

const int & Popup::getType() const
{
	return this->type;
}

void Popup::renderXP(RenderTarget & target)
{
	switch (this->type)
	{
	case AD1:
		this->shape.setTexture(textureXP1);
		break;
	case AD2:
		this->shape.setTexture(textureXP2);
		break;
	case AD3:
		this->shape.setTexture(textureXP3);
		break;
	case AD4:
		this->shape.setTexture(textureXP4);
		break;
	}
	target.draw(this->shape);
}

void Popup::render98(RenderTarget & target)
{
	switch (this->type)
	{
	case AD1:
		this->shape.setTexture(texture981);
		break;
	case AD2:
		this->shape.setTexture(texture982);
		break;
	case AD3:
		this->shape.setTexture(texture983);
		break;
	case AD4:
		this->shape.setTexture(texture984);
		break;
	}
	target.draw(this->shape);
}
