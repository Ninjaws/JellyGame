#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics.hpp>
#include <iostream>

class Game
{
public:
	Game();	
	~Game();
	
		// SetWindow - Sets the specifications of the window
		// @param videomode - Width and height of the window
		// @param string - Name that is displayed at the top of the window
	void SetWindow(sf::VideoMode videoMode, std::string windowName);
		// SetTestMode - Sets the possibility of making changes to the tile/collision map and loading them to the screen to true or false
		// @param bool - Whether the testmode is active
	void SetTestMode(bool mode);
		// SetMoveSpeed - Sets the movement speed for the player/enemies
		// @param float - The movement speed
	void SetMoveSpeed(float speed);
		// SetJumpSpeed - Sets the jump speed for the player/jellies
		// @param float - Jump speed
	void SetJumpSpeed(float jump);
		// SetNormalJumpSpeed - Sets the jump speed when the player isn't powered up
		// @param float - Jump speed
	void SetNormalJumpSpeed(float jump);
		// SetPoweredUpJumpSpeed - Sets the jump speed when the player is powered up 
		// @param float - Jump speed
	void SetPoweredUpJumpSpeed(float jump);
		// SetGravity - Sets the gravity that affects how quickly the player/jellies fall
		// @param float - The gravity
	void SetGravity(float grav);
		// SetFrameRate - Sets the amount of times per second the screen gets refreshed
		// @param float - Amount of times per second
	void SetFrameRate(float fps);
		// SetFireRate - Sets the amount of times per second the gun of the player can fire
		// @param float - Amount of times per second
	void SetFireRate(float bps);
		// SetEnemyFireRate - Sets the amount of times per second the gun of the enemy can fire
		// @param float - Amount of times per second
	void SetEnemyFireRate(float bps);
		// SetAnimationRate - Sets the amount of times per second the sprite is changed (to simulate animation)
		// @param float - Amount of times per second
	void SetAnimationRate(float aps);
		// SetStateSwitchingRate - Sets the time between switching states
		// @param float - Amount of times per second
	void SetStateSwitchingRate(float sps);
		// SetState - Sets the state of the game
		// @param int - The state that is being changed to
	void SetState(int state);
		// SetMouseCursor - Sets the cursor on or off
		// @param bool - Whether the cursor gets turned on
	void SetMouseCurser(bool boolean);
		// SetCrossHair - Sets the texture used as crosshair (replaces mouse arrow)
		// @param string - Directory of the texture
	void SetCrossHair(std::string texturelocation);	
		// SetSelectingKey - Sets the key used for choosing an option in the title/main/tutorial/pause/gaveover/victory screen
		// @param key - The key that is pressed
	void SetSelectingKey(sf::Keyboard::Key selectingkey);

		// GetWindow - Returns a reference of the window
	sf::RenderWindow& GetWindow();
		// GetMousePosition - Returns the global position of the mouse
	sf::Vector2f GetMousePosition();
		// GetWindowPosition - Returns the global position of the window
	sf::Vector2f GetWindowPosition();
		// GetSelectingKey - Returns the key that is used to choose an option in the title/main/tutorial/pause/gaveover/victory screen
	sf::Keyboard::Key GetSelectingKey();
		// GetScreenWidth - Returns the width of the window
	float GetScreenWidth();
		// GetScreenHeight - Returns the height of the window
	float GetScreenHeight();	
		// GetMoveSpeed - Returns the movement speed of the player/enemies
	float GetMoveSpeed();
		// GetJumpSpeed - Returns the jump speed of the player/jellies
	float GetJumpSpeed();
		// GetNormalJumpSpeed - Returns the jump speed without powerup
	float GetNormalJumpSpeed();
		// GetPoweredUpJumpSpeed - Returns the jump speed with powerup
	float GetPoweredUpJumpSpeed();
		// GetGravity - Returns the gravity that affects the player/enemies/jellies
	float GetGravity();
		// GetFrameRate - Returns the amount of times per second the screen gets updated
	float GetFrameRate();
		// GetFireRate - Returns the amount of times per second the gun of the player fires
	float GetFireRate();
		// GetEnemyFireRate - Returns the amount of times per second the enemy gun fires
	float GetEnemyFireRate();
		// GetAnimationRate - Returns the amount of times per second the sprite changes 
	float GetAnimationRate();
		// GetStateSwitchingRate - Returns the amoount of time between switching states
	float GetStateSwitchingRate();
		// GetTestMode - Returns whether testmode is active
	bool GetTestMode();
		// GetState - Returns the state the game is currently in
	int GetState();	
	
	
		// DisplayState - Prints a console message that shows in which state the game is currently
		// @param string - The state that is being switched to
	void DisplayState(std::string state);
		// States - Holds all the states the game can be in
	enum States { State_TitleScreen, State_MainScreen, State_TutorialScreen, State_GameScreen, State_PauseScreen, State_GameOverScreen, State_VictoryScreen };

		// DrawCrossHair - Draws the crosshair to the screen
	void DrawCrossHair();

		// UpdateMousePosition - Sets the mouse position to global (relative to desktop)
	void UpdateMousePosition();
		// UpdateWindowPosition - Sets the window position to global (relative to desktop)
	void UpdateWindowPosition();

private:
	sf::RenderWindow Window;		// Holds the window that draws everything to the screen
	bool testMode = false;			// Keeps track of whether or not testMode is activated 
		
	float moveSpeed;				// Keeps track of the movement speed of the player
	float jumpSpeed;				// Keeps track of the jump speed of the player
	float normalJumpSpeed;			// Keeps track of the jump speed of the player without the powerUp
	float poweredUpJumpSpeed;		// Keeps track of the jump speed of the player with the powerUp

	float gravity;					// Keeps track of the gravity (decides how fast the player falls when in the air)

	float frameRate;				// Keeps track of the amount of times the screen gets refreshed each second
	float fireRate;					// Keeps track of the amount of shots allowed per second
	float enemyFireRate;			// Keeps track of the amount of shots the enemy can fire per second
	float animationRate;			// Keeps track of the amount of times the player sprite cycles each second
	float stateSwitchingRate;		// Keeps track of the time between screenstate switching;
	
	sf::Keyboard::Key selectingKey;	// Holds the key that is used for pressing buttons in menus

	int State;						// Keeps track of which state should be displayed, works in conjuction with enum States

	sf::Texture crossHairTexture;	// Holds the location of the of the crosshair
	sf::Sprite crossHairSprite;     // Holds the image of the crosshair

	sf::Vector2i mousePixelPos;		// Holds the local position of the mouse
	sf::Vector2f mouseWorldPos;		// Holds the global position of the mouse

	sf::Vector2i windowPixelPos;	// Holds the local position of the window
	sf::Vector2f windowWorldPos;	// Holds the global position of the window		
};

#endif