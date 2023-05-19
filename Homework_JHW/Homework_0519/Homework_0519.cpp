#include <iostream>

using namespace std;

//Ch와 같은 문자가 몇개 들어있는지 세어서 리턴해주는 함수.
//완료
int ChCount(const char* const _string, char _Ch)
{
    if (_string == nullptr)
    {
        return 0;
    }

    int Count = 0;

    int i = 0;
    while (_string[i] != '\0')
    {
        if (_string[i] == _Ch)
        {
            ++Count;
        }
        ++i;
    }

    return Count;
}

//문자열의 공백을 제거하는 함수입니다.
void TrimDelete(char* _string)
{
    if (_string == nullptr)
    {
        return;
    }

    int i = 0;
    int j = 0;
    char tmp[] { "" };
    while (_string[i])
    {
        if (_string[i] != ' ')
        {
            tmp[j] = _string[i];
            ++j;
        }
        ++i;
    }
    
    
}

//
int DigitsCount(int _Number)
{
    if (_Number == 0)
    {
        return 0;
    }

    int Count = 0;

    int i = 1;
    /*while (_Number)
    {
        if (_Number / i > 0)
        {
            ++Count;
        }
        i *= 10;
    }*/

    /*
    256 / 1 = 256;
    256 / 10 = 25;
    256 / 100 = 2;
    256 / 1000 = 0.@@;
    */

    return Count;
}

//_Right는 _Left를 카피합니다.
void StrCopy(const char* const _Left, char* _Right)
{
    /*int LeftSize = 0;
    while (*_Left)
    {
        _Right[LeftSize] = *_Left;
        ++LeftSize;
    }*/
}

//숫자를 String으로 바꾸는 함수입니다.
int NumberToString(int _Numbers, char* _Right)
{
    
    //아스키 코드 확인
    return 0;
}

int main()
{
    {
        //4가 리턴되어야 합니다.
        int Result = ChCount("ab aaa ccc ddd eee", 'a');
        cout << Result << endl;
    }
        

    {
        //공백이 제거되어야 합니다.
        char Arr[20] = "My name  is  Jeon h";

        TrimDelete(Arr);
    }

    {
        //3이 리턴되어야 합니다.
        int Reuslt = DigitsCount(256);
    }
    
    {
        char ArrCopyText[256] = {};
        StrCopy("aaaa bbb ccc", ArrCopyText);
    }

    {
        char Result[256] = { };

        //Result = "3123123";

        NumberToString(312312, Result);
    }

}
