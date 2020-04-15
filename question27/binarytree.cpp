#include "binarytree.h"
#include<iostream>
using namespace std;

void PosorderShowProcess( Position TreeRoot )		//后续遍历的递归实现 
{
	if( TreeRoot->m_pLeft != nullptr )
		PosorderShowProcess( TreeRoot->m_pLeft );
	if( TreeRoot->m_pRight != nullptr )
		PosorderShowProcess( TreeRoot->m_pRight );
	cout << TreeRoot->m_nValue << ' '; 
}

void PosorderShowTree( const Position TreeRoot )	//利用后序遍历将树输出 
{
	if( TreeRoot == nullptr )
		return;
	Position pTreeRoot = TreeRoot;
	PosorderShowProcess( pTreeRoot );
	cout << endl;
}

void DeleteTree( Position TreeRoot )
{
	if( TreeRoot != nullptr )
	{
		if( TreeRoot->m_pLeft != nullptr )
			DeleteTree( TreeRoot->m_pLeft );
		if( TreeRoot->m_pRight != nullptr )
			DeleteTree( TreeRoot->m_pRight );
		delete TreeRoot;
	}
}
