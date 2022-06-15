#include "GUI.h"
#include "Audio.h"

GUI::GUI()
{
}

GUI::~GUI()
{
}

void GUI::setBGsize(const RenderWindow & window)
{
	this->BackgroundScreen.setScale(window.getSize().x / 800.f, window.getSize().y / 600.f);
}

void GUI::bgXP(const RenderWindow & window)
{
	this->Background.loadFromFile("Textures/XP/background.jpg");
}

void GUI::bg98(const RenderWindow & window)
{
	this->Background.loadFromFile("Textures/98/background.jpg");
}

void GUI::powerup98bg(const RenderWindow & window)
{
	this->Background.loadFromFile("Textures/98/powerupBG.jpg");
}

void GUI::powerupXPbg(const RenderWindow & window)
{
	this->Background.loadFromFile("Textures/XP/powerupBG.jpg");
}

void GUI::initGUI(const RenderWindow & window)
{
	this->MediaScreen.setTexture(Media);
	this->MediaScreen.setTextureRect(IntRect(0, 0, 165, 30));
	this->MediaScreen.setPosition(
		Vector2f(
			static_cast<float>(105.f),
			static_cast<float>(window.getSize().y - 30.f)
		)
	);

	this->StartScreen.setTexture(Start);
	this->StartScreen.setTextureRect(IntRect(0, 0, 99, 30));
	this->StartScreen.setPosition(
		Vector2f(
			static_cast<float>(0),
			static_cast<float>(window.getSize().y - 30.f)
		)
	);

	this->MiddleScreen.setTexture(Middle);
	this->MiddleScreen.setScale(window.getSize().x/66.f, 1);
	this->MiddleScreen.setPosition(
		Vector2f(
			static_cast<float>(0),
			static_cast<float>(window.getSize().y - 30.f)
		)
	);

	this->BackScreen.setTexture(Back);
	this->MiddleScreen.setTextureRect(IntRect(0, 0, 66, 30));
	this->BackScreen.setPosition(
		Vector2f(
			static_cast<float>(window.getSize().x - 66.f),
			static_cast<float>(window.getSize().y - 30.f)
		)
	);

	this->BackgroundScreen.setTexture(Background);
	this->BackgroundScreen.setScale(window.getSize().x / 800.f, window.getSize().y / 600.f);

	this->GameOverScreen.setTexture(GameOver);
	this->StartScreen.setTextureRect(IntRect(0, 0, 270, 150));
	this->GameOverScreen.setPosition(
		Vector2f(
			static_cast<float>((window.getSize().x / 2.f) - 135.f),
			static_cast<float>((window.getSize().y / 2.f) - 75.f)
		)
	);

	this->TutorialScreen.setTexture(Tutorial);
	this->TutorialScreen.setPosition(
		Vector2f(
			static_cast<float>(window.getSize().x - 346.f),
			static_cast<float>(window.getSize().y - 123.f)
		)
	);

	this->CMDScreen.setTexture(CMD);
	this->CMDScreen.setPosition( //randomowa pozycja
		Vector2f(
			static_cast<float>(rand() % ((window.getSize().x) / 10)) + 100.f,
			static_cast<float>(rand() % (window.getSize().y / 5)) + 100.f
		)
	);

	this->ScoreScreen.setTexture(Score);
	this->ScoreScreen.setPosition(Vector2f(8.f, 8.f));

	this->HealthScreenBG.setTexture(HealthBG);
	this->HealthScreenBG.setPosition(Vector2f(109.f, 77.f));
	this->HealthScreenBG.setTextureRect(IntRect(0, 0, 101, 17));

	this->HealthScreenBar.setTexture(HealthBar);
	this->HealthScreenBar.setPosition(Vector2f(109.f, 77.f));
}

void GUI::initXP(const RenderWindow& window){
	this->Media.loadFromFile("Textures/XP/media.png");
	this->Start.loadFromFile("Textures/XP/start.png");
	this->Middle.loadFromFile("Textures/XP/middle.png");
	this->Back.loadFromFile("Textures/XP/back.png");
	this->GameOver.loadFromFile("Textures/XP/gameover.png");
	this->Tutorial.loadFromFile("Textures/XP/Balloon.png");
	this->CMD.loadFromFile("Textures/XP/CMD.png");
	this->Score.loadFromFile("Textures/XP/Score.png");
	this->HealthBG.loadFromFile("Textures/XP/healthBG.png");
	this->HealthBar.loadFromFile("Textures/XP/healthBar.png");	
}

void GUI::init98(const RenderWindow& window) {
	this->Media.loadFromFile("Textures/98/media.png");
	this->Start.loadFromFile("Textures/98/start.png");
	this->Middle.loadFromFile("Textures/98/middle.png");
	this->Back.loadFromFile("Textures/98/back.png");
	this->GameOver.loadFromFile("Textures/98/gameover.png");
	this->Tutorial.loadFromFile("Textures/98/Balloon.png");
	this->CMD.loadFromFile("Textures/98/CMD.png");
	this->Score.loadFromFile("Textures/98/Score.png");
	this->HealthBG.loadFromFile("Textures/98/healthBG.png");
	this->HealthBar.loadFromFile("Textures/98/healthBar.png");
}

void GUI::setScore(int X) 	 //transparenty wynik
{
	this->ScoreScreen.setColor(Color(255, 255, 255, X));
	this->HealthScreenBG.setColor(Color(255, 255, 255, X));
}

void GUI::setHealthBarColour(int R, int G, int B, int X) 	 //transparenty wynik
{
	this->HealthScreenBar.setColor(Color(R, G, B, X));
}


void GUI::renderBG(RenderTarget & target)
{
	target.draw(this->BackgroundScreen);
}

void GUI::renderCMD(RenderTarget & target)
{
	target.draw(this->CMDScreen);
}

void GUI::renderHealthBG(RenderTarget & target)
{
	target.draw(this->HealthScreenBG);
}

void GUI::renderHealthBar(RenderTarget & target, float health)
{
	this->HealthScreenBar.setTextureRect(IntRect(0, 0, 101.f*health, 17));
	target.draw(this->HealthScreenBar);
}


void GUI::renderTutorial(RenderTarget & target)
{
	target.draw(this->TutorialScreen);
}


void GUI::renderScore(RenderTarget & target)
{
	target.draw(this->ScoreScreen);
}

void GUI::renderGameOver(RenderTarget & target)
{
	target.draw(this->GameOverScreen);
}

void GUI::renderMedia(RenderTarget & target)
{
	target.draw(this->MediaScreen);
}

void GUI::renderStart(RenderTarget & target)
{
	target.draw(this->StartScreen);
}

void GUI::renderMiddle(RenderTarget & target)
{
	target.draw(this->MiddleScreen);
}

void GUI::renderBack(RenderTarget & target)
{
	target.draw(this->BackScreen);
}