#pragma warning( disable : 4996)
#include "Camera.h"
#include <sstream>
#include "doublenumberssupport.h"
#include <cmath>
Camera::Camera(int locatoin) :_location(locatoin)
{
	
	tFStars.loadFromFile("D:/Game/Game/loc0/stars.png");
	tFpolosky.loadFromFile("D:/Game/Game/loc0/полоски.png");
	if (locatoin == 1)
	{
		tFGoru.loadFromFile("D:/Game/Game/loc0/mountain.png");
		tFPlanet.loadFromFile("D:/Game/Game/loc0/sun.png");
		tPlatform.loadFromFile("D:/Game/Game/loc0/platform.png");
		tGround.loadFromFile("D:/Game/Game/loc0/down.png");
		tStina.loadFromFile("D:/Game/Game/loc0/блок.png");
	}
	if (locatoin == 2)
	{
		tFGoru.loadFromFile("D:/Game/Game/loc1/mountain.png");
		tFPlanet.loadFromFile("D:/Game/Game/loc1/mercury.png");
		tPlatform.loadFromFile("D:/Game/Game/loc1/platform.png");
		tGround.loadFromFile("D:/Game/Game/loc1/down.png");
		tStina.loadFromFile("D:/Game/Game/loc1/блок.png");
	}
	if (locatoin == 3)
	{
		tFGoru.loadFromFile("D:/Game/Game/loc2/mountain.png");
		tFPlanet.loadFromFile("D:/Game/Game/loc2/earth.png");
		tPlatform.loadFromFile("D:/Game/Game/loc2/platform.png");
		tGround.loadFromFile("D:/Game/Game/loc2/down.png");
		tStina.loadFromFile("D:/Game/Game/loc2/блок.png");
	}
	if (locatoin == 4)
	{
		tFGoru.loadFromFile("D:/Game/Game/loc3/mountain.png");
		tFPlanet.loadFromFile("D:/Game/Game/loc3/mars.png");
		tPlatform.loadFromFile("D:/Game/Game/loc3/platform.png");
		tGround.loadFromFile("D:/Game/Game/loc3/down.png");
		tStina.loadFromFile("D:/Game/Game/loc3/блок.png");
	}
	if (locatoin == 5)
	{
		tFGoru.loadFromFile("D:/Game/Game/loc4/mountain.png");
		tFPlanet.loadFromFile("D:/Game/Game/loc4/planet.png");
		tPlatform.loadFromFile("D:/Game/Game/loc4/platform.png");
		tGround.loadFromFile("D:/Game/Game/loc4/down.png");
		tStina.loadFromFile("D:/Game/Game/loc4/блок.png");
	}
	if (locatoin == 6)
	{
		tFGoru.loadFromFile("D:/Game/Game/loc5/mountain.png");
		tFPlanet.loadFromFile("D:/Game/Game/loc5/planet.png");
		tPlatform.loadFromFile("D:/Game/Game/loc5/platform.png");
		tGround.loadFromFile("D:/Game/Game/loc5/down.png");
		tStina.loadFromFile("D:/Game/Game/loc5/блок.png");
	}
	if (locatoin == 7)
	{
		tFGoru.loadFromFile("D:/Game/Game/loc6/mountain.png");
		tFPlanet.loadFromFile("D:/Game/Game/loc6/planet.png");
		tPlatform.loadFromFile("D:/Game/Game/loc6/platform.png");
		tGround.loadFromFile("D:/Game/Game/loc6/down.png");
		tStina.loadFromFile("D:/Game/Game/loc6/блок.png");
		tFog.loadFromFile("D:/Game/Game/loc6/fog.png");
		sFog.setTexture(tFog);
		fog.push_back(Fon(sFog, 0, 200));
	}

	tRocket.loadFromFile("D:/Game/Game/rocket.png");
	sRocket.setTexture(tRocket);
	sRocket.setOrigin(215, 153);
	tCoins.loadFromFile("D:/Game/Game/zagEl/moon.png");
	tRBullet.loadFromFile("D:/Game/Game/character/RBullet.png");
	tLBullet.loadFromFile("D:/Game/Game/character/LBullet.png");
	sLBullet.setTexture(tLBullet);
	sRBullet.setTexture(tRBullet);
	sLBullet.setTextureRect(IntRect(0, 11, 24, 6));
	sRBullet.setTextureRect(IntRect(6, 11, 24, 6));
	sLBullet.setOrigin(7, 3);
	sRBullet.setOrigin(22, 3);
	sCoins.setTexture(tCoins);
	sGround.setTexture(tGround);
	sPlatform.setTexture(tPlatform);
	sFGoru.setTexture(tFGoru);
	sFStars.setTexture(tFStars);
	sFPlanet.setTexture(tFPlanet);
	sStina.setTexture(tStina);
	sFpolosky.setTexture(tFpolosky);
	sFGoru.setPosition(0, 217);
	goru.push_back(Fon(sFGoru, 0, 0));
	stars.push_back(Fon(sFStars, 0, 0));
	polosky.push_back(Fon(sFpolosky, 0, 0));

	font.loadFromFile("D:/Game/Game/9114.otf");
	text.setFont(font);
	text.setCharacterSize(40);
	text.setColor(Color::Color(168, 168, 168));

}

void Camera::draw(b2World *world, RenderWindow &window, Level *level, int score)
{
	window.clear();
	b2Vec2 pl = level->player->b2body()->GetPosition();
	offsetX = pl.x*scale - 683;
	moveFon(level);

	for (int i = 0; i < polosky.size(); i++)
	{
		window.draw(polosky[i].sprite);
	}
	for (int i = 0; i < stars.size(); i++)
	{
		window.draw(stars[i].sprite);
	}
	for (int i = 0; i < goru.size(); i++)
	{
		window.draw(goru[i].sprite);
	}
	if (_location == 7)
	{
		for (int i = 0; i < fog.size(); i++)
		{
			window.draw(fog[i].sprite);
		}
	}

	window.draw(sFPlanet);
	b2Vec2  pos = level->player->b2body()->GetPosition();
	if (drawRocket)
	{
		level->player->sprite()->setPosition(pos.x*scale - offsetX, pos.y*scale - offsetY + 1);
		window.draw(*level->player->sprite());
	}

	for (int i = 0; i < level->coins.size(); i++)
	{
		sCoins.setPosition(level->coins[i].x - offsetX, level->coins[i].y - offsetY);
		window.draw(sCoins);
	}
	for (int i = 0; i < level->ground.size(); i++)
	{
		if (level->ground[i].number == 1)
		{
			sGround.setPosition(level->ground[i].rect.left - offsetX, level->ground[i].rect.top - offsetY);
			window.draw(sGround);
		}
		if (level->ground[i].number == 2)
		{
			sPlatform.setPosition(level->ground[i].rect.left - offsetX, level->ground[i].rect.top - offsetY);
			window.draw(sPlatform);
		}
		if (level->ground[i].number == 3)
		{
			b2Vec2 posPl = level->ground[i].b2Body->GetPosition();
			sPlatform.setPosition(posPl.x*scale - level->ground[i].rect.width / 2.f - offsetX, posPl.y*scale - level->ground[i].rect.height / 2.f - offsetY);
			window.draw(sPlatform);
		}
		if (level->ground[i].number == 4)
		{
			sStina.setPosition(level->ground[i].rect.left - offsetX, level->ground[i].rect.top - offsetY);
			window.draw(sStina);
		}
	}
	for (int i = 0; i < level->bullet.size(); i++)
	{
		b2Vec2 position = level->bullet[i].b2Bullet->GetPosition();
		if (level->bullet[i].directionRignt())
		{

			sRBullet.setPosition(position.x*scale - offsetX, position.y*scale - offsetY);
			window.draw(sRBullet);
		}
		if (level->bullet[i].directionLeft())
		{
			sLBullet.setPosition(position.x*scale - offsetX, position.y*scale - offsetY);
			window.draw(sLBullet);
		}
	}
	for (int i = 0; i < level->monster.size(); i++)
	{
		b2Vec2  pos = level->monster[i]->b2body()->GetPosition();
		level->monster[i]->sprite()->setPosition(pos.x*scale - offsetX, pos.y*scale - offsetY);
		window.draw(*level->monster[i]->sprite());
	}
	if (drawRocket)
	{
		b2Vec2 positionFinal = level->b2theEnd->GetPosition();
		sRocket.setPosition(positionFinal.x*scale - offsetX, positionFinal.y*scale);
		window.draw(sRocket);
	}
	std::ostringstream _score;
	_score << score;
	text.setPosition(pos.x*scale - offsetX + 420, 30);
	text.setString("Score " + _score.str());
	window.draw(text);
	sCoins.setPosition(pos.x*scale - offsetX + 510 + _score.str().size() * 15, 33);
	window.draw(sCoins);
	if (display)
	{
		window.display();
	}
}

void Camera::moveFon(Level *level)
{
	b2Vec2 posP = level->player->b2body()->GetPosition();

	if (polosky[polosky.size() - 1].x - offsetX * 0.1f + 1363 < offsetX + 683)
	{
		polosky.push_back(Fon(sFpolosky, polosky[polosky.size() - 1].x + 1363, polosky[polosky.size() - 1].y));
	}
	if (goru[goru.size() - 1].x - offsetX * 0.2f + 1490 < offsetX + 683)
	{
		goru.push_back(Fon(sFGoru, goru[goru.size() - 1].x + 1700, goru[goru.size() - 1].y));
	}
	if (stars[stars.size() - 1].x - offsetX * 0.15f + 1608 < offsetX + 683)
	{
		stars.push_back(Fon(sFStars, stars[stars.size() - 1].x + 1608, stars[stars.size() - 1].y));
	}
	if (_location == 7)
	{
		if (fog[fog.size() - 1].x - offsetX * 0.25f + 1374 < offsetX + 683)
		{
			fog.push_back(Fon(sFog, fog[fog.size() - 1].x + 1374, fog[fog.size() - 1].y));
		}
	}
	if (polosky[0].x - offsetX * 0.1f > offsetX - 683)
	{
		polosky.emplace(polosky.begin(), Fon(sFpolosky, polosky[0].x - 1363, polosky[polosky.size() - 1].y));
	}
	if (goru[0].x - offsetX * 0.2f > offsetX - 683)
	{
		goru.emplace(goru.begin(), Fon(sFGoru, goru[0].x - 1700, goru[goru.size() - 1].y));
	}
	if (stars[0].x - offsetX * 0.15f > offsetX - 683)
	{
		stars.emplace(stars.begin(), Fon(sFStars, stars[0].x - 1608, stars[stars.size() - 1].y));
	}
	if (_location == 7)
	{
		if (fog[fog.size() - 1].x - offsetX * 0.25f + 1374 < offsetX + 683)
		{
			fog.emplace(fog.begin(), Fon(sFog, fog[0].x - 1374, fog[fog.size() - 1].y));
		}
	}
	sFPlanet.setPosition(1000-offsetX*0.04f, 0);
	for (int i = 0; i < polosky.size(); i++)
	{
		polosky[i].sprite.setPosition(polosky[i].x - (offsetX * 0.1f), polosky[i].y);
	}
	for (int i = 0; i < stars.size(); i++)
	{
		stars[i].sprite.setPosition(stars[i].x - (offsetX * 0.15f), stars[i].y);
	}
	for (int i = 0; i < goru.size(); i++)
	{
		goru[i].sprite.setPosition(goru[i].x - (offsetX * 0.2f), goru[i].y);
	}
	if (_location == 7)
	{
		for (int i = 0; i < fog.size(); i++)
		{
			fog[i].sprite.setPosition(fog[i].x - (offsetX * 0.25f), fog[i].y);
		}
	}

}

Camera::~Camera()
{
}
