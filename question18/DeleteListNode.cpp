#include "List.h"
#include<iostream>
using namespace std;

void Test1()
{
	cout << "test1: ���ܲ���" << endl;
	cout << "���������: 1 2 4 5" << endl;
	cout << "ʵ�ʵ����: ";
	Position pNode = nullptr;
	List pList = &pNode;
	for( int i = 1; i < 6; i++ )
		InsertNode( i, pList );
	Position pToBeDeleted = FindNode( 3, pList );
	DeleteNode( pToBeDeleted, pList );
	PrintList( pList );
	Delete( pList );
}

void Test2()
{
	cout << "test2: �߽�ֵ����" << endl;
	cout << "���������: 1 2 3 4" << endl;
	cout << "ʵ�ʵ����: ";
	Position pNode = nullptr;
	List pList = &pNode;
	for( int i = 1; i < 6; i++ )
		InsertNode( i, pList );
	Position pToBeDeleted = FindNode( 5, pList );
	DeleteNode( pToBeDeleted, pList );
	PrintList( pList );
	Delete( pList );
}

void Test3()
{
	cout << "test3: �������" << endl;
	cout << "���������: " << endl;
	cout << "ʵ�ʵ����: ";
	Position pNode = nullptr;
	List pList = &pNode;
	Position pToBeDeleted = FindNode( 5, pList );
	DeleteNode( pToBeDeleted, pList );
	PrintList( pList );
	Delete( pList );
}

int main()
{
	Test1();
	Test2();
	Test3(); 
	
	return 0;
}
