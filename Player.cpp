#include "player.h"
Player::Player()
{
	m_Speed = START_SPEED;
	m_Health = START_HEALTH;
	m_MaxHealth = START_HEALTH;
	// Do³¹cza Texturê do Duszka
	m_Texture.loadFromFile("graphics/player.png");
	m_Sprite.setTexture(m_Texture);
	// Ustawia centrum Duszka w centrum
	m_Sprite.setOrigin(25, 25);
}
void Player::spawn(IntRect arena,
	Vector2f resolution,
	int tileSize)
{
	// Ustawia gracza po œrodku areny
	m_Position.x = arena.width / 2;
	m_Position.y = arena.height / 2;
	// Kopiowanie areny
	m_Arena.left = arena.left;
	m_Arena.width = arena.width;
	m_Arena.top = arena.top;
	m_Arena.height = arena.height;
	// Zapamiêtywanie jak du¿e s¹ kafelki
	m_TileSize = tileSize;
	// Zapisywanie rozdzielczoœci
	m_Resolution.x = resolution.x;
	m_Resolution.y = resolution.y;
}

void Player::resetPlayerStats()
{
	m_Speed = START_SPEED;
	m_Health = START_HEALTH;
	m_MaxHealth = START_HEALTH;
}

Time Player::getLastHitTime()
{
	return m_LastHit;
}
bool Player::hit(Time timeHit)
{
	if (timeHit.asMilliseconds()
		- m_LastHit.asMilliseconds() > 200)
	{
		m_LastHit = timeHit;
		m_Health -= 10;
		return true;
	}
	else
	{
		return false;
	}
}