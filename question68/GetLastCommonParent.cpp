#include"tree.h"
#include<iostream>
#include<vector>
#include<list>
using namespace std;

bool GetNodePath( Position pTreeNode, Position pTreeNodeTarget, list< Position > & NodePath )
{
	if( pTreeNode == pTreeNodeTarget )
		return true;
	NodePath.push_back( pTreeNode );
	bool found = false;
	for( vector< Position >::iterator i = pTreeNode->m_vChildren.begin();!found && i < pTreeNode->m_vChildren.end(); ++i )
		found = GetNodePath( *i, pTreeNodeTarget, NodePath );
	if( !found )
		NodePath.pop_back();
	return found;
}

Position GetLastCommonNode( list< Position > & NodePath1, list< Position > & NodePath2 )
{
	list< Position >::iterator iterator1 = NodePath1.begin();
	list< Position >::iterator iterator2 = NodePath2.begin();
	Position CommonNode = nullptr;
	while( iterator1 != NodePath1.end() && iterator2 != NodePath2.end() )
	{
		if( *iterator1 == *iterator2 )
			CommonNode = *iterator1;
		++iterator1;
		++iterator2;
	}
	return CommonNode;
}

Position GetLastCommonParent( Position pTreeRoot, Position pTreeNode1, Position pTreeNode2 )
{
	if( pTreeRoot == nullptr || pTreeNode1 == nullptr || pTreeNode2 == nullptr )
		return nullptr;
	list< Position > NodePath1;
	GetNodePath( pTreeRoot, pTreeNode1, NodePath1 );
	list< Position > NodePath2;
	GetNodePath( pTreeRoot, pTreeNode2, NodePath2 );
	return GetLastCommonNode( NodePath1, NodePath2 );
}

void Test( const char * str, Position pTreeRoot, Position pTreeNode1, Position pTreeNode2, Position ans )
{
	cout << str << ": ";
	if( GetLastCommonParent( pTreeRoot, pTreeNode1, pTreeNode2 ) == ans )
		cout << "Passed!" << endl;
	else
		cout << "Failed!" << endl;
}

int main()
{
	Position pTreeNode_1 = CreateNewBinaryTreeNode( 1 );
	Position pTreeNode_2 = CreateNewBinaryTreeNode( 2 );
	Position pTreeNode_3 = CreateNewBinaryTreeNode( 3 );
	Position pTreeNode_4 = CreateNewBinaryTreeNode( 4 );
	Position pTreeNode_5 = CreateNewBinaryTreeNode( 5 );
	Position pTreeNode_6 = CreateNewBinaryTreeNode( 6 );
	Position pTreeNode_7 = CreateNewBinaryTreeNode( 7 );
	Position pTreeNode_8 = CreateNewBinaryTreeNode( 8 );
	Position pTreeNode_9 = CreateNewBinaryTreeNode( 9 );
	Position pTreeNode_10 = CreateNewBinaryTreeNode( 10 );
	vector< Position > tmpChildren;
	tmpChildren.push_back( pTreeNode_4 );
	tmpChildren.push_back( pTreeNode_6 );
	ConnectBinaryTreeNode( pTreeNode_3, tmpChildren );
	tmpChildren.push_back( pTreeNode_7 );
	tmpChildren.push_back( pTreeNode_9 );
	ConnectBinaryTreeNode( pTreeNode_4, tmpChildren );
	tmpChildren.push_back( pTreeNode_2 );
	tmpChildren.push_back( pTreeNode_10 );
	ConnectBinaryTreeNode( pTreeNode_7, tmpChildren );
	tmpChildren.push_back( pTreeNode_1 );
	tmpChildren.push_back( pTreeNode_5 );
	tmpChildren.push_back( pTreeNode_8 );
	ConnectBinaryTreeNode( pTreeNode_9, tmpChildren );
	Position pTreeRoot = pTreeNode_3;
	
	Test( "test1", pTreeRoot, pTreeNode_2, pTreeNode_5, pTreeNode_4 );
	
	Delete( pTreeRoot );
	
	Test( "test2", nullptr, nullptr, nullptr, nullptr );
	
	return 0;
}
