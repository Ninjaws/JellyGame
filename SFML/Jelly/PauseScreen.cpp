#include "PauseScreen.h"


PauseScreen::PauseScreen()
{
}
PauseScreen::~PauseScreen()
{
}

void PauseScreen::SetPauseScreenBackground(sf::Color color, float width, float height)
{
	sf::Vector2f screenDimensions;
	screenDimensions.x = GetWindow().getSize().x;
	screenDimensions.y = GetWindow().getSize().y; 
	//pauseScreenTexture.loadFromFile(texturelocation);
	//pauseScreenBackground.setTexture(&pauseScreenTexture);
	pauseScreenBackground.setFillColor(color);
	//pauseScreenBackground.setFillColor(sf::Color::Transparent);
	pauseScreenBackground.setSize(screenDimensions);
	//pauseScreenBackground.setPosition((GetWindow().getSize().x / 2) - (screenDimensions.x / 2), (GetWindow().getSize().y / 2) - (screenDimensions.y / 2));
	std::cout << "Pausescreen background loaded" << std::endl;
}
void PauseScreen::SetPauseFont(std::string fontlocation)
{
	pauseFont.loadFromFile(fontlocation);
}
void PauseScreen::SetPauseButtons(sf::Color selected, sf::Color other, float textsize, unsigned int numberofbuttons)
{
	selectedButton = selected;
	otherButtons = other;

	sf::Text text;

	for (int i = 0; i < numberofbuttons; i++)
	{
		pauseText.push_back(text);
		pauseText[i].setCharacterSize(textsize);
		pauseText[i].setFont(pauseFont);
		pauseText[i].setColor(otherButtons);
	}

	pauseText[0].setColor(selectedButton);

	pauseText[0].setString("Continue");
	pauseText[1].setString("Save Game");
	pauseText[2].setString("Quit to Main Menu");
	pauseText[3].setString("Quit to Desktop");

	selectedItemIndex = 0;

}

void PauseScreen::DrawPauseScreenBackground()
{
	sf::Vector2i pixel_pos = sf::Vector2i(0, 0);
	sf::Vector2f coord_pos = GetWindow().mapPixelToCoords(pixel_pos);
	pauseScreenBackground.setPosition(coord_pos);

	GetWindow().draw(pauseScreenBackground);
}
void PauseScreen::DrawPauseButtons()
{
	for (int i = 0; i < pauseText.size(); i++)
	{	
		sf::Vector2i pixel_pos = sf::Vector2i(GetScreenWidth() / 2 - GetScreenWidth() / 8, GetScreenHeight() / (pauseText.size() + 1) * i + (GetScreenHeight() / 6));
		sf::Vector2f coord_pos = GetWindow().mapPixelToCoords(pixel_pos);
		pauseText[i].setPosition(coord_pos);

		GetWindow().draw(pauseText[i]);
	}
}

void PauseScreen::MoveUp()
{
	if (selectedItemIndex - 1 >= 0)
	{
		pauseText[selectedItemIndex].setColor(otherButtons);
		selectedItemIndex--;
		pauseText[selectedItemIndex].setColor(selectedButton);
	}
}
void PauseScreen::MoveDown()
{
	if (selectedItemIndex + 1 < pauseText.size())
	{
		pauseText[selectedItemIndex].setColor(otherButtons);
		selectedItemIndex++;
		pauseText[selectedItemIndex].setColor(selectedButton);
	}
}

void PauseScreen::PauseMovementInput()
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
void PauseScreen::PauseButtonSelecting()
{
	if (sf::Keyboard::isKeyPressed(GetSelectingKey()))
	{
		if (selectedItemIndex == 0)
		{
			SetState(State_GameScreen);			
			PlayGameMusic();
			DisplayState("GameScreen");
		}
		else if (selectedItemIndex == 1)
		{
			SaveGame();
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

			SetState(State_MainScreen);
			StopGameMusic();
			
			PlayMainMusic();
			DisplayState("MainScreen");
		}
		else if (selectedItemIndex == 3)
		{
			GetWindow().close();
		}
	}
}