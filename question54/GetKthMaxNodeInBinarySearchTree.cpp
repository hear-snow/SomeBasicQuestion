#include"tree.h"
#include<iostream>
using namespace std;

Position FindBinarySearchTreeNode( Position pTreeNode, int & k )
{
	Position target = nullptr;
	if( pTreeNode->m_pLeft != nullptr )
		target = FindBinarySearchTreeNode( pTreeNode->m_pLeft, k );
	if( target == nullptr )
		if( --k == 0 )
			target = pTreeNode;
	if( target == nullptr && pTreeNode->m_pRight != nullptr )
		target = FindBinarySearchTreeNode( pTreeNode->m_pRight, k );
	return target;
}

Position GetKthMaxNodeInBinarySearchTree( Position pTreeRoot, int k )
{
	if( pTreeRoot == nullptr || k <= 0 )
		return nullptr;
	return FindBinarySearchTreeNode( pTreeRoot, k );
}

void Test( const char * str, Position pTreeRoot, int k, Position ans )
{
	cout << str << ": ";
	if( GetKthMaxNodeInBinarySearchTree( pTreeRoot, k ) == ans )
		cout << "Passed!" << endl;
	else
		cout << "Failed!" << endl;
}

int main()
{
	Position pTreeNode_2 = MakeNewBinarySearchTreeNode( 2 );
	Position pTreeNode_3 = MakeNewBinarySearchTreeNode( 3 );
	Position pTreeNode_4 = MakeNewBinarySearchTreeNode( 4 );
	Position pTreeNode_5 = MakeNewBinarySearchTreeNode( 5 );
	Position pTreeNode_6 = MakeNewBinarySearchTreeNode( 6 );
	Position pTreeNode_7 = MakeNewBinarySearchTreeNode( 7 );
	Position pTreeNode_8 = MakeNewBinarySearchTreeNode( 8 );
	ConnectBinarySearchTreeNode( pTreeNode_3, pTreeNode_2, pTreeNode_4 );
	ConnectBinarySearchTreeNode( pTreeNode_7, pTreeNode_6, pTreeNode_8 );
	ConnectBinarySearchTreeNode( pTreeNode_5, pTreeNode_3, pTreeNode_7 );
	Position pTreeRoot = pTreeNode_5, ans = pTreeNode_4;
	int k = 3;
	Test( "test1", pTreeRoot, k, ans );
	
	ans = pTreeNode_2;
	k = 1;
	Test( "test2", pTreeRoot, k, ans );
	
	ans = pTreeNode_8;
	k = 7;
	Test( "test3", pTreeRoot, k, ans );
	
	ans = nullptr;
	k = 0;
	Test( "test4", pTreeRoot, k, ans );
	
	ans = nullptr;
	k = 2;
	Test( "test5", nullptr, k, ans );
	
	return 0;
}
