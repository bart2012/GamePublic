#ifndef PLAYER_H
#define PLAYER_H
#include <SFML/Graphics.hpp>
#include"Box2D/Box2D.h"
#include <iostream>
#include "Bullet.h"
using namespace sf;

class Player
{
public:
	Player(b2World *world, FloatRect rect, float x, float y, float width);
	bool havePistol;
	b2Timer time;
	void setFirstCadr();
	bool canJump();
	void setDirectionRight();
	void setDirectionLeft();
	bool directionRignt() const;
	bool directionLeft() const;
	void jump();
	void goRight();
	void goLeft();
	void gorisontalMoveStop();
	void setSpriteKickback();
	void setAnimationCadr();
	void pistol(b2World *world,std::vector<Bullet> &bullet);
	Sprite* sprite();
	b2Body* b2body();
	~Player();
private:
	float _width;
	bool _directionRight = true;
	Sprite _sPlayer;
	FloatRect _rect;
	Texture _tPlayer;
	b2Body *_b2Player;
	float _speed;
	float _speedUp;
	float _speedAnimation;
	float _numberCadr;
	float scale = 30;
	int _kilkistCadriv;
	void createb2Body(b2World *world, float x, float y);
	void createGrafic(float x, float y);
	std::string pl = "pverx";
	std::string pl2 = "pdown";
};


#endif
