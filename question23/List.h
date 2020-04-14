#ifndef LIST_H_
#define LIST_H_

struct ListNode;
typedef ListNode * Position;
typedef ListNode ** List; 

struct ListNode
{
	int m_nValue;
	Position m_pNext;
};

void InsertNode( int Item, List pListHead );
Position FindNode( int Item, List pListHead );
void PrintList( List pListHead );
void DeleteNode( Position pToBeDeleted, List pListHead );
void Delete( List pListHead );

#endif
