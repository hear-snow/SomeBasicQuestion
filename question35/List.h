#ifndef LIST_H_
#define LIST_H_

struct ComplexListNode;
typedef ComplexListNode* Position;

struct ComplexListNode
{
	int m_nValue;
	Position m_pNext;
	Position m_pSlibing;
};

Position CreateNewListNode( int itemValue );
void ConnectListNextNode( Position listBeforeNode, Position listAfterNode );
void ConnectListSlibingNode( Position listCurrentNode, Position listSlibingNode );
void PrintComplexList( Position NewListHead );
void DeleteAll( Position listHead );

#endif
