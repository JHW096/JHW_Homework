#include "Global.h"
#include "ConsoleScreen.h"
#include "Player.h"
#include "Wall.h"
#include "Bullet.h"

/*
  1 :  .h / .cpp로 분리
  2 : 10개의 장애물 배치. (Wall Class)
  3 : 장애물 통과 못하게 하기.
  4 : Player와 Wall은 같은 Class를 상속받아서 만들어져야 한다. ?..
  5 : 화면안에 나오려면 위치가 필요하다.
  Class Wall : public int4
  6. 플레이어가 어떠한 키를 누르면, 플레이어 위치에서, 총알 한 발이
  발사되게 만드세요.

  7. 크 총알 1발에 벽이 닿으면 벽이 없어지게 만드세요.

*/

int main()
{
    //Create Object
    ConsoleScreen   Screen;
    Player          MainPlayer;
    Bullet          MainBullet;
    Wall            Walls[GlobalValue::WallCount];

    //Init Object
    Screen.Init(GlobalValue::Default);
    MainPlayer.SetPos({ 10, 5 });
    MainBullet.Init(&MainPlayer);
    for (int i = 0; i < GlobalValue::WallCount; i++)
    {
        Walls[i].SetPos({ 5 + i, 2 });
    }


    //Move Init Value
    int4 Dir = { 0, 0 };
    //int Count = 0;
    while (true)
    {
        //FrameStart, DrwaingStart
        Screen.Clear();

        //Drawing Player
        Screen.SetPixel(MainPlayer.GetPos(), GlobalValue::Player);

        //Drawing Wall
        for (int i = 0; i < GlobalValue::WallCount; i++)
        {
            Walls[i].Destroy(MainBullet.GetPos());
            Screen.SetPixel(Walls[i].GetPos(), Walls[i].GetCh());
        }

        //TODO - Wall Move per Frame
        /*
            for(int i = 0; i < GlobalValue::WallCount; i++)
            Screen.SetPixel(Walls[i].GetPos() + i, Walls[i].GetCh());
        */

        //Drawing and Reset Bullet, 
        Dir = MainBullet.GetDir();
        MainBullet.AddPos(Dir);
        if (MainBullet.IsBulletOut())
        {
            Dir = { 0, 0 };
            MainBullet.Init(&MainPlayer);
        }
        Screen.SetPixel(MainBullet.GetPos(), GlobalValue::Bullet);

        //FrameEnd, DrawingEnd;
        Screen.Print();


        //Wait Keyboard KeyValue, 'Applied only once'
        if (_kbhit() != 0)
        {
            MainPlayer.Input(&Screen, &MainBullet);
        }

        Sleep(100);
    }

}

