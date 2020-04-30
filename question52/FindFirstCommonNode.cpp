#include"list.h"
#include<iostream>
using namespace std;

Position FindFirstCommonNode( Position pListHead1, Position pListHead2 )
{
	if( pListHead1 == nullptr || pListHead2 == nullptr )
		return nullptr;
	unsigned int nListLength1 = 0, nListLength2 = 0;
	Position pListNode = pListHead1;
	while( pListNode != nullptr )
	{
		nListLength1++;
		pListNode = pListNode->m_pNext;
	}
	pListNode = pListHead2;
	while( pListNode != nullptr )
	{
		nListLength2++;
		pListNode = pListNode->m_pNext;
	}
	int nListLengthDif = nListLength1 - nListLength2;
	Position pListLong = pListHead1;
	Position pListShort = pListHead2;
	if( nListLength1 < nListLength2 )
	{
		nListLengthDif = nListLength2 - nListLength1;
		pListLong = pListHead2;
		pListShort = pListHead1;
	}
	for( int i = 1; i <= nListLengthDif; i++ )
		pListLong = pListLong->m_pNext;
	while( pListLong != pListShort && pListLong != nullptr && pListShort != nullptr )
	{
		pListLong = pListLong->m_pNext;
		pListShort = pListShort->m_pNext;
	}
	return pListLong;
}

void Test( const char * str, Position pListHead1, Position pListHead2, Position pConnectListNode )
{
	cout << str << ": ";
	if( FindFirstCommonNode( pListHead1, pListHead2 ) == pConnectListNode )
		cout << "Passed!" << endl;
	else
		cout << "Failed!" << endl;
}

int main()
{
	Position pListNode_1 = MakeNewListNode( 1 );
	Position pListNode_2 = MakeNewListNode( 2 );
	Position pListNode_3 = MakeNewListNode( 3 );
	Position pListNode_4 = MakeNewListNode( 4 );
	Position pListNode_5 = MakeNewListNode( 5 );
	Position pListNode_6 = MakeNewListNode( 6 );
	Position pListNode_7 = MakeNewListNode( 7 );
	ConnectListNode( pListNode_1, pListNode_2 );
	ConnectListNode( pListNode_2, pListNode_3 );
	ConnectListNode( pListNode_3, pListNode_6 );
	ConnectListNode( pListNode_4, pListNode_5 );
	ConnectListNode( pListNode_5, pListNode_6 );
	ConnectListNode( pListNode_6, pListNode_7 );
	Position pListHead1 = pListNode_1;
	Position pListHead2 = pListNode_4;
	Position pConnectListNode = pListNode_6;
	Test( "test1", pListHead1, pListHead2, pConnectListNode );
	
	Test( "test2", nullptr, pListHead2, nullptr );
	
	return 0;
}
