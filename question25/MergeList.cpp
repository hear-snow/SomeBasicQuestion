#include "List.h"
#include<iostream>
using namespace std;

Position MergeListProcess( Position pNode1, Position pNode2 )
{
	if( pNode1 == nullptr )
		return pNode2;
	if( pNode2 == nullptr )
		return pNode1;
	Position mergeListHead = nullptr;
	if( pNode1->m_nValue < pNode2->m_nValue )
	{
		mergeListHead = pNode1;
		mergeListHead->m_pNext = MergeListProcess( pNode1->m_pNext, pNode2 );
	}
	else
	{
		mergeListHead = pNode2;
		mergeListHead->m_pNext = MergeListProcess( pNode1, pNode2->m_pNext );
	}
	return mergeListHead;
}

List MergeList( List pListHead1, List pListHead2 )
{
	if( pListHead1 == nullptr || pListHead2 == nullptr )
		return nullptr;
	Position mergeListHead = MergeListProcess( *pListHead1, *pListHead2 );
	return &mergeListHead;
}

void Test1()
{
	cout << "test1: 功能测试" << endl;
	cout << "正常的输出: 1 2 3 4 5 6 7 8" << endl;
	cout << "实际的输出: ";
	Position pNode1 = nullptr, pNode2 = nullptr;
	List pList1 = &pNode1, pList2 = &pNode2;
	for( int i = 1; i < 9; i += 2 )
		InsertNode( i, pList1 );
	for( int i = 2; i < 9; i += 2 )
		InsertNode( i, pList2 );
	List pMergeList = MergeList( pList1, pList2 );
	PrintList( pMergeList );
	Delete( pMergeList );
}

void Test2()
{
	cout << "test2: 特殊输入测试" << endl;
	cout << "正常的输出: 1 3 5 7" << endl;
	cout << "实际的输出: ";
	Position pNode1 = nullptr, pNode2 = nullptr;
	List pList1 = &pNode1, pList2 = &pNode2;
	for( int i = 1; i < 9; i += 2 )
		InsertNode( i, pList1 );
	List pMergeList = MergeList( pList1, pList2 );
	PrintList( pMergeList );
	Delete( pMergeList );
}

void Test3()
{
	cout << "test3: 负面测试" << endl;
	cout << "正常的输出: " << endl;
	cout << "实际的输出: ";
	Position pNode1 = nullptr, pNode2 = nullptr;
	List pList1 = &pNode1, pList2 = &pNode2;
	List pMergeList = MergeList( pList1, pList2 );
	PrintList( pMergeList );
	Delete( pMergeList );
}

int main()
{
	Test1();
	Test2();
	Test3();
	
	return 0;
}
