#pragma once
#include "Global.h"
#include "int4.h"
#include "Wall.h"

class ConsoleScreen : public int4
{
public:
    ConsoleScreen(Wall* _Walls)
    {
        for (int i = 0; i < Global::WallCount; i++)
        {
            m_Walls[i] = _Walls[i];
        }
    }

    void Init(char _BaseCh);

    void SetPixel(const int4& _Pos, char _Ch);

    void Clear();

    bool IsScreenOut(const int4& _Pos) const;

    void Print() const;

protected:


private:
    char BaseCh = ' ';
    char ArrScreen[Global::YLine][Global::XLine + 1] = {};
    Wall m_Walls[Global::WallCount];
};

