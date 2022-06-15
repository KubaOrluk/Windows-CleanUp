#include "Audio.h"

Audio::Audio()
{
	this->initXPStartup();
	this->init98Startup();
	this->initSounds();
}

Audio::~Audio()
{
}

void Audio::initSounds()
{
	this->XPdamageBuffer.loadFromFile("Sounds/XP/damage.ogg");

	this->XPhealthBuffer.loadFromFile("Sounds/XP/health.ogg");

	this->XPpointBuffer.loadFromFile("Sounds/XP/point.ogg");

	this->XPGOBuffer.loadFromFile("Sounds/XP/gameover.ogg");

	this->XPerrorBuffer.loadFromFile("Sounds/XP/error.ogg");

	this->XPballoonBuffer.loadFromFile("Sounds/XP/balloon.ogg");

	this->ClassicDamageBuffer.loadFromFile("Sounds/98/damage.ogg");

	this->ClassicHealthBuffer.loadFromFile("Sounds/98/health.ogg");

	this->ClassicPointBuffer.loadFromFile("Sounds/98/point.ogg");

	this->ClassicGOBuffer.loadFromFile("Sounds/98/gameover.ogg");

	this->ClassicErrorBuffer.loadFromFile("Sounds/98/error.ogg");

	this->ClassicBalloonBuffer.loadFromFile("Sounds/98/balloon.ogg");
}

void Audio::initXPSounds()
{
	this->damageSound.setBuffer(XPdamageBuffer);

	this->healthSound.setBuffer(XPhealthBuffer);

	this->pointSound.setBuffer(XPpointBuffer);

	this->GOSound.setBuffer(XPGOBuffer);

	this->errorSound.setBuffer(XPerrorBuffer);

	this->balloonSound.setBuffer(XPballoonBuffer);
}

void Audio::init98Sounds()
{
	this->damageSound.setBuffer(ClassicDamageBuffer);

	this->healthSound.setBuffer(ClassicHealthBuffer);

	this->pointSound.setBuffer(ClassicPointBuffer);

	this->GOSound.setBuffer(ClassicGOBuffer);

	this->errorSound.setBuffer(ClassicErrorBuffer);

	this->balloonSound.setBuffer(ClassicBalloonBuffer);
}

void::Audio::init98Startup() {
	this->ClassicThemeBuffer.loadFromFile("Sounds/98/theme.ogg");
	this->ClassicTheme.setBuffer(ClassicThemeBuffer);

	this->ClassicStartupBuffer.loadFromFile("Sounds/98/startup.ogg");
	this->ClassicStartupSound.setBuffer(ClassicStartupBuffer);
}

void::Audio::initXPStartup() {
	this->XPthemeBuffer.loadFromFile("Sounds/XP/theme.ogg");
	this->XPtheme.setBuffer(XPthemeBuffer);

	this->XPstartupBuffer.loadFromFile("Sounds/XP/startup.ogg");
	this->XPstartupSound.setBuffer(XPstartupBuffer);
}


void Audio::playDamageSound()
{
	damageSound.play();
}

void Audio::playBalloonSound()
{
	balloonSound.play();
}

void Audio::playHealingSound()
{
	healthSound.play();
}

void Audio::playPointSound()
{
	pointSound.play();
}

void Audio::playGameOverSound()
{
	GOSound.play();
}

void Audio::playErrorSound()
{
	errorSound.play();
}

void Audio::Music98()
{
	this->ClassicThemeBuffer.loadFromFile("Sounds/98/theme.ogg");
	this->ClassicTheme.setBuffer(ClassicThemeBuffer);
	ClassicTheme.play();
	ClassicTheme.setLoop(true);
}

void Audio::stopMusic98()
{
	ClassicTheme.stop();

}

void Audio::MusicPower98()
{
	this->ClassicPowerUpBuffer.loadFromFile("Sounds/98/powerup.ogg");
	this->ClassicPowerUp.setBuffer(ClassicPowerUpBuffer);
	ClassicPowerUp.play();
}

void Audio::MusicPowerXP()
{
	this->XPpowerUpBuffer.loadFromFile("Sounds/XP/powerup.ogg");
	this->XPpowerUp.setBuffer(XPpowerUpBuffer);
	XPpowerUp.play();
}

void Audio::stopMusicPower98()
{
	ClassicPowerUp.stop();
}

void Audio::stopMusicPowerXP()
{
	XPpowerUp.stop();
}

void Audio::stopMusicXP()
{
	XPtheme.stop();
}



void Audio::MusicXP()
{
	this->XPthemeBuffer.loadFromFile("Sounds/XP/theme.ogg");
	this->XPtheme.setBuffer(XPthemeBuffer);
	XPtheme.play();
	XPtheme.setLoop(true);
}


void Audio::startup98()
{
	ClassicStartupSound.play();
}


void Audio::startupXP()
{
	XPstartupSound.play();
}

