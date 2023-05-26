#pragma once

#include"int4.h"

class ConsoleScreen;
class Bullet;

class Player : public int4
{
public:
	int4 GetPos() const
	{
		return Pos;
	}

	void AddPos(const int4& _Pos)
	{
		Pos += _Pos;
	}

	void SetPos(const int4& _Pos)
	{
		Pos = _Pos;
	}

	Player()
		: Pos()
	{

	}

	Player(const Player&) = delete;

	void Input(ConsoleScreen* _Screen, Bullet& _Bullet);

private:
	int4 Pos;
};

