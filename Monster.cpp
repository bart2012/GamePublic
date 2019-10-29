#include "Monster.h"
#include "doublenumberssupport.h"


Monster::Monster(b2World *world, float x, float y, int t1, int t2):_t1(t1),_t2(t2)
{
	_speed = 1;
	_speedAnimation = 0.005f;
	_kilkistCadriv = 4;
	_numberCadr = 0;
	_width = 218;
	_rect.left = 0;
	_rect.top = 0;
	_rect.width = 238;
	_rect.height = 192;
	createb2Body(world, x, y);
	createGrafic(x, y);
	_directionRight = true;
}

void Monster::createb2Body(b2World *world, float x, float y)
{
	b2BodyDef b2DefMonster;
	b2DefMonster.fixedRotation = true;
	b2DefMonster.type = b2_dynamicBody;
	b2DefMonster.position.Set(x / scale, y / scale);
	_b2Monster = world->CreateBody(&b2DefMonster);
	b2PolygonShape b2ShapeMonster;
	b2ShapeMonster.SetAsBox(_width / 2.f/ scale, _rect.height/ 2.f / scale);
	b2FixtureDef b2Fix;
	b2Fix.density = 1.0f;
	b2Fix.friction = 0.0f;
	b2Fix.shape = &b2ShapeMonster;
	_b2Monster->CreateFixture(&b2Fix);
	_b2Monster->SetUserData(&_name);
	_b2Monster->SetLinearVelocity(b2Vec2(_speed, 0));
}

void Monster::createGrafic(float x, float y)
{
	_tMonster.loadFromFile("D:/Game/Game/character/alien.png");
	_sMonster.setTexture(_tMonster);
	_sMonster.setTextureRect(IntRect(_rect.left, _rect.top, _width, _rect.height));
	_sMonster.setPosition(x, y);
	_sMonster.setOrigin(_width / 2.f, _rect.height / 2.f);
}

void Monster::update()
{
	move();
	setAnimationCadr();
}

void Monster::move()
{
	b2Vec2 position = _b2Monster->GetPosition();
	std::cout << "pos.x" << position.x*scale << std::endl;
	std::cout << "t1" << _t1 << std::endl;
	std::cout << "t2" << _t2 << std::endl;
	if (directionRignt() && position.x*scale + _rect.width / 2.f >= _t2)
	{
		b2Vec2 speed = _b2Monster->GetLinearVelocity();
		_b2Monster->SetLinearVelocity(-speed);
		setDirectionLeft();
	}
	if (directionLeft() && position.x*scale - _rect.width / 2.f <= _t1)
	{
		b2Vec2 speed = _b2Monster->GetLinearVelocity();
		_b2Monster->SetLinearVelocity(-speed);
		setDirectionRight();
	}
}

void Monster::setAnimationCadr()
{
	_numberCadr += _speedAnimation;
	if (_numberCadr > _kilkistCadriv)
		_numberCadr = 0;
	if (directionRignt())
	{
		_sMonster.setTextureRect(IntRect(_rect.width*int(_numberCadr), _rect.top, _width, _rect.height));
	}
	if (directionLeft())
	{
		_sMonster.setTextureRect(IntRect(_rect.width*int(_numberCadr) + _width, _rect.top, -_width, _rect.height));
	}

}

void Monster::pistol(b2World *world, std::vector<Bullet> &bullet)
{
	if (time.GetMilliseconds() >= 1000)
	{
			b2Vec2 position = _b2Monster->GetPosition();
			if (_directionRight)
			{
				position.x += 118 / scale;
				position.y -= 5 / scale;
			}
			if (!_directionRight)
			{
				position.x -= 118 / scale;
				position.y -= 5 / scale;
			}
			bullet.push_back(Bullet(world, position, _directionRight));
		time.Reset();
	}
}

bool Monster::reaction(Player *player)
{
	b2Vec2 playerPosition = player->b2body()->GetPosition();
	b2Vec2 monsetPosition = _b2Monster->GetPosition();
	b2Vec2 monsterSpeed = _b2Monster->GetLinearVelocity();
	if (playerPosition.y > monsetPosition.y - 200 / scale && playerPosition.y < monsetPosition.y + 200 / scale)
	{
		if (playerPosition.x > monsetPosition.x)
		{
			_directionRight = true;
		}
		if (playerPosition.x < monsetPosition.x)
		{
			_directionRight = false;
		}
		if (_directionRight)
		{
			_sMonster.setTextureRect(IntRect(_rect.left, _rect.top, _width, _rect.height));
		}
		if (!_directionRight)
		{
			_sMonster.setTextureRect(IntRect(_width, _rect.top, -_width, _rect.height));
		}
		_b2Monster->SetLinearVelocity(b2Vec2(0,monsterSpeed.y));
		return true;
	}
	if (DoubleCompare::fuzzyIsNull(monsterSpeed.x))
	{
		_b2Monster->SetLinearVelocity(b2Vec2(_speed, monsterSpeed.y));
	}
	return false;
}






void Monster::setDirectionRight()
{
	_directionRight = true;
}
void Monster::setDirectionLeft()
{
	_directionRight = false;

}
bool Monster::directionRignt() const
{
	return _directionRight;
}
bool Monster::directionLeft() const
{
	return !_directionRight;
}

Sprite* Monster::sprite()
{
	return &_sMonster;
}
b2Body* Monster::b2body()
{
	return _b2Monster;
}

Monster::~Monster()
{
}
