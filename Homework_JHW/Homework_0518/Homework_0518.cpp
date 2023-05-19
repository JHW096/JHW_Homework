#include<iostream>

using namespace std;

int StringCount(char* _Arr)
{
	if (_Arr == nullptr)
	{
		return 0;
	}
	/*
		_Arr가 nullptr인 경우, 아무 문자 혹은 문자열을 가지고 있지 않음으로 0을 리턴한다.
	*/

	int Answer = 0;
	while (*_Arr != '\0')
	{
		if (*_Arr != ' ')
		{
			++Answer;
		}
		++_Arr;
	}
	/*
		1. _Arr가 가르키고 있는 값이 0 혹은 '\0'이 아닐 경우 false임으로 while문을 종료한다.
		2. 만약 _Arr가 가르키고 있는 값이 ' '(띄어쓰기)가 아닐경우 Answer의 값을 증가시킨다.
		3. 증가된 Answer값을 리턴한다.
	*/

	return Answer;
}

void ChangeCh(char* _Arr, char _PrevCh, char _NextCh)
{
	if (_Arr == nullptr)
	{
		return;
	}
	/*
		_Arr가 아무주소도 가르키고 있지 않은 경우, 함수를 종료한다.
	*/
	while (*_Arr != '\0')
	{
		if (*_Arr == _PrevCh)
		{
			*_Arr = _NextCh;
		}
		++_Arr;
	}
	/*	while문 자가해석
		1. 입력 받은 _Arr가 '\0'이 되면 false임으로 while문 종료.
		2. 만약, _Arr가 가르키고 있는 값이 _PrevCh라면,
		3. _Arr가 가르키고 있는 값을 _NextCh로 변환한다.
		   (주소에 있는 값을 직접 바꿔줌으로 ChangeCh함수가 끝나도 변환이 된다.)
		4. _Arr의 자료형은 Char* 임으로, ++연산을 할 시 sizeof(char)값 만큼 주소를 증가시킨다.
		   (_Arr의 주소가 100번지라고 가정하면, ++_Arr를 할 경우, while문이 끝날때까지 주소값을 1씩 증가시킨다. )
	*/
}

void ChangeCh2(char* _Arr, char _PrevCh, char _NextCh)
{
	if (_Arr == nullptr)
	{
		return;
	}

	for (; *_Arr != '\0'; ++_Arr)
	{
		if (*_Arr == _PrevCh)
		{
			*_Arr = _NextCh;
		}
	}
	/*
	* while문을 for문으로 바꿔보았다.
	*/
}

int main(void)
{
	char str[100] = "aaa bbb ccc";

	int Count = StringCount(str);
	ChangeCh(str, 'c', 'd');

	cout << Count << " " << str << endl;
	/*
	* Expected Result.
	* StringCount = 9.
	* ChageCh = aaa bbb ddd'
	*/
}