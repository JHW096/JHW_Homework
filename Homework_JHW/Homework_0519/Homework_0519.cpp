#include <iostream>

//1. _string에 _Ch와 같은 문자가 몇 개인지 리턴해주는 함수.
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
    /*
        자가해석
        1. _string이 nullptr, 아무 것도 없는 상태라면 숫자 0을 리턴합니다.
        2. 문자열의 맨 끝('\0')까지 문자하나하나 반복하여 _Ch와 같다면 숫자를 증가시킨 후 리턴합니다.
    */
}

//2. 문자열의 공백을 없애주는 함수.
void TrimDelete(char* _string)
{
    if (_string == nullptr)
    {
        return;
    }

    int i = 0;
    int j = 0;

    while (_string[i] != '\0')
    {
        if (_string[i] != ' ')
        {
            _string[j] = _string[i];
            ++j;
        }
        ++i;
    }
    _string[j] = '\0';
    /*
       자가해석
       1. _string이 nullptr, 아무 것도 없는 상태라면 함수를 종료합니다.
       2. _string을 전부 순회하는 변수 i와 공백을 지우고 뒷문자를 채워주는 변수 j를 만듭니다.
       3. _string이 '\0'에 도달할때까지 반복합니다.
       4. 문자가 있다면 _string을 앞에서부터 채워줍니다.
       5. ' '를 만난다면, _string의 다음으로 넘어가고 ' '가 아닌 것을 만날때 _string의 뒷부분을 다시 채워줍니다.
       6. 다 채워졌다면, 문자열의 끝을 알리는 '\0'를 채워넣어 찌꺼기 문자가 들어오는 것을 막습니다.
   */
}

//3. 숫자의 자릿수를 리턴하는 함수.
int DigitsCount(int _Number)
{
    int Count = 0;

    int i = 1;
    while (_Number / i > 0)
    {
        i *= 10;
        ++Count;
    }
    /*
        자가해석 - 하나의 예시
        ex) 
		256 / 1 = 256 
		256 / 10 = 25
		256 / 100 = 2
		256 / 1000 = 0.xx No Count, Finish Repeatition
    */

    return Count;
}

//4. _Right에 _Left를 복사하는 함수.
void StrCopy(const char* const _Left, char* _Right)
{
    if (_Left == nullptr)
    {
        return;
    }

    const char* C_Ptr = _Left;

    int Leftcount = 0;
    while (C_Ptr[Leftcount] != '\0')
    {
        _Right[Leftcount] = C_Ptr[Leftcount];
        ++Leftcount;
    }
    /*
        자가해석
        1. _Left가 nullptr이라면, 함수를 종료합니다.
        2. _Left의 문자를 확인하기 위한 const char* C_Ptr변수를 만들고, _Left의 가장 첫 부분을 가르킵니다.
        3. C_Ptr의 값이 문자열의 끝인 '\0'을 가르킬때까지 반복합니다.
        4. _Right에 C_Ptr이 가르킨 값을 처음부터 C_Ptr이 _Left의 끝에 도달할 때 까지 채워줍니다.
    */
}

//5. 숫자를 char* 형으로 바꾸는 함수.
void NumberToString(int _Number, char* _Right)
{
    int Count = DigitsCount(_Number);

    _Right[Count] = '\0';
    while (_Number != 0)
    {
        Count--;
        _Right[Count] = _Number % 10 + '0';
        _Number /= 10;
    }
    /*
        자가해석
        1. Count는 _Number의 자릿수로 기존에 있던 Digits함수를 통해 가져옵니다.
        2. 문자열의 끝에는 '0'을 넣어 문자열임을 알리고, 배열의 시작은 0부터 시작하기에,
            _Right의 자릿수 번째에는 '0'을 채워줍니다.
        3. 문자열의 맨 끝의 바로 앞부터 채워주는데(Count--)
        4. _Number를 10으로 나눌 경우 1의 자리 숫자만 남게됨으로 나머지에 + '0'를 추가하여 char형으로 바꾸어
            _Right의 Count번지에 넣어줍니다.
        4. 다시 _Number는 10으로 나누어 일의 자리 숫자를 제거해주는 행위를 반복합니다.
    */
}

int main()
{
    {
        //4가 리턴되어야 합니다.
        int Result = ChCount("ab aaa ccc ddd eee", 'a');
        std::cout << Result << std::endl;
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
