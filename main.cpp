#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <windows.h>
#include "Box2D/Box2D.h"
#include <vector>
#include <conio.h>
#include <string>
#include <iostream>
#include "Level.h"
#include "Menu.h"
#include "Game.h"
#include "Camera.h"

using namespace sf;


int main()
{
	bool musicOn = true;
	bool soundOn = true;
	int level=0;
	b2World *world = nullptr;
	RenderWindow window(VideoMode(1366, 768), "MoonLight");
	Camera *camera = nullptr;
	Game *Game = nullptr;
	Menu *menu = new Menu(window, "main");
	b2Timer time;
	bool play = false;
	Music music;
 	music.openFromFile("D:/Game/Game/soung/music.ogg");
	music.play();
	music.setLoop(true);
	SoundBuffer buffer;
	Sound *click=new Sound();
	SoundBuffer *finalSoundB = new SoundBuffer();
	buffer.loadFromFile("D:/Game/Game/soung/click.ogg");
	click->setBuffer(buffer);
	Sound finalSound;
	SoundBuffer buf;
	buf.loadFromFile("D:/Game/Game/soung/breath.ogg");
	Sound los(buf);
	{
		Texture texture;
		texture.loadFromFile("D:/Game/Game/history/logo.png");
		Sprite sprite(texture);
		window.draw(sprite);
		window.display();
		Sleep(5000);
	}
	while (window.isOpen())
	{
		Event e;
		while (window.pollEvent(e));
		{
			if (e.type == Event::Closed)
				window.close();
		}
		if (play)
		{
			if (!Game->pause)
			{
				Game->logic(world);
				world->Step(1 / 60.f, 8, 3);
				camera->draw(world, window, Game->level, Game->score);
			}
			if (Game->pause&&menu == nullptr)
			{
				menu = new Menu(window, "pause");
				camera->display = false;
			}
			if (Game->pause)
			{
				camera->draw(world, window, Game->level, Game->score);
				menu->draw(window);
				if (menu->kliked(window, click, soundOn, musicOn))
				{
					Game->pause = false;
					camera->display = true;
					if (menu->ExitToMenu)
					{
						play = false;
						delete Game;
						Game = nullptr;
						delete world;
						world = nullptr;
					}
					delete menu; 
					menu = nullptr;
				}		
			}	
			if (Game!=nullptr&&!Game->game)
			{
				if (menu == nullptr)
				{
					menu = new Menu(window, "los");		
					if (soundOn)
					{
						los.play();
					}
					delete Game;
					Game = nullptr;
					delete world;
					world = nullptr;
					play = false;
				}
			}
			if (Game != nullptr&&Game->theEnd(world,window,camera))
			{
				menu = new Menu(window, "final");
				if (menu->finalLoad(Game, level, finalSoundB) && level == 7)
				{
					Texture image;
					image.loadFromFile("D:/Game/Game/history/complid.png");
					Sprite sImage(image);
					int n = 1;
					Texture button;
					button.loadFromFile("D:/Game/Game/history/button.png");
					Sprite sButton(button);
					sButton.setPosition(617, 690);
					window.clear();
					window.draw(sImage);
					window.draw(sButton);
					window.display();
					while (true)
					{
						if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
						{
							sf::Vector2i posMouse = sf::Mouse::getPosition();
							sf::Vector2i posWindow = window.getPosition();
							posWindow.y += 29;
							posWindow.x += 8;
							if (posMouse.x - posWindow.x > 617 && posMouse.x - posWindow.x < 617 + 197 && posMouse.y - posWindow.y> 690 && posMouse.y - posWindow.y < 690 + 48)
							{
								break;
							}
						}
					}
				}
				finalSound.setBuffer(*finalSoundB);
				if (soundOn)
				{
					finalSound.play();
				}
				delete Game;
				delete world;
				world = nullptr;
				Game = nullptr;
				play = false;
				camera->drawRocket = true;
			}
		}
		if (!play)
		{
			if (menu == nullptr)
			{
				menu = new Menu(window, "main");
			}
			if (menu->type == "final")
			{
				if (menu->kliked(window, click,soundOn,musicOn) && menu->ExitToMenu)
				{
					delete menu;
					menu = nullptr;
					menu = new Menu(window, "main");
				}
			}
			menu->draw(window);
			if (menu->kliked(window, click, soundOn, musicOn)&&!menu->ExitToMenu)
			{
				if (menu->type == "main")
				{
					level = menu->startLevel;
					camera = new Camera(menu->startLevel);
				}
				play = true;
				delete menu;
				menu = nullptr;
				world = new b2World(b2Vec2(0.f, 3.f));
				Game = new class Game(world, level);
			}

		}
		if (!musicOn)
		{
			music.stop();
		}
		if (musicOn && !music.getStatus())
		{
			music.play();
		}
		time.Reset();
	}
	return 0;
}