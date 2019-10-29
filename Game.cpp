#include "Game.h"
#include "doublenumberssupport.h"
#include <SFML/Graphics.hpp>


Game::Game(b2World *world, int location): location(location)
{
	level = new Level(world, location);
	soundCoinBuf.loadFromFile("D:/Game/Game/soung/coin.ogg");
	soundCoin.setBuffer(soundCoinBuf);
}

void Game::keyPressed(b2World *world)
{
	if (Keyboard::isKeyPressed(Keyboard::D))
	{
		level->player->goRight();
	}
	if (Keyboard::isKeyPressed(Keyboard::A))
	{
		level->player->goLeft();
	}
	if (Keyboard::isKeyPressed(Keyboard::Space) && level->player->canJump())
	{
		level->player->jump();
	}
	b2Vec2 speedP = level->player->b2body()->GetLinearVelocity();
	if (!Keyboard::isKeyPressed(Keyboard::D) && !Keyboard::isKeyPressed(Keyboard::A)&& !DoubleCompare::fuzzyIsNull(speedP.x))
	{
		level->player->gorisontalMoveStop();
	}
	if (Keyboard::isKeyPressed(Keyboard::RControl)&&canShoot&&level->player->havePistol)
	{
		level->player->pistol(world, level->bullet);
		canShoot = false;
	}
	if (!canShoot&&!Keyboard::isKeyPressed(Keyboard::RControl))
	{
		canShoot = true;
	}
	if (Keyboard::isKeyPressed(Keyboard::Escape)&&!pause)
	{
		pause = true;
	}
}

void Game::logic(b2World *world)
{
		if (level->player->time.GetMilliseconds() > 1000)
		{
			level->player->setFirstCadr();
		}
		keyPressed(world);
		logicBullet(world);
		logicCoin(world);
		logicMoveLPlatrotm();
		logicChasm();
		for (int i = 0; i < level->monster.size(); i++)
		{
			if (level->monster[i]->reaction(level->player))
			{
				level->monster[i]->pistol(world, level->bullet);
			}
			else
			{
				level->monster[i]->update();
			}
		}
}

void Game::logicCoin(b2World *world)
{
	for (b2ContactEdge *ContactList = level->player->b2body()->GetContactList(); ContactList != nullptr; ContactList = ContactList->next)
	{
		for (int i = 0; i < level->coins.size(); i++)
		{
			if (ContactList->other == level->coins[i].b2Coins&&ContactList->contact->IsTouching())
			{
				world->DestroyBody(level->coins[i].b2Coins);
				score += 100;
				std::cout << score << std::endl;
				level->coins.erase(level->coins.begin() + i);
				i--;
				ContactList = level->player->b2body()->GetContactList();
				soundCoin.play();
				break;
			}
		}
		if (ContactList == nullptr)
			break;
	}
}

void Game::logicMoveLPlatrotm()
{
	for (int i = 0; i < level->ground.size(); i++)
	{
		if (level->ground[i].number == 3)
		{
			b2Vec2 pos = level->ground[i].b2Body->GetPosition();
			if (level->ground[i].vector == 'v' && (pos.y*scale - level->ground[i].rect.height / 2.f <= level->ground[i].t1 || pos.y*scale + level->ground[i].rect.height / 2.f >= level->ground[i].t2))
			{
				b2Vec2  Velocity = level->ground[i].b2Body->GetLinearVelocity();
				level->ground[i].b2Body->SetLinearVelocity(-Velocity);
			}
			if (level->ground[i].vector == 'b' && (pos.x*scale - level->ground[i].rect.width / 2.f <= level->ground[i].t1 || pos.x*scale + level->ground[i].rect.width / 2.f >= level->ground[i].t2))
			{
				b2Vec2  Velocity = level->ground[i].b2Body->GetLinearVelocity();
				level->ground[i].b2Body->SetLinearVelocity(-Velocity);
			}
		}
	}

}

void Game::logicChasm()
{
	for (int i = 0; i < level->ground.size(); i++)
	{
		if (level->ground[i].number == 7)
		{
			for (b2ContactEdge *ContactList = level->ground[i].b2Body->GetContactList(); ContactList != nullptr; ContactList = ContactList->next)
				if (ContactList->other == level->player->b2body())
				{
					game = false;
				}
		}
	}
}

void Game::logicBullet(b2World *world)
{
	for (int i = 0; i < level->bullet.size(); i++)
	{
		b2Vec2 posBullet = level->bullet[i].b2Bullet->GetPosition();
		b2Vec2 posPlayer = level->player->b2body()->GetPosition();
		posBullet.x *= scale;
		posBullet.y *= scale;
		posPlayer.x *= scale;
		posPlayer.y *= scale;
		if (posBullet.x > posPlayer.x + 700 || posBullet.x < posPlayer.x - 700)
		{
			world->DestroyBody(level->bullet[i].b2Bullet);
			level->bullet.erase(level->bullet.begin() + i);
			i--;
			break;
		}
		for (b2ContactEdge *ContactList = level->bullet[i].b2Bullet->GetContactList(); ContactList != nullptr; ContactList = ContactList->next)
		{
			if (ContactList->other == level->player->b2body() && ContactList->contact->IsTouching())
			{
				world->DestroyBody(level->bullet[i].b2Bullet);
				level->bullet.erase(level->bullet.begin() + i);
				i--;
				game = false;
				break;
			}
			for (int j = 0; j < level->monster.size(); j++)
			{
				if (ContactList->other == level->monster[j]->b2body() && ContactList->contact->IsTouching())
				{
					world->DestroyBody(level->bullet[i].b2Bullet);
					world->DestroyBody(level->monster[j]->b2body());
					level->bullet.erase(level->bullet.begin() + i);
					level->monster.erase(level->monster.begin() + j);
					ContactList->other =  nullptr;
					i--;
					break;
				}
			}
			if (ContactList->other == nullptr)
				break;
			for (int j = 0; j < level->bullet.size(); j++)
			{
				if (i!=j&&ContactList->other == level->bullet[j].b2Bullet && ContactList->contact->IsTouching())
				{
					world->DestroyBody(level->bullet[i].b2Bullet);
					world->DestroyBody(level->bullet[j].b2Bullet);
					level->bullet.erase(level->bullet.begin() + i);
					level->bullet.erase(level->bullet.begin() + j-1);
					ContactList->other = nullptr;
					i--;
					break;
				}
			}			
			if (ContactList->other == nullptr)
				break;
			if (ContactList->contact->GetFixtureA()->GetBody()->GetUserData() != nullptr&&ContactList->contact->IsTouching())
			{
					std::cout << "2";
					world->DestroyBody(level->bullet[i].b2Bullet);
					level->bullet.erase(level->bullet.begin() + i);
					i--;
					break;
			}
		}
	}
}


bool Game::theEnd(b2World *world,RenderWindow &window,Camera *camera)
{
	for (b2ContactEdge *ContactList = level->b2theEnd->GetContactList(); ContactList != nullptr; ContactList = ContactList->next)
	{
		if (ContactList->other == level->player->b2body())
		{
			sf::Texture texture;
			texture.loadFromFile("D:/Game/Game/airRocket.png");
			sf::Sprite sprite(texture);
			sprite.setOrigin(212,212);
			b2Vec2 pos = level->b2theEnd->GetPosition();
			sprite.setPosition(pos.x*scale-camera->offsetX,pos.y*scale);
			camera->drawRocket = false;
			camera->display = false;
			while (true)
			{
				sprite.move(0, -0.5);
				sf::Vector2f position = sprite.getPosition();
				camera->draw(world,window,level, score);
				window.draw(sprite);
				window.display();
				if (position.y + 212 < 0)
				{
					break;
				}
			}
			if (location == 1)
			{
				Texture tZat, tGun, tText;
				tZat.loadFromFile("D:/Game/Game/menu/lvl1end/zat.png");
				tGun.loadFromFile("D:/Game/Game/menu/lvl1end/gun.png");
				tText.loadFromFile("D:/Game/Game/menu/lvl1end/text.png");
				Sprite sZat(tZat), sGun(tGun), sText(tText);
				sText.setPosition(435, 126);
				sGun.setOrigin(92, 101);
				sGun.setPosition(682, 322);
				while (true)
				{
					sGun.rotate(1);
					window.clear();
					window.draw(sZat);
					window.draw(sText);
					window.draw(sGun);
					window.display();
					if (Keyboard::isKeyPressed(Keyboard::Enter))
					{
						break;
					}
				}
			}
			camera->display = true;
			camera->drawRocket = true;
			return true;
		}
	}
	return false;
}


Game::~Game()
{
	delete level;
}
