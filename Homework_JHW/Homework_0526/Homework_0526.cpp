#include "Global.h"
#include "ConsoleScreen.h"
#include "Player.h"
#include "Wall.h"

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
    ConsoleScreen Screen;
    Screen.Init('*');

    Player MainPlayer;
    MainPlayer.SetPos({ 10, 5 });

    Wall Walls[GlobalValue::WallCount];
    int4 Wall_pos[GlobalValue::WallCount] = { { 0, 0} };
    for (int i = 0; i < GlobalValue::WallCount; i++)
    {
        Walls[i].SetPos({ 5, i });
        Wall_pos[i] = Walls[i].GetPos();
        Screen.InsertWallPos(Wall_pos);
    }

    int a = 0;

    while (true)
    {
        Screen.Clear();

        for (int i = 0; i < GlobalValue::WallCount; i++)
        {
            Screen.SetPixel(Walls[i].GetPos(), '#');
        }
        Screen.SetPixel(MainPlayer.GetPos(), 'a');

        Screen.Print();

        MainPlayer.Input(&Screen);
    }
}

