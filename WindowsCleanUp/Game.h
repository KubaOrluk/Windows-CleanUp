#pragma once

#include<iostream>
#include<ctime>
#include<vector>
#include<sstream>

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/System/Clock.hpp>

#include "Player.h"
#include "Folder.h"
#include "Icon.h"
#include "Audio.h"
#include "Popup.h"
#include "GUI.h"

using namespace sf;
using namespace std;

class Game
{
private:
	VideoMode videoMode;
	RenderWindow* window; //okno gry

	bool endGame; //zakonczenie gry
	bool BoolXP;
	bool Bool98;
	bool noMoreXP;
	bool noMore98;
	bool noMorePower;
	bool gameOverSet;
	bool balloon;
	bool PowerUpOn;

	Event sfmlEvent; //wydarzenia (x, esc etc.)

	Player player; 
	Audio audio;
	Clock clock;
	Clock balloonClock;
	Clock powerUpClock;

	int points;

	Font font;
	Text guiText;
	GUI gui;

	vector<Folder> Folders;
	vector<Icon> Icons;
	vector<Popup> Popups;

	float spawnTimerFolderMax;
	float spawnTimerFolder;
	float spawnTimerIconMax;
	float spawnTimerIcon;

	int maxFolders;
	int maxIcons;
	int maxPopups;

	void initVariables();
	void initWindow();
	void initFonts();
	void initText();

	void antivir();
	void malware();

	void win98();
	void winXP();
	void powerUpCycle();

	void cleanUp();
	void refresh();
public:
	Game(); //konstruktor
	~Game();

	const bool running() const;
	void pollEvents();

	void spawnFolders();
	void spawnIcons();

	int randomizeFolderType();
	int randomizeIconType();
	int randomizePopupType();

	void measureIconTime();

	void updatePlayer();
	void updateFolderCollision();
	void updateIconCollision();
	void updateGui();
	void GUIColour();
	void update();

	void renderGui(RenderTarget* target);
	void render();

	void EndGameProcedure();
};