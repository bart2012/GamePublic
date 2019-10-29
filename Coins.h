#ifndef COINS_H
#define COINS_H
#include  "Box2D/Box2D.h"
#include <SFML/Graphics.hpp>
using namespace sf;
class Coins
{
public:
	b2Body *b2Coins;
	float x;
	float y;
	std::string p = "coin";
	Coins(b2World *world, float x, float y);
	~Coins();
private:
	float scale = 30;
};

#endif

