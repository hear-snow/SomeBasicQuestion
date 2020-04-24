#include"binarytree.h"
using namespace std;

Position NewBinaryTreeNode( int itemValue )
{
	Position newNode = new BinaryTreeNode;
	newNode->m_nValue = itemValue;
	newNode->m_pLeft = nullptr;
	newNode->m_pRight = nullptr;
	return newNode;
}

void ConnectBinaryTreeNode( Position treeRoot, Position treeLeft, Position treeRight )
{
	treeRoot->m_pLeft = treeLeft;
	treeRoot->m_pRight = treeRight;
}

void DeleteAll( Position treeRoot )
{
	if( treeRoot != nullptr )
	{
		DeleteAll( treeRoot->m_pLeft );
		DeleteAll( treeRoot->m_pRight );
		delete treeRoot;
	}
} 
