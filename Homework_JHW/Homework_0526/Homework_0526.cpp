#include <iostream>
#include "Player.h"
#include "int4.h"
#include "ConsoleScreen.h"
#include "Global.h"
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
    Wall Walls[10];
    // 클래스의경우에는 
    int a = 0;
    int b = 0;
    MainPlayer.SetPos({ 2, 1 });
   
    for (int i = 0; i < Global::WallCount; i++)
    {
        Walls[i].SetPos({ i, i });
    }

   
    

    while (true)
    {
        Screen.Clear();
        Screen.SetPixel(MainPlayer.GetPos(), 'a');
        for (int i = 0; i < Global::WallCount; i++)
        {
            Screen.SetPixel(Walls[i].GetPos(), '#');
        }
        Screen.Print();

        MainPlayer.Input(&Screen);
    }
}

 /* Delta Time 같은 느낌으로다가.
 * #include <windows.h>에 있는 
 * Console.cpp에서 확인.
 if(_kbhit() != 0 ) {
    입력버퍼가 차있다는 뜻.
 }

    Sleep(200);


 */