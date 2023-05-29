#include "Player.h"
#include "Global.h"
#include "ConsoleScreen.h"
#include "Bullet.h"

void Player::Input(ConsoleScreen* _Screen, Bullet* _Bullet)
{
    char Select = (char)_getch();
    //char Select2 = (char)_getch();
    int4 MovePos = { 0, 0 };

    switch (Select)
    {
        case 'a':
            //_Bullet->SetDir(_Screen, Left);
            MovePos = Left;
            break;
        case 'd':
            //_Bullet->SetDir(_Screen, Right);
            MovePos = Right;
            break;
        case 'w':
            //_Bullet->SetDir(_Screen, Up);
            MovePos = Up;
            break;
        case 's':
            //_Bullet->SetDir(_Screen, Down);
            MovePos = Down;
            break;
        case 'f':
            _Bullet->SetDir(_Screen, { 0, -1 });
            break;
        default:
            break;
    }

    if (false == _Screen->IsScreenOut(GetPos() + MovePos))
    {
        AddPos(MovePos);
        _Bullet->SetBulletPos(this->GetPos());
    }

}
