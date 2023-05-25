#pragma once

class Player
{
public:

	void StatusRender();

	void DamagePrint(const char* const _AttName, int _Att);

	void Damage(int _Att);

	const char* GetName() 
	{
		return Name;
	}

	int GetAtt()
	{
		return Att;
	}

	bool IsDeath()
	{
		return Hp <= 0;
	}

private:

	char Name[40] = "Player";
	int Att = 10;
	int Hp = 100;
		
};

