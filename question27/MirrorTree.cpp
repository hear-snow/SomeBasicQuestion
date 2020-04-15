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

/* 下面的代码用于镜像树 */
void MirrorTree( Position pTreeRoot )
{
	if( pTreeRoot == nullptr )
		return;
	if( pTreeRoot->m_pLeft == nullptr && pTreeRoot->m_pRight == nullptr )
		return;
	if( pTreeRoot->m_pLeft )
		MirrorTree( pTreeRoot->m_pLeft );
	if( pTreeRoot->m_pRight )
		MirrorTree( pTreeRoot->m_pRight );
	Position pTemp = pTreeRoot->m_pLeft;
	pTreeRoot->m_pLeft = pTreeRoot->m_pRight;
	pTreeRoot->m_pRight = pTemp;
}

void Test1()
{
	cout << "test1: 功能测试" << endl; 
	cout << "正常的输出: 6 7 4 2 9 8 10" << endl;
	int Preorder[] = { 10, 8, 9, 2, 4, 7, 6 }, Inorder[] ={ 9, 8, 4, 2, 7, 10, 6 };
	Position tree = RebuildTree( Preorder, Inorder, sizeof( Preorder ) / sizeof ( int ) );
	cout << "实际的输出: "; 
	MirrorTree( tree );
	PosorderShowTree( tree );
	DeleteTree( tree );
}

void Test2()
{
	cout << "test2: 功能测试" << endl; 
	cout << "正常的输出: 9 2 4 7 6 8 10" << endl;
	int Preorder[] = { 10, 8, 6, 7, 4, 2, 9 }, Inorder[] ={ 9, 2, 4, 7, 6, 8, 10 };
	Position tree = RebuildTree( Preorder, Inorder, sizeof( Preorder ) / sizeof ( int ) );
	cout << "实际的输出: "; 
	MirrorTree( tree );
	PosorderShowTree( tree );
	DeleteTree( tree );
}

void Test3()
{
	cout << "test3: 负面测试" << endl; 
	cout << "正常的输出: " << endl;
	Position tree = nullptr; 
	cout << "实际的输出: "; 
	MirrorTree( tree );
	PosorderShowTree( tree );
	DeleteTree( tree );
}

int main()
{
	Test1();
	Test2();
	Test3();
	
	return 0;
}
