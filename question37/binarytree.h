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

Position CreateNewTreeNode( int itemValue );
void ConnectTreeNode( Position pTreeRoot, Position pTreeLeft, Position pTreeRight );
void PrintTreeNode( Position pTreeNode );
void DeleteAll( Position pTreeNode ); 

#endif
