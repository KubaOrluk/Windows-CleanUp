#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

enum FolderTypes {FOLDER1 = 0, FOLDER2, FOLDER3, FOLDER4, NROFTYPES}; //typy 

using namespace sf;
using namespace std;

class Folder
{
private:
	Sprite shape;

	Texture texture;

	int type;

	void initShape(const RenderWindow& window, Vector2f playerPos);
public:
	Folder(const RenderWindow& window, int type, Vector2f playerPos);
	virtual ~Folder();

	Sprite getShape();
	const int& getType() const;

	void renderXP(RenderTarget& target);
	void render98(RenderTarget& target);
};