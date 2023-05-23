#include<iostream>
#include<conio.h>

/*
    Homework_0522
    1. 문자의 오른쪽 끝을 맞춰오세요. 이름은 알파벳만, 글자수 40제한.
    2. 실시간으로 만들어오세요. 데미지 메세지가 나오는 순간 체력이 곧바로 감소되게끔.
    3. 누군가 죽었다면(Hp가 0이 된다면) 종료하세요.

    몬스터와 플레이어가 서로 한 대씩 때리면서 한 명이 죽으면 끝납니다.
    그래픽으로 표현할 수 없으니 출력으로 표현합니다.
*/

int GetStringSize(const char* const _Name)
{
    if (_Name == nullptr)
    {
        return 0;
    }
    int Count = 0;

    while (_Name[Count] != '\0')
    {
        ++Count;
    }
    return Count;
}

void StatusRender(const char* const _Name, int _Att, int _Hp)
{
    /*
        addtional solution.
        const int LINECOUNT = 40;
        을 전역변수로 두면 향후 다른 UI를 교체시 도움이 될 것.
    */

    if (_Name == nullptr)
    {
        printf_s("이름을 만들어 주세요.\n");
        return;
    }

    int _NameSize = GetStringSize(_Name);
    if (_NameSize > 40)
    {
        return;
    }

    printf_s("%s", _Name);
    for (int i = _NameSize; i < 40; ++i) //LINECOUNT - _NameSize; ++i
    {
        printf_s("-");
    }
    printf_s("\n");

    printf_s("공격력 : %d\n", _Att);
    printf_s("체  력 : %d\n", _Hp);

    printf_s("----------------------------------------\n");
    
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

int main()
{
    int PlayerHp = 200;
    int PlayerAtt = 20;
    char PlayerName[40] = "PlayerName";

    int MonsterHp = 100;
    int MonsterAtt = 10;
    char MonsterName[40] = "MonsterName";

    //초기 화면 출력
    StatusRender(PlayerName, PlayerAtt, PlayerHp);
    StatusRender(MonsterName, MonsterAtt, MonsterHp);

    while (true)
    {

        _getch();

        Damage(MonsterHp, PlayerAtt);

        system("cls");

        StatusRender(PlayerName, PlayerAtt, PlayerHp);
        StatusRender(MonsterName, MonsterAtt, MonsterHp);
        DamagePrint(PlayerName, MonsterName, PlayerAtt);

        if (PlayerHp <= 0 || MonsterHp <= 0)
        {
            printf_s("게임을 종료합니다.\n");
            return 0;
        }

        /*
            1. 키를 누른다.
            2. 데미지를 먼저 계산한다.
            3. 이전 화면을 지운다.
            4. 계산된 데미지와 데미지 정보를 출력한다.
            Hp를 확인하여 프로그램(게임)을 종료한다.
        */

        _getch();

        Damage(PlayerHp, MonsterAtt);

        system("cls");

        StatusRender(PlayerName, PlayerAtt, PlayerHp);
        StatusRender(MonsterName, MonsterAtt, MonsterHp);
        DamagePrint(MonsterName, PlayerName, MonsterAtt);

        if (PlayerHp <= 0 || MonsterHp <= 0)
        {
            printf_s("게임을 종료합니다.\n");
            return 0;
        }

    }





}