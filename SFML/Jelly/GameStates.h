#ifndef GAMESTATES_H
#define GAMESTATES_H

#include "Player.h"
#include "Enemy.h"
#include "TitleScreen.h"
#include "MainScreen.h"
#include "TutorialScreen.h"
#include "PauseScreen.h"
#include "GameOverScreen.h"
#include "VictoryScreen.h"
#include "Consumables.h"
#include "Collectables.h"
#include "StateSwitching.h"

class GameStates :virtual public Player, virtual public Enemy, virtual public Consumables, virtual public Collectables, virtual public StateSwitching,
					virtual public TitleScreen, public MainScreen, virtual public TutorialScreen, public PauseScreen, public GameOverScreen, public VictoryScreen
{
public:
	GameStates();
	~GameStates();

		// UpdateTitleState - Checks for input from the player
	void UpdateTitleState();
		// DrawTitleState - Draws the assets from the titlescreen
	void DrawTitleState();

		// UpdateMainState - Checks for input from the player
	void UpdateMainState();
		// DrawMainState - Draws the assets from the mainscreen
	void DrawMainState();
	
		// UpdateTutorialState - Checks for input from the player
	void UpdateTutorialState();
		// DrawTutorialState - Draws the assets from the tutorialscreen
	void DrawTutorialState();

		// UpdatePlayingState - Checks for input from the player; updates enemies, bullets, etc
	void UpdatePlayingState();
		// DrawPlayingState - Draws the assets from the gamescreen
	void DrawPlayingState();

		// UpdatePauseState - Checks for input from the player
	void UpdatePauseState();
		// DrawPauseState - Draws the assets from the pausescreen
	void DrawPauseState();

		// UpdateGameOverState - Checks for input from the player
	void UpdateGameOverState();
		// DrawGameOverState - Draws the assets from the gameoverscreen
	void DrawGameOverState();

		// UpdateVictoryState - Checks for input from the player
	void UpdateVictoryState();
		// DrawVictoryState - Draws the assets from the victoryscreen
	void DrawVictoryState();
	
		
		// GameLoop - Keeps track of which state the game is in and draws the appropriate assets to the screen
	void GameLoop();
	
private:
	sf::Clock frameRateTimer;	// Makes sure the game will only be updated and the objects will only be draw a certain amount of times per second			
};

#endif