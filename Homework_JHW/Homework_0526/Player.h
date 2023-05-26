#pragma once
#include "ConsoleScreen.h"

class Player : public ConsoleScreen
{
public:
    
    int4 GetPos() const
    {
        return Pos;
    }

    void AddPos(const int4& _Pos)
    {
        Pos += _Pos;
    }


    void SetPos(const int4& _Pos)
    {
        Pos = _Pos;
    }

    // 생성자에는 붙일수가 없다.
    Player()
        : Pos()
    {
    }

    Player(const Player&) = delete;

    void Input(ConsoleScreen* _Sreen);

protected:

private:
    int4 Pos;

    const int4 Left = { -1, 0 };
    const int4 Right = { 1, 0 };
    const int4 Up = { 0, -1 };
    const int4 Down = { 0, 1 };


};

