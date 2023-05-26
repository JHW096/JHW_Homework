#include "ConsoleScreen.h"
#include "Global.h"
#include "Wall.h"


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
    for (size_t y = 0; y < Global::YLine; y++)
    {
        for (size_t x = 0; x < Global::XLine; x++)
        {
            ArrScreen[y][x] = BaseCh;
        }
        ArrScreen[y][Global::XLine] = 0;
    }
}

bool ConsoleScreen::IsScreenOut(const int4& _Pos) const
{
    if (_Pos == Wall.GetPos())
    {
        return true;
    }

    if (0 > _Pos.X)
    {
        return true;
    }

    if (0 > _Pos.Y)
    {
        return true;
    }

    if (Global::XLine <= _Pos.X)
    {
        return true;
    }

    if (Global::YLine <= _Pos.Y)
    {
        return true;
    }


    return false;

}

void ConsoleScreen::Print() const
{
    for (size_t y = 0; y < Global::YLine; y++)
    {
        printf_s(ArrScreen[y]);
        printf_s("\n");
    }
}