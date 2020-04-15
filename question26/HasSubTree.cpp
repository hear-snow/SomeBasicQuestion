#include "binarytree.h"
#include<iostream>
using namespace std;

/* ����ĳ������ڹ����� */ 
Position RebuildTree( int * Preorder, int * Inorder, int length )
{
	Position Construct( int * , int * , int * , int * );
	if( Preorder == nullptr || Inorder == nullptr || length <= 0 )		//��ֹ���õ����� 
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
	int TreeRootValue = StartPreorder[ 0 ];		//����λ��λ������������е���λ 
	Position TreeRoot = new BinaryTreeNode;
	TreeRoot->m_nValue = TreeRootValue;
	TreeRoot->m_pLeft = TreeRoot->m_pRight = nullptr;
	
	if( StartPreorder == EndPreorder )		// �ж��Ƿ�ݹ���� 
	{
		if( StartInorder == EndInorder && *StartPreorder == *StartInorder )
			return TreeRoot;
		else
			throw "Invaild input";
	}
	
	int * TreeRootValueInorder = FindInorder( StartInorder, EndInorder, TreeRootValue );	//���������������Ѱ�Ҹ���λ�� 
	
	if( TreeRootValueInorder == EndInorder && *TreeRootValueInorder != TreeRootValue )		//����Ҳ���������˵������������� 
		throw "Invaild input";
	
	int LeftTreeLength = TreeRootValueInorder - StartInorder;
	int * LeftTreePreorderEnd = StartPreorder + LeftTreeLength;
	if( LeftTreeLength > 0 )	//������������Ȳ�Ϊ�㣬��������������� 
		TreeRoot->m_pLeft = Construct( StartPreorder + 1, LeftTreePreorderEnd, StartInorder, TreeRootValueInorder - 1 );
	if( EndPreorder - StartPreorder - LeftTreeLength > 0 )		//������������Ȳ�Ϊ�㣬��������������� 
		TreeRoot->m_pRight = Construct( LeftTreePreorderEnd + 1, EndPreorder, TreeRootValueInorder + 1, EndInorder );
		
	return TreeRoot;
}

/* ����Ĵ��������ж���A���Ƿ�������B */
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
	cout << "test1: ���ܲ���" << endl; 
	cout << "���������: B��A���ӽṹ" << endl;
	int Preorder1[] = { 10, 8, 9, 2, 4, 7, 6 }, Inorder1[] ={ 9, 8, 4, 2, 7, 10, 6 };
	Position treeA = RebuildTree( Preorder1, Inorder1, sizeof( Preorder1 ) / sizeof ( int ) );
	int Preorder2[] = { 8, 9, 2 }, Inorder2[] ={ 9, 8, 2 };
	Position treeB = RebuildTree( Preorder2, Inorder2, sizeof( Preorder2 ) / sizeof ( int ) );
	cout << "ʵ�ʵ����: "; 
	if( HasSubtree( treeA, treeB ) ) 
		cout << "B��A���ӽṹ" << endl;
	else
		cout << "B����A���ӽṹ" << endl;
	DeleteTree( treeA );
	DeleteTree( treeB );
}

void Test2()
{
	cout << "test2: �����������" << endl; 
	cout << "���������: B����A���ӽṹ" << endl;
	int Preorder1[] = { 10, 8, 6, 7, 4, 2, 9 }, Inorder1[] ={ 9, 2, 4, 7, 6, 8, 10 };
	Position treeA = RebuildTree( Preorder1, Inorder1, sizeof( Preorder1 ) / sizeof ( int ) );
	int Preorder2[] = { 8, 6, 4 }, Inorder2[] ={ 4, 6, 8 };
	Position treeB = RebuildTree( Preorder2, Inorder2, sizeof( Preorder2 ) / sizeof ( int ) );
	cout << "ʵ�ʵ����: "; 
	if( HasSubtree( treeA, treeB ) ) 
		cout << "B��A���ӽṹ" << endl;
	else
		cout << "B����A���ӽṹ" << endl;
	DeleteTree( treeA );
	DeleteTree( treeB );
}

void Test3()
{
	cout << "test3: �������" << endl; 
	cout << "���������: B����A���ӽṹ" << endl;
	Position treeA = nullptr; 
	int Preorder2[] = { 8, 9, 2 }, Inorder2[] ={ 9, 8, 2 };
	Position treeB = RebuildTree( Preorder2, Inorder2, sizeof( Preorder2 ) / sizeof ( int ) );
	cout << "ʵ�ʵ����: "; 
	if( HasSubtree( treeA, treeB ) ) 
		cout << "B��A���ӽṹ" << endl;
	else
		cout << "B����A���ӽṹ" << endl;
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
