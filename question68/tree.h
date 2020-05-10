#ifndef TREE_H_
#define TREE_H_

#include<vector>
using namespace std;

struct BinaryTreeNode;
typedef BinaryTreeNode* Position;

struct BinaryTreeNode
{
	int m_nValue;
	vector< Position > m_vChildren;
};

Position CreateNewBinaryTreeNode( int ItemValue );
void ConnectBinaryTreeNode( Position TreeRoot, vector< Position > & ChildrenNode );
void Delete( Position TreeNode );

#endif
