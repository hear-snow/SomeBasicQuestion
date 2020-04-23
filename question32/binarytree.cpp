#include "binarytree.h"
#include<iostream>
using namespace std;

void PosorderShowProcess( Position TreeRoot )		//���������ĵݹ�ʵ�� 
{
	if( TreeRoot->m_pLeft != nullptr )
		PosorderShowProcess( TreeRoot->m_pLeft );
	if( TreeRoot->m_pRight != nullptr )
		PosorderShowProcess( TreeRoot->m_pRight );
	cout << TreeRoot->m_nValue << ' '; 
}

void PosorderShowTree( const Position TreeRoot )	//���ú������������� 
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
