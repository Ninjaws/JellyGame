#include "Collectables.h"


Collectables::Collectables()
{
}
Collectables::~Collectables()
{
}


//--- Crates
void Collectables::DrawCrates()
{
	for (int i = 0; i < crateSprite.size(); i++)
	{
		if (!crateDestroyed[i])
		{
			GetWindow().draw(crateSprite[i]);
		}
	}
}
void Collectables::RestartCrates()
{
	crateSprite.clear();
	crateDestroyed.clear();
}
void Collectables::CrateCollision()
{
	SetCrateTopCollision(false);
	for (int i = 0; i < crateSprite.size(); i++)
	{		
		if (!crateDestroyed[i])
		{
			
			if (GetPlayerImage().getPosition().y <= crateSprite[i].getPosition().y + crateTexture.getSize().y &&					// Top of player is higher than bottom of crate
				crateSprite[i].getPosition().y <= GetPlayerImage().getPosition().y + GetPlayerSize().y)								// Top of crate is higher than bottom of player
			{
				if (GetPlayerImage().getPosition().x + GetPlayerImage().getTextureRect().width == crateSprite[i].getPosition().x)	// Left side of crate
				{
					GetPlayerImage().move(sf::Vector2f(-GetMoveSpeed(), 0));
				}

				if (crateSprite[i].getPosition().x + crateTexture.getSize().x == GetPlayerImage().getPosition().x)					// Right side of crate
				{
					GetPlayerImage().move(sf::Vector2f(GetMoveSpeed(), 0));
				}

				if (GetPlayerImage().getPosition().x + GetPlayerImage().getTextureRect().width >= crateSprite[i].getPosition().x &&		//Player is on top of the crate
					crateSprite[i].getPosition().x + crateTexture.getSize().x >= GetPlayerImage().getPosition().x)
				{
					SetCrateTopCollision(true);
				}

			}
		}			
	}
}

void Collectables::SetCrateTexture(std::string texturelocation)
{
	crateTexture.loadFromFile(texturelocation);
}
void Collectables::SetCrateLocation()
{
	sf::Vector2f location;
	for (int i = 0; i < numberOfCrates; i++)
	{
		crateLocation.push_back(location);
	}
	crateLocation[0].x = 38 * GetTileSize();
	crateLocation[0].y = 9 * GetTileSize();

	crateLocation[1].x = 41 * GetTileSize();
	crateLocation[1].y = 5 * GetTileSize();

	crateLocation[2].x = 68 * GetTileSize();
	crateLocation[2].y = 4 * GetTileSize();
}
void Collectables::SetCratePosition()
{
	for (int i = 0; i < numberOfCrates; i++)
	{
		crateSprite[i].setPosition(crateLocation[i].x, crateLocation[i].y);
	}
}
void Collectables::SetAmountOfCrates(unsigned int amountofcrates)
{
	numberOfCrates = amountofcrates;
}
void Collectables::SetCrateDestroyed(int i)
{
	crateDestroyed[i] = true;
	numberOfDestroyedCrates += 1;
}

std::vector<bool> Collectables::GetCrateDestroyed() const
{
	return crateDestroyed;
}

void Collectables::CreateCrates()
{
	sf::Sprite sprite;
	for (int i = 0; i < numberOfCrates; i++)
	{
		crateSprite.push_back(sprite);
		crateSprite[i].setTexture(crateTexture);

		crateDestroyed.push_back(false);
		numberOfDestroyedCrates = 0;
	}
}

std::vector<sf::Sprite>& Collectables::GetCrateSprite()
{
	return crateSprite;
}


//--- Jellies
void Collectables::DrawJellies()
{
	for (int i = 0; i < jellySprite.size(); i++)
	{
		GetWindow().draw(jellySprite[i]);
	}
}
void Collectables::RestartJellies()
{
	jellySprite.clear();

	velocity.clear();
	collision.clear();
}
void Collectables::JellyMovement()
{
	for (int i = 0; i < jellySprite.size(); i++)
	{
		if (crateDestroyed[i] == true)
		{

			if (jellySprite[i].getPosition().y >= crateLocation[i].y)
			{
				collision[i] = true;
			}

			if (collision[i])
			{
				velocity[i].y = -GetJumpSpeed();
				collision[i] = false;
			}
			else if (!collision[i])
			{
				velocity[i].y += GetGravity();
			}



			jellySprite[i].move(velocity[i]);

		}
	}
}

unsigned int Collectables::GetAmountOfJelliesRescued() const
{
	return numberOfDestroyedCrates;
}
unsigned int Collectables::GetNumberOfCrates() const
{
	return numberOfCrates;
}
sf::Texture Collectables::GetJellyTexture() const
{
	return jellyTexture;
}

void Collectables::SetJellyTexture(std::string texturelocation)
{
	jellyTexture.loadFromFile(texturelocation);
}
void Collectables::SetJellyPosition()
{
	for (int i = 0; i < numberOfCrates; i++)
	{
		jellySprite[i].setPosition(crateLocation[i].x, crateLocation[i].y);
	}
}

void Collectables::CreateJellies()
{
	sf::Sprite sprite;

	sf::Vector2f veloc;

	for (int i = 0; i < numberOfCrates; i++)
	{
		jellySprite.push_back(sprite);
		jellySprite[i].setTexture(jellyTexture);

		velocity.push_back(veloc);
		collision.push_back(false);
	}
}


//--- Display
void Collectables::DisplayJelliesFreed()
{
	sf::Vector2i pixel_pos = jellyDisplayLocation;
	sf::Vector2f coord_pos = GetWindow().mapPixelToCoords(pixel_pos);
	jelliesFreedSprite.setPosition(coord_pos);
	jelliesFreed.setPosition(jelliesFreedSprite.getPosition().x + jelliesFreedTexture.getSize().x * 1.5, coord_pos.y);

	std::stringstream stream;
	stream.clear();
	stream << numberOfDestroyedCrates;
	stream << "/";
	stream << numberOfCrates;
	jelliesFreed.setString(stream.str());

	GetWindow().draw(jelliesFreed);
	GetWindow().draw(jelliesFreedSprite);
}

void Collectables::SetJelliesFreedDisplay(std::string texturelocation, sf::Vector2i position, sf::Color color, std::string fontLocation, float textsize)
{
	jelliesFreedTexture.loadFromFile(texturelocation);
	jelliesFreedSprite.setTexture(jelliesFreedTexture);
	
	jellyDisplayLocation = position;

	jelliesFreedFont.loadFromFile(fontLocation);
	jelliesFreed.setColor(color);
	jelliesFreed.setCharacterSize(textsize);
	jelliesFreed.setFont(jelliesFreedFont);
}
