#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;

class Player
{
private:
	const float START_SPEED = 200;
	const float START_HEALTH = 100;
	// Pozycja gracza
	Vector2f m_Position;
	// Duszek 
	Sprite m_Sprite;
	// Textura
	Texture m_Texture;
	// Rozdzielczo�� ekranu
	Vector2f m_Resolution;
	// Rozmiar aktualnej areny
	IntRect m_Arena;
	// Wielko�� p�ytki
	int m_TileSize;
	// W kt�rym kierunku pod��a gracz
	bool m_UpPressed;
	bool m_DownPressed;
	bool m_LeftPressed;
	bool m_RightPressed;
	// Jak du�o �ycia ma gracz
	int m_Health;
	// Maksymalna ilo�� �ycia gracza
	int m_MaxHealth;
	// Kiedy gracz zosta� ostatnio uderzony
	Time m_LastHit;
	// Pr�dko�� w px/s
	float m_Speed;
public:
	Player();
	void spawn(IntRect arena, Vector2f resolution, int tileSize);
	// Wywo�aj na pocz�tku ka�dego programu
	void resetPlayerStats();
	// Kiedy gracz zostanie uderzony
	bool hit(Time timeHit);
	// Kiedy ostatnio gracz zosta� uderzony
	Time getLastHitTime();
	// Pozycja gracza
	FloatRect getPosition();
	// �rodek tekstury gracza
	Vector2f getCenter();
	// Pod jakim k�tem znajduje si� gracz
	float getRotation();
	// Wy�lij kopi� Duszka
	Sprite getSprite();
	// Funkcje poruszania si� gracza
	void moveLeft();
	void moveRight();
	void moveUp();
	void moveDown();
	// Zatrzymaj gracza w danej pozycji
	void stopLeft();
	void stopRight();
	void stopUp();
	void stopDown();
	// Od�wie�anie raz na klatk�
	void update(float elapsedTime, Vector2i mousePosition);
	// Boost pr�dkosci
	void upgradeSpeed();
	// Dodanie graczowi �ycia
	void upgradeHealth();
	// Zwi�ksz maksymlan� ilo�� �ycia graczowi
	void increaseHealthLevel(int amount);
	// Jak du�o �ycia ma teraz gracz
	int getHealth();

};