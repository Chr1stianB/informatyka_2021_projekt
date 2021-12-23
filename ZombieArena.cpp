/*
 Temat projektu: Strzelanka Zombie
 - Do zabijania b�d� trzy rodzaje zombie. B�d� mia�y r�ne atrybuty,
 takie jak wygl�d, zdrowie i szybko��. Nazwiemy je biegaczami, tankami i
 pe�zaczami.
 - Gracz b�dzie mia� za zadanie strzela� do zombie podczas ucieczki przed nimi.
 - �wiat przesuwa si� wraz z graczem podczas wciskania przycisk�w WASD.
 - Pistolet oraz strza�y kontrolujemy za pomoc� myszki
 - Mi�dzy kolejnymi levelami gracz b�dzie wybiera� w jaki spos�b chce polepszy�
   zdolno�ci swojej postaci.
 - Gracz b�dzie m�g� podnosi� r�ne "znajd�ki" losowo pojawi�ce si� w trakcie
   gry, kt�re b�d� odnawia�y jego amunicj� lub �ycie.
 - Ka�da fala zwi�ksza rozmiar areny oraz liczebno�� zombie
*/

#include <iostream>
#include <SFML/Graphics.hpp>
#include "Player.h"
int main()
{
	// Gra bedzie zawsze w jednym z czterech stanow
	enum class State {PAUSED, LEVELING_UP, GAME_OVER, PLAYING};

	// Zaczynamy ze stanem GAME_OVER
	State state = State::GAME_OVER;

	// Pobierz rozdzielczosc ekranu i stworz okno SFML
	Vector2f resolution;
	resolution.x = VideoMode::getDesktopMode().width;
	resolution.y = VideoMode::getDesktopMode().height;

	RenderWindow window(VideoMode(resolution.x, resolution.y), "Zombie Arena", Style::Fullscreen);

	// Stworzenie View dla glownego planu w SFML
	View mainView(sf::FloatRect(0, 0, resolution.x, resolution.y));

	// Odmierzanie czasu
	Clock clock;

	// Jak dlugo stan Playing byl aktywny
	Time gameTimeTotal;

	// Pozycja myszki relatywnie do koordynatow swiata
	Vector2f mouseWorldPosition;

	// Pozycja myszki relatywnie do koordynatow ekranu
	Vector2i mouseScreenPosition;

	// Stworz instancje klasy Player
	Player player;

	// Ograniczenia areny
	IntRect arena;

	// Glowna petla
	while (window.isOpen())
	{

	}

	return 0;
} //255