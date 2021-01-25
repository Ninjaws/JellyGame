#ifndef MAINSCREEN_H
#define MAINSCREEN_H

#include "TitleScreen.h"
#include "Player.h"
#include "Enemy.h"
#include "StateSwitching.h"

class MainScreen : virtual public Sound, virtual public Game, virtual public Player, virtual public Enemy, virtual public StateSwitching
{
public:
	MainScreen();
	~MainScreen();

		// DrawMainScreenBackground - Draws the background to the screen
	void DrawMainScreenBackground();
		// DrawMainButtons - Draws the buttons to the screen
	void DrawMainButtons();

		// MainMovementInput - Moves the selected button based on which button the player pressed
	void MainMovementInput();
		// MainButtonSelecting - Switches state based on the button the player has selected
	void MainButtonSelecting();

		// MoveUp - Highlights the button above the one previously selected
	void MoveUp();
		// MoveDown - Highlights the button below the one previously selected
	void MoveDown();

		// SetMainScreenBackground - Sets the texture for the background
		// @param string - Directory of the texture
	void SetMainScreenBackground(std::string texturelocation);
		// SetMainFont - Sets the font used by the buttons 
		// @param string - Directory of the font
	void SetMainFont(std::string fontlocation);
		// SetMainButtons - Sets the specifications for the buttons
		// @param color - Color of the selected button
		// @param color - Color of the other buttons
		// @param float - Size of the letters
		// @param unsigned int - Amount of buttons
	void SetMainButtons(sf::Color selected, sf::Color other, float textsize, unsigned int numberofbuttons);
		

		
		
private:
	sf::Texture mainScreenTexture;				// Holds the texture used for the background
	sf::RectangleShape mainScreenBackground;	// Holds the rectangle used as background on the mainscreen

	sf::Color selectedButton;					// Holds the color used for the selected button
	sf::Color otherButtons;						// Holds the color used for the other buttons
	
	int selectedItemIndex;						// Keeps track of which button is currently highlighted

	sf::Font mainFont;							// Holds the font used for the buttons
	std::vector<sf::Text>mainText;				// Holds the text used for the buttons
	
	sf::Clock buttonTimer;						// Makes sure the shuffling through the buttons doesn't go too quickly
	sf::Clock switchTimer;						// Slows stateswitching so that it can't happen multiple times after eachother
};

#endif
