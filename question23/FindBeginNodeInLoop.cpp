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

bool MakeLoopInList( List pListHead, int k )
{
	if( pListHead == nullptr || *pListHead == nullptr || k <= 0 )
		return false;
	Position pTail = FindkthNodeToTail( pListHead, 1 );
	Position pNode = FindkthNodeToTail( pListHead, k );
	if( pTail == nullptr || pNode == nullptr )
		return false;
	pTail->m_pNext = pNode;
	return true;
}

void CleanLoopInTail( Position loopNode )
{
	Position pNode = loopNode;
	while( pNode->m_pNext != loopNode )
		pNode = pNode->m_pNext;
	pNode->m_pNext = nullptr;
}

Position MeetingLoop( List pListHead )
{
	if( pListHead == nullptr || *pListHead == nullptr )
		return nullptr;
	Position pSlow = ( *pListHead )->m_pNext;
	if( pSlow == nullptr )
		return nullptr;
	Position pFast = pSlow->m_pNext;
	while( pFast != nullptr && pSlow != nullptr )
	{
		if( pFast == pSlow )
			return pFast;
		pFast = pFast->m_pNext;
		pSlow = pSlow->m_pNext;
		if( pFast != nullptr )
			pFast = pFast->m_pNext;
	}
	return nullptr;
}

Position FindBeginNodeInLoop( List pListHead )
{
	Position meetingNode = MeetingLoop( pListHead );
	if( meetingNode == nullptr )
		return nullptr;
	int nodesInLoop = 1;
	Position pNode = meetingNode;
	while( pNode->m_pNext != meetingNode )
	{
		nodesInLoop++;
		pNode = pNode->m_pNext;
	}
	Position pBegin = *pListHead, pEnd = *pListHead;
	for( int i = 0; i < nodesInLoop; i++ )
		pBegin = pBegin->m_pNext;
	while( pBegin != pEnd )
	{
		pBegin = pBegin->m_pNext;
		pEnd = pEnd->m_pNext;
	}
	return pBegin;
}

void Test1()
{
	cout << "test1: 功能测试" << endl;
	cout << "正常的输出: 3" << endl;
	cout << "实际的输出: ";
	Position pNode = nullptr;
	List pList = &pNode;
	for( int i = 1; i < 6; i++ )
		InsertNode( i, pList );
	if( MakeLoopInList( pList, 3 ) )
	{
		Position loopNode = FindBeginNodeInLoop( pList );
		if( loopNode != nullptr )
			cout << loopNode->m_nValue << endl;
		CleanLoopInTail( loopNode );
	}
	else
		cout << endl;
	Delete( pList );
}

void Test2()
{
	cout << "test2: 负面测试" << endl;
	cout << "正常的输出: " << endl;
	cout << "实际的输出: ";
	Position pNode = nullptr;
	List pList = &pNode;
	if( MakeLoopInList( pList, 3 ) )
	{
		Position loopNode = FindBeginNodeInLoop( pList );
		if( loopNode != nullptr )
			cout << loopNode->m_nValue << endl;
		CleanLoopInTail( loopNode );
	}
	else
		cout << endl;
	Delete( pList );
}

int main()
{
	Test1();
	Test2();
	
	return 0;
}
