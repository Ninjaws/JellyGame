#ifndef PAUSESCREEN_H
#define PAUSESCREEN_H

#include "TitleScreen.h"
#include "Player.h"
#include "StateSwitching.h"


class PauseScreen : virtual public Sound,  virtual public Game, virtual public Player, virtual public StateSwitching
{
public:
	PauseScreen();
	~PauseScreen();

		// DrawPauseScreenBackground - Draws the background to the screen
	void DrawPauseScreenBackground();
		// DrawPauseButtons - Draws the buttons to the screen
	void DrawPauseButtons();

		// PauseMovementInput - Moves the selected button based on which button the player pressed
	void PauseMovementInput();
		// PauseButtonSelecting - Switches state based on the button the player has selected
	void PauseButtonSelecting();

		// MoveUp - Highlights the button above the one previously selected
	void MoveUp();
		// MoveDown - Highlights the button below the one previously selected
	void MoveDown();

		// SetPauseScreenBackground - Sets the specifications for the background
		// @param color - Color of the background
		// @param float - Width of the background
		// @param float - Height of the background
	void SetPauseScreenBackground(sf::Color color, float width, float height);
		// SetPauseFont - Sets the font used for the buttons
		// @param string - Directory of the font
	void SetPauseFont(std::string fontlocation);
		// SetPauseButtons - Sets the specifications for the buttons
		// @param color - Color of the selected button
		// @param color - Color of the other buttons
		// @param float - Size of the letters
		// @param unsigned int - Amount of buttons
	void SetPauseButtons(sf::Color selected, sf::Color other, float textsize, unsigned int numberofbuttons);
	

	

private:
	sf::Texture pauseScreenTexture;				// Holds the texture used for the background
	sf::RectangleShape pauseScreenBackground;	// Holds the rectangle used as background on the pausescreen

	sf::Color selectedButton;					// Holds the color used for the selected button
	sf::Color otherButtons;						// Holds the color used for the other buttons

	int selectedItemIndex;						// Keeps track of which button is currently highlighted

	sf::Font pauseFont;							// Holds the font used for the buttons
	std::vector<sf::Text> pauseText;			// Holds the text used for the buttons
	 
	sf::Clock buttonTimer;						// Makes sure the shuffling through the buttons doesn't go too quickly
	sf::Clock switchTimer;						// Slows stateswitching so that it can't happen multiple times after eachother
};

#endif