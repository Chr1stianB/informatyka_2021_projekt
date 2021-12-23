/*
 Temat projektu: Strzelanka Zombie
 - Do zabijania bêd¹ trzy rodzaje zombie. Bêd¹ mia³y ró¿ne atrybuty,
 takie jak wygl¹d, zdrowie i szybkoœæ. Nazwiemy je biegaczami, tankami i
 pe³zaczami.
 - Gracz bêdzie mia³ za zadanie strzelaæ do zombie podczas ucieczki przed nimi.
 - Œwiat przesuwa siê wraz z graczem podczas wciskania przycisków WASD.
 - Pistolet oraz strza³y kontrolujemy za pomoc¹ myszki
 - Miêdzy kolejnymi levelami gracz bêdzie wybiera³ w jaki sposób chce polepszyæ
   zdolnoœci swojej postaci.
 - Gracz bêdzie móg³ podnosiæ ró¿ne "znajdŸki" losowo pojawi¹ce siê w trakcie
   gry, które bêd¹ odnawia³y jego amunicjê lub ¿ycie.
 - Ka¿da fala zwiêksza rozmiar areny oraz liczebnoœæ zombie
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