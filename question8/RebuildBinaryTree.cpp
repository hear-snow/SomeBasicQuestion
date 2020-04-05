#include "binarytree.h"
#include<iostream>
#include<stack>
using namespace std;
stack<Position> TreeNodeParents;

Position FindLeftChildTree( const Position NowPosition )
{
	Position Temp = NowPosition;
	while( Temp->m_pLeft != nullptr )
		Temp = Temp->m_pLeft;
	return Temp;
}

Position FindNextPosition( Position NowPosition )
{
	if( NowPosition == nullptr )
		return nullptr;
	
	if( NowPosition->m_pRight != nullptr )
	{
		return FindLeftChildTree( NowPosition->m_pRight );
	}
	else if( NowPosition->m_pParent != nullptr )
	{
		Position NowParent = NowPosition->m_pParent;
		Position Temp = NowPosition;
		while( NowParent != nullptr && Temp == NowParent->m_pRight )
		{
			Temp = NowParent;
			NowParent = Temp->m_pParent;
		}
		return NowParent;
	}
	return nullptr;
}

Position RebuildTree( int * Preorder, int * Inorder, int length )
{
	Position Construct( int * , int * , int * , int * );
	if( Preorder == nullptr || Inorder == nullptr || length <= 0 )		//��ֹ���õ����� 
		return nullptr;
	try
	{
		TreeNodeParents.push( nullptr );
		return Construct( Preorder, Preorder + length - 1 , Inorder, Inorder + length - 1 );
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
	TreeRoot->m_pParent = TreeNodeParents.top();	//�����ڵ�ָ�븳���½ڵ� 
	TreeNodeParents.push( TreeRoot );	//�½ڵ���ջ 
	
	if( StartPreorder == EndPreorder )		// �ж��Ƿ�ݹ���� 
	{
		if( StartInorder == EndInorder && *StartPreorder == *StartInorder )
		{
			TreeNodeParents.pop();		//�ݹ���������ڵ��ջ 
			return TreeRoot;
		}
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
	
	TreeNodeParents.pop();		//�ݹ���������ڵ��ջ
	return TreeRoot;
}

void Test1()
{
	cout << "test1: һ����ͨ�������������������е���һ���ڵ�ֵ" << endl; 
	int Preorder[] = { 1, 2, 4, 7, 3, 5, 6, 8 }, Inorder[] ={ 4, 7, 2, 1, 5, 3, 8, 6 };
	Position Tree = RebuildTree( Preorder, Inorder, sizeof( Preorder ) / sizeof ( int ) );
	Position NowNode = FindTree( Tree, 5 );
	if( NowNode == nullptr )
		return;
	Position NextNode = FindNextPosition( NowNode ); 
	cout << "���������: 3" << endl;
	cout << "ʵ�ʵ����: " << NextNode->m_nValue << endl; 
	DeleteTree( Tree );
}

void Test2()
{
	cout << "test2: һ������������������������е���һ���ڵ�ֵ" << endl; 
	int Preorder[] = { 1, 2, 4, 7, 3, 5, 6, 8 }, Inorder[] ={ 4, 7, 2, 5, 3, 8, 6, 1 };
	Position Tree = RebuildTree( Preorder, Inorder, sizeof( Preorder ) / sizeof ( int ) );
	Position NowNode = FindTree( Tree, 6 );
	if( NowNode == nullptr )
		return;
	Position NextNode = FindNextPosition( NowNode ); 
	cout << "���������: 1" << endl;
	cout << "ʵ�ʵ����: " << NextNode->m_nValue << endl; 
	DeleteTree( Tree );
}

int main()
{
	Test1();
	Test2();
	
	return 0;
}
