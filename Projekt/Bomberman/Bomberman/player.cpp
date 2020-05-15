#include <iostream>
#include <cmath>
#include <fstream>
#include <ctime>
#include <SFML/Graphics.hpp>

#include "player.hpp"
#include "bomb.hpp"
#include "map.hpp"
#include "enum.hpp"

Player::Player(std::string arg_name)
	: bombCooldown(2.f), defaultVelocity(200.f, 200.f), playerState(movingRight), name(arg_name), bombPlaced(0)
{
	velocity = defaultVelocity;

	collisionBox.width = 48;
	collisionBox.height = 48;

	sprite.setOrigin(collisionBox.width / 2, collisionBox.height / 2);
}

void Player::MoveWSAD(const sf::Time & deltaTime, Map & map)
{
	timeSinceBomb -= deltaTime.asSeconds();

	CheckForCollisions(deltaTime, map);

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
		GoUp(deltaTime, map);

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
		GoDown(deltaTime, map);

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		GoLeft(deltaTime, map);

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		GoRight(deltaTime, map);

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && timeSinceBomb <= 0)
	{
		timeSinceBomb = bombCooldown;

		bombLocation = this->GetPosition();													// robi zeby bomba  
		bombLocation.x = ((int)bombLocation.x / 64) * 64;									// pojawila sie dokladnie
		bombLocation.y = ((int)bombLocation.y / 64) * 64;

		Bomb * bomb = new Bomb{};
		bomb->SetUp();
		this->bombPlaced++;

		bomb->SetPosition(bombLocation);

		delete map.blocks[(int)(bombLocation.y) / 64][(int)(bombLocation.x) / 64];
		map.blocks[(int)(bombLocation.y) / 64][(int)(bombLocation.x) / 64] = bomb;
		map.blocks[(int)(bombLocation.y) / 64][(int)(bombLocation.x) / 64]->type = bombBlock;
	}
	else
	{
		bombLocation.x = -1;								// jesli bomba nie zostala postawiona to -1
		bombLocation.y = -1;								// tak aby za kazdym razem ramka TCP byla identyczna
	}
}

void Player::MoveArrows(const sf::Time & deltaTime, Map & map)
{
	timeSinceBomb -= deltaTime.asSeconds();

	CheckForCollisions(deltaTime, map);

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
		GoUp(deltaTime, map);

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
		GoDown(deltaTime, map);

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		GoLeft(deltaTime, map);

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		GoRight(deltaTime, map);

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::RShift) && timeSinceBomb <= 0)
	{
		timeSinceBomb = bombCooldown;

		bombLocation = this->GetPosition();													// robi zeby bomba  
		bombLocation.x = ((int)bombLocation.x / 64) * 64;									// pojawila sie dokladnie
		bombLocation.y = ((int)bombLocation.y / 64) * 64;									// w kratce a nie np w polowie

		Bomb * bomb = new Bomb{};
		bomb->SetUp();
		this->bombPlaced++;

		bomb->SetPosition(bombLocation);

		delete map.blocks[(int)(bombLocation.y) / 64][(int)(bombLocation.x) / 64];
		map.blocks[(int)(bombLocation.y) / 64][(int)(bombLocation.x) / 64] = bomb;
		map.blocks[(int)(bombLocation.y) / 64][(int)(bombLocation.x) / 64]->type = bombBlock;
	}
	else
	{
		bombLocation.x = -1;								// jesli bomba nie zostala postawiona to -1
		bombLocation.y = -1;								// tak aby za kazdym razem ramka TCP byla identyczna
	}
}

void Player::GoUp(const sf::Time & deltaTime, Map & map)
{
	if (canGoUp)
	{
		position.y -= int(velocity.y * deltaTime.asSeconds());
	}
}

void Player::GoDown(const sf::Time & deltaTime, Map & map)
{
	if (canGoDown)
	{
		position.y += int(velocity.y * deltaTime.asSeconds());
	}
}

void Player::GoLeft(const sf::Time & deltaTime, Map & map)
{
	if (canGoLeft)
	{
		position.x -= int(velocity.x * deltaTime.asSeconds());
		playerState = movingLeft;
	}
}

void Player::GoRight(const sf::Time & deltaTime, Map & map)
{
	if (canGoRight)
	{
		position.x += int(velocity.x * deltaTime.asSeconds());
		playerState = movingRight;
	}
}

void Player::Update(const sf::Time deltaTime)
{
	UpdateSprite();

	UpdateCollisionBox();

	sprite.setPosition(position);
}

void Player::UpdateSprite()
{
	switch (playerState)
	{
	case movingLeft:
		sprite.setScale(-1.f, 1.f);
		break;
	case movingRight:
		sprite.setScale(1.f, 1.f);
		break;
	}
}

void Player::UpdateCollisionBox()		
{
	collisionBox.left = position.x;
	collisionBox.top = position.y;
}

void Player::CheckForCollisions(const sf::Time & deltaTime, Map & map)
{
	float leftPlayerEdge = this->GetCollisionBox().left - collisionBox.width / 2;
	float rightPlayerEdge = this->GetCollisionBox().left + collisionBox.width / 2;
	float topPlayerEdge = this->GetCollisionBox().top - collisionBox.height / 2;
	float bottomPlayerEdge = this->GetCollisionBox().top + collisionBox.height / 2;

	sf::FloatRect playerCheck(sf::Vector2f(leftPlayerEdge / 64, topPlayerEdge / 64), sf::Vector2f(rightPlayerEdge / 64, bottomPlayerEdge / 64));

	if (map.blocks[(int)(this->GetPosition().y / 64)][(int)((this->GetPosition().x) / 64)]->type == explosionBlock
		&& map.blocks[(int)(this->GetPosition().y / 64)][(int)((this->GetPosition().x) / 64)]->GetCollisionBox().intersects(playerCheck))
	{
		this->Kill();
	}

	//kolizje z lewej
	if (map.blocks[(int)((topPlayerEdge + 5) / 64)][(int)((leftPlayerEdge - 1) / 64)]->type == solidBlock
		|| map.blocks[(int)((topPlayerEdge + 5) / 64)][(int)((leftPlayerEdge - 1) / 64)]->type == breakableBlock
		|| map.blocks[(int)((bottomPlayerEdge - 5) / 64)][(int)((leftPlayerEdge - 1) / 64)]->type == solidBlock
		|| map.blocks[(int)((bottomPlayerEdge - 5) / 64)][(int)((leftPlayerEdge - 1) / 64)]->type == breakableBlock)
	{
		this->ForbidGoingLeft();
	}
	else
		this->AllowGoingLeft();
	
	// kolizje z prawej
	if (map.blocks[(int)((topPlayerEdge + 5) / 64)][(int)((rightPlayerEdge + 1) / 64)]->type == solidBlock
		|| map.blocks[(int)((topPlayerEdge + 5) / 64)][(int)((rightPlayerEdge + 1) / 64)]->type == breakableBlock
		|| map.blocks[(int)((bottomPlayerEdge - 5) / 64)][(int)((rightPlayerEdge + 1) / 64)]->type == solidBlock
		|| map.blocks[(int)((bottomPlayerEdge - 5) / 64)][(int)((rightPlayerEdge + 1) / 64)]->type == breakableBlock)
	{
		this->ForbidGoingRight();
	}
	else
		this->AllowGoingRight();

	// kolizje z gora
	if (map.blocks[(int)((topPlayerEdge - 1) / 64)][(int)((leftPlayerEdge + 5) / 64)]->type == solidBlock
		|| map.blocks[(int)((topPlayerEdge - 1) / 64)][(int)((leftPlayerEdge + 5) / 64)]->type == breakableBlock
		|| map.blocks[(int)((topPlayerEdge - 1) / 64)][(int)((rightPlayerEdge - 5) / 64)]->type == solidBlock
		|| map.blocks[(int)((topPlayerEdge - 1) / 64)][(int)((rightPlayerEdge - 5) / 64)]->type == breakableBlock)
	{
		this->ForbidGoingUp();
	}
	else
		this->AllowGoingUp();

	// kolizje z dolem
	if (map.blocks[(int)((bottomPlayerEdge + 1) / 64)][(int)((leftPlayerEdge + 5) / 64)]->type == solidBlock
		|| map.blocks[(int)((bottomPlayerEdge + 1) / 64)][(int)((leftPlayerEdge + 5) / 64)]->type == breakableBlock
		|| map.blocks[(int)((bottomPlayerEdge + 1) / 64)][(int)((rightPlayerEdge - 5) / 64)]->type == solidBlock
		|| map.blocks[(int)((bottomPlayerEdge + 1) / 64)][(int)((rightPlayerEdge - 5) / 64)]->type == breakableBlock)
	{
		this->ForbidGoingDown();
	}
	else
		this->AllowGoingDown();
}

void Player::SaveToFile(bool param)
{
	std::ofstream outputFile;

	outputFile.open("res/stats/statistics.txt", std::ios_base::app);

	time_t rawtime;
	struct tm timeinfo;
	time(&rawtime);
	localtime_s(&timeinfo, &rawtime);

	if (param)
	{
		outputFile << "\n " << timeinfo.tm_mday << '.' << (timeinfo.tm_mon + 1) << '.' << (timeinfo.tm_year + 1900) << "\t\t"
			<< timeinfo.tm_hour << ":" << timeinfo.tm_min << ":" << timeinfo.tm_sec << "\n";

		outputFile << "\t" << this->name << " wins!\n";
	}

	outputFile << "\t -" << this->name << " planted " << this->bombPlaced << " bomb(s)\n";
}

void Player::SetPositionForLAN(int x, int y)
{
	position.x = x;
	position.y = y;
}

void Player::GetDataForLAN(std::string & data)
{
	data += toString(this->position.x) + ' ' + toString(this->position.y) + ' '
		+ toString(this->playerState) + ' ' + toString(this->bombLocation.x) + ' ' 
		+ toString(this->bombLocation.y) + ' ' + toString(this->IsKilled()) + '\0';
	
}

void Player::SetMovingSate(bool direction)
{
	if (direction == 0)
		this->playerState = movingLeft;
	else if (direction == 1)
		this->playerState = movingRight;
}
