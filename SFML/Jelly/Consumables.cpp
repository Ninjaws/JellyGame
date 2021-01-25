#include "Consumables.h"


Consumables::Consumables()
{
}
Consumables::~Consumables()
{
}

//--- Health
void Consumables::DrawHealthPacks()
{
	for (int i = 0; i < healthSprite.size(); i++)
	{
		if (healthTaken[i] == false)
		{

			GetWindow().draw(healthSprite[i]);

		}
	}
}
void Consumables::PickUpHealth()
{
	if (GetPlayerHealth() < GetPlayerMaxHealth())
	{
		for (int i = 0; i < healthSprite.size(); i++)
		{
			if (healthTaken[i] == false)
			{

				if (GetPlayerImage().getPosition().x + GetPlayerImage().getTextureRect().width >= healthSprite[i].getPosition().x && healthSprite[i].getPosition().x + healthTexture.getSize().x >= GetPlayerImage().getPosition().x &&
					GetPlayerImage().getPosition().y + GetPlayerSize().y >= healthSprite[i].getPosition().y && GetPlayerImage().getPosition().y <= healthSprite[i].getPosition().y + healthTexture.getSize().y)
				{
					PlayerHealed(amountHealed);
					healthTaken[i] = true;
				}

			}
		}
	}
}
void Consumables::RestartHealthPacks()
{
	healthSprite.clear();
	healthTaken.clear();
}

void Consumables::SetHealthPackTexture(std::string texturelocation)
{
	healthTexture.loadFromFile(texturelocation);
}
void Consumables::SetHealthPackLocation()
{
	sf::Vector2f location;
	for (int i = 0; i < numberOfHealthPacks; i++)
	{
		healthLocation.push_back(location);
	}
	healthLocation[0].x = 28 * GetTileSize();
	healthLocation[0].y = 10 * GetTileSize();

	healthLocation[1].x = 64 * GetTileSize();
	healthLocation[1].y = 6 * GetTileSize();

	healthLocation[2].x = 118 * GetTileSize();
	healthLocation[2].y = 11 * GetTileSize();

	healthLocation[3].x = 74 * GetTileSize();
	healthLocation[3].y = 8 * GetTileSize();
}
void Consumables::SetHealthPackPosition()
{
	for (int i = 0; i < numberOfHealthPacks; i++)	
	{
		healthSprite[i].setPosition(healthLocation[i].x, healthLocation[i].y);
	}
}
void Consumables::SetAmountOfHealthPacks(unsigned int amountofhealthpacks)
{
	numberOfHealthPacks = amountofhealthpacks;
}
void Consumables::SetAmountHealed(unsigned int amounthealed)
{
	amountHealed = amounthealed;
}
void Consumables::SetHealthTaken(int i, bool healthtaken)
{
	healthTaken[i] = healthtaken;
}

std::vector<bool> Consumables::GetHealthTaken() const
{
	return healthTaken;
}

void Consumables::CreateHealthPacks()
{
	sf::Sprite sprite;
	for (int i = 0; i < numberOfHealthPacks; i++)
	{
		healthSprite.push_back(sprite);
		healthSprite[i].setTexture(healthTexture);

		healthTaken.push_back(false);
	}
}


//--- Ammo
void Consumables::DrawAmmoPacks()
{
	for (int i = 0; i < ammoSprite.size(); i++)
	{
		if (ammoTaken[i] == false)
		{
			GetWindow().draw(ammoSprite[i]);
		}
	}
}
void Consumables::PickUpAmmo()
{
	if (GetPlayerAmmo() < GetMaxAmmo())
	{
		for (int i = 0; i < ammoSprite.size(); i++)
		{
			if (ammoTaken[i] == false)
			{

				if (GetPlayerImage().getPosition().x + GetPlayerImage().getTextureRect().width >= ammoSprite[i].getPosition().x && ammoSprite[i].getPosition().x + ammoTexture.getSize().x >= GetPlayerImage().getPosition().x &&
					GetPlayerImage().getPosition().y + GetPlayerSize().y >= ammoSprite[i].getPosition().y && GetPlayerImage().getPosition().y <= ammoSprite[i].getPosition().y + ammoTexture.getSize().y)
				{
					Reloading();
					ammoTaken[i] = true;
				}

			}
		}
	}
}
void Consumables::RestartAmmoPacks()
{
	ammoSprite.clear();
	ammoTaken.clear();
}

void Consumables::SetAmmoPackTexture(std::string texturelocation)
{
	ammoTexture.loadFromFile(texturelocation);
}
void Consumables::SetAmmoPackLocation()
{
	sf::Vector2f location;
	for (int i = 0; i < numberOfAmmoPacks; i++)
	{
		ammoLocation.push_back(location);
	}
	ammoLocation[0].x = 32 * GetTileSize();
	ammoLocation[0].y = 9 * GetTileSize();

	ammoLocation[1].x = 48 * GetTileSize();
	ammoLocation[1].y = 5 * GetTileSize();
	
	ammoLocation[2].x = 88 * GetTileSize();
	ammoLocation[2].y = 9 * GetTileSize();

	ammoLocation[3].x = 105 * GetTileSize();
	ammoLocation[3].y = 15 * GetTileSize();
}
void Consumables::SetAmmoPackPosition()
{
	for (int i = 0; i < numberOfAmmoPacks; i++)	
	{
		ammoSprite[i].setPosition(ammoLocation[i].x, ammoLocation[i].y);
	}
}
void Consumables::SetAmountOfAmmoPacks(unsigned int amountofammopacks)
{
	numberOfAmmoPacks = amountofammopacks;
}
void Consumables::SetAmmoTaken(int i, bool ammotaken)
{
	ammoTaken[i] = ammotaken;
}

std::vector<bool> Consumables::GetAmmoTaken() const
{
	return ammoTaken;
}

void Consumables::CreateAmmoPacks()
{
	sf::Sprite sprite;
	for (int i = 0; i < numberOfAmmoPacks; i++)
	{
		ammoSprite.push_back(sprite);
		ammoSprite[i].setTexture(ammoTexture);

		ammoTaken.push_back(false);
	}
}


//--- PowerUp
void Consumables::DrawPowerUps()
{
	for (int i = 0; i < powerUpSprite.size(); i++)
	{
		if (poweredUp == false)
		{
			powerUpSprite[i].setTextureRect(sf::IntRect(spriteAnimation[i].x * (powerUpTexture.getSize().x / 8) + powerUpMargin.x, powerUpMargin.y, powerUpSize.x, powerUpSize.y));
			GetWindow().draw(powerUpSprite[i]);
		}
	}
}
void Consumables::PickUpPowerUp()
{	
	for (int i = 0; i < powerUpSprite.size(); i++)
		{
			if (poweredUp == false)
			{
				if (GetPlayerImage().getPosition().x + GetPlayerImage().getTextureRect().width >= powerUpSprite[i].getPosition().x && powerUpSprite[i].getPosition().x + GetTileSize() >= GetPlayerImage().getPosition().x &&
					GetPlayerImage().getPosition().y + GetPlayerSize().y >= powerUpSprite[i].getPosition().y && GetPlayerImage().getPosition().y <= powerUpSprite[i].getPosition().y + GetTileSize())
				{
					PlayPowerUpSound();
					GetPlayerImage().setColor(sf::Color::Red);
					SetJumpSpeed(GetPoweredUpJumpSpeed());
					poweredUp = true;
				}
			}
		}	
}
void Consumables::RestartPowerUps()
{
	SetJumpSpeed(GetNormalJumpSpeed());
	GetPlayerImage().setColor(sf::Color::White);
	powerUpSprite.clear();

	spriteAnimation.clear();
	animationRateTimer.clear();
}
void Consumables::PowerUpAnimation()
{
	
	for (int i = 0; i < powerUpSprite.size(); i++)
	{
		if (poweredUp == false)
		{
			if (animationRateTimer[i].getElapsedTime().asSeconds() >= GetAnimationRate() / 2)
			{
				spriteAnimation[i].x += 1;
				animationRateTimer[i].restart();
			}
			if (spriteAnimation[i].x * 81 + 18 + powerUpSize.x >= powerUpTexture.getSize().x)
				spriteAnimation[i].x = 0;
		}
	}
}

void Consumables::SetPowerUpSize(float width, float height)
{
	powerUpSize.x = width;
	powerUpSize.y = height;
}
void Consumables::SetPowerUpMargin(float marginX, float marginY)
{
	powerUpMargin.x = marginX;
	powerUpMargin.y = marginY;
}
void Consumables::SetPowerUpTexture(std::string texturelocation)
{
	powerUpTexture.loadFromFile(texturelocation);
}
void Consumables::SetPowerUpLocation()
{
	sf::Vector2f location;
	for (int i = 0; i < numberOfPowerUps; i++)
	{
		powerUpLocation.push_back(location);
	}
	powerUpLocation[0].x = 41 * GetTileSize();
	powerUpLocation[0].y = 10 * GetTileSize();	
}
void Consumables::SetPowerUpPosition()
{
	for (int i = 0; i < numberOfPowerUps; i++)
	{
		powerUpSprite[i].setPosition(powerUpLocation[i].x, powerUpLocation[i].y - powerUpMargin.y);
	}
}
void Consumables::SetAmountOfPowerUps(unsigned int amountofpowerups)
{
	numberOfPowerUps = amountofpowerups;
}
void Consumables::SetPoweredUp(bool poweredup)
{
	poweredUp = poweredup;
	if (poweredUp == true)
	{
		GetPlayerImage().setColor(sf::Color::Red);
		SetJumpSpeed(GetPoweredUpJumpSpeed());
	}
}

bool Consumables::GetPoweredUp() const
{
	return poweredUp;
}

void Consumables::CreatePowerUps()
{
	sf::Sprite sprite;

	sf::Clock clock;

	for (int i = 0; i < numberOfPowerUps; i++)
	{
		powerUpSprite.push_back(sprite);
		powerUpSprite[i].setTexture(powerUpTexture);

		powerUpSprite[i].setScale(GetTileSize() / powerUpSize.x, GetTileSize() / powerUpSize.y);
		spriteAnimation.push_back(sf::Vector2i(0, 0));
		animationRateTimer.push_back(clock);
	}
}