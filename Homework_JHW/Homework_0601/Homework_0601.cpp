#include <iostream>
#include <list>
#include <vector>
#include <assert.h>

// 1. Push_front를 만들어보세요.
// 2. leck 잡으세요


using DataType = int;

class HList
{
private:

	class ListNode
	{
	public:
		DataType Value;
		ListNode* Prev = nullptr;
		ListNode* Next = nullptr;
	};


public:
	class iterator
	{
		friend HList;

	private:
		ListNode* CurNode = nullptr;

	public:
		iterator()
		{

		}

		iterator(ListNode* _Node)
			: CurNode(_Node)
		{

		}

		bool operator !=(const iterator& _Other)
		{
			return CurNode != _Other.CurNode;
		}

		iterator& operator ++()
		{
			CurNode = CurNode->Next;
			return *this;
		}

		DataType& operator*()
		{
			return CurNode->Value;
		}
	};

	HList()
	{
		StartNode = new ListNode();
		EndNode = new ListNode();

		// 이게 더미 노드 방식
		StartNode->Next = EndNode;
		EndNode->Prev = StartNode;
	}

	~HList()
	{
		ListNode* p, * q;
		p = StartNode;
		while (p != nullptr)
		{
			q = p->Next;
			delete p;
			p = q;
		}
		StartNode = nullptr;
		EndNode = nullptr;
		

		/*if (StartNode != nullptr || EndNode != nullptr)
		{
			std::cout << "error" << std::endl;
			assert(false);
		}*/
	}

	// void Push_front를 만들어보세요.
	void push_back(const DataType& _Data)
	{
		ListNode* NewNode = new ListNode();
		NewNode->Value = _Data;

		ListNode* PrevNode = EndNode->Prev;

		PrevNode->Next = NewNode;
		EndNode->Prev = NewNode;

		NewNode->Next = EndNode;
		NewNode->Prev = PrevNode;
	}

	void push_front(const DataType& _Data)
	{
		ListNode* NewNode = new ListNode();
		NewNode->Value = _Data;

		ListNode* NextNode = StartNode->Next;

		NextNode->Prev = NewNode;
		StartNode->Next = NewNode;

		NewNode->Prev = StartNode;
		NewNode->Next = NextNode;
	} 

	iterator erase(const iterator& _Iter)
	{
		ListNode* Node = _Iter.CurNode;

		// 터져야 한다.
		if (StartNode == Node
			|| EndNode == Node)
		{
			assert(false);
			return iterator(EndNode);
		}

		ListNode* NextNode = Node->Next;
		ListNode* PrevNode = Node->Prev;

		PrevNode->Next = NextNode;
		NextNode->Prev = PrevNode;

		if (nullptr == Node)
		{
			delete Node;
		}

		return iterator(NextNode);
	}

	iterator begin()
	{
		return iterator(StartNode->Next);
	}

	iterator end()
	{
		return iterator(EndNode);
	}

private:
	ListNode* StartNode;
	ListNode* EndNode;
};

int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);


	//{
	//	std::vector<int> Test;

	//	// 노드형 시퀀스 자료구조
	//	std::list<int> NewList;

	//	for (size_t i = 0; i < 10; i++)
	//	{
	//		// 리스트만 가지고 있는 함수인데.
	//		NewList.push_back(i);
	//	}

	//	// NewList.erase()

	//	std::list<int>::iterator StartIter = NewList.begin();
	//	std::list<int>::iterator EndIter = NewList.end();

	//	StartIter = NewList.erase(StartIter);

	//	for (; StartIter.operator!=(EndIter); ++StartIter)
	//	{
	//		// std::cout << (*StartIter) << std::endl;
	//	}
	//}
	{
		HList NewList;

		for (int i = 0; i < 10; i++)
		{
			NewList.push_front(i);
		}



		HList::iterator StartIter = NewList.begin();
		HList::iterator EndIter = NewList.end();


		for (; StartIter != EndIter; ++StartIter)
		{
			std::cout << (*StartIter) << std::endl;
		}
		
	}

}