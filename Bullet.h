#ifndef BULLET_H
#define BULLET_H
#include <SFML/Graphics.hpp>
#include "Box2D/Box2D.h"
#include <iostream>
class Bullet
{
public:
	b2Body *b2Bullet;
	Bullet(b2World *world,b2Vec2 position, bool directionRight);
	bool directionRignt();
	bool directionLeft();
	std::string st = "st";
	~Bullet();
private:
	bool _directionRight;
	float scale = 30;
};

#endif


