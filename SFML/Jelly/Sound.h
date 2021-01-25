#ifndef SOUND_H
#define SOUND_H

#include <SFML/Audio.hpp>
#include <string>

class Sound
{
public:
	Sound();
	~Sound();

		// SetGunSound - Sets the sound used when a weapon is fired
		// @param string - Directory of the sound
		// @param unsigned int - Volume
	void SetGunSound(std::string gunshot, unsigned int volume);
		// PlayGunSound - Plays the sound
	void PlayGunSound();

		// SetReloadSound - Sets the sound used when an ammopack is picked up
		// @param string - Directory of the sound
		// @param unsigned int - Volume
	void SetReloadSound(std::string reloadsound, unsigned int volume);
		// PlayReloadSound - Plays the sound
	void PlayReloadSound();

		// SetOutofammoSound - Sets the sound used when the player tries to fire the weapon while it is out of ammo
		// @param string - Directory of the sound
		// @param unsigned int - Volume
	void SetOutofammoSound(std::string noammosound, unsigned int volume);
		// PlayOutofammoSound - Plays the sound
	void PlayOutofammoSound();

		// SetPainSound - Sets the sound used when an enemy is destroyed
		// @param string - Directory of the sound
		// @param unsigned int - Volume
	void SetPainSound(std::string pain, unsigned int volume);
		// PlayPainSound - Plays the sound
	void PlayPainSound();

		// SetPlayerDamageSound - Sets the sound used when the player takes damage
		// @param string - Directory of the sound
		// @param unsigned int - Volume
	void SetPlayerDamageSound(std::string playerdamage, unsigned int volume);
		// PlayPlayerDamageSound - Plays the sound
	void PlayPlayerDamageSound();

		// SetPlayerSpottedSound - Sets the sound used when an enemy has spotted the player
		// @param string - Directory of the sound
		// @param unsigned int - Volume
	void SetPlayerSpottedSound(std::string playerspotted, unsigned int volume);
		// PlayPlayerSpottedSound - Plays the sound
	void PlayPlayerSpottedSound();

		// SetHealSound - Sets the sound used when the player picks up a healthpack
		// @param string - Directory of the sound
		// @param unsigned int - Volume
	void SetHealSound(std::string playerhealed, unsigned int volume);
		// PlayHealSound - Plays the sound
	void PlayHealSound();

		// SetCrateDestroyedSound - Sets the sound used when the player destroys a crate
		// @param string - Directory of the sound
		// @param unsigned int - Volume
	void SetCrateDestroyedSound(std::string cratedestroyed, unsigned int volume);
		// PlayCrateDestroyedSound - Plays the sound
	void PlayCrateDestroyedSound();

		// SetJellyFreedSound - Sets the sound used when a jelly has been freed
		// @param string - Directory of the sound
		// @param unsigned int - Volume 
	void SetJellyFreedSound(std::string jellyfreed, unsigned int volume);
		// PlayJellyFreedSound - Plays the sound
	void PlayJellyFreedSound();

		// SetPowerUpSound - Sets the sound used when the player picks up a powerup
		// @param string - Directory of the sound
		// @param unsigned int - Volume
	void SetPowerUpSound(std::string powerup, unsigned int volume);
		// PlayPowerUpSound - Plays the sound
	void PlayPowerUpSound();

		// SetVictorySound - Sets the sound used when the player reaches the finish
		// @param string - Directory of the sound
		// @param unsigned int - Volume
	void SetVictorySound(std::string victory, unsigned int volume);
		// PlayVictorySound - Plays the sound
	void PlayVictorySound();
		// StopVictorySound - Stop playing the sound
	void StopVictorySound();

		// SetMainMusic - Sets the music used in the title/main/tutorial screen
		// @param string - Directory of the music
		// @param unsigned int - Volume
	void SetMainMusic(std::string mainmusic, unsigned int volume);
		// PlayMainMusic - Plays the music
	void PlayMainMusic();
		// StopMainMusic - Stop playing the music
	void StopMainMusic();

		// SetGameMusic - Sets the music used in the gamescreen
		// @param string - Directory of the music
		// @param unsigned int - Volume
	void SetGameMusic(std::string gamemusic, unsigned int volume);
		// PlayGameMusic - Plays the music
	void PlayGameMusic();
		// StopGameMusic - Stop playing the music
	void StopGameMusic();
		// PauseGameMusic - Pause the music
	void PauseGameMusic();

		// SetGameOverMusic - Sets the music used when the player is defeated
		// @param string - Directory of the music
		// @param unsigned int - Volume
	void SetGameOverMusic(std::string gameovermusic, unsigned int volume);
		// PlayGameOverMusic - Plays the music
	void PlayGameOverMusic();
		// StopGameOverMusic - Stop playing the music
	void StopGameOverMusic();

private:
	sf::SoundBuffer gunBuffer;				// Loads the sound that is used for shooting the gun
	sf::Sound gunSound;						// Holds the sound that is used for shooting the gun
	sf::SoundBuffer reloadBuffer;			// Loads the sound that is used for reloading the gun
	sf::Sound reloadSound;					// Holds the sound that is used for reloading the gun
	sf::SoundBuffer noAmmoBuffer;			// Loads the sound that is used when there is no ammo in the gun
	sf::Sound noAmmoSound;					// Holds the sound that is used when there is no ammo in the gun
	sf::SoundBuffer painBuffer;				// Loads the sound that is used when the enemy gets hit
	sf::Sound painSound;					// Holds the sound that is used when the enemy gets hit
	sf::SoundBuffer playerDamageBuffer;		// Loads the sound that is used when the player gets hit
	sf::Sound playerDamageSound;			// Holds the sound that is used when the player gets hit
	sf::SoundBuffer playerSpottedBuffer;	// Loads the sound that is used when the player is spotted by the enemy
	sf::Sound playerSpottedSound;			// Holds the sound that is used when the player is spotted by the enemy
	sf::SoundBuffer healBuffer;				// Loads the sound that is used when the player picks up a health kit
	sf::Sound healSound;					// Holds the sound that is used when the player picks up a health kit
	sf::SoundBuffer crateDestroyedBuffer;	// Loads the sound that is used when the player destroys a crate
	sf::Sound crateDestroyedSound;			// Holds the sound that is used when the player destroys a crate
	sf::SoundBuffer jellyFreedBuffer;		// Loads the sound that is used when a jelly is freed
	sf::Sound jellyFreedSound;				// Holds the sound that is used when a jelly is freed
	sf::SoundBuffer powerUpBuffer;			// Loads the sound that is used when the player picks up a power up
	sf::Sound powerUpSound;					// Holds the sound that is used when the player picks up a power up
	sf::SoundBuffer victoryBuffer;			// Loads the sound that is used when the player reaches the finish
	sf::Sound victorySound;					// Holds the sound that is used when the player reaches the finish

	sf::Music mainMusic;					// Holds the music that is played in the titlescreen and the main menu
	sf::Music gameMusic;					// Holds the music that is played in the game
	sf::Music gameOverMusic;				// Holds the music that is played when the player is defeated
};

#endif
