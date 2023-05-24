#include <iostream>
#include <conio.h>

//1. Homework - 숙제 플레이어가 화면 바깥으로 나가지 못하게 해라.

const int XLine = 20;
const int YLine = 10;
/*
    My 수도코드.
    if,
    Player.Pos.x > 20 || Player.Pos.y > 10
    Player.Pos.x += 0;
    Player.Pos.y += 0;
    이런식으로 만들 예정.
*/

class int4
{
public:
    int X = 0;
    int Y = 0;
    int Z = 0;
    int W = 1;

    void operator=(const int4& _Other)
    {
        X = _Other.X;
        Y = _Other.Y;
        Z = _Other.Z;
        W = _Other.W;
    }

    void operator+=(const int4& _Other)
    {
        X += _Other.X;
        Y += _Other.Y;
        Z += _Other.Z;
        W += _Other.W;
    }

};

const int4 Left = { -1, 0 };
const int4 Right = { 1, 0 };
const int4 Up = { 0, -1 };
const int4 Down = { 0, 1 };
const int4 Zero = { };

class ConsoleScreen
{
public:
    ConsoleScreen()
    {

    }

    void Init(char _BaseCh)
    {
        BaseCh = _BaseCh;
        Clear();
    }

    void SetPixel(const int4& _Pos, char _Ch)
    {
        ArrScreen[_Pos.Y][_Pos.X] = _Ch;
    }

    void Clear()
    {
        system("cls");
        for (size_t y = 0; y < YLine; y++)
        {
            for (size_t x = 0; x < XLine; x++)
            {
                ArrScreen[y][x] = BaseCh;
            }
            ArrScreen[y][XLine] = 0;
        }
    }


    void Print()
    {
        for (size_t y = 0; y < YLine; y++)
        {
            printf_s(ArrScreen[y]);
            printf_s("\n");
        }
    }

protected:


private:
    char BaseCh = ' ';
    char ArrScreen[YLine][XLine + 1] = {};
};

class Player
{
public:
   
    int4 GetPos()
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

    Player()
        : Pos()
    {
    }

    Player(const Player&) = delete;

    void Input()
    {
        char Select = (char)_getch();

        switch (Select)
        {
        case 'a':
            AddPos(Left);
            break;
        case 'd':
            AddPos(Right);
            break;
        case 'w':
            AddPos(Up);
            break;
        case 's':
            AddPos(Down);
            break;
        default:
            break;
        }
    }

protected:

private:
    int4 Pos;
};

int main()
{
    ConsoleScreen Screen;
    Screen.Init('*');

    Player MainPlayer;
    MainPlayer.SetPos({ 10, 5 });

    while (true)
    {
        Screen.Clear();
        Screen.SetPixel(MainPlayer.GetPos(), 'a');
        Screen.Print();

        MainPlayer.Input();
    }


}