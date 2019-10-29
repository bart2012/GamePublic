#ifndef LEVEL_H
#define LEVEL_H
#include <SFML/Graphics.hpp>
#include"Box2D/Box2D.h"
#include <vector>
#include "Coins.h"
#include"Ground.h"
#include "Player.h"
#include "Bullet.h"
#include "Monster.h"
using namespace sf;

class Level
{
public:
	Player *player;
	std::vector<Coins> coins;
	std::vector<Ground> ground;
	std::vector<Bullet> bullet;
	std::vector<Monster*> monster;
	b2Body *b2theEnd;
	float scale = 30.0f;
	int maxCoins;
	Level(b2World *world,int location);
	~Level();
};

#endif
