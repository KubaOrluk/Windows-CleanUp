#include "Player.h"

Player::Player(float x, float y)
{
	this->shape.setPosition(x, y);

	this->initVariables();
	this->initShape();
	this->initTextureXPR();
}

Player::~Player()
{

}

void Player::initVariables()
{
	this->movementSpeed = 2.f;
	this->hpMax = 3; //zycie gracza
	this->hp = hpMax;
	
}

void Player::initShape()
{
	this->shape.setTexture(texture);
	this->shape.setTextureRect(IntRect(0, 0, 35, 35));
}


void Player::initTextureXPL()
{
	this->texture.loadFromFile("Textures/XP/playerL.png");
}

void Player::initTextureXPR()
{
	this->texture.loadFromFile("Textures/XP/playerR.png");
}

void Player::initTexture98L()
{
	this->texture.loadFromFile("Textures/98/playerL.png");
}

void Player::initTexture98R()
{
	this->texture.loadFromFile("Textures/98/playerR.png");
}

void Player::initTextureXPLFull()
{
	this->texture.loadFromFile("Textures/XP/playerLFull.png");
}

void Player::initTextureXPRFull()
{
	this->texture.loadFromFile("Textures/XP/playerRFull.png");
}

void Player::initTexture98LFull()
{
	this->texture.loadFromFile("Textures/98/playerLFull.png");
}

void Player::initTexture98RFull()
{
	this->texture.loadFromFile("Textures/98/playerRFull.png");
}

void Player::playerMovement(float speed)
{
	this->movementSpeed = speed;
}

const Sprite & Player::getShape() const
{
	return this->shape;
}

const float & Player::getHp() const
{
	return this->hp;
}

const float & Player::getHpMax() const
{
	return this->hpMax;
}

const Vector2f & Player::getPosition() const
{
	return this->shape.getPosition();
}

void Player::takeDamage(const int damage)
{
	if (this->hp > 0)
	{
		this->hp -= damage;
	}

	if (this->hp < 0)
	{
		this->hp = 0;
	}

}

void Player::gainHealth(const int health)
{
	if (this->hp < this->hpMax)
	{
		this->hp += health;
	}

	if (this->hp > this->hpMax)
	{
		this->hp = this->hpMax;
	}
}

void Player::setPlayerColor(int R, int G, int B)
{
	this->shape.setColor(Color(R, G, B, 255));
}

void Player::updateInputXP(int points)
{
	//Klawiatura
	if (Keyboard::isKeyPressed(Keyboard::A)) //lewo
	{
		this->shape.move(-this->movementSpeed, 0.f); // x, y
		if (points < 100) 
		{
			this->initTextureXPL();
		}
		else if(points > 100)
		{
			this->initTextureXPLFull();
		}
	}
	else if (Keyboard::isKeyPressed(Keyboard::D)) //prawo
	{
		this->shape.move(this->movementSpeed, 0.f); 
		if (points < 100) 
		{
			this->initTextureXPR();
		}
		else if (points > 100) 
		{
			this->initTextureXPRFull();
		}
	}
	if (Keyboard::isKeyPressed(Keyboard::W)) //gora
	{
		this->shape.move(0.f, -this->movementSpeed); 
	}
	else if (Keyboard::isKeyPressed(Keyboard::S)) //dol
	{
		this->shape.move(0.f, this->movementSpeed);
	}
}

void Player::updateInput98(int points)
{
	//Klawiatura
	if (Keyboard::isKeyPressed(Keyboard::A)) //lewo
	{
		this->shape.move(-this->movementSpeed, 0.f); // x, y
		if (points < 100) {
			this->initTexture98L();
		}
		else if (points > 100)
		{
			this->initTexture98LFull();
		}
	}
	else if (Keyboard::isKeyPressed(Keyboard::D)) //prawo
	{
		this->shape.move(this->movementSpeed, 0.f);
		if (points < 100) {
			this->initTexture98R();
		}
		else if (points > 100)
		{
			this->initTexture98RFull();
		}
	}
	if (Keyboard::isKeyPressed(Keyboard::W)) //gora
	{
		this->shape.move(0.f, -this->movementSpeed);
	}
	else if (Keyboard::isKeyPressed(Keyboard::S)) //dol
	{
		this->shape.move(0.f, this->movementSpeed);
	}
}

void Player::updateWindowBoundsCollision(const RenderTarget * target)
{
	//lewa strona okna
	if (this->shape.getGlobalBounds().left <= 0.f)
	{
		this->shape.setPosition(0.f, this->shape.getGlobalBounds().top);
	}
	//prawa strona okna
	else if (this->shape.getGlobalBounds().left + this->shape.getGlobalBounds().width >= target->getSize().x) {
		this->shape.setPosition(target->getSize().x - this->shape.getGlobalBounds().width, this->shape.getGlobalBounds().top);
	}
	//gora okna
	if (this->shape.getGlobalBounds().top <= 0.f) {
		this->shape.setPosition(this->shape.getGlobalBounds().left, 0.f);
	}
	//dol okna
	else if (this->shape.getGlobalBounds().top + this->shape.getGlobalBounds().height + 30 >= target->getSize().y) { //wartosc 30 uwzglednia pasek
		this->shape.setPosition(this->shape.getGlobalBounds().left, target->getSize().y - this->shape.getGlobalBounds().height - 30);
	}
}

void Player::updateXP(const RenderTarget* target, int points) //poruszamy graczem
{
	this->updateInputXP(points);

	//Granice okna
	this->updateWindowBoundsCollision(target);
}

void Player::update98(const RenderTarget* target, int points) //poruszamy graczem
{
	this->updateInput98(points);

	//Granice okna
	this->updateWindowBoundsCollision(target);
}


void Player::render(RenderTarget * target)
{
	target->draw(this->shape);
}
