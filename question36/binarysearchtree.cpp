#include"binarysearchtree.h"
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
