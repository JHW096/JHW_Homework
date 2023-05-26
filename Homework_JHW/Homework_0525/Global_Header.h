#pragma once
#include <iostream>
#include <conio.h>

/*
	결국 구현을 .cpp에만 남긴다.
	int count = 5;
	(선언)		(실체)

	extern int count를 해주면 선언부만 남길 수 있다. (-C style)
*/

//Function은 문제가 없는데 const는 왜 문제가없음?
//컴파일러가 중복된 LineCount를 다 지워버림.
//일반 int면 중복된 이름으로 error
//주소값 처리가 아니고 LineCount가 있어야 할 자리에 박아버림.
const int LineCount = 40;

int StringCount(const char* _Arr);


//Global도 객채화 시켜서 사용한다.
//class Global
//{
//public:
//	static const int LineCount;
//
//	static int StringCount(const char* _Arr);
//};