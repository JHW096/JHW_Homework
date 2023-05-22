#include <iostream>
#include <conio.h> // 키를 누를때까지 기다리는 함수

// 숙제 1 -- 문자의 오른쪽끝을 맞춰오세요. 이름은 알파뱃만
// 오른쪽끝 -------

// 숙제 2 -- 실시간으로 만들어오세요.
// 데미지 메세지가 나오는순간 체력이 곧바로 감소되게 만들어라.
// 화면 지우는 함수 화면에 출력하는 함수를 잘 생각해보세요.
// 그냥 무식하게 생각해라.

// 숙제 3 -- 누군가 죽었다. 누군가의 Hp가 0이 된순간 종료.


// 몬스터와 플레이어가 서로 한대씩 때리면서
// 한명이 죽으면 끝납니다.
// 지금 그걸 그래픽으로 표현할 방법이 없으니까.
// 글자로 표현하겠습니다.

void StatusRender(const char* const _Name, int _Att, int _Hp)
{
    // 40개로 맞춰오세요.

    // 줄바꿈이 안되고 있습니다.
    printf_s("%s--------------------------\n", _Name);
    printf_s("공격력 : %d\n", _Att);
    printf_s("체  력 : %d\n", _Hp);
    printf_s("--------------------------\n");
}

void DamagePrint(const char* const _AttName, const char* const _DefName, int _Att)
{
    printf_s("%s가 %s를 공격했습니다.\n", _AttName, _DefName);
    printf_s("%s는 %d의 데미지를 입었습니다.\n", _DefName, _Att);
}

void Damage(int& _Hp, int _Att)
{
    _Hp -= _Att;
}

// 내일꼭 break continue

//1.

int GetNameCount(const char* const _Name)
{
    int Count = 0;

    while (*_Name != '\0')
    {
        ++Count;
    }

    return Count;
}

void MyStatusRender(const char* const _Name, int _Att, int _Hp)
{
    if (_Name == nullptr)
    {
        return;
    }

    if (GetNameCount(_Name) > 40)
    {
        return;
    }
    // 0  1  2  3
    //[N][a][m][e]...[\0]

    std::cout << _Name << std::endl;
    /*for (int i = GetNameCount(_Name); i < 40; ++i) 
    {
        printf_s("-");
    }
    printf_s("\0");*/

}

int main()
{
    int PlayerHp = 200;
    int PlayerAtt = 100;
    char PlayerName[40] = "fasdhjkfasdhjkfasdhjfklasdhjkfasdhjfk";

    int MonsterHp = 100;
    int MonsterAtt = 10;
    char MonsterName[40] = "Monster";


    MyStatusRender(MonsterName, 10, 20);

    //while (true)
    //{
    //    // 콘솔창을 모조리 지우는 함수
    //    system("cls");

    //    // 한번에 함수로 만든것이고
    //    StatusRender(PlayerName, PlayerAtt, PlayerHp);
    //    StatusRender(MonsterName, MonsterAtt, MonsterHp);

    //    _getch();

    //    // 아무키나 입력할때까지 기다리는 함수

    //    DamagePrint(PlayerName, MonsterName, PlayerAtt);
    //    Damage(MonsterHp, PlayerAtt);
    //    // MonsterHp -= PlayerAtt;

    //    _getch();

    //    DamagePrint(MonsterName, PlayerName, MonsterAtt);
    //    Damage(PlayerHp, MonsterAtt);

    //    _getch();

    //    //if (조건 만족시)
    //    //{
    //    //    return;
    //    //}


    //}
}