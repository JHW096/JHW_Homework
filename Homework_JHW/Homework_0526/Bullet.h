#pragma once
#include "Global.h"
#include "int4.h"

class Player;
class ConsoleScreen;

class Bullet : public int4
{
public:

	Bullet() :
		m_Pos()
	{

	}

	Bullet(const Bullet& _Other) = delete;

	//Getter, Setter
public:

	int4 GetPos() const
	{
		return m_Pos;
	}

	int4 GetDir() const
	{
		return m_Dir;
	}

	char GetCh() const
	{
		return m_Ch;
	}

	void SetBulletPos(const int4& _Pos)
	{
		m_Pos = _Pos;
	}

	void SetDir(ConsoleScreen* _Screen, const int4& _Pos);

	//Behavior
public:

	void Init(Player* _Player);

	bool IsBulletFired(ConsoleScreen* _Screen);

	bool IsBulletOut();

	void AddPos(const int4& _Pos);

private:

	int4 m_Pos = { 0, 0 };
	int4 m_Dir;
	char m_Ch = GlobalValue::Bullet;

};

