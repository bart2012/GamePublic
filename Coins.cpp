#include "Coins.h"



Coins::Coins(b2World *world, float x, float y):x(x),y(y)
{
	b2BodyDef b2DefCoins;
	b2DefCoins.position.Set(x / scale, y / scale);
	b2CircleShape b2ShapeCoins;
	b2ShapeCoins.m_radius = 22/ scale;
	b2FixtureDef b2FixCoins;
	b2FixCoins.isSensor = true;
	b2FixCoins.density = 0;
	b2FixCoins.shape = &b2ShapeCoins;
	b2Coins = world->CreateBody(&b2DefCoins);
	b2Coins->CreateFixture(&b2FixCoins);
	b2Coins->SetUserData(&p);
}


Coins::~Coins()
{
}
