#include"tree.h"
#include<iostream>
using namespace std;

int TreeDepth( Position pTreeRoot )
{
	if( pTreeRoot == nullptr )
		return 0;
	int left = TreeDepth( pTreeRoot->m_pLeft );
	int right = TreeDepth( pTreeRoot->m_pRight );
	return left > right ? left + 1 : right + 1;
}

bool IsBalancedTreeProcess( Position pTreeRoot, int & depth )
{
	if( pTreeRoot == nullptr )
	{
		depth = 0;
		return true;
	}
	int left, right;
	if( IsBalancedTreeProcess( pTreeRoot->m_pLeft, left ) && IsBalancedTreeProcess( pTreeRoot->m_pRight, right ) )
	{
		int diff = left - right;
		if( diff <= 1 && diff >= -1 )
		{
			depth = 1 + ( left > right ? left : right );
			return true;
		}
	}
	return false;
}

bool IsBalancedTree( Position pTreeRoot )
{
	int depth = 0;
	return IsBalancedTreeProcess( pTreeRoot, depth );
}

void Test( const char * str, Position pTreeRoot, int ans )
{
	cout << str << ": ";
	if( TreeDepth( pTreeRoot ) == ans )
		cout << "Passed!" << endl;
	else
		cout << "Failed!" << endl;
	if( IsBalancedTree( pTreeRoot ) )
		cout << "The tree is balaneced." << endl;
	else
		cout << "The tree is not balaneced." << endl;
}

int main()
{
	Position pTreeNode_1 = MakeNewBinaryTreeNode( 1 );
	Position pTreeNode_2 = MakeNewBinaryTreeNode( 2 );
	Position pTreeNode_3 = MakeNewBinaryTreeNode( 3 );
	Position pTreeNode_4 = MakeNewBinaryTreeNode( 4 );
	Position pTreeNode_5 = MakeNewBinaryTreeNode( 5 );
	Position pTreeNode_6 = MakeNewBinaryTreeNode( 6 );
	Position pTreeNode_7 = MakeNewBinaryTreeNode( 7 );
	ConnectBinaryTreeNode( pTreeNode_1, pTreeNode_2, pTreeNode_3 );
	ConnectBinaryTreeNode( pTreeNode_2, pTreeNode_4, pTreeNode_5 );
	ConnectBinaryTreeNode( pTreeNode_5, pTreeNode_7, nullptr );
	ConnectBinaryTreeNode( pTreeNode_3, nullptr, pTreeNode_6 );
	Position pTreeRoot = pTreeNode_1;
	int ans = 4;
	Test( "test1", pTreeRoot, ans );
	
	Position pTreeNode_8 = MakeNewBinaryTreeNode( 8 );
	ConnectBinaryTreeNode( pTreeNode_7, nullptr, pTreeNode_8 );
	ans = 5;
	Test( "test2", pTreeRoot, ans );
	
	ans = 0;
	Test( "test3", nullptr, ans );
	
	return 0;
}
