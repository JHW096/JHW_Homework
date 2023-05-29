#pragma once
#include "Global.h"
#include"int4.h"

class ConsoleScreen;
class Bullet;

class Player : public int4
{
	//Player() ~Player()
public:

	Player()
		: m_Pos()
	{

	}

	Player(const Player&) = delete;

	//Getter, Setter
public:
	int4 GetPos() const
	{
		return m_Pos;
	}

	char GetCh() const
	{
		return m_Ch;
	}

	void SetPos(const int4& _Pos)
	{
		m_Pos = _Pos;
	}

	//Behavior
public:

	void AddPos(const int4& _Pos)
	{
		m_Pos += _Pos;
	}

	void Input(ConsoleScreen* _Screen, Bullet* _Bullet);


private:
	int4 m_Pos;
	char m_Ch;
	//Bullet m_Bullet;
};

