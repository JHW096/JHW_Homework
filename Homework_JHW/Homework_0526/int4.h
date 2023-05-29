#pragma once
class int4
{
public:
	int X = 0;
	int Y = 0;
	int Z = 0;
	int W = 1;

	void operator=(const int4& _Other);

	void operator+=(const int4& _Other);

	int4 operator+(const int4& _Other);


};

const int4 Left = { -1, 0 };
const int4 Right = { 1, 0 };
const int4 Up = { 0, -1 };
const int4 Down = { 0, 1 };