#pragma once
#include <iostream>
#include <conio.h>

/*
	�ᱹ ������ .cpp���� �����.
	int count = 5;
	(����)		(��ü)

	extern int count�� ���ָ� ����θ� ���� �� �ִ�. (-C style)
*/

//Function�� ������ ���µ� const�� �� ����������?
//�����Ϸ��� �ߺ��� LineCount�� �� ��������.
//�Ϲ� int�� �ߺ��� �̸����� error
//�ּҰ� ó���� �ƴϰ� LineCount�� �־�� �� �ڸ��� �ھƹ���.
const int LineCount = 40;

int StringCount(const char* _Arr);


//Global�� ��äȭ ���Ѽ� ����Ѵ�.
//class Global
//{
//public:
//	static const int LineCount;
//
//	static int StringCount(const char* _Arr);
//};