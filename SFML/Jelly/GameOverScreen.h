#ifndef GAMEOVERSCREEN_H
#define GAMEOVERSCREEN_H

#include "TitleScreen.h"
#include "Player.h"
#include "Enemy.h"
#include "StateSwitching.h"

class GameOverScreen : virtual public Sound, virtual public Game, virtual public Player, virtual public Enemy, virtual public StateSwitching
{
public:
	GameOverScreen();
	~GameOverScreen();

		// SetGameOverScreenBackground - Sets the background for the gameoverscreen
		// @param color - Color of the background
	void SetGameOverScreenBackground(sf::Color color);	
		// SetGameOverFont - Sets the font used by the text in the gameoverscreen
		// @param string - Directory of the font
	void SetGameOverFont(std::string fontlocation);
		// SetGameOverButtons - Sets the specifications for the buttons
		// @param color - Color of the selected button
		// @param color - Color of the other buttons
		// @param float - Size of the letters
		// @param unsigned int - Amount of buttons
	void SetGameOverButtons(sf::Color selected, sf::Color other, float textsize, unsigned int numberofbuttons);
		// SetGameOverText - Sets the specifications for the 'Game Over' sign
		// @param string - Text that is displayed above the buttons
		// @param color - Color of the text above the buttons
		// @param float - Size of the letters
	void SetGameOverText(std::string text, sf::Color color, float textsize);
	
		// DrawGameOverScreenBackground - Draws the background to the screen
	void DrawGameOverScreenBackground();
		// DrawGameOverButtons - Draws the buttons to the screen
	void DrawGameOverButtons();
		// DrawGameOverText - Draws the texxt above the buttons to the screen
	void DrawGameOverText();

		// GameOverMovementInput - Moves the selected button based on which button the player pressed
	void GameOverMovementInput();
		// GameOverButtonSelecting - Switches state based on the button the player has selected
	void GameOverButtonSelecting();
		// MoveLeft - Highlights the button to the left
	void MoveLeft();
		// MoveRight - Highlights the button to the right
	void MoveRight();

private:
	sf::RectangleShape GameOverScreenBackground;	// Holds the rectangle that is used as the game over background

	sf::Color selectedButton;						// Holds the color used for the selected button
	sf::Color otherButtons;							// Holds the color used for the other buttons

	int selectedItemIndex;							// Keeps track of which button is currently highlighted

	sf::Font gameOverFont;							// Holds the font used for the text on the game over screen
	sf::Text gameOver;								// Holds the text used on the game over screen
	std::vector<sf::Text> gameOverText;				// Holds the buttons used on the game over screen

	sf::Clock buttonTimer;							// Slows down buttonscrolling so you are able to select one button at a time
	sf::Clock switchTimer;							// Slows down stateswitching so buttons don't get pressed multiple times
};

#endif