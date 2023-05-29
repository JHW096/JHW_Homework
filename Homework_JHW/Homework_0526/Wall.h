#pragma once
#include "int4.h"

class Wall : public int4
{
public:

	Wall() :
		m_Pos()
	{
	}
	Wall(const Wall&) = delete;


	//Getter, Setter
public:

	int4 GetPos() const
	{
		return this->m_Pos;
	}

	char GetCh() const
	{
		return m_Ch;
	}

	void SetPos(const int4& _Pos)
	{
		m_Pos = _Pos;
	}


	//Behavior
public:

	void Destroy(const int4& _Pos);


private:
	int4 m_Pos;
	char m_Ch = '#';
};

