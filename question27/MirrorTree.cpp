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

/* ����Ĵ������ھ����� */
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
	cout << "test1: ���ܲ���" << endl; 
	cout << "���������: 6 7 4 2 9 8 10" << endl;
	int Preorder[] = { 10, 8, 9, 2, 4, 7, 6 }, Inorder[] ={ 9, 8, 4, 2, 7, 10, 6 };
	Position tree = RebuildTree( Preorder, Inorder, sizeof( Preorder ) / sizeof ( int ) );
	cout << "ʵ�ʵ����: "; 
	MirrorTree( tree );
	PosorderShowTree( tree );
	DeleteTree( tree );
}

void Test2()
{
	cout << "test2: ���ܲ���" << endl; 
	cout << "���������: 9 2 4 7 6 8 10" << endl;
	int Preorder[] = { 10, 8, 6, 7, 4, 2, 9 }, Inorder[] ={ 9, 2, 4, 7, 6, 8, 10 };
	Position tree = RebuildTree( Preorder, Inorder, sizeof( Preorder ) / sizeof ( int ) );
	cout << "ʵ�ʵ����: "; 
	MirrorTree( tree );
	PosorderShowTree( tree );
	DeleteTree( tree );
}

void Test3()
{
	cout << "test3: �������" << endl; 
	cout << "���������: " << endl;
	Position tree = nullptr; 
	cout << "ʵ�ʵ����: "; 
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
