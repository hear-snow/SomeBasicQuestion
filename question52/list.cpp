#include"list.h"

Position MakeNewListNode( int nItemValue )
{
	Position pNewListNode = new ListNode;
	pNewListNode->m_nValue = nItemValue;
	pNewListNode->m_pNext = nullptr;
	return pNewListNode;
}

void ConnectListNode( Position ListNode1, Position ListNode2 )
{
	ListNode1->m_pNext = ListNode2;
}
