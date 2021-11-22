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
	// Rozdzielczoœæ ekranu
	Vector2f m_Resolution;
	// Rozmiar aktualnej areny
	IntRect m_Arena;
	// Wielkoœæ p³ytki
	int m_TileSize;
	// W którym kierunku pod¹¿a gracz
	bool m_UpPressed;
	bool m_DownPressed;
	bool m_LeftPressed;
	bool m_RightPressed;
	// Jak du¿o ¿ycia ma gracz
	int m_Health;
	// Maksymalna iloœæ ¿ycia gracza
	int m_MaxHealth;
	// Kiedy gracz zosta³ ostatnio uderzony
	Time m_LastHit;
	// Prêdkoœæ w px/s
	float m_Speed;
public:
	Player();
	void spawn(IntRect arena, Vector2f resolution, int tileSize);
	// Wywo³aj na pocz¹tku ka¿dego programu
	void resetPlayerStats();
	// Kiedy gracz zostanie uderzony
	bool hit(Time timeHit);
	// Kiedy ostatnio gracz zosta³ uderzony
	Time getLastHitTime();
	// Pozycja gracza
	FloatRect getPosition();
	// Œrodek tekstury gracza
	Vector2f getCenter();
	// Pod jakim k¹tem znajduje siê gracz
	float getRotation();
	// Wyœlij kopiê Duszka
	Sprite getSprite();
	// Funkcje poruszania siê gracza
	void moveLeft();
	void moveRight();
	void moveUp();
	void moveDown();
	// Zatrzymaj gracza w danej pozycji
	void stopLeft();
	void stopRight();
	void stopUp();
	void stopDown();
	// Odœwie¿anie raz na klatkê
	void update(float elapsedTime, Vector2i mousePosition);
	// Boost prêdkosci
	void upgradeSpeed();
	// Dodanie graczowi ¿ycia
	void upgradeHealth();
	// Zwiêksz maksymlan¹ iloœæ ¿ycia graczowi
	void increaseHealthLevel(int amount);
	// Jak du¿o ¿ycia ma teraz gracz
	int getHealth();

};