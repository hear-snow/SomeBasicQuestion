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

/* ����Ĵ��������ж����ĶԳ��� */
bool IsSymmetricalProcess( Position pTree1, Position pTree2 )
{
	if( pTree1 == nullptr && pTree2 == nullptr )
		return true;
	if( pTree1 == nullptr || pTree2 == nullptr )
		return false;
	if( pTree1->m_nValue != pTree2->m_nValue )
		return false;
	return IsSymmetricalProcess( pTree1->m_pLeft, pTree2->m_pRight ) && IsSymmetricalProcess( pTree1->m_pRight, pTree2->m_pLeft );
}

bool IsSymmetricalTree( Position pTree )
{
	return IsSymmetricalProcess( pTree, pTree );
}

void Test1()
{
	cout << "test1: ���ܲ���" << endl; 
	cout << "���������: �Գ���" << endl;
	int Preorder[] = { 8, 6, 5, 7, 6, 7, 5 }, Inorder[] ={ 5, 6, 7, 8, 7, 6, 5 };
	Position tree = RebuildTree( Preorder, Inorder, sizeof( Preorder ) / sizeof ( int ) );
	cout << "ʵ�ʵ����: "; 
	if( IsSymmetricalTree( tree ) )
		cout << "�Գ���" << endl;
	else
		 cout << "�ǶԳ���" << endl;
	DeleteTree( tree );
}

void Test2()
{
	cout << "test2: ���ܲ���" << endl; 
	cout << "���������: �ǶԳ���" << endl;
	int Preorder[] = { 10, 8, 9, 2, 4, 7, 6 }, Inorder[] ={ 9, 8, 4, 2, 7, 10, 6 };
	Position tree = RebuildTree( Preorder, Inorder, sizeof( Preorder ) / sizeof ( int ) );
	cout << "ʵ�ʵ����: "; 
	if( IsSymmetricalTree( tree ) )
		cout << "�Գ���" << endl;
	else
		 cout << "�ǶԳ���" << endl;
	DeleteTree( tree );
}

void Test3()
{
	cout << "test3: �����������" << endl; 
	cout << "���������: �Գ���" << endl;
	Position tree = nullptr; 
	cout << "ʵ�ʵ����: "; 
	if( IsSymmetricalTree( tree ) )
		cout << "�Գ���" << endl;
	else
		 cout << "�ǶԳ���" << endl;
	DeleteTree( tree );
}

int main()
{
	Test1();
	Test2();
	Test3();
	
	return 0;
}
