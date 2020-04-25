#include"binarytree.h"
#include<iostream>
using namespace std;

Position CreateNewTreeNode( int itemValue )
{
	Position pNewTreeNode = new BinaryTreeNode;
	pNewTreeNode->m_nValue = itemValue;
	pNewTreeNode->m_pLeft = nullptr;
	pNewTreeNode->m_pRight = nullptr;
	return pNewTreeNode;
}

void ConnectTreeNode( Position pTreeRoot, Position pTreeLeft, Position pTreeRight )
{
	pTreeRoot->m_pLeft = pTreeLeft;
	pTreeRoot->m_pRight = pTreeRight;
}

void PrintTreeNode( Position pTreeNode )
{
	if( pTreeNode != nullptr )
	{
		cout << pTreeNode->m_nValue << ',';
		PrintTreeNode( pTreeNode->m_pLeft );
		PrintTreeNode( pTreeNode->m_pRight );
	}
	else
		cout << "$,";
}

void DeleteAll( Position pTreeNode )
{
	if( pTreeNode != nullptr )
	{
		DeleteAll( pTreeNode->m_pLeft );
		DeleteAll( pTreeNode->m_pRight );
		delete pTreeNode;
	}
}
