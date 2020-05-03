#ifndef TREE_H_
#define TREE_H_

struct BinaryTreeNode;
typedef BinaryTreeNode* Position;

struct BinaryTreeNode
{
	int m_nValue;
	Position m_pLeft;
	Position m_pRight;
};

Position MakeNewBinaryTreeNode( int nItemValue );
void ConnectBinaryTreeNode( Position pTreeRoot, Position pTreeLeft, Position pTreeRight );
void Delete( Position pTreeNode );

#endif
