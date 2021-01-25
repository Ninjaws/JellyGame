#ifndef VICTORYSCREEN_H
#define VICTORYSCREEN_H

#include "TitleScreen.h"
#include "Player.h"
#include "Enemy.h"
#include "StateSwitching.h"

class VictoryScreen : virtual public Player, virtual public StateSwitching, virtual public Collectables
{
public:
	VictoryScreen();
	~VictoryScreen();

	//--- Finish Flag

		// DrawFinish - Draws the finish to the screen
	void DrawFinish();
		// FinishReached - Switches the state to the victoryscreen once the player collides with the finish
	void FinishReached();

		// SetFinishTexture - Sets the texture used for the finish
		// @param string - Directory of the texture
	void SetFinishTexture(std::string texturelocation);
		// SetFinishLocation - Sets the location of the finish
		// @param float - Width of the finishsprite
		// @param float - Height of the finishsprite
	void SetFinishLocation(float width, float height);

	//--- Victory Screen

		// SetVictoryScreenBackground - Sets the texture for the background
		// @param string - Directory of the texture
	void SetVictoryScreenBackground(std::string texturelocation);
		// SetVictoryFont - Sets the font used for the 'Victory' text
		// @param string - Directory of the font
	void SetVictoryFont(std::string fontlocation);
		// SetJellyFont - Sets the font used for all text except the 'Victory' text
		// @param string - Directory of the font 
	void SetJellyFont(std::string fontlocation);
		// SetVictoryButtons - Sets the specifications of the buttons
		// @param color - Color of the selected button
		// @param color - Color of the other buttons
		// @param float - Size of the letters
		// @param unsigned int - Amount of buttons
	void SetVictoryButtons(sf::Color selected, sf::Color other, float textsize, unsigned int numberofbuttons);
		// SetVictoryText - Sets the 'Victory' text
		// @param string - The text displayed at the top of the victoryscreen
		// @param color - Color of the text
		// @param unsigned int - Size of the letters
	void SetVictoryText(std::string text, sf::Color color, unsigned int textsize);
		// SetJellyText - Sets the text under the jellies
		// @param color - Color of the text
		// @param unsigned int - Size of the letters
	void SetJellyText(sf::Color color, unsigned int textsize);
		// SetJellyTexture2 - Sets the texture used for the jellies in the victoryscreen
		// @param string - Directory of the texture
	void SetJellyTexture2(std::string texturelocation);

		// DrawVictoryScreenBackground - Draws the background to the screen
	void DrawVictoryScreenBackground();
		// DrawVictoryButtons - Draws the buttons to the screen
	void DrawVictoryButtons();
		// DrawVictoryText - Draws the 'Victory' text to the screen
	void DrawVictoryText();
		// DrawRescuedJellies - Draws the jellies to the screen
	void DrawRescuedJellies();
		// DrawRescuedJelliesText - Draws the text under the jellies to the screen
	void DrawRescuedJelliesText();

		// VictoryMovementInput - Moves the selected button based on which button the player pressed
	void VictoryMovementInput();
		// VictoryButtonSelecting - Switches state based on the button the player has selected
	void VictoryButtonSelecting();
		// MoveLeft - Highlights the button to the left of the one previously selected
	void MoveLeft();
		// MoveRight - Highlights the button to the right of the one previously selected
	void MoveRight();
	

private:
	//--- Finish Flag
	sf::Texture finishTexture;					// Loads the texture used for the finish of the game
	sf::Sprite finishSprite;					// Holds the sprite used for the finish of the game

	//--- Victory Screen
	sf::Texture victoryScreenTexture;			// Holds the texture used for the background
	sf::RectangleShape victoryScreenBackground; // Holds the rectangle used as background on the mainscreen

	sf::Color selectedButton;					// Holds the color used for the selected button
	sf::Color otherButtons;						// Holds the color used for the other buttons

	int selectedItemIndex;						// Keeps track of which button is currently highlighted

	sf::Font victoryFont;						// Holds the font used for the victory text
	sf::Font jellyFont;							// Holds the font used for the rest of the text
	sf::Text victory;							// Holds the text that says victory
	sf::Text jellyText;							// Holds the text that tells the player how many jellies he/she has freed
	std::vector<sf::Text> victoryText;			// Holds the text used for the buttons

	sf::Clock buttonTimer;					    // Slows down buttonscrolling so you are able to select one button at a time
	sf::Clock switchTimer;					    // Slows down stateswitching so buttons don't get pressed multiple times


	sf::Texture jellyTexture;			        // Loads the texture used for the jellies shown in the victory screen
	std::vector<sf::Sprite> jellySprite;        // Holds the sprites for the jellies shown in the victory screen


};

#endif