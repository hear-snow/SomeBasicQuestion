#ifndef LIST_H_
#define LIST_H_

struct ListNode;
typedef ListNode* Position;

struct ListNode
{
	int m_nValue;
	Position m_pNext;
};

Position MakeNewListNode( int nItemValue );
void ConnectListNode( Position ListNode1, Position ListNode2 );

#endif
