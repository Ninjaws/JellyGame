#include "Game.h"


Game::Game()
{
}
Game::~Game()
{
}

void Game::SetWindow(sf::VideoMode videoMode, std::string windowName)
{
	Window.create(videoMode, windowName, sf::Style::Close);
}
void Game::SetTestMode(bool mode)
{
	testMode = mode;
	std::cout << "Test mode: " << std::boolalpha << testMode << std::endl;
}
void Game::SetMoveSpeed(float speed)
{
	moveSpeed = speed;
	std::cout << "Movement speed: " << moveSpeed << std::endl;
}
void Game::SetJumpSpeed(float jump)
{
	jumpSpeed = jump;
	std::cout << "Jump speed: " << jumpSpeed << std::endl;
}
void Game::SetNormalJumpSpeed(float jump)
{
	normalJumpSpeed = jump;
}
void Game::SetPoweredUpJumpSpeed(float jump)
{
	poweredUpJumpSpeed = jump;
}
void Game::SetGravity(float grav)
{
	gravity = grav;
	std::cout << "Gravity: " << gravity << std::endl;
}
void Game::SetFrameRate(float fps)
{
	std::cout << "FPS: " << fps << std::endl;
	frameRate = 1 / fps;
}
void Game::SetFireRate(float bps)
{
	std::cout << "Bullets per Second: " << bps << std::endl;
	fireRate = 1 / bps;
}
void Game::SetEnemyFireRate(float bps)
{
	enemyFireRate = 1 / bps;
}
void Game::SetAnimationRate(float aps)
{
	std::cout << "Animations per second: " << aps << std::endl;
	animationRate = 1 / aps;
}
void Game::SetStateSwitchingRate(float sps)
{
	stateSwitchingRate = 1 / sps;
}
void Game::SetMouseCurser(bool boolean)
{
	GetWindow().setMouseCursorVisible(boolean);
}
void Game::SetCrossHair(std::string texturelocation)
{
	crossHairTexture.loadFromFile(texturelocation);
	crossHairSprite.setTexture(crossHairTexture);
	crossHairSprite.setOrigin(crossHairTexture.getSize().x / 2, crossHairTexture.getSize().y / 2);

}
void Game::SetState(int state)
{
	State = state;
}
void Game::SetSelectingKey(sf::Keyboard::Key selectingkey)
{
	selectingKey = selectingkey;
}

sf::RenderWindow& Game::GetWindow()
{
	return Window;
}
sf::Vector2f Game::GetMousePosition()
{
	return mouseWorldPos;
}
sf::Vector2f Game::GetWindowPosition()
{
	return windowWorldPos;
}
sf::Keyboard::Key Game::GetSelectingKey()
{
	return selectingKey;
}
float Game::GetScreenWidth()
{
	return Window.getSize().x;
}
float Game::GetScreenHeight()
{
	return Window.getSize().y;
}
float Game::GetMoveSpeed()
{
	return moveSpeed;
}
float Game::GetNormalJumpSpeed()
{
	return normalJumpSpeed;
}
float Game::GetJumpSpeed()
{
	return jumpSpeed;
}
float Game::GetPoweredUpJumpSpeed()
{
	return poweredUpJumpSpeed;
}
float Game::GetGravity()
{
	return gravity;
}
float Game::GetFrameRate()
{
	return frameRate;
}
float Game::GetFireRate()
{
	return fireRate;
}
float Game::GetEnemyFireRate()
{
	return enemyFireRate;
}
float Game::GetAnimationRate()
{
	return animationRate;
}
float Game::GetStateSwitchingRate()
{
	return stateSwitchingRate;
}
bool Game::GetTestMode()
{
	return testMode;
}
int Game::GetState()
{
	return State;
}


void Game::DisplayState(std::string state)
{
	std::cout << "State: " << state << std::endl;
}
void Game::DrawCrossHair()
{
	crossHairSprite.setPosition(GetMousePosition());
	GetWindow().draw(crossHairSprite);
}
void Game::UpdateMousePosition()
{
	mousePixelPos = sf::Mouse::getPosition(GetWindow());
	mouseWorldPos = GetWindow().mapPixelToCoords(mousePixelPos);	
}
void Game::UpdateWindowPosition()
{
	windowPixelPos = GetWindow().getPosition();
	windowWorldPos = GetWindow().mapPixelToCoords(windowPixelPos);
}
