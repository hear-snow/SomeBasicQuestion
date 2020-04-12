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

void DeleteNode( Position pToBeDeleted, List pListHead )
{
	if( pListHead == nullptr || *pListHead == nullptr || pToBeDeleted == nullptr )
		return; 
	if( pToBeDeleted->m_pNext != nullptr )			//待删除节点不是尾节点 
	{
		Position pNext = pToBeDeleted->m_pNext;
		pToBeDeleted->m_nValue = pNext->m_nValue;
		pToBeDeleted->m_pNext = pNext->m_pNext;
		delete pNext;
		pNext = nullptr;
	}
	else if( pToBeDeleted == *pListHead ) 			//如果链表只有一个节点，则同时删除头结点 
	{
		delete pToBeDeleted;
		pToBeDeleted = nullptr;
		*pListHead = nullptr;
	}
	else											//要删除的节点位于链表尾部，通过遍历完成删除 
	{
		Position pNode = *pListHead;
		while( pNode->m_pNext != pToBeDeleted )
			pNode = pNode->m_pNext;
		pNode->m_pNext = nullptr;
		delete pToBeDeleted;
		pToBeDeleted = nullptr;
	}
}

void Delete( List pListHead )
{
	Position pNode = *pListHead;
	while( pNode != nullptr )
	{
		Position temp = pNode->m_pNext;
		delete pNode;
		pNode = temp;
	}
}
