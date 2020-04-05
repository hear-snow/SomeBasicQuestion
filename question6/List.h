#ifndef LIST_H_
#define LIST_H_

struct ListNode;
typedef ListNode * Position;
typedef ListNode ** Head;

struct ListNode
{
	int m_nValue;
	ListNode * m_pNext;
};

void AddToTail( Head pHead, int value );
void RemoveNode( Head pHead, int value );
void DeleteList( Head pHead );
void PrintList( Head pHead );

#endif
