#ifndef TREE_H_
#define TREE_H_

struct BinarySearchTreeNode;
typedef BinarySearchTreeNode* Position;

struct BinarySearchTreeNode
{
	int m_nValue;
	Position m_pLeft;
	Position m_pRight;
};

Position MakeNewBinarySearchTreeNode( int nItemValue );
void ConnectBinarySearchTreeNode( Position pTreeRoot, Position pTreeLeft, Position pTreeRight );
void Delete( Position pTreeNode );

#endif
