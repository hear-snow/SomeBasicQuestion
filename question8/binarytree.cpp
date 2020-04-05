#include "binarytree.h"
#include<iostream>
using namespace std;

void PreorderFindProcess( Position TreeNode, Position * FindNode, int Target )		//�ݹ�Ѱ��Ŀ��ڵ㲢�������ַ 
{
	if( TreeNode->m_nValue == Target )
		*FindNode = TreeNode;
	if( TreeNode->m_pLeft != nullptr )
		PreorderFindProcess( TreeNode->m_pLeft, FindNode, Target );
	if( TreeNode->m_pRight != nullptr )
		PreorderFindProcess( TreeNode->m_pRight, FindNode, Target );
}

Position FindTree( const Position TreeRoot, int Target )	//Ѱ�Ҳ�����Ŀ��ֵ���ڽڵ�ĵ�ַ 
{
	if( TreeRoot == nullptr )
		return nullptr;
	Position TreeNode = TreeRoot, TargetNode = nullptr;
	Position * FindNode = &TargetNode;
	PreorderFindProcess( TreeNode, FindNode, Target );
	return TargetNode;
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
