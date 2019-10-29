#include "Ground.h"

// number
// 1 - Ground(1366*111)
// 2 - платформа
// 3 - літаюча платформа
// 4 - стіна
// 5 - підйом
// 6 - спуск
// 7 - яма
Ground::Ground(b2World *world,FloatRect rect,int number):rect(rect),number(number)
{
	if (number == 1 || number == 2 || number == 4)
	{
		b2BodyDef b2Def;
		b2Def.type = b2_staticBody;
		b2Def.position.Set((rect.left + rect.width / 2.f) / scale, (rect.top + rect.height / 2.f) / scale);
		b2Body = world->CreateBody(&b2Def);
		b2PolygonShape b2Shape;
		b2Shape.SetAsBox(rect.width / 2.f / scale, rect.height / 2.f / scale);
		b2FixtureDef b2;
		b2.density = 1.0;
		b2.friction = 0.0;
		b2.shape = &b2Shape;
		b2Body->CreateFixture(&b2);
		b2Body->SetUserData(&str2);
	}
	if (number == 5)
	{
		b2BodyDef b2Def;
		b2Def.position.Set((rect.left + rect.width / 2.f) / scale, (rect.top + rect.height / 2.f) / scale);
		b2Vec2 vertices[4];
		vertices[0].Set(rect.width /2.f / scale, -rect.height / 2.f / scale);
		vertices[1].Set(-rect.width / 2.f / scale, -(rect.height / 2.f - 400 ) / scale);
		vertices[2].Set(rect.width / 2.f / scale, rect.height / 2.f / scale);
		vertices[3].Set(-rect.width / 2.f / scale, rect.height / 2.f / scale);
		/*vertices[0].Set(649 / m, -579 / m);
		vertices[1].Set(-649 / m, -179 / m);
		vertices[2].Set(649 / m, 579 / m);
		vertices[3].Set(-649 / m, 579 / m);*/
		b2PolygonShape b2Shape;
		b2Shape.Set(vertices, 4);
		b2Body = world->CreateBody(&b2Def);
		b2Body->CreateFixture(&b2Shape, 0);
	}
	if (number == 6)
	{
		b2BodyDef b2Def;
		b2Def.position.Set((rect.left + rect.width / 2.f) / scale, (rect.top + rect.height / 2.f) / scale);
		b2Vec2 vertices[4];
		vertices[0].Set(-rect.width / 2.f / scale, -rect.height / 2.f / scale);
		vertices[1].Set(rect.width / 2.f / scale, -(rect.height / 2.f - 400) / scale);
		vertices[2].Set(rect.width / 2.f / scale, rect.height / 2.f / scale);
		vertices[3].Set(-rect.width / 2.f / scale, rect.height / 2.f / scale);
		/*vertices[0].Set(649 / m, -579 / m);
		vertices[1].Set(-649 / m, -179 / m);
		vertices[2].Set(649 / m, 579 / m);
		vertices[3].Set(-649 / m, 579 / m);*/
		b2PolygonShape b2Shape;
		b2Shape.Set(vertices, 4);
		b2Body = world->CreateBody(&b2Def);
		b2FixtureDef b2;
		b2.density = 1.0;
		b2.friction = 0.3;
		b2.shape = &b2Shape;
		b2Body->CreateFixture(&b2);
	}
	if (number == 7)
	{
		b2BodyDef b2Def;
		b2Def.position.Set((rect.left + rect.width / 2.f) / scale,(rect.top + rect.height / 2.f) / scale);
		b2Body = world->CreateBody(&b2Def);
		b2PolygonShape b2Shape;
		b2Shape.SetAsBox(rect.width / 2.f / scale, rect.height / 2.f / scale);
		b2FixtureDef b2Fix;
		b2Fix.isSensor = true;
		b2Fix.shape = &b2Shape;
		b2Body->CreateFixture(&b2Fix);
	}
}

Ground::Ground(b2World *world, FloatRect rect, int number, int t1, int t2, char vector) :rect(rect), number(number), t1(t1), t2(t2), vector(vector)
{
	b2BodyDef b2Def;
	b2Def.position.Set((rect.left + rect.width / 2.f) / scale, (rect.top + rect.height / 2.f) / scale);
	b2Def.type = b2_kinematicBody;
	b2Body = world->CreateBody(&b2Def);
	b2PolygonShape b2Shape;
	b2Shape.SetAsBox(rect.width / 2.f / scale, (rect.height-1) / 2.f / scale,b2Vec2(0,0.5 / scale),0);
	b2PolygonShape b2Shape2;
	b2FixtureDef b2;
	b2.density = 0.0;
	b2.friction = 0.0;
	b2.shape = &b2Shape;
	b2.userData = &str1;
	b2Body->CreateFixture(&b2);
	b2Shape2.SetAsBox((rect.width - 0.5) / 2.f / scale, 1 / 2.f / scale, b2Vec2(0, -(rect.height - 1) / 2.f / scale), 0);
	b2FixtureDef b2fixdef;
	b2fixdef.density = 0.0;
	b2fixdef.friction = 1000.0f;
	b2fixdef.userData = &str;
	b2fixdef.shape = &b2Shape2;
	b2Body->CreateFixture(&b2fixdef);
	if (vector == 'v')
		b2Body->SetLinearVelocity(b2Vec2(0, 0.5));
	if (vector == 'b')
		b2Body->SetLinearVelocity(b2Vec2(0.5, 0));
	//b2Body->SetUserData(&str2);
}



Ground::~Ground()
{
}
