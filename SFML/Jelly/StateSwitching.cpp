#include "StateSwitching.h"


StateSwitching::StateSwitching()
{
}
StateSwitching::~StateSwitching()
{
}


//--- Startup
void StateSwitching::LoadItems()
{
	RestartPlayerBullets();
	SetCurrentAmmo(GetMaxAmmo());
	SetPlayerPosition(GetPlayerStartingLocation());
	SetPlayerHealth(GetPlayerMaxHealth());

	RestartEnemies();
	CreateEnemies();

	SetEnemyPosition();
	SetEnemyHealthBar(sf::Color::Red);
	SetEnemyHealth(GetEnemyMaxHealth());

	RestartHealthPacks();
	CreateHealthPacks();
	SetHealthPackPosition();

	RestartAmmoPacks();
	CreateAmmoPacks();
	SetAmmoPackPosition();

	RestartPowerUps();
	CreatePowerUps();
	SetPowerUpPosition();
	SetPoweredUp(false);

	RestartCrates();
	CreateCrates();
	SetCratePosition();
	
	RestartJellies();
	CreateJellies();
	SetJellyPosition();
}

//--- SaveGame
void StateSwitching::SaveGame()
{
	std::ofstream outFile;
	outFile.open("savegame.txt");
	
	if (outFile.is_open())
	{
		outFile << GetPlayerHealth() << " ";
		outFile << GetPlayerAmmo() << " ";
		outFile << GetPlayerImage().getPosition().x << " ";
		outFile << GetPlayerImage().getPosition().y << " ";

		if (GetPoweredUp() == true)
		{
			outFile << 1 << " ";
		}
		else if (GetPoweredUp() == false)
		{
			outFile << 0 << " ";
		}

		for (int i = 0; i < GetCrateDestroyed().size(); i++)
		{
			if (GetCrateDestroyed()[i] == true)
			{
				outFile << 1 << " ";
			}
			else if (GetCrateDestroyed()[i] == false)
			{
				outFile << 0 << " ";
			}
		}
		for (int i = 0; i < GetEnemiesKilled().size(); i++)
		{
			if (GetEnemiesKilled()[i] == true)
			{
				outFile << 1 << " ";
			}
			else if (GetEnemiesKilled()[i] == false)
			{
				outFile << 0 << " ";
			}
		}
		for (int i = 0; i < GetHealthTaken().size(); i++)
		{
			if (GetHealthTaken()[i] == true)
			{
				outFile << 1 << " ";
			}
			else if (GetHealthTaken()[i] == false)
			{
				outFile << 0 << " ";
			}
		}
		for (int i = 0; i < GetAmmoTaken().size(); i++)
		{
			if (GetAmmoTaken()[i] == true)
			{
				outFile << 1 << " ";				
			}
			else if (GetAmmoTaken()[i] == false)
			{
				outFile << 0 << " ";
			}
		}

		outFile.close();
		std::cout << "Game saved" << std::endl;
	}	
}

//--- LoadGame
void StateSwitching::LoadGame()
{	
	std::vector<std::string> permString;
	std::vector <float> permFloat;

	permString.clear();
	permFloat.clear();

	std::ifstream inFile;
	inFile.open("savegame.txt");
	
	if (inFile.is_open())
	{
		
		while (!inFile.eof())
		{
			std::string str, value;			
			std::getline(inFile, str);
			std::stringstream stream(str);

			while (std::getline(stream, value, ' '))
			{				
				permString.push_back(value);
			}
		}		

		for (int i = 0; i < permString.size(); i++)
		{
			permFloat.push_back(std::stoi(permString[i]));
		}

		SetPlayerHealth(permFloat[0]);
		SetCurrentAmmo(permFloat[1]);
		SetPlayerPosition(sf::Vector2f(permFloat[2], permFloat[3]));

		if (permFloat[4] == 1)
		{
			SetPoweredUp(true);
		}

		for (int i = 0; i < GetNumberOfCrates(); i++)
		{
			if (permFloat[i + 5] == 1)
			{
				SetCrateDestroyed(i);
			}
		}

		for (int i = 0; i < GetAmountOfEnemies(); i++)
		{
			if (permFloat[i + GetNumberOfCrates() + 5] == 1)
			{
				SetEnemiesKilled(i);
			}
		}

		for (int i = 0; i < GetHealthTaken().size(); i++)
		{
			if (permFloat[i + GetAmountOfEnemies() + GetNumberOfCrates() + 5] == 1)
			{
				SetHealthTaken(i, true);
			}
		}

		for (int i = 0; i < GetAmmoTaken().size(); i++)
		{
			if (permFloat[i + GetHealthTaken().size() + GetAmountOfEnemies() + GetNumberOfCrates() + 5] == 1)
			{
				SetAmmoTaken(i, true);
			}
		}

		inFile.close();
		std::cout << "Game loaded" << std::endl;
	}
	else
	{
		std::cout << "No savegame present" << std::endl;
	}	
}