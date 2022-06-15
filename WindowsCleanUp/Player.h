#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

using namespace sf;

class Player
{
private:
	Sprite shape;
	Texture texture;

	float movementSpeed;
	float hp;
	float hpMax;

	void initVariables();
	void initShape();

public:
	Player(float x = 720.f, float y = 420.f);
	virtual ~Player();

	void playerMovement(float speed);

	const Sprite& getShape() const;
	const float& getHp() const;
	const float& getHpMax() const;
	const Vector2f& getPosition() const;

	void takeDamage(const int damage);
	void gainHealth(const int health);

	void setPlayerColor(int R, int G, int B);

	void initTextureXPL();
	void initTextureXPR();
	void initTexture98L();
	void initTexture98R();

	void initTextureXPLFull();
	void initTextureXPRFull();
	void initTexture98LFull();
	void initTexture98RFull();

	void updateInputXP(int points);
	void updateInput98(int points);
	void updateWindowBoundsCollision(const RenderTarget* target);
	void updateXP(const RenderTarget* target, int points);
	void update98(const RenderTarget* target, int points);
	void render(RenderTarget* target);
};

