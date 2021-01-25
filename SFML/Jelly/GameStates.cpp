#include "GameStates.h"


GameStates::GameStates()
{
}
GameStates::~GameStates()
{
}


void GameStates::UpdateTitleState()
{
	TitleScreenInput();
}
void GameStates::DrawTitleState()
{
	GetWindow().clear();

	//DrawTitleScreenBackground();
	DrawUnderTitleText();
	DrawTitleText();
	DrawNameText();

	GetWindow().display();
}

void GameStates::UpdateMainState()
{
	MainMovementInput();
	MainButtonSelecting();
}
void GameStates::DrawMainState()
{
	GetWindow().clear();

	//DrawMainScreenBackground();
	DrawMainButtons();

	GetWindow().display();
}

void GameStates::UpdateTutorialState()
{
	TutorialScreenInput();
}
void GameStates::DrawTutorialState()
{
	GetWindow().clear();

	DrawTutorialBackground();
	DrawTutorialText();

	GetWindow().display();
}

void GameStates::UpdatePlayingState()
{
	UpdateMousePosition();
	UpdateWindowPosition();

	PlayerDetection();	
	EnemyAttack();	
	CrateCollision();
	JellyMovement();
	Movement();		
	Firing();
	PickUpHealth();
	PickUpAmmo();
	PickUpPowerUp();
	FinishReached();
	EnemyDestroyed();
	GameScreenInput();
	RotateGun();
	PlayerOutOfBounds();
		
}
void GameStates::DrawPlayingState()
{
	GetWindow().clear();

	ScreenScrolling();
	DrawGameScreenBackground();
	EnemyBulletCollision();
	PlayerBulletCollision();
	EnemyBullets();
	Bullet();
	DrawMap();
	
	DrawHealthPacks();
	DrawAmmoPacks();
	DrawPowerUps();
	DrawFinish();
	PowerUpAnimation();
	DrawJellies();
	DrawCrates();
	DrawEnemyGun();
	DrawGun();
	DrawEnemy();
	DrawPlayer();
	DrawHealthBar();
	DisplayJelliesFreed();
	DisplayHealth();
	DisplayAmmo();
	DrawCrossHair();
		
	//GetWindow().display();
}

void GameStates::UpdatePauseState()
{
	PauseMovementInput();
	PauseButtonSelecting();
}
void GameStates::DrawPauseState()
{
	DrawPauseScreenBackground();
	DrawPauseButtons();

	GetWindow().display();
}

void GameStates::UpdateGameOverState()
{
	GameOverMovementInput();
	GameOverButtonSelecting();
}
void GameStates::DrawGameOverState()
{
	DrawGameOverScreenBackground();
	DrawGameOverButtons();
	DrawGameOverText();

	GetWindow().display();
}
void GameStates::UpdateVictoryState()
{
	VictoryMovementInput();
	VictoryButtonSelecting();
}
void GameStates::DrawVictoryState()
{
	GetWindow().clear();

	DrawVictoryScreenBackground();
	DrawVictoryButtons();
	DrawVictoryText();
	DrawRescuedJellies();
	DrawRescuedJelliesText();

	GetWindow().display();
}

void GameStates::GameLoop()
{
	LoadMap();
	LoadColMap();

	SetState(State_TitleScreen);
	DisplayState("TitleScreen");

	PlayMainMusic();

	while (GetWindow().isOpen())
	{		
		sf::Event Event;
		while (GetWindow().pollEvent(Event))
		{

			switch (Event.type)
			{
			case sf::Event::Closed:
				GetWindow().close();
				break;
			case sf::Event::KeyPressed:
				if (Event.key.code == sf::Keyboard::L && GetTestMode() == true)
				{
					LoadMap();
					LoadColMap();
					break;
				}								
			}		
		}

		if (frameRateTimer.getElapsedTime().asSeconds() >= GetFrameRate())
		{
			switch (GetState())
			{
			case State_TitleScreen:
			{
				UpdateTitleState();
				DrawTitleState();
				break;
			}
			case State_MainScreen:
			{
				UpdateMainState();
				DrawMainState();
				break;
			}
			case State_TutorialScreen:
			{
				UpdateTutorialState();
				DrawTutorialState();
				break;
			}
			case State_GameScreen:
			{
				UpdatePlayingState();
				DrawPlayingState();
				GetWindow().display();
				break;
			}
			case State_PauseScreen:
			{
				DrawPlayingState();
				UpdatePauseState();
				DrawPauseState();
				break;
			}
			case State_GameOverScreen:
			{
				DrawPlayingState();
				UpdateGameOverState();
				DrawGameOverState();
				break;
			}
			case State_VictoryScreen:
			{
				UpdateVictoryState();
				DrawVictoryState();
			}


			}
			frameRateTimer.restart();
		}
	}
}