#include <iostream>

using namespace std;

class Test
{
public:
    int A;
    __int64 B;
    char C;
    char D;
    short E; 
    int F;
};

class Player
{
    int HP;
    int ATT;
};

void TestFunction(Player _Newplayer, int _Test)
{
    // 이것도 확인해보세요.
}

int main()
{
    //1. TestClass Size
    size_t ClassSize = sizeof(Test);
    
    cout << ClassSize << endl;

    //2. TestClass 

    /*size_t Size = sizeof(Test);

    Test NewTest;

    __int64 Address0 = (__int64)&NewTest.A;

    Player NewPlayer;
    TestFunction(NewPlayer, 20);*/
}

