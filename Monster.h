#ifndef MONSTER_H
#define MONSTER_H
#include <SFML/Graphics.hpp>
#include "Box2D/Box2D.h"
#include "Bullet.h"
#include "Player.h"
using namespace sf;

class Monster
{
public:
	Monster(b2World *world,float x, float y, int t1, int t2);
	~Monster();
	void update();
	Sprite* sprite();
	b2Body* b2body();
	void setDirectionRight();
	void setDirectionLeft();
	bool directionRignt() const;
	bool directionLeft() const;
	void pistol(b2World *world, std::vector<Bullet> &bullet);
	Texture _tMonster;
	Sprite _sMonster;
	bool reaction(Player *player);
private:
	b2Timer time;
	float _width;
	bool _directionRight;
	float _speedAnimation;
	float _numberCadr;
	float scale = 30;
	int _kilkistCadriv;
	FloatRect _rect;
	float _speed;
	b2Body *_b2Monster;
	int _t1;
	int _t2;
	void createb2Body(b2World *world, float x, float y);
	void createGrafic(float x, float y);
	std::string _name = "monster";
	void move();
	void setAnimationCadr();
};
#endif

