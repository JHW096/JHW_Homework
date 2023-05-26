#include "ConsoleScreen.h"

void ConsoleScreen::Init(char _BaseCh)
{
	BaseCh = _BaseCh;
	Clear();
}

void ConsoleScreen::SetPixel(const int4& _Pos, char _Ch)
{
	ArrScreen[_Pos.Y][_Pos.X] = _Ch;
}

void ConsoleScreen::Clear()
{
	system("cls");
	for (size_t y = 0; y < GlobalValue::YLine; y++)
	{
		for (size_t x = 0; x < GlobalValue::XLine; x++)
		{
			ArrScreen[y][x] = BaseCh;
		}
		ArrScreen[y][GlobalValue::XLine] = 0;
	}
}

bool ConsoleScreen::IsScreenOut(const int4& _Pos) const
{
    if (0 > _Pos.X)
    {
        return true;
    }

    if (0 > _Pos.Y)
    {
        return true;
    }

    if (GlobalValue::XLine <= _Pos.X)
    {
        return true;
    }

    if (GlobalValue::YLine <= _Pos.Y)
    {
        return true;
    }

    return false;
}


void ConsoleScreen::Print() const
{
    for (size_t y = 0; y < GlobalValue::YLine; y++)
    {
        printf_s(ArrScreen[y]);
        printf_s("\n");
    }
}

void ConsoleScreen::InsertWallPos(int4* _Pos)
{
    for (int i = 0; i < GlobalValue::WallCount; i++)
    {
        Walls[i] = _Pos[i];
    }
    
}
