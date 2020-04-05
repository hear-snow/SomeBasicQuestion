#include "List.h"
#include<iostream>
#include<stack>
using namespace std;

void BackPrintList_One( Head pHead )	//���õݹ鷽��ʵ�� 
{
	if( pHead == nullptr || *pHead == nullptr )
	{
		cout << endl;
		return;
	}
	void Reverse( Position );
	Reverse( *pHead );
	cout << endl;
}

void Reverse( Position Node )
{
	if( Node->m_pNext != nullptr )
		Reverse( Node->m_pNext );
	cout << Node->m_nValue << ' ';
}

void BackPrintList_Two( Head pHead )	//����ջ����ʵ�� 
{
	stack<Position> Nodes;
	Position pNode = *pHead;
	
	while( pNode != nullptr )
	{
		Nodes.push( pNode );
		pNode = pNode->m_pNext;
	}
	while( !Nodes.empty() )
	{
		pNode = Nodes.top();
		cout << pNode->m_nValue << ' ';
		Nodes.pop();
	}
	cout << endl;
}

void BackPrintList_Three( Head pHead )		//�����½�һ����ʱ����ʵ�� 
{
	if( pHead == nullptr || *pHead == nullptr )
		return; 
	Position NewNode = nullptr, pNode = *pHead, Temp = nullptr;
	while( pNode != nullptr )
	{
		NewNode = new ListNode;
		if( NewNode == nullptr )
			return;
		NewNode->m_nValue = pNode->m_nValue;
		NewNode->m_pNext = Temp;
		Temp = NewNode;
		pNode = pNode->m_pNext;
	} 
	Head NewList = &NewNode;
	PrintList( NewList );
	DeleteList( NewList );
}

void Test1()
{
	Position Node = nullptr;
	Head List = &Node;
	cout << "test1: ����һ������������ʾ������" << endl;
	
	for( int i = 1; i < 10; i++ )
		AddToTail( List, i );
	cout << "���������: 9 8 7 6 5 4 3 2 1" << endl;
	cout << "ʵ�ʵ����: " << endl;
	cout << "����һ: ";
	BackPrintList_One( List );
	cout << "������: ";
	BackPrintList_Two( List );
	cout << "������: ";
	BackPrintList_Three( List );

	DeleteList( List );
}

void Test2()
{
	Position Node = nullptr;
	Head List = &Node;
	cout << "test2: ����һ����������в���" << endl;
	
	cout << "���������: " << endl;
	cout << "ʵ�ʵ����: " << endl;
	cout << "����һ: ";
	BackPrintList_One( List );
	cout << "������: ";
	BackPrintList_Two( List );
	cout << "������: ";
	BackPrintList_Three( List );
}

int main()
{
	Test1();
	Test2(); 
	
	return 0;
}
