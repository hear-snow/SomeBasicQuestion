#include "List.h"
#include<iostream>
#include<stack>
using namespace std;

void BackPrintList_One( Head pHead )	//采用递归方法实现 
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

void BackPrintList_Two( Head pHead )	//采用栈方法实现 
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

void BackPrintList_Three( Head pHead )		//采用新建一个临时链表实现 
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
	cout << "test1: 输入一个链表并反向显示该链表" << endl;
	
	for( int i = 1; i < 10; i++ )
		AddToTail( List, i );
	cout << "正常的输出: 9 8 7 6 5 4 3 2 1" << endl;
	cout << "实际的输出: " << endl;
	cout << "方法一: ";
	BackPrintList_One( List );
	cout << "方法二: ";
	BackPrintList_Two( List );
	cout << "方法三: ";
	BackPrintList_Three( List );

	DeleteList( List );
}

void Test2()
{
	Position Node = nullptr;
	Head List = &Node;
	cout << "test2: 输入一个空链表进行测试" << endl;
	
	cout << "正常的输出: " << endl;
	cout << "实际的输出: " << endl;
	cout << "方法一: ";
	BackPrintList_One( List );
	cout << "方法二: ";
	BackPrintList_Two( List );
	cout << "方法三: ";
	BackPrintList_Three( List );
}

int main()
{
	Test1();
	Test2(); 
	
	return 0;
}
