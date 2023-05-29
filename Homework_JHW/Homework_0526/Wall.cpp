#include "Wall.h"

void Wall::Destroy(const int4& _Pos)
{
	if (this->m_Pos.X == _Pos.X &&
		this->m_Pos.Y == _Pos.Y)
	{
		this->m_Ch = '*';
	}
}
