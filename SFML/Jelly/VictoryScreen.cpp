#include "VictoryScreen.h"


VictoryScreen::VictoryScreen()
{
}
VictoryScreen::~VictoryScreen()
{
}

//--- Finish Flag
void VictoryScreen::DrawFinish()
{
	GetWindow().draw(finishSprite);
}
void VictoryScreen::FinishReached()
{
	
	if (GetPlayerImage().getPosition().y <= finishSprite.getPosition().y + GetTileSize() &&										// Top of player is higher than bottom of crate
		finishSprite.getPosition().y <= GetPlayerImage().getPosition().y + GetPlayerSize().y)									// Top of crate is higher than bottom of player
	{
		if (GetPlayerImage().getPosition().x + GetPlayerImage().getTextureRect().width >= finishSprite.getPosition().x &&		// Right of player is larger than left of flag
			finishSprite.getPosition().x + GetTileSize() >= GetPlayerImage().getPosition().x)									// Right of flag is larger than left of player
		{
			SetState(State_VictoryScreen);
			StopGameMusic();

			PlayVictorySound();
			DisplayState("VictoryScreen");
		}

	}	
	
}

void VictoryScreen::SetFinishTexture(std::string texturelocation)
{
	finishTexture.loadFromFile(texturelocation);
	finishSprite.setTexture(finishTexture);
	finishSprite.setScale(GetTileSize() / finishTexture.getSize().x, GetTileSize() / finishTexture.getSize().y);
}
void VictoryScreen::SetFinishLocation(float width, float height)
{
	finishSprite.setPosition(width, height);
}

//--- Victory Screen
void VictoryScreen::SetVictoryScreenBackground(std::string texturelocation)
{
	sf::Vector2f screenDimensions;
	screenDimensions.x = GetWindow().getSize().x;
	screenDimensions.y = GetWindow().getSize().y;
	victoryScreenTexture.loadFromFile(texturelocation);
	victoryScreenBackground.setTexture(&victoryScreenTexture);

	victoryScreenBackground.setTextureRect(sf::IntRect(0, 0, GetScreenWidth(), GetScreenHeight()));
	victoryScreenBackground.setSize(screenDimensions);

	std::cout << "Victoryscreen background loaded" << std::endl;
}
void VictoryScreen::SetVictoryFont(std::string fontlocation)
{
	victoryFont.loadFromFile(fontlocation);
}
void VictoryScreen::SetJellyFont(std::string fontlocation)
{
	jellyFont.loadFromFile(fontlocation);
}
void VictoryScreen::SetVictoryButtons(sf::Color selected, sf::Color other, float textsize, unsigned int numberofbuttons)
{
	selectedButton = selected;
	otherButtons = other;

	sf::Text text;

	for (int i = 0; i < numberofbuttons; i++)
	{
		victoryText.push_back(text);
		victoryText[i].setCharacterSize(textsize);
		victoryText[i].setFont(jellyFont);
		victoryText[i].setColor(otherButtons);
	}

	victoryText[0].setColor(selectedButton);

	victoryText[0].setString("Return to Main menu");
	victoryText[1].setString("Play Again");

	selectedItemIndex = 0;
}
void VictoryScreen::SetVictoryText(std::string text, sf::Color color, unsigned int textsize)
{
	victory.setFont(victoryFont);
	victory.setString(text);
	victory.setColor(color);
	victory.setCharacterSize(textsize);
}
void VictoryScreen::SetJellyText(sf::Color color, unsigned int textsize)
{
	jellyText.setFont(jellyFont);	
	jellyText.setColor(color);
	jellyText.setCharacterSize(textsize);
}
void VictoryScreen::SetJellyTexture2(std::string texturelocation)
{
	sf::Sprite sprite;

	jellyTexture.loadFromFile(texturelocation);
	for (int i = 0; i < GetNumberOfCrates(); i++)
	{
		jellySprite.push_back(sprite);
		jellySprite[i].setTexture(jellyTexture);
	}
}

void VictoryScreen::DrawVictoryScreenBackground()
{
	sf::Vector2i pixel_pos = sf::Vector2i(0, 0);
	sf::Vector2f coord_pos = GetWindow().mapPixelToCoords(pixel_pos);
	victoryScreenBackground.setPosition(coord_pos);

	GetWindow().draw(victoryScreenBackground);
}
void VictoryScreen::DrawVictoryButtons()
{
	for (int i = 0; i < victoryText.size(); i++)
	{
		sf::Vector2i pixel_pos = sf::Vector2i(GetScreenWidth() / 8 + (GetScreenWidth() / 2 * i), GetScreenHeight() / 1.2);
		sf::Vector2f coord_pos = GetWindow().mapPixelToCoords(pixel_pos);
		victoryText[i].setPosition(coord_pos);

		GetWindow().draw(victoryText[i]);
	}
}
void VictoryScreen::DrawVictoryText()
{	
	if (GetAmountOfJelliesRescued() == GetNumberOfCrates())
	{
		sf::Vector2i pixel_pos = sf::Vector2i(GetScreenWidth() / 4, GetScreenHeight() / 2 - GetScreenHeight() / 6);
		sf::Vector2f coord_pos = GetWindow().mapPixelToCoords(pixel_pos);
		victory.setPosition(coord_pos);

		GetWindow().draw(victory);
	}
}
void VictoryScreen::DrawRescuedJellies()
{	
	for (int i = 0; i < GetAmountOfJelliesRescued(); i++)
	{
		sf::Vector2i pixel_pos = sf::Vector2i(GetScreenWidth() / 5 + i * GetScreenWidth() / 4, GetScreenHeight() / 2);
		sf::Vector2f coord_pos = GetWindow().mapPixelToCoords(pixel_pos);
		jellySprite[i].setPosition(coord_pos);

		GetWindow().draw(jellySprite[i]);
	}
}
void VictoryScreen::DrawRescuedJelliesText()
{
	sf::Vector2i pixel_pos = sf::Vector2i(GetScreenWidth() / 7, GetScreenHeight() / 1.7);
	sf::Vector2f coord_pos = GetWindow().mapPixelToCoords(pixel_pos);
	jellyText.setPosition(coord_pos);

	std::stringstream stream;
	stream.clear();
	
	stream << "You have rescued ";
	if (GetAmountOfJelliesRescued() == GetNumberOfCrates())
	{
		stream << "all of the jellies!";
	}
	else
	{
		stream << GetAmountOfJelliesRescued();
		stream << " of the ";
		stream << GetNumberOfCrates();
		stream << " jellies";
	}	
	jellyText.setString(stream.str());

	GetWindow().draw(jellyText);
}

void VictoryScreen::MoveLeft()
{
	if (selectedItemIndex - 1 >= 0)
	{
		victoryText[selectedItemIndex].setColor(otherButtons);
		selectedItemIndex--;
		victoryText[selectedItemIndex].setColor(selectedButton);
	}
}
void VictoryScreen::MoveRight()
{
	if (selectedItemIndex + 1 < victoryText.size())
	{
		victoryText[selectedItemIndex].setColor(otherButtons);
		selectedItemIndex++;
		victoryText[selectedItemIndex].setColor(selectedButton);
	}
}

void VictoryScreen::VictoryMovementInput()
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
void VictoryScreen::VictoryButtonSelecting()
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
			StopVictorySound();

			PlayMainMusic();
			DisplayState("MainScreen");

		}
		else if (selectedItemIndex == 1)
		{
			SetState(State_GameScreen);
			StopVictorySound();

			LoadItems();

			PlayGameMusic();
			DisplayState("GameScreen");
		}
	}
}
