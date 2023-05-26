#include "Player.h"
#include "Global.h"
#include "ConsoleScreen.h"
#include "Bullet.h"

void Player::Input(ConsoleScreen* _Screen, Bullet& _Bullet)
{
    char Select = (char)_getch();

    int4 MovePos = { 0, 0 };

    switch (Select)
    {
        case 'a':
            //_Bullet.SetDir(Left);
            MovePos = Left;
            break;
        case 'd':
            //_Bullet.SetDir(Right);
            MovePos = Right;
            break;
        case 'w':
            //_Bullet.SetDir(Up);
            MovePos = Up;
            break;
        case 's':
            //_Bullet.SetDir(Down);
            MovePos = Down;
            break;
        default:
            break;
    }

    _Bullet.SetDir(MovePos);
    
    if (false == _Screen->IsScreenOut(GetPos() + MovePos))
    {   
        if (_Screen->CollisionWall(GetPos() + MovePos) == false)
        {
            AddPos(MovePos);
        }
        
    }
    
}
