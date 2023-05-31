#include <iostream>
#include <crtdbg.h>

/*
    Homework
    - HVector의 leck제거.
    - 대입연산자를 사용하면 터지는 것을 정상화
    - Array코드 참고.
*/

template<typename DataType>
class HVector
{
    //Constructor, Destructor
public:

    ~HVector()
    {
        if (m_ArrPtr != nullptr)
        {
            delete[] m_ArrPtr;
            m_ArrPtr = nullptr;
        }
    }

//Getter, Setter
public: 
    
    size_t size() const
    {
        return m_SizeValue;
    }

    size_t capacity() const
    {
        return m_CapacityValue;
    }

//Behavior Fn
public:

    void Clear()
    {
        if (m_ArrPtr != nullptr)
        {
            delete[] m_ArrPtr;
            m_ArrPtr = nullptr;
        }
    }
    
    void reserve(size_t _capacity)
    {
        DataType* PrevPtr = m_ArrPtr;

        m_ArrPtr = new DataType[_capacity];

        if (PrevPtr != nullptr)
        {
            for (int i = 0; i < m_SizeValue; i++)
            {
                m_ArrPtr[i] = PrevPtr[i];
            }
        }

        if (PrevPtr != nullptr)
        {
            delete[] PrevPtr;
            PrevPtr = nullptr;
        }
        
        m_CapacityValue = (int)_capacity;
    }

    void push_back(const DataType& _Data)
    {
        if (m_SizeValue + 1 > m_CapacityValue)
        {
            reserve((int)((m_CapacityValue * 1.5) + 1));
        }

        m_ArrPtr[m_SizeValue] = _Data;
        m_SizeValue += 1;
    }

//Operator
public:

    DataType& operator[](size_t _Index) const
    {
        return m_ArrPtr[_Index];
    }

    void operator=(const HVector& _Other)
    {
        if (_Other.m_SizeValue <= 0)
        {
            return;
        }

        if (m_ArrPtr != nullptr)
        {
            delete[] m_ArrPtr;
            m_ArrPtr = nullptr;
        }

        m_SizeValue = _Other.m_SizeValue;
        m_CapacityValue = _Other.m_CapacityValue;
        m_ArrPtr = new DataType[m_CapacityValue];

        for (size_t i = 0; i < m_SizeValue; i++)
        {
            m_ArrPtr[i] = _Other[i];
        }
    }

//Variable
private: 
    int     m_SizeValue     = 0;
    int     m_CapacityValue = 0;
    DataType* m_ArrPtr      = nullptr;
};

int main()
{
    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

    HVector<int> Arr;
    Arr.reserve(10);

    for (int i = 0; i < 10; i++)
    {
        Arr.push_back(i);
    }

    std::cout << "Arr : ";

    for (size_t i = 0; i < Arr.size(); i++)
    {
        std::cout << Arr[i] << " ";
    }
    std::cout << std::endl;
    std::cout << "Arr.size() : " << Arr.size() << ", " << "Arr.capacity() : " << Arr.capacity() << std::endl;


    HVector<int> Arr0;

    Arr0 = Arr;

    std::cout << "Arr0 : ";

    for (size_t i = 0; i < Arr0.size(); i++)
    {
        std::cout << Arr0[i] << " ";
    }
    std::cout << std::endl;
    std::cout << "Arr0.size() : " << Arr0.size() << ", " << "Arr0.capacity() : " << Arr0.capacity() << std::endl;

}
