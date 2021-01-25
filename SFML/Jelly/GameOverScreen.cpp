#include "GameOverScreen.h"


GameOverScreen::GameOverScreen()
{
}
GameOverScreen::~GameOverScreen()
{
}

void GameOverScreen::SetGameOverScreenBackground(sf::Color color)
{
	sf::Vector2f screenDimensions;
	screenDimensions.x = GetWindow().getSize().x;
	screenDimensions.y = GetWindow().getSize().y;
	GameOverScreenBackground.setFillColor(color);
	GameOverScreenBackground.setSize(screenDimensions);
	std::cout << "GameOverscreen background loaded" << std::endl;
}
void GameOverScreen::SetGameOverFont(std::string fontlocation)
{
	gameOverFont.loadFromFile(fontlocation);
}
void GameOverScreen::SetGameOverButtons(sf::Color selected, sf::Color other, float textsize, unsigned int numberofbuttons)
{
	selectedButton = selected;
	otherButtons = other;

	sf::Text text;

	for (int i = 0; i < numberofbuttons; i++)
	{
		gameOverText.push_back(text);
		gameOverText[i].setCharacterSize(textsize);
		gameOverText[i].setFont(gameOverFont);
		gameOverText[i].setColor(otherButtons);
	}

	gameOverText[0].setColor(selectedButton);

	gameOverText[0].setString("Quit to Main Menu");
	gameOverText[1].setString("Try Again");

	selectedItemIndex = 0;
}
void GameOverScreen::SetGameOverText(std::string text, sf::Color color, float textsize)
{
	gameOver.setFont(gameOverFont);
	gameOver.setString(text);
	gameOver.setColor(color);
	gameOver.setCharacterSize(textsize);
}

void GameOverScreen::DrawGameOverScreenBackground()
{
	sf::Vector2i pixel_pos = sf::Vector2i(0, 0);
	sf::Vector2f coord_pos = GetWindow().mapPixelToCoords(pixel_pos);

	GameOverScreenBackground.setPosition(coord_pos);
	GetWindow().draw(GameOverScreenBackground);
}
void GameOverScreen::DrawGameOverButtons()
{
	for (int i = 0; i < gameOverText.size(); i++)
	{
		sf::Vector2i pixel_pos = sf::Vector2i(GetScreenWidth() / 8 + (GetScreenWidth() / 2 * i), GetScreenHeight() / 2);
		sf::Vector2f coord_pos = GetWindow().mapPixelToCoords(pixel_pos);
		gameOverText[i].setPosition(coord_pos);

		GetWindow().draw(gameOverText[i]);
	}
}
void GameOverScreen::DrawGameOverText()
{
	sf::Vector2i pixel_pos = sf::Vector2i(GetScreenWidth() / 2 - GetScreenWidth() / 4, GetScreenHeight() / 2 - GetScreenHeight() / 6);
	sf::Vector2f coord_pos = GetWindow().mapPixelToCoords(pixel_pos);
	gameOver.setPosition(coord_pos);

	GetWindow().draw(gameOver);
}

void GameOverScreen::MoveLeft()
{
	if (selectedItemIndex - 1 >= 0)
	{
		gameOverText[selectedItemIndex].setColor(otherButtons);
		selectedItemIndex--;
		gameOverText[selectedItemIndex].setColor(selectedButton);
	}
}
void GameOverScreen::MoveRight()
{
	if (selectedItemIndex + 1 < gameOverText.size())
	{
		gameOverText[selectedItemIndex].setColor(otherButtons);
		selectedItemIndex++;
		gameOverText[selectedItemIndex].setColor(selectedButton);
	}
}

void GameOverScreen::GameOverMovementInput()
{
	if (buttonTimer.getElapsedTime().asSeconds() >= GetFrameRate() * 6)
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) || sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		{
			MoveLeft();
			buttonTimer.restart();
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) || sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		{
			MoveRight();
			buttonTimer.restart();
		}

	}
}
void GameOverScreen::GameOverButtonSelecting()
{
	if (sf::Keyboard::isKeyPressed(GetSelectingKey()))
	{
		if (selectedItemIndex == 0)
		{
			switchTimer.restart();
			while (true)
			{
				if (switchTimer.getElapsedTime().asSeconds() >= GetStateSwitchingRate())
				{					
					break;
				}
			}

			SetState(State_MainScreen);
			StopGameOverMusic();

			PlayMainMusic();
			DisplayState("MainScreen");

		}
		else if (selectedItemIndex == 1)
		{
			SetState(State_GameScreen);
			StopGameOverMusic();

			LoadItems();

			PlayGameMusic();
			DisplayState("GameScreen");
		}
	}
}