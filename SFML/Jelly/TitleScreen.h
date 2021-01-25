#ifndef TITLESCREEN_H
#define TITLESCREEN_H

#include "Game.h"
#include "Sound.h"

class TitleScreen : virtual public Sound, virtual public Game
{
public:
	TitleScreen();
	~TitleScreen();

		// TitleScreenInput - Switches to mainscreen when the player presses a key
	void TitleScreenInput();
		// DrawTitleText - Draws the name of the game to the screen
	void DrawTitleText();
		// DrawUnderTitleText - Draws the text under the title to the screen
	void DrawUnderTitleText();
		// DrawNameText - Draws the text that shows who created the game
	void DrawNameText();
		// DrawTitleScreenBackground - Draws the background to the screen
	void DrawTitleScreenBackground();

		// SetTitleFont - Sets the font used for the title
		// @param string - Directory of the font
	void SetTitleFont(std::string fontlocation);
		// SetTitleText - Sets the specifications of the title text
		// @param string - Text that is displayed as the title
		// @param float - Size of the letters
		// @param color - Color of the title
	void SetTitleText(std::string titletext, float textsize, sf::Color color);
		// SetUnderTitleFont - Sets the font used for the text under the title
		// @param string - Directory of the font
	void SetUnderTitleFont(std::string fontlocation);
		// SetUnderTitleText - Sets the specifications of the text under the title
		// @param float - Size of the letters
		// @param color - Color of the text under the title
	void SetUnderTitleText(float textsize, sf::Color color);
		// SetNameText - Sets the text that display the name of the creator
		// @param float - Size of the letters
		// @param color - Color of the text
	void SetNameText(float textsize, sf::Color);
		// SetTitleScreenBackground - Sets the background for the titlescreen
		// @param string - Directory of the texture		
	void SetTitleScreenBackground(std::string texturelocation);
	
private:
	sf::Texture titleScreenTexture;				// Holds the texture used for the background
	sf::RectangleShape titleScreenBackground;	// Holds the rectangle used as background on the titlescreen

	sf::Font titleFont;							// Holds the font used for the title
	sf::Text titleText;							// Holds the text used for the title

	sf::Font underTitleFont;					// Holds the font used for the text under the title
	sf::Text underTitleText;					// Holds the text that is displayed under the title 

	sf::Text nameText;							// Holds the text that displays the creator of the game

	sf::Clock switchTimer;						// Slows stateswitching so that it can't happen multiple times after eachother
};

#endif TITLESCREEN_H
