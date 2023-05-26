#pragma once
#include "int4.h"
#include "Global.h"

class Wall : public int4
{
public:

	
	Wall() 
		: Pos()
	{

	}

	int4 GetPos()
	{
		return Pos;
	}

	void SetPos(const int4& _Pos)
	{
		Pos = _Pos;
	}

private:
	int4 Pos;
};

