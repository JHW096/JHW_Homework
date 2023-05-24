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
    int Def;
};

void TestFunction(Player _Newplayer, int _Test)
{
    __int64 Address0 = (__int64)&_Newplayer;
    __int64 Address1 = (__int64)&_Test;
    /*
        Result

        Address0 = 423898380416
        Address1 = 423898380424     (+8)

        Parameters byte size = 8byte
        Player has 2int Variable


        if Player has diff Variables (int HP, int ATT, Char N)
        ByteSize + 16

        if Player has over 8byte Variables (int, int, int)
        Result
        Address0 = ex) 0
        Address1 = ex) -520
    */
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
        [ ] = 8byte

        [ test.A | 4byte ] [ test.B ] [ test.C | test.D | test.E | test.F ]

        Result

        Address0 = 258049570712
        Address1 = 258049570720     (+8)
        Address2 = 258049570728     (+8)
        Address3 = 258049570729     (+1)
        Address4 = 258049570730     (+1)
        Address5 = 258049570732     (+2)

        Expected Correct.
    */

    int a = 0; //break point


    //3. TestFucntion Parameters Address Check
    Player NewPlayer{};
    TestFunction(NewPlayer, 20);

}

/*
    Additional Comment.
    1. Virtual Address.
    Address를 확인할 때, Ram의 진짜 위치를 알려주지 않는다.
    이때 보이는 주소는 가상주소(Virtual Address)이다.
    BCuz 진짜 Ram의 위치를 조정할 수 있다면,
    다른 프로그램 또는 프로세스를 간섭할 수 있기 때문이다.

    Physical Address <=> Virtual Address

    객체의 메모리와 함수의 Parameter의 메모리를 분리해서 처리한다.

*/