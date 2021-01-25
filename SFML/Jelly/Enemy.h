#ifndef ENEMY_H
#define ENEMY_H

#include "Sound.h"
#include "Map.h"
#include "Player.h"
#include "Collectables.h"
#include <string>


class Enemy : virtual public Sound, virtual public Map, virtual public Player, virtual public Collectables
{
public:
	Enemy();
	~Enemy();

		// DrawEnemy - Draws the enemies to the screen
	void DrawEnemy();
		// EnemyMovement - Moves the enemy into the direction it is facing; turns the enemy when it reaches an edge or obstacle
		// @param int - The enemy 
	void EnemyMovement(int i);
		// EnemyPositionUpdate - Keeps track of the enemy position on the collision map
		// @param int - The enemy
	void EnemyPositionUpdate(int i);
		// EnemyCollision - Keeps track of whether the enemy has collided with the tilemap
		// @param int - The enemy
	void EnemyCollision(int i);
		// PlayerBulletCollision - Checks if shots from the player have hit the enemy, a crate or the collision map
	void PlayerBulletCollision();		 
		// EnemyBulletCollision - Checks if shots from the enemy have hit the player or the collision map
	void EnemyBulletCollision();		 
		// DrawHealthBar - Draws the healthbar above the enemy to the screen
	void DrawHealthBar();
		// EnemyDestroyed - Stops all interaction with the enemy once the health reaches 0
	void EnemyDestroyed();
		// EnemyAttack - Damages the player when he/she collides with the enemy
	void EnemyAttack();					
		// RestartEnemies - Clears all vectors that affect the enemies (sprite, health, etc)
	void RestartEnemies();				
		// EnemyAnimation - Changes the sprite that is currently visible to make it look like the sprite is moving
		// @param int - The enemy
	void EnemyAnimation(int i);
		// PlayerDetection - Checks if the player is within range of the enemy
	void PlayerDetection();
		// EnemyShootingLeft - Fires a bullet towards the player when the enemy is turned to the left
		// @param int - The enemy
	void EnemyShootingLeft(int i);
		// EnemyShootingRight - Fires a bullet towards the player when the enemy is turned to the right
		// @param int - The enemy
	void EnemyShootingRight(int i);
		// EnemyBullets - Updates the position of the bullets, moves them forward
	void EnemyBullets();
		// DrawEnemyGun - Draws the guns of the enemies to the screen
	void DrawEnemyGun();
		
		// SetEnemyDamage - Sets the amount of damage the enemies deal
		// @param unsigned int - Amount of damage
	void SetEnemyDamage(unsigned int damage);	
		// SetEnemyStartingPosition - Sets the startinglocations of all enemies
	void SetEnemyStartingPosition();
		// SetEnemyPosition - Places the enemies on the startinglocations set in SetEnemyStartingPosition
	void SetEnemyPosition();	
		// SetEnemyMaxHealth - Sets the maximum amount of health for the enemies 
		// @param unsigned int - Maximum amount of health
	void SetEnemyMaxHealth(unsigned int health);
		// SetEnemyHealth - Sets the amount of health the enemy has currently
		// @param unsigned int - Amount of health
	void SetEnemyHealth(unsigned int health);
		// SetEnemyHealthBar - Sets the rectangle that serves as a healthbar 
		// @param color - Color of the healthbar
	void SetEnemyHealthBar(sf::Color color);
		// SetEnemySize - Sets the width and height of the enemies
		// @param vector2f - Width (x) and height (y)
	void SetEnemySize(sf::Vector2f enemysize);
		// SetEnemyTexture - Sets the texture used for the enemies
		// @param string - Directory of the texture
	void SetEnemyTexture(std::string texturelocation);
		// SetAmountOfEnemies - Sets how many enemies are present
		// @param unsigned int - Amount of enemies
	void SetAmountOfEnemies(unsigned int amountofenemies);
		// SetEnemySpriteAnimation - Sets the startingposition of the spritecycling
		// @param int - The first sprite shown when the cycling starts
		// @param int - The startingdirection of the enemy
	void SetEnemySpriteAnimation(int size, int direction);		
		// SetEnemySpottingRange - Sets the distance the enemies can detect the player over
		// @param float - Distance the enemies can see
	void SetEnemySpottingRange(float spottingrange);
		// SetEnemyBullet - Sets the specifications of the bullets
		// @param color - Color of the bullets
		// @param float - Radius of the bullets
		// @param float - Speed of the bullets
	void SetEnemyBullet(sf::Color color, float radius, float bulletspeed);
		// SetEnemyGun - Sets the texture and position of the enemy guns
		// @param string - Directory of the texture of the left side of the gun
		// @param string - Directory of the texture of the right side of the gun
	void SetEnemyGun(std::string gunleft, std::string gunright);
		// SetEnemiesKilled - Sets an enemy to 'killed' (no longer has interaction with the player)
		// @param int - The enemy
	void SetEnemiesKilled(int i);

		// GetEnemyMaxHealth - Returns the maximum amount of health for enemies
	unsigned int GetEnemyMaxHealth();
		// GetAmountOfEnemies - Returns the number of enemies
	unsigned int GetAmountOfEnemies();
		// GetEnemyTexturesLocation - Returns the directory of the texture used for the enemies
	std::string GetEnemyTextureLocation();
		// GetEnemySize - Returns the width and height of the enemies
	sf::Vector2f GetEnemySize();
		// GetEnemiesKilled - Returns whether an enemy has been killed
	std::vector<bool> GetEnemiesKilled();
	
		// CreateEnemies - Creates vector elements equal to the amount of enemies
	void CreateEnemies();

private:
	sf::CircleShape enemyBullet;									// Keeps track of the bullet's radius and color
	sf::Texture enemyTexture;										// Loads the texture used for the enemies
	sf::Clock invulnerabilityTimer;									// Holds the amount of time between getting hit by standing on the enemy the player cannot be damaged
	sf::Vector2f enemySize;											// Holds the width and height of the enemies
	std::string enemyTextureLocation;								// Holds the location of the enemy texture

	sf::Texture gunTextureRight;									// Loads the sprite used for the gun when looking to the right	
	std::vector<sf::Sprite> gunImageRight;							// Shows the sprite used for the gun when looking to the right
	sf::Texture gunTextureLeft;										// Loads the sprite used for the gun when looking to the left
	std::vector<sf::Sprite> gunImageLeft;							// Shows the sprite used for the gun when looking to the left

	std::vector<float> gunRotationLeft;								// Makes sure the gun will point to where the player is when the enemy is turned to the left
	std::vector<float> gunRotationRight;							// Makes sure the gun will point to where the player is when the enemy is turned to the right	

	std::vector<sf::Sprite> enemySprite;							// Holds the sprites used for the enemies
	std::vector<sf::Vector2f> velocity;								// Holds the movespeed of all enemies and in what direction they should move
	std::vector<sf::Clock> animationRateTimer;						// Makes the movement animation of the enemies seem smooth
	std::vector<sf::Clock> fireRateTimer;							// Makes sure the gun will only fire a certain amount of times per second
	std::vector<sf::Vector2f> enemyStartingLocation;				// Holds the starting position of all enemies; doesnt get erased
	std::vector<sf::Vector2f> enemyStartPosition;					// Holds the starting position of all enemies; gets erased when enemy is destroyed
	std::vector<sf::RectangleShape> healthBar;						// Holds the healthbars for all enemies
	std::vector<unsigned int> enemyHealth;							// Holds the health for all enemies
	std::vector<bool> hasMoved;										// Checks if the enemy has moved, so that the spotted sound only plays once
	std::vector<bool> isKilled;										// Keeps track of if the enemy is killed, so that the killed sound only plays once
	std::vector<sf::Vector2i> spriteAnimation;						// Keeps track of (1) Sprite cycling and (2) Enemy direction	
			
	std::vector<std::vector <sf::Vector2f>> enemyBullets;			// Holds the (1) Horizontal and (2) Vertical positions of every bullet
	std::vector<std::vector <float>> enemyBulletDirections;			// Keeps track of the direction of every bullet	
		
	float enemySpottingRange;										// Holds the amount of distance over which the enemy can spot the player
	float enemyAngleShot;											// Makes sure the bullet will go to where the player is standing	
	float enemyBulletSpeed;											// Holds the speed at which the bullets travel
	unsigned int numberOfEnemies;									// Holds the total amount of enemies there are
	unsigned int maxEnemyHealth;									// Holds the maximum amount of health the enemies have
	unsigned int enemyDamage;										// Holds the amount of damage the enemies deal
	
	enum Direction { Down, Left, Right, Up };						// Used in conjuction with spriteAnimation, makes sure sprite direction matches with enemy direction


	std::vector<std::vector<sf::Vector2i>> enemyCorners;			// Keeps track of the part of the enemy that collides with the tilemap
	std::vector<bool> collision;									// Keeps track of whether or not the enemy has reached a dead end
	std::vector<bool> groundCollision;								// Keeps track of whether or not the enemy is standing on the ground
};

#endif