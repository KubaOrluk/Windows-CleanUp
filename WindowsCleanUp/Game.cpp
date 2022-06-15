#include "Game.h"
#include "Audio.h"
#include "Popup.h"
#include "GUI.h"

Game::Game()
{
	this->initWindow();
	gui.bgXP(*this->window);
	gui.initXP(*this->window);
	gui.initGUI(*this->window);
	audio.startupXP();
	audio.MusicXP();
	audio.initXPSounds();
	this->initVariables();
	this->initFonts();
	this->initText();
}

Game::~Game()
{
	delete this->window;
}

void Game::initVariables()
{
	this->balloon = true;
	this->BoolXP = true;
	this->Bool98 = false;
	this->noMoreXP = true;
	this->noMore98 = false;
	this->gameOverSet = false;
	this->endGame = false;
	this->spawnTimerFolderMax = 10.f;
	this->spawnTimerFolder = this->spawnTimerFolderMax;
	this->spawnTimerIconMax = 10.f;
	this->spawnTimerIcon = this->spawnTimerFolderMax;
	this->maxFolders = 10;
	this->maxIcons = 3;
	this->maxPopups = 0;
	this->points = 0;
	this->PowerUpOn = false;
}

void Game::initWindow()
{
	this->videoMode = VideoMode(800, 600);
	this->window = new RenderWindow(this->videoMode, "Windows CleanUp - gra stworzona przez Jakuba Orluka", Style::Close | Style::Titlebar);
	this->window->setFramerateLimit(60); //limit fps
}

void Game::initFonts()
{
	if (!this->font.loadFromFile("Fonts/PixelLettersFull.ttf")) //ladowanie czcionki
	{
		cout << "ERROR::GAME::INITFONTS::NIE MOZNA WCZYTAC CZCIONKI" << endl;
	}
}

void Game::initText()
{
	this->guiText.setFont(this->font);
	this->guiText.setFillColor(Color::Black);
	this->guiText.setCharacterSize(32); //wielkosc tekstu
}

const bool Game::running() const
{
	return this->window->isOpen();
}

void Game::pollEvents()
{
	while (this->window->pollEvent(this->sfmlEvent))
	{
		switch (this->sfmlEvent.type)
		{
		case Event::Closed: //"x"
			this->cleanUp();
			this->window->close(); //zamyka gre
			break;
		case Event::KeyPressed: //esc
			if (this->sfmlEvent.key.code == Keyboard::Escape) {
				this->cleanUp();
				this->window->close();
			}
			break;
		}
	}
}

//icon behaviour

void Game::antivir()
{
	if (PowerUpOn == false) {
		audio.playHealingSound();
		this->player.gainHealth(1);

		if (maxPopups != 0)
		{
			maxPopups--;
			this->Popups.pop_back();
		}
	}
	else {
		audio.playPointSound();
		this->points++;
	}
}

void Game::cleanUp()
{
	while (maxPopups != 0)
	{
		maxPopups--;
		this->Popups.pop_back();
	}
}

void Game::refresh() {
	bool isThereTwo = false;
	for (size_t i = 0; i < this->Icons.size(); i++) //petla do kazdego spawnu wroga
	{
		if (Icons[i].getType() == WinXP or Icons[i].getType() == Win98)
		{
			if (isThereTwo == true) {
				this->Icons.erase(this->Icons.begin() + i); //usuwamy element, wskaznik na start + i, czyli to, co teraz jest w petli
			}
			isThereTwo = true;
		}
	}
}

void Game::win98()
{
	if (PowerUpOn == false) {
		noMore98 = true;
		noMoreXP = false;
		Bool98 = true;
		BoolXP = false;
		gui.bg98(*this->window);
		gui.init98(*this->window);
		audio.stopMusicXP();
		audio.startup98();
		audio.Music98();
		audio.init98Sounds();
		if (points > 100) 
		{
			player.initTexture98RFull();
		}
		else if (points < 100)
		{
			player.initTexture98R(); //nowa tekstura gracza
		}
		cleanUp();
		refresh();
	}
	else {
		audio.playPointSound();
		this->points++;
	}
}

void Game::winXP()
{
	if (PowerUpOn == false) {
		noMore98 = false;
		noMoreXP = true;
		BoolXP = true;
		Bool98 = false;
		gui.bgXP(*this->window);
		gui.initXP(*this->window);
		audio.stopMusic98();
		audio.startupXP();
		audio.MusicXP();
		audio.initXPSounds();
		if (points > 100) 
		{
			player.initTextureXPRFull();
		}
		else if (points < 100) 
		{
			player.initTextureXPR(); //nowa tekstura gracza
		}
		cleanUp();
		refresh();
	}
	else {
		audio.playPointSound();
		this->points++;
	}
}

void Game::malware()
{
	if (PowerUpOn == false) {
		if (this->player.getHp() > 1)
		{
			audio.playDamageSound();
		}

		this->player.takeDamage(1);

		this->Popups.push_back(Popup(*this->window, this->randomizePopupType())); //randomizuje typ wrogow

		if (maxPopups < this->player.getHpMax()) {
			maxPopups++;
		}
	}
	else {
		audio.playPointSound();
		this->points++;
	}
}


void Game::powerUpCycle()
{
	if (PowerUpOn == true) 
	{
		cleanUp();
		if (powerUpClock.getElapsedTime() < seconds(28.5f))
		{
			if (this->BoolXP == true)
			{
				player.playerMovement(4);
				gui.powerupXPbg(*this->window);
			}
			else {
				player.playerMovement(4.5);
				gui.powerup98bg(*this->window);
			}
			player.gainHealth(3);
			

			noMore98 = true;
			noMoreXP = true;
			noMorePower = true;
		}

		if(powerUpClock.getElapsedTime() > seconds(28.5f))
		{
			player.playerMovement(2);

			PowerUpOn = false; //zapobiega zapetleniu
			noMorePower = false;

			if (this->BoolXP == true)
			{
				gui.bgXP(*this->window);
				noMore98 = false;
				noMoreXP = true;
				audio.MusicXP();
			}
			else {
				gui.bg98(*this->window);
				noMore98 = true;
				noMoreXP = false;
				audio.Music98();
			}
		}
	}
}

//folders spawning

void Game::spawnFolders()
{
	if (this->spawnTimerFolder < this->spawnTimerFolderMax) //maksymalna liczba wrogow
	{
		this->spawnTimerFolder += 1.f;
	}
	else
	{
		if (this->Folders.size() < this->maxFolders)
		{
			this->Folders.push_back(Folder(*this->window, this->randomizeFolderType(), this->player.getPosition())); //randomizuje typ wrogow
			this->spawnTimerFolder = 0.f;
		}
	}
}

int Game::randomizeFolderType() //zmiana prawdopodobienstwa specjalnych punktow
{
	int type = FolderTypes::FOLDER1;
	int randValue = rand() % 100 + 1;

	if (randValue > 25 and randValue <= 50)
	{
		type = FolderTypes::FOLDER2;
	}
	else if (randValue > 50 and randValue <= 75)
	{
		type = FolderTypes::FOLDER3;
	}
	else if (randValue > 75 and randValue <= 100)
	{
		type = FolderTypes::FOLDER4;
	}
	
	return type;
}

void Game::updateFolderCollision() 	//Sprawdz kolizje
{
	for (size_t i = 0; i < this->Folders.size(); i++) //petla do kazdego spawnu wroga
	{
		if (this->player.getShape().getGlobalBounds().intersects(this->Folders[i].getShape().getGlobalBounds())) //czy nachodza na siebie
		{
			if (Folders[i].getType() == FOLDER1 or Folders[i].getType() == FOLDER2 or Folders[i].getType() == FOLDER3 or Folders[i].getType() == FOLDER4)
			{
				audio.playPointSound();
				this->points++;
			}

			this->Folders.erase(this->Folders.begin() + i); //usuwamy element, wskaznik na start + i, czyli to, co teraz jest w petli
		}
	}
}

//Icons spawning

int Game::randomizeIconType() //zmiana prawdopodobienstwa specjalnych punktow
{
	int type = IconTypes::MALWARE;
	int randValue = rand() % 100 + 1;

	if (randValue > 25 and randValue <= 50)
	{
		type = IconTypes::MALWARE2;
	}
	else if (randValue > 50 and randValue <= 70 and this->player.getHp() < player.getHpMax()) { //ilosc max antiwirusow (+ brak spawnu gdy hp = 100%)
		type = IconTypes::ANTIVIRUS;
	}
	else if (randValue > 70 and randValue <= 80 and noMorePower == false) {
		type = IconTypes::PowerUp;
	}
	else if (randValue > 80 and randValue <= 90 and BoolXP == false and noMoreXP == false) {
		type = IconTypes::WinXP;
	}
	else if (randValue > 90 and randValue <= 100 and Bool98 == false and noMore98 == false) {
		type = IconTypes::Win98;
	}

	return type;
}

void Game::spawnIcons()
{
	if (this->spawnTimerIcon < this->spawnTimerIconMax) //maksymalna liczba wrogow
	{
		this->spawnTimerIcon += 1.f;
	}
	else
	{
		if (this->Icons.size() < this->maxIcons)
		{
			this->Icons.push_back(Icon(*this->window, this->randomizeIconType(), this->player.getPosition())); //randomizuje typ wrogow
			this->spawnTimerIcon = 0.f;
		}
	}
}

void Game::measureIconTime() {
	for (size_t i = 0; i < this->Icons.size(); i++) //petla do kazdego spawnu wroga
	{
		if (clock.getElapsedTime() > seconds(10.f)) //co 5 sekund
		{
			this->Icons.erase(this->Icons.begin() + i);
			clock.restart();
		}
	}
}

void Game::updateIconCollision() 	//Sprawdz kolizje
{
	for (size_t i = 0; i < this->Icons.size(); i++) //petla do kazdego spawnu wroga
	{
		if (this->player.getShape().getGlobalBounds().intersects(this->Icons[i].getShape().getGlobalBounds())) //czy nachodza na siebie
		{
			if (Icons[i].getType() == MALWARE)
			{
				this->malware();
			}
			if (Icons[i].getType() == MALWARE2)
			{
				this->malware();
			}
			if (Icons[i].getType() == ANTIVIRUS)
			{
				this->antivir();
			}
			if (Icons[i].getType() == WinXP)
			{
				this->winXP();
			}
			if (Icons[i].getType() == Win98)
			{
				this->win98();
			}
			if (Icons[i].getType() == PowerUp)
			{
				powerUpClock.restart();
				if (this->BoolXP == true)
				{
					audio.stopMusicXP();
					audio.MusicPowerXP();
				}
				else {
					audio.stopMusic98();
					audio.MusicPower98();
				}
				PowerUpOn = true;
			}

			this->Icons.erase(this->Icons.begin() + i); //usuwamy element, wskaznik na start + i, czyli to, co teraz jest w petli
		}
	}
}

void Game::GUIColour() {
	if (this->player.getShape().getPosition().x < 240 and this->player.getShape().getPosition().y < 140) { //transparent score
		gui.setScore(128);
	}
	else {
		gui.setScore(255);
	}

	if (PowerUpOn == true) {

		player.setPlayerColor(rand() % 255, rand() % 255, rand() % 255);

		if (this->player.getShape().getPosition().x < 240 and this->player.getShape().getPosition().y < 140) { //transparent score
			gui.setHealthBarColour(rand() % 255, rand() % 255, rand() % 255, 128);
		}
		else {
			gui.setHealthBarColour(rand() % 255, rand() % 255, rand() % 255, 192);
		}
	}
	else {

		player.setPlayerColor(255, 255, 255);

		if (this->player.getShape().getPosition().x < 240 and this->player.getShape().getPosition().y < 140) { //transparent score
			gui.setHealthBarColour(255, 255, 255, 128);
		}
		else {
			gui.setHealthBarColour(255, 255, 255, 255);
		}
	}
}

//Popups spawning

int Game::randomizePopupType() //zmiana prawdopodobienstwa specjalnych punktow
{
	int type = PopupTypes::AD1;
	int randValue = rand() % 100 + 1;

	if (randValue > 25 and randValue <= 50)
	{
		type = PopupTypes::AD2;
	}
	else if (randValue > 50 and randValue <= 75)
	{
		type = PopupTypes::AD3;
	}
	else if (randValue > 75 and randValue <= 100)
	{
		type = PopupTypes::AD4;
	}

	return type;
}

void Game::updatePlayer()
{
	if (this->BoolXP == true) {
		this->player.updateXP(this->window, this->points);
	}
	else {
		this->player.update98(this->window, this->points);
	}

	if (this->player.getHp() <= 0) {
		this->endGame = true;
	}
}

void Game::updateGui()
{
	stringstream ss; //zamienia dynamicznie dane na string

	ss << endl;
	ss << "  Usunieto " << this->points << "MB"<<endl; //punkty
	ss << "  Zapora: " << endl;

	this->guiText.setString(ss.str());
}

void Game::update() 
{
	this->pollEvents();

	if (this->endGame == false)
	{
		this->spawnFolders();
		this->spawnIcons();
		this->updatePlayer();
		if (this->BoolXP == true) {
			this->player.updateXP(this->window, this->points);
		}
		else {
			this->player.update98(this->window, this->points);
		}
		this->updateFolderCollision();
		this->updateIconCollision();
		this->GUIColour();
		this->measureIconTime();
		this->updateGui();
		this->powerUpCycle();
	}
}

void Game::renderGui(RenderTarget* target)
{
	target->draw(this->guiText);
}

void Game::render()
{
	this->window->clear();
	gui.renderBG(*this->window);

	this->player.render(this->window); //renderowanie gracza


	for (auto i : this->Folders) 
	{
		if (BoolXP == true) {
			i.renderXP(*this->window);
		}
		else {
			i.render98(*this->window);
		}
	}

	for (auto i : this->Icons)
	{
		if (BoolXP == true) {
			i.renderXP(*this->window);
		}
		else {
			i.render98(*this->window);
		}
	}

	for (auto i : this->Popups)
	{
		if (BoolXP == true) {
			i.renderXP(*this->window);
		}
		else {
			i.render98(*this->window);
		}
	}

	if (balloonClock.getElapsedTime() > seconds(4.f) and balloonClock.getElapsedTime() < seconds(12.f))
	{
		if (balloon == true) {
			audio.playBalloonSound();
			balloon = false;
		}
		gui.renderTutorial(*this->window);
	}

	//Render gui
	gui.renderScore(*this->window);
	this->renderGui(this->window);

	gui.renderHealthBG(*this->window);
	gui.renderHealthBar(*this->window, (this->player.getHp()/this->player.getHpMax()));

	if (this->endGame == true)
	{
		this->EndGameProcedure();
	}

	gui.renderMiddle(*this->window);
	gui.renderStart(*this->window);
	gui.renderBack(*this->window);

	if (PowerUpOn == true) {
		gui.renderMedia(*this->window);
	}

	this->window->display();
}

void Game::EndGameProcedure()
{
	gui.renderCMD(*this->window);
	gui.renderGameOver(*this->window);
	if (gameOverSet == false) {
		if (Bool98 == true) {
			audio.stopMusic98();
		}
		else
		{
			audio.stopMusicXP();
		}
		audio.playGameOverSound();
		gameOverSet = true;
	}
}
