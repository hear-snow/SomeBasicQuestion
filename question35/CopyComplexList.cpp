#include"List.h"
#include<iostream> 
using namespace std;

void CreateNewListNodeInOddList( Position ListHead )
{
	Position pListNode = ListHead;
	while( pListNode != nullptr )
	{
		Position NewListNode = new ComplexListNode;
		NewListNode->m_nValue = pListNode->m_nValue;
		NewListNode->m_pNext = pListNode->m_pNext;
		NewListNode->m_pSlibing = nullptr;
		pListNode->m_pNext = NewListNode;
		pListNode = NewListNode->m_pNext;
	}
}

void CreateNewListSlibingNode( Position ListHead )
{
	Position pListNode = ListHead;
	while( pListNode != nullptr )
	{
		if( pListNode->m_pSlibing != nullptr )
			pListNode->m_pNext->m_pSlibing = pListNode->m_pSlibing->m_pNext;
		pListNode = pListNode->m_pNext->m_pNext;
	}
}

Position ReconnectListNode( Position ListHead )
{
	Position pListNode = ListHead;
	Position newListHead = ListHead->m_pNext;
	Position newListNode = ListHead->m_pNext;
	pListNode->m_pNext = newListNode->m_pNext;
	pListNode = pListNode->m_pNext;
	while( pListNode != nullptr )
	{
		newListNode->m_pNext = pListNode->m_pNext;
		newListNode = newListNode->m_pNext;
		pListNode->m_pNext = newListNode->m_pNext;
		pListNode = pListNode->m_pNext;
	}
	return newListHead;
}

Position CopyComplexList( Position ListHead )
{
	if( ListHead == nullptr )
		return nullptr;
	CreateNewListNodeInOddList( ListHead );
	CreateNewListSlibingNode( ListHead );
	return ReconnectListNode( ListHead );
}

void Test1()
{
	cout << "test1: 功能测试" << endl;
	Position ListNode_7 = CreateNewListNode( 7 );
	Position ListNode_2 = CreateNewListNode( 2 );
	Position ListNode_4 = CreateNewListNode( 4 );
	Position ListNode_9 = CreateNewListNode( 9 );
	Position ListNode_3 = CreateNewListNode( 3 );
	ConnectListNextNode( ListNode_7, ListNode_2 );
	ConnectListNextNode( ListNode_2, ListNode_4 );
	ConnectListNextNode( ListNode_4, ListNode_9 );
	ConnectListNextNode( ListNode_9, ListNode_3 );
	ConnectListSlibingNode( ListNode_7, ListNode_4 );
	ConnectListSlibingNode( ListNode_2, ListNode_3 );
	ConnectListSlibingNode( ListNode_9, ListNode_2 );
	Position ListHead = ListNode_7;
	cout << "正确的输出: " << endl;
	cout << "7 2 4 9 3" << endl;
	cout << "4 3   2  " << endl;
	cout << "实际的输出: " << endl; 
	Position NewListHead = CopyComplexList( ListHead );
	PrintComplexList( NewListHead );
	DeleteAll( ListHead );
	DeleteAll( NewListHead );
}

void Test2()
{
	cout << "test2: 负面测试" << endl;
	Position ListHead = nullptr;
	cout << "正确的输出: " << endl;
	cout << "实际的输出: " << endl; 
	Position NewListHead = CopyComplexList( ListHead );
	PrintComplexList( NewListHead );
	DeleteAll( ListHead );
	DeleteAll( NewListHead );
}

int main()
{
	Test1();
	Test2();
	
	return 0;
}
