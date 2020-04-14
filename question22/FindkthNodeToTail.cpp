#include "List.h"
#include<iostream>
using namespace std;

Position FindkthNodeToTail( List pListHead, int k )
{
	if( pListHead == nullptr || *pListHead == nullptr || k <= 0 )
		return nullptr;
	Position pHead = *pListHead;
	Position pBehind = *pListHead;
	for( int i = 1; i < k; i++ )
	{
		if( pHead->m_pNext != nullptr )
			pHead = pHead->m_pNext;
		else
			return nullptr;
	}
	while( pHead->m_pNext != nullptr )
	{
		pHead = pHead->m_pNext;
		pBehind = pBehind->m_pNext;
	}
	return pBehind;
}

void Test1()
{
	cout << "test1: ���ܲ���" << endl;
	cout << "���������: 4" << endl;
	cout << "ʵ�ʵ����: ";
	Position pNode = nullptr;
	List pList = &pNode;
	for( int i = 1; i < 6; i++ )
		InsertNode( i, pList );
	Position kthNodeToTail = FindkthNodeToTail( pList, 2 );
	if( kthNodeToTail != nullptr )
		cout << kthNodeToTail->m_nValue << endl;
	Delete( pList );
}

void Test2()
{
	cout << "test2: �������" << endl;
	cout << "���������: " << endl;
	cout << "ʵ�ʵ����: ";
	Position pNode = nullptr;
	List pList = &pNode;
	Position kthNodeToTail = FindkthNodeToTail( pList, 2 );
	if( kthNodeToTail != nullptr )
		cout << kthNodeToTail->m_nValue << endl;
	Delete( pList );
}

int main()
{
	Test1();
	Test2();
	
	return 0;
}
