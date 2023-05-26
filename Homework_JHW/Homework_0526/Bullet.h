#pragma once
#include "int4.h"

class Bullet
{
public:

	void init()
	{

	}

	void UpdatePos(const int4& _Pos)
	{
		this->Pos = _Pos;
	}

	void UpdateDir()
	{

	}

	void Fire()
	{
		
	}

	void SetDir(const int4& _Dir)
	{
		Dir = _Dir;
	}

	int4 GetDir() const
	{
		return Dir;
	}

private:
	
	int4 Pos;
	int4 Dir;

};

