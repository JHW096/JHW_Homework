#pragma once
#include "int4.h"

class Wall : public int4
{
public:

	int4 GetPos() const
	{
		return Pos;
	}

	void SetPos(const int4& _Pos)
	{
		Pos = _Pos;
	}

	Wall()
		: Pos()
	{

	}

	Wall(const Wall&) = delete;

private:

	int4 Pos;
};

