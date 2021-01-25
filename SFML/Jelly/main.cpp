/******************
*	Ian Vink	  *
*	Jelly Rescue  *
*	06-04-2015    *
*******************/

#include "GameStates.h"
#include "Player.h"

int main()
{
	GameStates game;
		
	//-----General	
	game.SetWindow(sf::VideoMode(640, 544, 32), "Jelly Rescue");
	game.SetTestMode(true);
	game.SetMoveSpeed(5.0f);		
	game.SetJumpSpeed(7.0f);		
	game.SetNormalJumpSpeed(7.2f);	
	game.SetPoweredUpJumpSpeed(9.0f); 
	game.SetGravity(0.6f);			
	game.SetSelectingKey(sf::Keyboard::Return);
	//-----TileMap
	game.SetMapLocation("Data/Maps/map1.txt");
	game.SetColMapLocation("Data/Maps/colmap1.txt");		
	//-----Player Settings
	game.SetPlayerSettings(32, 32, "Data/Textures/player.png"); 
	game.SetPlayerStartingLocation(sf::Vector2f(200, 350)); 
	game.SetSpriteAnimation(1, 0);
	game.SetPlayerMaxHealth(10);
	game.SetPlayerInvulnerability(500);
	game.SetPlayerDamage(1);
	//-----Enemy Settings
	game.SetEnemySize(sf::Vector2f(32, 32));
	game.SetEnemyTexture("Data/Textures/enemy.png");
	game.SetAmountOfEnemies(8);	
	game.SetEnemyStartingPosition();
	game.SetEnemyDamage(1);
	game.SetEnemyMaxHealth(10);
	game.SetEnemyHealthBar(sf::Color::Red);
	game.SetEnemySpriteAnimation(1, 2);
	game.SetEnemySpottingRange(300);
	//-----Healthpacks
	game.SetHealthPackTexture("Data/Textures/FirstAidKit.png");
	game.SetAmountOfHealthPacks(4);
	game.SetHealthPackLocation();
	game.SetAmountHealed(2);
	game.SetHealSound("Data/Audio/Sounds/healmag.wav", 70);
	//-----Ammopacks
	game.SetAmmoPackTexture("Data/Textures/Bullets_small.png");
	game.SetAmountOfAmmoPacks(4);
	game.SetAmmoPackLocation();
	game.SetMaxAmmo(100);
	game.SetReloadAmount(10);
	game.SetReloadSound("Data/Audio/Sounds/shotgunReload.wav", 100);
	//-----PowerUp
	game.SetPowerUpTexture("Data/Textures/powerUpAnimation.png");
	game.SetAmountOfPowerUps(1);
	game.SetPowerUpLocation();
	game.SetPowerUpSound("Data/Audio/Sounds/powerUpSound.wav", 100);
	game.SetPowerUpSize(50, 55);
	game.SetPowerUpMargin(18, 10);
	//-----Crates
	game.SetCrateTexture("Data/Textures/woodencrate.png");
	game.SetAmountOfCrates(3);
	game.SetCrateLocation();
	game.SetCrateDestroyedSound("Data/Audio/Sounds/crateBreak.wav", 100);
	//-----Jellies
	game.SetJellyFreedSound("Data/Audio/Sounds/jellyFreed.wav", 25);
	game.SetJellyTexture("Data/Textures/happyjelly.png");
	//-----Player Weapon
	game.SetGun("Data/Textures/gunleft.png", "Data/Textures/gunright.png");
	game.SetBullet(sf::Color::Yellow, 5.0f, 15.0f);	
	//-----Enemy Weapon
	game.SetEnemyBullet(sf::Color::Red, 5.0f, 15.0f);
	game.SetEnemyGun("Data/Textures/gunleft_2.png", "Data/Textures/gunright_2.png");	
	//-----Weapon Sounds
	game.SetGunSound("Data/Audio/Sounds/gunShot.wav", 10);	
	game.SetOutofammoSound("Data/Audio/Sounds/outOfAmmo.wav", 20);	
	//-----Other Sounds
	game.SetPainSound("Data/Audio/Sounds/pain.wav", 30);
	game.SetPlayerDamageSound("Data/Audio/Sounds/WaterBalloon.wav", 200);
	game.SetPlayerSpottedSound("Data/Audio/Sounds/playerSpotted.wav", 300);
	//-----Timers
	game.SetFireRate(6);			// So many times per second
	game.SetEnemyFireRate(12);
	game.SetFrameRate(45);
	game.SetAnimationRate(6);	
	game.SetStateSwitchingRate(4);	// 1/4th of a second per switch, so button doesnt get pressed twice
	//-----Display
	game.SetJelliesFreedDisplay("Data/Textures/happyjelly.png", sf::Vector2i(500, 5), sf::Color::Red, "Data/Fonts/Sansation.ttf", 30);
	game.SetAmmoDisplay("Data/Textures/bullet_hud.png",sf::Vector2i(5, 40));
	game.SetHealthDisplay("Data/Textures/heart.png", "Data/Textures/heart_empty.png", sf::Vector2i(5, 5));
	game.SetScreenScrolling();
	//-----TitleScreen
	  //game.SetTitleScreenBackground("Data/Textures/TitleScreenBackground.png");
	game.SetMainMusic("Data/Audio/Music/Crash_WarpRoomTheme.ogg", 50);
	game.SetTitleFont("Data/Fonts/Reckoner_Bold.ttf");
	game.SetTitleText("Jelly rescue", 100, sf::Color::Red);
	game.SetUnderTitleFont("Data/Fonts/Sansation.ttf");
	game.SetUnderTitleText(30, sf::Color::White);
	game.SetNameText(20, sf::Color::White);
	//-----Main Menu
	  //game.SetMainScreenBackground("Data/Textures/MainScreen.jpg");
	game.SetMainFont("Data/Fonts/Gtek.ttf");
	game.SetMainButtons(sf::Color::Red, sf::Color::White, 30, 4);
	//-----TutorialScreen
	game.SetTutorialScreenBackground("Data/Textures/TutorialBackground2.png");
	game.SetTutorialScreenFont("Data/Fonts/Sansation.ttf");
	game.SetTutorialScreenText("Press Enter to go back", 30, sf::Color::Red);
	//-----Game
	game.SetGameScreenBackground("Data/Textures/GameBackground_1.png", "Data/Textures/GameBackground_2.jpg", "Data/Textures/GameBackground_3.png"); 
	game.SetGameMusic("Data/Audio/Music/GameTheme_2.ogg", 1);		
	game.SetMouseCurser(false);
	game.SetCrossHair("Data/Textures/crosshair_3.png");
	//-----Finish
	game.SetFinishTexture("Data/Textures/flag.png");
	game.SetFinishLocation(118 * 32, 3 * 32);
	game.SetVictorySound("Data/Audio/Sounds/victorySound.wav", 50);
	//-----PauseScreen
	game.SetPauseScreenBackground(sf::Color(100, 100, 255, 60), 200, 400);
	game.SetPauseFont("Data/Fonts/Sansation.ttf");
	game.SetPauseButtons(sf::Color::Red, sf::Color::White, 30, 4);
	//-----VictoryScreen
	game.SetVictoryScreenBackground("Data/Textures/VictoryScreenBackground.png");
	game.SetVictoryFont("Data/Fonts/Gtek.ttf");		
	game.SetJellyFont("Data/Fonts/Sansation.ttf");	
	game.SetVictoryButtons(sf::Color::Red, sf::Color::White, 30, 2);
	game.SetVictoryText("victory", sf::Color::Red, 60);
	game.SetJellyTexture2("Data/Textures/happyjelly2.png");
	game.SetJellyText(sf::Color::White, 30);
	//-----GameOverScreen
	game.SetGameOverScreenBackground(sf::Color(255,0,0,50));
	game.SetGameOverFont("Data/Fonts/Sansation.ttf");
	game.SetGameOverButtons(sf::Color::Red, sf::Color::White, 30, 2);
	game.SetGameOverText("Game Over", sf::Color::White, 60);
	game.SetGameOverMusic("Data/Audio/Music/gameOverTheme_2.ogg", 40);
		
	game.GameLoop();

	return 0;
}