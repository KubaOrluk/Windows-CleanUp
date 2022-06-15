#pragma once

#include<iostream>

#include <SFML/Audio.hpp>

using namespace sf;
using namespace std;

class Audio
{
private:
	SoundBuffer XPdamageBuffer;
	SoundBuffer XPhealthBuffer;
	SoundBuffer XPpointBuffer;
	SoundBuffer XPGOBuffer;
	SoundBuffer XPerrorBuffer;
	SoundBuffer XPballoonBuffer;
	
	SoundBuffer ClassicDamageBuffer;
	SoundBuffer ClassicHealthBuffer;
	SoundBuffer ClassicPointBuffer;
	SoundBuffer ClassicGOBuffer;
	SoundBuffer ClassicErrorBuffer;
	SoundBuffer ClassicBalloonBuffer;

	Sound damageSound;
	Sound healthSound;
	Sound pointSound;
	Sound GOSound;
	Sound errorSound;
	Sound balloonSound;

	SoundBuffer XPthemeBuffer;
	Sound XPtheme;
	SoundBuffer XPstartupBuffer;
	Sound XPstartupSound;
	SoundBuffer ClassicThemeBuffer;
	Sound ClassicTheme;
	SoundBuffer ClassicStartupBuffer;
	Sound ClassicStartupSound;

	SoundBuffer XPpowerUpBuffer;
	SoundBuffer ClassicPowerUpBuffer;

	Sound XPpowerUp;
	Sound ClassicPowerUp;
public:
	Audio();
	~Audio();
	void initSounds();
	void initXPSounds();
	void init98Sounds();
	void init98Startup();
	void initXPStartup();
	void playDamageSound();
	void playHealingSound();
	void playPointSound();
	void playGameOverSound();
	void playErrorSound();
	void playBalloonSound();
	void MusicXP();
	void Music98();
	void stopMusicXP();
	void stopMusic98();

	void MusicPower98();
	void MusicPowerXP();
	void stopMusicPower98();
	void stopMusicPowerXP();

	void startup98();
	void startupXP();
};
