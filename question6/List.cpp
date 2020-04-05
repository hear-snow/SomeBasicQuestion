#include "List.h"
#include<iostream>
using namespace std;

void AddToTail( Head pHead, int value )
{
	Position NewNode = new ListNode;
	if( NewNode == nullptr )
		return; 
	NewNode->m_nValue = value;
	NewNode->m_pNext = nullptr;
	
	if( *pHead == nullptr )		//判断头结点是否为空 
		*pHead = NewNode;
	else
	{
		Position pNode = *pHead;
		while( pNode->m_pNext != nullptr )
			pNode = pNode->m_pNext;
		pNode->m_pNext = NewNode;
	}
}

void RemoveNode( Head pHead, int value )
{
	if( pHead == nullptr || *pHead == nullptr )		//排除不好的输入 
		return;
	
	Position DeleteNode = nullptr;
	if( ( *pHead )->m_nValue == value )		//判断头结点是否需要删除 
	{
		DeleteNode = *pHead;
		*pHead = ( *pHead )->m_pNext;
	}
	else
	{
		Position pNode = *pHead;
		while( pNode->m_pNext != nullptr && pNode->m_pNext->m_nValue != value )		//寻找待删除节点的前向元 
			pNode = pNode->m_pNext;
		if( pNode->m_pNext != nullptr && pNode->m_pNext->m_nValue == value )
		{
			DeleteNode = pNode->m_pNext;
			pNode->m_pNext = pNode->m_pNext->m_pNext;
		}
	}
	
	if( DeleteNode != nullptr )
	{
		delete DeleteNode;
		DeleteNode = nullptr;
	}
}

void PrintList( Head pHead )
{
	if( pHead == nullptr || *pHead == nullptr )		//排除不好的输入 
		return;
	
	Position pNode = *pHead;
	while( pNode != nullptr )
	{
		cout << pNode->m_nValue << ' ';
		pNode = pNode->m_pNext;
	}
	cout << endl;
}

void DeleteList( Head pHead ) 
{
	Position DeleteNode = *pHead, Temp;
	*pHead = nullptr;
	while( DeleteNode != nullptr )
	{
		Temp = DeleteNode->m_pNext;
		delete DeleteNode;
		DeleteNode = Temp;
	}
} 
