#pragma once
#include "Global.h"
#include "int4.h"


class ConsoleScreen : public int4
{
public:

	void Init(char _BaseCh);

	void SetPixel(const int4& _Pos, char _Ch);

	void Clear();

	bool IsScreenOut(const int4& _Pos) const;

	void Print() const;

	bool FindPixel(char _Ch);



private:

	char BaseCh = ' ';
	char ArrScreen[GlobalValue::YLine][GlobalValue::XLine + 1] = {};

};

