#ifndef PLAYER_H
#define PLAYER_H

#include "Sound.h"
#include "Map.h"

class Player : virtual public Sound, virtual public Map
{
public:		
	Player();
	~Player();	
	
		// Movement - Moves the player into the direction he/she chooses
	void Movement();
		// PositionUpdate - Keeps track of the position of the player on the collision map
	void PositionUpdate();
		// Animation - Changes the sprite that is currently visible to make it look like the sprite is moving
	void Animation();
		// Collision - Keeps track of whether the player is colliding with the tilemap
	void Collision();
		// DrawPlayer - Draws the player sprite to the screen
	void DrawPlayer();
		// GameScreenInput - Keeps track of whether the player is killed or has paused the game (switching to gameoverscreen and pausescreen respectively)
	void GameScreenInput();
		// ScreenScrolling - Moves the camera depending on the position of the player
	void ScreenScrolling();
		// DisplayHealth - Draws the hearts used as health to the screen
	void DisplayHealth();
		// Firing - Keeps track of whether the player is fired his gun, and whether a bullet should be created (only if player has ammo) 
	void Firing();							
		// Shoot - Creates a bullet and launches it into the direction of the crosshair
	void Shoot();							
		// Bullet - Updates the position of the bullets, moves them forward
	void Bullet();							
		// RotateGun - Rotates the gun towards the position of the crosshair
	void RotateGun();						
		// DrawGun - Draws the gun to the screen
	void DrawGun();							
		// Reloading - Increases the player's ammo, but not higher than the maximum amount of ammo specified
	void Reloading();						
		// DisplayAmmo - Draws the bullets used as ammo to the screen
	void DisplayAmmo();						
		// PlayerHit - Damages the player
		// @param unsigned int - The amount of damage
	void PlayerHit(unsigned int damage);	
		// PlayerHealed - Increases the health of the player, but not higher than the maximum amount of health specified
		// @param unsigned int - The amount of health healed
	void PlayerHealed(unsigned int health);	
		// DrawGameScreenBackground - Draws the backgrounds to the screen
	void DrawGameScreenBackground();
		// PlayerOutOfBounds - Reduces the players health to zero once he/she falls out of the screen
	void PlayerOutOfBounds();
		// RestartPlayerBullets - Clears the vectors that hold the bullets and bulletdirections
	void RestartPlayerBullets();

		// SetMaxAmmo - Sets the maximum amount of ammo the player can have
		// @param unsigned int - Maximum amount of ammo
	void SetMaxAmmo(unsigned int maxammo);
		// SetAmmoDisplay - Sets the specifications of the bullets used as ammo
		// @param string - Directory of the texture 
		// @param vector2i - Position of the bullets (display)
	void SetAmmoDisplay(std::string texturelocation, sf::Vector2i position);
		// SetReloadAmount - Sets the amount of ammo the player gets when colliding with an ammopack
		// @param unsigned int - Amount of ammo
	void SetReloadAmount(unsigned int reloadamount);
		// SetBullet - Sets the specifications of the bullets
		// @param color - Color of the bullets
		// @param float - Radius of the bullets
		// @param float - Speed of the bullets
	void SetBullet(sf::Color color, float radius, float bulletspeed);
		// SetGun - Sets the texture and position of the gun of the player
		// @param string - Directory of the texture used for the left side of the gun
		// @param string - Directory of the texture used for the right side of the gun
	void SetGun(std::string gunleft, std::string gunright);
		// SetPlayerSettings - Sets the specifications of the player
		// @param float - Width of the player
		// @param float - Height of the player
		// @param string - Directory of the texture
	void SetPlayerSettings(float width, float height, std::string spritelocation);
		// SetPlayerStartingLocation - Sets the location where the player starts
		// @param vector2f - The startingposition
	void SetPlayerStartingLocation(sf::Vector2f startingposition);
		// SetPlayerPosition - Sets the position of the player
		// @param vector2f - position of the x and y axis
	void SetPlayerPosition(sf::Vector2f position);
		// SetPlayerMaxHealth - Sets the maximum amount of health the player has
		// @param unsigned int - Maximum amount of health
	void SetPlayerMaxHealth(unsigned int health);
		// SetPlayerHealth - Sets the amount of health the player has
		// @param unsigned int - Amount of health
	void SetPlayerHealth(unsigned int health);	
		// SetSpriteAnimation -  Sets the startingposition of the spritecycling
		// @param int - The first sprite shown when the cycling starts
		// @param int - The startingdirection of the player
	void SetSpriteAnimation(int size, int direction);
		// SetPlayerInvulnerability - Sets the amount of time the player is invulnerable after getting hit by an enemy melee attack	
		// @param float - Amount of milliseconds
	void SetPlayerInvulnerability(float milliseconds);
		// SetHealthDisplay - Sets tje specifications of the hearts used as health	
		// @param string - Directory of the texture used for the hearts
		// @param string - Directory of the texture used for the empty hearts
		// @param vector2i - Position of the hearts
	void SetHealthDisplay(std::string texturelocation, std::string texturelocation2, sf::Vector2i position);
		// SetCurrentAmmo - Sets the amount of ammo the player currently has
		// @param unsigned int - Amount of ammo
	void SetCurrentAmmo(unsigned int ammo);
		// SetScreemScrolling - Sets the camera to the right position
	void SetScreenScrolling();
		// SetPlayerDamage - Sets the amount of damage the player deals
		// @param unsigned int - Amount of damage
	void SetPlayerDamage(unsigned int damage);
		// SetGameScreenBackground - Sets the specifications of the backgrounds
		// @param string - Directory of the first background
		// @param string - Directory of the second background
		// @param string - Directory of the third background
	void SetGameScreenBackground(std::string texturelocation, std::string texturelocation2, std::string texturelocation3);
		// SetCrateTopCollision - Sets whether the player is colliding with the top of the crate
		// @param bool - Whether the player is colliding with the top of the crate
	void SetCrateTopCollision(bool crate);
		
		// GetPlayerStartingLocation - Returns the starting location of the player
	sf::Vector2f GetPlayerStartingLocation();
		// GetPlayerSize - Returns the width (x) and height (y) of the player
	sf::Vector2f GetPlayerSize();
		// GetPlayerImage - Returns a reference of the sprite of the player
	sf::Sprite& GetPlayerImage();
		// GetPlayerHealth - Returns the amount of health the player has
	unsigned int GetPlayerHealth();
		// GetPlayerMaxHealth - Returns the maximum amount of health the player can have
	unsigned int GetPlayerMaxHealth();
		// GetPlayerAmmo - Returns the amount of ammo the player has
	unsigned int GetPlayerAmmo();
		// GetMaxAmmo - Returns the maximum amount of ammo the player can have
	unsigned int GetMaxAmmo();
		// GetPlayerDamage - Returns the amount of damage the player deals
	unsigned int GetPlayerDamage();
		// GetPlayerInvulnerability - Returns the amount of time the player is invulnerable after taking damage from enemy in melee
	float GetPlayerInvulnerability();
		// GetBullet - Returns the bullet
	sf::CircleShape GetBullet();
		// GetGameScreenBackground3 - Returns the backgroundimage used for the third section of the game
	sf::Sprite GetGameScreenBackground3();

		// GetBullets - Returns a reference of the position of the bullets
	std::vector <sf::Vector2f>& GetBullets();
		// GetBulletDirections - Returns a reference of the direction of the bullets
	std::vector <float>& GetBulletDirections();
		
private:	
	sf::Vector2f velocity;							// Keeps track of the (1) Horizontal and (2) Vertical velocity of the player	
	sf::Vector2f playerStartingLocation;			// Saves the (1) Horizontal and (2) Vertical starting position of the player
	sf::Vector2f playerSize;						// Holds the (1) Horizontal and (2) Vertical size of the player	
	sf::Vector2i healthDisplayLocation;				// Holds the (1) Horizontal and (2) Vertical of the health display
	sf::Vector2i ammoDisplayLocation;				// Holds the (1) Horizontal and (2) Vertical of the ammo display
	sf::Vector2i spriteAnimation;					// Keeps track of (1) Sprite cycling and (2) Player direction

	sf::Clock animationRateTimer;					// Makes sure the sprite cycling only happens a certain amount of times per second
	sf::Clock fireRateTimer;						// Makes sure the gun will only fire a certain amount of times per second	
	sf::CircleShape bullet;							// Keeps track of the bullet's radius and color
		
	sf::View camera;								// Keeps track of what part of the map should be shown
	sf::Vector2f cameraPosition;					// Keeps track of where the player is in the screen
	
	sf::Texture gameScreenTexture;					// Loads the sprite used as the background while playing (1st area)
	sf::Sprite gameScreenBackground;				// Holds the sprite used as the background while playing (1st area)
	sf::Texture gameScreenTexture2;					// Loads the sprite used as the background while playing (2nd area)
	sf::Sprite gameScreenBackground2;				// Holds the sprite used as the background while playing (2nd area)
	sf::Texture gameScreenTexture3;					// Loads the sprite used as the background while playing (3rd area)
	sf::Sprite gameScreenBackground3;				// Holds the sprite used as the background while playing (3rd area)

	

	sf::Texture playerTexture;						// Loads the sprite used for the player	
	sf::Sprite playerImage;							// Shows the sprite used for the player
	sf::Texture gunTextureRight;					// Loads the sprite used for the gun when looking to the right	
	sf::Sprite gunImageRight;						// Shows the sprite used for the gun when looking to the right
	sf::Texture gunTextureLeft;						// Loads the sprite used for the gun when looking to the left
	sf::Sprite gunImageLeft;						// Shows the sprite used for the gun when looking to the left
	sf::Texture healthTexture;						// Loads the sprite used for the health bar
	std::vector<sf::Sprite> healthSprite;			// Shows the sprite used for the health bar
	sf::Texture noHealthTexture;					// Loads the sprite used when health is lost
	std::vector<sf::Sprite> noHealthSprite;			// Shows the sprite used when health is lost
	sf::Texture ammoTexture;						// Loads the sprite used for the ammo bar
	std::vector<sf::Sprite> ammoSprite;				// Shows the sprite used for the ammo bar

	std::vector <sf::Vector2i> tiles;				// Holds eight points of the player for accurate collision	
	std::vector <sf::Vector2f> bullets;				// Holds the (1) Horizontal and (2) Vertical positions of every bullet
	std::vector <float> bulletDirections;			// Keeps track of the direction of every bullet
	
	float bulletSpeed;								// Holds the speed at which the bullets travel
	float angleShot;								// Makes sure the bullet will go to where the mouse is poiting
	float gunRotationRight;							// Makes sure the gun will point to where the mouse is when the player is turned to the right
	float gunRotationLeft;							// Makes sure the gun will point to where the mouse is when the player is turned to the left		
	float playerInvulnerability;					// Keeps track of the time a player is invulnerable

	unsigned int maxPlayerHealth;					// Keeps track of the maximum amount of health the player has
	unsigned int playerHealth;						// Keeps track of the current amount of health the player has	
	unsigned int maxAmmo;							// Keeps track of the maximum amount of ammo that is allowed
	unsigned int currentAmmo;						// Keeps track of the current amount of ammo
	unsigned int reloadAmount;						// Keeps track of the amount of bullets added upon picking up an ammo box
	std::vector<unsigned int> timesCollision;		// Holds the amount of times the player has collided with a tile, and which corner of the player is touching a tile
	unsigned int playerDamage;						// Holds the amount of damage the player deals
		
	bool groundCollision;							// Keeps track of whether or not the player has collided with the ground
	bool crateTopCollision;							// Keeps tracko f whether or not the player has collided with the top of the crate
	
	enum Direction { Down, Left, Right, Up };		// Used in conjuction with spriteAnimation, makes sure sprite direction matches with player direction
};

#endif