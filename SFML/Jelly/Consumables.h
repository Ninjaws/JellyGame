#ifndef CONSUMABLES_H
#define CONSUMABLES_H

#include "Enemy.h"

class Consumables : virtual public Enemy
{
public:
	Consumables();
	~Consumables();

	//---- Health

		// DrawHealthPacks - Draws the healthpacks to the screen
	void DrawHealthPacks();
		// PickUpHealth - Increases the player's health when he/she collides with a healthpack 
	void PickUpHealth();
		// RestartHealthPacks - Clears the vectors that hold the sprites and which healthpacks have been used
	void RestartHealthPacks();

		// SetHealthPackTexture - Sets the texture of the healthpack
		// @param string - Directory of the texture
	void SetHealthPackTexture(std::string texturelocation);
		// SetHealthPackLocation - Sets the locations of all healthpacks
	void SetHealthPackLocation();
		// SetHealthPackPosition - Places the healthpacks on the locations set in SetHealthPackLocation
	void SetHealthPackPosition();
		// SetAmountOfHealthPacks - Sets the number of healthpacks
		// @param unsigned int - Amount of healthpacks
	void SetAmountOfHealthPacks(unsigned int amountofhealthpacks);
		// SetAmountHealed - Sets the amount of health that is regained upon colliding with a healthpack
		// @param unsigned int - Amount of health regained
	void SetAmountHealed(unsigned int amounthealed);
		// SetHealthTaken - Sets a healthpack to taken (won't be draw or collide with player)
		// @param int - The healthpack that is taken
	    // @param bool - Whether the healthpack is taken
	void SetHealthTaken(int i, bool healthtaken);

		// GetHealthTaken - Returns the healthpacks that have been used
	std::vector<bool> GetHealthTaken() const;

		// CreateHealthPacks - Creates vector elements equal to the amount of healthpacks
	void CreateHealthPacks();	

	//---- Ammo

		// DrawAmmoPacks - Draws the ammopacks to the screen
	void DrawAmmoPacks();
		// PickUpAmmo - Increases the player's ammo when he/she collides with an ammopack
	void PickUpAmmo();
		// RestartAmmoPacks - Clears the vectors that hold the sprites and which ammopacks have been used
	void RestartAmmoPacks();

		// SetAmmoPackTexture - Sets the texture of the ammopack
		// @param string - Directory of the texture
	void SetAmmoPackTexture(std::string texturelocation);
		// SetAmmoPackLocation - Sets the locations of all ammopacks
	void SetAmmoPackLocation();
		// SetAmmoPackPosition - Places the ammopacks on the locations set in SetAmmoPackLocation
	void SetAmmoPackPosition();
		// SetAmountOfAmmoPacks - Sets the number of ammopacks
		// @param unsigned int - Amount of ammopacks
	void SetAmountOfAmmoPacks(unsigned int amountofammopacks);
		// SetAmmoTaken - Sets an ammopack to taken (won't be draw or collide with player)
		// @param int - The ammopack that is taken
		// @param bool - Whether the healthpack is taken
	void SetAmmoTaken(int i, bool ammotaken);

		// GetAmmoTaken - Returns the ammopacks that have been used
	std::vector<bool> GetAmmoTaken() const;

		// CreateAmmoPacks - Creates vector elements equal to the amount of ammopacks
	void CreateAmmoPacks();

	//---- PowerUp

		// DrawPowerUps - Draws the powerups to the screen
	void DrawPowerUps();
		// PickUpPowerUp - Increases the player's jumpspeed when he/she collides with a powerup
	void PickUpPowerUp();
		// RestartPowerUps - Clears the vectors that hold the sprites and animation; Resets jumpspeed and player color
	void RestartPowerUps();
		// PowerUpAnimation - Changes the sprite that is currently visible to make it look like the sprite is moving
	void PowerUpAnimation();

		// SetPowerUpSize - Sets the width and height of the powerup
		// @param float - Width of the powerup
		// @param float - Height of the powerup
	void SetPowerUpSize(float width, float height);
		// SetPowerUpMargin - Sets the margin so the texture is displayed properly
		// @param float - Width of the margin
		// @param float - Height of the margin
	void SetPowerUpMargin(float marginX, float marginY);
		//SetPowerUpTexture - Sets the texture of the powerup
		// @param string - Directory of the texture
	void SetPowerUpTexture(std::string texturelocation);
		// SetPowerUpLocation - Sets the locations of all powerups
	void SetPowerUpLocation();
	    // SetPowerUpPosition - Places the powerups on the locations set in SetPowerUpLocation
	void SetPowerUpPosition();
		// SetAmountOfPowerUps - Sets the number of powerups
		// @param unsigned int - Amount of powerups
	void SetAmountOfPowerUps(unsigned int amountofpowerups);
		// SetPoweredUp - Sets powered up to true once the player has collided with the powerup
		// @param bool - Whether the player is powered up
	void SetPoweredUp(bool poweredup);		

		// GetPoweredUp - Returns whether the player is powered up
	bool GetPoweredUp() const;
	
		// CreatePowerUps - Creates vector elements equal to the amount of powerups
	void CreatePowerUps();

private:
	sf::Texture healthTexture;						// Loads the texture of the healthpacks
	sf::Texture ammoTexture;						// Loads the texture of the ammopacks
	sf::Texture powerUpTexture;						// Loads the texture of the power ups

	std::vector<sf::Sprite> healthSprite;			// Holds the sprites of the healthpacks
	std::vector<sf::Vector2f> healthLocation;		// Holds the locations of the healthpacks
	std::vector<sf::Sprite> ammoSprite;				// Holds the sprites of the ammopacks
	std::vector<sf::Vector2f> ammoLocation;			// holds the locations of the ammopacks
	std::vector<sf::Sprite> powerUpSprite;			// Holds the sprites of the power ups
	std::vector<sf::Vector2f> powerUpLocation;		// holds the locations of the power ups

	std::vector<sf::Vector2i> spriteAnimation;		// The cycling between two sprites
	std::vector<sf::Clock> animationRateTimer;		// The time between two sprites (for fluid animation)
	sf::Vector2f powerUpSize;						// The width and height of the powerup sprite
	sf::Vector2f powerUpMargin;						// The withspace between two sprites

	unsigned int numberOfHealthPacks;				// Holds the total amount of healthpacks
	unsigned int amountHealed;						// Holds the amount the player is healed when they pick up a healthpack
	unsigned int numberOfAmmoPacks;					// Holds the total amount of ammopacks
	unsigned int numberOfPowerUps;					// Holds the total amount of powerups
		
	bool poweredUp;									// Keeps track of if the player has used the powerup
	std::vector<bool> healthTaken;					// Keeps track of which healthpack has been used by the player
	std::vector<bool> ammoTaken;					// Keeps track of which ammopack has been used by the player
};

#endif
