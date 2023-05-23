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
public:
    int HP;
    int ATT;
};

void TestFunction(Player _Newplayer, int _Test)
{
    __int64 Address0 = (__int64)&_Newplayer;
    __int64 Address1 = (__int64)&_Test;

    int a = 0; // break point
}

int main()
{
    //0. CreateObject
    Test test;

    //1. TestClass Size
    size_t ClassSize = sizeof(Test);
    
    //2. TestClass Addresses
    __int64 Address0 = (__int64)&test.A;
    __int64 Address1 = (__int64)&test.B;
    __int64 Address2 = (__int64)&test.C;
    __int64 Address3 = (__int64)&test.D;
    __int64 Address4 = (__int64)&test.E;
    __int64 Address5 = (__int64)&test.F;
    /*
        My Expected Result
        [ test.A | 4byte ] [ test.B ] [ test.C | test.D | test.E | test.F ] 
    */
    
    int a = 0; //break point


    //3. TestFucntion Parameters Address Check
    Player NewPlayer;
    TestFunction(NewPlayer, 20);
}

