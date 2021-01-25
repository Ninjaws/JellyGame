#include "Enemy.h"


Enemy::Enemy()
{
}
Enemy::~Enemy()
{
}

void Enemy::DrawEnemy()
{
	for (int i = 0; i < enemySprite.size(); i++)
	{
		if (enemySprite[i].getPosition().y <= GetScreenHeight())
		{
			enemySprite[i].setTextureRect(sf::IntRect(spriteAnimation[i].x * enemySize.x, spriteAnimation[i].y * enemySize.y, enemySize.x, enemySize.y));
			GetWindow().draw(enemySprite[i]);
		}		
	}
}
void Enemy::EnemyMovement(int i)
{	
	groundCollision[i] = true;

	if (spriteAnimation[i].y == Left)
	{
		velocity[i].x = (-GetMoveSpeed() / 3);	
		EnemyAnimation(i);
	}
	else if (spriteAnimation[i].y == Right)
	{
		velocity[i].x = (GetMoveSpeed() / 3);	
		EnemyAnimation(i);
	}

	EnemyPositionUpdate(i);
	EnemyCollision(i);

	if (groundCollision[i] == false)
	{
		velocity[i].y += GetGravity();
	}	
	else
	{
		velocity[i].y = 0;
	}


	if (collision[i] == true)	// edge - > turn around
	{
		if (spriteAnimation[i].y == Left)
		{
			spriteAnimation[i].y = Right;
		}
		else if (spriteAnimation[i].y == Right)
		{
			spriteAnimation[i].y = Left;
		}
		collision[i] = false;
	}
	
	enemySprite[i].move(velocity[i]);
}
void Enemy::EnemyPositionUpdate(int i)
{
	float bottom = enemySprite[i].getPosition().y + enemySprite[i].getTextureRect().height + velocity[i].y;
	float left = enemySprite[i].getPosition().x + velocity[i].x;
	float right = enemySprite[i].getPosition().x + enemySprite[i].getTextureRect().width + velocity[i].x;
	float top = enemySprite[i].getPosition().y + velocity[i].y;
		
	sf::Vector2i leftTop(sf::Vector2i((int)left / GetTileSize(), (int)(top + 5) / GetTileSize()));
	sf::Vector2i leftBottom(sf::Vector2i((int)left / GetTileSize(), (int)(bottom - 5) / GetTileSize()));
	sf::Vector2i rightTop(sf::Vector2i((int)right / GetTileSize(), (int)(top + 5) / GetTileSize()));
	sf::Vector2i rightBottom(sf::Vector2i((int)right / GetTileSize(), (int)(bottom - 5) / GetTileSize()));

	sf::Vector2i bottomLeft(sf::Vector2i((int)(left + 5) / GetTileSize(), (int)bottom / GetTileSize()));		// +5 to separate bottom from side
	sf::Vector2i bottomRight(sf::Vector2i((int)(right - 5) / GetTileSize(), (int)bottom / GetTileSize()));		// -5 to separate bottom from side

	enemyCorners[i].clear();
	
	enemyCorners[i].push_back(leftTop);
	enemyCorners[i].push_back(leftBottom);
	enemyCorners[i].push_back(rightTop);
	enemyCorners[i].push_back(rightBottom);

	enemyCorners[i].push_back(bottomLeft);
	enemyCorners[i].push_back(bottomRight);
}
void Enemy::EnemyCollision(int i)
{
		if (GetColMap()[enemyCorners[i][4].y][enemyCorners[i][4].x] == 0 || GetColMap()[enemyCorners[i][5].y][enemyCorners[i][5].x] == 0)	  // No ground below enemy
		{
			collision[i] = true;
		}
		else if (GetColMap()[enemyCorners[i][0].y][enemyCorners[i][0].x] == 1 || GetColMap()[enemyCorners[i][1].y][enemyCorners[i][1].x] == 1 // Tile in front of enemy
			|| GetColMap()[enemyCorners[i][2].y][enemyCorners[i][2].x] == 1 || GetColMap()[enemyCorners[i][3].y][enemyCorners[i][3].x] == 1)
		{
			collision[i] = true;
		}

		if (GetColMap()[enemyCorners[i][4].y][enemyCorners[i][4].x] == 0 && GetColMap()[enemyCorners[i][5].y][enemyCorners[i][5].x] == 0)	// Enemy is floating
		{
			groundCollision[i] = false;
		}
}
void Enemy::PlayerBulletCollision()
{
	if (GetBullets().size() >= 1)
	{
		for (int i = 0; i < GetBullets().size(); i++)
		{
			bool enemyHit = false;
			bool tileHit = false;
			bool crateHit = false;

			sf::Vector2i bulletMiddle(sf::Vector2i((int)GetBullets()[i].x / GetTileSize(), (int)GetBullets()[i].y / GetTileSize()));			

			for (int j = 0; j < enemySprite.size(); j++)
			{

				if (((GetBullets()[i].x >= enemySprite[j].getPosition().x && GetBullets()[i].x <= enemySprite[j].getPosition().x + enemySprite[j].getTextureRect().width)
					&& (GetBullets()[i].y >= enemySprite[j].getPosition().y && GetBullets()[i].y <= enemySprite[j].getPosition().y + enemySprite[j].getTextureRect().height)))	// Enemy hit
				{
					if (enemyHealth[j] > 0)
					{
						enemyHealth[j] -= GetPlayerDamage();
					}
					enemyHit = true;
				}

			}
			if (GetColMap()[bulletMiddle.y][bulletMiddle.x] == 1)	// Tilemap hit
				{
					tileHit = true;
				}
			
			else
			{
				for (int j = 0; j < GetCrateSprite().size(); j++)	// Crate hit
				{
					if (!GetCrateDestroyed()[j])
					{

						if (((GetBullets()[i].x >= GetCrateSprite()[j].getPosition().x && GetBullets()[i].x <= GetCrateSprite()[j].getPosition().x + GetCrateSprite()[j].getTextureRect().width)
							&& (GetBullets()[i].y >= GetCrateSprite()[j].getPosition().y && GetBullets()[i].y <= GetCrateSprite()[j].getPosition().y + GetCrateSprite()[j].getTextureRect().height)))
						{
							PlayCrateDestroyedSound();
							SetCrateDestroyed(j);

							crateHit = true;
							PlayJellyFreedSound();
						}
					}
					}
				}
			

			if (enemyHit | tileHit | crateHit)
			{
				GetBullets().erase(GetBullets().begin() + i);
				GetBulletDirections().erase(GetBulletDirections().begin() + i);
			}
		}
	}
}
void Enemy::EnemyBulletCollision()
{

	for (int j = 0; j < numberOfEnemies; j++)
	{
		if (enemyBullets[j].size() > 0)
		{
			for (int i = 0; i < enemyBullets[j].size(); i++)
			{
				sf::Vector2i bulletMiddle(sf::Vector2i((int)enemyBullets[j][i].x / GetTileSize(), (int)enemyBullets[j][i].y / GetTileSize()));

				if (((enemyBullets[j][i].x >= GetPlayerImage().getPosition().x && enemyBullets[j][i].x <= GetPlayerImage().getPosition().x + GetPlayerImage().getTextureRect().width)	// Player hit
					&& (enemyBullets[j][i].y >= GetPlayerImage().getPosition().y && enemyBullets[j][i].y <= GetPlayerImage().getPosition().y + GetPlayerImage().getTextureRect().height)))
				{
					if (GetPlayerHealth() > 0)
					{
						PlayerHit(enemyDamage);
					}
					enemyBullets[j].erase(enemyBullets[j].begin() + i);
					enemyBulletDirections[j].erase(enemyBulletDirections[j].begin() + i);

				}
				else if (GetColMap()[bulletMiddle.y][bulletMiddle.x] == 1)		// Tilemap hit
				{
					enemyBullets[j].erase(enemyBullets[j].begin() + i);
					enemyBulletDirections[j].erase(enemyBulletDirections[j].begin() + i);
				}
			}
		}
	}
}
void Enemy::DrawHealthBar()
{
	for (int i = 0; i < enemySprite.size(); i++)
	{
		healthBar[i].setSize(sf::Vector2f(3 * enemyHealth[i], 5));
		healthBar[i].setPosition(enemySprite[i].getPosition().x, enemySprite[i].getPosition().y - 20);
		GetWindow().draw(healthBar[i]);
	}
}
void Enemy::EnemyDestroyed()
{
	for (int i = 0; i < enemySprite.size(); i++)
	{
		
			if (enemyHealth[i] <= 0)
			{
				if (isKilled[i] == false)
				{
					PlayPainSound();
					isKilled[i] = true;
				}
				if (enemySprite[i].getPosition().y <= GetScreenHeight())
				{
					velocity[i].y += GetGravity();
					enemySprite[i].move(velocity[i]);
				}
				
			}		
	}
}
void Enemy::RestartEnemies()
{
	enemySprite.clear();
	enemyHealth.clear();
	velocity.clear();
	healthBar.clear();

	enemyBullets.clear();
	enemyBulletDirections.clear();

	enemyStartPosition.clear();

   	enemyCorners.clear();
    collision.clear();
    groundCollision.clear();
	isKilled.clear();
}
void Enemy::EnemyAttack()
{
	for (int i = 0; i < enemySprite.size(); i++)
	{
		if (GetPlayerHealth() > 0)
		{
			if (invulnerabilityTimer.getElapsedTime().asMilliseconds() >= GetPlayerInvulnerability())
			{
				if (GetPlayerImage().getPosition().x + GetPlayerImage().getTextureRect().width >= enemySprite[i].getPosition().x && enemySprite[i].getPosition().x + enemySize.x >= GetPlayerImage().getPosition().x &&
					GetPlayerImage().getPosition().y + GetPlayerSize().y >= enemySprite[i].getPosition().y && GetPlayerImage().getPosition().y <= enemySprite[i].getPosition().y + enemySize.y)
				{
					PlayerHit(enemyDamage);
				}

				invulnerabilityTimer.restart();
			}
		}
	}
}
void Enemy::EnemyAnimation(int i)
{	
		if (animationRateTimer[i].getElapsedTime().asSeconds() >= GetAnimationRate())
		{
			spriteAnimation[i].x += 1;
			animationRateTimer[i].restart();
		}
		if (spriteAnimation[i].x * enemySize.x >= enemyTexture.getSize().x)
			spriteAnimation[i].x = 0;	
}
void Enemy::PlayerDetection()
{
	for (int i = 0; i < enemySprite.size(); i++)
	{
		if (enemyHealth[i] > 0)
		{
			
			if (fireRateTimer[i].getElapsedTime().asSeconds() >= GetEnemyFireRate())
			{

				if (spriteAnimation[i].y == Left && enemySprite[i].getPosition().x - GetPlayerImage().getPosition().x <= enemySpottingRange &&
					enemySprite[i].getPosition().x - GetPlayerImage().getPosition().x > 55
					&& enemySprite[i].getPosition().y + enemySize.y >= GetPlayerImage().getPosition().y)	// && enemySprite[i].getPosition().y + enemySize.y >= GetPlayerImage().getPosition().y)
				{
					

					if (hasMoved[i] == true)
					{
						PlayPlayerSpottedSound();
						hasMoved[i] = false;
					}
										
					EnemyShootingLeft(i);
					
				}

				else if (spriteAnimation[i].y == Right && GetPlayerImage().getPosition().x - enemySprite[i].getPosition().x <= enemySpottingRange &&
					GetPlayerImage().getPosition().x - enemySprite[i].getPosition().x > 55
					&& enemySprite[i].getPosition().y + enemySize.y >= GetPlayerImage().getPosition().y)	// && enemySprite[i].getPosition().y + enemySize.y >= GetPlayerImage().getPosition().y)
				{
					

					if (hasMoved[i] == true)
					{
						PlayPlayerSpottedSound();
						hasMoved[i] = false;
					}

					
					EnemyShootingRight(i);
					
				}

				fireRateTimer[i].restart();
			}


			if ((spriteAnimation[i].y == Left && enemySprite[i].getPosition().x - GetPlayerImage().getPosition().x <= enemySpottingRange &&
				enemySprite[i].getPosition().x - GetPlayerImage().getPosition().x > 55
				&& enemySprite[i].getPosition().y + enemySize.y >= GetPlayerImage().getPosition().y) ||
				(spriteAnimation[i].y == Right && GetPlayerImage().getPosition().x - enemySprite[i].getPosition().x <= enemySpottingRange &&
				GetPlayerImage().getPosition().x - enemySprite[i].getPosition().x > 55
				&& enemySprite[i].getPosition().y + enemySize.y >= GetPlayerImage().getPosition().y))
			{

			}
				else
				{
					EnemyMovement(i);
					hasMoved[i] = true;
				}
								
			
		}
	}
}
void Enemy::EnemyShootingLeft(int i)
{
	sf::Vector2f bulletStartLocation(enemySprite[i].getPosition().x - 25, enemySprite[i].getPosition().y + 10);   //-5, +10
	PlayGunSound();
	enemyBullets[i].push_back(bulletStartLocation);

	enemyAngleShot = atan2((GetPlayerImage().getPosition().y + 10) - bulletStartLocation.y,
		GetPlayerImage().getPosition().x - bulletStartLocation.x);
	enemyBulletDirections[i].push_back(enemyAngleShot);
}
void Enemy::EnemyShootingRight(int i)
{
	sf::Vector2f bulletStartLocation(enemySprite[i].getPosition().x + 55, enemySprite[i].getPosition().y + 10);		//+22, + 10
	PlayGunSound();
	enemyBullets[i].push_back(bulletStartLocation);

	enemyAngleShot = atan2((GetPlayerImage().getPosition().y + 10) - bulletStartLocation.y,
		GetPlayerImage().getPosition().x - bulletStartLocation.x);
	enemyBulletDirections[i].push_back(enemyAngleShot);
}
void Enemy::EnemyBullets()
{
	for (int j = 0; j < numberOfEnemies; j++)  //enemySprite.size()
	{
		if (enemyBullets[j].size() >= 1)
		{
			for (int i = 0; i < enemyBullets[j].size(); i++)
			{
				enemyBullets[j][i].x += cos(enemyBulletDirections[j][i]) * enemyBulletSpeed;	
				enemyBullets[j][i].y += sin(enemyBulletDirections[j][i]) * enemyBulletSpeed;	

				enemyBullet.setPosition(enemyBullets[j][i].x, enemyBullets[j][i].y);
				GetWindow().draw(enemyBullet);
			}
		}
	}
}
void Enemy::DrawEnemyGun()
{
	for (int i = 0; i < enemySprite.size(); i++)
	{
		gunImageLeft[i].setPosition(enemySprite[i].getPosition().x, enemySprite[i].getPosition().y + 17);
		gunImageRight[i].setPosition(enemySprite[i].getPosition().x + 25, enemySprite[i].getPosition().y + 17);

		if (spriteAnimation[i].y == Left)
		{
			GetWindow().draw(gunImageLeft[i]);
		}
		else if (spriteAnimation[i].y == Right)
		{
			GetWindow().draw(gunImageRight[i]);
		}
	}
}

void Enemy::SetEnemyStartingPosition()	//Parameter not necessary; Sets the startingpositions for all enemies
{
	sf::Vector2f startlocation;

	for (int i = 0; i < GetAmountOfEnemies(); i++)
	{
		enemyStartingLocation.push_back(startlocation);
	}
	
	enemyStartingLocation[0].x = 31 * GetTileSize();
	enemyStartingLocation[0].y = 15 * GetTileSize();

	enemyStartingLocation[1].x = 51 * GetTileSize();
	enemyStartingLocation[1].y = 10 * GetTileSize();

	enemyStartingLocation[2].x = 56 * GetTileSize();
	enemyStartingLocation[2].y = 5 * GetTileSize();

	enemyStartingLocation[3].x = 78 * GetTileSize();
	enemyStartingLocation[3].y = 10 * GetTileSize();

	enemyStartingLocation[4].x = 82 * GetTileSize();
	enemyStartingLocation[4].y = 15 * GetTileSize();	

	enemyStartingLocation[5].x = 88 * GetTileSize();
	enemyStartingLocation[5].y = 4 * GetTileSize();
	
	enemyStartingLocation[6].x = 98 * GetTileSize();
	enemyStartingLocation[6].y = 11 * GetTileSize();

	enemyStartingLocation[7].x = 103 * GetTileSize();
	enemyStartingLocation[7].y = 15 * GetTileSize();
	
	
	
}
void Enemy::SetEnemyPosition()										// Gives the startingposition to the enemy
{
	for (int i = 0; i < enemySprite.size(); i++)
	{
		enemyStartPosition.push_back(sf::Vector2f(0, 0));
		enemyStartPosition[i] = enemyStartingLocation[i];
		enemySprite[i].setPosition(enemyStartPosition[i].x, enemyStartPosition[i].y);
	}
}
void Enemy::SetEnemyDamage(unsigned int damage)
{
	enemyDamage = damage;
}
void Enemy::SetEnemyMaxHealth(unsigned int health)
{
	maxEnemyHealth = health;
}
void Enemy::SetEnemyHealth(unsigned int health)
{
	for (int i = 0; i < enemySprite.size(); i++)
	{
		enemyHealth.push_back(health);
	}
}
void Enemy::SetEnemyHealthBar(sf::Color color)
{	
	sf::RectangleShape rect;

	for (int i = 0; i < enemySprite.size(); i++)
	{
		healthBar.push_back(rect);

		healthBar[i].setFillColor(color);
	}
}
void Enemy::SetEnemySize(sf::Vector2f enemysize)
{
	enemySize.x = enemysize.x;
	enemySize.y = enemysize.y;
}
void Enemy::SetEnemyTexture(std::string texturelocation)
{
	enemyTextureLocation = texturelocation;
	enemyTexture.loadFromFile(enemyTextureLocation);
}
void Enemy::SetAmountOfEnemies(unsigned int amountofenemies)
{
	numberOfEnemies = amountofenemies;
}
void Enemy::SetEnemySpriteAnimation(int size, int direction)
{
	sf::Clock clock;
	srand(time(NULL));
	for (int i = 0; i < numberOfEnemies; i++)
	{
		animationRateTimer.push_back(clock);
				
		int v1 = rand() % 2 + 1;

		if (v1 == 1)
		{
			spriteAnimation.push_back(sf::Vector2i(size, direction));
		}
		else if (v1 == 2)
		{
			spriteAnimation.push_back(sf::Vector2i(size, direction - 1));
		}
	}
}
void Enemy::SetEnemySpottingRange(float spottingrange)
{
	enemySpottingRange = spottingrange;
}
void Enemy::SetEnemyBullet(sf::Color color, float radius, float bulletspeed)
{
	enemyBullet.setFillColor(color);
	enemyBullet.setRadius(radius);
	enemyBulletSpeed = bulletspeed;
}
void Enemy::SetEnemyGun(std::string gunleft, std::string gunright)
{
	gunTextureLeft.loadFromFile(gunleft);
	gunTextureRight.loadFromFile(gunright);

	sf::Sprite sprite;
	for (int i = 0; i < numberOfEnemies; i++)
	{
		gunImageLeft.push_back(sprite);
		gunImageRight.push_back(sprite);

		gunImageLeft[i].setTexture(gunTextureLeft);
		gunImageLeft[i].setOrigin(gunTextureLeft.getSize().x / 2, gunTextureLeft.getSize().y / 2);

		gunImageRight[i].setTexture(gunTextureRight);
		gunImageRight[i].setOrigin(gunTextureRight.getSize().x / 2, gunTextureRight.getSize().y / 2);
	}
}
void Enemy::SetEnemiesKilled(int i)
{
	isKilled[i] = true;
	enemyHealth[i] = 0;
	enemySprite[i].setPosition(0, GetScreenHeight());
}

unsigned int Enemy::GetEnemyMaxHealth()
{
	return  maxEnemyHealth;
}
unsigned int Enemy::GetAmountOfEnemies()
{
	return numberOfEnemies;
}
std::string Enemy::GetEnemyTextureLocation()
{
	return enemyTextureLocation;
}
sf::Vector2f Enemy::GetEnemySize()
{
	return enemySize;
}
std::vector<bool> Enemy::GetEnemiesKilled()
{
	return isKilled;
}

void Enemy::CreateEnemies()
{
	sf::Sprite sprite;

	std::vector<sf::Vector2f> bullet;
	/**/std::vector<sf::Vector2i> corners;
	std::vector<float> directions;
	sf::Clock clock;

	for (int i = 0; i < numberOfEnemies; i++)
	{
		enemySprite.push_back(sprite);
		enemySprite[i].setTexture(enemyTexture);

		enemyBullets.push_back(bullet);
		enemyBulletDirections.push_back(directions);
		fireRateTimer.push_back(clock);

		velocity.push_back(sf::Vector2f(0, 0));
		hasMoved.push_back(false);
		isKilled.push_back(false);		

		enemyCorners.push_back(corners);
		collision.push_back(false);
		groundCollision.push_back(false);
	}
}