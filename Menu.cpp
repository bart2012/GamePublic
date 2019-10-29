#include "Menu.h"

#include <fstream>


Menu::Menu(sf::RenderWindow &window, std::string type):type(type)
{

	if (type == "main")
	{
		tBExittoMainMenu.loadFromFile("D:/Game/Game/menu/pause/exittomaimmenu.png");
		sBExittoMainMenu.setTexture(tBExittoMainMenu);

		tFon.loadFromFile("D:/Game/Game/menu/main/background.png");
		tBNewGame.loadFromFile("D:/Game/Game/menu/main/нова гра.png");
		tBExit.loadFromFile("D:/Game/Game/menu/main/вийти.png");
		tBlvl.loadFromFile("D:/Game/Game/menu/main/обратирівень.png");
		tBSettings.loadFromFile("D:/Game/Game/menu/main/налаштування.png");

		tBMusicOn.loadFromFile("D:/Game/Game/menu/settings/mon.png");
		tBMusicOff.loadFromFile("D:/Game/Game/menu/settings/moff.png");
		tBSoundOn.loadFromFile("D:/Game/Game/menu/settings/son.png");
		tBSoundOff.loadFromFile("D:/Game/Game/menu/settings/soff.png");

		tBLoc1.loadFromFile("D:/Game/Game/menu/level/1.png");
		tBLoc2.loadFromFile("D:/Game/Game/menu/level/2.png");
		tBLoc3.loadFromFile("D:/Game/Game/menu/level/3.png");
		tBLoc4.loadFromFile("D:/Game/Game/menu/level/4.png");
		tBLoc5.loadFromFile("D:/Game/Game/menu/level/5.png");
		tBLoc6.loadFromFile("D:/Game/Game/menu/level/6.png");
		tBLoc7.loadFromFile("D:/Game/Game/menu/level/7.png");

		BExittoMainMenu.left = 535;
		BExittoMainMenu.top = 660;
		BExittoMainMenu.width = 315;
		BExittoMainMenu.height = 71;
		sBExittoMainMenu.setPosition(BExittoMainMenu.left, BExittoMainMenu.top);

		sBLoc1.setTexture(tBLoc1);
		sBLoc2.setTexture(tBLoc2);
		sBLoc3.setTexture(tBLoc3);
		sBLoc4.setTexture(tBLoc4);
		sBLoc5.setTexture(tBLoc5);
		sBLoc6.setTexture(tBLoc6);
		sBLoc7.setTexture(tBLoc7);

		BLoc1.left = 148;
		BLoc1.top = 151;
		BLoc1.width = 180;
		BLoc1.height = 227;
		sBLoc1.setPosition(BLoc1.left, BLoc1.top);

		BLoc2.left = 374;
		BLoc2.top = 151;
		BLoc2.width = 180;
		BLoc2.height = 227;
		sBLoc2.setPosition(BLoc2.left, BLoc2.top);

		BLoc3.left = 593;
		BLoc3.top = 151;
		BLoc3.width = 180;
		BLoc3.height = 227;
		sBLoc3.setPosition(BLoc3.left, BLoc3.top);

		BLoc4.left = 805;
		BLoc4.top = 151;
		BLoc4.width = 180;
		BLoc4.height = 227;
		sBLoc4.setPosition(BLoc4.left, BLoc4.top);

		BLoc5.left = 1015;
		BLoc5.top = 151;
		BLoc5.width = 188;
		BLoc5.height = 227;
		sBLoc5.setPosition(BLoc5.left, BLoc5.top);

		BLoc6.left = 475;
		BLoc6.top = 418;
		BLoc6.width = 180;
		BLoc6.height = 227;
		sBLoc6.setPosition(BLoc6.left, BLoc6.top);

		BLoc7.left = 723;
		BLoc7.top = 418;
		BLoc7.width = 180;
		BLoc7.height = 227;
		sBLoc7.setPosition(BLoc7.left, BLoc7.top);

		sBMusicOff.setTexture(tBMusicOff);
		sBMusicOn.setTexture(tBMusicOn);
		sBSoundOff.setTexture(tBSoundOff);
		sBSoundOff.setTexture(tBSoundOn);

		sFon.setTexture(tFon);
		sBNewGame.setTexture(tBNewGame);
		sBExit.setTexture(tBExit);
		sBlvl.setTexture(tBlvl);
		sBSettings.setTexture(tBSettings);

		sBSoundOn.setTexture(tBSoundOn);
		sBSoundOff.setTexture(tBSoundOff);
		sBMusicOn.setTexture(tBMusicOn);
		sBMusicOff.setTexture(tBMusicOff);

		BNewGame.left = 1366 / 2.f - 392 / 2.f;
		BNewGame.top = 300;
		BNewGame.width = 393;
		BNewGame.height = 89;
		sBNewGame.setPosition(BNewGame.left, BNewGame.top);

		Blvl.left = 1366 / 2.f - 392 / 2.f;
		Blvl.top = 400;
		Blvl.width = 393;
		Blvl.height = 89;
		sBlvl.setPosition(Blvl.left, Blvl.top);

		BSettings.left = 1366 / 2.f - 392 / 2.f;
		BSettings.top = 500;
		BSettings.width = 393;
		BSettings.height = 89;
		sBSettings.setPosition(BSettings.left, BSettings.top);

		BExit.left = 1366 / 2.f - 392 / 2.f;
		BExit.top = 600;
		BExit.width = 393;
		BExit.height = 89;
		sBExit.setPosition(BExit.left, BExit.top);

		BSoundOn.left = 1366 / 2.f - 574 / 2.f;
		BSoundOn.top = 200;
		BSoundOn.width = 575;
		BSoundOn.height = 99;
		sBSoundOn.setPosition(BSoundOn.left, BSoundOn.top);

		BSoundOff.left = 1366 / 2.f - 574 / 2.f;
		BSoundOff.top = 200;
		BSoundOff.width = 575;
		BSoundOff.height = 99;
		sBSoundOff.setPosition(BSoundOff.left, BSoundOff.top);

		BMusicOn.left = 1366 / 2.f - 574 / 2.f;
		BMusicOn.top = 350;
		BMusicOn.width = 575;
		BMusicOn.height = 99;
		sBMusicOn.setPosition(BMusicOn.left, BMusicOn.top);

		BMusicOff.left = 1366 / 2.f - 574 / 2.f;
		BMusicOff.top = 350;
		BMusicOff.width = 575;
		BMusicOff.height = 99;
		sBMusicOff.setPosition(BMusicOff.left, BMusicOff.top);

		activeButton.push_back(Button(sBNewGame, "newD:/Game", BNewGame));
		activeButton.push_back(Button(sBlvl, "lvl", Blvl));
		activeButton.push_back(Button(sBSettings, "settings", BSettings));
		activeButton.push_back(Button(sBExit, "exit", BExit));
	}
	if (type == "pause")
	{
		tZat.loadFromFile("D:/Game/Game/menu/pause/zat.png");
		tBContinue.loadFromFile("D:/Game/Game/menu/pause/continue.png");
		tBExittoMainMenu.loadFromFile("D:/Game/Game/menu/pause/exittomaimmenu.png");
		sZat.setTexture(tZat);
		sBPNewGame.setTexture(tBPNewGame);
		sBContinue.setTexture(tBContinue);
		sBExittoMainMenu.setTexture(tBExittoMainMenu);

		BContinue.left = 520;
		BContinue.top = 400;
		BContinue.width = 316;
		BContinue.height = 71;
		sBContinue.setPosition(BContinue.left, BContinue.top);

		BExittoMainMenu.left = 520;
		BExittoMainMenu.top = 500;
		BExittoMainMenu.width = 315;
		BExittoMainMenu.height = 71;
		sBExittoMainMenu.setPosition(BExittoMainMenu.left, BExittoMainMenu.top);
		activeButton.push_back(Button(sBContinue, "Continue", BContinue));
		activeButton.push_back(Button(sBExittoMainMenu, "ExitToMainMenu", BExittoMainMenu));
	}
	if (type == "los")
	{
		tFon.loadFromFile("D:/Game/Game/menu/los/fon.png");
		sFon.setTexture(tFon);
		tText.loadFromFile("D:/Game/Game/menu/los/text.png");
		sText.setTexture(tText);
		sText.setPosition(320, 100);
		tRestart.loadFromFile("D:/Game/Game/menu/los/restart.png");
		sRestart.setTexture(tRestart);
		Restart.left = 520;
		Restart.top = 400;
		Restart.width = 318;
		Restart.height = 73;
		sRestart.setPosition(Restart.left, Restart.top);
		activeButton.push_back(Button(sRestart, "restart", Restart));
	}

}

bool Menu::finalLoad(Game *Game, int level,sf::SoundBuffer *sound)
{
	if (Game->level->maxCoins * 80 <= Game->score)
	{
		sound->loadFromFile("D:/Game/Game/soung/finalLevel.ogg");
		tFon.loadFromFile("D:/Game/Game/menu/final/+.png");
		sFon.setTexture(tFon);
		tBExittoMainMenu.loadFromFile("D:/Game/Game/menu/pause/exittomaimmenu.png");
		sBExittoMainMenu.setTexture(tBExittoMainMenu);
		BExittoMainMenu.left = 920;
		BExittoMainMenu.top = 500;
		BExittoMainMenu.width = 315;
		BExittoMainMenu.height = 71;
		sBExittoMainMenu.setPosition(BExittoMainMenu.left, BExittoMainMenu.top);
		activeButton.push_back(Button(sBExittoMainMenu, "ExitToMainMenu", BExittoMainMenu));
		std::ifstream file("D:/Game/Game/lvl.txt");
		int i;
		file >> i;
		file.close();
		if (i < level + 1)
		{
			std::ofstream file("D:/Game/Game/lvl.txt");
			file << level + 1;
			file.close();
		}
		return true;
	}
	else
	{
		sound->loadFromFile("D:/Game/Game/soung/breath.ogg");
		tFon.loadFromFile("D:/Game/Game/menu/final/-.png");
		sFon.setTexture(tFon);
		tRestart.loadFromFile("D:/Game/Game/menu/los/restart.png");
		sRestart.setTexture(tRestart);
		Restart.left = 194;
		Restart.top = 551;
		Restart.width = 318;
		Restart.height = 73;
		sRestart.setPosition(Restart.left, Restart.top);
		activeButton.push_back(Button(sRestart, "restart", Restart));

		return false;
	}
}


void Menu::draw(sf::RenderWindow &window)
{
	if (type == "main"||type=="los"||type=="final")
	{
		window.clear();
		window.draw(sFon);
	}
	if (type == "los")
	{
		window.draw(sText);
	}
	if (type == "pause")
	{
		window.draw(sZat);
	}
	for (int i = 0; i < activeButton.size(); i++)
	{
		window.draw(activeButton[i].sprite);
	}
	window.display();
}

bool Menu::kliked(sf::RenderWindow &window, sf::Sound *click, bool &soundOn, bool &musicOn)
{
	if (!flag)
	{
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			sf::Vector2i posMouse = sf::Mouse::getPosition();
			sf::Vector2i posWindow = window.getPosition();
			posWindow.y += 29;
			posWindow.x += 8;
			for (int i = 0; i < activeButton.size(); i++)
			{
				if (posMouse.x - posWindow.x > activeButton[i].rect.left && posMouse.x - posWindow.x < activeButton[i].rect.left + activeButton[i].rect.width && posMouse.y - posWindow.y> activeButton[i].rect.top && posMouse.y - posWindow.y < activeButton[i].rect.top + activeButton[i].rect.height)
				{
					if (soundOn)
					{
						click->play();
					}
					if (type == "main")
					{
						if (activeButton[i].name == "newGame")
						{
							Texture image;
							image.loadFromFile("D:/Game/Game/history/1.png");
							Sprite sImage(image);
							int n = 1;
							Texture button;
							button.loadFromFile("D:/Game/Game/history/button.png");
							Sprite sButton(button);
							sButton.setPosition(617, 690);
							while (true)
							{
								if (sf::Mouse::isButtonPressed(sf::Mouse::Left)&&!flag)
								{
									sf::Vector2i posMouse = sf::Mouse::getPosition();
									sf::Vector2i posWindow = window.getPosition();
									posWindow.y += 29;
									posWindow.x += 8;
									if (posMouse.x - posWindow.x > 617 && posMouse.x - posWindow.x < 617 + 197 && posMouse.y - posWindow.y> 690 && posMouse.y - posWindow.y < 690 + 48)
									{
										n++;
										if (n == 2)
										{
											image.loadFromFile("D:/Game/Game/history/2.png");
										}
										if (n == 3)
										{
											image.loadFromFile("D:/Game/Game/history/3.png");
										}
										if (n == 4)
										{
											image.loadFromFile("D:/Game/Game/history/4.png");
										}
										if (n == 5)
										{
											image.loadFromFile("D:/Game/Game/history/5.png");
										}
										if (n > 5)
										{
											break;
										}
										flag = true;
									}
									window.clear();
									window.draw(sImage);
									window.draw(sButton);
									window.display();
								}
								else
								{
									flag = false;
								}
							}
							std::ofstream file("D:/Game/Game/lvl.txt");
							int i = 1;
							file << i;
							file.close();
							return true;
						}
						if (activeButton[i].name == "lvl")
						{

							activeButton.clear();
							int i = 0;
							std::ifstream file("D:/Game/Game/lvl.txt");
							file >> i;
							activeButton.push_back(Button(sBExittoMainMenu, "ExitToMainMenu", BExittoMainMenu));
							activeButton.push_back(Button(sBLoc1, "lvl1", BLoc1));
							if (i >= 2)
							{
								activeButton.push_back(Button(sBLoc2, "lvl2", BLoc2));
								if (i >= 3)
								{
									activeButton.push_back(Button(sBLoc3, "lvl3", BLoc3));
									if (i >= 4)
									{
										activeButton.push_back(Button(sBLoc4, "lvl4", BLoc4));
										if (i >= 5)
										{
											activeButton.push_back(Button(sBLoc5, "lvl5", BLoc5));
											if (i >= 6)
											{
												activeButton.push_back(Button(sBLoc6, "lvl6", BLoc6));
												if (i >= 7)
												{
													activeButton.push_back(Button(sBLoc7, "lvl7", BLoc7));
												}
											}
										}
									}
								}
							}
							flag = true;
							break;
						}
						if (activeButton[i].name == "settings")
						{
							activeButton.clear();
							if (soundOn)
							{
								activeButton.push_back(Button(sBSoundOn, "soundOn", BSoundOn));
							}
							else
							{
								activeButton.push_back(Button(sBSoundOff, "soundOff", BSoundOff));
							}
							if (musicOn)
							{
								activeButton.push_back(Button(sBMusicOn, "musicOn", BMusicOn));
							}
							else
							{
								activeButton.push_back(Button(sBMusicOff, "musicOff", BMusicOff));
							}
							activeButton.push_back(Button(sBExittoMainMenu, "ExitToMainMenu", BExittoMainMenu));
							flag = true;
							break;
						}
						if (activeButton[i].name == "soundOn"|| activeButton[i].name == "soundOff")
						{
							soundOn = !soundOn;
							activeButton.clear();
							if (soundOn)
							{
								activeButton.push_back(Button(sBSoundOn, "soundOn", BSoundOn));
							}
							else
							{
								activeButton.push_back(Button(sBSoundOff, "soundOff", BSoundOff));
							}
							if (musicOn)
							{
								activeButton.push_back(Button(sBMusicOn, "musicOn", BMusicOn));
							}
							else
							{
								activeButton.push_back(Button(sBMusicOff, "musicOff", BMusicOff));
							}
							activeButton.push_back(Button(sBExittoMainMenu, "ExitToMainMenu", BExittoMainMenu));
							flag = true;
							break;
						}
						if (activeButton[i].name == "musicOn" || activeButton[i].name == "musicOff")
						{
							musicOn = !musicOn;
							activeButton.clear();
							if (soundOn)
							{
								activeButton.push_back(Button(sBSoundOn, "soundOn", BSoundOn));
							}
							else
							{
								activeButton.push_back(Button(sBSoundOff, "soundOff", BSoundOff));
							}
							if (musicOn)
							{
								activeButton.push_back(Button(sBMusicOn, "musicOn", BMusicOn));
							}
							else
							{
								activeButton.push_back(Button(sBMusicOff, "musicOff", BMusicOff));
							}
							activeButton.push_back(Button(sBExittoMainMenu, "ExitToMainMenu", BExittoMainMenu));
							flag = true;
							break;
						}
						if (activeButton[i].name == "exit")
						{
							window.close();
						}
						if (activeButton[i].name == "lvl1")
						{
							Texture image;
							image.loadFromFile("D:/Game/Game/history/1.png");
							Sprite sImage(image);
							int n = 1;
							Texture button;
							button.loadFromFile("D:/Game/Game/history/button.png");
							Sprite sButton(button);
							sButton.setPosition(617, 690);
							while (true)
							{
								if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && !flag)
								{
									sf::Vector2i posMouse = sf::Mouse::getPosition();
									sf::Vector2i posWindow = window.getPosition();
									posWindow.y += 29;
									posWindow.x += 8;
									if (posMouse.x - posWindow.x > 617 && posMouse.x - posWindow.x < 617 + 197 && posMouse.y - posWindow.y> 690 && posMouse.y - posWindow.y < 690 + 48)
									{
										n++;
										if (n == 2)
										{
											image.loadFromFile("D:/Game/Game/history/2.png");
										}
										if (n == 3)
										{
											image.loadFromFile("D:/Game/Game/history/3.png");
										}
										if (n == 4)
										{
											image.loadFromFile("D:/Game/Game/history/4.png");
										}
										if (n == 5)
										{
											image.loadFromFile("D:/Game/Game/history/5.png");
										}
										if (n > 5)
										{
											break;
										}
										flag = true;
									}
									window.clear();
									window.draw(sImage);
									window.draw(sButton);
									window.display();
								}
								else
								{
									flag = false;
								}
							}
							startLevel = 1;
							return true;
						}
						if (activeButton[i].name == "lvl2")
						{
							startLevel = 2;
							return true;
						}
						if (activeButton[i].name == "lvl3")
						{
							startLevel = 3;
							return true;
						}
						if (activeButton[i].name == "lvl4")
						{
							startLevel = 4;
							return true;
						}
						if (activeButton[i].name == "lvl5")
						{
							startLevel = 5;
							return true;
						}
						if (activeButton[i].name == "lvl6")
						{
							startLevel = 6;
							return true;
						}
						if (activeButton[i].name == "lvl7")
						{
							startLevel = 7;
							return true;
						}
						if (activeButton[i].name == "ExitToMainMenu")
						{
							activeButton.clear();
							activeButton.push_back(Button(sBNewGame, "newD:/Game", BNewGame));
							activeButton.push_back(Button(sBlvl, "lvl", Blvl));
							activeButton.push_back(Button(sBSettings, "settings", BSettings));
							activeButton.push_back(Button(sBExit, "exit", BExit));
							flag = true;
							break;
						}
					}
					if (type == "pause"||type=="final")
					{
						if (activeButton[i].name == "Continue")
						{
							return true;
						}
						if (activeButton[i].name == "ExitToMainMenu")
						{
							ExitToMenu = true;
							return true;
						}
					}
					if (type == "los" || type == "final")
					{
						if (activeButton[i].name == "restart")
						{
							return true;
						}
					}
					break;
					flag = true;
				}
			}
		}
	}
	if (!sf::Mouse::isButtonPressed(sf::Mouse::Left) && flag)
	{
		flag = false;
	}
	return false;
}


Menu::~Menu()
{
}
