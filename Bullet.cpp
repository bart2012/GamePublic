#include "Bullet.h"



Bullet::Bullet(b2World *world,b2Vec2 position, bool directionRight):_directionRight(directionRight)
{
	b2BodyDef b2Def;
	b2Def.position.Set(position.x, position.y);
	b2Def.type = b2_dynamicBody;
	b2Def.gravityScale = 0;
	b2Bullet = world->CreateBody(&b2Def);
	b2PolygonShape b2Shape;
	b2Shape.SetAsBox(7 / scale, 3 / scale);
	b2FixtureDef b2Fix;
	b2Fix.isSensor = true;
	b2Fix.density = 1.0;
	b2Fix.userData = &st;
	b2Fix.shape = &b2Shape;
	b2Bullet->CreateFixture(&b2Fix);
	b2Bullet->SetUserData(&st);

	if (_directionRight)
	{
		b2Bullet->SetLinearVelocity(b2Vec2(2, 0));
	}
	if (!_directionRight)
	{
		b2Bullet->SetLinearVelocity(b2Vec2(-2, 0));
	}
}

bool Bullet::directionRignt()
{
	return _directionRight;
}
bool Bullet::directionLeft()
{
	return !_directionRight;
}

Bullet::~Bullet()
{
}
