#include"tree.h"

Position MakeNewBinarySearchTreeNode( int nItemValue )
{
	Position pNewTreeNode = new BinarySearchTreeNode;
	pNewTreeNode->m_nValue = nItemValue;
	pNewTreeNode->m_pLeft = nullptr;
	pNewTreeNode->m_pRight = nullptr;
	return pNewTreeNode;
}

void ConnectBinarySearchTreeNode( Position pTreeRoot, Position pTreeLeft, Position pTreeRight )
{
	pTreeRoot->m_pLeft = pTreeLeft;
	pTreeRoot->m_pRight = pTreeRight;
}

void Delete( Position pTreeNode )
{
	if( pTreeNode != nullptr )
	{
		Delete( pTreeNode->m_pLeft );
		Delete( pTreeNode->m_pRight );
		delete pTreeNode;
	}
}
