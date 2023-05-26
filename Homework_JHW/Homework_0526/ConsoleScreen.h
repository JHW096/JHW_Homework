#pragma once
#include "Global.h"
#include "int4.h"


class ConsoleScreen : public int4
{
public:

	void Init(char _BaseCh);

	void SetPixel(const int4& _Pos, char _Ch);

	void Clear();

	bool IsScreenOut(const int4& _Pos) const;

	void Print() const;

	void InsertWallPos(int4* _Pos);

	int4* GetWallPos()
	{
		return Walls;
	}

	bool CollisionWall(int4 _Pos)
	{
		bool check{ false };
		for (int i = 0; i < GlobalValue::WallCount; i++)
		{
			if (_Pos.X == Walls[i].X && _Pos.Y == Walls[i].Y)
			{
				check = true;
			}
		}
		return check;
	}

private:

	char BaseCh = ' ';
	char ArrScreen[GlobalValue::YLine][GlobalValue::XLine + 1] = { };
	int4 Walls[GlobalValue::WallCount];
};

