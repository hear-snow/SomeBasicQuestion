#include "binarytree.h"
#include<iostream>
#include<queue>
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

/* ����Ĵ������ڴ��ϵ��´�ӡ�� */
void PrintTreeFromTopToBottom( Position tree )
{
	if( tree == nullptr )
		return;
	queue< Position > treeNode;
	treeNode.push( tree );
	while( !treeNode.empty() )
	{
		Position temp = treeNode.front();
		cout << temp->m_nValue << ' ';
		treeNode.pop();
		if( temp->m_pLeft != nullptr ) 
			treeNode.push( temp->m_pLeft );
		if( temp->m_pRight != nullptr )
			treeNode.push( temp->m_pRight );
	}
	cout << endl;
} 

void Test1()
{
	cout << "test1: ���ܲ���" << endl; 
	cout << "���������: 8 6 6 5 7 7 5" << endl;
	int Preorder[] = { 8, 6, 5, 7, 6, 7, 5 }, Inorder[] ={ 5, 6, 7, 8, 7, 6, 5 };
	Position tree = RebuildTree( Preorder, Inorder, sizeof( Preorder ) / sizeof ( int ) );
	cout << "ʵ�ʵ����: "; 
	PrintTreeFromTopToBottom( tree );
	DeleteTree( tree );
}

void Test2()
{
	cout << "test2: ���ܲ���" << endl; 
	cout << "���������: 10 8 6 7 4 2" << endl;
	int Preorder[] = { 10, 8, 6, 7, 4, 2 }, Inorder[] ={ 2, 4, 7, 6, 8, 10 };
	Position tree = RebuildTree( Preorder, Inorder, sizeof( Preorder ) / sizeof ( int ) );
	cout << "ʵ�ʵ����: "; 
	PrintTreeFromTopToBottom( tree );
	DeleteTree( tree );
}

void Test3()
{
	cout << "test3: �������" << endl; 
	cout << "���������: " << endl;
	Position tree = nullptr; 
	cout << "ʵ�ʵ����: ";
	PrintTreeFromTopToBottom( tree );
	DeleteTree( tree );
}

int main()
{
	Test1();
	Test2();
	Test3();
	
	return 0;
}
