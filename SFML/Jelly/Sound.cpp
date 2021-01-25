#include "Sound.h"


Sound::Sound()
{
}
Sound::~Sound()
{
}


void Sound::SetGunSound(std::string gunshot, unsigned int volume)
{
	gunBuffer.loadFromFile(gunshot);
	gunSound.setBuffer(gunBuffer);
	gunSound.setVolume(volume);
}
void Sound::PlayGunSound()
{
	gunSound.play();
}

void Sound::SetReloadSound(std::string reloadsound, unsigned int volume)
{
	reloadBuffer.loadFromFile(reloadsound);
	reloadSound.setBuffer(reloadBuffer);
	reloadSound.setVolume(volume);
}
void Sound::PlayReloadSound()
{
	reloadSound.play();
}

void Sound::SetOutofammoSound(std::string noammosound, unsigned int volume)
{
	noAmmoBuffer.loadFromFile(noammosound);
	noAmmoSound.setBuffer(noAmmoBuffer);
	noAmmoSound.setVolume(volume);
}
void Sound::PlayOutofammoSound()
{
	noAmmoSound.play();
}

void Sound::SetPainSound(std::string pain, unsigned int volume)
{
	painBuffer.loadFromFile(pain);
	painSound.setBuffer(painBuffer);
	painSound.setVolume(volume);
}
void Sound::PlayPainSound()
{
	painSound.play();
}

void Sound::SetPlayerDamageSound(std::string playerdamage, unsigned int volume)
{
	playerDamageBuffer.loadFromFile(playerdamage);
	playerDamageSound.setBuffer(playerDamageBuffer);
	playerDamageSound.setVolume(volume);
}
void Sound::PlayPlayerDamageSound()
{
	playerDamageSound.play();
}

void Sound::SetPlayerSpottedSound(std::string playerspotted, unsigned int volume)
{
	playerSpottedBuffer.loadFromFile(playerspotted);
	playerSpottedSound.setBuffer(playerSpottedBuffer);
	playerSpottedSound.setVolume(volume);
}
void Sound::PlayPlayerSpottedSound()
{
	playerSpottedSound.play();
}

void Sound::SetHealSound(std::string playerhealed, unsigned int volume)
{
	healBuffer.loadFromFile(playerhealed);
	healSound.setBuffer(healBuffer);
	healSound.setVolume(volume);
}
void Sound::PlayHealSound()
{
	healSound.play();
}

void Sound::SetCrateDestroyedSound(std::string cratedestroyed, unsigned int volume)
{
	crateDestroyedBuffer.loadFromFile(cratedestroyed);
	crateDestroyedSound.setBuffer(crateDestroyedBuffer);
	crateDestroyedSound.setVolume(volume);
}
void Sound::PlayCrateDestroyedSound()
{
	crateDestroyedSound.play();
}

void Sound::SetJellyFreedSound(std::string jellyfreed, unsigned int volume)
{
	jellyFreedBuffer.loadFromFile(jellyfreed);
	jellyFreedSound.setBuffer(jellyFreedBuffer);
	jellyFreedSound.setVolume(volume);
}
void Sound::PlayJellyFreedSound()
{
	jellyFreedSound.play();
}

void Sound::SetPowerUpSound(std::string powerup, unsigned int volume)
{
	powerUpBuffer.loadFromFile(powerup);
	powerUpSound.setBuffer(powerUpBuffer);
	powerUpSound.setVolume(volume);
}
void Sound::PlayPowerUpSound()
{
	powerUpSound.play();
}

void Sound::SetVictorySound(std::string victory, unsigned int volume)
{
	victoryBuffer.loadFromFile(victory);
	victorySound.setBuffer(victoryBuffer);
	victorySound.setVolume(volume);
}
void Sound::PlayVictorySound()
{
	victorySound.play();
}
void Sound::StopVictorySound()
{
	victorySound.stop();
}

void Sound::SetMainMusic(std::string mainmusic, unsigned int volume)
{
	mainMusic.openFromFile(mainmusic);
	mainMusic.setLoop(true);
	mainMusic.setVolume(volume);

}
void Sound::PlayMainMusic()
{	
	mainMusic.play();
}
void Sound::StopMainMusic()
{
	mainMusic.stop();
}

void Sound::SetGameMusic(std::string gamemusic, unsigned int volume)
{
	gameMusic.openFromFile(gamemusic);
	gameMusic.setLoop(true);
	gameMusic.setVolume(volume);
}
void Sound::PlayGameMusic()
{
	gameMusic.play();
}
void Sound::StopGameMusic()
{
	gameMusic.stop();
}
void Sound::PauseGameMusic()
{
	gameMusic.pause();
}

void Sound::SetGameOverMusic(std::string gameovermusic, unsigned int volume)
{
	gameOverMusic.openFromFile(gameovermusic);
	gameMusic.setVolume(volume);
}
void Sound::PlayGameOverMusic()
{
	gameOverMusic.play();
}
void Sound::StopGameOverMusic()
{
	gameOverMusic.stop();
}