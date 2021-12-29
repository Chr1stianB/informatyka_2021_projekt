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
	enum class State { PAUSED, LEVELING_UP, GAME_OVER, PLAYING };

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
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::KeyPressed)
			{
				// Zapauzuj gre jezli w trakcie
				if (event.key.code == Keyboard::Return &&
					state == State::PLAYING)
				{
					state = State::PAUSED;
				}
				// zrestartuj jezeli zapauzowana
				else if (event.key.code == Keyboard::Return &&
					state == State::PAUSED)
				{
					state = State::PLAYING;
					// Resetowanie zegara
					clock.restart();
				}
				// Rozpicznij nowa gre jezeli w trybie GAME_OVER
				else if (event.key.code == Keyboard::Return && state == State::GAME_OVER)
				{
					state = State::LEVELING_UP;
				}
				if (state == State::PLAYING)
				{
					;
				}
			}
		} // Koniec event pooling
		// Gracz wychodzi po wcisnieciu ESC
		if (Keyboard::isKeyPressed(Keyboard::Escape))
		{
			window.close();
		}
		// Kontrolowanie ruchu z klawiatury
		if (state == State::PLAYING)
		{
			if (Keyboard::isKeyPressed(Keyboard::W))
			{
				player.moveUp();
			}
			else
			{
				player.stopUp();
			}
			if (Keyboard::isKeyPressed(Keyboard::S))
			{
				player.moveDown();
			}
			else
			{
				player.stopDown();
			}
			if (Keyboard::isKeyPressed(Keyboard::A))
			{
				player.moveLeft();
			}
			else
			{
				player.stopLeft();
			}
			if (Keyboard::isKeyPressed(Keyboard::D))
			{
				player.moveRight();
			}
			else
			{
				player.stopRight();
			}
		} // Zakonczenie instrukcji sterujacych WASD
		// Stan LEVELING_UP
		if (state == State::LEVELING_UP)
		{
			if (event.key.code == Keyboard::Num1)
			{
				state = State::PLAYING;
			}
			if (event.key.code == Keyboard::Num2)
			{
				state = State::PLAYING;
			}
			if (event.key.code == Keyboard::Num3)
			{
				state = State::PLAYING;
			}
			if (event.key.code == Keyboard::Num4)
			{
				state = State::PLAYING;
			}
			if (event.key.code == Keyboard::Num5)
			{
				state = State::PLAYING;
			}
			if (event.key.code == Keyboard::Num6)
			{
				state = State::PLAYING;
			}
			if (state == State::PLAYING)
			{
				// Przygotowanie poziomu 
				arena.width = 500;
				arena.height = 500;
				arena.left = 0;
				arena.top = 0;

				int tileSize = 50;
				player.spawn(arena, resolution, tileSize);
				clock.restart();
			}
		} // Koniec PETLI LEVELING_UP
		if (state == State::PLAYING)
		{
			// Aktualizajca czasu
			Time dt = clock.restart();

			// Aktualizacja calkowiteg czasu gry
			gameTimeTotal += dt;

			// Zaokraglij czas gry
			float dtAsSeconds = dt.asSeconds();

			// Gdzie jest wskaznik myszy
			mouseScreenPosition = Mouse::getPosition();

			// Konwertuj polozenie myszy na koorydnaty swiata z mainView
			mouseWorldPosition = window.mapPixelToCoords(Mouse::getPosition(), mainView);

			// Aktualizuj gracza
			player.update(dtAsSeconds, Mouse::getPosition());

			// Zapisz nowa pozycje gracza
			Vector2f playerPosition(player.getCenter());

			// Wysrodkuj View dookola gracza
			mainView.setCenter(player.getCenter());
		}// Koniec updaetowania sceny
		if (state == State::PLAYING)
		{
			window.clear();
			window.setView(mainView);
			window.draw(player.getSprite());
		}
		if (state == State::LEVELING_UP)
		{

		}
		if (state == State::PAUSED)
		{

		}
		if (state == State::GAME_OVER)
		{

		}
		window.display();
	} // Koniec glownej petli

	return 0;
}