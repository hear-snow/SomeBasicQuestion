#include "binarytree.h"
#include<iostream>
using namespace std;

Position RebuildTree( int * Preorder, int * Inorder, int length )
{
	Position Construct( int * , int * , int * , int * );
	if( Preorder == nullptr || Inorder == nullptr || length <= 0 )		//防止不好的输入 
		return nullptr;	
	try
	{
		return Construct( Preorder, Preorder + length -1 , Inorder, Inorder + length - 1 );
	}
	catch( const char * s )
	{
		cout << s << endl;
		return nullptr;
	}
}

int * FindInorder( int * StartInorder, int * EndInorder, int TreeRootValue )
{
	int * Temp = StartInorder;
	while( Temp < EndInorder && *Temp != TreeRootValue )
		Temp++;
	return Temp;
}

Position Construct( int * StartPreorder, int * EndPreorder, int * StartInorder, int * EndInorder )
{
	int TreeRootValue = StartPreorder[ 0 ];		//根的位置位于先序遍历序列的首位 
	Position TreeRoot = new BinaryTreeNode;
	TreeRoot->m_nValue = TreeRootValue;
	TreeRoot->m_pLeft = TreeRoot->m_pRight = nullptr;
	
	if( StartPreorder == EndPreorder )		// 判断是否递归结束 
	{
		if( StartInorder == EndInorder && *StartPreorder == *StartInorder )
			return TreeRoot;
		else
			throw "Invaild input";
	}
	
	int * TreeRootValueInorder = FindInorder( StartInorder, EndInorder, TreeRootValue );	//在中序遍历序列中寻找根的位置 
	
	if( TreeRootValueInorder == EndInorder && *TreeRootValueInorder != TreeRootValue )		//如果找不到根，则说明输入存在问题 
		throw "Invaild input";
	
	int LeftTreeLength = TreeRootValueInorder - StartInorder;
	int * LeftTreePreorderEnd = StartPreorder + LeftTreeLength;
	if( LeftTreeLength > 0 )	//如果左子树长度不为零，则继续遍历左子树 
		TreeRoot->m_pLeft = Construct( StartPreorder + 1, LeftTreePreorderEnd, StartInorder, TreeRootValueInorder - 1 );
	if( EndPreorder - StartPreorder - LeftTreeLength > 0 )		//如果右子树长度不为零，则继续遍历右子树 
		TreeRoot->m_pRight = Construct( LeftTreePreorderEnd + 1, EndPreorder, TreeRootValueInorder + 1, EndInorder );
		
	return TreeRoot;
}

void Test1()
{
	cout << "test1: 重建普通二叉树并输出后向遍历序列" << endl; 
	int Preorder[] = { 1, 2, 4, 7, 3, 5, 6, 8 }, Inorder[] ={ 4, 7, 2, 1, 5, 3, 8, 6 };
	cout << "正常的输出: 7 4 2 5 8 6 3 1" << endl;
	Position Tree = RebuildTree( Preorder, Inorder, sizeof( Preorder ) / sizeof ( int ) );
	cout << "实际的输出: "; 
	PosorderShowTree( Tree );
	DeleteTree( Tree );
}

void Test2()
{
	cout << "test2: 重建特殊二叉树并输出后向遍历序列" << endl; 
	int Preorder[] = { 1, 2, 4, 7, 3, 5, 6, 8 }, Inorder[] ={ 4, 7, 2, 5, 3, 8, 6, 1 };
	cout << "正常的输出: 7 4 5 8 6 3 2 1" << endl;
	Position Tree = RebuildTree( Preorder, Inorder, sizeof( Preorder ) / sizeof ( int ) );
	cout << "实际的输出: "; 
	PosorderShowTree( Tree );
	DeleteTree( Tree );
}

int main()
{
	Test1();
	Test2();
	
	return 0;
}
