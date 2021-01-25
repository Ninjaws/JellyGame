#include "TitleScreen.h"


TitleScreen::TitleScreen()
{
}
TitleScreen::~TitleScreen()
{
}

void TitleScreen::DrawTitleText()
{
	GetWindow().draw(titleText);
}
void TitleScreen::DrawUnderTitleText()
{
	GetWindow().draw(underTitleText);
}
void TitleScreen::DrawNameText()
{
	GetWindow().draw(nameText);
}
void TitleScreen::TitleScreenInput()
{
	if (sf::Keyboard::isKeyPressed(GetSelectingKey()))
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
		DisplayState("MainScreen");
	}
}
void TitleScreen::DrawTitleScreenBackground()
{
	GetWindow().draw(titleScreenBackground);
}

void TitleScreen::SetTitleFont(std::string fontlocation)
{
	titleFont.loadFromFile(fontlocation);
}
void TitleScreen::SetTitleText(std::string titletext, float textsize, sf::Color color)
{
	titleText.setFont(titleFont);
	titleText.setPosition(GetWindow().getSize().x / 7, GetWindow().getSize().y / 3);
	titleText.setCharacterSize(textsize);
	titleText.setColor(color);
	titleText.setString(titletext);
}
void TitleScreen::SetUnderTitleFont(std::string fontlocation)
{
	underTitleFont.loadFromFile(fontlocation);
}
void TitleScreen::SetUnderTitleText(float textsize, sf::Color color)
{
	underTitleText.setFont(underTitleFont);
	underTitleText.setPosition(GetWindow().getSize().x / 4, GetWindow().getSize().y / 3 * 2);
	underTitleText.setCharacterSize(textsize);
	underTitleText.setColor(color);
	underTitleText.setString("Press Enter to continue");
}
void TitleScreen::SetNameText(float textsize, sf::Color color)
{
	nameText.setFont(underTitleFont);
	nameText.setPosition(GetWindow().getSize().x / 1.5, GetWindow().getSize().y / 8);
	nameText.setCharacterSize(textsize);
	nameText.setColor(color);
	nameText.setString("Made by Ian Vink");
}
void TitleScreen::SetTitleScreenBackground(std::string texturelocation)
{
	sf::Vector2f screenDimensions;
	screenDimensions.x = GetWindow().getSize().x;
	screenDimensions.y = GetWindow().getSize().y;
	titleScreenTexture.loadFromFile(texturelocation);
	titleScreenBackground.setTexture(&titleScreenTexture);
	titleScreenBackground.setSize(screenDimensions);
	std::cout << "Titlescreen background loaded" << std::endl;
}

