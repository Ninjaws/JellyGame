#include "TutorialScreen.h"


TutorialScreen::TutorialScreen()
{
}
TutorialScreen::~TutorialScreen()
{
}

void TutorialScreen::DrawTutorialText()
{
	sf::Vector2i pixel_pos = sf::Vector2i(GetWindow().getSize().x / 3, GetWindow().getSize().y / 1.2);
	sf::Vector2f coord_pos = GetWindow().mapPixelToCoords(pixel_pos);
	tutorialText.setPosition(coord_pos);

	GetWindow().draw(tutorialText);
}
void TutorialScreen::TutorialScreenInput()
{
	if (sf::Keyboard::isKeyPressed(GetSelectingKey()))
	{
		stateSwitchTimer.restart();
		while (true)
		{
			if (stateSwitchTimer.getElapsedTime().asSeconds() >= GetStateSwitchingRate())
			{
				break;
			}
		}

		SetState(State_MainScreen);
		DisplayState("MainScreen");
	}
}
void TutorialScreen::DrawTutorialBackground()
{
	sf::Vector2i pixel_pos = sf::Vector2i(0, 0);
	sf::Vector2f coord_pos = GetWindow().mapPixelToCoords(pixel_pos);
	tutorialScreenBackground.setPosition(coord_pos);

	GetWindow().draw(tutorialScreenBackground);
}

void TutorialScreen::SetTutorialScreenFont(std::string fontlocation)
{
	tutorialFont.loadFromFile(fontlocation);
}
void TutorialScreen::SetTutorialScreenText(std::string tutorialtext, float textsize, sf::Color color)
{
	tutorialText.setFont(tutorialFont);
	tutorialText.setPosition(GetWindow().getSize().x / 3, GetWindow().getSize().y / 1.2);
	tutorialText.setCharacterSize(textsize);
	tutorialText.setColor(color);
	tutorialText.setString(tutorialtext);
}

void TutorialScreen::SetTutorialScreenBackground(std::string texturelocation)
{
	sf::Vector2f screenDimensions;
	screenDimensions.x = GetWindow().getSize().x;
	screenDimensions.y = GetWindow().getSize().y;
	tutorialScreenTexture.loadFromFile(texturelocation);
	tutorialScreenBackground.setTexture(&tutorialScreenTexture);
	tutorialScreenBackground.setSize(screenDimensions);
	std::cout << "Tutorialscreen background loaded" << std::endl;
}

