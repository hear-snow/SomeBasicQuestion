#include "binarytree.h"
#include<iostream>
using namespace std;

/* 下面的程序用于构建树 */ 
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

/* 下面的代码用于判断树A中是否有子树B */
bool Equal( int treeAValue, int treeBValue )
{
	if( ( treeAValue + 0.0000001 > treeBValue ) && ( treeAValue - 0.0000001 < treeBValue ) )
		return true;
	return false;
}

bool DoesTreeAHasTreeB( Position TreeA, Position TreeB )
{
	if( TreeB == nullptr )
		return true;
	if( TreeA == nullptr )
		return false;
	if( !Equal( TreeA->m_nValue, TreeB->m_nValue ) )
		return false;
	return DoesTreeAHasTreeB( TreeA->m_pLeft, TreeB->m_pLeft ) && DoesTreeAHasTreeB( TreeA->m_pRight, TreeB->m_pRight );
}

bool HasSubtree( Position TreeA, Position TreeB )
{
	bool result = false;
	if( TreeA != nullptr && TreeB != nullptr )
	{
		if( Equal( TreeA->m_nValue, TreeB->m_nValue ) )
			result = DoesTreeAHasTreeB( TreeA, TreeB );
		if( !result )
			result = HasSubtree( TreeA->m_pLeft, TreeB );
		if( !result )
			result = HasSubtree( TreeA->m_pRight, TreeB );
	}
	return result;
}

void Test1()
{
	cout << "test1: 功能测试" << endl; 
	cout << "正常的输出: B是A的子结构" << endl;
	int Preorder1[] = { 10, 8, 9, 2, 4, 7, 6 }, Inorder1[] ={ 9, 8, 4, 2, 7, 10, 6 };
	Position treeA = RebuildTree( Preorder1, Inorder1, sizeof( Preorder1 ) / sizeof ( int ) );
	int Preorder2[] = { 8, 9, 2 }, Inorder2[] ={ 9, 8, 2 };
	Position treeB = RebuildTree( Preorder2, Inorder2, sizeof( Preorder2 ) / sizeof ( int ) );
	cout << "实际的输出: "; 
	if( HasSubtree( treeA, treeB ) ) 
		cout << "B是A的子结构" << endl;
	else
		cout << "B不是A的子结构" << endl;
	DeleteTree( treeA );
	DeleteTree( treeB );
}

void Test2()
{
	cout << "test2: 特殊输入测试" << endl; 
	cout << "正常的输出: B不是A的子结构" << endl;
	int Preorder1[] = { 10, 8, 6, 7, 4, 2, 9 }, Inorder1[] ={ 9, 2, 4, 7, 6, 8, 10 };
	Position treeA = RebuildTree( Preorder1, Inorder1, sizeof( Preorder1 ) / sizeof ( int ) );
	int Preorder2[] = { 8, 6, 4 }, Inorder2[] ={ 4, 6, 8 };
	Position treeB = RebuildTree( Preorder2, Inorder2, sizeof( Preorder2 ) / sizeof ( int ) );
	cout << "实际的输出: "; 
	if( HasSubtree( treeA, treeB ) ) 
		cout << "B是A的子结构" << endl;
	else
		cout << "B不是A的子结构" << endl;
	DeleteTree( treeA );
	DeleteTree( treeB );
}

void Test3()
{
	cout << "test3: 负面测试" << endl; 
	cout << "正常的输出: B不是A的子结构" << endl;
	Position treeA = nullptr; 
	int Preorder2[] = { 8, 9, 2 }, Inorder2[] ={ 9, 8, 2 };
	Position treeB = RebuildTree( Preorder2, Inorder2, sizeof( Preorder2 ) / sizeof ( int ) );
	cout << "实际的输出: "; 
	if( HasSubtree( treeA, treeB ) ) 
		cout << "B是A的子结构" << endl;
	else
		cout << "B不是A的子结构" << endl;
	DeleteTree( treeA );
	DeleteTree( treeB );
}

int main()
{
	Test1();
	Test2();
	Test3();
	
	return 0;
}
