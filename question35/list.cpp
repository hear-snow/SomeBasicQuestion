#include"List.h"
#include<iostream>

Position CreateNewListNode( int itemValue )
{
	Position newListNode = new ComplexListNode;
	newListNode->m_nValue = itemValue;
	newListNode->m_pNext = nullptr;
	newListNode->m_pSlibing = nullptr;
	return newListNode;
} 

void ConnectListNextNode( Position listBeforeNode, Position listAfterNode )
{
	listBeforeNode->m_pNext = listAfterNode;
}

void ConnectListSlibingNode( Position listCurrentNode, Position listSlibingNode )
{
	listCurrentNode->m_pSlibing = listSlibingNode;
}

void PrintComplexList_NextNode( Position ListHead )
{
	if( ListHead != nullptr )
	{
		std::cout << ListHead->m_nValue << ' ';
		PrintComplexList_NextNode( ListHead->m_pNext );
	}
}

void PrintComplexList_SlibingNode( Position ListHead )
{
	if( ListHead != nullptr )
	{
		if( ListHead->m_pSlibing != nullptr )
			std::cout << ListHead->m_pSlibing->m_nValue << ' ';
		else
			std::cout << ' ' << ' ';
		PrintComplexList_SlibingNode( ListHead->m_pNext );
	}
}

void PrintComplexList( Position ListHead )
{
	PrintComplexList_NextNode( ListHead );
	std::cout << std::endl;
	PrintComplexList_SlibingNode( ListHead );
	std::cout << std::endl;
}

void DeleteAll( Position listHead )
{
	if( listHead != nullptr )
	{
		DeleteAll( listHead->m_pNext );
		delete listHead;
	}
}
