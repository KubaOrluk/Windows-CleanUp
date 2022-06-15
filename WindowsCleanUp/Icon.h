#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

enum IconTypes { MALWARE = 0, MALWARE2, ANTIVIRUS, Win98, WinXP, PowerUp}; //typy 

using namespace sf;
using namespace std;

class Icon
{
private:
	Sprite shape;

	Texture texture;

	int type;

	void initShape(const RenderWindow& window, Vector2f playerPos);
public:
	Icon(const RenderWindow& window, int type, Vector2f playerPos);
	virtual ~Icon();

	Sprite getShape();
	const int& getType() const;
	const Vector2f& getPosition() const;

	void renderXP(RenderTarget& target);
	void render98(RenderTarget& target);
};
