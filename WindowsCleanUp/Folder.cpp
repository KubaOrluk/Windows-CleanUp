#include "Folder.h"
#include<iostream>

using namespace sf;

void Folder::initShape(const RenderWindow& window, Vector2f playerPos)
{
	this->shape.setTextureRect(IntRect(0, 0, 35, 35));
	this->shape.setPosition( //randomowa pozycja
		Vector2f(
			static_cast<float>(rand() % (window.getSize().x - 20)- this->shape.getGlobalBounds().width + 20),
			static_cast<float>(rand() % (window.getSize().y - 50) - this->shape.getGlobalBounds().height + 20) //30 to szerokosc paska XP, 20 to margines
		)
	);

	while (shape.getPosition().y >= playerPos.y and shape.getPosition().y <= (playerPos.y + 50) //zapobiega spawnie wokol gracza
		and shape.getPosition().x >= playerPos.x and shape.getPosition().x <= (playerPos.x + 50)
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


Folder::Folder(const RenderWindow& window, int type, Vector2f playerPos)
{
	this->type = type;
	this->initShape(window, playerPos);
}

Folder::~Folder()
{
}

Sprite Folder::getShape()
{
	return this->shape;
}

const int & Folder::getType() const
{
	return this->type;
}

void Folder::renderXP(RenderTarget & target)
{
	switch (this->type)
	{
	case FOLDER1:
		this->texture.loadFromFile("Textures/XP/folder1.png");
		this->shape.setTexture(texture);
		break;
	case FOLDER2:
		this->texture.loadFromFile("Textures/XP/folder2.png");
		this->shape.setTexture(texture);
		break;
	case FOLDER3:
		this->texture.loadFromFile("Textures/XP/folder3.png");
		this->shape.setTexture(texture);
		break;
	case FOLDER4:
		this->texture.loadFromFile("Textures/XP/folder4.png");
		this->shape.setTexture(texture);
		break;
	}
		target.draw(this->shape);
}

void Folder::render98(RenderTarget & target)
{
	switch (this->type)
	{
	case FOLDER1:
		this->texture.loadFromFile("Textures/98/folder1.png");
		this->shape.setTexture(texture);
		break;
	case FOLDER2:
		this->texture.loadFromFile("Textures/98/folder2.png");
		this->shape.setTexture(texture);
		break;
	case FOLDER3:
		this->texture.loadFromFile("Textures/98/folder3.png");
		this->shape.setTexture(texture);
		break;
	case FOLDER4:
		this->texture.loadFromFile("Textures/98/folder4.png");
		this->shape.setTexture(texture);
		break;
		
	}
	target.draw(this->shape);
}
