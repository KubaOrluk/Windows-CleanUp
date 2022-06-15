#pragma once
#pragma once

#include <SFML/Graphics.hpp>


using namespace sf;
using namespace std;

class GUI
{
private:
	Sprite BackgroundScreen;
	Sprite TutorialScreen;
	Sprite GameOverScreen;
	Sprite CMDScreen;
	Sprite ScoreScreen;
	Sprite StartScreen;
	Sprite MiddleScreen;
	Sprite BackScreen;
	Sprite MediaScreen;

	Sprite HealthScreenBG;
	Sprite HealthScreenBar;

	Texture Background;
	Texture Tutorial;
	Texture GameOver;
	Texture CMD;
	Texture Score;
	Texture Start;
	Texture Middle;
	Texture Back;
	Texture Media;

	Texture HealthBG;
	Texture HealthBar;

public:
	GUI(); //konstruktor
	~GUI();

	void initXP(const RenderWindow& window);
	void initGUI(const RenderWindow& window);
	void init98(const RenderWindow& window);
	void setScore(int X);
	void setHealthBarColour(int R, int G, int B, int X);
	void setBGsize(const RenderWindow & window);
	void bgXP(const RenderWindow & window);
	void bg98(const RenderWindow & window);
	void powerup98bg(const RenderWindow & window);
	void powerupXPbg(const RenderWindow & window);

	void renderBG(RenderTarget& target);
	void renderCMD(RenderTarget& target);
	void renderTutorial(RenderTarget& target);
	void renderScore(RenderTarget& target);
	void renderGameOver(RenderTarget & target);
	void renderMedia(RenderTarget& target);
	void renderStart(RenderTarget & target);
	void renderMiddle(RenderTarget & target);
	void renderBack(RenderTarget & target);
	void renderHealthBG(RenderTarget& target);
	void renderHealthBar(RenderTarget& target, float health);
};