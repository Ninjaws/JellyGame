#include "Player.h"

Player::Player()
{
}
Player::~Player()
{
}

void Player::Movement()
{
	if (playerHealth > 0)
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		{
			spriteAnimation.y = Right;
			velocity.x = GetMoveSpeed();
			Animation();
		}
		
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		{
			spriteAnimation.y = Left;
			velocity.x = -GetMoveSpeed();
			Animation();
		}
		else
			velocity.x = 0.0f;

		PositionUpdate();
		Collision();

		if (!groundCollision && !crateTopCollision)
		{
			velocity.y += GetGravity();
		}
		else
		{
			velocity.y = 0.0f;
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && (groundCollision == true || crateTopCollision == true))
		{
			velocity.y = -GetJumpSpeed();
		}

		playerImage.move(velocity);


	}
}
void Player::PositionUpdate()
{
	float bottom = playerImage.getPosition().y + playerImage.getTextureRect().height + velocity.y;
	float left = playerImage.getPosition().x + velocity.x;
	float right = playerImage.getPosition().x + playerImage.getTextureRect().width + velocity.x;
	float top = playerImage.getPosition().y + velocity.y;

	sf::Vector2i topLeft(sf::Vector2i((int)(left + 5) / GetTileSize(), (int)top / GetTileSize()));				// +5 to separate top from side
	sf::Vector2i topRight(sf::Vector2i((int)(right - 5) / GetTileSize(), (int)top / GetTileSize()));			// -5 to separate top from side

	sf::Vector2i leftTop(sf::Vector2i((int)left / GetTileSize(), (int)(top + 5) / GetTileSize()));
	sf::Vector2i leftBottom(sf::Vector2i((int)left / GetTileSize(), (int)(bottom - 5) / GetTileSize()));
	sf::Vector2i rightTop(sf::Vector2i((int)right / GetTileSize(), (int)(top + 5) / GetTileSize()));
	sf::Vector2i rightBottom(sf::Vector2i((int)right / GetTileSize(), (int)(bottom - 5) / GetTileSize()));

	sf::Vector2i bottomLeft(sf::Vector2i((int)(left + 5) / GetTileSize(), (int)bottom / GetTileSize()));		// +5 to separate bottom from side
	sf::Vector2i bottomRight(sf::Vector2i((int)(right - 5) / GetTileSize(), (int)bottom / GetTileSize()));		// -5 to separate bottom from side


	tiles.clear();

	tiles.push_back(topLeft);
	tiles.push_back(topRight);

	tiles.push_back(leftTop);
	tiles.push_back(leftBottom);
	tiles.push_back(rightTop);
	tiles.push_back(rightBottom);

	tiles.push_back(bottomLeft);
	tiles.push_back(bottomRight);
}
void Player::Collision()
{
	timesCollision.clear();

	for (int i = 0; i < tiles.size(); i++)
	{
		if (GetColMap()[tiles[i].y][tiles[i].x] == 1)
		{
			timesCollision.push_back(i);
		}
	}

	groundCollision = false;

	if (timesCollision.size() > 0)
	{
		for (int i = 0; i < timesCollision.size(); i++)
		{
			if (timesCollision[i] == 0 || timesCollision[i] == 1)						//Topleft and Topright
			{
				velocity.y = 0;
			}
			else if (timesCollision[i] == 2 || timesCollision[i] == 3 ||				//Lefttop and Leftbottom
				timesCollision[i] == 4 || timesCollision[i] == 5)						//Righttop and Lefttop
			{
				velocity.x = 0;
			}
			else if (timesCollision[i] == 6 || timesCollision[i] == 7)					 //Bottomleft and Bottomright
			{
				groundCollision = true;
			}
		}
	}
}
void Player::Shoot()
{
	sf::Vector2f bulletStartLocation(playerImage.getPosition().x + 10, playerImage.getPosition().y + 10);

	if (spriteAnimation.y == Left)
	{
		bulletStartLocation.y = playerImage.getPosition().y + 10;
		bulletStartLocation.x = playerImage.getPosition().x - 5;
	}
	if (spriteAnimation.y == Right)
	{
		bulletStartLocation.y = playerImage.getPosition().y + 10;
		bulletStartLocation.x = playerImage.getPosition().x + 22;
	}
	
	if (GetMousePosition().x > playerImage.getPosition().x + (gunTextureLeft.getSize().x) && spriteAnimation.y == Right ||
		GetMousePosition().x + (gunTextureLeft.getSize().x / 2) < playerImage.getPosition().x && spriteAnimation.y == Left)
	{
		PlayGunSound();
		currentAmmo--;
		bullets.push_back(bulletStartLocation);
		angleShot = atan2(GetMousePosition().y - bulletStartLocation.y,
			GetMousePosition().x - bulletStartLocation.x);
		bulletDirections.push_back(angleShot);
	}
}
void Player::Bullet()
{
	if (bullets.size() >= 1)
	{
		for (int i = 0; i < bullets.size(); i++)
		{
			bullets[i].x += cos(bulletDirections[i]) * bulletSpeed;
			bullets[i].y += sin(bulletDirections[i]) * bulletSpeed;

			bullet.setPosition(bullets[i].x, bullets[i].y);
			GetWindow().draw(bullet);
		}
	}

}
void Player::Animation()
{
	if (animationRateTimer.getElapsedTime().asSeconds() >= GetAnimationRate())
	{
		spriteAnimation.x += 1;
		animationRateTimer.restart();
	}
	if (spriteAnimation.x * 32 >= playerTexture.getSize().x)
		spriteAnimation.x = 0;
}
void Player::Firing()
{
	if (groundCollision || crateTopCollision)
	{

		if (fireRateTimer.getElapsedTime().asSeconds() >= GetFireRate())
		{
			if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			{
				if (currentAmmo > 0)
				{
					Shoot();
					fireRateTimer.restart();
				}
				else if (currentAmmo == 0 && ((GetMousePosition().x > playerImage.getPosition().x + (gunTextureLeft.getSize().x) && spriteAnimation.y == Right) ||
					(GetMousePosition().x + (gunTextureLeft.getSize().x / 2) < playerImage.getPosition().x && spriteAnimation.y == Left)))
				{
					PlayOutofammoSound();
					fireRateTimer.restart();
				}
			}			
		}

	}
}
void Player::RotateGun()
{
	if (GetMousePosition().x > playerImage.getPosition().x + (gunTextureLeft.getSize().x) && spriteAnimation.y == Right)
	{

		gunImageRight.setPosition(playerImage.getPosition().x + 32, playerImage.getPosition().y + 17);
		gunRotationRight = atan2(GetMousePosition().y - playerImage.getPosition().y,
			GetMousePosition().x - playerImage.getPosition().x);
		gunImageRight.setRotation(gunRotationRight * 90);
	}
	else if (GetMousePosition().x + (gunTextureLeft.getSize().x / 2) < playerImage.getPosition().x && spriteAnimation.y == Left)
	{
		gunImageLeft.setPosition(playerImage.getPosition().x, playerImage.getPosition().y + 17);
		gunRotationLeft = atan2(GetMousePosition().y - playerImage.getPosition().y,
			playerImage.getPosition().x - GetMousePosition().x);
		gunImageLeft.setRotation(-gunRotationLeft * 90);
	}
}
void Player::DrawGun()
{
	if (GetMousePosition().x > playerImage.getPosition().x + (gunTextureLeft.getSize().x) && spriteAnimation.y == Right)
	{
		GetWindow().draw(gunImageRight);
	}
	else if (GetMousePosition().x + (gunTextureLeft.getSize().x / 2) < playerImage.getPosition().x && spriteAnimation.y == Left)
	{
		GetWindow().draw(gunImageLeft);
	}
}
void Player::Reloading()
{
	PlayReloadSound();
	currentAmmo += reloadAmount;
	if (currentAmmo >= maxAmmo)
	{
		currentAmmo = maxAmmo;
	}
}
void Player::DisplayAmmo()
{
	sf::Vector2i pixel_pos = ammoDisplayLocation;
	sf::Vector2f coord_pos = GetWindow().mapPixelToCoords(pixel_pos);

	for (int i = 0; i < currentAmmo; i++)
	{
		if (i <= 49)
		{
			ammoSprite[i].setPosition(coord_pos.x + ammoTexture.getSize().x * i, coord_pos.y);
		}
		if (i > 49 && i <= 99)
		{
			ammoSprite[i].setPosition(coord_pos.x + ammoTexture.getSize().x * (i - (50)), coord_pos.y + ammoTexture.getSize().y);
		}
		else if (i > 99 && i <= 149)
		{
			ammoSprite[i].setPosition(coord_pos.x + ammoTexture.getSize().x * (i - (100)), coord_pos.y + ammoTexture.getSize().y * 2);
		}
		else if (i > 149 && i <= 199)
		{
			ammoSprite[i].setPosition(coord_pos.x + ammoTexture.getSize().x * (i - (150)), coord_pos.y + ammoTexture.getSize().y * 3);
		}
		else if (i > 199 && i <= 249)
		{
			ammoSprite[i].setPosition(coord_pos.x + ammoTexture.getSize().x * (i - (200)), coord_pos.y + ammoTexture.getSize().y * 4);
		}		
		GetWindow().draw(ammoSprite[i]);

	}	
}
void Player::DrawPlayer()
{
	playerImage.setTextureRect(sf::IntRect(spriteAnimation.x * playerSize.x, spriteAnimation.y * playerSize.y, playerSize.x, playerSize.y));
	GetWindow().draw(playerImage);
}
void Player::GameScreenInput()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
	{
		SetState(State_PauseScreen);
		PauseGameMusic();
		DisplayState("PauseScreen");
	}

	if (playerHealth <= 0)
	{
		velocity.y += GetGravity();
		playerImage.move(velocity);
		if (playerImage.getPosition().y >= GetScreenHeight() + 20)
		{
			SetState(State_GameOverScreen);
			StopGameMusic();			

			PlayGameOverMusic();
			DisplayState("GameOverScreen");
		}
	}
}
void Player::PlayerHit(unsigned int damage)
{
	playerHealth -= damage;
	PlayPlayerDamageSound();
}
void Player::PlayerHealed(unsigned int health)
{
	playerHealth += health;
	if (playerHealth > maxPlayerHealth)
	{
		playerHealth = maxPlayerHealth;
	}
	PlayHealSound();
}
void Player::DisplayHealth()
{
	sf::Vector2i pixel_pos = healthDisplayLocation;
	sf::Vector2f coord_pos = GetWindow().mapPixelToCoords(pixel_pos);	
	for (int i = 0; i < maxPlayerHealth; i++)
	{
		noHealthSprite[i].setPosition(coord_pos.x + noHealthTexture.getSize().x * i, coord_pos.y);
		GetWindow().draw(noHealthSprite[i]);
	}
	for (int i = 0; i < playerHealth; i++)
	{	
		healthSprite[i].setPosition(coord_pos.x + healthTexture.getSize().x * i, coord_pos.y);
		GetWindow().draw(healthSprite[i]);
	}	
	
}
void Player::ScreenScrolling()
{
	if (playerImage.getPosition().x + (playerSize.x / 2) + (GetScreenWidth() / 2) > gameScreenBackground3.getPosition().x + gameScreenBackground3.getTextureRect().width - 20)
	{
		cameraPosition.x = (gameScreenBackground3.getPosition().x + gameScreenBackground3.getTextureRect().width) - camera.getSize().x / 2;
	}
	else if (playerImage.getPosition().x + playerImage.getTextureRect().width > camera.getSize().x / 2)
	{
		cameraPosition.x = playerImage.getPosition().x + playerImage.getTextureRect().width;
	}
	else
	{
		cameraPosition.x = camera.getSize().x / 2;
	}
	
	camera.setCenter(cameraPosition);

	GetWindow().setView(camera);
	
}
void Player::DrawGameScreenBackground()
{
	GetWindow().draw(gameScreenBackground);	
	GetWindow().draw(gameScreenBackground3);
	GetWindow().draw(gameScreenBackground2);
}
void Player::PlayerOutOfBounds()
{
	if (playerImage.getPosition().y >= GetScreenHeight())
	{
		playerHealth = 0;
	}
}
void Player::RestartPlayerBullets()
{
	bullets.clear();
	bulletDirections.clear();
}

void Player::SetSpriteAnimation(int size, int direction)
{
	spriteAnimation.x = size;
	spriteAnimation.y = direction;
}
void Player::SetBullet(sf::Color color, float radius, float bulletspeed)
{
	bullet.setFillColor(color);
	bullet.setRadius(radius);
	bulletSpeed = bulletspeed;
	std::cout << "Bullet speed: " << bulletSpeed << std::endl;

}
void Player::SetPlayerSettings(float width, float height, std::string spritelocation)
{
	playerTexture.loadFromFile(spritelocation);
	playerTexture.setSmooth(true);
	playerImage.setTexture(playerTexture);
	

	playerSize.x = width;
	playerSize.y = height;
}
void Player::SetMaxAmmo(unsigned int maxammo)
{
	maxAmmo = maxammo;
	currentAmmo = maxammo;
}
void Player::SetAmmoDisplay(std::string texturelocation, sf::Vector2i position)
{
	ammoTexture.loadFromFile(texturelocation);

	sf::Sprite sprite;
	for (int i = 0; i < maxAmmo; i++)
	{
		ammoSprite.push_back(sprite);
		ammoSprite[i].setTexture(ammoTexture);
	}
	ammoDisplayLocation = position;	
}
void Player::SetReloadAmount(unsigned int reloadamount)
{
	reloadAmount = reloadamount;
}
void Player::SetCurrentAmmo(unsigned int ammo)
{
	currentAmmo = ammo;
}
void Player::SetPlayerStartingLocation(sf::Vector2f startingposition)
{
	playerStartingLocation = startingposition;
}
void Player::SetPlayerPosition(sf::Vector2f position)
{
	playerImage.setPosition(position);
}
void Player::SetPlayerMaxHealth(unsigned int health)
{
	maxPlayerHealth = health;
}
void Player::SetPlayerHealth(unsigned int health)
{	
	playerHealth = health;
}
void Player::SetHealthDisplay(std::string texturelocation, std::string texturelocation2, sf::Vector2i position)
{
	healthTexture.loadFromFile(texturelocation);
	noHealthTexture.loadFromFile(texturelocation2);

	sf::Sprite sprite;
	for (int i = 0; i < maxPlayerHealth; i++)
	{
		healthSprite.push_back(sprite);
		noHealthSprite.push_back(sprite);

		healthSprite[i].setTexture(healthTexture);
		noHealthSprite[i].setTexture(noHealthTexture);
	}
	healthDisplayLocation = position;
}
void Player::SetPlayerInvulnerability(float milliseconds)
{
	playerInvulnerability = milliseconds;
	std::cout << "Player Invulnerability (in milliseconds): " << milliseconds << std::endl;
}
void Player::SetScreenScrolling()
{
	camera.setSize(GetWindow().getSize().x, GetWindow().getSize().y);
	cameraPosition.x = GetWindow().getSize().x / 2;
	cameraPosition.y = GetWindow().getSize().y / 2;
}
void Player::SetGun(std::string gunleft, std::string gunright)
{
	gunTextureRight.loadFromFile(gunright);
	gunImageRight.setTexture(gunTextureRight);
	gunImageRight.setPosition(playerImage.getPosition().x, playerImage.getPosition().y);
	gunImageRight.setOrigin(gunTextureRight.getSize().x / 2, gunTextureRight.getSize().y / 2);

	gunTextureLeft.loadFromFile(gunleft);
	gunImageLeft.setTexture(gunTextureLeft);
	gunImageLeft.setPosition(playerImage.getPosition().x, playerImage.getPosition().y);
	gunImageLeft.setOrigin(gunTextureLeft.getSize().x / 2, gunTextureLeft.getSize().y / 2);

}
void Player::SetPlayerDamage(unsigned int damage)
{
	playerDamage = damage;
}
void Player::SetGameScreenBackground(std::string texturelocation, std::string texturelocation2, std::string texturelocation3)
{
	gameScreenTexture.loadFromFile(texturelocation);
	gameScreenBackground.setTexture(gameScreenTexture);	
	gameScreenBackground.setPosition(0, 0);
	gameScreenBackground.setTextureRect(sf::IntRect(0, 0, GetScreenWidth() * 2, gameScreenTexture.getSize().y));

	gameScreenTexture2.loadFromFile(texturelocation2);
	gameScreenBackground2.setTexture(gameScreenTexture2);
	gameScreenBackground2.setPosition(GetScreenWidth() * 2, -200);
	gameScreenBackground2.setTextureRect(sf::IntRect(0, 0, (67 * GetTileSize()) - (GetScreenWidth() * 2), gameScreenTexture2.getSize().y));

	gameScreenTexture3.loadFromFile(texturelocation3);
	gameScreenBackground3.setTexture(gameScreenTexture3);
	gameScreenBackground3.setPosition(65 * GetTileSize(), -200);
	gameScreenBackground3.setTextureRect(sf::IntRect(0, 0, 56 * GetTileSize(), gameScreenTexture3.getSize().y));

	std::cout << "Gamescreen background Loaded" << std::endl;
}
void Player::SetCrateTopCollision(bool crate)
{
	crateTopCollision = crate;
}

sf::Vector2f Player::GetPlayerStartingLocation()
{
	return playerStartingLocation;
}
sf::Vector2f Player::GetPlayerSize()
{
	return playerSize;
}
sf::Sprite& Player::GetPlayerImage()
{
	return playerImage;
}
unsigned int Player::GetPlayerHealth()
{
	return playerHealth;
}
unsigned int Player::GetPlayerMaxHealth()
{
	return maxPlayerHealth;
}
unsigned int Player::GetPlayerDamage()
{
	return playerDamage;
}
unsigned int Player::GetPlayerAmmo()
{
	return currentAmmo;
}
unsigned int Player::GetMaxAmmo()
{
	return maxAmmo;
}
float Player::GetPlayerInvulnerability()
{
	return playerInvulnerability;
}
sf::CircleShape Player::GetBullet()
{
	return bullet;
}

std::vector <sf::Vector2f>& Player::GetBullets()
{
	return bullets;
}
std::vector <float>& Player::GetBulletDirections()
{
	return bulletDirections;
}
sf::Sprite Player::GetGameScreenBackground3()
{
	return gameScreenBackground3;
}