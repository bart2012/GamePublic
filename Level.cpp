#include "Level.h"
#include <fstream>

Level::Level(b2World *world,int location)
{
	struct element
	{
		int number;
		int x;
		int y;
		int dx;
		int dy;
		int t1;
		int t2;
		char vec = ' ';
	};
	std::vector <element> elements;
	std::ifstream file;
	if (location == 1)
	{
		player = new Player(world, FloatRect(0, 228, 112, 199), 150, 0, 86);
		file.open("D:/Game/Game/map/dat/lvl1", std::ios::binary);
		player->havePistol = false;
		b2BodyDef b2Def;
		b2Def.position.Set(10000 / scale, -300 / scale);
		b2Def.type = b2_dynamicBody;
		b2theEnd = world->CreateBody(&b2Def);
		b2PolygonShape b2Shape;
		b2Shape.SetAsBox(429 / 2.f / scale, 256 / 2.f / scale);
		b2FixtureDef b2Fix;
	//	b2Fix.isSensor = true;
		b2Fix.shape = &b2Shape;
		b2Fix.density = 1.0;
		b2theEnd->CreateFixture(&b2Fix);
		maxCoins = 9;
	}
	if (location == 2)
	{
		player = new Player(world, FloatRect(0, 0, 112, 199), 0, 0, 103);
		file.open("D:/Game/Game/map/dat/lvl2", std::ios::binary);
		player->havePistol = true;
		b2BodyDef b2Def;
		b2Def.type = b2_dynamicBody;
		b2Def.position.Set(19800 / scale, 100 / scale);
		b2theEnd = world->CreateBody(&b2Def);
		b2PolygonShape b2Shape;
		b2Shape.SetAsBox(429 / 2.f / scale, 256 / 2.f / scale);
		b2FixtureDef b2Fix;
		//b2Fix.isSensor = true;
		b2Fix.shape = &b2Shape;
		b2Fix.density = 1.0;
		b2theEnd->CreateFixture(&b2Fix);
		maxCoins = 20;
	}
	if (location == 3)
	{
		player = new Player(world, FloatRect(0, 0, 112, 199), 150, 0, 103);
		file.open("D:/Game/Game/map/dat/lvl3", std::ios::binary);
		player->havePistol = true;
		b2BodyDef b2Def;
		b2Def.type = b2_dynamicBody;
		b2Def.position.Set(13400 / scale, 0 / scale);
		b2theEnd = world->CreateBody(&b2Def);
		b2PolygonShape b2Shape;
		b2Shape.SetAsBox(429 / 2.f / scale, 256 / 2.f / scale);
		b2FixtureDef b2Fix;
		//b2Fix.isSensor = true;
		b2Fix.shape = &b2Shape;
		b2Fix.density = 1.0;
		b2theEnd->CreateFixture(&b2Fix);
		maxCoins = 10;
	}
	if (location == 4)
	{
		player = new Player(world, FloatRect(0, 0, 112, 199), 100, 0, 103);
		file.open("D:/Game/Game/map/dat/lvl4", std::ios::binary);
		player->havePistol = true;
		b2BodyDef b2Def;
		b2Def.type = b2_dynamicBody;
		b2Def.position.Set(19930 / scale, 0 / scale);
		b2theEnd = world->CreateBody(&b2Def);
		b2PolygonShape b2Shape;
		b2Shape.SetAsBox(429 / 2.f / scale, 256 / 2.f / scale);
		b2FixtureDef b2Fix;
		///b2Fix.isSensor = true;
		b2Fix.shape = &b2Shape;
		b2Fix.density = 1.0;
		b2theEnd->CreateFixture(&b2Fix);
		maxCoins = 24;
	}
	if (location == 5)
	{
		player = new Player(world, FloatRect(0, 0, 112, 199), 60, 0, 103);
		file.open("D:/Game/Game/map/dat/lvl5", std::ios::binary);
		player->havePistol = true;
		b2BodyDef b2Def;
		b2Def.type = b2_dynamicBody;
		b2Def.position.Set(19800 / scale, 0 / scale);
		b2theEnd = world->CreateBody(&b2Def);
		b2PolygonShape b2Shape;
		b2Shape.SetAsBox(429 / 2.f / scale, 256 / 2.f / scale);
		b2FixtureDef b2Fix;
		//b2Fix.isSensor = true;
		b2Fix.shape = &b2Shape;
		b2Fix.density = 1.0;
		b2theEnd->CreateFixture(&b2Fix);
		maxCoins = 20;
	}
	if (location == 6)
	{
		player = new Player(world, FloatRect(0, 0, 112, 199), 0, 0, 103);
		file.open("D:/Game/Game/map/dat/lvl6", std::ios::binary);
		player->havePistol = true;
		b2BodyDef b2Def;
		b2Def.type = b2_dynamicBody;
		b2Def.position.Set(19950 / scale, 300 / scale);
		b2theEnd = world->CreateBody(&b2Def);
		b2PolygonShape b2Shape;
		b2Shape.SetAsBox(429 / 2.f / scale, 256 / 2.f / scale);
		b2FixtureDef b2Fix;
		//b2Fix.isSensor = true;
		b2Fix.shape = &b2Shape;
		b2Fix.density = 1.0;
		b2theEnd->CreateFixture(&b2Fix);
		maxCoins = 25;
	}
	if (location == 7)
	{
		player = new Player(world, FloatRect(0, 0, 112, 199), 150, 0, 103);
		file.open("D:/Game/Game/map/dat/lvl7", std::ios::binary);
		player->havePistol = true;
		b2BodyDef b2Def;
		b2Def.type = b2_dynamicBody;
		b2Def.position.Set(16500 / scale, 300 / scale);
		b2theEnd = world->CreateBody(&b2Def);
		b2PolygonShape b2Shape;
		b2Shape.SetAsBox(429 / 2.f / scale, 256 / 2.f / scale);
		b2FixtureDef b2Fix;
		//b2Fix.isSensor = true;
		b2Fix.shape = &b2Shape;
		b2Fix.density = 1.0;
		b2theEnd->CreateFixture(&b2Fix);
		maxCoins = 20;
	}
	for (int i = 0; !file.eof(); i++)
	{
		elements.resize(i + 1);
		file.read(reinterpret_cast<char*>(&elements[i]), sizeof(element));
	}
	if (file.is_open())
	{
		for (int i = 0; i < elements.size(); i++)
		{
			if (elements[i].number == 1)
			{
				ground.push_back(Ground(world, FloatRect(elements[i].x, elements[i].y, 1366, 514), 1));
			}
			if (elements[i].number == 2)
			{
				ground.push_back(Ground(world, FloatRect(elements[i].x, elements[i].y, 121, 39), 2));
			}
			if (elements[i].number == 3)
			{
				ground.push_back(Ground(world, FloatRect(elements[i].x, elements[i].y, 121, 39), 3, elements[i].t1, elements[i].t2, elements[i].vec));
			}
			if (elements[i].number == 4)
			{
				ground.push_back(Ground(world, FloatRect(elements[i].x, elements[i].y, 405, 755), 4));
			}
			if (elements[i].number == 7)
			{
				ground.push_back(Ground(world, FloatRect(elements[i].x, elements[i].y, elements[i].dx, elements[i].dy), 7));
			}
			if (elements[i].number == 8)
			{
				coins.push_back(Coins(world, elements[i].x, elements[i].y));
			}
			if (elements[i].number == 9)
			{
				monster.push_back(new Monster(world, elements[i].x, elements[i].y, elements[i].t1, elements[i].t2));
				std::cout << elements[i].t1 << std::endl << elements[i].t2 << std::endl << std::endl;
			}
		}
	}
}


Level::~Level()
{
}
