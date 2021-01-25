#ifndef COLLECTABLES_H
#define COLLECTABLES_H

#include "Player.h"

class Collectables : virtual public Player
{
public:
	Collectables();
	~Collectables();

	//--- Crates

		// DrawCrates - Draws the crates to the screen
	void DrawCrates();
		// RestartCrates - Clears the vectors that hold the sprites and which crates are destroyed
	void RestartCrates();
		// CrateCollision - Makes sure the player cannot move through the crate	 
	void CrateCollision();
		
		// SetCrateTexture - Sets the texture of the crate
		// @param string - Directory of the texture
	void SetCrateTexture(std::string texturelocation);
		// SetCrateLocation - Sets the locations of all crates
	void SetCrateLocation();
		// SetCratePosition - Places the crates on the locations set in SetCrateLocation
	void SetCratePosition();
		// SetAmountOfCrates - Sets the number of crates (and jellies)
		// @param unsigned int - Amount of crates/jellies 
	void SetAmountOfCrates(unsigned int amountofcrates);
		// SetCrateDestroyed - Sets a crate to destroyed (won't be drawn or collide with player)
		// @param int - The crate that is destroyed
	void SetCrateDestroyed(int i);

		// GetCrateDestroyed - Returns the destroyed crates
	std::vector<bool> GetCrateDestroyed() const;
		// GetCrateSprite - Returns references of the sprites of the crates
	std::vector <sf::Sprite>& GetCrateSprite();
	
		// CreateCrates - Creates vector elements equal to the amount of crates
	void CreateCrates();	
	

	//--- Jellies

		// DrawJellies - Draws the jellies to the screen
	void DrawJellies();
		// RestartJellies - Clears the vectors that hold the sprites, velocity and collision
	void RestartJellies();
		// JellyMovement - Makes the jellies jump up and down when the crate is destroyed
	void JellyMovement();

		// GetAmountOfJelliesRescued - Returns the amount of jellies who's crates are destroyed
	unsigned int GetAmountOfJelliesRescued() const;
		// GetNumberOfCrates - Returns the total amount of crates
	unsigned int GetNumberOfCrates() const;	
		// GetJellyTexture - Returns the texture used for the jellies
	sf::Texture GetJellyTexture() const;

		// SetJellyTexture - Sets the texture of the jelly
		// @param string - Directory of the texture
	void SetJellyTexture(std::string texturelocation);
		// SetJellyPosition - Places the jellies on the locations set in SetCrateLocation
	void SetJellyPosition();

		// CreateJellies - Creates vector elements equal to the amount of crates
	void CreateJellies();


	//--- Display

		// DisplayJelliesFreed - Draws the display (jelly sprite and amount freed) to the screen
	void DisplayJelliesFreed();

		// SetJelliesFreedDisplay - Sets the specifications of the display 
		// @param string - Directory of the texture
		// @param Vector2i - Position of the display
		// @param Color - Color of the letters
		// @param string - Directory of the font
		// @param float - Size of the letters
	void SetJelliesFreedDisplay(std::string texturelocation, sf::Vector2i position, sf::Color color, std::string fontLocation, float textsize);


private:
	sf::Texture crateTexture;					// Loads the texture of the crates
	sf::Texture jellyTexture;					// Loads the texture of the jellies
	sf::Texture jelliesFreedTexture;			// Loads the texture of the jelly in the top right corner

	sf::Text jelliesFreed;						// Holds the text that shows how many jellies are freed
	sf::Font jelliesFreedFont;					// Holds the font used for the text of the display

	sf::Sprite jelliesFreedSprite;				// Holds the sprite of the jelly in the top right corner

	sf::Vector2i jellyDisplayLocation;			// Holds the location where the amount of jellies freed are displayed

	std::vector<sf::Sprite> crateSprite;		// Holds the sprites of the crates
	std::vector<sf::Sprite> jellySprite;		// Holds the sprites of the jellies inside the crates
	std::vector<sf::Vector2f> crateLocation;	// Holds the locations of the crates/jellies
	std::vector<sf::Vector2f> velocity;			// Makes sure the jellies jump when the crate is destroyed
	std::vector<bool> collision;				// Keeps track of whether or not the player has collided with a crate
	std::vector<bool> crateDestroyed;			// Keeps track of whether or not a crate has been destroyed

	unsigned int numberOfCrates;				// Holds the total amount of crates
	unsigned int numberOfDestroyedCrates;		// Holds the amount of crates that have been destroyed
};

#endif