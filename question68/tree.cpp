#include"tree.h"

Position CreateNewBinaryTreeNode( int ItemValue )
{
	Position newNode = new BinaryTreeNode;
	newNode->m_nValue = ItemValue;
	return newNode;
}

void ConnectBinaryTreeNode( Position TreeRoot, vector< Position > & ChildrenNode )
{
	while( ChildrenNode.size() != 0 )
	{
		TreeRoot->m_vChildren.push_back( ChildrenNode.front() );
		ChildrenNode.erase( ChildrenNode.begin() );
	}
}

void Delete( Position TreeNode )
{
	if( TreeNode != nullptr )
	{
		for( vector< Position >::iterator i = TreeNode->m_vChildren.begin(); i != TreeNode->m_vChildren.end(); ++i )
			Delete( *i );
		delete TreeNode;
	}
}
