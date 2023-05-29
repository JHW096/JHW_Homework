#include "Bullet.h"
#include "Player.h"
#include "ConsoleScreen.h"

void Bullet::Init(Player* _Player)
{
	m_Pos = _Player->GetPos();
	m_Dir = { 0, 0 };
}

bool Bullet::IsBulletFired(ConsoleScreen* _Screen)
{
	if (_Screen == nullptr)
	{
		return true;
	}

	if (_Screen->FindPixel(GlobalValue::Bullet))
	{
		return true;
	}

	return false;
}

bool Bullet::IsBulletOut()
{
	if (m_Pos.X >= GlobalValue::XLine ||
		m_Pos.Y >= GlobalValue::YLine ||
		m_Pos.X < 0 ||
		m_Pos.Y < 0)
	{
		return true;
	}

	return false;
}


void Bullet::AddPos(const int4& _Pos)
{
	m_Pos += _Pos;
}

void Bullet::SetDir(ConsoleScreen* _Screen, const int4& _Pos)
{
	if (_Screen == nullptr)
	{
		return;
	}

	if (!IsBulletFired(_Screen))
	{
		return;
	}

	m_Dir = _Pos;
}

