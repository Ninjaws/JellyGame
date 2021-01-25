#ifndef TUTORIALSCREEN_H
#define TUTORIALSCREEN_H

#include "TitleScreen.h"

class TutorialScreen : virtual public TitleScreen
{
public:
	TutorialScreen();
	~TutorialScreen();

		// TutorialScreenInput - Switches back to the mainscreen upon pressing a key
	void TutorialScreenInput();
		// DrawTutorialText - Draws the text to the screen
	void DrawTutorialText();
		// DrawTutorialBackground - Draws the background to the screen
	void DrawTutorialBackground();

		// SetTutorialScreenBackground - Sets the texture for the background
		// @param string - Directory of the texture
	void SetTutorialScreenBackground(std::string texturelocation);
		// SetTutorialScreenText - Sets the specifications of the text on the tutorialscreen
		// @param string - Text that is displayed on the tutorialscreen
		// @param float - Size of the letters
		// @param color - Color of the text
	void SetTutorialScreenText(std::string tutorialtext, float textsize, sf::Color color);
		// SetTutorialScreenFont - Sets the font of the text
		// @param string - Directory of the font
	void SetTutorialScreenFont(std::string fontlocation);

private:
	sf::Texture tutorialScreenTexture;				// Holds the texture used for the background
	sf::RectangleShape tutorialScreenBackground;	// Holds the rectangle used as background on the tutorialscreen

	sf::Font tutorialFont;							// Holds the font used on the text on the tutorialscreen
	sf::Text tutorialText;							// Holds the text used on the tutorial screen

	sf::Clock stateSwitchTimer;						// Slows stateswitching so that it can't happen multiple times after eachother
};

#endif
