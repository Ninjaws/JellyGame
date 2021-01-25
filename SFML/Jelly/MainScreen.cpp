#include "MainScreen.h"


MainScreen::MainScreen()
{
}
MainScreen::~MainScreen()
{
}

void MainScreen::SetMainScreenBackground(std::string texturelocation)
{
	sf::Vector2f screenDimensions;
	screenDimensions.x = GetWindow().getSize().x;
	screenDimensions.y = GetWindow().getSize().y;
	mainScreenTexture.loadFromFile(texturelocation);
	mainScreenBackground.setTexture(&mainScreenTexture);
	mainScreenBackground.setSize(screenDimensions);
	std::cout << "Mainscreen background loaded" << std::endl;
}
void MainScreen::SetMainFont(std::string fontlocation)
{
	mainFont.loadFromFile(fontlocation);
}
void MainScreen::SetMainButtons(sf::Color selected, sf::Color other, float textsize, unsigned int numberofbuttons)
{
	selectedButton = selected;
	otherButtons = other;

	sf::Text text;

	for (int i = 0; i < numberofbuttons; i++)
	{
		mainText.push_back(text);
		mainText[i].setCharacterSize(textsize);
		mainText[i].setFont(mainFont);
		mainText[i].setColor(otherButtons);
	}

	mainText[0].setColor(selectedButton);

	mainText[0].setString("new game");		//"New Game"
	mainText[1].setString("load game");		//"Load Game"
	mainText[2].setString("tutorial");		//"Tutorial"
	mainText[3].setString("quit");			//"Quit"

	selectedItemIndex = 0;
}

void MainScreen::DrawMainScreenBackground()
{
	sf::Vector2i pixel_pos = sf::Vector2i(0, 0);
	sf::Vector2f coord_pos = GetWindow().mapPixelToCoords(pixel_pos);
	mainScreenBackground.setPosition(coord_pos);

	GetWindow().draw(mainScreenBackground);
}
void MainScreen::DrawMainButtons()
{	
	for (int i = 0; i < mainText.size(); i++)
	{
		sf::Vector2i pixel_pos = sf::Vector2i(GetScreenWidth() / 2 - GetScreenWidth() / 8, GetScreenHeight() / (mainText.size() + 1) * i + (GetScreenHeight() / 10));
		sf::Vector2f coord_pos = GetWindow().mapPixelToCoords(pixel_pos);
		mainText[i].setPosition(coord_pos);

		GetWindow().draw(mainText[i]);
	}
}

void MainScreen::MoveUp()
{
	if (selectedItemIndex - 1 >= 0)
	{
		mainText[selectedItemIndex].setColor(otherButtons);
		selectedItemIndex--;
		mainText[selectedItemIndex].setColor(selectedButton);
	}
}
void MainScreen::MoveDown()
{
	if (selectedItemIndex + 1 < mainText.size())
	{
		mainText[selectedItemIndex].setColor(otherButtons);
		selectedItemIndex++;
		mainText[selectedItemIndex].setColor(selectedButton);
	}
}

void MainScreen::MainMovementInput()
{
	if (buttonTimer.getElapsedTime().asSeconds() >= GetFrameRate() * 6)
	{		
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) || sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
		{
			MoveUp();
			buttonTimer.restart();
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) || sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
		{
			MoveDown();
			buttonTimer.restart();
		}		
	}
}
void MainScreen::MainButtonSelecting()
{
	if (sf::Keyboard::isKeyPressed(GetSelectingKey()))
	{
		if (selectedItemIndex == 0)
		{
			SetState(State_GameScreen);	
			StopMainMusic();
			
			LoadItems();

			PlayGameMusic();
			DisplayState("GameScreen");
		}

		else if (selectedItemIndex == 1)
		{	
			SetState(State_GameScreen);
			StopMainMusic();

			LoadItems();
			LoadGame();

			PlayGameMusic();
			DisplayState("GameScreen");
		}

		else if (selectedItemIndex == 2)
		{
			switchTimer.restart();
			while (true)
			{
				if (switchTimer.getElapsedTime().asSeconds() >= GetStateSwitchingRate())
				{
					break;
				}
			}

			SetState(State_TutorialScreen);			

			DisplayState("TutorialScreen");
		}

		else if (selectedItemIndex == 3)
		{
			GetWindow().close();
		}
	}
}