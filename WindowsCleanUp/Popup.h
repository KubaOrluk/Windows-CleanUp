#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

enum PopupTypes {AD1 = 0, AD2, AD3, AD4}; //typy 

using namespace sf;
using namespace std;

class Popup
{
private:
	Sprite shape;

	Texture textureXP1;
	Texture textureXP2;
	Texture textureXP3;
	Texture textureXP4;

	Texture texture981;
	Texture texture982;
	Texture texture983;
	Texture texture984;

	int type;

	void initShape(const RenderWindow& window);
public:
	Popup(const RenderWindow& window, int type);
	virtual ~Popup();

	const int& getType() const;

	void renderXP(RenderTarget& target);
	void render98(RenderTarget& target);
};

