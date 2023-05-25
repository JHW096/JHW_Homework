#include<iostream>
#include <conio.h>

//1. Homework - 숙제 플레이어가 화면 바깥으로 나가지 못하게 해라.

const int XLine = 20;
const int YLine = 10;

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

    int4 operator+(const int4& _Other)
    {
        int4 Return;
        Return.X = X + _Other.X;
        Return.Y = Y + _Other.Y;
        Return.Z = Z + _Other.Z;
        Return.W = W + _Other.W;

        return Return;
    }

};

const int4 Left = { -1, 0 };
const int4 Right = { 1, 0 };
const int4 Up = { 0, -1 };
const int4 Down = { 0, 1 };
const int4 Zero = { 0, 0 };

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

    //Add teacher solution
    bool IsScreenOut(const int4& _Pos)
    {
        if (_Pos.X < 0)
        {
            return true;
        }

        if (_Pos.Y < 0)
        {
            return true;
        }

        if (XLine <= _Pos.X)
        {
            return true;
        }

        if (YLine <= _Pos.Y)
        {
            return true;
        }

        return false;
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
            {
                if (Pos.X <= 0)
                {
                    AddPos(Zero);
                }
                else
                {
                    AddPos(Left);
                }
                break;
            }
            case 'd':
            {
                if (Pos.X > XLine - 2)
                {
                    AddPos(Zero);
                }
                else
                {
                    AddPos(Right);
                }
                break;
            }
            case 'w':
            {
                if (Pos.Y <= 0)
                {
                    AddPos(Zero);
                }
                else
                {
                    AddPos(Up);
                }
                break;
            }
            case 's':
            {
                if (Pos.Y > YLine - 2)
                {
                    AddPos(Zero);
                }
                else
                {
                    AddPos(Down);
                }
                break;
            }
            default:
            {
                break;
            }
        }
    }

#pragma region Teacher_Solution

    void Input(ConsoleScreen* _Screen)
    {
        char Select = (char)_getch();

        //add move { 0, 0 };

        switch (Select)
        {
        case 'a':
        {
            if (false == _Screen->IsScreenOut(GetPos() + Left))
            {
                AddPos(Left);
            }
            break;
        }
        case 'd':
        {
            if (false == _Screen->IsScreenOut(GetPos() + Right))
            {
                AddPos(Right);
            }
            break;
        }
        case 'w':
        {
            if (false == _Screen->IsScreenOut(GetPos() + Up))
            {
                AddPos(Up);
            }
            break;
        }
        case 's':
        {
            if (false == _Screen->IsScreenOut(GetPos() + Down))
            {
                AddPos(Down);
            }
        }
        default:
        {
            break;
        }
        }
    }


    

#pragma endregion 

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