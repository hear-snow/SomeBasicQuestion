#include "List.h"
#include<iostream>
using namespace std;

void InsertNode( int Item, List pListHead )
{
	Position newList = new ListNode;
	newList->m_nValue = Item;
	newList->m_pNext = nullptr;
	
	if( *pListHead == nullptr )
		*pListHead = newList;
	else
	{
		Position pNode = *pListHead;
		while( pNode->m_pNext != nullptr )
			pNode = pNode->m_pNext;
		pNode->m_pNext = newList;
	}
}

Position FindNode( int Item, List pListHead )
{
	if( pListHead == nullptr || *pListHead == nullptr )
		return nullptr; 
	Position pNode = *pListHead;
	while( pNode != nullptr && pNode->m_nValue != Item )
		pNode = pNode->m_pNext;
	return pNode;
}

void PrintList( List pListHead )
{
	if( pListHead == nullptr || *pListHead == nullptr )
		return; 
	Position pNode = *pListHead;
	while( pNode != nullptr )
	{
		cout << pNode->m_nValue << ' ';
		pNode = pNode->m_pNext;
	}
	cout << endl;
}

void Delete( List pListHead )
{
	if( pListHead == nullptr )
		return;
	Position pNode = *pListHead;
	while( pNode != nullptr )
	{
		Position temp = pNode->m_pNext;
		delete pNode;
		pNode = temp;
	}
}
