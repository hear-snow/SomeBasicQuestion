#include "List.h"
#include<iostream>
using namespace std;

List ReverseList( List pListHead )
{
	if( pListHead == nullptr || *pListHead == nullptr )
		return nullptr;
	Position pNode = *pListHead;
	Position pBefore = nullptr;
	Position pAfter = nullptr;
	while( pNode != nullptr )
	{
		pAfter = pNode->m_pNext;
		pNode->m_pNext = pBefore;
		pBefore = pNode;
		pNode = pAfter;
	}
	return &pBefore;
}

void Test1()
{
	cout << "test1: 功能测试" << endl;
	cout << "正常的输出: 5 4 3 2 1" << endl;
	cout << "实际的输出: ";
	Position pNode = nullptr;
	List pList = &pNode;
	for( int i = 1; i < 6; i++ )
		InsertNode( i, pList );
	List pReverseList = ReverseList( pList );
	PrintList( pReverseList );
	Delete( pReverseList );
}

void Test2()
{
	cout << "test2: 边界值测试" << endl;
	cout << "正常的输出: 1" << endl;
	cout << "实际的输出: ";
	Position pNode = nullptr;
	List pList = &pNode;
	for( int i = 1; i < 2; i++ )
		InsertNode( i, pList );
	List pReverseList = ReverseList( pList );
	PrintList( pReverseList );
	Delete( pReverseList );
}

void Test3()
{
	cout << "test3: 负面测试" << endl;
	cout << "正常的输出: " << endl;
	cout << "实际的输出: ";
	Position pNode = nullptr;
	List pList = &pNode;
	List pReverseList = ReverseList( pList );
	PrintList( pReverseList );
	Delete( pReverseList );
}

int main()
{
	Test1();
	Test2();
	Test3();
	
	return 0;
}
